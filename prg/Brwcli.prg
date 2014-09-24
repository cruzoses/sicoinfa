#include "FiveWin.Ch"
#include "Folder.ch"
#include "Report.ch"
#include "Label.ch"
#include "Factu.ch" 
#include "MesDbf.ch"
#include "TGraph.ch"
#include "Xbrowse.ch"

static dbfAlbCliT
static dbfAlbCliL
static dbfAlbCliP
static dbfFacCliT
static dbfFacCliL
static dbfFacCliP
static dbfFacRecT
static dbfFacRecL
static dbfPreCliT
static dbfPreCliL
static dbfPedCliT
static dbfPedCliL
static dbfPedCliR
static dbfPedCliP
static dbfTikCliT
static dbfTikCliL
static dbfTikCliP
static dbfAntCliT
static dbfFPago
static dbfIva
static dbfDiv
static dbfClient
static dbfSatCliT
static dbfSatCliL
static dbfSatCliS
static dbfCategoria

static oDbfTmp
static oDbfTmpMaq
static oDbfTmpMaqL
static oOperario

static oBtnFiltro

static oMeter
static nMeter

static oText
static cText      := "" 

static cPouDiv
static cPinDiv
static cPirDiv
static cPorDiv
static nDouDiv
static nDorDiv
static nDinDiv
static nDirDiv
static cPicUnd
static nVdvDiv

static oMenu

static oGraph

static oTreeDocument
static oTreeDocumentos
static oTreeCobros
static oTreeImageList

static oVta
static aVta
static nCobTik       := 0
static nValTik       := 0
static nCobFac       := 0
static nCobAnt       := 0
static nTotCob       := 0
static nPdtFac       := 0
static nFacRec       := 0
static nTotTik       := 0
static nTotFac       := 0
static nTotEnt       := 0
static nTotPed       := 0
static oTotVta
static aTotVta
static oPdtFac
static oTotVal
static oTotCob
static oCobAnt
static oFacRec
static oTotTik
static oTotFac
static oTotPdt
static oTotRie
static oTotEnt
static oTotPed

static lOpenFiles    := .f.

//---------------------------------------------------------------------------//

Static Function OpenFiles( lMessage )

   local oError
   local oBlock

   DEFAULT lMessage  := .t.

   CursorWait()

   oTotVta           := Array( 4 )
   aTotVta           := Afill( Array( 4 ), 0 )

   oVta              := Array( 12, 4 )
   aVta              := Array( 12, 4 )

   aEval( aVta, {|a| Afill( a, 0 ) } )

   oBlock            := ErrorBlock( {| oError | ApoloBreak( oError ) } )
   BEGIN SEQUENCE

      USE ( cPatDat() + "DIVISAS.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "DIVISAS", @dbfDiv ) )
      SET ADSINDEX TO ( cPatDat() + "DIVISAS.CDX" ) ADDITIVE

      USE ( cPatCli() + "CLIENT.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "CLIENT", @dbfClient ) )
      SET ADSINDEX TO ( cPatCli() + "CLIENT.CDX" ) ADDITIVE

      USE ( cPatDat() + "TIVA.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "TIVA", @dbfIva ) )
      SET ADSINDEX TO ( cPatDat() + "TIVA.CDX" ) ADDITIVE

      /*
      Documentos relacionados de ventas
      */

      USE ( cPatEmp() + "SATCLIT.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "SATCLIT", @dbfSatCliT ) )
      SET ADSINDEX TO ( cPatEmp() + "SATCLIT.CDX" ) ADDITIVE

      USE ( cPatEmp() + "SATCLIL.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "SATCLIL", @dbfSatCliL ) )
      SET ADSINDEX TO ( cPatEmp() + "SATCLIL.CDX" ) ADDITIVE

      USE ( cPatEmp() + "SATCLIS.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "SATCLIS", @dbfSatCliS ) )
      SET ADSINDEX TO ( cPatEmp() + "SATCLIS.CDX" ) ADDITIVE

      USE ( cPatEmp() + "PRECLIL.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "PRECLIL", @dbfPreCliL ) )
      SET ADSINDEX TO ( cPatEmp() + "PRECLIL.CDX" ) ADDITIVE

      USE ( cPatEmp() + "PEDCLIL.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "PEDCLIL", @dbfPedCliL ) )
      SET ADSINDEX TO ( cPatEmp() + "PEDCLIL.CDX" ) ADDITIVE

      USE ( cPatEmp() + "PEDCLIR.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "PEDCLIR", @dbfPedCliR ) )
      SET ADSINDEX TO ( cPatEmp() + "PEDCLIR.CDX" ) ADDITIVE

      USE ( cPatEmp() + "PEDCLIP.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "PEDCLIP", @dbfPedCliP ) )
      SET ADSINDEX TO ( cPatEmp() + "PEDCLIP.CDX" ) ADDITIVE
      SET TAG TO "CCODCLI"

      USE ( cPatEmp() + "ALBCLIL.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "ALBCLIL", @dbfAlbCliL ) )
      SET ADSINDEX TO ( cPatEmp() + "ALBCLIL.CDX" ) ADDITIVE

      USE ( cPatEmp() + "ALBCLIP.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "ALBCLIP", @dbfAlbCliP ) )
      SET ADSINDEX TO ( cPatEmp() + "ALBCLIP.CDX" ) ADDITIVE
      SET TAG TO "CCODCLI"

      USE ( cPatEmp() + "FACCLIL.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "FACCLIL", @dbfFacCliL ) )
      SET ADSINDEX TO ( cPatEmp() + "FACCLIL.CDX" ) ADDITIVE

      USE ( cPatEmp() + "FACRECT.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "FACRECT", @dbfFacRecT ) )
      SET ADSINDEX TO ( cPatEmp() + "FACRECT.CDX" ) ADDITIVE
      SET TAG TO "CCODCLI"

      USE ( cPatEmp() + "FACRECL.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "FACRECL", @dbfFacRecL ) )
      SET ADSINDEX TO ( cPatEmp() + "FACRECL.CDX" ) ADDITIVE

      USE ( cPatEmp() + "AntCliT.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "AntCliT", @dbfAntCliT ) )
      SET ADSINDEX TO ( cPatEmp() + "AntCliT.CDX" ) ADDITIVE
      SET TAG TO "CCODCLI"

      USE ( cPatEmp() + "TIKET.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "TIKET", @dbfTikCliT ) )
      SET ADSINDEX TO ( cPatEmp() + "TIKET.CDX" ) ADDITIVE
      SET TAG TO "CCLITIK"

      USE ( cPatEmp() + "TIKEL.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "TIKEL", @dbfTikCliL ) )
      SET ADSINDEX TO ( cPatEmp() + "TIKEL.CDX" ) ADDITIVE
      SET TAG TO "CNUMTIL"

      USE ( cPatEmp() + "TIKEP.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "TIKEP", @dbfTikCliP ) )
      SET ADSINDEX TO ( cPatEmp() + "TIKEP.CDX" ) ADDITIVE

      USE ( cPatGrp() + "FPAGO.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "FPAGO", @dbfFPago ) )
      SET ADSINDEX TO ( cPatGrp() + "FPAGO.CDX" ) ADDITIVE

      USE ( cPatArt() + "CATEGORIAS.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "CATEGORIA", @dbfCategoria ) )
      SET ADSINDEX TO ( cPatArt() + "CATEGORIAS.CDX" ) ADDITIVE

      if !TDataCenter():OpenPreCliT( @dbfPreCliT )
         lOpenFiles     := .f.
      else
         ( dbfPreCliT )->( ordSetFocus( "cCodCli" ) )
      end if 

      if !TDataCenter():OpenPedCliT( @dbfPedCliT )
         lOpenFiles     := .f.
      else 
         ( dbfPedCliT )->( OrdSetFocus( "cCodCli" ) )
      end if 

      if !TDataCenter():OpenAlbCliT( @dbfAlbCliT )
         lOpenFiles     := .f.
      else 
         ( dbfAlbCliT )->( OrdSetFocus( "cCodCli" ) )
      end if

      if !TDataCenter():OpenFacCliT( @dbfFacCliT )
         lOpenFiles     := .f.
      else 
         ( dbfFacCliT )->( OrdSetFocus( "cCodCli" ) )
      end if

      if !TDataCenter():OpenFacCliP( @dbfFacCliP )
         lOpenFiles     := .f.
      end if

      oOperario         := TOperarios():Create()
      if !oOperario:OpenFiles()
         lOpenFiles     := .f.
      end if

      oDbfTmp           := DefineTemporal()
      oDbfTmp:Activate( .f., .f. )

      oDbfTmpMaq        := DefineTemporalMaquinas()
      oDbfTmpMaq:Activate( .f., .f. )

      oDbfTmpMaqL       := DefineTemporalMaquinasLineas()
      oDbfTmpMaqL:Activate( .f., .f. )

      lOpenFiles        := .t.

   RECOVER USING oError

      if lMessage
         msgStop( ErrorMessage( oError ), "Imposible abrir las bases de datos" )
      end if

      lOpenFiles     := .f.

   END SEQUENCE

   ErrorBlock( oBlock )

   CursorWE()

Return ( lOpenFiles )

//--------------------------------------------------------------------------//

Static Function CloseFiles()

   if oTreeImageList != nil
      oTreeImageList:End()
   end if

   ( dbfSatCliT   )->( dbCloseArea() )
   ( dbfSatCliL   )->( dbCloseArea() )
   ( dbfSatCliS   )->( dbCloseArea() )
   ( dbfPreCliT   )->( dbCloseArea() )
   ( dbfPreCliL   )->( dbCloseArea() )
   ( dbfPedCliT   )->( dbCloseArea() )
   ( dbfPedCliL   )->( dbCloseArea() )
   ( dbfPedCliR   )->( dbCloseArea() )
   ( dbfPedCliP   )->( dbCloseArea() )
   ( dbfAlbCliT   )->( dbCloseArea() )
   ( dbfAlbCliL   )->( dbCloseArea() )
   ( dbfAlbCliP   )->( dbCloseArea() )
   ( dbfFacCliT   )->( dbCloseArea() )
   ( dbfFacCliL   )->( dbCloseArea() )
   ( dbfFacCliP   )->( dbCloseArea() )
   ( dbfFacRecT   )->( dbCloseArea() )
   ( dbfFacRecL   )->( dbCloseArea() )
   ( dbfTikCliT   )->( dbCloseArea() )
   ( dbfTikCliL   )->( dbCloseArea() )
   ( dbfTikCliP   )->( dbCloseArea() )
   ( dbfAntCliT   )->( dbCloseArea() )
   ( dbfDiv       )->( dbCloseArea() )
   ( dbfClient    )->( dbCloseArea() )
   ( dbfIva       )->( dbCloseArea() )
   ( dbfFPago     )->( dbCloseArea() )
   ( dbfCategoria )->( dbCloseArea() )

   if !Empty( oOperario )
      oOperario:End()
   end if

   oDbfTmp:Close()
   oDbfTmpMaq:Close()
   oDbfTmpMaqL:Close()

   dbfErase( oDbfTmp:cPath + oDbfTmp:cName )
   dbfErase( oDbfTmpMaq:cPath + oDbfTmpMaq:cName )
   dbfErase( oDbfTmpMaq:cPath + oDbfTmpMaqL:cName )

   lOpenFiles       := .f.

return .t.

//---------------------------------------------------------------------------//

function BrwVtaCli( cCodCli, cNomCli )

   local oDlg
   local oFld
   local oBrwTmp
   local oBrwVta
   local oBrwMaq
   local oTree
   local oCmbAnio
   local cCmbAnio          := "Todos" //Str( Year( GetSysDate() ) )
   local oBmpGeneral
   local oBmpDocumentos
   local oBmpGraficos
   local oBmpMaquina

   if !OpenFiles( .f. )
      Return nil
   end if

   CursorWait()

   cPicUnd                 := MasUnd()
   cPouDiv                 := cPouDiv( cDivEmp(), dbfDiv )
   cPinDiv                 := cPinDiv( cDivEmp(), dbfDiv )
   cPirDiv                 := cPirDiv( cDivEmp(), dbfDiv )
   cPorDiv                 := cPorDiv( cDivEmp(), dbfDiv )
   nDouDiv                 := nDouDiv( cDivEmp(), dbfDiv )
   nDorDiv                 := nRouDiv( cDivEmp(), dbfDiv )
   nDinDiv                 := nDinDiv( cDivEmp(), dbfDiv ) // Decimales sin redondeo
   nDirDiv                 := nRinDiv( cDivEmp(), dbfDiv ) // Decimales con redondeo
   nVdvDiv                 := nChgDiv( cDivEmp(), dbfDiv )

   /*
   Codigo de cliente-----------------------------------------------------------
   */

   oDbfTmp:Cargo           := cCodCli

   ( dbfClient )->( dbSeek( cCodCli ) )

   /*
   Montamos el dialogo
   */

   DEFINE DIALOG oDlg RESOURCE "ARTINFO" TITLE "Informaci�n del cliente : " + Rtrim( cNomCli )

      REDEFINE FOLDER oFld ;
            ID       300 ;
            OF       oDlg ;
            PROMPT   "E&stadisticas"      ,;
                     "Documentos"         ,;
                     "Gr�fico"            ,;
                     "Art�culos por contador";
            DIALOGS  "CLIENT_9"           ,; 
                     "INFO_1"             ,;
                     "INFO_2"             ,;
                     "INFO_4"

   REDEFINE BITMAP oBmpGeneral ID 500 RESOURCE "Businessman2_Alpha_48" TRANSPARENT OF oFld:aDialogs[ 1 ]

   /*
   Browse con la informaci�n por meses-----------------------------------------
   */

   oBrwVta                       := IXBrowse():New( oFld:aDialogs[ 1 ] )

   oBrwVta:bClrSel               := {|| { CLR_BLACK, Rgb( 229, 229, 229 ) } }
   oBrwVta:bClrSelFocus          := {|| { CLR_BLACK, Rgb( 167, 205, 240 ) } }

   oBrwVta:SetArray( aVta, , , .f. )

   oBrwVta:lFooter            := .t.
   oBrwVta:lVScroll           := .f.
   oBrwVta:lHScroll           := .f.
   oBrwVta:nMarqueeStyle      := 5
   oBrwVta:cName              := "Ventas en informe de clientes"
   oBrwVta:CreateFromResource( 400 )

   with object ( oBrwVta:AddCol() )
      :cHeader                   := "Mes"
      :nWidth                    := 290
      :bStrData                  := {|| cNombreMes( oBrwVta:nArrayAt ) }
      :bFooter                   := {|| "Totales" }
   end with

   with object ( oBrwVta:AddCol() )
      :cHeader                   := cNombreCajas()
      :nWidth                    := 120
      :bEditValue                := {|| aVta[ oBrwVta:nArrayAt, 1] }
      :cEditPicture              := cPicUnd
      :bFooter                   := {|| aTotVta[1] }
      :nDataStrAlign             := 1
      :nHeadStrAlign             := 1
      :nFootStrAlign             := 1
   end with

   with object ( oBrwVta:AddCol() )
      :cHeader                   := cNombreUnidades()
      :nWidth                    := 120
      :bEditValue                := {|| aVta[ oBrwVta:nArrayAt, 2] }
      :cEditPicture              := cPicUnd
      :bFooter                   := {|| aTotVta[2] }
      :nDataStrAlign             := 1
      :nHeadStrAlign             := 1
      :nFootStrAlign             := 1
   end with

   with object ( oBrwVta:AddCol() )
      :cHeader                   := "Total " + cNombreUnidades()
      :nWidth                    := 120
      :bEditValue                := {|| NotCero( aVta[ oBrwVta:nArrayAt, 1] ) + NotCero( aVta[ oBrwVta:nArrayAt, 2] ) }
      :cEditPicture              := cPicUnd
      :bFooter                   := {|| aTotVta[2] }
      :nDataStrAlign             := 1
      :nHeadStrAlign             := 1
      :nFootStrAlign             := 1
      :lHide                     := .t.
   end with

   with object ( oBrwVta:AddCol() )
      :cHeader                   := "Importe"
      :nWidth                    := 140
      :bEditValue                := {|| aVta[ oBrwVta:nArrayAt, 3] }
      :cEditPicture              := cPirDiv
      :bFooter                   := {|| aTotVta[3] }
      :nDataStrAlign             := 1
      :nHeadStrAlign             := 1
      :nFootStrAlign             := 1
   end with

   if !oUser():lNotRentabilidad()

   with object ( oBrwVta:AddCol() )
      :cHeader                   := "Rentabilidad"
      :nWidth                    := 140
      :bEditValue                := {|| aVta[ oBrwVta:nArrayAt, 4] }
      :cEditPicture              := cPirDiv
      :bFooter                   := {|| aTotVta[4] }
      :nDataStrAlign             := 1
      :nHeadStrAlign             := 1
      :nFootStrAlign             := 1
   end with

   end if

   /*
   Estado de cuentas
   */

   REDEFINE SAY oTotPed PROMPT nTotPed                                                       ID 609 PICTURE cPorDiv   OF oFld:aDialogs[1] // Pedido
   REDEFINE SAY oPdtFac PROMPT nPdtFac                                                       ID 601 PICTURE cPorDiv   OF oFld:aDialogs[1] // Pendiente facturar
   REDEFINE SAY oTotFac PROMPT nTotFac                                                       ID 602 PICTURE cPorDiv   OF oFld:aDialogs[1] // Facturado
   REDEFINE SAY oFacRec PROMPT nFacRec                                                       ID 606 PICTURE cPorDiv   OF oFld:aDialogs[1] // Rectificado
   REDEFINE SAY oTotTik PROMPT nTotTik                                                       ID 611 PICTURE cPorDiv   OF oFld:aDialogs[1] // Tickets
   REDEFINE SAY oTotCob PROMPT nTotCob                                                       ID 603 PICTURE cPorDiv   OF oFld:aDialogs[1] // Cobros
   REDEFINE SAY oCobAnt PROMPT nCobAnt                                                       ID 604 PICTURE cPorDiv   OF oFld:aDialogs[1] // Anticipado
   REDEFINE SAY oTotEnt PROMPT nTotEnt                                                       ID 605 PICTURE cPorDiv   OF oFld:aDialogs[1] // Entregas
   REDEFINE SAY oTotPdt PROMPT ( nPdtFac + ( ( nTotFac + nTotTik + nFacRec ) - ( nTotCob + nCobAnt + nTotEnt ) ) );
                                                                                             ID 607 PICTURE cPorDiv   OF oFld:aDialogs[1]
   REDEFINE SAY oTotRie PROMPT ( ( nTotFac + nTotTik + nFacRec ) - ( nTotCob + nCobAnt + nTotEnt ) ) ;
                                                                                             ID 608 PICTURE cPorDiv   OF oFld:aDialogs[1]


   REDEFINE SAY oTotVal PROMPT nValTik                                                       ID 610 PICTURE cPorDiv   OF oFld:aDialogs[1]

   /*
   Documentos------------------------------------------------------------------
   */

   oTree          := TTreeView():Redefine( 310, oFld:aDialogs[2]  )
   oTree:bChanged := {|| TreeChanged( oTree, oBrwTmp ) }

   /*
   Barra de botones y datos----------------------------------------------------
   */

   REDEFINE BUTTON ;
      ID       301 ;
      OF       oFld:aDialogs[2] ;
      ACTION   ( EditDocument( oBrwTmp ) )

   REDEFINE BUTTON ;
      ID       302 ;
      OF       oFld:aDialogs[2] ;
      ACTION   ( ZoomDocument( oBrwTmp ) )

   REDEFINE BUTTON ;
      ID       303 ;
      OF       oFld:aDialogs[2] ;
      ACTION   ( DeleteDocument( oBrwTmp ) )

   REDEFINE BUTTON ;
      ID       304 ;
      OF       oFld:aDialogs[2] ;
      ACTION   ( VisualizaDocument( oBrwTmp ) )

   REDEFINE BUTTON ;
      ID       305 ;
      OF       oFld:aDialogs[2] ;
      ACTION   ( PrintDocument( oBrwTmp ) )

   REDEFINE BUTTON oBtnFiltro ;
      ID       306 ;
      OF       oFld:aDialogs[2] ;
      ACTION   ( Filtro( oBrwTmp ) )

   REDEFINE BUTTON ;
      ID       307 ;
      OF       oFld:aDialogs[2] ;
      ACTION   ( TInfLCli():New( "Informe detallado de documentos de clientes", , , , , , { oDbfTmp, cCmbAnio } ):Play() )

   /*
   Browse temporarl------------------------------------------------------------
   */

   REDEFINE BITMAP oBmpDocumentos ID 500 RESOURCE "Document_Text_Alpha_48" TRANSPARENT OF oFld:aDialogs[ 2 ]

   oBrwTmp                       := IXBrowse():New( oFld:aDialogs[ 2 ] )

   oBrwTmp:bClrSel               := {|| { CLR_BLACK, Rgb( 229, 229, 229 ) } }
   oBrwTmp:bClrSelFocus          := {|| { CLR_BLACK, Rgb( 167, 205, 240 ) } }

   oDbfTmp:SetBrowse( oBrwTmp )

   oBrwTmp:nMarqueeStyle         := 5
   oBrwTmp:lFooter               := .t.

   oBrwTmp:cName                 := "Documentos en informe de cliente"

   oBrwTmp:CreateFromResource( 300 )

   with object ( oBrwTmp:addCol() )
      :cHeader       := "Dc. Documento"
      :bStrData      := {|| cTextoDocumento() }
      :bBmpData      := {|| nImagenDocument() }
      :nWidth        := 20
      :AddResource( "Notebook_user1_16" )
      :AddResource( "Clipboard_empty_user1_16" )
      :AddResource( "Document_plain_user1_16" )
      :AddResource( "Document_user1_16" )
      :AddResource( "Document_delete_16" )
      :AddResource( "Document_money2_16" )
      :AddResource( "Cashier_user1_16" )
      :AddResource( "Briefcase_user1_16" )
      :AddResource( "Clipboard_empty_money_16" )
      :AddResource( "Document_plain_money_16" )
      :AddResource( "Cashier_user1_16" )
   end with

   with object ( oBrwTmp:addCol() )
      :cHeader       := "Estado"
      :bEditValue    := {|| oDbfTmp:cEstado }
      :nWidth        := 70
   end with

   with object ( oBrwTmp:addCol() )
      :cHeader       := "N�mero"
      :bEditValue    := {|| cMaskNumDoc( oDbfTmp ) }
      :nWidth        := 80
   end with

   with object ( oBrwTmp:addCol() )
      :cHeader       := "Fecha"
      :bEditValue    := {|| Dtoc( oDbfTmp:dFecDoc ) }
      :nWidth        := 70
   end with

   with object ( oBrwTmp:addCol() )
      :cHeader       := "C�digo"
      :bEditValue    := {|| oDbfTmp:cCodCli }
      :nWidth        := 50
   end with

   with object ( oBrwTmp:addCol() )
      :cHeader       := "Nombre"
      :bEditValue    := {|| oDbfTmp:cNomCli }
      :nWidth        := 310
   end with

   with object ( oBrwTmp:addCol() )
      :cHeader       := "Almac�n"
      :bEditValue    := {|| oDbfTmp:cAlmDoc }
      :nWidth        := 30
      :lHide         := .t.
   end with

   with object ( oBrwTmp:addCol() )
      :cHeader       := "Total"
      :bEditValue    := {|| oDbfTmp:nImpDoc }
      :bFooter       := {|| nTotImp( oDbfTmp ) }
      :cEditPicture  := cPorDiv
      :nWidth        := 80
      :nDataStrAlign := 1
      :nHeadStrAlign := 1
      :nFootStrAlign := 1
   end with

   oBrwTmp:bLDblClick   := {|| ZoomDocument( oBrwTmp ) }

   /*
   Graph start setting---------------------------------------------------------
   */

   REDEFINE BITMAP oBmpGraficos ID 500 RESOURCE "Chart_area_48_alpha" TRANSPARENT OF oFld:aDialogs[ 3 ]

   REDEFINE BTNBMP ;
      ID       101 ;
      OF       oFld:aDialogs[ 3 ] ;
      RESOURCE "ColumnChart16" ;
      NOBORDER ;
      TOOLTIP  "Gr�fico de barras" ;
      ACTION   ( oGraph:SetType( GRAPH_TYPE_BAR ) )

   REDEFINE BTNBMP ;
      ID       102 ;
      OF       oFld:aDialogs[ 3 ] ;
      RESOURCE "LineChart16" ;
      NOBORDER ;
      TOOLTIP  "Gr�fico de lineas" ;
      ACTION   ( oGraph:SetType( GRAPH_TYPE_LINE ) )

   REDEFINE BTNBMP ;
      ID       103 ;
      OF       oFld:aDialogs[ 3 ] ;
      RESOURCE "DotChart16" ;
      NOBORDER ;
      TOOLTIP  "Gr�fico de puntos" ;
      ACTION   ( oGraph:SetType( GRAPH_TYPE_POINT ) )

   REDEFINE BTNBMP ;
      ID       104 ;
      OF       oFld:aDialogs[ 3 ] ;
      RESOURCE "PieChart16" ;
      NOBORDER ;
      TOOLTIP  "Gr�fico combinado" ;
      ACTION   ( oGraph:SetType( GRAPH_TYPE_PIE ) )

   REDEFINE BTNBMP ;
      ID       105 ;
      OF       oFld:aDialogs[ 3 ] ;
      RESOURCE "Chart16" ;
      NOBORDER ;
      TOOLTIP  "Gr�fico combinado" ;
      ACTION   ( oGraph:SetType( GRAPH_TYPE_ALL ) )

   REDEFINE BTNBMP ;
      ID       106 ;
      OF       oFld:aDialogs[ 3 ] ;
      RESOURCE "Text3d16" ;
      NOBORDER ;
      TOOLTIP  "Gr�ficos en tres dimensiones" ;
      ACTION   ( oGraph:l3D :=!oGraph:l3D, oGraph:Refresh() )

   REDEFINE BTNBMP ;
      ID       107 ;
      OF       oFld:aDialogs[ 3 ] ;
      RESOURCE "Copy16" ;
      NOBORDER ;
      TOOLTIP  "Copiar el gr�fico en el portapapeles" ;
      ACTION   ( oGraph:Copy2ClipBoard() )

   REDEFINE BTNBMP ;
      ID       108 ;
      OF       oFld:aDialogs[ 3 ] ;
      RESOURCE "Imp16" ;
      NOBORDER ;
      TOOLTIP  "Imprimir el gr�fico" ;
      ACTION   ( GetPrtCoors( oGraph ) )

   REDEFINE BTNBMP ;
      ID       109 ;
      OF       oFld:aDialogs[ 3 ] ;
      RESOURCE "Preferences16" ;
      NOBORDER ;
      TOOLTIP  "Propiedades del gr�fico" ;
      ACTION   ( GraphPropierties( oGraph ) )

   oGraph                  := TGraph():ReDefine( 300, oFld:aDialogs[3] )

   /*
   Cuarta pesta�a para CZ------------------------------------------------------
   */

   REDEFINE BITMAP oBmpMaquina ID 500 RESOURCE "Chart_area_48_alpha" TRANSPARENT OF oFld:aDialogs[ 4 ]

   oBrwMaq                       := IXBrowse():New( oFld:aDialogs[ 4 ] )

   oBrwMaq:bClrSel               := {|| { CLR_BLACK, Rgb( 229, 229, 229 ) } }
   oBrwMaq:bClrSelFocus          := {|| { CLR_BLACK, Rgb( 167, 205, 240 ) } }

   oDbfTmpMaq:SetBrowse( oBrwMaq )

   oBrwMaq:nMarqueeStyle         := 6

   oBrwMaq:cName                 := "M�quinas en informe de clientes"

   oBrwMaq:CreateFromResource( 300 )

   with object ( oBrwMaq:addCol() )
      :cHeader          := "Art�culo"
      :bEditValue       := {|| AllTrim( oDbfTmpMaq:cRef ) + " - " + AllTrim( oDbfTmpMaq:cDetalle ) + " [" + AllTrim( oDbfTmpMaq:cNumSer )  + "]" }
      :nWidth           := 260
   end with

   with object ( oBrwMaq:addCol() )
      :cHeader          := "Fecha"
      :bEditValue       := {|| oDbfTmpMaq:dFecSat }
      :nDataStrAlign    := AL_LEFT
      :nHeadStrAlign    := AL_LEFT
      :nWidth           := 80
   end with
      
   with object ( oBrwMaq:addCol() )
      :cHeader          := "Operario"
      :bEditValue       := {|| AllTrim( oDbfTmpMaq:cCodOpe ) + if( !Empty( oDbfTmpMaq:cCodOpe ), " - ", "" ) + oRetFld( oDbfTmpMaq:cCodOpe, oOperario:oDbf, "cNomTra", "cCodTra" ) }
      :nWidth           := 200
   end with

   with object ( oBrwMaq:addCol() )
      :cHeader          := "Categor�a"
      :bEditValue       := {|| AllTrim( oDbfTmpMaq:cCodCat ) }
      :bStrData         := {|| AllTrim( oDbfTmpMaq:cCodCat ) + if( !Empty( oDbfTmpMaq:cCodCat ), " - ", "" ) + RetFld( oDbfTmpMaq:cCodCat, dbfCategoria, "cNombre" ) }
      :bBmpData         := {|| nBitmapTipoCategoria( RetFld( oDbfTmpMaq:cCodCat, dbfCategoria, "cTipo" ) ) }
      :nWidth           := 200
      AddResourceTipoCategoria( hb_QWith() )
   end with

   with object ( oBrwMaq:addCol() )
      :cHeader          := "Situaci�n"
      :bEditValue       := {|| oDbfTmpMaq:cSituac }
      :nWidth           := 130
   end with

   oBrwMaq:bLDblClick   := {|| HistoriaMaquina( cCmbAnio ) }

   /*Anno del ejecicio, por defecto lleva el anno actual*/

   REDEFINE COMBOBOX oCmbAnio VAR cCmbAnio ;
      ITEMS    { "Todos", "2000", "2001", "2002", "2003", "2004", "2005", "2006", "2007", "2008", "2009", "2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018", "2019", "2020" } ;
      ID       310 ;
      COLOR    CLR_GET ;
      ON CHANGE( LoadDatos( cCodCli, oDlg, cCmbAnio, oBrwVta ), LoadMaquinas( cCodCli, cCmbAnio, oBrwMaq ), oBrwTmp:Refresh(), oGraph:Refresh() ) ;
      OF       oDlg

   /*
   Botones comunes a la caja de dialogo----------------------------------------
   */

   REDEFINE SAY oText VAR cText ;
      ID       400 ;
      OF       oDlg

   oMeter      := TApoloMeter():ReDefine( 200, { | u | if( pCount() == 0, nMeter, nMeter := u ) }, 10, oDlg, .f., , , .t., Rgb( 255,255,255 ), , Rgb( 128,255,0 ) )

   REDEFINE BUTTON ;
      ID       306 ;
      OF       oDlg ;
      ACTION   ( LoadDatos( cCodCli, oDlg, cCmbAnio, oBrwVta ), LoadMaquinas( cCodCli, cCmbAnio, oBrwMaq ), oBrwTmp:Refresh(), oGraph:Refresh() )

   REDEFINE BUTTON ;
      ID       501 ;
      OF       oDlg ;
      ACTION   ( oDlg:end( IDOK ) )

   /*
   Teclas r�pidas para los botones---------------------------------------------
   */

   oFld:aDialogs[2]:AddFastKey( VK_F3, {|| EditDocument( oBrwTmp ) } )
   oFld:aDialogs[2]:AddFastKey( VK_F4, {|| DeleteDocument( oBrwTmp ) } )

   oDlg:bStart := {|| LoadDatos( cCodCli, oDlg, cCmbAnio, oBrwVta ), LoadMaquinas( cCodCli, cCmbAnio, oBrwMaq ), oBrwTmp:Refresh(), oGraph:Refresh(), oBrwMaq:Load() }

   ACTIVATE DIALOG oDlg CENTER ;
         ON INIT  ( InitBrwVtaCli( cCodCli, oBrwTmp, oTree, oDlg ), SysRefresh() ) ;
         VALID    ( CloseFiles() )

   if !Empty( oBmpGeneral )
      oBmpGeneral:End()
   end if

   if !Empty( oBmpDocumentos )
      oBmpDocumentos:End()
   end if

   if !Empty( oBmpGraficos )
      oBmpGraficos:End()
   end if

   oMenu:End()

   oBrwMaq:CloseData()

return nil

//---------------------------------------------------------------------------//

Static Function InitBrwVtaCli( cCodCli, oBrwTmp, oTree, oDlg )

   oBrwTmp:Load()

   oTreeImageList := TImageList():New( 16, 16 )

   oTreeImageList:AddMasked( TBitmap():Define( "User1_16" ),                  Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Notebook_user1_16" ),         Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Clipboard_empty_user1_16" ),  Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Document_plain_user1_16" ),   Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Document_user1_16" ),         Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Document_delete_16" ),        Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Briefcase_user1_16" ),        Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Document_money2_16" ),        Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Cashier_user1_16" ),          Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Folder_document_16" ),        Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Money_envelope_16" ),         Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Clipboard_empty_money_16" ),  Rgb( 255, 0, 255 ) )
   oTreeImageList:AddMasked( TBitmap():Define( "Document_plain_money_16" ),   Rgb( 255, 0, 255 ) )

   oTree:SetImageList( oTreeImageList )

   oTreeDocument     := oTree:Add( "Todos los documentos", 0 )

   oTreeDocumentos   := oTreeDocument:Add( "Documentos", 9 )
   oTreeDocumentos:Add( cTextoDocumento( PRE_CLI ), 1 )
   oTreeDocumentos:Add( cTextoDocumento( PED_CLI ), 2 )
   oTreeDocumentos:Add( cTextoDocumento( ALB_CLI ), 3 )
   oTreeDocumentos:Add( cTextoDocumento( FAC_CLI ), 4 )
   oTreeDocumentos:Add( cTextoDocumento( FAC_REC ), 5 )
   oTreeDocumentos:Add( cTextoDocumento( ANT_CLI ), 7 )
   oTreeDocumentos:Add( cTextoDocumento( TIK_CLI ), 8 )
   oTreeDocumentos:Add( cTextoDocumento( DEV_CLI ), 8 )
   oTreeDocumentos:Add( cTextoDocumento( VAL_CLI ), 8 )
   oTreeDocumentos:Add( cTextoDocumento( APT_CLI ), 8 )

   oTreeCobros       := oTreeDocument:Add( "Cobros", 10 )
   oTreeCobros:Add( cTextoDocumento( REC_CLI ), 6 )
   oTreeCobros:Add( cTextoDocumento( COB_TIK ), 8 )
   oTreeCobros:Add( cTextoDocumento( ANT_CLI ), 7 )
   oTreeCobros:Add( cTextoDocumento( ENT_PED ), 11 )
   oTreeCobros:Add( cTextoDocumento( ENT_ALB ), 12 )

   oTreeDocument:Expand()
   oTreeDocumentos:Expand()
   oTreeCobros:Expand()

   MENU oMenu

      MENUITEM    "&1. Rotor"

         MENU

         MENUITEM "&1. A�adir presupuesto de cliente";
            MESSAGE  "A�ade un presupuesto de cliente" ;
            RESOURCE "Notebook_user1_16";
            ACTION   ( AppPreCli( cCodCli ) )

         MENUITEM "&2. A�adir pedido de cliente";
            MESSAGE  "A�ade un pedido de cliente" ;
            RESOURCE "Clipboard_empty_user1_16";
            ACTION   ( AppPedCli( cCodCli ) )

         MENUITEM "&3. A�adir albar�n de cliente";
            MESSAGE  "A�ade un albar�n de cliente" ;
            RESOURCE "Document_plain_user1_16";
            ACTION   ( AppAlbCli( { "Cliente" => cCodCli } ) )

         MENUITEM "&4. A�adir factura de cliente";
            MESSAGE  "A�ade una factura de cliente" ;
            RESOURCE "Document_user1_16";
            ACTION   ( AppFacCli( cCodCli ) )

         MENUITEM "&5. A�adir tiket de cliente";
            MESSAGE  "A�ade un tiket de cliente" ;
            RESOURCE "Cashier_user1_16";
            ACTION   ( AppTikCli( cCodCli ) )

         ENDMENU

   ENDMENU

   oDlg:SetMenu( oMenu )

Return nil

//---------------------------------------------------------------------------//

Static Function LoadDatos( cCodCli, oDlg, Anio, oBrwVta )

   local n

   oDlg:Disable()

   CursorWait()

   /*
   Calculos a mostrar----------------------------------------------------------
   */

   oMeter:Show()
   oMeter:SetTotal( 15 )

   SysRefresh()

   oText:SetText( "Calculando ventas mensuales" )

   aFill( aTotVta, 0 )

   aTotVentasCliente( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ), .t. )

   for n := 1 to 12

      aTotVta[1]  += aVta[n,1]
      aTotVta[2]  += aVta[n,2]
      aTotVta[3]  += aVta[n,3]
      aTotVta[4]  += aVta[n,4]

   next

   oMeter:AutoInc()

   oText:SetText( "Calculando cobros de tickets" )
   nCobTik  := nCobrosTik( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oText:SetText( "Calculando vales pendientes de liquidar" )
   nValTik  := nValesTik( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oText:SetText( "Calculando cobros de facturas" )
   nCobFac  := nCobrosFac( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oText:SetText( "Calculando facturas de clientes" )
   nTotFac  := nTotalFacturas( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oText:SetText( "Calculando facturas rectificadas" )
   nFacRec  := nTotalRectificativa( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oText:SetText( "Calculando tickets de clientes" )
   nTotTik  := nTotalTickets( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oText:SetText( "Calculando anticipos de facturas" )
   nCobAnt  := nTotalAnticipo( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oText:SetText( "Calculando entregas a cuenta" )
   nTotEnt  := nTotalEntregas( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oText:SetText( "Calculando ventas de albaranes" )
   nPdtFac  := nTotalAlbaran( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oPdtFac:SetText( nPdtFac )

   oTotFac:SetText( nTotFac )
   oTotTik:SetText( nTotTik )

   // nTotCob  := nCobTik + nCobFac
   
   oTotCob:SetText( nCobTik + nCobFac )
   oCobAnt:SetText( nCobAnt )

   oTotVal:SetText( nValTik )
   oTotEnt:SetText( nTotEnt )
   oFacRec:SetText( nFacRec )

   oTotPdt:SetText( ( nPdtFac + nTotFac + nTotTik + nFacRec ) - ( nCobTik + nCobFac + nCobAnt + nTotEnt ) )
   oTotRie:SetText( ( nTotFac + nTotTik + nFacRec ) - ( nCobTik + nCobFac + nCobAnt + nTotEnt ) )

   oBrwVta:Refresh()
   oBrwVta:RefreshFooters()

   oDbfTmp:Zap()

   /*
   Cargamos los datos----------------------------------------------------------
   */

   oText:SetText( "Cargando los documentos" )

   LoadPresupuestoCliente( cCodCli, dbfDiv, dbfIva, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadPedidosCliente( cCodCli, dbfDiv, dbfIva, dbfFPago, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadAlbaranesCliente( cCodCli, dbfDiv, dbfIva, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadFacturasCliente( cCodCli, dbfDiv, dbfIva, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadFacturasRectificativas( cCodCli, dbfDiv, dbfIva, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadRecibosCliente( cCodCli, dbfDiv, dbfIva, dbfClient, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadTiketsCliente( cCodCli, dbfDiv, dbfIva, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadCobrosTiketsCliente( cCodCli, dbfDiv, dbfIva, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadAnticiposCliente( cCodCli, dbfDiv, dbfIva, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadEntregasPedidos( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   LoadEntregasAlbaranes( cCodCli, if( Anio == "Todos", nil, Val( Anio ) ) )
   oMeter:AutoInc()

   oDbfTmp:GoTop()

   /*
   Generamos el grafico--------------------------------------------------------
   */

   oGraph:aSeries    := {}
   oGraph:aData      := {}
   oGraph:aSTemp     := {}
   oGraph:aDTemp     := {}

   oGraph:AddSerie( { aVta[ 1, 3 ], aVta[ 2, 3 ], aVta[ 3, 3 ], aVta[ 4, 3 ], aVta[ 5, 3 ], aVta[ 6, 3 ], aVta[ 7, 3 ], aVta[ 8, 3 ], aVta[ 9, 3 ], aVta[ 10, 3 ], aVta[ 11, 3 ], aVta[ 12, 3 ] }, "Ventas", Rgb( 253, 186,  40 ) )
   oGraph:SetYVals( { "Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic" } )

   oGraph:cTitle     := "Evoluci�n anual de ventas"
   oGraph:lcTitle    := .f.
   oGraph:nClrT      := Rgb( 55, 55, 55)
   oGraph:nClrX      := CLR_BLUE
   oGraph:nClrY      := CLR_RED
   oGraph:cPicture   := cPorDiv

   oMeter:AutoInc()

   oText:SetText()

   oMeter:Hide()

   CursorWE()

   oDlg:Enable()

return nil

//---------------------------------------------------------------------------//

Static Function LoadMaquinas( cCodCli, cCmbAnio, oBrwMaq )

   local nOrdAntS  := ( dbfSatCliS )->( OrdSetFocus( "nNumRef" ) )
   local nOrdAntT  := ( dbfSatCliT )->( OrdSetFocus( "nNumSat" ) )

   oDbfTmpMaq:Zap()

   ( dbfSatCliL )->( dbGoTop() )

   while !( dbfSatCliL )->( Eof() )

      if !Empty( ( dbfSatCliL )->cRef )      .and.;
         ( dbfSatCliL )->nCtlStk == 2        .and.;
         ( dbfSatCliL )->cCodCli == cCodCli  .and.;
         if( cCmbAnio == "Todos", .t., ( Year( ( dbfSatCliL )->dFecSat ) == Val( cCmbAnio ) ) )

         if ( dbfSatCliS )->( dbSeek( ( dbfSatCliL )->cSerSat + Str( ( dbfSatCliL )->nNumSat ) + ( dbfSatCliL )->cSufSat + ( dbfSatCliL )->cRef + Str( ( dbfSatCliL )->nNumLin ) ) )

            if !oDbfTmpMaq:Seek( ( dbfSatCliL )->cRef + ( dbfSatCliS )->cNumSer )

               oDbfTmpMaq:Append()

               oDbfTmpMaq:cCodCli      := cCodCli
               oDbfTmpMaq:cRef         := ( dbfSatCliL )->cRef
               oDbfTmpMaq:cDetalle     := ( dbfSatCliL )->cDetalle
               oDbfTmpMaq:cNumSer      := ( dbfSatCliS )->cNumSer

               if ( dbfSatCliT )->( dbSeek( ( dbfSatCliL )->cSerSat + Str( ( dbfSatCliL )->nNumSat ) + ( dbfSatCliL )->cSufSat ) )

                  oDbfTmpMaq:dFecSat   := ( dbfSatCliT )->dFecSat
                  oDbfTmpMaq:cSituac   := ( dbfSatCliT )->cSituac
                  oDbfTmpMaq:cCodOpe   := ( dbfSatCliT )->cCodOpe
                  oDbfTmpMaq:cCodCat   := ( dbfSatCliT )->cCodCat

               end if   

               oDbfTmpMaq:Save()

            else
            
               if ( dbfSatCliL )->dFecSat > oDbfTmpMaq:dFecSat .and.;
                  ( dbfSatCliT )->( dbSeek( ( dbfSatCliL )->cSerSat + Str( ( dbfSatCliL )->nNumSat ) + ( dbfSatCliL )->cSufSat ) )
                  
                  oDbfTmpMaq:Load()

                  oDbfTmpMaq:dFecSat   := ( dbfSatCliT )->dFecSat
                  oDbfTmpMaq:cSituac   := ( dbfSatCliT )->cSituac
                  oDbfTmpMaq:cCodOpe   := ( dbfSatCliT )->cCodOpe
                  oDbfTmpMaq:cCodCat   := ( dbfSatCliT )->cCodCat

                  oDbfTmpMaq:Save()

               end if

            end if   

         end if   
         
      end if

      ( dbfSatCliL )->( dbSkip() )

   end while

   oDbfTmpMaq:GoTop()

   ( dbfSatCliS )->( OrdSetFocus( nOrdAntS ) )
   ( dbfSatCliT )->( OrdSetFocus( nOrdAntT ) )

   if !Empty( oBrwMaq )
      oBrwMaq:Refresh()
   end if  

Return nil

//---------------------------------------------------------------------------//

Static function LoadLineasMaquinas( cCmbAnio, oBrwMaqL )

   local nOrdAntS  := ( dbfSatCliS )->( OrdSetFocus( "cRef" ) )
   local nOrdAntT  := ( dbfSatCliT )->( OrdSetFocus( "nNumSat" ) )

   oDbfTmpMaqL:Zap()

   ( dbfSatCliS )->( dbGoTop() )

   if ( dbfSatCliS )->( dbSeek( oDbfTmpMaq:cRef + oDbfTmpMaq:cNumSer ) )

      while ( dbfSatCliS )->cRef + ( dbfSatCliS )->cNumSer == oDbfTmpMaq:cRef + oDbfTmpMaq:cNumSer .and. !( dbfSatCliS )->( Eof() )

         if ( dbfSatCliT )->( dbSeek( ( dbfSatCliS )->cSerSat + Str( ( dbfSatCliS )->nNumSat ) + ( dbfSatCliS )->cSufSat ) )

            oDbfTmpMaqL:Append()

            oDbfTmpMaqL:cSerSat      := ( dbfSatCliT )->cSerSat
            oDbfTmpMaqL:nNumSat      := ( dbfSatCliT )->nNumSat
            oDbfTmpMaqL:cSufSat      := ( dbfSatCliT )->cSufSat
            oDbfTmpMaqL:dFecSat      := ( dbfSatCliT )->dFecSat
            oDbfTmpMaqL:cCodCli      := oDbfTmpMaq:cCodCli
            oDbfTmpMaqL:cRef         := oDbfTmpMaq:cRef
            oDbfTmpMaqL:cDetalle     := oDbfTmpMaq:cDetalle
            oDbfTmpMaqL:cNumSer      := oDbfTmpMaq:cNumSer
            oDbfTmpMaqL:cSituac      := ( dbfSatCliT )->cSituac
            oDbfTmpMaqL:cCodOpe      := ( dbfSatCliT )->cCodOpe
            oDbfTmpMaqL:cCodCat      := ( dbfSatCliT )->cCodCat

            oDbfTmpMaqL:Save()

         end if   

         oDbfTmpMaqL:Save()

         ( dbfSatCliS )->( dbSkip() )

      end while

   end if
   
   ( dbfSatCliS )->( OrdSetFocus( nOrdAntS ) )
   ( dbfSatCliT )->( OrdSetFocus( nOrdAntT ) )

   if !Empty( oBrwMaqL )
      oBrwMaqL:Refresh()
   end if

Return nil

//---------------------------------------------------------------------------//

Static Function HistoriaMaquina( cCmbAnio )
   
   local oDlg
   local oBmp
   local oBrwMaqL
   local oCliente
   local oMaquina
   local oSerie

   DEFINE DIALOG oDlg RESOURCE "LHISMAQ" TITLE "Hist�rico de S.A.T de clientes"

      REDEFINE BITMAP oBmp ID 500 RESOURCE "Businessman2_Alpha_48" TRANSPARENT OF oDlg

      REDEFINE SAY oCliente PROMPT "Cliente: " + AllTrim( oDbfTmpMaq:cCodCli ) ;
         ID       110 ;
         OF       oDlg

      REDEFINE SAY oMaquina PROMPT "Art�culo: " + AllTrim( oDbfTmpMaq:cRef ) + " - " + AllTrim( oDbfTmpMaq:cDetalle ) ;
         ID       120 ;
         OF       oDlg 

      REDEFINE SAY oSerie PROMPT "N�mero de serie: " + AllTrim( oDbfTmpMaq:cNumSer ) ;
         ID       130 ;
         OF       oDlg     

      oBrwMaqL                       := IXBrowse():New( oDlg )

      oBrwMaqL:bClrSel               := {|| { CLR_BLACK, Rgb( 229, 229, 229 ) } }
      oBrwMaqL:bClrSelFocus          := {|| { CLR_BLACK, Rgb( 167, 205, 240 ) } }

      oDbfTmpMaqL:SetBrowse( oBrwMaqL )

      oBrwMaqL:nMarqueeStyle         := 6

      oBrwMaqL:cName                 := "Hist�rico maquina"

      oBrwMaqL:CreateFromResource( 100 )

      with object ( oBrwMaqL:addCol() )
         :cHeader          := "N�mero"
         :bEditValue       := {|| oDbfTmpMaqL:cSerSat + "/" + AllTrim( Str( oDbfTmpMaqL:nNumSat ) ) + "/" + oDbfTmpMaqL:cSufSat }
         :nWidth           := 70
      end with

      with object ( oBrwMaqL:addCol() )
         :cHeader          := "Fecha"
         :bEditValue       := {|| oDbfTmpMaqL:dFecSat }
         :nDataStrAlign    := AL_LEFT
         :nHeadStrAlign    := AL_LEFT
         :nWidth           := 80
      end with
      
      with object ( oBrwMaqL:addCol() )
         :cHeader          := "Operario"
         :bEditValue       := {|| AllTrim( oDbfTmpMaqL:cCodOpe ) + if( !Empty( oDbfTmpMaqL:cCodOpe ), " - ", "" ) + oRetFld( oDbfTmpMaqL:cCodOpe, oOperario:oDbf, "cNomTra", "cCodTra" ) } 
         :nWidth           := 200
      end with

      with object ( oBrwMaqL:addCol() )
         :cHeader          := "Categor�a"
         :bEditValue       := {|| AllTrim( oDbfTmpMaqL:cCodCat ) }
         :bStrData         := {|| AllTrim( oDbfTmpMaqL:cCodCat ) + if( !Empty( oDbfTmpMaqL:cCodCat ), " - ", "" ) + RetFld( oDbfTmpMaqL:cCodCat, dbfCategoria, "cNombre" ) }
         :bBmpData         := {|| nBitmapTipoCategoria( RetFld( oDbfTmpMaqL:cCodCat, dbfCategoria, "cTipo" ) ) }
         :nWidth           := 200
         AddResourceTipoCategoria( hb_QWith() )
      end with

      with object ( oBrwMaqL:addCol() )
         :cHeader          := "Situaci�n"
         :bEditValue       := {|| AllTrim( oDbfTmpMaqL:cSituac ) }
         :nWidth           := 130
      end with

      REDEFINE BUTTON ;
         ID       IDOK ;
         OF       oDlg ;
         ACTION   oDlg:End()

      oDlg:bStart := {|| LoadLineasMaquinas( cCmbAnio, oBrwMaqL ), oBrwMaqL:Load() }

   ACTIVATE DIALOG oDlg CENTER

   oBrwMaqL:CloseData()

   if !Empty( oBmp )
      oBmp:End()
   end if

Return nil

//---------------------------------------------------------------------------//

Function aTotVentasCliente( cCodCli, nYear, lUnits )

   local lClo     := .f.
   local cCodEmp
   local dbfAlbEmpT
   local dbfAlbEmpL
   local dbfFacEmpT
   local dbfFacEmpL
   local dbfAntEmpT
   local dbfRecEmpT
   local dbfRecEmpL
   local dbfTikEmpT
   local dbfTikEmpL

   DEFAULT lUnits := .t.

   if !lOpenFiles
      if OpenFiles( .f. )
         lClo     := .t.
      else
         return ( aVta )
      end if
   end if

   aEval( aVta, {|a| Afill( a, 0 ) } )

   TotalAlbaranesClientes( cCodCli, dbfAlbCliT, dbfAlbCliL, dbfDiv, dbfIva, nYear, lUnits  )

   TotalFacturasClientes( cCodCli, dbfFacCliT, dbfFacCliL, dbfAntCliT, dbfDiv, dbfIva, nYear, lUnits )

   TotalFacturasRectificativas( cCodCli, dbfFacRecT, dbfFacRecL, dbfAntCliT, dbfDiv, dbfIva, nYear, lUnits )

   TotalTicketsClientes( cCodCli, dbfTikCliT, dbfTikCliL, dbfDiv, nYear, lUnits )

   if lClo
      CloseFiles()
   end if

Return ( aVta )

//---------------------------------------------------------------------------//

Static Function TreeChanged( oTree, oBrwTmp )

   local cText    := oTree:GetSelText()

   do case

      case cText == cTextoDocumento( PRE_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( PRE_CLI )

      case cText == cTextoDocumento( PED_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( PED_CLI )

      case cText == cTextoDocumento( ALB_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( ALB_CLI )

      case cText == cTextoDocumento( FAC_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( FAC_CLI )

      case cText == cTextoDocumento( FAC_REC )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( FAC_REC )

      case cText == cTextoDocumento( REC_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( REC_CLI )

      case cText == cTextoDocumento( ANT_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( ANT_CLI )

      case cText == cTextoDocumento( TIK_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( TIK_CLI )

      case cText == cTextoDocumento( DEV_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( DEV_CLI )

      case cText == cTextoDocumento( VAL_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( VAL_CLI )

      case cText == cTextoDocumento( APT_CLI )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( APT_CLI )

      case cText == cTextoDocumento( ENT_PED )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( ENT_PED )

      case cText == cTextoDocumento( ENT_ALB )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( ENT_ALB )

      case cText == cTextoDocumento( COB_TIK )
         oDbfTmp:OrdSetFocus( "cTypDoc" )
         oDbfTmp:OrdScope( COB_TIK )

      case cText == "Documentos"
         oDbfTmp:OrdSetFocus( "cDocume" )
         oDbfTmp:GoTop()

      case cText == "Cobros"
         oDbfTmp:OrdSetFocus( "cCobros" )
         oDbfTmp:GoTop()

      otherwise
         oDbfTmp:OrdSetFocus( "cAllDoc" )
         oDbfTmp:OrdClearScope()

   end case

   oDbfTmp:GoTop()

   oBrwTmp:Refresh()

Return nil

//---------------------------------------------------------------------------//

Static Function nImagenDocument()

   do case

      case oDbfTmp:nTypDoc == PRE_CLI
         Return ( 1 )

      case oDbfTmp:nTypDoc == PED_CLI
         Return ( 2 )

      case oDbfTmp:nTypDoc == ALB_CLI
         Return ( 3 )

      case oDbfTmp:nTypDoc == FAC_CLI
         Return ( 4 )

      case oDbfTmp:nTypDoc == FAC_REC
         Return ( 5 )

      case oDbfTmp:nTypDoc == ANT_CLI
         Return ( 6 )

      case oDbfTmp:nTypDoc == TIK_CLI
         Return ( 7 )

      case oDbfTmp:nTypDoc == DEV_CLI
         Return ( 7 )

      case oDbfTmp:nTypDoc == APT_CLI
         Return ( 7 )

      case oDbfTmp:nTypDoc == VAL_CLI
         Return ( 7 )

      case oDbfTmp:nTypDoc == REC_CLI
         Return ( 8 )

      case oDbfTmp:nTypDoc == ENT_PED
         Return ( 9 )

      case oDbfTmp:nTypDoc == ENT_ALB
         Return ( 10 )

      case oDbfTmp:nTypDoc == COB_TIK
         Return ( 11 )

   end case

Return ( 1 )

//---------------------------------------------------------------------------//

Static Function EditDocument( oBrwTmp )

   do case
      case oDbfTmp:nTypDoc == PRE_CLI
         EdtPreCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == PED_CLI
         EdtPedCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ALB_CLI
         EdtAlbCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == FAC_CLI
         EdtFacCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == REC_CLI
         EdtRecCli( Left( oDbfTmp:cNumDoc, 12 ) + Str( oDbfTmp:nNumRec ) )

      case oDbfTmp:nTypDoc == ANT_CLI
         EdtAntCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == TIK_CLI .or.;
           oDbfTmp:nTypDoc == DEV_CLI .or.;
           oDbfTmp:nTypDoc == APT_CLI .or.;
           oDbfTmp:nTypDoc == VAL_CLI
         EdtTikCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ENT_PED
         EdtPedCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ENT_ALB
         EdtAlbCli( oDbfTmp:cNumDoc )

   end case

Return nil

//---------------------------------------------------------------------------//

Static Function ZoomDocument( oBrwTmp )

   do case
      case oDbfTmp:nTypDoc == PRE_CLI
         ZooPreCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == PED_CLI
         ZooPedCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ALB_CLI
         ZooAlbCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == FAC_CLI
         ZooFacCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == REC_CLI
         ZooRecCli( Left( oDbfTmp:cNumDoc, 12 ) + Str( oDbfTmp:nNumRec ) )

      case oDbfTmp:nTypDoc == ANT_CLI
         ZooAntCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == TIK_CLI .or.;
           oDbfTmp:nTypDoc == DEV_CLI .or.;
           oDbfTmp:nTypDoc == APT_CLI .or.;
           oDbfTmp:nTypDoc == VAL_CLI
         ZooTikCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ENT_PED
         ZooPedCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ENT_ALB
         ZooAlbCli( oDbfTmp:cNumDoc )

   end case

Return nil

//---------------------------------------------------------------------------//

Static Function DeleteDocument( oBrwTmp )

   do case
      case oDbfTmp:nTypDoc == PRE_CLI
         DelPreCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == PED_CLI
         DelPedCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ALB_CLI
         DelAlbCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == FAC_CLI
         DelFacCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == REC_CLI
         DelRecCli( Left( oDbfTmp:cNumDoc, 12 ) + Str( oDbfTmp:nNumRec ) )

      case oDbfTmp:nTypDoc == ANT_CLI
         DelAntCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == TIK_CLI .or.;
           oDbfTmp:nTypDoc == DEV_CLI .or.;
           oDbfTmp:nTypDoc == APT_CLI .or.;
           oDbfTmp:nTypDoc == VAL_CLI
         DelTikCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ENT_PED
         EdtPedCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ENT_ALB
         EdtAlbCli( oDbfTmp:cNumDoc )

   end case

Return nil

//---------------------------------------------------------------------------//

Static Function VisualizaDocument( oBrwTmp )

   do case
      case oDbfTmp:nTypDoc == PRE_CLI
         VisPreCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == PED_CLI
         VisPedCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ALB_CLI
         VisAlbCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == FAC_CLI
         VisFacCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == REC_CLI
         VisRecCli( Left( oDbfTmp:cNumDoc, 12 ) + Str( oDbfTmp:nNumRec ) )

      case oDbfTmp:nTypDoc == ANT_CLI
         VisAntCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == TIK_CLI .or.;
           oDbfTmp:nTypDoc == DEV_CLI .or.;
           oDbfTmp:nTypDoc == APT_CLI .or.;
           oDbfTmp:nTypDoc == VAL_CLI
         VisTikCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ENT_PED
         PrnEntPed( Left( oDbfTmp:cNumDoc, 12 ) + Str( oDbfTmp:nNumRec ), .f., dbfPedCliP )

      case oDbfTmp:nTypDoc == ENT_ALB
         PrnEntAlb( Left( oDbfTmp:cNumDoc, 12 ) + Str( oDbfTmp:nNumRec ), .f. )

   end case

Return nil

//---------------------------------------------------------------------------//

Static Function PrintDocument( oBrwTmp )

   do case
      case oDbfTmp:nTypDoc == PRE_CLI
         PrnPreCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == PED_CLI
         PrnPedCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ALB_CLI
         PrnAlbCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == FAC_CLI
         PrnFacCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ANT_CLI
         PrnAntCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == REC_CLI
         PrnRecCli( Left( oDbfTmp:cNumDoc, 12 ) + Str( oDbfTmp:nNumRec ) )

      case oDbfTmp:nTypDoc == TIK_CLI .or.;
           oDbfTmp:nTypDoc == DEV_CLI .or.;
           oDbfTmp:nTypDoc == APT_CLI .or.;
           oDbfTmp:nTypDoc == VAL_CLI
         PrnTikCli( oDbfTmp:cNumDoc )

      case oDbfTmp:nTypDoc == ENT_PED
         PrnEntPed( Left( oDbfTmp:cNumDoc, 12 ) + Str( oDbfTmp:nNumRec ), .t., dbfPedCliP )

      case oDbfTmp:nTypDoc == ENT_ALB
         PrnEntAlb( Left( oDbfTmp:cNumDoc, 12 ) + Str( oDbfTmp:nNumRec ), .t. )

   end case

Return nil

//---------------------------------------------------------------------------//

Static Function DefineTemporal( cPath, lUniqueName, cFileName )

   local oDbf

   DEFAULT cPath        := cPatTmp()
   DEFAULT lUniqueName  := .t.
   DEFAULT cFileName    := "InfCli"

   if lUniqueName
      cFileName         := cGetNewFileName( cFileName, , , cPatTmp() )
   end if

   DEFINE TABLE oDbf FILE ( cFileName ) CLASS "InfCli" ALIAS ( cFileName ) PATH ( cPath ) VIA ( cLocalDriver() )

      FIELD NAME "nTypDoc" TYPE "C" LEN  2 DEC 0 COMMENT "Tipo de documento"     OF oDbf
      FIELD NAME "cEstado" TYPE "C" LEN 20 DEC 0 COMMENT "Estado del documento"  OF oDbf
      FIELD NAME "dFecDoc" TYPE "D" LEN  8 DEC 0 COMMENT "Fecha del documento"   OF oDbf
      FIELD NAME "cNumDoc" TYPE "C" LEN 13 DEC 0 COMMENT "Codigo del documento"  OF oDbf
      FIELD NAME "nNumRec" TYPE "N" LEN  2 DEC 0 COMMENT "N�mero del recibo"     OF oDbf
      FIELD NAME "cCodCli" TYPE "C" LEN 12 DEC 0 COMMENT "C�digo del cliente"    OF oDbf
      FIELD NAME "cNomCli" TYPE "C" LEN 50 DEC 0 COMMENT "Nombre del cliente"    OF oDbf
      FIELD NAME "cAlmDoc" TYPE "C" LEN  3 DEC 0 COMMENT "Almac�n"               OF oDbf
      FIELD NAME "nImpDoc" TYPE "N" LEN 16 DEC 6 COMMENT "Importe del documento" OF oDbf
      FIELD NAME "cDivisa" TYPE "C" LEN  3 DEC 0 COMMENT "Divisa del documento"  OF oDbf

      INDEX TO ( cFileName ) TAG "cAllDoc" ON "Dtos( dFecDoc )"                                                                                                           OF oDbf
      INDEX TO ( cFileName ) TAG "cTypDoc" ON "nTypDoc + Dtos( dFecDoc )"                                                                                                 OF oDbf
      INDEX TO ( cFileName ) TAG "cDocume" ON "Dtos( dFecDoc )" FOR "( nTypDoc >= '05' .and. nTypDoc <= '09' ) .or. ( nTypDoc >= '12' .and. nTypDoc <= '14' )"            OF oDbf
      INDEX TO ( cFileName ) TAG "cCobros" ON "Dtos( dFecDoc )" FOR "nTypDoc == '10' .or. nTypDoc == '15' .or. nTypDoc == '21' .or. nTypDoc == '22' .or. nTypDoc == '30'" OF oDbf

   END DATABASE oDbf

Return ( oDbf )

//---------------------------------------------------------------------------//

Static Function DefineTemporalMaquinas( cPath, lUniqueName, cFileName )

   local oDbf

   DEFAULT cPath        := cPatTmp()
   DEFAULT lUniqueName  := .t.
   DEFAULT cFileName    := "InfMaq"

   if lUniqueName
      cFileName         := cGetNewFileName( cFileName, , , cPatTmp() )
   end if

   DEFINE TABLE oDbf FILE ( cFileName ) CLASS "InfMaq" ALIAS ( cFileName ) PATH ( cPath ) VIA ( cLocalDriver() )

      FIELD NAME "CCODCLI"  TYPE "C" LEN  12 DEC 0 COMMENT "C�digo del cliente"        OF oDbf
      FIELD NAME "CREF"     TYPE "C" LEN  18 DEC 0 COMMENT "Referencia del art�culo"   OF oDbf
      FIELD NAME "CDETALLE" TYPE "C" LEN 250 DEC 0 COMMENT "Descripci�n de art�culo"   OF oDbf
      FIELD NAME "CNUMSER"  TYPE "C" LEN  30 DEC 0 COMMENT "N�mero de serie"           OF oDbf
      FIELD NAME "DFECSAT"  TYPE "D" LEN   8 DEC 0 COMMENT "Fecha del SAT"             OF oDbf
      FIELD NAME "CSITUAC"  TYPE "C" LEN  20 DEC 0 COMMENT "Situaci�n del SAT"         OF oDbf
      FIELD NAME "CCODOPE"  TYPE "C" LEN   5 DEC 0 COMMENT "C�digo operario"           OF oDbf
      FIELD NAME "CCODCAT"  TYPE "C" LEN   3 DEC 0 COMMENT "C�digo categor�a"          OF oDbf

      INDEX TO ( cFileName ) TAG "cRefSer" ON "cRef + cNumSer"                         OF oDbf

   END DATABASE oDbf

Return ( oDbf )

//---------------------------------------------------------------------------//

Static Function DefineTemporalMaquinasLineas( cPath, lUniqueName, cFileName )

   local oDbf

   DEFAULT cPath        := cPatTmp()
   DEFAULT lUniqueName  := .t.
   DEFAULT cFileName    := "InfMaqL"

   if lUniqueName
      cFileName         := cGetNewFileName( cFileName, , , cPatTmp() )
   end if

   DEFINE TABLE oDbf FILE ( cFileName ) CLASS "InfMaqL" ALIAS ( cFileName ) PATH ( cPath ) VIA ( cLocalDriver() )

      FIELD NAME "CSERSAT"  TYPE "C" LEN   1 DEC 0 COMMENT "Serie del SAT"             OF oDbf
      FIELD NAME "NNUMSAT"  TYPE "N" LEN   9 DEC 0 COMMENT "N�mero del SAT"            OF oDbf
      FIELD NAME "CSUFSAT"  TYPE "C" LEN   2 DEC 0 COMMENT "Sufijo del SAT"            OF oDbf
      FIELD NAME "DFECSAT"  TYPE "D" LEN   8 DEC 0 COMMENT "Fecha del SAT"             OF oDbf
      FIELD NAME "CCODCLI"  TYPE "C" LEN  12 DEC 0 COMMENT "C�digo del cliente"        OF oDbf
      FIELD NAME "CREF"     TYPE "C" LEN  18 DEC 0 COMMENT "Referencia del art�culo"   OF oDbf
      FIELD NAME "CDETALLE" TYPE "C" LEN 250 DEC 0 COMMENT "Descripci�n de art�culo"   OF oDbf
      FIELD NAME "CNUMSER"  TYPE "C" LEN  30 DEC 0 COMMENT "N�mero de serie"           OF oDbf
      FIELD NAME "CSITUAC"  TYPE "C" LEN  20 DEC 0 COMMENT "Situaci�n del SAT"         OF oDbf
      FIELD NAME "CCODOPE"  TYPE "C" LEN   5 DEC 0 COMMENT "C�digo operario"           OF oDbf
      FIELD NAME "CCODCAT"  TYPE "C" LEN   3 DEC 0 COMMENT "C�digo categor�a"          OF oDbf

      INDEX TO ( cFileName ) TAG "cRefSer" ON "cRef + cNumSer"                         OF oDbf

   END DATABASE oDbf

Return ( oDbf )

//---------------------------------------------------------------------------//

Function cTextoDocumento( nTypDoc )

   local cTextDocument  := ""

   DEFAULT nTypDoc      := oDbfTmp:nTypDoc

   do case
      case nTypDoc == PRE_CLI
         cTextDocument  := "Presupuestos"
      case nTypDoc == PED_CLI
         cTextDocument  := "Pedidos"
      case nTypDoc == ALB_CLI
         cTextDocument  := "Albaranes"
      case nTypDoc == FAC_CLI
         cTextDocument  := "Facturas"
      case nTypDoc == FAC_REC
         cTextDocument  := "Rectificativas"
      case nTypDoc == ANT_CLI
         cTextDocument  := "Anticipos"
      case nTypDoc == TIK_CLI
         cTextDocument  := "Tickets"
      case nTypDoc == COB_TIK
         cTextDocument  := "Cobros tickets"
      case nTypDoc == REC_CLI
         cTextDocument  := "Recibos"
      case nTypDoc == DEV_CLI
         cTextDocument  := "Devoluciones"
      case nTypDoc == VAL_CLI
         cTextDocument  := "Vale"
      case nTypDoc == APT_CLI
         cTextDocument  := "Apartado"
      case nTypDoc == ENT_PED
         cTextDocument  := "Ent. pedido"
      case nTypDoc == ENT_ALB
         cTextDocument  := "Ent. albar�n"
   end case

Return ( cTextDocument )

//---------------------------------------------------------------------------//

Static Function LoadPresupuestoCliente( cCodCli, dbfDiv, dbfIva, Anio )

   if ( dbfPreCliT )->( dbSeek( cCodCli ) )

      while ( dbfPreCliT )->cCodCli == cCodCli .and. !( dbfPreCliT )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfPreCliT )->dFecPre )

            oDbfTmp:Append()
            oDbfTmp:nTypDoc      := PRE_CLI
            oDbfTmp:cNumDoc      := ( dbfPreCliT )->cSerPre + Str( ( dbfPreCliT )->nNumPre ) + ( dbfPreCliT )->cSufPre
            if ( dbfPreCliT )->lEstado
               oDbfTmp:cEstado   := "Aceptado"
            else
               oDbfTmp:cEstado   := "Pendiente"
            end if
            oDbfTmp:dFecDoc      := ( dbfPreCliT )->dFecPre
            oDbfTmp:cCodCli      := ( dbfPreCliT )->cCodCli
            oDbfTmp:cNomCli      := ( dbfPreCliT )->cNomCli
            oDbfTmp:cAlmDoc      := ( dbfPreCliT )->cCodAlm
            oDbfTmp:nImpDoc      := ( dbfPreCliT )->nTotPre
            oDbfTmp:cDivisa      := ( dbfPreCliT )->cDivPre
            oDbfTmp:Save()

         end if

         ( dbfPreCliT )->( dbSkip() )

      end while

   end if

Return nil

//---------------------------------------------------------------------------//

Static Function LoadPedidosCliente( cCodCli, dbfDiv, dbfIva, dbfFPago, Anio )

   if ( dbfPedCliT )->( dbSeek( cCodCli ) )
      while ( dbfPedCliT )->cCodCli == cCodCli .and. !( dbfPedCliT )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfPedCliT )->dFecPed )

            oDbfTmp:Append()
            oDbfTmp:nTypDoc         := PED_CLI
            oDbfTmp:cNumDoc         := ( dbfPedCliT )->cSerPed + Str( ( dbfPedCliT )->nNumPed ) + ( dbfPedCliT )->cSufPed
            do case
               case ( dbfPedCliT )->nEstado == 1
                  oDbfTmp:cEstado   := "Pendiente"
               case ( dbfPedCliT )->nEstado == 2
                  oDbfTmp:cEstado   := "Parcialmente"
               case ( dbfPedCliT )->nEstado == 3
                  oDbfTmp:cEstado   := "Entregado"
            end case
            oDbfTmp:dFecDoc         := ( dbfPedCliT )->dFecPed
            oDbfTmp:cCodCli         := ( dbfPedCliT )->cCodCli
            oDbfTmp:cNomCli         := ( dbfPedCliT )->cNomCli
            oDbfTmp:cAlmDoc         := ( dbfPedCliT )->cCodAlm
            oDbfTmp:nImpDoc         := ( dbfPedCliT )->nTotPed
            oDbfTmp:cDivisa         := ( dbfPedCliT )->cDivPed
            oDbfTmp:Save()

         end if

         ( dbfPedCliT )->( dbSkip() )

      end while
   end if

Return nil

//---------------------------------------------------------------------------//

Static Function LoadAlbaranesCliente( cCodCli, dbfDiv, dbfIva, Anio )

   if ( dbfAlbCliT )->( dbSeek( cCodCli ) )
      while ( dbfAlbCliT )->cCodCli == cCodCli .and. !( dbfAlbCliT )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfAlbCliT )->dFecAlb )

            oDbfTmp:Append()
            oDbfTmp:nTypDoc      := ALB_CLI
            oDbfTmp:cNumDoc      := ( dbfAlbCliT )->cSerAlb + Str( ( dbfAlbCliT )->nNumAlb ) + ( dbfAlbCliT )->cSufAlb
            if( dbfAlbCliT )->lFacturado
               oDbfTmp:cEstado   := "Facturado"
            else
               oDbfTmp:cEstado   := "No facturado"
            end if
            oDbfTmp:dFecDoc      := ( dbfAlbCliT )->dFecAlb
            oDbfTmp:cCodCli      := ( dbfAlbCliT )->cCodCli
            oDbfTmp:cNomCli      := ( dbfAlbCliT )->cNomCli
            oDbfTmp:cAlmDoc      := ( dbfAlbCliT )->cCodAlm
            oDbfTmp:nImpDoc      := ( dbfAlbCliT )->nTotAlb
            oDbfTmp:cDivisa      := ( dbfAlbCliT )->cDivAlb
            oDbfTmp:Save()

         end if

         ( dbfAlbCliT )->( dbSkip() )

      end while
   end if

Return nil

//---------------------------------------------------------------------------//

Static Function LoadFacturasCliente( cCodCli, dbfDiv, dbfIva, Anio )

   if ( dbfFacCliT )->( dbSeek( cCodCli ) )

      while ( dbfFacCliT )->cCodCli == cCodCli .and. !( dbfFacCliT )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfFacCliT )->dFecFac )

            oDbfTmp:Append()
            oDbfTmp:nTypDoc      := FAC_CLI
            oDbfTmp:cNumDoc      := ( dbfFacCliT )->cSerie + Str( ( dbfFacCliT )->nNumFac ) + ( dbfFacCliT )->cSufFac
            if( dbfFacCliT )->lLiquidada
               oDbfTmp:cEstado   := "Liquidada"
            else
               oDbfTmp:cEstado   := "No liquidada"
            end if
            oDbfTmp:dFecDoc      := ( dbfFacCliT )->dFecFac
            oDbfTmp:cCodCli      := ( dbfFacCliT )->cCodCli
            oDbfTmp:cNomCli      := ( dbfFacCliT )->cNomCli
            oDbfTmp:cAlmDoc      := ( dbfFacCliT )->cCodAlm
            oDbfTmp:cDivisa      := ( dbfFacCliT )->cDivFac
            oDbfTmp:nImpDoc      := ( dbfFacCliT )->nTotFac
            oDbfTmp:Save()

         end if

         ( dbfFacCliT )->( dbSkip() )

      end while
   end if

Return nil

//---------------------------------------------------------------------------//

Static Function LoadFacturasRectificativas( cCodCli, dbfDiv, dbfIva, Anio )

   if ( dbfFacRecT )->( dbSeek( cCodCli ) )

      while ( dbfFacRecT )->cCodCli == cCodCli .and. !( dbfFacRecT )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfFacRecT )->dFecFac )

            oDbfTmp:Append()
            oDbfTmp:nTypDoc      := FAC_REC
            oDbfTmp:cNumDoc      := ( dbfFacRecT )->cSerie + Str( ( dbfFacRecT )->nNumFac ) + ( dbfFacRecT )->cSufFac
            if( dbfFacRecT )->lLiquidada
               oDbfTmp:cEstado   := "Liquidada"
            else
               oDbfTmp:cEstado   := "No liquidada"
            end if
            oDbfTmp:dFecDoc      := ( dbfFacRecT )->dFecFac
            oDbfTmp:cCodCli      := ( dbfFacRecT )->cCodCli
            oDbfTmp:cNomCli      := ( dbfFacRecT )->cNomCli
            oDbfTmp:cAlmDoc      := ( dbfFacRecT )->cCodAlm
            oDbfTmp:cDivisa      := ( dbfFacRecT )->cDivFac
            oDbfTmp:nImpDoc      := ( dbfFacRecT )->nTotFac
            oDbfTmp:Save()

         end if

         ( dbfFacRecT )->( dbSkip() )

      end while
   end if

Return nil

//---------------------------------------------------------------------------//

Static Function LoadRecibosCliente( cCodCli, dbfDiv, dbfIva, dbfClient, Anio )

   local nOrd  := ( dbfFacCliP )->( ordSetFocus( "cCodCli" ) )

   if ( dbfFacCliP )->( dbSeek( cCodCli ) )
      while ( dbfFacCliP )->cCodCli == cCodCli .and. !( dbfFacCliP )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfFacCliP )->dPreCob )

            oDbfTmp:Append()
            oDbfTmp:nTypDoc      := REC_CLI
            oDbfTmp:cNumDoc      := ( dbfFacCliP )->cSerie + Str( ( dbfFacCliP )->nNumFac ) + ( dbfFacCliP )->cSufFac
            oDbfTmp:nNumRec      := ( dbfFacCliP )->nNumRec
            if ( dbfFacCliP )->lCobrado
               oDbfTmp:cEstado   := "Cobrado"
            else
               oDbfTmp:cEstado   := "Pendiente"
            end if
            oDbfTmp:dFecDoc      := ( dbfFacCliP )->dPreCob
            oDbfTmp:cCodCli      := ( dbfFacCliP )->cCodCli
            oDbfTmp:cNomCli      := RetClient( ( dbfFacCliP )->cCodCli, dbfClient )
            oDbfTmp:cAlmDoc      := Space( 3 )
            oDbfTmp:cDivisa      := ( dbfFacCliP )->cDivPgo
            oDbfTmp:nImpDoc      := nTotRecCli( dbfFacCliP, dbfDiv, cDivEmp() )
            oDbfTmp:Save()

         end if

         ( dbfFacCliP )->( dbSkip() )

      end while
   end if

   ( dbfFacCliP )->( ordSetFocus( nOrd ) )

Return nil

//---------------------------------------------------------------------------//

Static Function LoadAnticiposCliente( cCodCli, dbfDiv, dbfIva, Anio )

   if ( dbfAntCliT )->( dbSeek( cCodCli ) )
      while ( dbfAntCliT )->cCodCli == cCodCli .and. !( dbfAntCliT )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfAntCliT )->dFecAnt )

            oDbfTmp:Append()
            oDbfTmp:nTypDoc      := ANT_CLI
            oDbfTmp:cNumDoc      := ( dbfAntCliT )->cSerAnt + Str( ( dbfAntCliT )->nNumAnt ) + ( dbfAntCliT )->cSufAnt
            if( dbfAntCliT )->lLiquidada 
               oDbfTmp:cEstado   := "Liquidado"
            else
               oDbfTmp:cEstado   := "No liquidado"
            end if
            oDbfTmp:dFecDoc      := ( dbfAntCliT )->dFecAnt
            oDbfTmp:cCodCli      := ( dbfAntCliT )->cCodCli
            oDbfTmp:cNomCli      := ( dbfAntCliT )->cNomCli
            oDbfTmp:cAlmDoc      := ( dbfAntCliT )->cCodAlm
            oDbfTmp:cDivisa      := ( dbfAntCliT )->cDivAnt
            oDbfTmp:nImpDoc      := ( dbfAntCliT )->nImpArt
            oDbfTmp:Save()

         end if

         ( dbfAntCliT )->( dbSkip() )

      end while
   end if

Return nil

//---------------------------------------------------------------------------//

Static Function LoadEntregasPedidos( cCodCli, Anio )

   if ( dbfPedCliP )->( dbSeek( cCodCli ) )

      while ( dbfPedCliP )->cCodCli == cCodCli .and. !( dbfPedCliP )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfPedCliP )->dEntrega )

            oDbfTmp:Append()
            oDbfTmp:nTypDoc      := ENT_PED
            oDbfTmp:cNumDoc      := ( dbfPedCliP )->cSerPed + Str( ( dbfPedCliP )->nNumPed ) + ( dbfPedCliP )->cSufPed
            oDbfTmp:nNumRec      := ( dbfPedCliP )->nNumRec
            if ( dbfPedCliP )->lPasado
               oDbfTmp:cEstado   := "Pasado"
            else
               oDbfTmp:cEstado   := "No pasado"
            end if
            oDbfTmp:dFecDoc      := ( dbfPedCliP )->dEntrega
            oDbfTmp:cCodCli      := ( dbfPedCliP )->cCodCli
            oDbfTmp:cNomCli      := RetFld( ( dbfPedCliP )->cCodCli, dbfClient, "Titulo" )
            oDbfTmp:cAlmDoc      := Space(3)
            oDbfTmp:cDivisa      := ( dbfPedCliP )->cDivPgo
            oDbfTmp:nImpDoc      := ( dbfPedCliP )->nImporte
            oDbfTmp:Save()

         end if

         ( dbfPedCliP )->( dbSkip() )

      end while

   end if

Return nil

//---------------------------------------------------------------------------//

Static Function LoadEntregasAlbaranes( cCodCli, Anio )

   if ( dbfAlbCliP )->( dbSeek( cCodCli ) )

      while ( dbfAlbCliP )->cCodCli == cCodCli .and. !( dbfAlbCliP )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfAlbCliP )->dEntrega )

            oDbfTmp:Append()
            oDbfTmp:nTypDoc      := ENT_ALB
            oDbfTmp:cNumDoc      := ( dbfAlbCliP )->cSerAlb + Str( ( dbfAlbCliP )->nNumAlb ) + ( dbfAlbCliP )->cSufAlb
            oDbfTmp:nNumRec      := ( dbfAlbCliP )->nNumRec
            if ( dbfAlbCliP )->lPasado
               oDbfTmp:cEstado   := "Pasado"
            else
               oDbfTmp:cEstado   := "No pasado"
            end if
            oDbfTmp:dFecDoc      := ( dbfAlbCliP )->dEntrega
            oDbfTmp:cCodCli      := ( dbfAlbCliP )->cCodCli
            oDbfTmp:cNomCli      := ( ( dbfAlbCliP )->cCodCli, dbfClient, "Titulo" )
            oDbfTmp:cAlmDoc      := Space(3)
            oDbfTmp:cDivisa      := ( dbfAlbCliP )->cDivPgo
            oDbfTmp:nImpDoc      := ( dbfAlbCliP )->nImporte
            oDbfTmp:Save()

         end if

         ( dbfAlbCliP )->( dbSkip() )

      end while

   end if

Return nil

//---------------------------------------------------------------------------//

Static Function LoadTiketsCliente( cCodCli, dbfDiv, dbfIva, Anio )

   if ( dbfTikCliT )->( dbSeek( cCodCli ) )

      while ( dbfTikCliT )->cCliTik == cCodCli .and. !( dbfTikCliT )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfTikCliT )->dFecTik )

            if ( dbfTikCliT )->cTipTik == SAVTIK .or.;
               ( dbfTikCliT )->cTipTik == SAVDEV .or.;
               ( dbfTikCliT )->cTipTik == SAVAPT .or.;
               ( dbfTikCliT )->cTipTik == SAVVAL

               oDbfTmp:Append()

               do case
               case( dbfTikCliT )->cTipTik == SAVTIK

                  oDbfTmp:nTypDoc      := TIK_CLI

                  if ( dbfTikCliT )->lPgdTik
                     oDbfTmp:cEstado   := "Cobrado"
                  else
                     oDbfTmp:cEstado   := "No cobrado"
                  end if

               case ( dbfTikCliT )->cTipTik == SAVDEV

                  oDbfTmp:nTypDoc      := DEV_CLI
                  oDbfTmp:cEstado      := "Devoluci�n"

               case ( dbfTikCliT )->cTipTik == SAVVAL

                  oDbfTmp:nTypDoc      := VAL_CLI

                  if ( dbfTikCliT )->lLiqTik
                     oDbfTmp:cEstado   := "Liquidado"
                  else
                     oDbfTmp:cEstado   := "Pdte. liquidar"
                  end if

               case ( dbfTikCliT )->cTipTik == SAVAPT
                  oDbfTmp:nTypDoc      := APT_CLI
                  oDbfTmp:cEstado      := "Apartado"

               end case

               oDbfTmp:cNumDoc      := ( dbfTikCliT )->cSerTik + ( dbfTikCliT )->cNumTik + ( dbfTikCliT )->cSufTiK
               oDbfTmp:dFecDoc      := ( dbfTikCliT )->dFecTik
               oDbfTmp:cCodCli      := ( dbfTikCliT )->cCliTik
               oDbfTmp:cNomCli      := ( dbfTikCliT )->cNomTik
               oDbfTmp:cAlmDoc      := ( dbfTikCliT )->cAlmTik
               oDbfTmp:nImpDoc      := ( dbfTikCliT )->nTotTik
               oDbfTmp:cDivisa      := ( dbfTikCliT )->cDivTik
               oDbfTmp:Save()

            end if

         end if

         ( dbfTikCliT )->( dbSkip() )

      end while

   end if

Return nil

//---------------------------------------------------------------------------//

Static Function LoadCobrosTiketsCliente( cCodCli, dbfDiv, dbfIva, Anio )

   if ( dbfTikCliT )->( dbSeek( cCodCli ) )

      while ( dbfTikCliT )->cCliTik == cCodCli .and. !( dbfTikCliT )->( eof() )

         if Anio == nil .or. Anio == Year( ( dbfTikCliT )->dFecTik )

            if ( dbfTikCliT )->cTipTik == SAVTIK .or.;
               ( dbfTikCliT )->cTipTik == SAVDEV .or.;
               ( dbfTikCliT )->cTipTik == SAVAPT .or.;
               ( dbfTikCliT )->cTipTik == SAVVAL

               oDbfTmp:Append()
               oDbfTmp:nTypDoc      := COB_TIK
               oDbfTmp:cNumDoc      := ( dbfTikCliT )->cSerTik + ( dbfTikCliT )->cNumTik + ( dbfTikCliT )->cSufTiK
               oDbfTmp:dFecDoc      := ( dbfTikCliT )->dFecTik
               oDbfTmp:cCodCli      := ( dbfTikCliT )->cCliTik
               oDbfTmp:cNomCli      := ( dbfTikCliT )->cNomTik
               oDbfTmp:cAlmDoc      := ( dbfTikCliT )->cAlmTik
               oDbfTmp:cDivisa      := ( dbfTikCliT )->cDivTik
               oDbfTmp:nImpDoc      := nTotCobTik( ( dbfTikCliT )->cSerTik + ( dbfTikCliT )->cNumTik + ( dbfTikCliT )->cSufTik, dbfTikCliP, dbfDiv )
               oDbfTmp:Save()

            end if

         end if

         ( dbfTikCliT )->( dbSkip() )

      end while

   end if

Return nil

//---------------------------------------------------------------------------//

Static Function nTotImp( oDbfTmp )

   local nRec     := 0
   local nTotImp  := 0

   if !Empty( oDbfTmp ) .and. ( oDbfTmp:Used() )

      nRec        := oDbfTmp:Recno()

      oDbfTmp:GoTop()
      while !oDbfTmp:Eof()

         nTotImp  += oDbfTmp:nImpDoc

         oDbfTmp:Skip()

      end while

      oDbfTmp:GoTo( nRec )

   end if

Return ( nTotImp )

//--------------------------------------------------------------------------//

function cMesEsp(n)

   local cMes  := ""
   local aMes  := { "Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" }

   if n >= 1 .or. n <= 12
      cMes     := aMes[ n ]
   end if

return ( cMes )

//---------------------------------------------------------------------------//

Static Function Filtro( oBrwTmp )

   local oFilter  := TFilterCreator():Init() 
   
   oFilter:SetDatabase( oDbfTmp )  
   oFilter:Dialog()

   if !Empty( oFilter:cExpresionFilter )
      oDbfTmp:SetFilter( oFilter:cExpresionFilter )
      SetWindowText( oBtnFiltro:hWnd, "Filtro activo" )
   else 
      oDbfTmp:SetFilter()
      SetWindowText( oBtnFiltro:hWnd, "Filtrar" )
   end if 

   oBrwTmp:Refresh()

Return( .t. )

//---------------------------------------------------------------------------//
/*
Esta funcion devuelve el total entregado por un cliente
*/

Function nTotEntCli( cCodCli, dbfPedCliT, dbfPedCliP, dbfAlbCliT, dbfAlbCliP, cPorDiv, nYear )

   local nTotal   := 0
   local nRec
   local nOrdAnt

   /*
   Recorremos los pedidos sumando s�lo las entregas de pedidos que no hayan sido albaranados
   */

   nRec           := ( dbfPedCliP )->( RecNo() )
   nOrdAnt        := ( dbfPedCliP )->( OrdSetFocus( "NNUMPED" ) )

   if( dbfPedCliT )->( dbSeek( cCodCli ) )

      while ( dbfPedCliT )->cCodCli == cCodCli .and. !( dbfPedCliT )->( Eof() )

         if ( dbfPedCliT )->nEstado <= 1 .and.;
            ( nYear == nil .or. Year( ( dbfPedCliT )->dFecPed ) == nYear )

            if ( dbfPedCliP )->( dbSeek( ( dbfPedCliT )->cSerPed + Str( ( dbfPedCliT )->nNumPed ) + ( dbfPedCliT )->cSufPed ) )

               while ( dbfPedCliP )->cSerPed + Str( ( dbfPedCliP )->nNumPed ) + ( dbfPedCliP )->cSufPed == ( dbfPedCliT )->cSerPed + Str( ( dbfPedCliT )->nNumPed ) + ( dbfPedCliT )->cSufPed .and. !( dbfPedCliP )->(Eof())

                  nTotal += ( dbfPedCliP )->nImporte

               ( dbfPedCliP )->( dbSkip() )

               end while

            end if

         end if

      ( dbfPedCliT )->( dbSkip() )

      end while

   end if

   ( dbfPedCliP )->( OrdSetFocus( nOrdAnt ) )
   ( dbfPedCliP )->( dbGoTo( nRec ) )

   /*
   Recorremos los albaranes sumando s�lo las entregas de albaranes que no hayan sido facturado
   */

   nRec           := ( dbfAlbCliP )->( RecNo() )
   nOrdAnt        := ( dbfAlbCliP )->( OrdSetFocus( "NNUMALB" ) )

   if( dbfAlbCliT )->( dbSeek( cCodCli ) )

      while ( dbfAlbCliT )->cCodCli == cCodCli .and. !( dbfAlbCliT )->( Eof() )

         if !( dbfAlbCliT )->lFacturado .and. ( nYear == nil .or. Year( ( dbfAlbCliT )->dFecAlb ) == nYear )

            if ( dbfAlbCliP )->( dbSeek( ( dbfAlbCliT )->cSerAlb + Str( ( dbfAlbCliT )->nNumAlb ) + ( dbfAlbCliT )->cSufAlb ) )

               while ( dbfAlbCliP )->cSerAlb + Str( ( dbfAlbCliP )->nNumAlb ) + ( dbfAlbCliP )->cSufAlb == ( dbfAlbCliT )->cSerAlb + Str( ( dbfAlbCliT )->nNumAlb ) + ( dbfAlbCliT )->cSufAlb .and. !( dbfAlbCliP )->( Eof() )

               nTotal += ( dbfAlbCliP )->nImporte

               ( dbfAlbCliP )->( dbSkip() )

               end while

            end if

         end if

      ( dbfAlbCliT )->( dbSkip() )

      end while

   end if

   ( dbfAlbCliP )->( OrdSetFocus( nOrdAnt ) )
   ( dbfAlbCliP )->( dbGoTo( nRec ) )

Return ( nTotal )

//---------------------------------------------------------------------------//
/*
Esta funcion devuelve el total que tiene pedido un cliente, para pedidos no albaranados
*/

Function nTotPedXCli( cCodCli, dbfPedCliT, dbfPedCliL, dbfIva, dbfDiv, nYear )

   local nTotal      := 0
   local nRec        := ( dbfPedCliT )->( Recno() )

   if ( dbfPedCliT )->( dbSeek( cCodCli ) )

      while ( dbfPedCliT )->cCodCli == cCodCli .and. !( dbfPedCliT )->( Eof() )

         if ( dbfPedCliT )->nEstado == 1 .and. ( nYear == nil .or. Year( ( dbfPedCliT )->dFecPed ) == nYear )

            nTotal   += nTotPedCli( ( dbfPedCliT )->cSerPed + Str( ( dbfPedCliT )->nNumPed ) + ( dbfPedCliT )->cSufPed, dbfPedCliT, dbfPedCliL, dbfIva, dbfDiv, dbfFPago, nil, cDivEmp(), .f. )

         end if

         ( dbfPedCliT )->( dbSkip() )

      end while

   end if

   ( dbfPedCliT )->( dbGoTo( nRec ) )

Return nTotal

//---------------------------------------------------------------------------//

static function TotalAlbaranesClientes( cCodCli, dbfAlbCliT, dbfAlbCliL, dbfDiv, dbfIva, nYear, lUnits  )

   local a
   local nRec     := ( dbfAlbCliT )->( Recno() )
   local nMes


   if Empty( cCodCli ) .or. ( dbfAlbCliT )->( dbSeek( cCodCli ) )

      while ( Empty( cCodCli ) .or. ( dbfAlbCliT )->cCodCli == cCodCli ) .and. !( dbfAlbCliT )->( Eof() )

         if !( dbfAlbCliT )->lFacturado .and. ( nYear == nil .or. Year( ( dbfAlbCliT )->dFecAlb ) == nYear )

            nMes                    := Month( ( dbfAlbCliT )->dFecAlb )
            a                       := aTotAlbCli( ( dbfAlbCliT )->cSerAlb + Str( ( dbfAlbCliT )->nNumAlb ) + ( dbfAlbCliT )->cSufAlb, dbfAlbCliT, dbfAlbCliL, dbfIva, dbfDiv, cDivEmp() )

            aVta[ nMes, 3 ]         += a[ 4 ]
            aVta[ nMes, 4 ]         += a[ 11]

            if lUnits .and. ( dbfAlbCliL )->( dbSeek( ( dbfAlbCliT )->cSerAlb + Str( ( dbfAlbCliT )->nNumAlb ) + ( dbfAlbCliT )->cSufAlb ) )

               while ( dbfAlbCliT )->cSerAlb + Str( ( dbfAlbCliT )->nNumAlb ) + ( dbfAlbCliT )->cSufAlb == ( dbfAlbCliL )->cSerAlb + Str( ( dbfAlbCliL )->nNumAlb ) + ( dbfAlbCliL )->cSufAlb .and. !( dbfAlbCliL )->( Eof() )

                  aVta[ nMes, 1 ]   += ( dbfAlbCliL )->nCanEnt
                  aVta[ nMes, 2 ]   += nUnitEnt( dbfAlbCliL )

                  ( dbfAlbCliL )->( dbSkip() )

               end while

            end if

         end if

         ( dbfAlbCliT )->( dbSkip() )

      end while

   end if

   ( dbfAlbCliT )->( dbGoTo( nRec ) )

Return nil

//---------------------------------------------------------------------------//

static function TotalFacturasClientes( cCodCli, dbfFacCliT, dbfFacCliL, dbfAntCliT, dbfDiv, dbfIva, nYear, lUnits )

   local a
   local nRec           := ( dbfFacCliT )->( Recno() )
   local nMes

   if Empty( cCodCli ) .or. ( dbfFacCliT )->( dbSeek( cCodCli ) )

      while ( Empty( cCodCli ) .or. ( dbfFacCliT )->cCodCli == cCodCli ) .and. !( dbfFacCliT )->( Eof() )

         if ( nYear == nil .or. Year( ( dbfFacCliT )->dFecFac ) == nYear )

            nMes                    := Month( ( dbfFacCliT )->dFecFac )
            a                       := aTotFacCli( ( dbfFacCliT )->cSerie + Str( ( dbfFacCliT )->nNumFac ) + ( dbfFacCliT )->cSufFac, dbfFacCliT, dbfFacCliL, dbfIva, dbfDiv, nil, dbfAntCliT, nil, cDivEmp(), .f. )

            aVta[ nMes, 3 ]         += a[ 4 ]
            aVta[ nMes, 4 ]         += a[ 11 ]

            if lUnits .and. ( dbfFacCliL )->( dbSeek( ( dbfFacCliT )->cSerie + Str( ( dbfFacCliT )->nNumFac ) + ( dbfFacCliT )->cSufFac ) )

               while ( dbfFacCliT )->cSerie + Str( ( dbfFacCliT )->nNumFac ) + ( dbfFacCliT )->cSufFac == ( dbfFacCliL )->cSerie + Str( ( dbfFacCliL )->nNumFac ) + ( dbfFacCliL )->cSufFac .and. !( dbfFacCliL )->( Eof() )

                  aVta[ nMes, 1 ]   += ( dbfFacCliL )->nCanEnt
                  aVta[ nMes, 2 ]   += nUnitEnt( dbfFacCliL )

                  ( dbfFacCliL )->( dbSkip() )

               end while

            end if

         end if

         ( dbfFacCliT )->( dbSkip() )

      end while

   end if

   ( dbfFacCliT )->( dbGoTo( nRec ) )

return nil

//---------------------------------------------------------------------------//

static function TotalFacturasRectificativas( cCodCli, dbfFacRecT, dbfFacRecL, dbfAntCliT, dbfDiv, dbfIva, nYear, lUnits )

   local a
   local nMes
   local nRec                       := ( dbfFacRecT )->( Recno() )

   if Empty( cCodCli ) .or. ( dbfFacRecT )->( dbSeek( cCodCli ) )

      while ( Empty( cCodCli ) .or. ( dbfFacRecT )->cCodCli == cCodCli ) .and. !( dbfFacRecT )->( Eof() )

         if ( nYear == nil .or. Year( ( dbfFacRecT )->dFecFac ) == nYear )

            nMes                    := Month( ( dbfFacRecT )->dFecFac )

            a                       := aTotFacRec( ( dbfFacRecT )->cSerie + Str( ( dbfFacRecT )->nNumFac ) + ( dbfFacRecT )->cSufFac, dbfFacRecT, dbfFacRecL, dbfIva, dbfDiv, nil, dbfAntCliT, nil, cDivEmp(), .f. )

            aVta[ nMes, 3 ]         += a[ 4 ]
            aVta[ nMes, 4 ]         += a[ 11 ]

            if lUnits .and. ( dbfFacRecL )->( dbSeek( ( dbfFacRecT )->cSerie + Str( ( dbfFacRecT )->nNumFac ) + ( dbfFacRecT )->cSufFac ) )

               while ( dbfFacRecT )->cSerie + Str( ( dbfFacRecT )->nNumFac ) + ( dbfFacRecT )->cSufFac == ( dbfFacRecL )->cSerie + Str( ( dbfFacRecL )->nNumFac ) + ( dbfFacRecL )->cSufFac .and. !( dbfFacRecL )->( Eof() )

                  aVta[ nMes, 1 ]   += ( dbfFacRecL )->nCanEnt
                  aVta[ nMes, 2 ]   += nUnitEnt( dbfFacRecL )

                  ( dbfFacRecL )->( dbSkip() )

               end while

            end if

         end if

         ( dbfFacRecT )->( dbSkip() )

      end while

   end if

   ( dbfFacRecT )->( dbGoTo( nRec ) )

return nil

//---------------------------------------------------------------------------//

static function TotalTicketsClientes( cCodCli, dbfTikCliT, dbfTikCliL, dbfDiv, nYear, lUnits )

   local a
   local nRec           := ( dbfTikCliT )->( Recno() )
   local nMes

   if Empty( cCodCli ) .or. ( dbfTikCliT )->( dbSeek( cCodCli ) )

      while ( Empty( cCodCli ) .or. ( dbfTikCliT )->cCliTik == cCodCli ) .and. !( dbfTikCliT )->( Eof() )

         if ( nYear == nil .or. Year( ( dbfTikCliT )->dFecTik ) == nYear )

            nMes                       := Month( ( dbfTikCliT )->dFecTik )

            if ( dbfTikCliT )->cTipTik == SAVTIK
               aVta[ nMes, 3 ]         += nTotTik( ( dbfTikCliT )->cSerTik + ( dbfTikCliT )->cNumTik + ( dbfTikCliT )->cSufTik, dbfTikCliT, dbfTikCliL, dbfDiv, nil, cDivEmp(), .f. )
            elseif ( dbfTikCliT )->cTipTik == SAVDEV
               aVta[ nMes, 3 ]         -= nTotTik( ( dbfTikCliT )->cSerTik + ( dbfTikCliT )->cNumTik + ( dbfTikCliT )->cSufTik, dbfTikCliT, dbfTikCliL, dbfDiv, nil, cDivEmp(), .f. )
            end if

            if lUnits .and. ( dbfTikCliL )->( dbSeek( ( dbfTikCliT )->cSerTik + (dbfTikCliT)->cNumTik + (dbfTikCliT)->cSufTik ) )

               while ( dbfTikCliT )->cSerTik + ( dbfTikCliT )->cNumTik + ( dbfTikCliT )->cSufTik == ( dbfTikCliL )->cSerTil + ( dbfTikCliL )->cNumTil + ( dbfTikCliL )->cSufTil .and. !( dbfTikCliL )->( Eof() )

                  if ( dbfTikCliT )->cTipTik == SAVTIK
                     aVta[ nMes, 2 ]   += ( dbfTikCliL )->nUntTil

                  elseif ( dbfTikCliT )->cTipTik == SAVDEV
                     aVta[ nMes, 2 ]   -= ( dbfTikCliL )->nUntTil

                  end if

                  ( dbfTikCliL )->( dbSkip() )

               end while

            end if

         end if

         ( dbfTikCliT )->( dbSkip() )

      end while

   end if

   ( dbfTikCliT )->( dbGoTo( nRec ) )

Return nil

//---------------------------------------------------------------------------//

Static Function nCobrosTik( cCodCli, nYear )

Return ( nCobTik( cCodCli, nil, nil, dbfTikCliT, dbfTikCliP, dbfIva, dbfDiv, nYear ) )

//---------------------------------------------------------------------------//

static function nValesTik( cCodCli, nYear )

Return ( nValTik( cCodCli, nil, nil, dbfTikCliT, dbfTikCliL, dbfDiv, nYear ) )

//---------------------------------------------------------------------------//

Static Function nCobrosFac( cCodCli, nYear )

Return ( nCobFacCli( cCodCli, nil, nil, dbfFacCliT, dbfFacCliL, dbfFacCliP, dbfIva, dbfDiv, .t., nYear ) )

//---------------------------------------------------------------------------//

Static Function nTotalRectificativa( cCodCli, nYear )

Return ( nVtaFacRec( cCodCli, nil, nil, dbfFacRecT, dbfFacRecL, dbfIva, dbfDiv, nYear ) )

//---------------------------------------------------------------------------//

Static Function nTotalFacturas( cCodCli, nYear )

Return ( nVtaFacCli( cCodCli, nil, nil, dbfFacCliT, dbfFacCliL, dbfIva, dbfDiv, nYear ) )

//---------------------------------------------------------------------------//

Static Function nTotalTickets( cCodCli, nYear )

Return ( nVtaTik( cCodCli, nil, nil, dbfTikCliT, dbfTikCliL, dbfIva, dbfDiv ) )

//---------------------------------------------------------------------------//

Static Function nTotalAnticipo( cCodCli, nYear )

Return ( nCobAntCli( cCodCli, dbfAntCliT, dbfIva, dbfDiv, nYear ) )

//---------------------------------------------------------------------------//

static function nTotalPedido( cCodCli, nYear )

Return ( nTotPedXCli( cCodCli, dbfPedCliT, dbfPedCliL, dbfIva, dbfDiv, nYear ) )

//---------------------------------------------------------------------------//

static function nTotalEntregas( cCodCli, nYear )

Return ( nTotEntCli( cCodCli, dbfPedCliT, dbfPedCliP, dbfAlbCliT, dbfAlbCliP, cPorDiv, nYear ) )

//---------------------------------------------------------------------------//

Static Function nTotalAlbaran( cCodCli, nYear )

Return ( nVtaAlbCli( cCodCli, nil, nil, dbfAlbCliT, dbfAlbCliL, dbfIva, dbfDiv, .t., nYear ) )

//---------------------------------------------------------------------------//