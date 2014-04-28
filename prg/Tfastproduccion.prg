#include "FiveWin.Ch"
#include "Factu.ch" 
#include "Report.ch"
#include "MesDbf.ch"
// #include "FastRepH.ch"

//---------------------------------------------------------------------------//

CLASS TFastProduccion FROM TFastReportInfGen
   
   DATA cType                             INIT "PRODUCCION"

   DATA oProCab   
   DATA oProLin   
   DATA oProMat   
   DATA oHorasPers
   DATA oMaqLin   
   DATA oProMaq   
   DATA oArticulos
   DATA oFamArt   
   DATA oAlmacen 
   DATA oProPer 

   METHOD lResource( cFld )

   METHOD Create()
   METHOD lGenerate()
   METHOD lValidRegister()

   METHOD OpenFiles()
   METHOD CloseFiles()

   METHOD DataReport( oFr )
   METHOD AddVariable()

   METHOD StartDialog()
   METHOD BuildTree()

   METHOD AddParteProducccion()

ENDCLASS

//----------------------------------------------------------------------------//

METHOD lResource( cFld ) CLASS TFastProduccion

   ::lNewInforme     := .t.
   ::lDefCondiciones := .f.

   ::cSubTitle       := "Informe de producci�n"

   if !::NewResource()
      return .f.
   end if

   /*
   Carga controles-------------------------------------------------------------
   */

   if !::lGrupoOperacion( .t. )
      return .f.
   end if
   
   if !::lGrupoTOperacion( .t. )
      return .f.
   end if

   if !::lGrupoSeccion( .t. )
      return .f.
   end if

   if !::lGrupoAlmacen( .t. )
      return .f.
   end if

   if !::lGrupoArticulo( .t. )
      return .f.
   end if

   if !::lGrupoFamilia( .t. )
      return .f.
   end if

   if !::lGrupoGFamilia( .t. )
      return .f.
   end if
   
   if !::lGrupoTipoArticulo( .t. )
      return .f.
   end if

   if !::lGrupoCategoria( .t. )
      return .f.
   end if

   if !::lGrupoTemporada( .t. )
      return .f.
   end if

   if !::lGrupoOperario( .t. )
      return .t.
   end if

   if !::lGrupoMaquina( .t. )
      return .f.
   end if

   if !::lGrupoSerie( .t. )
      return .f.
   end if

   ::oFilter      := TFilterCreator():Init()
   if !Empty( ::oFilter )
      ::oFilter:SetDatabase( ::oDbf )
      ::oFilter:SetFilterType( FST_PRO )
   end if 

RETURN .t.

//---------------------------------------------------------------------------//

METHOD OpenFiles() CLASS TFastProduccion

   local lOpen    := .t.
   local oBlock
   local oError

   oBlock         := ErrorBlock( {| oError | ApoloBreak( oError ) } )
   BEGIN SEQUENCE

      DATABASE NEW ::oProCab     PATH ( cPatEmp() ) CLASS "PROCAB"      FILE "PROCAB.DBF"    VIA ( cDriver() ) SHARED INDEX "PROCAB.CDX"
      DATABASE NEW ::oProLin     PATH ( cPatEmp() ) CLASS "PROLIN"      FILE "PROLIN.DBF"    VIA ( cDriver() ) SHARED INDEX "PROLIN.CDX"
      DATABASE NEW ::oProMat     PATH ( cPatEmp() ) CLASS "PROMAT"      FILE "PROMAT.DBF"    VIA ( cDriver() ) SHARED INDEX "PROMAT.CDX"
      DATABASE NEW ::oProPer     PATH ( cPatEmp() ) CLASS "PROPER"      FILE "PROPER.DBF"    VIA ( cDriver() ) SHARED INDEX "PROPER.CDX"
      DATABASE NEW ::oHorasPers  PATH ( cPatEmp() ) CLASS "HORASPERS"   FILE "PROHPER.DBF"   VIA ( cDriver() ) SHARED INDEX "PROHPER.CDX"
      DATABASE NEW ::oMaqLin     PATH ( cPatEmp() ) CLASS "MAQLIN"      FILE "MAQCOSL.DBF"   VIA ( cDriver() ) SHARED INDEX "MAQCOSL.CDX"
      DATABASE NEW ::oProMaq     PATH ( cPatEmp() ) CLASS "PROMAQ"      FILE "PROMAQ.DBF"    VIA ( cDriver() ) SHARED INDEX "PROMAQ.CDX"
      DATABASE NEW ::oArticulos  PATH ( cPatEmp() ) CLASS "ARTICULOS"   FILE "ARTICULO.DBF"  VIA ( cDriver() ) SHARED INDEX "ARTICULO.CDX"
      DATABASE NEW ::oFamArt     PATH ( cPatEmp() ) CLASS "FAMART"      FILE "FAMILIAS.DBF"  VIA ( cDriver() ) SHARED INDEX "FAMILIAS.CDX"
      DATABASE NEW ::oAlmacen    PATH ( cPatEmp() ) CLASS "ALMACEN"     FILE "ALMACEN.DBF"   VIA ( cDriver() ) SHARED INDEX "ALMACEN.CDX"

      ::oCnfFlt   := TDataCenter():oCnfFlt()

   RECOVER USING oError

      msgStop( ErrorMessage( oError ), "Imposible abrir las bases de datos de producci�n" )

      ::CloseFiles()

      lOpen       := .f.

   END SEQUENCE

   ErrorBlock( oBlock )

RETURN ( lOpen )

//---------------------------------------------------------------------------//

METHOD CloseFiles() CLASS TFastProduccion

   if !Empty( ::oProCab ) .and. ( ::oProCab:Used() )
      ::oProCab:end()
   end if

   if !Empty( ::oProLin ) .and. ( ::oProLin:Used() )
      ::oProLin:end()
   end if

   if !Empty( ::oProMat ) .and. ( ::oProMat:Used() )
      ::oProMat:end()
   end if

   if !Empty( ::oProPer ) .and. ( ::oProPer:Used() )
      ::oProPer:end()
   end if

   if !Empty( ::oHorasPers ) .and. ( ::oHorasPers:Used() )
      ::oHorasPers:end()
   end if

   if !Empty( ::oMaqLin ) .and. ( ::oMaqLin:Used() )
      ::oMaqLin:end()
   end if

   if !Empty( ::oProMaq ) .and. ( ::oProMaq:Used() )
      ::oProMaq:end()
   end if

   if !Empty( ::oArticulos ) .and. ( ::oArticulos:Used() )
      ::oArticulos:end()
   end if

   if !Empty( ::oFamArt ) .and. ( ::oFamArt:Used() )
      ::oFamArt:end()
   end if

   if !Empty( ::oAlmacen ) .and. ( ::oAlmacen:Used() )
      ::oAlmacen:end()
   end if

   if !Empty( ::oCnfFlt ) .and. ( ::oCnfFlt:Used() )
      ::oCnfFlt:end()
   end if

RETURN .t.

//---------------------------------------------------------------------------//

METHOD Create( uParam ) CLASS TFastProduccion

   ::AddField( "cSerDoc",     "C",  1, 0, {|| "" },   "Serie del documento"                     )
   ::AddField( "cNumDoc",     "C",  9, 0, {|| "" },   "N�mero del documento"                    )
   ::AddField( "cSufDoc",     "C",  2, 0, {|| "" },   "Delegaci�n del documento"                )
   ::AddField( "cIdeDoc",     "C", 27, 0, {|| "" },   "Identificador del documento"             )

   ::AddField( "nAnoDoc",     "N",  4, 0, {|| "" },   "A�o del documento"                       )
   ::AddField( "nMesDoc",     "N",  2, 0, {|| "" },   "Mes del documento"                       )
   ::AddField( "dFecDoc",     "D",  8, 0, {|| "" },   "Fecha del documento"                     )

   ::AddField( "cCodOpe",     "C",  3, 0, {|| "" },   "Operaci�n"                               )
   ::AddField( "cCodSec",     "C",  3, 0, {|| "" },   "Secci�n"                                 )

   ::AddField( "nTotDoc",     "N", 16, 6, {|| "" },   "Total documento"                         )
   ::AddField( "nTotPrd",     "N", 16, 6, {|| "" },   "Total producido"                         )
   ::AddField( "nTotMat",     "N", 16, 6, {|| "" },   "Total materias primas"                   )
   ::AddField( "nTotPer",     "N", 16, 6, {|| "" },   "Total horas personal"                    )
   ::AddField( "nTotMaq",     "N", 16, 6, {|| "" },   "Total maquinaria"                        )

   ::AddTmpIndex( "cNumDoc", "cSerDoc + cNumDoc + cSufDoc" )

RETURN ( self )

//---------------------------------------------------------------------------//

Method lValidRegister( cCodigoProveedor ) CLASS TFastProduccion

   if ( ::oDbf:cCodOpe >= ::oGrupoOperacion:Cargo:Desde     .and. ::oDbf:cCodOpe <= ::oGrupoOperacion:Cargo:Hasta )  .and.;
      ( ::oDbf:cCodSec >= ::oGrupoSeccion:Cargo:Desde       .and. ::oDbf:cCodSec <= ::oGrupoSeccion:Cargo:Hasta )

      Return .t.

   end if

/*
lGrupoOperacion
lGrupoTOperacion
lGrupoSeccion
lGrupoAlmacen
lGrupoArticulo
lGrupoFamilia
lGrupoGFamilia
lGrupoTipoArticulo
lGrupoCategoria
lGrupoTemporada
lGrupoOperario
lGrupoMaquina
*/

RETURN ( .f. )


//---------------------------------------------------------------------------//

METHOD AddParteProducccion() CLASS TFastProduccion
   local sTot
   local oError
   local oBlock
   local cExpHead
   
   oBlock               := ErrorBlock( {| oError | ApoloBreak( oError ) } )
   BEGIN SEQUENCE

      ::oProCab:OrdSetFocus( "dFecOrd" )

      cExpHead          := 'dFecOrd >= Ctod( "' + Dtoc( ::dIniInf ) + '" ) .and. dFecOrd <= Ctod( "' + Dtoc( ::dFinInf ) + '" )'
      cExpHead          += ' .and. cSerOrd >= "' + Rtrim( ::oGrupoSerie:Cargo:Desde ) + '" .and. cSerOrd <= "'    + Rtrim( ::oGrupoSerie:Cargo:Hasta ) + '"'

      ::oProCab:AddTmpIndex( cCurUsr(), GetFileNoExt( ::oProCab:cFile ), ::oProCab:OrdKey(), ( cExpHead ), , , , , , , , .t. )

      ::oMtrInf:cText   := "Procesando partes de producci�n"
      ::oMtrInf:SetTotal( ::oProCab:OrdKeyCount() )

      ::oProCab:GoTop()
      while !::lBreak .and. !::oProCab:Eof()

         ::oDbf:Blank()

         ::oDbf:cSerDoc    := ::oProCab:cSerOrd
         ::oDbf:cNumDoc    := Str( ::oProCab:nNumOrd )
         ::oDbf:cSufDoc    := ::oProCab:cSufOrd

         ::oDbf:nAnoDoc    := Year( ::oProCab:dFecOrd )
         ::oDbf:nMesDoc    := Month( ::oProCab:dFecOrd )
         ::oDbf:dFecDoc    := ::oProCab:dFecOrd

         ::oDbf:cCodOpe    := ::oProCab:cCodOpe
         ::oDbf:cCodSec    := ::oProCab:cCodSec

         ::oDbf:nTotPrd    := nTotProd( ::oProCab:cSerOrd + Str(::oProCab:nNumOrd ) + ::oProCab:cSufOrd, ::oProLin:cAlias )
         ::oDbf:nTotMat    := nTotMat( ::oProCab:cSerOrd + Str(::oProCab:nNumOrd ) + ::oProCab:cSufOrd, ::oProMat:cAlias )
         ::oDbf:nTotPer    := nTotPer( ::oProCab:cSerOrd + Str(::oProCab:nNumOrd ) + ::oProCab:cSufOrd, ::oHorasPers:cAlias )
         ::oDbf:nTotMaq    := nTotMaq( ::oProCab:cSerOrd + Str(::oProCab:nNumOrd ) + ::oProCab:cSufOrd, ::oProMaq:cAlias )
         ::oDbf:nTotDoc    := nTotParte( ::oProCab:cSerOrd + Str(::oProCab:nNumOrd ) + ::oProCab:cSufOrd, ::oProLin:cAlias, ::oProMat:cAlias, ::oHorasPers:cAlias, ::oProMaq:cAlias )

         /*
         A�adimos un nuevo registro--------------------------------------------
         */

         if ::lValidRegister()
            ::oDbf:Insert()
         else
            ::oDbf:Cancel()
         end if

         ::oProCab:Skip()

         ::oMtrInf:AutoInc()

      end while

      ::oProCab:IdxDelete( cCurUsr(), GetFileNoExt( ::oProCab:cFile ) )
   
   RECOVER USING oError

      msgStop( ErrorMessage( oError ), "Imposible a�adir partes de producci�n" )

   END SEQUENCE

   ErrorBlock( oBlock )

   ::oMtrInf:SetTotal( ::oDbf:OrdKeyCount() )

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD StartDialog() CLASS TFastProduccion

   ::CreateTreeImageList()

   ::BuildTree()

 RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD BuildTree( oTree, lLoadFile ) CLASS TFastProduccion

   local aReports

   DEFAULT oTree     := ::oTreeReporting
   DEFAULT lLoadFile := .t.

   aReports          := {  {  "Title" => "Partes de produccion", "Image" => 14, "Type" => "Partes de produccion", "Directory" => "Produccion", "File" => "Partes de produccion.fr3"  } }

   ::BuildNode( aReports, oTree, lLoadFile )

   //oTree:ExpandAll()

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD DataReport( oFr ) CLASS TFastProduccion

   /*
   Zona de detalle-------------------------------------------------------------
   */

   ::oFastReport:SetWorkArea(       "Informe", ::oDbf:nArea )
   ::oFastReport:SetFieldAliases(   "Informe", cObjectsToReport( ::oDbf ) )

   /*
   Zona de datos---------------------------------------------------------------
   */

   ::oFastReport:SetWorkArea(       "Empresa", ::oDbfEmp:nArea )
   ::oFastReport:SetFieldAliases(   "Empresa", cItemsToReport( aItmEmp() ) )

   ::oFastReport:SetWorkArea(       "Lineas de material producido", ::oProLin:nArea )
   ::oFastReport:SetFieldAliases(   "Lineas de material producido", cObjectsToReport( TDetProduccion():DefineFiles()  ) )

   ::oFastReport:SetWorkArea(       "Lineas de materias primas", ::oProMat:nArea )
   ::oFastReport:SetFieldAliases(   "Lineas de materias primas", cObjectsToReport( TDetMaterial():DefineFiles()  ) )

   ::oFastReport:SetWorkArea(       "Lineas de personal", ::oProPer:nArea )
   ::oFastReport:SetFieldAliases(   "Lineas de personal", cObjectsToReport( TDetPersonal():DefineFiles() ) )

   ::oFastReport:SetWorkArea(       "Lineas de horas de personal", ::oHorasPers:nArea )
   ::oFastReport:SetFieldAliases(   "Lineas de horas de personal", cObjectsToReport( TDetHorasPersonal():DefineFiles()  ) )

   ::oFastReport:SetWorkArea(       "Lineas de costo de maquinaria", ::oProMaq:nArea )
   ::oFastReport:SetFieldAliases(   "Lineas de costo de maquinaria", cObjectsToReport( TDetMaquina():DefineFiles()  ) )

   ::oFastReport:SetWorkArea(       "Operarios", ::oOperario:oDbf:nArea )
   ::oFastReport:SetFieldAliases(   "Operarios", cObjectsToReport( TOperarios():DefineFiles() ) )

   /*
   Relaciones------------------------------------------------------------------
   */

   ::oFastReport:SetMasterDetail(   "Informe", "Empresa",         {|| cCodEmp() } )
   ::oFastReport:SetMasterDetail(   "Informe", "Lineas de material producido",   {|| ::oDbf:cSerDoc + ::oDbf:cNumDoc + ::oDbf:cSufDoc } )
   ::oFastReport:SetMasterDetail(   "Informe", "Lineas de materias primas",   {|| ::oDbf:cSerDoc + ::oDbf:cNumDoc + ::oDbf:cSufDoc } )
   ::oFastReport:SetMasterDetail(   "Informe", "Lineas de personal",   {|| ::oDbf:cSerDoc + ::oDbf:cNumDoc + ::oDbf:cSufDoc } )
   ::oFastReport:SetMasterDetail(   "Informe", "Lineas de costo de maquinaria",   {|| ::oDbf:cSerDoc + ::oDbf:cNumDoc + ::oDbf:cSufDoc } )
   ::oFastReport:SetMasterDetail(   "Lineas de personal", "Operarios",   {|| ::oProPer:cCodTra } )
   ::oFastReport:SetMasterDetail(   "Lineas de personal", "Lineas de horas de personal",   {|| ::oProPer:cSerOrd + Str( ::oProPer:nNumOrd) + ::oProPer:cSuford + ::oProPer:cCodTra } )

   ::oFastReport:SetResyncPair(     "Informe", "Empresa" )
   ::oFastReport:SetResyncPair(     "Informe", "Lineas de material producido" )
   ::oFastReport:SetResyncPair(     "Informe", "Lineas de materias primas" )
   ::oFastReport:SetResyncPair(     "Informe", "Lineas de personal" )
   ::oFastReport:SetResyncPair(     "Informe", "Lineas de costo de maquinaria" )
   ::oFastReport:SetResyncPair(     "Lineas de personal", "Lineas de horas de personal" )
   ::oFastReport:SetResyncPair(     "Lineas de personal", "Operarios" )

   //----------------------------------------------------------

   ::AddVariable()

Return ( Self )

//---------------------------------------------------------------------------//

METHOD AddVariable() CLASS TFastProduccion 

   /*
   Tablas en funcion del tipo de informe---------------------------------------
   */
   // al tener solo un tipo de de informe no necesitamos el case
   
   ::AddVariableLineasParteProduccion()

Return ( Super:AddVariable() )

//---------------------------------------------------------------------------//

METHOD lGenerate() CLASS TFastProduccion

   ::oDbf:Zap()

   /*
   Recorremos los partes de produccion------------------------------------------------------
   */

   ::AddParteProducccion()

   ::oDbf:SetFilter( ::oFilter:cExpresionFilter )

   ::oDbf:GoTop()

RETURN ( ::oDbf:LastRec() > 0 )

//---------------------------------------------------------------------------//
