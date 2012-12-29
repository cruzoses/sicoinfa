#include "FiveWin.Ch"
#include "Font.ch"
#include "Factu.ch"
#include "MesDbf.ch"

//---------------------------------------------------------------------------//

CLASS TLisAgeInf FROM TInfGen

   METHOD Create()

   METHOD OpenFiles()

   METHOD CloseFiles()

   METHOD lResource( cFld )

   METHOD lGenerate()

   METHOD oDefIniInf()  VIRTUAL
   METHOD oDefFinInf()  VIRTUAL

END CLASS

//---------------------------------------------------------------------------//

METHOD Create()

   ::AddField ( "CCODAGE", "C",  3, 0, {|| "@!" },   "Age",                       .f., "Cod. Agente",                 3 )
   ::AddField ( "CNOMAGE", "C", 50, 0, {|| "@!" },   "Nom Age",                   .f., "Nom. Agente",                25 )
   ::AddField ( "CCODGRP", "C",  4, 0, {|| "@!" },   "Grp.",                      .f., "C�digo de grupo de cliente",  6 )
   ::AddField ( "CCODCLI", "C", 12, 0, {|| "@!" },   "Cliente",                   .t., "Cod. Cliente",                8 )
   ::AddField ( "CNOMCLI", "C", 50, 0, {|| "@!" },   "Nombre",                    .t., "Nom. Cliente",               50 )
   ::AddField ( "CNIFCLI", "C", 15, 0, {|| "@!" },   "Nif",                       .t., "Nif",                        15 )
   ::AddField ( "CDOMCLI", "C", 35, 0, {|| "@!" },   "Domicilio",                 .t., "Domicilio",                  25 )
   ::AddField ( "CPOBCLI", "C", 25, 0, {|| "@!" },   "Poblaci�n",                 .f., "Poblaci�n",                  25 )
   ::AddField ( "CPROCLI", "C", 20, 0, {|| "@!" },   "Provincia",                 .f., "Provincia",                  20 )
   ::AddField ( "CCDPCLI", "C",  7, 0, {|| "@!" },   "C�digo postal",             .f., "Cod. Postal",                 7 )
   ::AddField ( "CTLFCLI", "C", 12, 0, {|| "@!" },   "Tel�fono",                  .f., "Tel�fono",                   12 )
   ::AddField ( "CDEFI01", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(1) },      .f., {|| ::cNameIniCli(1) },       50 )
   ::AddField ( "CDEFI02", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(2) },      .f., {|| ::cNameIniCli(2) },       50 )
   ::AddField ( "CDEFI03", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(3) },      .f., {|| ::cNameIniCli(3) },       50 )
   ::AddField ( "CDEFI04", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(4) },      .f., {|| ::cNameIniCli(4) },       50 )
   ::AddField ( "CDEFI05", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(5) },      .f., {|| ::cNameIniCli(5) },       50 )
   ::AddField ( "CDEFI06", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(6) },      .f., {|| ::cNameIniCli(6) },       50 )
   ::AddField ( "CDEFI07", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(7) },      .f., {|| ::cNameIniCli(7) },       50 )
   ::AddField ( "CDEFI08", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(8) },      .f., {|| ::cNameIniCli(8) },       50 )
   ::AddField ( "CDEFI09", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(9) },      .f., {|| ::cNameIniCli(9) },       50 )
   ::AddField ( "CDEFI10", "C",100, 0, {|| "@!" },   {|| ::cNameIniCli(10)},      .f., {|| ::cNameIniCli(10)},       50 )

   ::AddTmpIndex( "CCODAGE", "CCODAGE + CCODGRP + CCODCLI" )
   ::AddGroup( {|| ::oDbf:cCodAge }, {|| "Agente  : " + Rtrim( ::oDbf:cCodAge ) + "-" + oRetFld( ::oDbf:cCodAge, ::oDbfAge ) } )
   ::AddGroup( {|| ::oDbf:cCodAge + ::oDbf:cCodGrp }, {|| "Grupo  : " + Rtrim( ::oDbf:cCodGrp ) + "-" + oRetFld( ::oDbf:cCodGrp, ::oGrpCli:oDbf ) } )

RETURN ( self )

//---------------------------------------------------------------------------//

METHOD OpenFiles() CLASS TLisAgeInf

RETURN ( self )

//---------------------------------------------------------------------------//

METHOD CloseFiles() CLASS TLisAgeInf

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD lResource( cFld ) CLASS TLisAgeInf

   if !::StdResource( "INF_GEN23" )
      return .f.
   end if

   /*
   Monta los agentes de manera automatica
   */

   if !::oDefAgeInf( 70, 80, 90, 100, 930 )
      return .f.
   end if

   /*
   Monta los grupos de clientes
   */

   if !::oDefGrpCli( 170, 171, 180, 181, 888 )
      return .f.
   end if

   /*
   Monta los clientes de manera autom�tica
   */

   if !::oDefCliInf( 110, 120, 130, 140, , 600 )
      return .f.
   end if

   /*
   Damos valor al meter
   */

   ::oMtrInf:SetTotal( ::oDbfCli:Lastrec() )

   ::CreateFilter( aItmCli(), ::oDbfCli:cAlias )

RETURN .t.

//---------------------------------------------------------------------------//
/*
Esta funcion crea la base de datos para generar posteriormente el informe
*/

METHOD lGenerate()

   local cExpHead := ""

   ::oDlg:Disable()
   ::oBtnCancel:Enable()
   ::oDbf:Zap()

   ::oDbfCli:GoTop()

   ::aHeader   := {{|| "Fecha         : "   + Dtoc( Date() ) },;
                   {|| "Agentes       : "   + AllTrim( ::cAgeOrg ) + " > " + AllTrim( ::cAgeDes ) },;
                   {|| "Grp. clientes : "   + AllTrim( ::cGrpOrg ) + " > " + AllTrim( ::cGrpDes ) },;
                   {|| "Clientes      : "   + AllTrim( ::cCliOrg ) + " > " + AllTrim( ::cCliDes ) } }

   ::oDbfCli:OrdSetFocus( "COD" )

   if !Empty( ::oFilter:cExpFilter )
      cExpHead       := ::oFilter:cExpFilter
   else
      cExpHead       := '.t.'
   end if

   ::oDbfCli:AddTmpIndex( cCurUsr(), GetFileNoExt( ::oDbfCli:cFile ), ::oDbfCli:OrdKey(), ( cExpHead ), , , , , , , , .t. )

   ::oMtrInf:SetTotal( ::oDbfCli:OrdKeyCount() )

   /*
   Nos movemos por las cabeceras de los clientes
   */

   while !::lBreak .and. !::oDbfCli:Eof()

      if ( ::lAllCli .or. ( ::oDbfCli:Cod >= ::cCliOrg .and. ::oDbfCli:Cod <= ::cCliDes ))           .and.;
         ( ::lGrpAll .or. ( ::oDbfCli:cCodGrp >= ::cGrpOrg .and. ::oDbfCli:cCodGrp <= ::cGrpDes ))   .and.;
         ( ::lAgeAll .or. ( ::oDbfCli:cAgente >= ::cAgeOrg .and. ::oDbfCli:cAgente <= ::cAgeDes ) )

         ::oDbf:Append()

         ::oDbf:cCodAge := ::oDbfCli:cAgente
         ::oDbf:cNomAge := ::oDbfAge:cNbrAge
         ::oDbf:cCodGrp := ::oDbfCli:cCodGrp
         ::oDbf:cCodCli := ::oDbfCli:Cod
         ::oDbf:cNomCli := ::oDbfCli:Titulo
         ::oDbf:CNIFCLI := ::oDbfCli:Nif
         ::oDbf:CDOMCLI := ::oDbfCli:Domicilio
         ::oDbf:CPOBCLI := ::oDbfCli:Poblacion
         ::oDbf:CPROCLI := ::oDbfCli:Provincia
         ::oDbf:CCDPCLI := ::oDbfCli:CodPostal
         ::oDbf:CTLFCLI := ::oDbfCli:Telefono
         ::oDbf:CDEFI01 := ::oDbfCli:CusRDef01
         ::oDbf:CDEFI02 := ::oDbfCli:CusRDef02
         ::oDbf:CDEFI03 := ::oDbfCli:CusRDef03
         ::oDbf:CDEFI04 := ::oDbfCli:CusRDef04
         ::oDbf:CDEFI05 := ::oDbfCli:CusRDef05
         ::oDbf:CDEFI06 := ::oDbfCli:CusRDef06
         ::oDbf:CDEFI07 := ::oDbfCli:CusRDef07
         ::oDbf:CDEFI08 := ::oDbfCli:CusRDef08
         ::oDbf:CDEFI09 := ::oDbfCli:CusRDef09
         ::oDbf:CDEFI10 := ::oDbfCli:CusRDef10

         ::oDbf:Save()

      end if

      ::oDbfCli:Skip()

      ::oMtrInf:AutoInc( ::oDbfCli:OrdKeyNo() )

   end while

   ::oDbfCli:IdxDelete( cCurUsr(), GetFileNoExt( ::oDbfCli:cFile ) )

   ::oMtrInf:AutoInc( ::oDbfCli:LastRec() )

   ::oDlg:Enable()

RETURN ( ::oDbf:LastRec() > 0 )

//---------------------------------------------------------------------------//