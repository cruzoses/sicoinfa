#include "FiveWin.Ch"
#include "Font.ch"
#include "Factu.ch" 
#include "MesDbf.ch"

//---------------------------------------------------------------------------//

FUNCTION DtaAgeTpv()

   local oInf
   local aCol  := {}
   local aIdx  := {}

   aAdd( aCol, { "CCODAGE", "C",  3, 0,  {|| "@!" },         "Cod. age.",                 .f., "Cod. agente",                 3 } )
   aAdd( aCol, { "CNOMAGE", "C", 50, 0,  {|| "@!" },         "Agente",                    .f., "Nom. agente",                25 } )
   aAdd( aCol, { "CCODCLI", "C", 12, 0,  {|| "@!" },         "Cod. cli.",                 .t., "Cod. cliente",               12 } )
   aAdd( aCol, { "CNOMCLI", "C", 50, 0,  {|| "@!" },         "Nombre",                    .t., "Nom. cliente",               35 } )
   aAdd( aCol, { "CNIFCLI", "C", 15, 0,  {|| "@!" },         "Nif",                       .f., "Nif",                        12 } )
   aAdd( aCol, { "CDOMCLI", "C", 35, 0,  {|| "@!" },         "Domicilio",                 .f., "Domicilio",                  40 } )
   aAdd( aCol, { "CPOBCLI", "C", 35, 0,  {|| "@!" },         "Poblaci�n",                 .f., "Poblaci�n",                  25 } )
   aAdd( aCol, { "CPROCLI", "C", 20, 0,  {|| "@!" },         "Provincia",                 .f., "Provincia",                  20 } )
   aAdd( aCol, { "CCDPCLI", "C",  7, 0,  {|| "@!" },         "Cod. Postal",               .f., "Cod. Postal",                 7 } )
   aAdd( aCol, { "CTLFCLI", "C", 12, 0,  {|| "@!" },         "Tel�fono",                  .f., "Tel�fono",                   12 } )
   aAdd( aCol, { "CREFART", "C", 18, 0,  {|| "@!" },         "C�digo art�culo",                 .f., "Cod. art�culo",              14 } )
   aAdd( aCol, { "CDESART", "C", 50, 0,  {|| "@!" },         "Descripci�n",               .f., "Descripci�n",                25 } )
   aAdd( aCol, { "CCSUFAC", "C", 12, 0,  {|| "@!" },         "Su factura",                .f., "Su factura N�",              12 } )
   aAdd( aCol, { "DFECMOV", "D",  8, 0,  {|| "@!" },         "Fecha",                     .f., "Fecha",                      12 } )
   aAdd( aCol, { "NUNDCAJ", "N", 13, 6,  {|| MasUnd () },    "Cajas",                     .f., "Cajas",                      14 } )
   aAdd( aCol, { "NUNDART", "N", 13, 6,  {|| MasUnd () },    "Und.",                      .t., "Unidades",                   14 } )
   aAdd( aCol, { "NCAJUND", "N", 13, 6,  {|| MasUnd () },    "Tot. Und.",                 .f., "Total unidades",             12 } )
   aAdd( aCol, { "NBASCOM", "N", 13, 6,  {|| oInf:cPicOut }, "Base",                      .t., "Base comisi�n",              12 } )
   aAdd( aCol, { "NCOMAGE", "N",  4, 1,  {|| "@E 99,99" },   "%Com",                      .t., "Porcentaje de comisi�n",     12 } )
   aAdd( aCol, { "NTOTCOM", "N", 13, 6,  {|| oInf:cPicOut }, "Comisi�n",                  .t., "Importe comisi�n",           12 } )
   aAdd( aCol, { "CDOCMOV", "C", 14, 0,  {|| "@!" },         "Factura",                   .t., "Factura",                    14 } )
   aAdd( aCol, { "DFECMOV", "D",  8, 0,  {|| "@!" },         "Fecha",                     .t., "Fecha",                       8 } )
   aAdd( aCol, { "CTIPVEN", "C", 20, 0,  {|| "@!" },         "Venta",                     .f., "Tipo de venta",              20 } )

   aAdd( aIdx, { "CNOMAGE", "CNOMAGE + CREFART" } )

   oInf  := TDLAgeTpv():New( "Informe detallado de la liquidaci�n de agentes agrupados por art�culos en tikets", aCol, aIdx, "01047" )

   oInf:AddGroup( {|| oInf:oDbf:cNomAge },                     {|| "Agente   : " + Rtrim( oInf:oDbf:cNomAge ) + "-" + oRetFld( oInf:oDbf:cNomAge, oInf:oDbfAge ) }, {||"Total agente..."} )
   oInf:AddGroup( {|| oInf:oDbf:cNomAge + oInf:oDbf:cDesArt }, {|| "Art�culo : " + Rtrim( oInf:oDbf:cRefArt ) + "-" + Rtrim( oInf:oDbf:cDesArt ) }, {||""} )

   oInf:Resource()
   oInf:Activate()

   // oInf:End()
   oInf  := nil

RETURN NIL

//---------------------------------------------------------------------------//

CLASS TdlAgeFac FROM TInfGen

   DATA  lResumen    AS LOGIC    INIT .f.
   DATA  lExcCero    AS LOGIC    INIT .f.
   DATA  cEstado     AS CHARACTER     INIT  ""
   DATA  oEstado     AS OBJECT
   DATA  oTpvCliT    AS OBJECT
   DATA  oTpvCliL    AS OBJECT
   DATA  aEstado     AS ARRAY    INIT  { "" }

   METHOD OpenFiles()

   METHOD CloseFiles()

   METHod lResource( cFld )

   METHOD lGenerate()

END CLASS

//---------------------------------------------------------------------------//

METHOD OpenFiles() CLASS TdlAgeFac

   local lOpen    := .t.
   local oBlock   := ErrorBlock( {| oError | ApoloBreak( oError ) } )

   BEGIN SEQUENCE

   DATABASE NEW ::oTpvCliT  PATH ( cPatEmp() ) FILE "TIKET.DBF" VIA ( cDriver() ) SHARED INDEX "TIKET.CDX"

   DATABASE NEW ::oTpvCliL  PATH ( cPatEmp() ) FILE "TIKEL.DBF" VIA ( cDriver() ) SHARED INDEX "TIKEL.CDX"

   DATABASE NEW ::oDbfCli   PATH ( cPatCli() ) FILE "CLIENT.DBF"  VIA ( cDriver() ) SHARED INDEX "CLIENT.CDX"

   RECOVER

      msgStop( "Imposible abrir todas las bases de datos" )
      ::CloseFiles()
      lOpen          := .f.

   END SEQUENCE

   ErrorBlock( oBlock )

RETURN ( lOpen )

//---------------------------------------------------------------------------//

METHOD CloseFiles() CLASS TdlAgeFac

   if !Empty( ::oTpvCliT )
      ::oTpvCliT:End()
   end if
   if !Empty( ::oTpvCliL )
      ::oTpvCliL:End()
   end if
   if !Empty( ::oDbfCli )
      ::oDbfCli:End()
   end if

   ::oTpvCliT := Nil
   ::oTpvCliL := Nil
   ::oDbfCli  := Nil

RETURN ( Self )

//---------------------------------------------------------------------------//

METHod lResource( cFld ) CLASS TdlAgeFac

   local oTipVen
   local oTipVen2
   local cEstado     := ""
   local This        := Self

   if !::StdResource( "INF_GEN17B" )
      return .f.
   end if

   /*
   Monta los agentes de manera automatica
   */

   ::oDefAgeInf( 70, 80, 90, 100 )

   ::oDefResInf()

   ::oDefExcImp()

   /*
   Monta los articulos de manera automatica
   */

   ::lDefArtInf( 110, 120, 130, 140 )

   ::oMtrInf:SetTotal( ::oTpvCliT:Lastrec() )

RETURN ( Self )

//---------------------------------------------------------------------------//
/*
Esta funcion crea la base de datos para generar posteriormente el informe
*/

METHOD lGenerate() CLASS TdlAgeFac

   local bValid   := {|| .t. }
   local lExcCero := .f.

   ::oDlg:Disable()

   ::oDbf:Zap()
   ::oTpvCliT:GoTop()

  ::aHeader       := {  {|| "Fecha   : " + Dtoc( Date() ) },;
                        {|| "Periodo : " + Dtoc( ::dIniInf ) + " > " + Dtoc( ::dFinInf ) },;
                        {|| "Agentes : " + ::cAgeOrg         + " > " + ::cAgeDes } }

	/*
   Nos movemos por las cabeceras de los albaranes
   */

   WHILE ! ::oTpvCliT:Eof()

      IF Eval( bValid )                                                                     .AND.;
         ::oTpvCliT:DFECFAC >= ::dIniInf                                                    .AND.;
         ::oTpvCliT:DFECFAC <= ::dFinInf                                                    .AND.;
         ::oTpvCliT:CCODAGE >= ::cAgeOrg                                                    .AND.;
         ::oTpvCliT:CCODAGE <= ::cAgeDes                                                    .AND.;
         lChkSer( ::oTpvCliT:cSerie, ::aSer )

         /*
         Posicionamos en las lineas de detalle --------------------------------
         */

         if ::oTpvCliL:Seek( ::oTpvCliT:cSerie + Str( ::oTpvCliT:NNUMFAC ) + ::oTpvCliT:CSUFFAC )

            while ::oTpvCliT:cSerie + Str( ::oTpvCliT:NNUMFAC ) + ::oTpvCliT:CSUFFAC == ::oTpvCliL:cSerie + Str( ::oTpvCliL:NNUMFAC ) + ::oTpvCliL:CSUFFAC .AND. ! ::oTpvCliL:eof()

               if ::oTpvCliL:CREF >= ::cArtOrg                                      .AND.;
                  ::oTpvCliL:CREF <= ::cArtDes                                      .AND.;
                  !( ::lExcImp .and. ( nTotLFacCli( ::oTpvCliL:cAlias, ::nDecOut, ::nDerOut, ::nValDiv ) == 0 ) )

                  ::oDbf:Append()

                  ::oDbf:cCodAge := ::oTpvCliT:cCodAge
                  ::oDbf:CCODCLI := ::oTpvCliT:cCodCli
                  ::oDbf:CNOMCLI := ::oTpvCliT:cNomCli
                  ::oDbf:DFECMOV := ::oTpvCliT:dFecFac
                  ::oDbf:CCSUFAC := ::oTpvCliT:cSufFac
                  ::oDbf:CDOCMOV := ::oTpvCliT:cSerie + "/" + Str( ::oTpvCliT:NNUMFAC ) + "/" + ::oTpvCliT:CSUFFAC
                  ::oDbf:CREFART := ::oTpvCliL:cRef
                  ::oDbf:CDESART := ::oTpvCliL:cDetalle

                  ::AddCliente( ::oTpvCliT:CCODCLI, ::oTpvCliT, .t. )

                  if ( ::oDbfAge:Seek ( ::oTpvCliT:cCodAge ) )
                     ::oDbf:cNomAge := Rtrim( ::oDbfAge:cApeAge ) + ", " + Rtrim( ::oDbfAge:cNbrAge )
                  end if

                  ::oDbf:NUNDCAJ := ::oTpvCliL:NCANENT
                  ::oDbf:NCAJUND := NotCaja( ::oTpvCliL:NCANENT ) * ::oTpvCliL:NUNICAJA
                  ::oDbf:NUNDART := ::oTpvCliL:NUNICAJA
                  ::oDbf:nComAge := ::oTpvCliL:nComAge
                  ::oDbf:nBasCom := nImpLFacCli( ::oTpvCliT:cAlias, ::oTpvCliL:cAlias, ::nDecOut, ::nDerOut, ::nValDiv, .f., .t., .f., .f. )
                  ::oDbf:nTotCom := nComLFacCli( ::oTpvCliT:cAlias, ::oTpvCliL:cAlias, ::nDecOut, ::nDerOut, ::nValDiv )

                  ::oDbf:Save()

               end if

            ::oTpvCliL:Skip()

            end while

         end if

      end if

      ::oTpvCliT:Skip()

      ::oMtrInf:AutoInc( ::oTpvCliT:OrdKeyNo() )

   end while

   ::oDlg:Enable()

RETURN ( ::oDbf:LastRec() > 0 )

//---------------------------------------------------------------------------//