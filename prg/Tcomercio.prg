#include "FiveWin.Ch" 
#include "Struct.ch"
#include "Factu.ch" 
#include "Ini.ch"
#include "MesDbf.ch" 

#define tipoProducto    1
#define tipoCategoria   2     

//---------------------------------------------------------------------------//

static oTimer
static oComercio
static oMsgAlarm

//---------------------------------------------------------------------------//

CLASS TComercio

   CLASSDATA oInstance

   DATA  TPrestashopConfig  
   
   DATA  aSend
   DATA  oInt
   DATA  oUrl
   DATA  oFtp
   DATA  nTotMeter

   DATA  oBmpSel
   DATA  oDlg
   DATA  oFld
   DATA  oBmp

   DATA  oDlgWait
   DATA  oBmpWait
   DATA  oSayWait
   DATA  cSayWait

   DATA  oSubItem
   DATA  oSubItem2

   DATA  cIniFile

   DATA  lPedidosWeb                INIT  .f.

   DATA  nTipoEnvio                 INIT  1

   DATA  nLevel

   DATA  aFilesProcessed

   DATA  oBotonTerminar

   DATA  cFilTxt
   DATA  oFilTxt
   DATA  hFilTxt

   DATA  oBtnCancel
   DATA  oBtnExportar
   DATA  oBtnImportar
   DATA  oBtnStock

   DATA  cPath

   DATA  lSyncAll                   INIT .f.
   DATA  lArticulos                 INIT .f.
   DATA  lFamilias                  INIT .f.
   DATA  lPedidos                   INIT .f.
   DATA  lFabricantes               INIT .f.
   DATA  lIva                       INIT .f.
   DATA  lImagenes                  INIT .f.
   DATA  lClientes                  INIT .f.

   DATA  oArticulos
   DATA  oPedidos
   DATA  oTipIva
   DATA  oCliente
   DATA  oImagenes

   DATA  oArt
   DATA  oPro
   DATA  oTblPro
   DATA  oFPago

   DATA  oArtDiv
   DATA  oTipArt
   DATA  oFam
   DATA  oGrpFam
   DATA  oCli
   DATA  oObras

   DATA  oIva
   DATA  oDivisas
   DATA  oPedCliT
   DATA  oPedCliI
   DATA  oPedCliE
   DATA  oPedCliL
   DATA  oCount
   DATA  oFab
   DATA  oKit
   DATA  oAlbCliT
   DATA  oAlbCliL
   DATA  oFacCliL
   DATA  oFacRecL
   DATA  oTikCliL
   DATA  oProLin
   DATA  oProMat
   DATA  oHisMov
   DATA  oPedPrvL
   DATA  oAlbPrvT
   DATA  oAlbPrvL
   DATA  oFacPrvL
   DATA  oRctPrvL
   DATA  oArtImg
   DATA  oOferta
   DATA  oTextOfertas
   DATA  oPreCliT
   DATA  oPreCliL
   DATA  oPreCliI
   DATA  oPreCliE

   DATA  aDeletedImages

   DATA  oStock

   DATA  oCon
   DATA  cHost
   DATA  cUser
   DATA  cPasswd
   DATA  cDbName
   DATA  nPort
   DATA  cSeriePed

   DATA  Cookiekey

   DATA  oInt
   DATA  aImages
   DATA  aImagesArticulos
   DATA  aImagesCategories
   DATA  aTipoImagesPrestashop

   DATA  nImagePosition             INIT 0

   DATA  nLanguage

   DATA  nPrecioMinimo              INIT 0

   DATA  lProductIdColumnImageShop  
   DATA  lProductIdColumnProductAttribute
   DATA  lProductIdColumnProductAttributeShop

   DATA  nSecondTimer

   DATA  lDefImgPrp                 INIT .f.

   DATA  nNumeroCategorias          INIT 0
   DATA  aCategorias                INIT {}

   DATA  aArticulosActualizar       INIT {}

   DATA  cPrefijoBaseDatos

   DATA TSituaciones

   DATA idOrderPrestashop
   DATA cSeriePedido
   DATA cSeriePresupuesto
   DATA nNumeroPedido
   DATA nNumeroPresupuesto
   DATA cSufijoPedido
   DATA cSufijoPresupuesto

   METHOD GetInstance()              
   METHOD New()                        CONSTRUCTOR
   METHOD Connect()
   METHOD Disconnect()

   METHOD MeterTotal( oMeterTotal )    INLINE ( iif( oMeterTotal == nil, ::oMeterTotal := oMeterTotal, ::oMeterTotal ) )
   METHOD TextTotal( oTextTotal )      INLINE ( iif( oTextTotal == nil, ::oTextTotal := oTextTotal, ::oTextTotal ) )

   METHOD lReady()                     INLINE ( !empty( ::cHost ) .and. !empty( ::cUser ) .and. !empty( ::cDbName ) )

   METHOD writeText( cText )           INLINE ( if( !empty( ::oTextTotal ), ::oTextTotal:SetText( cText ), ),;
                                                if( !empty( ::oTree ), ::oTree:Select( ::oTree:Add( cText ) ), ),;
                                                logWrite( cText, "prestashop.log" ) )

   // Apertura y cierre de ficheros--------------------------------------------

   METHOD filesOpen()
   METHOD filesClose()

   // Dialogos-----------------------------------------------------------------

   METHOD dialogActivate( oWnd )
      METHOD dialogStart()
      METHOD disableDialog()           INLINE   (  if( !empty(::oDlg),           ::oDlg:bValid := {|| .f. }, ),;
                                                   if( !empty(::oBtnExportar),   ::oBtnExportar:Hide(), ),;
                                                   if( !empty(::oBtnImportar),   ::oBtnImportar:Hide(), ),;
                                                   if( !empty(::oBtnStock),      ::oBtnStock:Hide(), ),;
                                                   if( !empty(::oBtnCancel),     ::oBtnCancel:Disable(), ) )
      METHOD enableDialog()            INLINE   (  if( !empty(::oDlg),           ::oDlg:bValid := {|| .t. }, ),;
                                                   if( !empty(::oBtnCancel),     ::oBtnCancel:Enable(), ) )

   // Mensajes-----------------------------------------------------------------

   DATA  oTree

   DATA  oMeterTotal
   DATA  nMeterTotal                   INIT 0

   METHOD MeterTotal( oMeterTotal)     INLINE ( iif( oMeterTotal != nil, ::oMeterTotal := oMeterTotal, ::oMeterTotal ) )
   METHOD setMeterTotal( nTotal )      INLINE ( ::nTotMeter := nTotal, ( if( !empty( ::oMeterProceso ), ::oMeterProceso:SetTotal( ::nTotMeter ), ) ) )

   DATA  oTextTotal
   DATA  cTextTotal

   METHOD TextTotal( oTextTotal )      INLINE ( iif( oTextTotal != nil, ::oTextTotal := oTextTotal, ::oTextTotal ) )

   DATA  oMeterProceso
   DATA  nMeterProceso                 INIT 0

   DATA  aIvaData                      INIT {}
   DATA  aFabricantesData              INIT {}
   DATA  aFamiliaData                  INIT {}
   DATA  aArticuloData                 INIT {}
   DATA  aPropiedadesCabeceraData      INIT {}
   DATA  aPropiedadesLineasData        INIT {}
   DATA  aStockArticuloData            INIT {}

   METHOD buildFTP()                   
   METHOD destroyFTP()                 INLINE ( ::oFtp:end() )

   METHOD treeSetText( cText )
   METHOD MeterTotalText( cText )
   METHOD MeterTotalSetTotal( nTotal )
   METHOD meterProcesoText( cText )
   METHOD meterProcesoSetTotal( nTotal )
   
   METHOD ExportarPrestashop()
   METHOD ImportarPrestashop()

   METHOD AppendIvaPrestashop()
   METHOD InsertIvaPrestashop()
   METHOD lUpdateIvaPrestashop( nId )
   METHOD DelIdIvaPrestashop()

   METHOD AppendFabricantesPrestashop()
   METHOD InsertFabricantesPrestashop()
   METHOD lUpdateFabricantesPrestashop()
   METHOD DelIdFabricantePrestashop()

   METHOD AppendFamiliaPrestashop()
   METHOD AddCategoriaRaiz()
   METHOD InsertCategoriesPrestashop()
   METHOD UpdateCategoriesPrestashop()
   METHOD DeleteCategoriesPrestashop()
   METHOD DeleteImagesCategories()
   METHOD ActualizaCategoriesPrestashop()
   METHOD DelCascadeCategoriesPrestashop()
   METHOD ActualizaCaterogiaPadrePrestashop()
   METHOD RecalculaPosicionesCategoriasPrestashop()
   
   METHOD DelIdFamiliasPrestashop()

   METHOD AppendPropiedadesPrestashop()
   METHOD InsertPropiedadesPrestashop()
   METHOD UpdatePropiedadesPrestashop()
   METHOD DeletePropiedadesPrestashop()
   METHOD ActualizaPropiedadesPrestashop()
   METHOD InsertLineasPropiedadesPrestashop()
   METHOD UpdateLineasPropiedadesPrestashop()
   METHOD DeleteLineasPropiedadesPrestashop()
   METHOD InsertPropiedadesProductPrestashop()
   METHOD EliminaPropiedadesProductsPrestashop()
   METHOD GetValPrp( nIdPrp, nProductAttibuteId )
   METHOD DelIdPropiedadesPrestashop()

   METHOD AppendArticuloPrestashop()
   METHOD ActualizaProductsPrestashop()
   METHOD InsertProductsPrestashop()
   METHOD DeleteProductsPrestashop()
   METHOD InsertOfertasPrestashop()
   METHOD UpdateOfertasPrestashop()
   METHOD DeleteImagesProducts( cCodWeb )
   METHOD InsertImageProductsPrestashop( cCodArt )
   METHOD InsertImageProductImage()
   METHOD InsertImageProductImageShop( nCodigoImagen )
   METHOD InsertImageProductImageLang( nCodigoImagen )

   METHOD nIvaProduct( cCodArt )
   METHOD ActualizaPropiedadesProducts( cCodWeb )
   METHOD ActualizaStockProductsPrestashop( cCodigoArticulo )
   METHOD nIdProductAttribute( cCodWebArt, cCodWebValPr1, cCodWebValPr2 )

   METHOD DelIdArticuloPrestashop()

   METHOD AppTipoArticuloPrestashop()

   //---------------------------------------------------------------------------//

   METHOD aTipoImagenPrestashop()

   METHOD addImages( cImage )                INLINE ( iif(  ascan( ::aImages, cImage ) == 0,;
                                                            aadd( ::aImages, cImage ),;
                                                            ),;
                                                      ::aImages )

   METHOD addImagesArticulos( cImage )       INLINE ( iif(  ascan( ::aImagesArticulos, cImage ) == 0,;
                                                            aadd( ::aImagesArticulos, cImage ),;
                                                            ),;
                                                      ::aImagesArticulos )

   METHOD addImagesCategories( cImage )      INLINE ( iif(  ascan( ::aImagesCategories, cImage ) == 0,;
                                                            aadd( ::aImagesCategories, cImage ),;
                                                            ),;
                                                      ::aImagesCategories )


   METHOD addTipoImagesPrestashop( cImage )  INLINE ( iif(  ascan( ::aTipoImagesPrestashop, cImage ) == 0,;
                                                            aadd( ::aTipoImagesPrestashop, cImage ),;
                                                            ),;
                                                      ::aTipoImagesPrestashop )

   //---------------------------------------------------------------------------//

   METHOD nDefImagen( cCodArt, cImagen )
   METHOD nCodigoWebImagen( cCodArt, cImagen )
   METHOD lLimpiaRefImgWeb()

   METHOD ConectBBDD()
   METHOD DisconectBBDD()
   METHOD lShowDialogWait()
   METHOD lHideDialogWait()
   METHOD cTextoWait( cText )
   METHOD AvisoSincronizaciontotal()
   METHOD cPreFixtable( cName )
   METHOD AutoRecive()
   METHOD GetLanguagePrestashop()

   METHOD AppendClientesToPrestashop()

   METHOD checkDate( cDatePrestashop )

   METHOD AppendClientPrestashop()
   METHOD EstadoPedidosPrestashop()
   METHOD AppendMessagePedido()

   METHOD GetParentCategories()

   METHOD cValidDirectoryFtp( cDirectory )

   METHOD CreateDirectoryImagesLocal( cCarpeta )

   METHOD controllerOrders()
   METHOD loadOrders()
   METHOD processOrder( oQuery )
   METHOD checkDate( cDatePrestashop )

   METHOD payOrder( cPrestashopModule )

   METHOD documentRecived( oQuery, oDatabase )   
      METHOD orderRecived( oQuery )    INLINE ( ::documentRecived( oQuery, ::oPedCliT ) )
      METHOD estimateRecived( oQuery ) INLINE ( ::documentRecived( oQuery, ::oPreCliT ) )

   METHOD insertPedidoPrestashop( oQuery )
   METHOD insertPresupuestoPrestashop( oQuery )
   METHOD getCountersPedidoPrestashop( oQuery )
   METHOD insertCabeceraPedidoPretashop( oQuery )
   METHOD insertLineaPedidoPrestashop( oQuery )
   METHOD insertClientePedidoPrestashop( oQuery )
   METHOD getDate( cDatePrestashop )
   METHOD getTime( ctimePrestashop )
   METHOD insertPresupuestoPrestashop( oQuery )
   METHOD getCountersPresupustoPrestashop( oQuery )
   METHOD insertDatosCabeceraPedidoPretashop( oQuery )
   METHOD insertDatosCabeceraPresupuestoPretashop( oQuery )
   METHOD insertLineaPresupuestoPrestashop( oQuery )
   METHOD appendMessagePresupuesto ( dFecha )
   METHOD insertCabeceraPresupuestoPretashop( oQuery )
   METHOD insertClientePresupuestoPrestashop( oQuery )
   METHOD appendStatePedidoPrestashop( oQuery )
   METHOD appendStatePresupuestoPrestashop( oQuery )

   METHOD syncSituacionesPedidoPrestashop( cCodWeb, cSerPed, nNumPed, cSufPed )
   METHOD syncronizeStatesGestool( cCodWeb, cSerPed, nNumPed, cSufPed )
   METHOD checkExistStateUp( oQuery, cCodWeb, cSerPed, nNumPed, cSufPed )
   METHOD syncronizeStatesPrestashop ( cSerPed, nNumPed, cSufPed, cCodWeb, oQuery )
   METHOD downloadState( oQuery, cSerPed, nNumPed, cSufPed )
   METHOD UploadState( id_order_state, dFecSit, tFecSit, cCodWeb )

   METHOD getDatePrestashop( dFec, tFec )
   METHOD idOrderState( cSitua )

   METHOD syncSituacionesPresupuestoPrestashop( cCodWeb, cSerPre, nNumPre, cSufPre )
   METHOD syncronizeStatesPresupuestoGestool( cCodWeb, cSerPre, nNumPre, cSufPre )
   METHOD presupuestoCheckExistStateUp( oQuery, cCodWeb, cSerPre, nNumPre, cSufPre )
   METHOD downloadStateToPresupuesto( oQuery, cSerPre, nNumPre, cSufPre )
   METHOD syncronizeStatesPresupuestoPrestashop ( cSerPre, nNumPre, cSufPre, cCodWeb )
   METHOD UploadStatePrestashop( id_order_state, dFecSit, tFecSit, cCodWeb )

   METHOD isProductIdColumn( cTable )
   METHOD isProductIdColumnImageShop()                INLINE ( ::isProductIdColumn( "image_shop" ) )
   METHOD isProductIdColumnProductAttribute()         INLINE ( ::isProductIdColumn( "product_attribute" ) )
   METHOD isProductIdColumnProductAttributeShop()     INLINE ( ::isProductIdColumn( "product_attribute_shop" ) )

   // Datos para la recopilacion de informacion----------------------------

   METHOD ProductInCurrentWeb()              INLINE ( ::oArt:lPubInt )  // DE MOMENTO

   // Metodos para la recopilacion de informacion----------------------------

   METHOD prestaShopConnect()
   METHOD prestashopDisConnect()

   METHOD buildInitData()
   METHOD buildIvaPrestashop( id )
   METHOD buildFabricantePrestashop( id )
   METHOD buildFamiliaPrestashop( id )

   METHOD buildProductPrestashop( id )
   METHOD buildInformacion()
   METHOD buildSubirInformacion()
   METHOD buildInsertIvaPrestashop( hIvaData )
   METHOD buildInsertFabricantesPrestashop( hFabricantesData )
   METHOD buildInsertCategoriesPrestashop( hFamiliaData )
   METHOD buildInsertProductsPrestashop( hArticuloData )
   METHOD buildArticuloPrestashop( id )
   METHOD buildActualizaCaterogiaPadrePrestashop( hFamiliaData )
   METHOD buildInsertImageProductsPrestashop( hArticuloData )
   METHOD buildRecalculaPosicionesCategoriasPrestashop()
   METHOD buildInsertOfertasPrestashop( hArticuloData, nCodigoWeb )
   METHOD buildPropiedadesPrestashop( id )
   METHOD buildInsertPropiedadesPrestashop( hPropiedadesCabData )
   METHOD buildInsertLineasPropiedadesPrestashop( hPropiedadesLinData )
   METHOD buildInsertPropiedadesProductPrestashop( hArticuloData, nCodigoWeb )

   METHOD buildImagesArticuloPrestashop( id )

   METHOD buildDeleteProductPrestashop()

   METHOD buildDeleteImagesProducts( cCodWeb )
   METHOD buildDeleteImagesFiles()

   METHOD buildImagenes()
   METHOD buildSubirImagenes()

   METHOD buildPrecioArtitulo()

   METHOD buildGetParentCategories()

   METHOD buildExportarPrestashop()

   METHOD buildEliminaTablas()

   METHOD buildCleanPrestashop()

   METHOD buildCleanTable( oTable )

   METHOD buildTextOk( cValue, cTable )      INLINE ( ::treeSetText( "Insertado correctamente " + cValue + ", en la tabla " + cTable, 3 ) )
   METHOD buildTextError( cValue, cTable )   INLINE ( ::treeSetText( "Error insertado " + cValue + ", en la tabla " + cTable, 3 ) )

   METHOD buildActualizaStock()
   METHOD buildActualizaStockProductPrestashop()
   METHOD buildInformacionStockProductPrestashop()
   METHOD buildSubirStockPrestashop()
   METHOD buildAddInformacionStockProductPrestashop()
   METHOD BuildAddArticuloActualizar( cCodArt )

   // ftp y movimientos de ficheros

   DATA  cDirImagen

   METHOD cDirectoryProduct()                INLINE ( ::TPrestashopConfig:getImagesDirectory() + "/p" )
   METHOD cDirectoryCategories()             INLINE ( ::TPrestashopConfig:getImagesDirectory() + "/c" )

   METHOD ftpTestConexion()                  INLINE ( if (  ::oFtp:CreateConexion(),;
                                                            msgInfo( "Conectado a servidor FTP correctamente." ),;
                                                            msgStop( "Error al conectar con el servidor FTP" ) ),;
                                                            ::oFtp:EndConexion() )

END CLASS

//---------------------------------------------------------------------------//

METHOD GetInstance() CLASS TComercio

   if empty( ::oInstance )
      ::oInstance          := ::New()
   end if

RETURN ( ::oInstance )

//---------------------------------------------------------------------------//

METHOD New( oMenuItem, oMeterTotal, oTextTotal ) CLASS TComercio

   DEFAULT oMenuItem       := "01108"

   ::oMeterTotal           := oMeterTotal
   ::oTextTotal            := oTextTotal

   ::lSyncAll              := .f.
   ::nTotMeter             := 0 

   ::TPrestashopConfig     := TPrestashopConfig():New()
   ::TPrestashopConfig:loadJSON()

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD buildInitData() CLASS TComercio

   ::aImages                     := {}
   ::aImagesArticulos            := {}
   ::aImagesCategories           := {}
   ::aTipoImagesPrestashop       := {}

   ::aIvaData                    := {}
   ::aFabricantesData            := {}
   ::aFamiliaData                := {}
   ::aArticuloData               := {}
   ::aArticulosActualizar        := {}
   ::aPropiedadesCabeceraData    := {}
   ::aPropiedadesLineasData      := {}

Return ( Self )

//---------------------------------------------------------------------------//

METHOD Connect()

   ::oCon            := TMSConnect():New()

RETURN ( ::oCon:Connect( ::cHost, ::cUser, ::cPasswd, ::cDbName, ::nPort ) )

//---------------------------------------------------------------------------//

METHOD Disconnect()

   if !empty( ::oCon )
      ::oCon:Destroy()
   end if

RETURN ( self )

//---------------------------------------------------------------------------//

METHOD filesOpen() CLASS TComercio

   local oBlock
   local oError
   local lOpen       := .t.

   oBlock            := ErrorBlock( { | oError | Break( oError ) } )
   BEGIN SEQUENCE

      DATABASE NEW ::oArt     PATH ( cPatArt() ) FILE "ARTICULO.DBF"    VIA ( cDriver() ) SHARED INDEX "ARTICULO.CDX"
      ::oArt:OrdSetFocus( "lPubInt" )

      DATABASE NEW ::oPro     PATH ( cPatArt() ) FILE "PRO.DBF"         VIA ( cDriver() ) SHARED INDEX "PRO.CDX"

      DATABASE NEW ::oTblPro  PATH ( cPatArt() ) FILE "TBLPRO.DBF"      VIA ( cDriver() ) SHARED INDEX "TBLPRO.CDX"

      DATABASE NEW ::oArtDiv  PATH ( cPatArt() ) FILE "ARTDIV.DBF"      VIA ( cDriver() ) SHARED INDEX "ARTDIV.CDX"

      DATABASE NEW ::oOferta  PATH ( cPatArt() ) FILE "OFERTA.DBF"      VIA ( cDriver() ) SHARED INDEX "OFERTA.CDX"

      DATABASE NEW ::oFam     PATH ( cPatArt() ) FILE "FAMILIAS.DBF"    VIA ( cDriver() ) SHARED INDEX "FAMILIAS.CDX"

      DATABASE NEW ::oGrpFam  PATH ( cPatArt() ) FILE "GRPFAM.DBF"      VIA ( cDriver() ) SHARED INDEX "GRPFAM.CDX"

      DATABASE NEW ::oTipArt  PATH ( cPatArt() ) FILE "TIPART.DBF"      VIA ( cDriver() ) SHARED INDEX "TIPART.CDX"

      DATABASE NEW ::oCli     PATH ( cPatCli() ) FILE "CLIENT.DBF"      VIA ( cDriver() ) SHARED INDEX "CLIENT.CDX"

      DATABASE NEW ::oObras   PATH ( cPatCli() ) FILE "OBRAST.DBF"      VIA ( cDriver() ) SHARED INDEX "OBRAST.CDX"

      DATABASE NEW ::oIva     PATH ( cPatDat() ) FILE "TIVA.DBF"        VIA ( cDriver() ) SHARED INDEX "TIVA.CDX"

      DATABASE NEW ::oDivisas PATH ( cPatDat() ) FILE "DIVISAS.DBF"     VIA ( cDriver() ) SHARED INDEX "DIVISAS.CDX"

      ::oPedCliT := TDataCenter():oPedCliT()

      DATABASE NEW ::oPedCliI PATH ( cPatEmp() ) FILE "PEDCLII.DBF"     VIA ( cDriver() ) SHARED INDEX "PEDCLII.CDX"

      DATABASE NEW ::oPedCliE PATH ( cPatEmp() ) FILE "PEDCLIE.DBF"     VIA ( cDriver() ) SHARED INDEX "PEDCLIE.CDX"

      DATABASE NEW ::oPedCliL PATH ( cPatEmp() ) FILE "PEDCLIL.DBF"     VIA ( cDriver() ) SHARED INDEX "PEDCLIL.CDX"

      DATABASE NEW ::oCount   PATH ( cPatEmp() ) FILE "NCOUNT.DBF"      VIA ( cDriver() ) SHARED INDEX "NCOUNT.CDX"

      DATABASE NEW ::oFPago   PATH ( cPatEmp() ) FILE "FPAGO.DBF"       VIA ( cDriver() ) SHARED INDEX "FPAGO.CDX"

      DATABASE NEW ::oFab     PATH ( cPatArt() ) FILE "FABRICANTES.DBF" VIA ( cDriver() ) SHARED INDEX "FABRICANTES.CDX"

      DATABASE NEW ::oKit     PATH ( cPatArt() ) FILE "ARTKIT.DBF"      VIA ( cDriver() ) SHARED INDEX "ARTKIT.Cdx"

      ::oAlbCliT := TDataCenter():oAlbCliT()

      DATABASE NEW ::oAlbCliL PATH ( cPatEmp() ) FILE "ALBCLIL.DBF"     VIA ( cDriver() ) SHARED INDEX "ALBCLIL.CDX"

      DATABASE NEW ::oFacCliL PATH ( cPatEmp() ) FILE "FACCLIL.DBF"     VIA ( cDriver() ) SHARED INDEX "FACCLIL.CDX"

      DATABASE NEW ::oFacRecL PATH ( cPatEmp() ) FILE "FACRECL.DBF"     VIA ( cDriver() ) SHARED INDEX "FACRECL.CDX"

      DATABASE NEW ::oTikCliL PATH ( cPatEmp() ) FILE "TIKEL.DBF"       VIA ( cDriver() ) SHARED INDEX "TIKEL.CDX"

      DATABASE NEW ::oProLin  PATH ( cPatEmp() ) FILE "PROLIN.DBF"      VIA ( cDriver() ) SHARED INDEX "PROLIN.CDX"

      DATABASE NEW ::oProMat  PATH ( cPatEmp() ) FILE "PROMAT.DBF"      VIA ( cDriver() ) SHARED INDEX "PROMAT.CDX"

      DATABASE NEW ::oHisMov  PATH ( cPatEmp() ) FILE "HISMOV.DBF"      VIA ( cDriver() ) SHARED INDEX "HISMOV.CDX"

      DATABASE NEW ::oPedPrvL PATH ( cPatEmp() ) FILE "PEDPROVL.DBF"    VIA ( cDriver() ) SHARED INDEX "PEDPROVL.CDX"

      DATABASE NEW ::oAlbPrvT PATH ( cPatEmp() ) FILE "ALBPROVT.DBF"    VIA ( cDriver() ) SHARED INDEX "ALBPROVT.CDX"

      DATABASE NEW ::oAlbPrvL PATH ( cPatEmp() ) FILE "ALBPROVL.DBF"    VIA ( cDriver() ) SHARED INDEX "ALBPROVL.CDX"

      DATABASE NEW ::oFacPrvL PATH ( cPatEmp() ) FILE "FACPRVL.DBF"     VIA ( cDriver() ) SHARED INDEX "FACPRVL.CDX"

      DATABASE NEW ::oRctPrvL PATH ( cPatEmp() ) FILE "RCTPRVL.DBF"     VIA ( cDriver() ) SHARED INDEX "RCTPRVL.CDX"

      DATABASE NEW ::oArtImg  PATH ( cPatArt() ) FILE "ARTIMG.DBF"      VIA ( cDriver() ) SHARED INDEX "ARTIMG.CDX"

      DATABASE NEW ::oPreCliT PATH ( cPatEmp() ) FILE "PRECLIT.DBF"     VIA ( cDriver() ) SHARED INDEX "PRECLIT.CDX"

      DATABASE NEW ::oPreCliL PATH ( cPatEmp() ) FILE "PRECLIL.DBF"     VIA ( cDriver() ) SHARED INDEX "PRECLIL.CDX"

      DATABASE NEW ::oPreCliI PATH ( cPatEmp() ) FILE "PRECLII.DBF"     VIA ( cDriver() ) SHARED INDEX "PRECLII.CDX"

      DATABASE NEW ::oPreCliE PATH ( cPatEmp() ) FILE "PRECLIE.DBF"     VIA ( cDriver() ) SHARED INDEX "PRECLIE.CDX"

      ::oStock                := TStock():Create( cPatGrp() )
      if !::oStock:lOpenFiles()
         lOpen                := .f.
      end if

   RECOVER USING oError

      lOpen                   := .f.

      msgStop( ErrorMessage( oError ), 'Imposible abrir las bases de datos de art�culos' )      
      
      ::filesClose()

   END SEQUENCE

   ErrorBlock( oBlock )

RETURN ( lOpen )

//---------------------------------------------------------------------------//

METHOD filesClose() CLASS TComercio

   if !empty( ::oArt ) .and. ::oArt:Used()
      ::oArt:End()
   end if

   if !empty( ::oPro ) .and. ::oPro:Used()
      ::oPro:End()
   end if

   if !empty( ::oTblPro ) .and. ::oTblPro:Used()
      ::oTblPro:End()
   end if

   if !empty( ::oFam ) .and. ::oFam:Used()
      ::oFam:End()
   end if

   if !empty( ::oGrpFam ) .and. ::oGrpFam:Used()
      ::oGrpFam:End()
   end if

   if !empty( ::oTipArt ) .and. ::oTipArt:Used()
      ::oTipArt:End()
   end if

   if !empty( ::oCli ) .and. ::oCli:Used()
      ::oCli:End()
   end if

   if !empty( ::oFPago ) .and. ::oFPago:Used()
      ::oFPago:End()
   end if

   if !empty( ::oObras ) .and. ::oObras:Used()
      ::oObras:End()
   end if

   if !empty( ::oArtDiv ) .and. ::oArtDiv:Used()
      ::oArtDiv:End()
   end if

   if !empty( ::oIva ) .and. ::oIva:Used()
      ::oIva:End()
   end if

   if !empty( ::oDivisas ) .and. ::oDivisas:Used()
      ::oDivisas:End()
   end if

   if !empty( ::oPedCliT ) .and. ::oPedCliT:Used()
      ::oPedCliT:End()
   end if

   if !empty( ::oPedCliI ) .and. ::oPedCliI:Used()
      ::oPedCliI:End()
   end if

   if !empty( ::oPedCliL ) .and. ::oPedCliL:Used()
      ::oPedCliL:End()
   end if

   if !empty( ::oCount ) .and. ::oCount:Used()
      ::oCount:End()
   end if

   if !empty( ::oFab ) .and. ::oFab:Used()
      ::oFab:End()
   end if

   if !empty( ::oKit ) .and. ::oKit:Used()
      ::oKit:End()
   end if

   if !empty( ::oAlbCliT ) .and. ::oAlbCliT:Used()
      ::oAlbCliT:End()
   end if

   if !empty( ::oAlbCliL ) .and. ::oAlbCliL:Used()
      ::oAlbCliL:End()
   end if

   if !empty( ::oFacCliL ) .and. ::oFacCliL:Used()
      ::oFacCliL:End()
   end if

   if !empty( ::oFacRecL ) .and. ::oFacRecL:Used()
      ::oFacRecL:End()
   end if

   if !empty( ::oTikCliL ) .and. ::oTikCliL:Used()
      ::oTikCliL:End()
   end if

   if !empty( ::oProLin ) .and. ::oProLin:Used()
      ::oProLin:End()
   end if

   if !empty( ::oProMat ) .and. ::oProMat:Used()
      ::oProMat:End()
   end if

   if !empty( ::oHisMov ) .and. ::oHisMov:Used()
      ::oHisMov:End()
   end if

   if !empty( ::oPedPrvL ) .and. ::oPedPrvL:Used()
      ::oPedPrvL:End()
   end if

   if !empty( ::oAlbPrvT ) .and. ::oAlbPrvT:Used()
      ::oAlbPrvT:End()
   end if

   if !empty( ::oAlbPrvL ) .and. ::oAlbPrvL:Used()
      ::oAlbPrvL:End()
   end if

   if !empty( ::oFacPrvL ) .and. ::oFacPrvL:Used()
      ::oFacPrvL:End()
   end if

   if !empty( ::oRctPrvL ) .and. ::oRctPrvL:Used()
      ::oRctPrvL:End()
   end if

   if !empty( ::oArtImg ) .and. ::oArtImg:Used()
      ::oArtImg:End()
   end if

   if !empty( ::oOferta ) .and. ::oOferta:Used()
      ::oOferta:End()
   end if

   ::oArt      := nil
   ::oPro      := nil
   ::oTblPro   := nil
   ::oFPago    := nil
   ::oFam      := nil
   ::oGrpFam   := nil
   ::oCli      := nil
   ::oObras    := nil
   ::oPedCliT  := nil
   ::oPedCliI  := nil
   ::oPedCliL  := nil
   ::oCount    := nil
   ::oFab      := nil
   ::oIva      := nil
   ::oDivisas  := nil
   ::oTipArt   := nil
   ::oKit      := nil
   ::oAlbCliT  := nil
   ::oAlbCliL  := nil
   ::oFacCliL  := nil
   ::oFacRecL  := nil
   ::oTikCliL  := nil
   ::oProLin   := nil
   ::oProMat   := nil
   ::oHisMov   := nil
   ::oPedPrvL  := nil
   ::oAlbPrvT  := nil
   ::oAlbPrvL  := nil
   ::oFacPrvL  := nil
   ::oRctPrvL  := nil
   ::oArtImg   := nil
   ::oOferta   := nil

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD dialogActivate( oWnd ) CLASS TComercio

   DEFAULT  oWnd        := oWnd()

   ::lSyncAll           := .t.
   ::nLevel             := nLevelUsr( "01108" )

   if nAnd( ::nLevel, 1 ) != 0
      msgStop( "Acceso no permitido." )
      return ( Self )
   end if

   if oWnd != nil
      SysRefresh(); oWnd:CloseAll(); SysRefresh()
   end if

   /*
   Apertura del fichero de texto---------------------------------------------//
   */

   DEFINE DIALOG ::oDlg RESOURCE "Comercio_0"

      REDEFINE BITMAP ::oBmp ;
         ID       500 ;
         RESOURCE "earth2_alpha_48" ;
         TRANSPARENT ;
         OF       ::oDlg

      // Servidor--------------------------------------------------------------

      REDEFINE SAY PROMPT ::TPrestashopConfig:getFullFileName() ;
         ID       140 ;
         OF       ::oDlg

      // Puerto----------------------------------------------------------------

      REDEFINE SAY PROMPT ::nPort; 
         ID       150 ;
         OF       ::oDlg

      // Usuario---------------------------------------------------------------

      REDEFINE SAY PROMPT ::cUser;
         ID       160 ;
         OF       ::oDlg

      // Base de datos---------------------------------------------------------

      REDEFINE SAY PROMPT ::cDbName;
         ID       170 ;
         OF       ::oDlg

      REDEFINE SAY PROMPT "Usuario" ;
         ID       180 ;
         OF       ::oDlg

      REDEFINE SAY PROMPT "Imagenes" ;
         ID       190 ;
         OF       ::oDlg

      /*
      Tree---------------------------------------------------------------------
      */   

      ::oTree           := TTreeView():Redefine( 200, ::oDlg )

      REDEFINE SAY ::oTextTotal PROMPT ::cTextTotal ID 210 OF ::oDlg

      ::oMeterTotal     := TApoloMeter():ReDefine( 220, { | u | if( pCount() == 0, ::nMeterTotal, ::nMeterTotal := u ) }, 10, ::oDlg, .f., , , .t., rgb( 255,255,255 ), , rgb( 128,255,0 ) )

      ::oMeterProceso   := TApoloMeter():ReDefine( 230, { | u | if( pCount() == 0, ::nMeterProceso, ::nMeterProceso := u ) }, 10, ::oDlg, .f., , , .t., rgb( 255,255,255 ), , rgb( 128,255,0 ) )

      /*
      Botones exportaci�n------------------------------------------------------
      */

      REDEFINE BUTTONBMP ::oBtnExportar ;
         ID       510 ;
         OF       ::oDlg;
         ACTION   ( ::buildExportarPrestashop() ); //ExportarPrestashop()

      REDEFINE BUTTONBMP ::oBtnImportar ;
         ID       520 ;
         OF       ::oDlg;
         ACTION   ( ::ImportarPrestashop() );

      REDEFINE BUTTONBMP ::oBtnStock ;
         ID       530 ;
         OF       ::oDlg;
         ACTION   ( ::buildActualizaStock() );

      REDEFINE BUTTON ::oBtnCancel ;
         ID       IDCANCEL ;
         OF       ::oDlg ;
         ACTION   ( ::oDlg:end() )

      ::oDlg:AddFastKey( VK_F5, {|| ::buildExportarPrestashop() } )

      ::oDlg:bStart := {|| ::dialogStart() }

   ACTIVATE DIALOG ::oDlg CENTER

   /*
   Liberamos la imagen---------------------------------------------------------
   */

   ::oBmp:End()

Return Nil

//------------------------------------------------------------------------//

METHOD dialogStart() CLASS TComercio

   if ::TPrestashopConfig:getHideExportButton()
      ::oBtnExportar:Hide()
   else
      ::oBtnExportar:Show()
   end if

Return nil

//---------------------------------------------------------------------------//

METHOD treeSetText( cText, nLevel ) CLASS TComercio

   if empty( ::cFilTxt )
      ::cFilTxt      := cGetNewFileName( cPatLog() + "Com" + Dtos( Date() ) + StrTran( Time(), ":", "" ) ) + ".Txt"
      ::hFilTxt      := fCreate( ::cFilTxt )
   end if

   if empty( ::hFilTxt )
      ::hFilTxt      := fOpen( ::cFilTxt, 1 )
   endif

   // Escritura en el fichero

   fWrite( ::hFilTxt, cValToChar( cText ) + CRLF )

   // Pintamos en el tree

   if !empty( ::oTree )
      ::oTree:Select( ::oTree:Add( cText ) )
   end if 

   // Texto para dialogo 

   ::cTextoWait( cText )

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD MeterTotalText( cText ) Class TComercio

   DEFAULT cText  := ""

   ::writeText( cText )

   if !empty( ::oMeterTotal )
      ::oMeterTotal:Set( ++::nMeterTotal )
   end if

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD MeterTotalSetTotal( nTotal ) Class TComercio

   if !empty( ::oMeterTotal )
      ::oMeterTotal:SetTotal( nTotal )
   end if

   ::nMeterTotal := 1

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD meterProcesoText( cText ) Class TComercio

   DEFAULT cText  := ""

   ::writeText( cText )

   if !empty( ::oMeterProceso )
      ::oMeterProceso:Set( ++::nMeterProceso )
   end if

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD meterProcesoSetTotal( nTotal ) Class TComercio

   if !empty( ::oMeterProceso )
      ::oMeterProceso:SetTotal( nTotal )
   end if

   ::nMeterProceso   := 1

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD ExportarPrestashop() Class TComercio

Return .t.

//---------------------------------------------------------------------------//

METHOD ImportarPrestashop() CLASS TComercio

   local oDb
   local oBlock
   local oError

   ::oBtnExportar:Hide()
   ::oBtnImportar:Hide()
   ::oBtnStock:Hide()

   ::oBtnCancel:Disable()

   oBlock            := ErrorBlock( { | oError | Break( oError ) } )
   BEGIN SEQUENCE

   if ::filesOpen()

      ::treeSetText( 'Intentando conectar con el servidor ' + '"' + ::cHost + '"' + ', el usuario ' + '"' + ::cUser + '"' + ' y la base de datos ' + '"' + ::cDbName + '".' , 1 )

      ::oCon            := TMSConnect():New()

      if !::oCon:Connect( ::cHost, ::cUser, ::cPasswd, ::cDbName, ::nPort )

          ::treeSetText( 'No se ha podido conectar con la base de datos.' )

      else

           ::treeSetText( 'Se ha conectado con �xito a la base de datos.' , 1 )

          oDb := TMSDataBase():New ( ::oCon, ::cDbName )

          if empty( oDb )

             ::treeSetText( 'La Base de datos: ' + ::cDbName + ' no esta activa.', 1 )

          else

            /*
            Nos traemos los clientes y pedidos hacia nuestras bases de datos y actualizamos el estado de los pedidos de arriba
            */

            ::MeterTotalText( "Descargando clientes" )
            ::AppendClientPrestashop()
            sysRefresh()

            ::MeterTotalText( "Descargando pedidos" )
            ::controllerOrders()
            sysRefresh()

            ::MeterTotalText( "Actualizando estado de los pedidos" )
            ::EstadoPedidosPrestashop()
            sysRefresh()

          end if

      end if

      ::oCon:Destroy()

      ::treeSetText( 'Base de datos desconectada.', 1 )

      ::MeterTotalText( "Proceso finalizado" )

      /*
      Para que al final del proceso quede totalmente llena la barra del meter--
      */

      ::oMeterTotal:Set( 100 )
      ::oMeterProceso:Set( 100 )

   else

      ::treeSetText( 'Error al abrir los ficheros necesarios.', 1 )

   end if

   RECOVER USING oError

      msgStop( ErrorMessage( oError ), "Error al conectarnos con la base de datos" )

   END SEQUENCE

   ErrorBlock( oBlock )

   ::filesClose()

   ::oBtnExportar:Hide()
   ::oBtnImportar:Hide()

   ::oBtnCancel:Enable()

Return .t.

//---------------------------------------------------------------------------//

METHOD AppendIvaPrestashop() Class TComercio

   /*
   Vaciamos las tablas para el proceso global----------------------------------
   */

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPreFixtable( "tax" ) )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "tax" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "tax" ), 3  )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPreFixtable( "tax_lang" ) )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "tax_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "tax_lang" ), 3  )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPreFixtable( "tax_rule" ) )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "tax_rule" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "tax_rule" ), 3  )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPreFixtable( "tax_rules_group" ) )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "tax_rules_group" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "tax_rules_group" ), 3  )
   end if

   /*
   Inicializamos el c�digo para la web en el programa--------------------------
   */

   ::DelIdIvaPrestashop()

   /*
   A�adimos tipos de IVA a prestashop------------------------------------------
   */

   ::oIva:GoTop()

   while !::oIva:Eof()

      if ::oIva:lPubInt

         ::meterProcesoText( "Actualizando tipos de " + cImp() )

         ::InsertIvaPrestashop()

      end if

      ::oIva:FieldPutByName( "lSndDoc", .f. )

      ::oIva:Skip()

   end while

return ( Self )


//---------------------------------------------------------------------------//

METHOD InsertIvaPrestashop() CLASS TComercio

   local cCommand          := ""  
   local nCodigoWeb        := 0
   local nCodigoGrupoWeb   := 0

   cCommand := "INSERT INTO " + ::cPreFixtable( "tax") + ;
                  "( rate, " + ;
                  "active ) " + ;
               "VALUES " + ;
                  "('" + alltrim( str( ::oIva:TpIva ) ) + "', " + ;  // rate
                  "'1' )"                                            // active

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      nCodigoWeb           := ::oCon:GetInsertId()

      ::oIva:fieldPutByName( "cCodWeb", nCodigoWeb )

      ::treeSetText( "He insertado el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " correctamente en la tabla " + ::cPreFixtable( "tax" ), 3 )

   else
      ::treeSetText( "Error al insertar el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla " + ::cPreFixtable( "tax" ), 3 )
   end if

   /*
   Insertamos un tipo de IVA nuevo en la tabla tax_lang-----------------
   */

   cCommand := "INSERT INTO " + ::cPrefixTable( "tax_lang" ) + "( " +;
                  "id_tax, " + ;
                  "id_lang, " + ;
                  "name )" + ;
               " VALUES " + ;
                  "('" + str( nCodigoWeb ) + "', " + ;         // id_tax
                  "'" + str( ::nLanguage ) + "', " + ;         // id_lang
                  "'" + ::oCon:Escapestr( ::oIva:DescIva ) + "' )"      // name

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      ::treeSetText( "He insertado el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " correctamente en la tabla" + ::cPrefixTable( "tax_lang" ), 3 )

   else

      ::treeSetText( "Error al insertar el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla" + ::cPrefixTable( "tax_lang" ), 3 )

   end if

   /*
   Insertamos un tipo de IVA nuevo en la tabla tax_rule_group-----------------
   */

   cCommand := "INSERT INTO "+ ::cPrefixTable( "tax_rules_group" ) + "( " + ;
                  "name, " + ;
                  "active )" + ;
               " VALUES " + ;
                  "('" + ::oCon:Escapestr( ::oIva:DescIva ) + "', " + ; // name
                  "'1' )"                                      // active

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      nCodigoGrupoWeb           := ::oCon:GetInsertId()

      ::oIva:fieldPutByName( "cGrpWeb", nCodigoGrupoWeb )

      ::treeSetText( "He insertado el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " correctamente en la tabla " + ::cPreFixtable( "tax_rule_group" ), 3 )

   else

      ::treeSetText( "Error al insertar el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla " + ::cPreFixTable( "tax_rule_group" ), 3 )

   end if

   /*
   Insertamos un tipo de IVA nuevo en la tabla tax_rule-----------------
   */

   cCommand := "INSERT INTO " + ::cPrefixTable( "tax_rule" ) + "( " +;
                  "id_tax_rules_group, " + ;
                  "id_country, " + ;
                  "id_tax )" + ;
               " VALUES " + ;
                  "('" + str( nCodigoGrupoWeb ) + "', " + ;  // id_tax_rules_group
                  "'6', " + ;                                // id_country - 6 es el valor de Espa�a
                  "'" + str( nCodigoWeb ) + "' )"            // id_tax

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      ::treeSetText( "He insertado el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " correctamente en la tabla " + ::cPrefixTable( "tax_rule" ), 3 )

   else

      ::treeSetText( "Error al insertar el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla " + ::cPrefixTable( "tax_rule" ), 3 )

   end if

return nCodigoweb

//---------------------------------------------------------------------------//

METHOD lUpdateIvaPrestashop( nId ) CLASS TComercio

   local lReturn  := .f.

   /*
   Actualizamos los tipos de IVA ----------------------------------------
   */

   if TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "tax" ) + " SET rate='" + alltrim( str( ::oIva:TpIva ) ) + "' WHERE id_tax=" + alltrim( str( nId ) ) )
      ::treeSetText( "Actualizada correctamente el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla tax", 3 )
      lReturn     := .t.
   else
      ::treeSetText( "Error al actualizar el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla tax", 3 )
      lReturn     := .f.
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "tax_lang" ) + " SET name='" + alltrim( ::oIva:DescIva ) + "' WHERE id_tax=" + alltrim( str( nId ) ) )
      ::treeSetText( "Actualizada correctamente el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla tax_lang", 3 )
      lReturn     := .t.
   else
      ::treeSetText( "Error al actualizar el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla tax_lang", 3 )
      lReturn     := .f.
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "tax_rules_group" ) + " SET name='" + alltrim( ::oIva:DescIva ) + "' WHERE id_tax_rules_group=" + alltrim( str( nId ) ) )
      ::treeSetText( "Actualizada correctamente el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla tax_rules_group", 3 )
      lReturn     := .t.
   else
      ::treeSetText( "Error al actualizar el tipo de " + cImp() + Space(1) + alltrim( ::oIva:DescIva ) + " en la tabla tax_rules_group", 3 )
      lReturn     := .f.
   end if

Return lReturn

//---------------------------------------------------------------------------//

METHOD DelIdIvaPrestashop() Class TComercio

   local nRec  := ::oIva:Recno()

   ::oIva:GoTop()

   while !::oIva:Eof()

      ::oIva:Load()
      ::oIva:cCodWeb := 0
      ::oIva:cGrpWeb := 0
      ::oIva:Save()

      ::treeSetText( 'Eliminando c�digo web en el tipo de I.V.A. ' + alltrim( ::oIva:DescIva ), 3  )

      ::oIva:Skip()

   end while

   ::oIva:GoTo( nRec )

RETURN ( .t. )

//---------------------------------------------------------------------------//

METHOD AppendFabricantesPrestashop CLASS TComercio

   local n

   /*
   Vaciamos las tablas para el proceso global-------------------------
   */

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPrefixTable( "manufacturer" ) )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "manufacturer" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "manufacturer" ), 3  )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPrefixTable( "manufacturer_shop" ) )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "manufacturer_shop" ) + ' borrada correctamente', 3 )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "manufacturer_shop" ), 3 )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPrefixTable( "manufacturer_lang" ) )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "manufacturer_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "manufacturer_lang" ), 3  )
   end if

   /*
   Ponemos los id de fabricantes para la web-----------------------------------
   */

   ::DelIdFabricantePrestashop()

   /*
   A�adimos familias a prestashop----------------------------------------------
   */

   ::oFab:GoTop()

   while !::oFab:Eof()

      if ::oFab:lPubInt

         ::meterProcesoText( "Actualizando fabricantes" )

         /*
         Metemos las familias como categor�as----------------------------------
         */

         ::InsertFabricantesPrestashop()

      end if

      ::oFab:FieldPutByName( "lSndDoc", .f. )

      ::oFab:Skip()

   end while

Return ( self )

//---------------------------------------------------------------------------//

METHOD InsertFabricantesPrestashop() CLASS TComercio

   local oImagen
   local cCommand    := ""    
   local nCodigoWeb  := 0
   local nParent     := 1

   /*
   Insertamos una familia nueva en las tablas de prestashop-----------------
   */

   cCommand := "INSERT INTO " + ::cPrefixTable( "manufacturer" ) + "( " +;
                  "name, " + ;
                  "date_add, " + ;
                  "date_upd, " + ;
                  "active )" + ;
               " VALUES " + ;
                  "('" + ::oCon:Escapestr( ::oFab:cNomFab ) + "', " + ;       //name
                  "'" + dtos( GetSysDate() ) + "', " + ;             //date_add
                  "'" + dtos( GetSysDate() ) + "', " + ;             //date_upd
                  "'1' )"                                            //active

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      nCodigoWeb           := ::oCon:GetInsertId()

      ::oFab:fieldPutByName( "cCodWeb", nCodigoWeb )

      ::treeSetText( "He insertado el fabricante " + alltrim( ::oFab:cNomFab ) + " correctamente en la tabla " + ::cPrefixTable( "manufacturer" ), 3 )

   else
      ::treeSetText( "Error al insertar el fabricante " + alltrim( ::oFab:cNomFab ) + " en la tabla " + ::cPreFixtable( "manufacturer" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "manufacturer_shop" ) + "( "+ ;
                  "id_manufacturer, " + ;
                  "id_shop ) " + ;
               "VALUES " + ;
                  "('" + alltrim( str( nCodigoWeb ) ) + "', " + ;     // id_manufacturer
                  "'1' )"                                             // id_shop                  


   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado el fabricante " + alltrim( ::oFab:cNomFab ) + " correctamente en la tabla" + ::cPreFixtable( "manufacturer_shop" ), 3 )
   else
      ::treeSetText( "Error al insertar el fabricante " + alltrim( ::oFab:cNomFab ) + " en la tabla" + ::cPreFixtable( "manufacturer_shop" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPreFixtable( "manufacturer_lang" ) + "( " +;
                  "id_manufacturer, " + ;
                  "id_lang ) " + ;
               "VALUES " + ;
                  "('" + alltrim( str( nCodigoWeb ) ) + "', " + ;    //id_manufacturer
                  "'" + str( ::nLanguage ) + "' )"                   //id_lang

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      ::treeSetText( "He insertado el fabricante " + alltrim( ::oFab:cNomFab ) + " correctamente en la tabla" + ::cPreFixtable( "manufacturer_lang" ), 3 )

   else
      ::treeSetText( "Error al insertar el fabricante " + alltrim( ::oFab:cNomFab ) + " en la tabla" + ::cPreFixtable( "manufacturer_lang" ), 3 )
   end if

return nCodigoWeb

//---------------------------------------------------------------------------//

METHOD lUpdateFabricantesPrestashop( nId ) Class TComercio

   local lReturn  := .f.

   if TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "manufacturer" ) + " SET name='" + alltrim( ::oFab:cNomFab ) + "', date_upd='" + dtos( GetSysDate() ) + "' WHERE id_manufacturer=" + alltrim( str( ::oFab:cCodWeb ) ) )
      ::treeSetText( "Actualizada correctamente el fabricante " + alltrim( ::oFab:cNomFab ) + " en la tabla manufacturer", 3 )
      lReturn     := .t.
   else
     ::treeSetText( "Error al actualizar el fabricante " + alltrim( ::oFab:cNomFab ) + " en la tabla manufacturer", 3 )
     lReturn     := .f.
   end if

Return lReturn   

//---------------------------------------------------------------------------//

METHOD DelIdFabricantePrestashop() Class TComercio

   local nRec  := ::oFab:Recno()

   ::oFab:GoTop()

   while !::oFab:Eof()

      ::oFab:Load()
      ::oFab:cCodWeb := 0
      ::oFab:Save()

      ::treeSetText( 'Eliminando c�digo web en el fabricante ' + alltrim( ::oFab:cNomFab ), 3  )

      ::oFab:Skip()

   end while

   ::oFab:GoTo( nRec )

RETURN ( .t. )

//---------------------------------------------------------------------------//

METHOD AppendFamiliaPrestashop( oDb ) CLASS TComercio

   local n
   local cCommand := ""

   /*
   Vaciamos las tablas para el proceso global-------------------------
   */

   cCommand       := "TRUNCATE TABLE " + ::cPrefixtable( "category" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "category" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "category" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "category_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "category_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "category_lang" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "category_product" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "category_product" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "category_product" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "category_group" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "category_group" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "category_group" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "category_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "category_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla '+ ::cPrefixTable( "category_group" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "image" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "image" ) + 'borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla' + ::cPrefixTable( "image" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "image_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "image_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla '+ ::cPrefixTable( "image_shop" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "image_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "image_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "image_lang" ), 3  )
   end if

   /*
   Borramos los IdWeb de todas las familias---------------------------------
   */

   ::DelIdFamiliasPrestashop()

   /*
   Cargamos la categor�a raiz de la que colgar�n todas las dem�s------------
   */

   ::AddCategoriaRaiz()

   /*
   A�adimos familias a prestashop----------------------------------------------
   */

   ::oFam:GoTop()

   while !::oFam:Eof()

      if ::oFam:lPubInt
         ::meterProcesoText( "Actualizando familias" )
         ::InsertCategoriesPrestashop()
      end if

      ::oFam:FieldPutByName( "lSelDoc", .f. )

      ::oFam:Skip()

   end while

   /*
   Damos una segunda pasada para ponerle los id de los padres------------------
   */

   ::oFam:GoTop()

   while !::oFam:Eof()

      if ::oFam:lPubInt .and. !empty( ::oFam:cFamCmb )

         ::meterProcesoText( "Actualizando familias" )

         ::ActualizaCaterogiaPadrePrestashop()

      end if

      ::oFam:FieldPutByName( "lSelDoc", .f. )

      ::oFam:Skip()

   end while

Return ( Self )

//---------------------------------------------------------------------------//

METHOD ActualizaCaterogiaPadrePrestashop() CLASS TComercio

   local lReturn  := .f.
   local cCommand := ""
   local nParent  := 2

   /*
   Actualizamos las familias padre en prestashop-------------------------------
   */

   ::cTextoWait( "Actualizando categor�a: " + ::oFam:cNomFam )

   nParent        := oRetFld( ::oFam:cFamCmb, ::oFam, "cCodWeb" )
      
   if nParent == 0
      nParent     := 2
   end if

   cCommand       := "UPDATE " + ::cPrefixTable( "category" ) + " SET " + ;
                        "id_parent='" + alltrim( str( nParent ) ) + "' " +;
                        "WHERE id_category = " + alltrim( str( ::oFam:cCodWeb ) )

   lReturn        := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   SysRefresh()

Return lReturn

//---------------------------------------------------------------------------//

METHOD DelIdFamiliasPrestashop() Class TComercio

   local nRec  := ::oFam:Recno()

   ::oFam:GoTop()

   while !::oFam:Eof()

      ::oFam:Load()
      ::oFam:cCodWeb := 0
      ::oFam:Save()

      ::treeSetText( 'Eliminando c�digo web en la familia ' + alltrim( ::oFam:cNomFam ), 3  )

      ::oFam:Skip()

   end while

   ::oFam:GoTo( nRec )

RETURN ( .t. )

//---------------------------------------------------------------------------//

METHOD AddCategoriaRaiz() CLASS TComercio

   local cCommand := ""

   /*
   Insertamos el root en la tabla de categorias------------------------------
   */

   ::cTextoWait( "A�adiendo categor�a raiz" )

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category" ) + " ( id_category, id_parent, id_shop_default, level_depth, nleft, nright, active, date_add, date_upd, position ) VALUES ( '1', '0', '1', '0', '0', '0', '1', '" + dtos( GetSysDate() ) + "', '" + dtos( GetSysDate() ) + "', '0' ) "

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::nNumeroCategorias++
      ::treeSetText( "He insertado correctamente en la tabla categor�as la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + " ( id_category, id_lang, name, description, link_rewrite, meta_title, meta_keywords, meta_description ) VALUES ( '1', '" + str( ::nLanguage ) + "', 'Root', 'Root', 'Root', '', '', '' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias lenguajes la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + " ( id_category, id_shop, position ) VALUES ( '1', '1', '0' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '1', '1' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '1', '2' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '1', '3' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a root en category_group", 3 )
   end if

   /*
   Metemos la categor�a de inicio de la que colgar�n los grupos y las categorias
   */

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category" ) + " ( id_parent, id_shop_default, level_depth, nleft, nright, active, date_add, date_upd, position, is_root_category ) VALUES ( '1', '1', '1', '0', '0', '1', '" + dtos( GetSysDate() ) + "', '" + dtos( GetSysDate() ) + "', '0', '1' ) "

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::nNumeroCategorias++
      ::treeSetText( "He insertado correctamente en la tabla categorias la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + " ( id_category, id_lang, name, description, link_rewrite, meta_title, meta_keywords, meta_description ) VALUES ( '2', '" + str( ::nLanguage ) + "', 'Inicio', 'Inicio', 'Inicio', '', '', '' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias lenguajes la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + " ( id_category, id_shop, position ) VALUES ( '2', '1', '0' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '2', '1' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '2', '2' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '2', '3' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a inicio", 3 )
   end if

   SysRefresh()

Return ( Self )

//---------------------------------------------------------------------------//

METHOD InsertCategoriesPrestashop() CLASS TComercio

   local oImagen
   local oCategoria
   local nCodigoWeb           := 0
   local nParent              := getCodigoWebFamiliaPadre( ::oFam )
   local cCommand             := ""

   ::cTextoWait( "A�adiendo categor�a: " + alltrim( ::oFam:cNomFam ) )

   /*
   Insertamos una familia nueva en las tablas de prestashop-----------------
   */

   cCommand := "INSERT INTO " + ::cPrefixTable( "category" ) + "( " + ;
                  "id_parent, " + ;
                  "level_depth, " + ;
                  "nleft, " + ;
                  "nright, " + ;
                  "active, " + ;
                  "date_add,  " + ;
                  "date_upd, " + ;
                  "position " + ;
               ") VALUES ( '" + ;
                  str( nParent ) + "', " + ;
                  "'2', " + ;
                  "'0', " + ;
                  "'0', " + ;
                  "'1', " + ;
                  "'" + dtos( GetSysDate() ) + "', " + ;
                  "'" + dtos( GetSysDate() ) + "', " + ;
                  "'0' ) "

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      nCodigoWeb           := ::oCon:GetInsertId()

      ::nNumeroCategorias++

      /*
      Metemos en un array para luego calcular las coordenadas---------------
      */

      oCategoria                       := SCategoria()
      oCategoria:id                    := nCodigoWeb
      oCategoria:idParent              := nParent
      oCategoria:nTipo                 := 2

      aAdd( ::aCategorias, oCategoria )

      /*
      Guardamos en nuestra tabla lasel id de la categoria-------------------
      */

      ::oFam:fieldPutByName( "cCodWeb", nCodigoWeb )

      ::treeSetText( "He insertado la familia " + alltrim( ::oFam:cNomFam ) + " correctamente en la tabla " + ::cPrefixTable( "category" ), 3 )

   else
      ::treeSetText( "Error al insertar la familia " + alltrim( ::oFam:cNomFam ) + " en la tabla " + ::cPrefixTable( "category" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + "( " + ;
                  "id_category, " + ;
                  "id_lang, " + ;
                  "name, " + ;
                  "description, " + ;
                  "link_rewrite, " + ;
                  "meta_title, " + ;
                  "meta_keywords, " + ;
                  "meta_description" + ;
                  " ) VALUES ( '" + ;
                  str( nCodigoWeb ) + "', '" +;
                  str( ::nLanguage ) + "', '" + ;
                  if( empty( ::oFam:cDesWeb ), alltrim( ::oFam:cNomFam ), alltrim( ::oFam:cDesWeb ) ) + "', '" + ;
                  if( empty( ::oFam:cDesWeb ), alltrim( ::oFam:cNomFam ), alltrim( ::oFam:cDesWeb ) ) + "', '" + ;
                  cLinkRewrite( if( empty( ::oFam:cDesWeb ), alltrim( ::oFam:cNomFam ), alltrim( ::oFam:cDesWeb ) ) ) + "', " + ;
                  "'', " + ;
                  "'', " + ;
                  "'' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado la familia " + alltrim( ::oFam:cNomFam ) + " correctamente en la tabla " + ::cPrefixTable( "category_lang" ), 3 )
   else
      ::treeSetText( "Error al insertar la familia " + alltrim( ::oFam:cNomFam ) + " en la tabla " + ::cPrefixTable( "category_lang" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + "( id_category, id_shop, position ) VALUES ( '" + str( nCodigoWeb ) + "', '1', '0' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::treeSetText( "Error al insertar la categor�a inicio en " + ::cPrefixTable( "category_group" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( id_category, id_group ) VALUES ( '" + str( nCodigoWeb ) + "', '1' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado la familia " + alltrim( ::oFam:cNomFam ) + " correctamente en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   else
      ::treeSetText( "Error al insertar la familia " + alltrim( ::oFam:cNomFam ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( id_category, id_group ) VALUES ( '" + str( nCodigoWeb ) + "', '2' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado la familia " + alltrim( ::oFam:cNomFam ) + " correctamente en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   else
      ::treeSetText( "Error al insertar la familia " + alltrim( ::oFam:cNomFam ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( id_category, id_group ) VALUES ( '" + str( nCodigoWeb ) + "', '3' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado la familia " + alltrim( ::oFam:cNomFam ) + " correctamente en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   else
      ::treeSetText( "Error al insertar la familia " + alltrim( ::oFam:cNomFam ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

   SysRefresh()

   /*
   Insertamos un registro en las tablas de im�genes----------------------
   */

   if !empty( ::oFam:cImgBtn ) .and. file( ::oFam:cImgBtn )

      /*
      A�adimos la imagen al array para pasarla a prestashop--------------
      */

      oImagen                       := SImagen()
      oImagen:cNombreImagen         := alltrim( ::oFam:cImgBtn )
      oImagen:nTipoImagen           := tipoCategoria
      oImagen:cPrefijoNombre        := alltrim( str( nCodigoWeb ) )

      ::AddImages( oImagen )

   end if

return nCodigoWeb

//---------------------------------------------------------------------------//

METHOD UpdateCategoriesPrestashop() CLASS TComercio

   local lReturn  := .f.
   local cCommand := ""
   local nParent  := getCodigoWebFamiliaPadre( ::oFam )

   ::cTextoWait( "Actualizando categor�a: " + alltrim( ::oFam:cNomFam ) )

   cCommand       := "UPDATE " + ::cPrefixTable( "category" ) + " SET " + ;
                        "id_parent='" + alltrim( str( nParent ) ) + "', " + ;
                        "date_upd='" + dtos( GetSysDate() ) + "' " + ;
                     "WHERE id_category=" + alltrim( str( ::oFam:cCodWeb ) )

   ::cTextoWait( cCommand )

   lReturn        := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::ActualizaCaterogiaPadrePrestashop()

   cCommand       := "UPDATE " + ::cPrefixTable( "category_lang" ) + " SET " + ;
                        "name='" + if( empty( ::oFam:cDesWeb ), alltrim( ::oFam:cNomFam ), alltrim( ::oFam:cDesWeb ) ) + "', " + ;
                        "description='" + if( empty( ::oFam:cDesWeb ), alltrim( ::oFam:cNomFam ), alltrim( ::oFam:cDesWeb ) ) + "', " + ;
                        "link_rewrite='" + cLinkRewrite( if( empty( ::oFam:cDesWeb ), alltrim( ::oFam:cNomFam ), alltrim( ::oFam:cDesWeb ) ) ) + "' " + ;
                     "WHERE id_category=" + alltrim( str( ::oFam:cCodWeb ) )

   lReturn        := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   SysRefresh()

Return lReturn

//---------------------------------------------------------------------------//

METHOD DeleteCategoriesPrestashop() CLASS TComercio

   local lReturn     := .f.
   local cCommand    := ""

   ::cTextoWait( "Eliminando categor�a: " + ::oFam:cNomFam )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "category" ) + " WHERE id_category=" + alltrim( str( ::oFam:cCodWeb ) )
   lReturn           := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "category_lang" ) + " WHERE id_category=" + alltrim( str( ::oFam:cCodWeb ) )
   lReturn           := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "category_product" ) + " WHERE id_category=" + alltrim( str( ::oFam:cCodWeb ) )
   lReturn           := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "category_group" ) + " WHERE id_category=" + alltrim( str( ::oFam:cCodWeb ) )
   lReturn           := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "category_shop" ) + " WHERE id_category=" + alltrim( str( ::oFam:cCodWeb ) )
   lReturn           := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   SysRefresh()

   /*
   Eliminamos las im�genes de la familia---------------------------------------
   */

   ::cTextoWait( "Eliminando im�genes categor�a: " + ::oFam:cNomFam )

   ::DeleteImagesCategories( ::oFam:cCodWeb )

   SysRefresh()

   /*
   Eliminamos en cascada Todo lo que est� tirando de la familia----------------
   */

   ::DelCascadeCategoriesPrestashop()

   /*
   Quitamos la referencia de nuestra tabla-------------------------------------
   */

   ::oFam:fieldPutByName( "cCodWeb", 0 )

Return lReturn

//---------------------------------------------------------------------------//

METHOD DelCascadeCategoriesPrestashop() CLASS TComercio

   local nRec     := ::oArt:Recno()
   local nOrdAnt  := ::oArt:OrdSetFocus( "FAMILIA" )

   if ::oArt:Seek( ::oFam:cCodFam )

      while ::oArt:Familia == ::oFam:cCodfam .and. !::oArt:Eof()

         if ::oArt:lPubInt .and. ::oArt:cCodWeb != 0

            ::DeleteProductsPrestashop()

         end if

         SysRefresh()

         ::oArt:Skip()

      end while

   end if

   /*
   Antes de irnos dejamos la tabla donde estaba--------------------------------
   */

   ::oArt:OrdSetFocus( nOrdAnt )
   ::oArt:GoTo( nRec )

return .t.

//---------------------------------------------------------------------------//

METHOD ActualizaCategoriesPrestashop( cCodigoFamilia ) CLASS TComercio

   local oQuery
   local cCommand

   if !::lReady()
      Return .f.
   end if
   
   if !::filesOpen()
      Return .f.
   end if 

   if ::oFam:Seek( cCodigoFamilia )

      if ::ConectBBDD()

         do case
            case !::oFam:lPubInt .and. ::oFam:cCodWeb != 0
   
               ::cTextoWait( "Elimina categor�a: " + ::oFam:cNomFam )

               ::DeleteCategoriesPrestashop()
   
            case ::oFam:lPubInt .and. ::oFam:cCodWeb != 0

               cCommand := 'SELECT * FROM ' + ::cPrefixTable( "category" ) + ' WHERE id_category=' + alltrim( str( ::oFam:cCodWeb ) )

               ::cTextoWait( cCommand )
   
               oQuery   := TMSQuery():New( ::oCon, cCommand )
   
               if oQuery:Open()
   
                  if oQuery:RecCount() > 0
   
                     ::cTextoWait( "Actualizando categor�a: " + ::oFam:cNomFam )

                     ::UpdateCategoriesPrestashop()
   
                  else
   
                     ::cTextoWait( "A�adiendo categor�a: " + ::oFam:cNomFam )

                     ::InsertCategoriesPrestashop()
   
                  end if
   
               end if
   
               oQuery:Free()
   
            case ::oFam:lPubInt .and. ::oFam:cCodWeb == 0
   
               ::cTextoWait( "A�adiendo categor�a: " + ::oFam:cNomFam )

               ::InsertCategoriesPrestashop()
   
         end case   

         ::DisconectBBDD()

      endif      

   end if

   ::filesClose()

Return .t.

//---------------------------------------------------------------------------//

METHOD DeleteImagesCategories( cCodCategorie ) CLASS TComercio

   local oInt
   local aDirectory
   local cDirectory
   local lerror

   if !empty( cCodCategorie )

      /*
      Conectamos al FTP para eliminar las imagenes de las categor�as-----------
      */

      if ::oFtp:CreateConexion()

         MsgStop( "Imposible conectar al sitio ftp " + ::TPrestashopConfig:getFtpServer() )

      else

         if !empty( ::TPrestashopConfig:getImagesDirectory() )
            ::oFtp:SetCurrentDirectory( ::cDirectoryCategories() )
         end if

         ::oFtp:DeleteMask( alltrim( str( cCodCategorie ) ) + "*.*" )

      end if

      ::oFtp:EndConexion()

   end if

Return .t.

//---------------------------------------------------------------------------//

METHOD RecalculaPosicionesCategoriasPrestashop() CLASS TComercio

   local nContador      := 3
   local aTemporal      := ::aCategorias
   local oCategoria
   local nPos           := 0
   local oCat
   local oCat2

   /*
   Pongo posiciones en la categor�a raiz e inicio
   */

   if TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "category" ) + " SET nLeft='1', nRight='" + alltrim( str( ::nNumeroCategorias * 2 ) ) + "' WHERE id_category=1" )
      ::treeSetText( "Actualizada correctamente el grupo de familia en la tabla category", 3 )
   else
      ::treeSetText( "Error al actualizar el grupo de familia en la tabla category", 3 )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "category" ) + " SET nLeft='2', nRight='" + alltrim( str( ( ::nNumeroCategorias * 2 ) -1 ) ) + "' WHERE id_category=2" )
      ::treeSetText( "Actualizada correctamente el grupo de familia en la tabla category", 3 )
   else
      ::treeSetText( "Error al actualizar el grupo de familia en la tabla category", 3 )
   end if

   /*
   Calculo las posiciones en un array temporal---------------------------------
   */

   for each oCategoria in aTemporal

      do case
         case oCategoria:nTipo == 1    //Grupos

            nPos := aScan( ::aCategorias, {|a| a:id == oCategoria:id } )

            if nPos != 0
               ::aCategorias[ nPos ]:nLeft   := nContador
               nContador++
            end if

            for each oCat in ::aCategorias

               if oCat:idParent == oCategoria:id

                  oCat:nLeft   := nContador
                  nContador++

                  for each oCat2 in ::aCategorias

                     if oCat2:idParent == oCat:id
                        oCat2:nLeft   := nContador
                        nContador++
                        oCat2:nRight  := nContador
                        nContador++
                     end if

                  next

                  oCat:nRight  := nContador
                  nContador++

               end if

            next

            nPos := aScan( ::aCategorias, {|a| a:id == oCategoria:id } )

            if nPos != 0
               ::aCategorias[ nPos ]:nRight   := nContador
               nContador++
            end if

         case oCategoria:nTipo == 2    //Familias

            if oCategoria:idParent == 2

                  nPos := aScan( ::aCategorias, {|a| a:id == oCategoria:id } )

                  if nPos != 0
                     ::aCategorias[ nPos ]:nLeft   := nContador
                     nContador++
                     ::aCategorias[ nPos ]:nRight  := nContador
                     nContador++
                  end if

            end if

      end case

   next

   /*
   Actualizo las posiciones en la tabla de la web en mysql---------------------
   */

   for each oCategoria in ::aCategorias

      if TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "category" ) + " SET nLeft='" + alltrim( str( oCategoria:nLeft ) ) + "', nRight='" + alltrim( str( ( oCategoria:nRight ) ) + "' WHERE id_category=" + alltrim( str( oCategoria:id ) ) ) )
         ::treeSetText( "Actualizada correctamente el grupo de familia en la tabla category", 3 )
      else
         ::treeSetText( "Error al actualizar el grupo de familia en la tabla category", 3 )
      end if

   next

return ( .t. )

//---------------------------------------------------------------------------//

METHOD AppendPropiedadesPrestashop CLASS TComercio

   local n
   local cCommand := ""

   /*
   Vaciamos las tablas para el proceso global-------------------------
   */

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_lang" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_shop" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_impact" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_impact" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_impact" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_group" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_group" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_group" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_group_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_group_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_group_lang" ), 3  )
   end if

   /*
   A�adimos Propiedades de art�culos a prestashop------------------------------
   */

   ::oPro:GoTop()

   while !::oPro:Eof()

      if ::oPro:lPubInt

         ::meterProcesoText( "Actualizando propiedades de art�culos" )

         ::InsertPropiedadesPrestashop()

      end if

      ::oPro:FieldPutByName( "lSndDoc", .f. )

      ::oPro:Skip()

   end while

Return ( self )

//---------------------------------------------------------------------------//

METHOD InsertPropiedadesPrestashop() CLASS TComercio

   local oImagen
   local nCodigoGrupo      := 0
   local nCodigoPropiedad  := 0
   local nParent           := 1
   local cCommand          := ""

   /*
   Insertamos una propiedad nueva en las tablas de prestashop-----------------
   */

   cCommand          := "INSERT INTO " + ::cPrefixTable( "attribute_group" ) + ; 
                              " ( is_color_group, " + ;
                                  "group_type )" + ;
                              " VALUES " + ;
                                  "('" + if( ::oPro:lColor, "1", "0" ) + "', " + ;        //is_color_group
                                  "'" + if( ::oPro:lColor, "color", "select" ) + "' )"    //group_type                        

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      nCodigoGrupo   := ::oCon:GetInsertId()

      ::oPro:fieldPutByName( "cCodWeb", nCodigoGrupo )

   else

      ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oPro:cDesPro ) + " en la tabla " + ::cPrefixTable( "attribute_group" ), 3 )

   end if

   cCommand          := "INSERT INTO " + ::cPrefixTable( "attribute_group_lang" ) + ; 
                              " ( id_attribute_group, " + ;
                                  "id_lang, " + ;
                                  "name, " + ;
                                  "public_name )" + ;
                              " VALUES " + ;
                                  "('" + alltrim( str( nCodigoGrupo ) ) + "', " + ;    //id_attribute_group
                                  "'" + str( ::nLanguage ) + "', " + ;                 //id_lang
                                  "'" + if( empty( ::oPro:cNomInt ), alltrim( ::oPro:cDesPro ), alltrim( ::oPro:cNomInt ) ) + "', " + ;          //name
                                  "'" + if( empty( ::oPro:cNomInt ), alltrim( ::oPro:cDesPro ), alltrim( ::oPro:cNomInt ) ) + "' )"              //public_name

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      ::treeSetText( "He insertado la propiedad " + alltrim( ::oPro:cDesPro ) + " correctamente en la tabla " + ::cPrefixTable( "attribute_group_lang" ), 3 )

   else

      ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oPro:cDesPro ) + " en la tabla " + ::cPrefixTable( "attribute_group_lang" ), 3 )

   end if

   /*
   Introducimos las l�neas-----------------------------------------------------
   */

   ::InsertLineasPropiedadesPrestashop( ::oPro:cCodPro, nCodigoGrupo )

return nCodigoGrupo

//---------------------------------------------------------------------------//

METHOD UpdatePropiedadesPrestashop( nTipoActualizacionLineas ) CLASS TComercio

   local cCommand

   DEFAULT nTipoActualizacionLineas := EDIT_MODE

   /*
   Modificamos la cabecera de las propiedades----------------------------------
   */

   cCommand       := "UPDATE " + ::cPrefixTable( "attribute_group" ) + " SET " + ;
                        "is_color_group='" + if( ::oPro:lColor, "1", "0" ) + "', " + ; 
                        "group_type='" + if( ::oPro:lColor, "color", "select" ) + "' " + ;
                     "WHERE id_attribute_group=" + alltrim( str( ::oPro:cCodWeb ) )                  

   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   cCommand       := "UPDATE " + ::cPrefixTable( "attribute_group_lang" ) + " SET " + ;
                        "name='" + if( empty( ::oPro:cNomInt ), alltrim( ::oPro:cDesPro ), alltrim( ::oPro:cNomInt ) ) + "', " + ; 
                        "public_name='" + if( empty( ::oPro:cNomInt ), alltrim( ::oPro:cDesPro ), alltrim( ::oPro:cNomInt ) ) + "' " + ;
                     "WHERE id_attribute_group=" + alltrim( str( ::oPro:cCodWeb ) )

   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   /*
   Tratamiento de las lineas de las propiedades--------------------------------
   */

   do case 
      case nTipoActualizacionLineas == EDIT_MODE //Actualiza las lineas--------

         ::UpdateLineasPropiedadesPrestashop( ::oPro:cCodPro )

      case nTipoActualizacionLineas != EDIT_MODE //Han eliminado o insertado alguna linea

         ::DeleteLineasPropiedadesPrestashop( ::oPro:cCodWeb )
         ::InsertLineasPropiedadesPrestashop( ::oPro:cCodPro, ::oPro:cCodWeb )

   end case

return ( self )

//---------------------------------------------------------------------------//

METHOD DeletePropiedadesPrestashop() CLASS TComercio

   local lReturn     := .f.
   local cCommand    := ""
   local oQuery

   cCommand          := "DELETE FROM " + ::cPrefixTable( "attribute_group" ) + " WHERE id_attribute_group=" + alltrim( str( ::oPro:cCodWeb ) )
   lReturn           := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "attribute_group_lang" ) + " WHERE id_attribute_group=" + alltrim( str( ::oPro:cCodWeb ) )
   lReturn           := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "attribute_group_shop" ) + " WHERE id_attribute_group=" + alltrim( str( ::oPro:cCodWeb ) )
   lReturn           := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   /*
   Eliminamos las lineas-------------------------------------------------------
   */

   ::DeleteLineasPropiedadesPrestashop( ::oPro:cCodWeb )

   /*
   Quitamos la referencia de nuestra tabla-------------------------------------
   */

   ::oPro:fieldPutByName( "cCodWeb", 0 )

return ( self )

//---------------------------------------------------------------------------//

METHOD ActualizaPropiedadesPrestashop( cCodigoPropiedad, nTipoActualizacionLineas ) CLASS TComercio

   local oQuery
   local cCommand

   DEFAULT nTipoActualizacionLineas  := EDIT_MODE

   if !::lReady()
      Return .f.
   end if
   
   if ::filesOpen()

      if ::oPro:Seek( cCodigoPropiedad )
   
         if ::ConectBBDD()
   
            do case
               case !::oPro:lPubInt .and. ::oPro:cCodWeb != 0
      
                  ::DeletePropiedadesPrestashop()

                  ::AvisoSincronizaciontotal()
      
               case ::oPro:lPubInt .and. ::oPro:cCodWeb != 0
      
                  cCommand := 'SELECT * FROM ' + ::cPrefixTable( "attribute_group" ) +  ' WHERE id_attribute_group=' + alltrim( str( ::oPro:cCodWeb ) )
                  oQuery   := TMSQuery():New( ::oCon, cCommand )
      
                  if oQuery:Open()
      
                     if oQuery:RecCount() > 0

                        ::UpdatePropiedadesPrestashop( nTipoActualizacionLineas )

                        if nTipoActualizacionLineas != EDIT_MODE
                           ::AvisoSincronizaciontotal()
                        end if

                     else

                        ::InsertPropiedadesPrestashop()
                        
                        ::AvisoSincronizaciontotal()

                     end if
      
                  end if
      
                  oQuery:Free()
      
               case ::oPro:lPubInt .and. ::oPro:cCodWeb == 0
      
                  ::InsertPropiedadesPrestashop()

                  ::AvisoSincronizaciontotal()
      
            end case

            ::DisconectBBDD()
   
         end if

      end if

      ::filesClose()

   end if

Return .t.

//---------------------------------------------------------------------------//

METHOD InsertLineasPropiedadesPrestashop( cCodPro, nCodigoGrupo ) CLASS TComercio

   local nPosition         := 0
   local nCodigoPropiedad  := 0
   local nRec              := ::oTblPro:Recno()
   local nOrdAnt           := ::oTblPro:OrdSetFocus( "CPRO" )
   local cCommand          := ""

   /*
   Introducimos las l�neas-----------------------------------------------------
   */

   if ::oTblPro:Seek( cCodPro )

      while cCodPro == ::oTblPro:cCodPro .and. !::oTblPro:Eof()

         cCommand    := "INSERT INTO " + ::cPrefixTable( "attribute" ) + ; 
                              " ( id_attribute_group, " + ;
                                 "color, " + ;
                                 "position )" + ;
                           "VALUES " + ;
                              " ( '" + alltrim( str( nCodigoGrupo ) ) + "', " + ;            // grupo
                                 "'" + alltrim( RgbToRgbHex( ::oTblPro:nColor) ) + "', " + ; // color
                                 "'" + alltrim( str( ++nPosition ) ) + "'" + ;             // posicion
                                 "' )"    

         if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

            nCodigoPropiedad   := ::oCon:GetInsertId()

            ::oTblPro:fieldPutByName( "cCodWeb", nCodigoPropiedad )

         else

            ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPreFixtable( "attribute" ), 3 )

         end if

         cCommand    := "INSERT INTO " + ::cPrefixTable( "attribute_lang" ) + ;
                           " ( id_attribute, " + ;
                              "id_lang, " + ;
                              "name ) " + ;
                           "VALUES " + ;
                              "('" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;   //id_attribute
                              "'" + str( ::nLanguage ) + "', " + ;                    //id_lang
                              "'" + ::oCon:Escapestr( ::oTblPro:cDesTbl ) + "' )"              //name

         if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
            ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPrefixTable( "attribute_lang" ), 3 )
         end if

         cCommand    := "INSERT INTO " + ::cPrefixTable( "attribute_shop" ) + ;
                           " ( id_attribute, " + ;
                              "id_shop ) " + ;
                           "VALUES " + ;
                              "('" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;   //id_attribute
                              "'1' )"                                                 //id_shop

         if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
            ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPrefixTable( "attribute_shop" ), 3 )
         end if

         ::oTblPro:Skip()

      end while

   end if

   /*
   Dejamos la tabla como estaba antes de entrar--------------------------------
   */

   ::oTblPro:OrdSetFocus( nOrdAnt )

   ::oTblPro:GoTo( nRec )

Return ( self )

//---------------------------------------------------------------------------//

METHOD UpdateLineasPropiedadesPrestashop( nCodigoPropiedad ) CLASS TComercio

   local cCommand
   local nRec              := ::oTblPro:Recno()
   local nOrdAnt           := ::oTblPro:OrdSetFocus( "CPRO" )

   if ::oTblPro:Seek( nCodigoPropiedad )

      while nCodigoPropiedad == ::oTblPro:cCodPro .and. !::oTblPro:Eof()

         cCommand       := "UPDATE " + ::cPrefixTable( "attribute" ) + " SET " + ;
                              "color='" + alltrim( RgbToRgbHex( ::oTblPro:nColor ) ) + "' " + ;
                           "WHERE id_attribute=" + alltrim( str( ::oTblPro:cCodWeb ) )

         TMSCommand():New( ::oCon ):ExecDirect( cCommand )

         cCommand       := "UPDATE " + ::cPrefixTable( "attribute_lang" ) + " SET " + ;
                              "name='" + alltrim( ::oTblPro:cDesTbl ) + "' " + ;
                           "WHERE id_attribute=" + alltrim( str( ::oTblPro:cCodWeb ) )

         TMSCommand():New( ::oCon ):ExecDirect( cCommand )

         ::oTblPro:Skip()

      end while

   end if

   /*
   Dejamos la tabla como estaba antes de entrar--------------------------------
   */

   ::oTblPro:OrdSetFocus( nOrdAnt )

   ::oTblPro:GoTo( nRec )

Return ( self )

//---------------------------------------------------------------------------//

METHOD DeleteLineasPropiedadesPrestashop( nCodigoPropiedad ) CLASS TComercio

   local oQuery
   local cCommand    := ""

   /*
   Borramos las tablas auxiliares de lineas de propiedades---------------------
   */

   cCommand          := "SELECT * FROM " + ::cPrefixTable( "attribute" ) + ;
                        " WHERE id_attribute_group = " + alltrim( str( nCodigoPropiedad ) )

   oQuery            := TMSQuery():New( ::oCon, cCommand )

   if oQuery:Open() .and. oQuery:RecCount() > 0

      oQuery:GoTop()

      while !oQuery:Eof()

         cCommand    := "DELETE FROM " + ::cPrefixTable( "attribute_lang" ) + " WHERE id_attribute=" + alltrim( str( oQuery:FieldGet( 1 ) ) )
         TMSCommand():New( ::oCon ):ExecDirect( cCommand )

         oQuery:Skip()

      end while

   end if

   /*
   Borramos las l�neas de propiedades de la tabla attribute--------------------
   */

   cCommand          := "DELETE FROM " + ::cPrefixTable( "attribute" ) + " WHERE id_attribute_group=" + alltrim( str( nCodigoPropiedad ) )
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

return ( self )

//---------------------------------------------------------------------------//

METHOD InsertPropiedadesProductPrestashop( nCodigoWeb ) CLASS TComercio


Return ( self )

//---------------------------------------------------------------------------//

METHOD EliminaPropiedadesProductsPrestashop( cCodWeb ) CLASS TComercio

   local oQuery
   local cCommand    := ""
   local idDelete

   /*
   Borramos las tablas auxiliares de lineas de propiedades---------------------
   */

   cCommand          := "SELECT * FROM " + ::cPrefixTable( "product_attribute" ) + ;
                        " WHERE id_product = " + alltrim( str( cCodWeb ) )

   oQuery            := TMSQuery():New( ::oCon, cCommand )

   if oQuery:Open() .and. oQuery:RecCount() > 0

      oQuery:GoTop()

      while !oQuery:Eof()

         idDelete    := oQuery:FieldGet( 1 ) //id_product_attributeb

         cCommand    := "DELETE FROM " + ::cPrefixTable( "product_attribute_combination" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
         TMSCommand():New( ::oCon ):ExecDirect( cCommand )

         cCommand    := "DELETE FROM " + ::cPrefixTable( "product_attribute_shop" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
         TMSCommand():New( ::oCon ):ExecDirect( cCommand )

         cCommand    := "DELETE FROM " + ::cPrefixTable( "stock_available" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
         TMSCommand():New( ::oCon ):ExecDirect( cCommand )
         
         cCommand    := "DELETE FROM " + ::cPrefixTable( "product_attribute_image" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
         TMSCommand():New( ::oCon ):ExecDirect( cCommand )
         
         oQuery:Skip()

      end while

   end if

   /*
   Borramos las l�neas de propiedades de la tabla attribute--------------------
   */

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attribute" ) + " WHERE id_product=" + alltrim( str( cCodWeb ) )
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

Return ( self )

//---------------------------------------------------------------------------//

METHOD AppendArticuloPrestashop( oDb ) CLASS TComercio

   local cCommand    := ""

   /*
   Art�culos----------------------------------------------------------
   */

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_attachment" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attachment" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attachment" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_attribute" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attribute" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attribute" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_attribute_combination" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attribute_combination" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attribute_combination" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_attribute_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attribute_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attribute_shop" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPreFixTable( "product_attribute_image" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attribute_image" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attribute_image" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_country_tax" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_country_tax" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_country_tax" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_download" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_download" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la table ' + ::cPrefixTable( "product_download" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_group_reduction_cache" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_group_reduction_cache" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_group_reduction_cache" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_shop" ), 3  )
   end if

   /*
   Descripciones de art�culos-----------------------------------------------
   */

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_lang" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_sale" ) 

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_sale" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_sale" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_tag" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_tag" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_tag" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "specific_price")

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "specific_price" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "specific_price" ), 3  )
   end if

   /*
   Propiedades logistica----------------------------------------------------
   */

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla '  + ::cPrefixTable( "feature" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "feature_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature_lang" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature_product" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "feature_product" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature_product" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature_value" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "feature_value" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature_value" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature_value_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "feature_value_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature_value_lang" ), 3  )
   end if

   /*
   Imagenes de escena-------------------------------------------------------
   */

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "scene" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "scene " ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "scene" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "scene_category" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "scene_category" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla' + ::cPrefixTable( "scene_category" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "scene_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "scene_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "scene_lang" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "scene_products" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "scene_products" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "scene_products" ), 3  )
   end if

   /*
   stockaje--------------------------------------------------------------------
   */

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "stock_available" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "stock_available" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "stock_available" ), 3  )
   end if

   /*
   limpiamos refencias de imagenes a la web------------------------------------
   */

   ::lLimpiaRefImgWeb()

   /*
   Limpiamos las Id de las tablas del programa--------------------------------
   */

   //::DelIdTipoArticuloPrestashop()

   ::oMeterProceso:Set( 0 )

   ::oMeter:Refresh()

   ::oMeterProceso:SetTotal( ::oArt:OrdKeyCount() )

   /*
   A�adimos articulos a prestashop---------------------------------------------
   */

   ::oArt:GoTop()

   while !::oArt:Eof()

      if ::oArt:lPubInt

         ::meterProcesoText( "Actualizando art�culos" )

         /*
         Metemos las familias como categor�as----------------------------------
         */

         ::InsertProductsPrestashop()

      end if

      ::oArt:FieldPutByName( "lSndDoc", .f. )

      ::oArt:Skip()

      ::oMeterProceso:AutoInc()

   end while

   ::oMeterProceso:SetTotal( ::oArt:LastRec() )

return ( Self )

//---------------------------------------------------------------------------//

METHOD ActualizaProductsPrestashop( cCodigoArticulo, lChangeImage ) CLASS TComercio

   local oQuery
   local cCommand

   if !::lReady()
      Return .f.
   end if

   if ::filesOpen()

      if ::oArt:Seek( cCodigoArticulo )
   
         if ::ConectBBDD()

            do case
               case !::oArt:lPubInt .and. ::oArt:cCodWeb != 0
      
                  ::cTextoWait( "Eliminando art�culo en prestashop" )

                  ::DeleteProductsPrestashop()
      
               case ::oArt:lPubInt .and. ::oArt:cCodWeb != 0

                  ::cTextoWait( "Eliminando art�culo en prestashop" )

                  ::DeleteProductsPrestashop()

                  ::cTextoWait( "A�adiendo art�culo en prestashop" )

                  ::InsertProductsPrestashop( .t. )

               case ::oArt:lPubInt .and. ::oArt:cCodWeb == 0
      
                  ::cTextoWait( "A�adiendo art�culo en prestashop" )

                  ::InsertProductsPrestashop( .t. )
      
            end case   

            ::DisconectBBDD()
   
         endif      

      end if

      ::filesClose()

   end if

Return .t.

//---------------------------------------------------------------------------//

METHOD InsertProductsPrestashop( lExt ) CLASS TComercio

   local nCodigoWeb           := 0
   local nCodigoImagen        := 0
   local oImagen
   local nOrdAnt
   local nPosition            := 1
   local nCodigoPropiedad     := 0
   local aPropiedades1        := {}
   local aPropiedades2        := {}
   local aPropiedad1
   local aPropiedad2
   local nPrecio              := 0
   local nParent              := ::GetParentCategories()
   local cCommand             := ""
   local nTotStock
   local nOrdArtDiv           := ::oArtDiv:OrdSetFocus( "cCodArt" )

   DEFAULT lExt               := .f.

   /*
   ----------------------------------------------------------------------------
   INSERTAMOS EL ART�CULO EN TODAS LAS TABLAS DE PRESTASHOP--------------------
   ----------------------------------------------------------------------------
   */

   ::cTextoWait( "A�adiendo art�culo: " + alltrim( ::oArt:Nombre ) )

   /*
   Vemos el preciodel art�culo-------------------------------------------------
   */

   if ::oArtDiv:Seek( ::oArt:Codigo )
      nPrecio  := 0
   else
      nPrecio  := ::oArt:pVtaWeb
   end if

   ::oArtDiv:OrdSetFocus( nOrdArtDiv )

   cCommand    := "INSERT INTO " + ::cPrefixTable( "product" ) + ;
                     " ( id_manufacturer, " + ;
                     "id_tax_rules_group, " + ;
                     "id_category_default, " + ;
                     "id_shop_default, " + ;
                     "quantity, " + ;
                     "minimal_quantity, " + ;
                     "price, " + ;
                     "reference, " + ;
                     "weight, " + ;
                     "active, " + ;
                     "date_add, " + ;
                     "date_upd )" + ;
                  " VALUES " + ;
                     "('" + alltrim( str( oRetFld( ::oArt:cCodFab, ::oFab, "cCodWeb", "cCodFab" ) ) ) + "', " + ; //id_manufacturer
                     "'" + alltrim( str( oRetFld( ::oArt:TipoIva, ::oIva, "CGRPWEB", "TIPO" ) ) ) + "', " + ;     //id_tax_rules_group  - tipo IVA
                     "'" + alltrim( str( nParent ) ) + "', " + ;                                                  //id_category_default
                     "'1', " + ;                                                                                  //id_shop_default
                     "'1', " + ;                                                                                  //quantity
                     "'1', " + ;                                                                                  //minimal_quantity
                     "'" + alltrim( str( nPrecio ) ) + "', " + ;                                                  //price
                     "'" + alltrim( ::oArt:Codigo ) + "', " + ;                                                   //reference
                     "'" + alltrim( str( ::oArt:nPesoKg ) ) + "', " + ;                                           //weight
                     "'1', " + ;                                                                                  //active
                     "'" + dtos( GetSysDate() ) + "', " + ;                                                       //date_add
                     "'" + dtos( GetSysDate() ) + "' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )                                                                                                             //date_upd

      nCodigoWeb           := ::oCon:GetInsertId()

      ::oArt:fieldPutByName( "cCodWeb", nCodigoWeb )

      ::treeSetText( "He insertado el art�culo " + alltrim( ::oArt:Nombre ) + " correctamente en la tabla " + ::cPrefixTable( "product" ), 3 )

   else

      ::treeSetText( "Error al insertar el art�culo " + alltrim( ::oArt:Nombre ) + " en la tabla " + ::cPrefixTable( "product" ), 3 )

   end if

   /*
   Insertamos un art�culo nuevo en la tabla category_product----------------
    */

   cCommand    := "INSERT INTO " + ::cPrefixTable( "category_product" ) + ;
                     " ( id_category, " + ;
                     "id_product )" + ;
                  " VALUES " + ;
                     "('" + alltrim( str( Max( nParent, 1 ) ) ) + "', " + ;
                     "'" + str( nCodigoWeb ) + "' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado el art�culo " + alltrim( ::oArt:Nombre ) + " correctamente en la tabla " + ::cPrefixTable( "product_lang" ), 3 )
   else
      ::treeSetText( "Error al insertar el art�culo " + alltrim( ::oArt:Nombre ) + " en la tabla " + ::cPrefixTable( "category_product" ), 3 )
   end if

   /*
   Insertamos un art�culo como producto destacado------------------------------
   */

   if ::oArt:lPubPor

      cCommand    := "INSERT INTO " + ::cPrefixTable( "category_product" ) + ;
                     " ( id_category, " + ;
                     "id_product )" + ;
                  " VALUES " + ;
                     "('2', " + ;
                     "'" + str( nCodigoWeb ) + "' )"
   
      if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
         ::treeSetText( "He insertado el art�culo " + alltrim( ::oArt:Nombre ) + " como producto destacado", 3 )
      else
         ::treeSetText( "Error al insertar el art�culo " + alltrim( ::oArt:Nombre ) + " como producto destacado", 3 )
      end if

   end if

   /*
   Insertamos un art�culo nuevo en la tabla category_shop-------------------
   */

   cCommand    := "INSERT INTO " + ::cPrefixTable( "product_shop" ) + ;
                     " ( id_product, " + ;
                     "id_shop, " + ;
                     "id_category_default, " + ;
                     "id_tax_rules_group, " + ;
                     "on_sale, " + ;
                     "price, " + ;
                     "active, " + ;
                     "date_add, " + ;
                     "date_upd )" + ;
                  " VALUES " + ;
                     "('" + str( nCodigoWeb ) + "', " + ;
                     "'1', " + ;
                     "'" + alltrim( str( nParent ) ) + "', " + ;
                     "'" + alltrim( str( oRetFld( ::oArt:TipoIva, ::oIva, "CGRPWEB", "TIPO" ) ) ) + "', " + ;
                     "'0', " + ;
                     "'" + alltrim( str( nPrecio ) ) + "', " + ;
                     "'1', " + ;
                     "'" + dtos( GetSysDate() ) + "', " + ;
                     "'" + dtos( GetSysDate() ) + "' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado el art�culo " + alltrim( ::oArt:Nombre ) + " correctamente en la tabla " + ::cPrefixTable( "product_shop" ), 3 )
   else
      ::treeSetText( "Error al insertar el art�culo " + alltrim( ::oArt:Nombre ) + " en la tabla " + ::cPrefixTable( "product_shop" ), 3 )
   end if

   /*
   Insertamos un art�culo nuevo en la tabla product_lang--------------------
   */

   cCommand    := "INSERT INTO " + ::cPrefixTable( "product_lang" ) +;
                     " ( id_product, " + ;
                     "id_lang, " + ;
                     "description, " + ;
                     "description_short, " + ;
                     "link_rewrite, " + ;
                     "meta_title, " + ;
                     "meta_description, " + ;
                     "meta_keywords, " + ;
                     "name, " + ;
                     "available_now, " + ;
                     "available_later )" + ;
                  " VALUES " + ;
                     "('" + str( nCodigoWeb ) + "', " + ;                  // id_product
                     "'" + str( ::nLanguage ) + "', " + ;                  // id_lang
                     "'" + if( !empty( ::oArt:mDesTec ), ::oCon:Escapestr( ::oArt:mDesTec ), ::oCon:Escapestr( ::oArt:Nombre ) ) + "', " + ;        // description
                     "'" + alltrim( ::oArt:Nombre ) + "', " + ;   // description_short
                     "'" + cLinkRewrite( ::oCon:Escapestr( ::oArt:Nombre ) ) + "', " + ;       // link_rewrite
                     "'" + alltrim( ::oArt:cTitSeo ) + "', " + ;   // Meta_t�tulo
                     "'" + alltrim( ::oArt:cDesSeo ) + "', " + ;   // Meta_description
                     "'" + alltrim( ::oArt:cKeySeo ) + "', " + ;   // Meta_keywords
                     "'" + ::oCon:Escapestr( ::oArt:Nombre ) + "', " + ;      // name
                     "'En stock', " + ;                                       // avatible_now
                     "'' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "He insertado el art�culo " + alltrim( ::oArt:Nombre ) + " correctamente en la tabla " + ::cPrefixTable( "product_lang" ), 3 )
   else
      ::treeSetText( "Error al insertar el art�culo " + alltrim( ::oArt:Nombre ) + " en la tabla " + ::cPrefixTable( "product_lang" ), 3 )
   end if

   /*
   Metemos el stock total del art�culo-----------------------------------------
   */

   nTotStock   := ::oStock:nStockArticulo( ::oArt:Codigo, ::TPrestashopConfig:getStore() )

   cCommand    := "INSERT INTO " + ::cPrefixTable( "stock_available" ) + " ( " + ;
                     "id_product, " + ;
                     "id_product_attribute, " + ;
                     "id_shop, " + ;
                     "id_shop_group, " + ;
                     "quantity, " + ;
                     "depends_on_stock, " + ;
                     "out_of_stock ) " + ;
                  "VALUES " + ;
                     "('" + alltrim( str( nCodigoWeb ) ) + "', " + ;
                     "'0', " + ;   
                     "'1', " + ;
                     "'0', " + ;
                     "'" + alltrim( str( nTotStock ) ) + "', " + ;
                     "'0', " + ;
                     "'2' )"

      if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
         ::treeSetText( "He insertado el art�culo  " + alltrim( ::oArt:Nombre ) + " correctamente en la tabla " + ::cPrefixTable( "stock_available" ), 3 )
      else
         ::treeSetText( "Error al insertar el art�culo " + alltrim( ::oArt:Nombre ) + " en la tabla " + ::cPrefixTable( "stock_available" ), 3 )
      end if

   SysRefresh()

   /*
   ----------------------------------------------------------------------------
   Insertamos las im�genes del producto----------------------------------------
   ----------------------------------------------------------------------------
   */

   ::cTextoWait( "A�adiendo im�genes art�culo: " + alltrim( ::oArt:Nombre ) )

   ::InsertImageProductsPrestashop()

   /*
   ----------------------------------------------------------------------------
   Insertamos las propiedades del producto-------------------------------------
   ----------------------------------------------------------------------------
   */

   ::cTextoWait( "A�adiendo propiedades del art�culo: " + alltrim( ::oArt:Nombre ) )

   ::InsertPropiedadesProductPrestashop( nCodigoWeb )

   /*
   ----------------------------------------------------------------------------
   Insertamos las ofertas del producto-----------------------------------------
   ----------------------------------------------------------------------------
   */

   ::cTextoWait( "A�adiendo ofertas del art�culo: " + alltrim( ::oArt:Nombre ) )

   ::InsertOfertasPrestashop( nCodigoWeb )

   /*
   ----------------------------------------------------------------------------
   Subimos las im�genes si no es una global------------------------------------
   ----------------------------------------------------------------------------
   */

   if lExt
      ::cTextoWait( "A�adiendo im�genes del art�culo: " + alltrim( ::oArt:Nombre ) )
      ::buildImagenes()
   end if   

return nCodigoweb

//---------------------------------------------------------------------------//

METHOD DeleteProductsPrestashop() CLASS TComercio

   local idDelete    := 0
   local idDelete2   := 0
   local cCommand    := ""
   local oQuery
   local oQuery2
   local cCodWeb 

   cCodWeb           := alltrim( str( ::oArt:cCodWeb ) )

   ::cTextoWait( "Eliminando art�culo de Prestashop" )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando adjuntos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attachment" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando impuestos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_country_tax" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando archivos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_download" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando cache de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_group_reduction_cache" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando multitienda de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_shop" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando descripciones de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_lang" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando ofertas de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_sale" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando etiquetas de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_tag" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando complementos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_supplier" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando transporte de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_carrier" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando atributos de Prestashop"  )

   cCommand          := 'SELECT * FROM ' + ::cPrefixTable( "product_attribute" ) +  ' WHERE id_product=' + cCodWeb
   oQuery            := TMSQuery():New( ::oCon, cCommand )
   
   ::cTextoWait( "Eliminando lineas atributos de Prestashop"  )

   if oQuery:Open()
   
      if oQuery:RecCount() > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            idDelete    := oQuery:FieldGet( 1 )

            if !empty( idDelete )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attribute" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attribute_combination" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attribute_image" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attribute_shop" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

            end if

            oQuery:Skip()

            SysRefresh()

         end while
   
      end if

   end if

   ::cTextoWait( "Eliminando precios especificos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "specific_price" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando prioridad de precio de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "specific_price_priority" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando funciones de Prestashop"  )

   cCommand          := 'SELECT * FROM ' + ::cPrefixTable( "feature_product" ) +  ' WHERE id_product=' + cCodWeb
   oQuery            := TMSQuery():New( ::oCon, cCommand )
   
   ::cTextoWait( "Eliminando lineas funciones de Prestashop"  )

   if oQuery:Open()
   
      if oQuery:RecCount() > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            idDelete    := oQuery:FieldGet( 1 )

            if !empty( idDelete )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_product" ) + " WHERE id_product=" + cCodWeb
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "feature" ) + " WHERE id_feature=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_lang" ) + " WHERE id_feature=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_shop" ) + " WHERE id_feature=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := 'SELECT * FROM ' + ::cPrefixTable( "feature_value" ) +  ' WHERE id_feature=' + alltrim( str( idDelete ) )
               oQuery2           := TMSQuery():New( ::oCon, cCommand )

               if oQuery2:Open()
         
                  if oQuery2:RecCount() > 0

                     oQuery2:GoTop()

                     while !oQuery2:Eof()

                     idDelete2    := oQuery:FieldGet( 1 )

                        if !empty( idDelete2 )

                           cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_value" ) + " WHERE id_feature_value=" + alltrim( str( idDelete2 ) )
                           TMSCommand():New( ::oCon ):ExecDirect( cCommand )

                           cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_value_lang" ) + " WHERE id_feature_value=" + alltrim( str( idDelete2 ) )
                           TMSCommand():New( ::oCon ):ExecDirect( cCommand )

                        end if

                        oQuery2:Skip()

                        SysRefresh()

                     end while      

                  end if

               end if

            end if

            oQuery:Skip()

            SysRefresh()

         end while      
   
      end if

   end if

   SysRefresh()

   /*
   Eliminamos las im�genes del art�culo---------------------------------------
   */

   ::cTextoWait( "Eliminando im�genes de prestashop" )

   ::DeleteImagesProducts( cCodWeb )

   SysRefresh()

   /*
   Quitamos la referencia de nuestra tabla-------------------------------------
   */

   ::oArt:fieldPutByName( "cCodWeb", 0 )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD DeleteImagesProducts( cCodWeb ) CLASS TComercio 

   local oInt
   local aDirectory
   local cDirectory
   local lError
   local idDelete
   local oQuery
   local cCommand    := ""
   local aDelImages  := {}
   local cCarpeta

   if !empty( cCodWeb )
      
      /*
      Limpiamos la refecencia en la base de datos------------------------------
      */

      cCommand          := 'SELECT * FROM ' + ::cPrefixTable( "image" ) +  ' WHERE id_product=' + cCodWeb
      oQuery            := TMSQuery():New( ::oCon, cCommand )

      if oQuery:Open() .and. oQuery:RecCount() > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            idDelete    := oQuery:FieldGet( 1 )

            aAdd( aDelImages, idDelete )

            cCommand          := "DELETE FROM " + ::cPrefixTable( "image" ) + " WHERE id_image=" + alltrim( str( idDelete ) )
            TMSCommand():New( ::oCon ):ExecDirect( cCommand )

            cCommand          := "DELETE FROM " + ::cPrefixTable( "image_shop" ) + " WHERE id_image=" + alltrim( str( idDelete ) )
            TMSCommand():New( ::oCon ):ExecDirect( cCommand )

            cCommand          := "DELETE FROM " + ::cPrefixTable( "image_lang" ) + " WHERE id_image=" + alltrim( str( idDelete ) )
            TMSCommand():New( ::oCon ):ExecDirect( cCommand )
         
            oQuery:Skip()

            SysRefresh()

         end while

      end if

      oQuery:Free()

      if !empty( ::TPrestashopConfig:getFtpServer() )

         if !empty( ::TPrestashopConfig:getImagesDirectory() )
            
            for each idDelete in aDelImages

               if !::oFtp:CreateConexion()

                  MsgStop( "Imposible conectar al sitio ftp " + ::TPrestashopConfig:getFtpServer() )

               else

                  cCarpeta    := ::CreateDirectoryImagesLocal( idDelete )

                  ::oFtp:SetCurrentDirectory( ::cDirectoryProduct() + cCarpeta )
                  ::oFtp:DeleteMask()

                  ::oFtp:SetCurrentDirectory( ".." )

               end if 

               ::oFtp:EndConexion()                  

            next

         end if

      else

         if isDirectory( ::TPrestashopConfig:getImagesDirectory() )
            
            for each idDelete in aDelImages

               cCarpeta       := ::CreateDirectoryImagesLocal( idDelete )

               DeleteFilesToDirectory( ::cDirectoryProduct() + cCarpeta )

            next

         end if
      
      end if   

   end if

   SysRefresh()

Return nil

//---------------------------------------------------------------------------//

METHOD InsertOfertasPrestashop( nCodigoWeb ) CLASS TComercio

   local cCommand          := ""

   if ::oArt:lSbrInt .and. ::oArt:nDtoInt1 != 0

      cCommand          := "INSERT INTO " + ::cPrefixTable( "specific_price" ) + ; 
                           " ( id_specific_price_rule, " + ;
                              "id_cart, " + ;
                              "id_product, " + ;
                              "id_shop, " + ;
                              "id_shop_group, " + ;
                              "id_currency, " + ;
                              "id_country, " + ;
                              "id_group, " + ;
                              "id_customer, " + ;
                              "id_product_attribute, " + ;
                              "price, " + ;
                              "from_quantity, " + ;
                              "reduction, " + ;
                              "reduction_type )" + ;
                           " VALUES " + ;
                              "('0', " + ;                                             //id_specific_price_rule
                              "'0', " + ;                                              //id_cart
                              "'" + alltrim( str( nCodigoWeb ) ) + "', " + ;           //id_product
                              "'1', " + ;                                              //id_shop
                              "'0', " + ;                                              //id_shop_group
                              "'0', " + ;                                              //id_currency
                              "'0', " + ;                                              //id_country
                              "'0', " + ;                                              //id_group
                              "'0', " + ;                                              //id_customer
                              "'0', " + ;                                              //id_product_attribute
                              "'-1', " + ;                                             //price
                              "'1', " + ;                                              //from_quantity
                              "'" + alltrim( str( ::oArt:nDtoInt1 / 100 ) ) + "', " + ;//reduction
                              "'percentage' )"                                         //reduction_type
   
      if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

         ::treeSetText( "He insertado la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " correctamente en la tabla " + ::cPrefixTable( "attribute" ), 3 )

      else

         ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPreFixtable( "attribute" ), 3 )

      end if

   end if

return nil

//---------------------------------------------------------------------------//

METHOD UpdateOfertasPrestashop() CLASS TComercio

   local cCommand          := ""

   if ::oArt:lSbrInt .and. ::oArt:nDtoInt1 != 0

      cCommand          := "UPDATE " + ::cPrefixTable( "specific_price" ) + " SET " + ;
                              "reduction='" + alltrim( str( ::oArt:nDtoInt1 / 100 ) ) + "' " + ;
                           "WHERE id_product=" + alltrim( str( ::oArt:cCodWeb ) )

      TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   end if   
            
return nil

//---------------------------------------------------------------------------//

METHOD InsertImageProductsPrestashop() CLASS TComercio

Return .t.

//---------------------------------------------------------------------------//

METHOD InsertImageProductImage( cCodigoWeb, lDefault )

   local cCommand
   local nCodigoImagen  := 0

   cCommand             := "INSERT INTO " + ::cPrefixTable( "image" ) + " ( " +;
                              "id_product, " + ;
                              "position, " + ;
                              "cover ) " + ;
                           "VALUES ( " + ;
                              "'" + alltrim( str( cCodigoWeb ) ) + "', " + ;
                              "'" + str( ::nImagePosition ) + "', " + ;
                              if( lDefault, "'1'", "'0'" ) + " )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      nCodigoImagen     := ::oCon:GetInsertId()
      
      ::oArtImg:fieldPutByName( "cCodWeb", nCodigoImagen )

      ::treeSetText( "Insertado la imagen del art�culo " + alltrim( ::oArt:Nombre ) + " correctamente en la tabla " + ::cPrefixTable( "image" ), 3 )
   else
      ::treeSetText( "Error al insertar la imagen del art�culo " + alltrim( ::oArt:Nombre ) + " en la tabla " + ::cPrefixTable( "image" ), 3 )
   end if

Return ( nCodigoImagen )

//---------------------------------------------------------------------------//

METHOD InsertImageProductImageLang( nCodigoImagen )

   local cCommand

   cCommand := "INSERT INTO " + ::cPrefixTable( "image_lang" ) + " ( " +;
                  "id_image, " + ;
                  "id_lang, " + ;
                  "legend ) " + ;
               "VALUES (" + ;
                  "'" + alltrim( str( nCodigoImagen ) ) + "', " + ;
                  "'" + alltrim( str( ::nLanguage ) ) + "', " + ;
                  "'" + ::oCon:Escapestr( ::oArtImg:cNbrArt ) + "' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Insertado la imagen del art�culo " + alltrim( ::oArt:Nombre ) + " correctamente en la tabla " + ::cPrefixTable( "image_lang" ), 3 )
   else
      ::treeSetText( "Error al insertar la imagen del art�culo " + alltrim( ::oArt:Nombre ) + " en la tabla " + ::cPrefixTable( "image_lang" ), 3 )
   end if

Return .t.

//---------------------------------------------------------------------------//

METHOD InsertImageProductImageShop( nCodigoImagen, lCover )

   local cCommand 

   DEFAULT lCover := .f.

   cCommand       := "INSERT INTO " + ::cPrefixTable( "image_shop" ) + " ( " 
   if ::lProductIdColumnImageShop
      cCommand    += "id_product, " 
   end if
   cCommand       += "id_image, "
   cCommand       += "id_shop, " 
   cCommand       += "cover ) " 
   cCommand       += "VALUES ( " 
   if ::lProductIdColumnImageShop
      cCommand    += "'" + alltrim( str( ::oArt:cCodWeb ) ) + "', "  // id_product
   end if
   cCommand       += "'" + alltrim( str( nCodigoImagen ) ) + "', "   // id_image
   cCommand       += "'1', "                                         // id_shop
   cCommand       += if( lCover, "'1'", "0" ) + ")"                  // cover

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Insertado la imagen del art�culo " + alltrim( ::oArt:Nombre ) + " correctamente en la tabla " + ::cPrefixTable( "image_shop" ), 3 )
   else
      ::treeSetText( "Error al insertar la imagen del art�culo " + alltrim( ::oArt:Nombre ) + " en la tabla " + ::cPrefixTable( "image_shop" ), 3 )
   end if

Return .t.

//---------------------------------------------------------------------------//

METHOD nIvaProduct( cCodArt ) Class TComercio

   local nIva        := 0
   local oQuery
   local cCommand    := ""
   
   cCommand    := 'SELECT * FROM ' + ::cPrefixTable( "tax" ) + ;
                  ' INNER JOIN ' + ::cPreFixTable( "tax_rule" ) + ' ON ' + ::cPrefixTable( "tax" ) + '.id_tax = ' + ::cPrefixTable( "tax_rule" ) + '.id_tax ' +; 
                  ' INNER JOIN ' + ::cPrefixTable( "product" ) + ' ON ' + ::cPrefixTable( "tax_rule" ) + '.id_tax_rules_group = ' + ::cPrefixTable( "product" ) + '.id_tax_rules_group ' + ;
                  ' WHERE ' + ::cPrefixTable( "product" ) + '.id_product = ' + alltrim( str( cCodArt ) )

   oQuery     := TMSQuery():New( ::oCon, cCommand )

   if oQuery:Open() .and. oQuery:RecCount() > 0

      oQuery:GoTop()

      nIva     := oQuery:FieldGetByName( "rate" )

   end if

Return ( nIva )

//---------------------------------------------------------------------------//

METHOD DelIdArticuloPrestashop() Class TComercio

   local nRec  := ::oArt:Recno()

   ::oArt:GoTop()

   while !::oArt:Eof()

      ::oArt:Load()
      ::oArt:cCodWeb := 0
      ::oArt:Save()

      ::treeSetText( 'Eliminando c�digo web en el art�culo ' + alltrim( ::oArt:Nombre ), 3  )

      SysRefresh()
      ::oArt:Skip()

   end while

   ::oArt:GoTo( nRec )

RETURN ( .t. )

//---------------------------------------------------------------------------//

METHOD buildImagenes() CLASS TComercio

   local oFile
   local oImage
   local oTipoImage
   local cNewImg           := ""
   local oImagenFinal
   local cCarpeta          := ""

   ::aImagesCategories     := {}
   ::aImagesArticulos      := {}

   CursorWait()

   /*
   Recogemos los tipos de imagenes---------------------------------------------
   */

   ::aTipoImagenPrestashop()

   ::meterProcesoSetTotal( len( ::aImages ) )

   /*
   Cargamos creamos las imagenes a subir---------------------------------------
   */

   for each oImage in ::aImages

      ::meterProcesoText( "Elaborando imagen " + alltrim(str(hb_enumindex())) + " de "  + alltrim(str(len(::aImages))) )

      // Metemos primero la imagen que no lleva tipo------------------------------

      do case
         case oImage:nTipoImagen == tipoProducto

            cNewImg                       := cPatTmp() + oImage:cPrefijoNombre + ".jpg"

            SaveImage( oImage:cNombreImagen, cNewImg )

            oImagenFinal                  := SImagen()
            oImagenFinal:cNombreImagen    := cNewImg
            oImagenFinal:nTipoImagen      := oImage:nTipoImagen
            oImagenFinal:cCarpeta         := oImage:cCarpeta

            ::AddImagesArticulos( oImagenFinal )

         case oImage:nTipoImagen == tipoCategoria

            cNewImg                       := cPatTmp() + oImage:cPrefijoNombre + ".jpg"

            SaveImage( oImage:cNombreImagen, cNewImg )

            oImagenFinal                  := SImagen()
            oImagenFinal:cNombreImagen    := cNewImg
            oImagenFinal:nTipoImagen      := oImage:nTipoImagen

            ::AddImagesCategories( oImagenFinal )

      end case

      /*
      Metemos las imagenes por tipo--------------------------------------------
      */

      for each oTipoImage in ::aTipoImagesPrestashop

         do case
            case oImage:nTipoImagen == tipoProducto .and. oTipoImage:lProducts

               cNewImg                       := cPatTmp() + oImage:cPrefijoNombre + "-" + oTipoImage:cNombreTipo + ".jpg"

               SaveImage( oImage:cNombreImagen, cNewImg, oTipoImage:nAnchoTipo, oTipoImage:nAltoTipo )

               oImagenFinal                  := SImagen()
               oImagenFinal:cNombreImagen    := cNewImg
               oImagenFinal:nTipoImagen      := oImage:nTipoImagen
               oImagenFinal:cCarpeta         := oImage:cCarpeta

               ::AddImagesArticulos( oImagenFinal )

            case oImage:nTipoImagen == tipoCategoria .and. oTipoImage:lCategories

               cNewImg                       := cPatTmp() + oImage:cPrefijoNombre + "-" + oTipoImage:cNombreTipo + ".jpg"

               SaveImage( oImage:cNombreImagen, cNewImg, oTipoImage:nAnchoTipo, oTipoImage:nAltoTipo )

               oImagenFinal                  := SImagen()
               oImagenFinal:cNombreImagen    := cNewImg
               oImagenFinal:nTipoImagen      := oImage:nTipoImagen

               ::AddImagesCategories( oImagenFinal )

         end case

         SysRefresh()

      next

   next

Return( nil )

//---------------------------------------------------------------------------//

METHOD buildSubirImagenes() CLASS TComercio

   local oImage

   // Conectamos al FTP y Subimos las im�genes de art�culos--------------------

   if Len( ::aImagesArticulos ) > 0

      if !::oFtp:CreateConexion()

         msgStop( "Imposible conectar al sitio ftp " + ::TPrestashopConfig:getFtpServer() )

      else

         // Subimos los ficheros de imagenes-----------------------------------

         ::meterProcesoSetTotal( len( ::aImagesArticulos ) )

         if !empty( ::TPrestashopConfig:getImagesDirectory() )
            ::oFtp:CreateDirectory( ::cDirectoryProduct(), .t. )
         end if

         for each oImage in ::aImagesArticulos

            ::meterProcesoText( "Subiendo imagen " + oImage:cNombreImagen + " [" + alltrim(str(hb_enumindex())) + " de "  + alltrim(str(len(::aImagesArticulos))) + "]" )

            // Posicionamos en el directorio-----------------------------------

            ::oFtp:CreateDirectoryRecursive( oImage:cCarpeta )

            // Sube el fichero ------------------------------------------------

            ::oFtp:CreateFile( oImage:cNombreImagen, ::cDirectoryProduct() + "/" + oImage:cCarpeta )
           
            // Volvemos al directorio raiz--------------------------------------

            ::oFtp:ReturnDirectory( oImage:cCarpeta )

            SysRefresh()

         next

      end if
      
      ::oFtp:EndConexion()

   end if 

   // Subimos las imagenes de las categories-----------------------------------

   if Len( ::aImagesCategories ) > 0

      if !::oFtp:CreateConexion()

         MsgStop( "Imposible conectar al sitio ftp " + ::TPrestashopConfig:getFtpServer() )

      else

         // Subimos los ficheros de imagenes-----------------------------------

         ::meterProcesoSetTotal( len( ::aImagesCategories ) )

         if !empty( ::TPrestashopConfig:getImagesDirectory() )
            ::oFtp:CreateDirectory( ::cDirectoryCategories(), .t. )
         end if

         for each oImage in ::aImagesCategories

            ::meterProcesoText( "Subiendo imagen categor�a " + alltrim(str(hb_enumindex())) + " de "  + alltrim(str(len(::aImagesCategories))) )

            // Posicionamos en el directorio-----------------------------------

            ::oFtp:CreateDirectoryRecursive( oImage:cCarpeta )

            // Sube el fichero ------------------------------------------------

            ::oFtp:CreateFile( oImage:cNombreImagen, oImage:cCarpeta )
           
            // Volvemos al directorio raiz-------------------------------------

            ::oFtp:ReturnDirectory( oImage:cCarpeta )

            SysRefresh()

         next

      end if

      ::oFtp:EndConexion()

      // Borramos las imagenes creadas en los temporales-----------------------

      for each oImage in ::aImagesArticulos
         fErase( oImage:cNombreImagen )
      next

      for each oImage in ::aImagesCategories
         fErase( oImage:cNombreImagen )
      next

   end if 

   ::aImages               := {}

   CursorWe()

Return( nil )

//---------------------------------------------------------------------------//

METHOD aTipoImagenPrestashop() CLASS TComercio

   local oImagen
   local oQuery            := TMSQuery():New( ::oCon, 'SELECT * FROM ' + ::cPrefixTable( "image_type" ) )

   if oQuery:Open()

      if oQuery:RecCount() > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            oImagen                       := STipoImagen()
            oImagen:cNombreTipo           := oQuery:FieldGetByName( "name" )
            oImagen:nAnchoTipo            := oQuery:FieldGetByName( "width" )
            oImagen:nAltoTipo             := oQuery:FieldGetByName( "height" )
            oImagen:lCategories           := ( oQuery:FieldGetByName( "categories" ) == 1 )
            oImagen:lProducts             := ( oQuery:FieldGetByName( "products" ) == 1 )
            oImagen:lManufactures         := ( oQuery:FieldGetByName( "manufacturers" ) == 1 )
            oImagen:lSuppliers            := ( oQuery:FieldGetByName( "suppliers" ) == 1 )
            oImagen:lScenes               := ( oQuery:FieldGetByName( "scenes" ) == 1 )
            oImagen:lStores               := ( oQuery:FieldGetByName( "stores" ) == 1 )

            ::AddTipoImagesPrestashop( oImagen )

            oQuery:Skip()

            SysRefresh()

         end while

      end if

   else 

      ::treeSetText( "Error al ejecutar la sentencia " + "SELECT * FROM " + ::cPrefixTable( "image_type" ), 3 )

   end if

   oQuery:Free()

   oQuery            := nil

Return ( self )

//---------------------------------------------------------------------------//

METHOD nDefImagen( cCodArt, cImagen ) CLASS TComercio

   local nDef           := 0

   if ::oArtImg:SeekInOrd( cCodArt, "lDefImg" )

      if ::oArtImg:cImgArt == cImagen

         nDef           := 1

      end if

   else

      if !::lDefImgPrp

         nDef           := 1

         ::lDefImgPrp   := .t.

      end if

   end if

Return nDef

//---------------------------------------------------------------------------//

METHOD lLimpiaRefImgWeb() CLASS TComercio

   local nRec     := ::oArtDiv:Recno()
   local nOrdAnt  := ::oArtDiv:OrdSetFocus( "cCodArt" )

   ::oArtDiv:GoTop()

   while !::oArtDiv:Eof()

      if ::oArtDiv:cCodImgWeb != 0
         ::oArtDiv:fieldPutByName( "cCodImgWeb", 0 )
      end if   

      ::oArtDiv:Skip()

   end while

   ::oArtDiv:OrdSetFocus( nOrdAnt )
   ::oArtDiv:GoTo( nRec )

return .t.

//-----------------------------------------------------------------------------

METHOD nCodigoWebImagen( cCodArt, cImagen ) CLASS TComercio

   local nCodigo  := 0
   local nRec     := ::oArtDiv:Recno()
   local nOrdAnt  := ::oArtDiv:OrdSetFocus( "cCodArt" )

   ::oArtDiv:GoTop()

   if ::oArtDiv:Seek( cCodArt )

      while ::oArtDiv:cCodArt == cCodArt .and. !::oArtDiv:Eof()

         if ::oArtDiv:cImgWeb == cImagen .and. ::oArtDiv:cCodImgWeb != 0

            nCodigo  := ::oArtDiv:cCodImgWeb

         end if

         ::oArtDiv:Skip()

      end while

   end if

   ::oArtDiv:OrdSetFocus( nOrdAnt )
   ::oArtDiv:GoTo( nRec )

return nCodigo

//---------------------------------------------------------------------------//

METHOD ConectBBDD() Class TComercio

Return ( .f. )

//---------------------------------------------------------------------------//

METHOD DisconectBBDD() Class TComercio

   if !empty( ::oCon )
      ::oCon:Destroy()
   end if

Return .t.  

//---------------------------------------------------------------------------//

METHOD isProductIdColumn( cTable )

   local oQuery
   local cCommand       
   local isProduct      := .f.

   DEFAULT cTable       := "image_shop"

   cCommand             := "SHOW COLUMNS FROM " + ::cPrefixTable( cTable ) + " LIKE 'id_product'"

   oQuery               := TMSQuery():New( ::oCon, cCommand )

   if oQuery:Open()
      isProduct         := oQuery:RecCount() > 0
   end if

   if !empty( oQuery )
      oQuery:Free()
   end if   

Return ( isProduct )

//---------------------------------------------------------------------------//

METHOD lShowDialogWait() Class TComercio

   CursorWait()

   ::oDlgWait     := TDialog():New( , , , , , "wait_web", , .f.,,,,,,.f. )

   ::oBmpWait     := TBitmap():ReDefine( 500, "logogestool_48", , ::oDlgWait, , , .f., .f., , , .f., , , .t. ) 

   ::oSayWait     := TSay():ReDefine( 510, {|| "Actualizando web espere por favor..." }, ::oDlgWait )

   TAnimat():Redefine( ::oDlgWait, 520, { "BAR_01" }, 1 )

   ::oDlgWait:Activate( , , , .t., ,.f. )

Return .t.

//---------------------------------------------------------------------------//

METHOD lHideDialogWait() Class TComercio

   ::oDlgWait:End()

   if !empty( ::oBmpWait )
      ::oBmpWait:End()
   end if

   CursorWe()

Return .t.

//---------------------------------------------------------------------------//

METHOD cTextoWait( cText ) CLASS TComercio

   if empty( cText )
      cText    := "Actualizando web espere por favor..."
   end if   

   ::writeText( cText )

Return nil

//---------------------------------------------------------------------------//

METHOD AvisoSincronizaciontotal() CLASS TComercio

   msginfo( "Faltan Avisar de que necesita una sincronizaci�n total" )

Return .t.

//---------------------------------------------------------------------------//

METHOD cPreFixtable( cName ) Class TComercio

Return ( ::TPrestashopConfig:getPrefixDatabase() + alltrim( cName ) )

//---------------------------------------------------------------------------//

METHOD AutoRecive( oWnd ) CLASS TComercio

   local oDb

   if !empty( oTimer )
      oTimer:DedialogActivate()
   end if

   DEFAULT  oWnd        := oWnd()

   if ::filesOpen()

      ::treeSetText( 'Intentando conectar con el servidor ' + '"' + ::cHost + '"' + ', el usuario ' + '"' + ::cUser + '"' + ' y la base de datos ' + '"' + ::cDbName + '".' , 1 )

      ::oCon            := TMSConnect():New()

      if !::oCon:Connect( ::cHost, ::cUser, ::cPasswd, ::cDbName, ::nPort )

          ::treeSetText( 'No se ha podido conectar con la base de datos.' )

      else

          ::treeSetText( 'Se ha conectado con �xito a la base de datos.' , 1 )

          oDb           := TMSDataBase():New ( ::oCon, ::cDbName )

          if empty( oDb )

             ::treeSetText( 'La Base de datos: ' + ::cDbName + ' no est� activa.', 1 )

          else

            ::AppendClient( oDb )
            ::AppendPedido( oDb )

          end if

      end if

      ::oCon:Destroy()

      ::treeSetText( 'Base de datos desconectada.', 1 )

   else

      ::treeSetText( 'Error al abrir los ficheros necesarios.', 1 )

   end if

   /*
   Comprobamos q existen pedidos para recibir----------------------------------
   */

   lPedidosWeb( ::oPedCliT:cAlias )

   /*
   Cerramos los ficheros-------------------------------------------------------
   */

   ::filesClose()

   /*
   Reactivamos el timer--------------------------------------------------------
   */

   if !empty( oTimer )
      oTimer:dialogActivate()
   end if

Return Nil

//---------------------------------------------------------------------------//

METHOD GetLanguagePrestashop() CLASS TComercio

   local oQuery
   local cCodLanguage

   oQuery               := TMSQuery():New( ::oCon, 'SELECT * FROM ' + ::cPrefixTable( "lang" ) +  ' WHERE active = 1' )

   if oQuery:Open() .and. oQuery:RecCount() > 0
      cCodLanguage   := oQuery:FieldGet( 1 )
   end if

   if !empty( oQuery )
      oQuery:Free()
   end if   

Return if( !empty( cCodLanguage ), cCodLanguage, 1 )

//---------------------------------------------------------------------------//

METHOD GetValPrp( nIdPrp, nProductAttibuteId ) CLASS TComercio

   local oQuery1
   local oQuery2
   local nIdAttribute
   local nIdAttributeGroup
   local cValPrp                 := ""

   oQuery1                       := TMSQuery():New( ::oCon, 'SELECT * FROM ' + ::cPrefixTable( "product_attribute_combination" ) + ' where id_product_attribute=' + alltrim( str( nProductAttibuteId ) ) )

   if oQuery1:Open()

      /*
      Recorremos el Query con la consulta-----------------------------------------
      */

      if oQuery1:RecCount() > 0

         oQuery1:GoTop()

         while !oQuery1:Eof()

         nIdAttribute            := oQuery1:FieldGet( 1 )

         oQuery2                 := TMSQuery():New( ::oCon, 'SELECT * FROM ' + ::cPrefixTable( "attribute" ) + ' where id_attribute=' + alltrim( str( nIdAttribute ) ) )

         if oQuery2:Open()

            if oQuery2:RecCount() > 0

               nIdAttributeGroup := oQuery2:FieldGet( 2 )

               if nIdAttributeGroup == nIdPrp

                  if ::oTblPro:SeekInOrd( str( nIdAttribute, 11 ), "cCodWeb" )

                     cValPrp     := ::oTblPro:cCodTbl

                  end if

               end if

            end if

         end if

         oQuery1:Skip()

         end while

      end if

   end if

   oQuery1:Free()

return cValPrp

//---------------------------------------------------------------------------//

METHOD AppTipoArticuloPrestashop( cCodTip, IdParent ) CLASS TComercio

   local nCodigoWeb     := 0
   local nOrdAnt        := ::oTipArt:OrdSetFocus( "cCodTip" )
   local oCategoria
   local oImagen

   if !::oTipArt:Seek( cCodTip )

      nCodigoWeb        := IdParent

   else

      if ( ::oTipArt:cCodWeb != 0 )

         nCodigoWeb     := ::oTipArt:cCodWeb

      else

         if TMSCommand():New( ::oCon ):ExecDirect( ;
            "INSERT INTO " + ::cPrefixTable( "category" ) + ;
               " ( id_parent, level_depth, nleft, nright, active, date_add, date_upd, position ) " + ;
            "VALUES " + ;
               " ( '" + str( IdParent ) + "', '2', '0', '0', '1', '" + dtos( GetSysDate() ) + "', '" + dtos( GetSysDate() ) + "', '0' ) " )

            nCodigoWeb           := ::oCon:GetInsertId()

            ::nNumeroCategorias++

            /*
            Metemos en un array para luego calcular las coordenadas---------------
            */

            oCategoria                       := SCategoria()
            oCategoria:id                    := nCodigoWeb
            oCategoria:idParent              := IdParent
            oCategoria:nTipo                 := 3

            aAdd( ::aCategorias, oCategoria )

            /*
            Guardamos en nuestra tabla lasel id de la categoria-------------------
            */

            ::oTipArt:fieldPutByName( "cCodWeb", nCodigoWeb )

            ::treeSetText( "He insertado el tipo de art�culo " + alltrim( ::oTipArt:cNomTip ) + " correctamente en la tabla category", 3 )

         else
            ::treeSetText( "Error al insertar el tipo de art�culo " + alltrim( ::oTipArt:cNomTip ) + " en la tabla category", 3 )
         end if

         if TMSCommand():New( ::oCon ):ExecDirect( ;
            "INSERT INTO " + ::cPrefixTable( "category_lang" ) +;
               " ( id_category, id_lang, name, description, link_rewrite, meta_title, meta_keywords, meta_description ) " + ;
            "VALUES"+ ;
               " ( '" + str( nCodigoWeb ) + "', '" + str( ::nLanguage ) + "', '" + ::oCon:Escapestr( ::oTipArt:cNomTip ) + "', '" + ::oCon:Escapestr( ::oTipArt:cNomTip ) + "', '" + cLinkRewrite( ::oTipArt:cNomTip ) + "', '', '', '' )" )

            ::treeSetText( "He insertado el tipo de art�culo " + alltrim( ::oTipArt:cNomTip ) + " correctamente en la tabla category_lang", 3 )
         else
            ::treeSetText( "Error al insertar el tipo de art�culo " + alltrim( ::oTipArt:cNomTip ) + " en la tabla category_lang", 3 )
         end if

         if TMSCommand():New( ::oCon ):ExecDirect( "INSERT INTO " + ::cPrefixTable( "category_shop" ) + " ( id_category, id_shop, position ) VALUES ( '" + str( nCodigoWeb ) + "', '1', '0' )" )
            ::treeSetText( "He insertado correctamente en la tabla category_group la categor�a raiz", 3 )
         else
            ::treeSetText( "Error al insertar la categor�a inicio en category_group", 3 )
         end if

         if TMSCommand():New( ::oCon ):ExecDirect( "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '" + str( nCodigoWeb ) + "', '1' )" )
            ::treeSetText( "He insertado el tipo de art�culo " + alltrim( ::oTipArt:cNomTip ) + " correctamente en la tabla category_group", 3 )
         else
            ::treeSetText( "Error al insertar " + alltrim( ::oTipArt:cNomTip ) + " en la tabla category_group", 3 )
         end if

         if TMSCommand():New( ::oCon ):ExecDirect( "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '" + str( nCodigoWeb ) + "', '2' )" )
            ::treeSetText( "He insertado el tipo de art�culo " + alltrim( ::oTipArt:cNomTip ) + " correctamente en la tabla category_group", 3 )
         else
            ::treeSetText( "Error al insertar el tipo de art�culo " + alltrim( ::oTipArt:cNomTip ) + " en la tabla category_group", 3 )
         end if

         if TMSCommand():New( ::oCon ):ExecDirect( "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '" + str( nCodigoWeb ) + "', '3' )" )
            ::treeSetText( "He insertado el tipo de art�culo " + alltrim( ::oTipArt:cNomTip ) + " correctamente en la tabla category_group", 3 )
         else
            ::treeSetText( "Error al insertar el tipo de art�culo " + alltrim( ::oTipArt:cNomTip ) + " en la tabla category_group", 3 )
         end if

         /*
         Insertamos un registro en las tablas de im�genes----------------------
         */

         if !empty( ::oTipArt:cImgTip )

            /*
            A�adimos la imagen al array para pasarla a prestashop--------------
            */

            oImagen                       := SImagen()
            oImagen:cNombreImagen         := alltrim( ::oTipArt:cImgTip )
            oImagen:nTipoImagen           := tipoCategoria
            oImagen:cPrefijoNombre        := alltrim( str( nCodigoWeb ) )

            ::AddImages( oImagen )

         end if

      end if

   end if

return nCodigoWeb

//---------------------------------------------------------------------------//

METHOD AppendClientesToPrestashop() CLASS TComercio

   local nCodigoWeb  := 0
   local nSpace      := 0
   local cFirstName  := ""
   local cLastName   := ""

   ::treeSetText( "Recorremos la tabla de clientes", 2 )

   /*
   A�adimos familias a prestashop----------------------------------------------
   */

   ::oCli:GoTop()

   while !::oCli:Eof()

      if ::oCli:lPubInt .and. ::oCli:lSndInt

         if !::oCli:lWeb

            if ::oCli:cCodWeb == 0

               nSpace               := At( " ", ::oCli:Titulo )
               cFirstName           := ::oCon:Escapestr( Substr( ::oCli:Titulo, 1, nSpace ) )
               cLastName            := ::oCon:Escapestr( Substr( ::oCli:Titulo, nSpace + 1 ) )

               if TMSCommand():New( ::oCon ):ExecDirect( "INSERT INTO " + ::cPrefixTable( "customer" ) + " ( id_gender, " + ;
                                                                                    "id_default_group, " + ;
                                                                                    "firstname, " + ;
                                                                                    "lastname, " + ;
                                                                                    "email, " + ;
                                                                                    "passwd, " + ;
                                                                                    "newsletter, " + ;
                                                                                    "secure_key, " + ;
                                                                                    "active, " + ;
                                                                                    "is_guest, " + ;
                                                                                    "deleted, " + ;
                                                                                    "date_add, " + ;
                                                                                    "date_upd )" + ;
                                                                           " VALUES " + ;
                                                                                    "('9', " + ;                                                         //id_gender, " - Genero desconocido
                                                                                    "'1', " + ;                                                          //"id_default_group, " + ;
                                                                                    "'" + ( cFirstName ) + "', " + ;                                     //"firstname, " + ;
                                                                                    "'" + ( cLastName ) + "', " + ;                                      //"lastname, " + ;
                                                                                    "'" + ::oCon:Escapestr( ::oCli:cMeiInt ) + "', " + ;                 //"email, " + ;
                                                                                    "'" + hb_md5( alltrim( ::TPrestashopConfig:getCookieKey() ) + alltrim( ::oCli:cClave ) ) + "', " + ;   //"passwd, " + ;
                                                                                    "'1', " + ;                                                          //"newletter, " + ;
                                                                                    "'" + hb_md5( alltrim( ::oCli:Cod ) ) + "', " + ;                    //"secure_key, " + ;
                                                                                    "'1', " + ;                                                          //"active, " + ;
                                                                                    "'0', " + ;                                                          //"is_guest, " + ;
                                                                                    "'0', " + ;                                                          //"deleted, " + ;
                                                                                    "'" + dtos( GetSysDate() ) + "', " + ;                               //"date_add )" + ;
                                                                                    "'" + dtos( GetSysDate() ) + "' )" )                                 //"date_upd )" + ;

                  nCodigoWeb           := ::oCon:GetInsertId()

                  ::oCli:fieldPutByName( "cCodWeb", nCodigoWeb )

                  ::treeSetText( "He insertado el cliente " + alltrim( ::oCli:Titulo ) + " correctamente en la tabla customer", 3 )

               else
                  ::treeSetText( "Error al insertar el cliente " + alltrim( ::oCli:Titulo ) + " en la tabla customer", 3 )
               end if

               /*
               Insertamos en la tabla customer_group------------------------
               */

               if TMSCommand():New( ::oCon ):ExecDirect( "INSERT INTO " + ::cPrefixTable( "customer_group" ) + " ( id_customer, " + ;
                                                                                          "id_group )" + ;
                                                                                 " VALUES " + ;
                                                                                           "('" + alltrim( str( nCodigoWeb ) ) + "', " + ;
                                                                                           "'1' )" )

                  ::treeSetText( "He insertado el cliente " + alltrim( ::oCli:Titulo ) + " correctamente en la tabla customer_group", 3 )

               else
                  ::treeSetText( "Error al insertar el cliente " + alltrim( ::oCli:Titulo ) + " en la tabla customer_group", 3 )
               end if

               /*
               Insertamos en la tabla address------------------------
               */

               if TMSCommand():New( ::oCon ):ExecDirect( "INSERT INTO " + ::cPrefixTable( "address" ) + " ( id_country, " + ;
                                                                                  "id_customer, " + ;
                                                                                  "alias, " + ;
                                                                                  "lastname, " + ;
                                                                                  "firstname, " + ;
                                                                                  "address1, " + ;
                                                                                  "postcode, " + ;
                                                                                  "city, " + ;
                                                                                  "phone, " + ;
                                                                                  "phone_mobile, " + ;
                                                                                  "dni, " + ;
                                                                                  "date_add, " + ;
                                                                                  "date_upd, " + ;
                                                                                  "active, " + ;
                                                                                  "deleted )" + ;
                                                                         " VALUES " + ;
                                                                                  "('6', " + ;                                                   //id_country
                                                                                  "'" + alltrim( str( nCodigoWeb ) ) + "', " + ;                 //id_customer
                                                                                  "'" + cFirstName + cLastName  + "', " + ; //alias
                                                                                  "'" + alltrim( cLastName ) + "', " + ;                         //lastname
                                                                                  "'" + alltrim( cFirstName ) + "', " + ;                        //firstname
                                                                                  "'" + ::oCon:Escapestr( ::oCli:Domicilio ) + "', " + ;                  //address1
                                                                                  "'" + ::oCon:Escapestr( ::oCli:CodPostal ) + "', " + ;                  //postcode
                                                                                  "'" + ::oCon:Escapestr( ::oCli:Poblacion ) + "', " + ;                  //city
                                                                                  "'" + ::oCon:Escapestr( ::oCli:Telefono ) + "', " + ;                   //phone
                                                                                  "'" + ::oCon:Escapestr( ::oCli:Movil ) + "', " + ;                      //phone_mobile
                                                                                  "'" + ::oCon:Escapestr( ::oCli:Nif ) + "', " + ;                        //dni
                                                                                  "'" + dtos( GetSysDate() ) + "', " + ;                         //date_add
                                                                                  "'" + dtos( GetSysDate() ) + "', " + ;                         //date_upd
                                                                                  "'1', " + ;                                                    //active
                                                                                  "'0' )" )                                                      //deleted


                  ::treeSetText( "He insertado el cliente " + alltrim( ::oCli:Titulo ) + " correctamente en la tabla address", 3 )

               else
                  ::treeSetText( "Error al insertar el cliente " + alltrim( ::oCli:Titulo ) + " en la tabla address", 3 )
               end if

            else

               nSpace               := At( " ", ::oCli:Titulo )
               cFirstName           := ::oCon:Escapestr( Substr( ::oCli:Titulo, 1, nSpace ) )
               cLastName            := ::oCon:Escapestr( Substr( ::oCli:Titulo, nSpace + 1 ) )

               if !::oCli:lWeb

                  /*
                  Actualizamos la tabla de clientes----------------------------
                  */

                  if TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "customer" ) + " SET firstname='" + alltrim( cFirstName ) + ;
                                                                                "', lastname='" + alltrim( cLastName ) + ;
                                                                                "', email='" + alltrim( ::oCli:cMeiInt ) + ;
                                                                                "', passwd='" + hb_md5( alltrim( ::TPrestashopConfig:getCookieKey() ) + alltrim( ::oCli:cClave ) ) + ;
                                                                                "', secure_key='" + hb_md5( alltrim( ::oCli:Cod ) ) + ;
                                                                                "', date_upd='" + dtos( GetSysDate() ) + ;
                                                                                "' WHERE id_customer=" + alltrim( str( ::oCli:cCodWeb ) ) )

                     ::treeSetText( "Actualizado correctamente el cliente " + alltrim( ::oCli:Titulo ) + " en la tabla customer", 3 )
                  else
                     ::treeSetText( "Error al actualizar el cliente " + alltrim( ::oCli:Titulo ) + " en la tabla customer", 3 )
                  end if

                  /*
                  Actualizamos la tabla de direcciones-------------------------
                  */

                  if TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "address" ) + " SET alias='" + ( cFirstName ) + ( cLastName ) + ;
                                                                                "', firstname='" + ( cFirstName ) + ;
                                                                                "', lastname='" + ( cLastName ) + ;
                                                                                "', address1='" + ::oCon:Escapestr( ::oCli:Domicilio ) + ;
                                                                                "', postcode='" + ::oCon:Escapestr( ::oCli:CodPostal ) + ;
                                                                                "', city='" + ::oCon:Escapestr( ::oCli:Poblacion ) + ;
                                                                                "', phone='" + ::oCon:Escapestr( ::oCli:Telefono ) + ;
                                                                                "', phone_mobile='" + ::oCon:Escapestr( ::oCli:Movil ) + ;
                                                                                "', dni='" + ::oCon:Escapestr( ::oCli:Nif ) + ;
                                                                                "', date_upd='" + dtos( GetSysDate() ) + ;
                                                                                "' WHERE id_customer=" + alltrim( str( ::oCli:cCodWeb ) ) )

                     ::treeSetText( "Actualizado correctamente el cliente " + alltrim( ::oCli:Titulo ) + " en la tabla address", 3 )
                  else
                     ::treeSetText( "Error al actualizar el cliente " + alltrim( ::oCli:Titulo ) + " en la tabla address", 3 )
                  end if

               end if

            end if

         end if

      end if

      ::oCli:FieldPutByName( "lSndDoc", .f. )

      ::oCli:Skip()

   end while

Return ( self )

//---------------------------------------------------------------------------//

METHOD AppendClientPrestashop() CLASS TComercio

   local oQueryDirecciones
   local lFirst                  := .t.
   local oQuery                  := TMSQuery():New( ::oCon, 'SELECT * FROM ' + ::cPrefixTable( "customer" ) )
   local cCodCli
   local oQueryState
   local cProvincia              := ""

   /*
   Recorremos el Query con la consulta-----------------------------------------
   */

   if oQuery:Open()

      /*
      Cargamos los valores para el meter------------------------------------------
      */

      ::nTotMeter    := oQuery:RecCount()

      if !empty( ::oMeterProceso )
         ::oMeterProceso:SetTotal( ::nTotMeter )
      end if

      ::nMeterProceso := 1

      if oQuery:RecCount() > 0

         ::treeSetText( "Descargando clientes desde la web", 2 )

         oQuery:GoTop()

         while !oQuery:Eof()

            ::meterProcesoText( " Descargando cliente " + alltrim( str( ::nMeterProceso ) ) + " de "  + alltrim( str( ::nTotMeter ) ) )

            if !::oCli:SeekInOrd( str( oQuery:FieldGet( 1 ), 11 ), "cCodWeb" )

               cCodCli           := NextKey( dbLast(  ::oCli, 1 ), ::oCli:cAlias, "0", RetNumCodCliEmp() )

               ::oCli:Append()
               ::oCli:Blank()
               ::oCli:Cod        := cCodCli
               
               if ::TPrestashopConfig:getHideHideExportButton()
                  ::oCli:Titulo  := UPPER( oQuery:FieldGetbyName( "lastname" ) ) + ", " + UPPER( oQuery:FieldGetByName( "firstname" ) ) // Last Name - firstname
               else   
                  ::oCli:Titulo  := UPPER( oQuery:FieldGetbyName( "firstname" ) ) + Space( 1 ) + UPPER( oQuery:FieldGetByName( "lastname" ) ) //firstname - Last Name
               end if   
               
               ::oCli:nTipCli    := 3
               ::oCli:CopiasF    := 1
               ::oCli:Serie      := ::TPrestashopConfig:getOrderSerie()
               ::oCli:nRegIva    := 1
               ::oCli:nTarifa    := 1
               ::oCli:cMeiInt    := oQuery:FieldGetByName( "email" ) //email
               ::oCli:lChgPre    := .t.
               ::oCli:lSndInt    := .t.
               ::oCli:CodPago    := cDefFpg()
               ::oCli:cCodAlm    := cDefAlm()
               ::oCli:dFecChg    := GetSysDate()
               ::oCli:cTimChg    := Time()
               ::oCli:cCodWeb    := oQuery:FieldGet( 1 ) //id_customer
               ::oCli:lWeb       := .t.

               /*
               Vamos a meter las direcciones-----------------------------------
               */

               oQueryDirecciones       := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixTable( "address" ) + " WHERE id_customer = " + str( oQuery:FieldGet( 1 ) ) )

               if oQueryDirecciones:Open()

                  if oQueryDirecciones:RecCount() > 0

                     oQueryDirecciones:GoTop()

                     while !oQueryDirecciones:Eof()

                        /*
                        Tomamos el nombre de la provincia----------------------
                        */                        

                        oQueryState       := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixTable( "state" ) + " WHERE id_state = " + str( oQueryDirecciones:FieldGetByName( "id_state" ) ) )

                        if oQueryState:Open() .and. oQueryState:RecCount() > 0

                           cProvincia     := oQueryState:FieldGetbyName( "name" )

                        end if   

                        /*
                        El primero lo ponemos en la tabla de clientes----------
                        */

                        if lFirst

                           ::oCli:Nif            := oQueryDirecciones:FieldGetByName( "dni" ) //"dni"
                           ::oCli:Domicilio      := oQueryDirecciones:FieldGetByName( "address1" ) + " " + oQueryDirecciones:FieldGetByName( "address2" ) //"address1" - "address2"
                           ::oCli:Poblacion      := oQueryDirecciones:FieldGetByName( "city" ) //"city"
                           ::oCli:CodPostal      := oQueryDirecciones:FieldGetByName( "postcode" ) //"postcode"
                           ::oCli:Provincia      := cProvincia
                           ::oCli:Telefono       := oQueryDirecciones:FieldGetByName( "phone" ) //"phone"
                           ::oCli:Movil          := oQueryDirecciones:FieldGetByName( "phone_mobile" ) //"phone_mobile"

                        end if

                        /*
                        Ahora lo metemos en la tabla de obras------------------
                        */

                        ::oObras:Append()
                        ::oObras:Blank()

                        ::oObras:cCodCli         := cCodCli
                        ::oObras:cCodObr         := "@" + alltrim( str( oQueryDirecciones:FieldGet( 1 ) ) ) //"id_address"
                        
                        if ::TPrestashopConfig:getHideHideExportButton() 
                           ::oObras:cNomObr      := UPPER( oQuery:FieldGetbyName( "lastname" ) ) + ", " + UPPER( oQuery:FieldGetByName( "firstname" ) ) // Last Name - firstname
                        else   
                           ::oObras:cNomObr      := UPPER( oQuery:FieldGetbyName( "firstname" ) ) + Space( 1 ) + UPPER( oQuery:FieldGetByName( "lastname" ) ) //firstname - Last Name
                        end if

                        ::oObras:cDirObr         := oQueryDirecciones:FieldGetByName( "address1" ) + " " + oQueryDirecciones:FieldGetByName( "address2" ) //"address1" - "address2"
                        ::oObras:cPobObr         := oQueryDirecciones:FieldGetByName( "city" ) //"city"
                        ::oObras:cPosObr         := oQueryDirecciones:FieldGetByName( "postcode" ) //"postcode"
                        ::oObras:cPrvObr         := cProvincia
                        ::oObras:cTelObr         := oQueryDirecciones:FieldGetByName( "phone" ) //"phone"
                        ::oObras:cMovObr         := oQueryDirecciones:FieldGetByName( "phone_mobile" ) //"phone_mobile"
                        ::oObras:lDefObr         := lFirst
                        ::oObras:cCodWeb         := oQueryDirecciones:FieldGet( 1 ) //"id_address"

                        ::oObras:Save()

                        oQueryDirecciones:Skip()

                        lFirst                   := .f.

                     end while

                  end if

               end if

               if ::oCli:Save()
                  ::treeSetText( "Cliente " + alltrim( oQuery:FieldGetByName( "ape" ) ) + Space( 1 ) + alltrim( oQuery:FieldGetByName( "firstname" ) ) + " introducido correctamente.", 3 )
               else
                  ::treeSetText( "Error al descargar el cliente: " + alltrim( oQuery:FieldGetByName( "ape" ) ) + Space( 1 ) + alltrim( oQuery:FieldGetByName( "firstname" ) ), 3 )
               end if

            else

               ::treeSetText( "El cliente " + alltrim( oQuery:FieldGetByName( "ape" ) ) + Space( 1 ) + alltrim( oQuery:FieldGetByName( "firstname" ) ) + " ya existe en nuestra base se datos.", 3 )

            end if

            oQuery:Skip()

            ::nMeterProceso++

            lFirst                               := .t.

         end while

      end if

   end if

   oQuery:Free()

   oQuery                                        := nil

Return ( self )

//---------------------------------------------------------------------------//

METHOD AppendMessagePedido( dFecha ) Class TComercio

   local oQueryThead
   local oQueryMessage

   oQueryThead    := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "customer_thread" ) + " WHERE id_order=" + alltrim( str( ::idOrderPrestashop ) ) )

   if oQueryThead:Open()

      if oQueryThead:RecCount() > 0

         oQueryThead:GoTop()

         while !oQueryThead:Eof()

            oQueryMessage    := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "customer_message" ) + " WHERE id_customer_thread=" + alltrim( str( oQueryThead:FieldGet( 1 ) ) ) )

            if oQueryMessage:Open()

               if oQueryMessage:RecCount() > 0

                  oQueryMessage:GoTop()

                  while !oQueryMessage:Eof()

                     ::oPedCliI:Append()
                     ::oPedCliI:Blank()

                     ::oPedCliI:cSerPed   := ::cSeriePedido
                     ::oPedCliI:nNumPed   := ::nNumeroPedido
                     ::oPedCliI:cSufPed   := ::cSufijoPedido
                     ::oPedCliI:dFecInc   := dFecha
                     ::oPedCliI:mDesInc   := oQueryMessage:FieldGetByName( "message" )
                     ::oPedCliI:lAviso    := .t.

                     ::oPedCliI:Save()

                  oQueryMessage:Skip()

                  end while

               end if
               
            end if      

            oQueryThead:Skip()

         end while

      end if   

   end if

Return ( self )

//---------------------------------------------------------------------------//

METHOD EstadoPedidosPrestashop() Class TComercio

   local oQuery

   ::nTotMeter := 0

   /*
   Compruebo datos para el meter-----------------------------------------
   */

   ::oPedCliT:GoTop()
   while !::oPedCliT:Eof()

      if ::oPedCliT:lInternet .and. ::oPedCliT:nEstado != 3
         ::nTotMeter ++
      end if

   ::oPedCliT:Skip()

   end while

   ::oMeterProceso:SetTotal( ::nTotMeter )
   ::nMeterProceso   := 1

   /*
   Modifico los datos y tablas correspondientes--------------------------
   */

   ::treeSetText( "Actualizando el estado de los pedidos", 2 )

   ::oPedCliT:GoTop()
   while !::oPedCliT:Eof()

      if ::oPedCliT:lInternet .and. ::oPedCliT:nEstado != 1

         ::meterProcesoText( "Actualizando estado de pedidos " + alltrim( str( ::nMeterProceso ) ) + " de " + alltrim( str( ::nTotMeter ) ) )

         oQuery                  := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixTable( "order_history" ) + " WHERE id_order=" + alltrim( str( ::oPedCliT:cCodWeb ) ) + " AND id_order_state=5" )

         if oQuery:Open()

            if oQuery:RecCount() == 0

               if TMSCommand():New( ::oCon ):ExecDirect( "INSERT INTO " + ::cPrefixTable( "order_history" ) + " ( id_employee, " + ;
                                                                                         "id_order, " + ;
                                                                                         "id_order_state, " + ;
                                                                                         "date_add )" + ;
                                                                              " VALUES " + ;
                                                                                         "('1', " + ;                                           //id_employee
                                                                                         "'" + alltrim( str( ::oPedCliT:cCodWeb ) ) + "', " + ; //id_order
                                                                                         "'5', " + ;                                            //id_ordder_state
                                                                                         "'" + dtos( GetSysDate() ) + "' )" )                   //date_add

                  ::treeSetText( "Actualizado el estado del pedido " + ::oPedCliT:cSerPed + "/" + alltrim( str( ::oPedCliT:nNumPed ) ) + "/" + ::oPedCliT:cSufPed, 3 )

               else

                  ::treeSetText( "Error al actualizar el estado del pedido " + ::oPedCliT:cSerPed + "/" + alltrim( str( ::oPedCliT:nNumPed ) ) + "/" + ::oPedCliT:cSufPed, 3 )

               end if

            end if

         end if

      end if

   ::oPedCliT:Skip()

   end while

Return ( self )

//---------------------------------------------------------------------------//

METHOD GetParentCategories() CLASS TComercio

   local idCategories := 2

   if !empty( ::oArt:Familia )
      if ::oFam:Seek( ::oArt:Familia )
         if ::oFam:lPubInt
            idCategories := ::oFam:cCodWeb
         end if
      end if
   end if   

Return( idCategories )

//---------------------------------------------------------------------------//

METHOD ActualizaPropiedadesProducts( cCodWeb ) CLASS TComercio

   /*
   Eliminamos todas las comvinaciones------------------------------------------
   */

   ::EliminaPropiedadesProductsPrestashop( cCodWeb )
   ::InsertPropiedadesProductPrestashop( cCodWeb )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD ActualizaStockProductsPrestashop( cCodigoArticulo, cCodigoPropiedad1, cCodigoPropiedad2, cValorPropiedad1, cValorPropiedad2 ) CLASS TComercio

   local oQuery
   local cCommand
   local nTotStock            := 0
   local cCodWebValPr1
   local cCodWebValPr2
   local nIdProductAttribute

   if !::lReady()
      Return .f.
   end if
   
   if ::filesOpen()

      if !empty( cCodigoArticulo )

         if ::oArt:Seek( cCodigoArticulo )

            cCodWebValPr1        := oRetFld( cCodigoPropiedad1 + cValorPropiedad1, ::oTblPro, "cCodWeb" )
            cCodWebValPr2        := oRetFld( cCodigoPropiedad2 + cValorPropiedad2, ::oTblPro, "cCodWeb" )
   
            if ::ConectBBDD()

               do case
                  case empty( cValorPropiedad1 ) .and. empty( cValorPropiedad2 ) //Caso de art�culo sin propiedades

                     /*
                     Actualizamos el stock total de la web---------------------
                     */

                     nTotStock   := ::oStock:nStockArticulo( ::oArt:Codigo, ::TPrestashopConfig:getStore() )

                     cCommand    := "UPDATE " + ::cPrefixTable( "stock_available" ) + " SET " + ;
                                       "quantity='" + alltrim( str( nTotStock ) ) + "' " + ;
                                    "WHERE id_product=" + alltrim( str( ::oArt:cCodWeb ) ) + " AND id_product_attribute=0 "

                     TMSCommand():New( ::oCon ):ExecDirect( cCommand )

                  case !empty( cValorPropiedad1 ) .and. empty( cValorPropiedad2 ) //Caso de art�culo con una sola propiedad

                     /*
                     Actualizamos el stock total de la web---------------------
                     */

                     nTotStock   := ::oStock:nStockArticulo( ::oArt:Codigo, ::TPrestashopConfig:getStore() )

                     cCommand    := "UPDATE " + ::cPrefixTable( "stock_available" ) + " SET " + ;
                                       "quantity='" + alltrim( str( nTotStock ) ) + "' " + ;
                                    "WHERE id_product=" + alltrim( str( ::oArt:cCodWeb ) ) + " AND id_product_attribute=0 "

                     TMSCommand():New( ::oCon ):ExecDirect( cCommand )

                     /*
                     Actualizamos el stock por propiedades---------------------
                     */

                     nTotStock   := ::oStock:nStockAlmacen( cCodigoArticulo, ::TPrestashopConfig:getStore(), cValorPropiedad1 )

                     nIdProductAttribute := ::nIdProductAttribute( ::oArt:cCodWeb, cCodWebValPr1 )

                     if nIdProductAttribute != 0

                        cCommand    := "UPDATE " + ::cPrefixTable( "stock_available" ) + " SET " + ;
                                          "quantity='" + alltrim( str( nTotStock ) ) + "' " + ;
                                       "WHERE id_product=" + alltrim( str( ::oArt:cCodWeb ) ) + " AND id_product_attribute=" + str( nIdProductAttribute )

                        TMSCommand():New( ::oCon ):ExecDirect( cCommand )

                     end if   

                  case !empty( cValorPropiedad1 ) .and. !empty( cValorPropiedad2 ) //Caso de art�culo con dos propiedades

                     /*
                     Actualizamos el stock total de la web---------------------
                     */

                     nTotStock   := ::oStock:nStockArticulo( ::oArt:Codigo, ::TPrestashopConfig:getStore() )

                     cCommand    := "UPDATE " + ::cPrefixTable( "stock_available" ) + " SET " + ;
                                       "quantity='" + alltrim( str( nTotStock ) ) + "' " + ;
                                    "WHERE id_product=" + alltrim( str( ::oArt:cCodWeb ) ) + " AND id_product_attribute=0 "

                     TMSCommand():New( ::oCon ):ExecDirect( cCommand )

                     /*
                     Actualizamos el stock por propiedades---------------------
                     */

                     nTotStock   := ::oStock:nStockAlmacen( cCodigoArticulo, ::TPrestashopConfig:getStore(), cValorPropiedad1, cValorPropiedad2 )

                     nIdProductAttribute := ::nIdProductAttribute( ::oArt:cCodWeb, cCodWebValPr1, cCodWebValPr2 )

                     if nIdProductAttribute != 0

                        cCommand    := "UPDATE " + ::cPrefixTable( "stock_available" ) + " SET " + ;
                                          "quantity='" + alltrim( str( nTotStock ) ) + "' " + ;
                                       "WHERE id_product=" + alltrim( str( ::oArt:cCodWeb ) ) + " AND id_product_attribute=" + str( nIdProductAttribute )

                        TMSCommand():New( ::oCon ):ExecDirect( cCommand )

                     end if   

               end case   

            ::DisconectBBDD()
   
            endif      

         end if   

      end if

      ::filesClose()

   end if

Return .t.

//---------------------------------------------------------------------------//

METHOD nIdProductAttribute( cCodWebArt, cCodWebValPr1, cCodWebValPr2 ) CLASS TComercio

   local nIdProductAttribute  := 0
   local cCommand             := ""
   local oQuery
   local oQuery2
   local lPrp1                := .f.
   local lPrp2                := .f.

   do case
      case !empty( cCodWebValPr1 ) .and. empty( cCodWebValPr2 )

      cCommand          := "SELECT * FROM " + ::cPrefixTable( "product_attribute" ) + ;
                        " WHERE id_product = " + alltrim( str( cCodWebArt ) )

      oQuery            := TMSQuery():New( ::oCon, cCommand )

      if oQuery:Open() .and. oQuery:RecCount() > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            cCommand                      := "SELECT * FROM " + ::cPrefixTable( "product_attribute_combination" ) + ;
                                             " WHERE id_product_attribute = " + alltrim( str( oQuery:FieldGet( 1 ) ) )

            oQuery2                       := TMSQuery():New( ::oCon, cCommand )

               if oQuery2:Open()             .and.;
                  oQuery2:RecCount() == 1    .and.;
                  oQuery2:FieldGet( 1 ) == cCodWebValPr1

                  nIdProductAttribute     := oQuery:FieldGet( 1 )

               end if   

            oQuery:Skip()

         end while

      end if

      case !empty( cCodWebValPr1 ) .and. !empty( cCodWebValPr2 )

      cCommand          := "SELECT * FROM " + ::cPrefixTable( "product_attribute" ) + " WHERE id_product=" + alltrim( str( cCodWebArt ) )

      oQuery            := TMSQuery():New( ::oCon, cCommand )

      if oQuery:Open() .and. oQuery:RecCount() > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            cCommand                      := "SELECT * FROM " + ::cPrefixTable( "product_attribute_combination" ) + " WHERE id_product_attribute=" + alltrim( str( oQuery:FieldGet( 1 ) ) )

            oQuery2                       := TMSQuery():New( ::oCon, cCommand )

               if oQuery2:Open() .and. oQuery2:RecCount() == 2

                  oQuery2:GoTop()

                  while !oQuery2:Eof()

                     if !lPrp1
                        lPrp1 := ( oQuery2:FieldGet( 1 ) == cCodWebValPr1 )
                     end if

                     oQuery2:Skip()

                  end while

                  oQuery2:GoTop()

                  while !oQuery2:Eof()

                     if !lPrp2
                        lPrp2 := ( oQuery2:FieldGet( 1 ) == cCodWebValPr2 )
                     end if

                     oQuery2:Skip()

                  end while

                  if lPrp1 .and. lPrp2
                     nIdProductAttribute     := oQuery:FieldGet( 1 )
                  end if

               end if

            oQuery:Skip()

            lPrp1 := .f.
            lPrp2 := .f.

         end while

      end if

   end case

Return nIdProductAttribute

//---------------------------------------------------------------------------//

METHOD cValidDirectoryFtp( cDirectory ) CLASS TComercio

   local cResult

   /*
   Cambiamos todas las contrabarras por barras normales------------------------
   */

   cResult     := StrTran( alltrim( cDirectory ), "\", "/" )

   /*
   Si empieza por barra la quitamos--------------------------------------------
   */

   if Left( cResult, 1 ) == "/"
      cResult  := Substr( cResult, 2 )
   end if

   /*
   Si termina por barra la quitamos--------------------------------------------
   */

   if Right( cResult, 1 ) == "/"
      cResult  := Substr( cResult, 1, Len( cResult ) - 1 )
   end if

Return ( cResult )

//---------------------------------------------------------------------------//

METHOD CreateDirectoryImagesLocal( cCarpeta ) CLASS TComercio

   local n
   local cResult  := ""

   if ValType( cCarpeta ) == "N"
      cCarpeta    := alltrim( str( cCarpeta ) )
   end if

   for n := 1 to Len( cCarpeta )

      cResult     += "/" + Substr( cCarpeta, n, 1 )
         
      if !isDirectory( ::cDirectoryProduct() + cResult )
         Makedir( ::cDirectoryProduct() + cResult )
      end if

   next

Return ( cResult )

//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//

METHOD prestaShopConnect()

   local oDb
   local lConect     := .f.

   ::treeSetText( 'Intentando conectar con el servidor ' + '"' + ::TPrestashopConfig:getMySqlServer() + '"' + ', el usuario ' + '"' + ::TPrestashopConfig:getMySqlUser()  + '"' + ' y la base de datos ' + '"' + ::TPrestashopConfig:getMySqlDatabase() + '".' , 3 )

   ::oCon            := TMSConnect():New()

   if !::oCon:Connect(  ::TPrestashopConfig:getMySqlServer(),;
                        ::TPrestashopConfig:getMySqlUser(),;
                        ::TPrestashopConfig:getMySqlPassword(),;
                        ::TPrestashopConfig:getMySqlDatabase(),;
                        ::TPrestashopConfig:getMySqlPort() )

      ::treeSetText( 'No se ha podido conectar con la base de datos.' )

   else

      ::treeSetText( 'Se ha conectado con �xito a la base de datos.' , 3 )

      oDb            := TMSDataBase():New( ::oCon, ::TPrestashopConfig:getMySqlDatabase() )

      if empty( oDb )

         ::treeSetText( 'La Base de datos: ' + ::TPrestashopConfig:getMySqlDatabase() + ' no esta activa.', 3 )

      else

         ::nLanguage                            := ::getLanguagePrestashop()
         ::lProductIdColumnImageShop            := ::isProductIdColumnImageShop()
         ::lProductIdColumnProductAttribute     := ::isProductIdColumnProductAttribute()
         ::lProductIdColumnProductAttributeShop := ::isProductIdColumnProductAttributeShop()

         lConect     := .t.

      end if

   end if   

Return ( lConect )

//---------------------------------------------------------------------------//

METHOD prestashopDisConnect()

   if !empty( ::oCon )
      ::oCon:Destroy()
   end if   

   ::treeSetText( 'Base de datos desconectada.', 1 )

return .t.   

//---------------------------------------------------------------------------//

METHOD buildIvaPrestashop( id ) CLASS TComercio

   if aScan( ::aIvaData, {|h| hGet( h, "id" ) == id } ) == 0
      if ::oIva:SeekInOrd( id, "Tipo" ) 
         if ::lSyncAll .or. ::oIva:cCodWeb == 0
            aAdd( ::aIvaData, { "id" => id, "rate" => alltrim( str( ::oIva:TpIva ) ), "name" => rtrim( ::oIva:DescIva ) } )
         end if
      end if 
   end if 

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildFabricantePrestashop( id ) CLASS TComercio

   if aScan( ::aFabricantesData, {|h| hGet( h, "id" ) == id } ) == 0
      if ::oFab:SeekInOrd( id, "cCodFab" ) .and. ::oFab:lPubInt
         if ::lSyncAll .or. ::oFab:cCodWeb == 0
            aAdd( ::aFabricantesData, { "id" => id, "name"  => rtrim( ::oFab:cNomFab ) } )
         end if
      end if 
   end if

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildFamiliaPrestashop( id ) CLASS TComercio

   if aScan( ::aFamiliaData, {|h| hGet( h, "id" ) == id } ) == 0

      if ::oFam:SeekInOrd( id, "cCodFam" ) 
         
         if ::lSyncAll .or. ::oFam:cCodWeb == 0
            aAdd( ::aFamiliaData, { "id"           => id,;
                                    "id_parent"    => ::oFam:cFamCmb,;
                                    "name"         => if( empty( ::oFam:cDesWeb ), alltrim( ::oFam:cNomFam ), alltrim( ::oFam:cDesWeb ) ),;
                                    "description"  => if( empty( ::oFam:cDesWeb ), alltrim( ::oFam:cNomFam ), alltrim( ::oFam:cDesWeb ) ),;
                                    "link_rewrite" => cLinkRewrite( if( empty( ::oFam:cDesWeb ), alltrim( ::oFam:cNomFam ), alltrim( ::oFam:cDesWeb ) ) ),;
                                    "image"        => ::oFam:cImgBtn } )
         end if

         if !empty( ::oFam:cFamCmb )
            ::buildFamiliaPrestashop( ::oFam:cFamCmb )
         end if

      end if 

   end if

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildArticuloPrestashop( id ) CLASS TComercio

   local hImagesArticulos     := {}

   if aScan( ::aArticuloData, {|h| hGet( h, "id" ) == id } ) != 0
      Return ( self )
   end if 

   // Recopilar info de imagenes-----------------------------------------

   hImagesArticulos           := ::buildImagesArticuloPrestashop( id )

   // Rellenamos el Hash-------------------------------------------------

   aAdd( ::aArticuloData, {"id"                   => id,;
                           "name"                  => alltrim( ::oArt:Nombre ),;
                           "id_manufacturer"       => ::oArt:cCodFab ,;
                           "id_tax_rules_group"    => ::oArt:TipoIva ,;
                           "id_category_default"   => ::oArt:Familia ,;
                           "price"                 => if( ::oArtDiv:Seek( ::oArt:Codigo ), 0, ::buildPrecioArtitulo() ) ,;
                           "reference"             => ::oArt:Codigo ,;
                           "weight"                => ::oArt:nPesoKg ,;
                           "description"           => if( !empty( ::oArt:mDesTec ), ::oArt:mDesTec, ::oArt:Nombre ) ,; 
                           "description_short"     => alltrim( ::oArt:Nombre ) ,;
                           "link_rewrite"          => cLinkRewrite( ::oArt:Nombre ),;
                           "meta_title"            => alltrim( ::oArt:cTitSeo ) ,;
                           "meta_description"      => alltrim( ::oArt:cDesSeo ) ,;
                           "meta_keywords"         => alltrim( ::oArt:cKeySeo ) ,;
                           "lPubPor"               => ::oArt:lPubPor,;
                           "cImagen"               => ::oArt:cImagen,;
                           "lSbrInt"               => ::oArt:lSbrInt,;
                           "nDtoInt1"              => ::oArt:nDtoInt1,;
                           "nImpInt1"              => ::buildPrecioArtitulo(),;
                           "aImages"               => hImagesArticulos } )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildImagesArticuloPrestashop( id ) CLASS TComercio

   local aImgToken      := {}
   local cImgToken      := ""
   local cImagen
   local aImages        := {}
   local nOrdAntImg
   local nOrdAntDiv     := ::oArtDiv:OrdSetFocus( "cCodigo" )

   /*
   Pasamos las im�genes de los art�culos por propiedades-----------------------
   */

   if ::oArtDiv:Seek( id )

      while ::oArtDiv:cCodArt == id .and. !::oArtDiv:Eof()

         if !empty( ::oArtDiv:mImgWeb )

            aImgToken   := hb_atokens( ::oArtDiv:mImgWeb, "," )

            for each cImgToken in aImgToken

               if file( cImgToken )
                  if !empty( cImgToken ) .and. ascan( aImages, {|a| hGet( a, "name" ) == cImgToken } ) == 0
                     aadd( aImages, { "name" => cImgToken, "lDefault"  => oRetFld( cImgToken, ::oArtImg, "lDefImg", "cImgArt" ) } )
                  end if
               else
                  ::treeSetText( "El fichero de imagen " + cImgToken + " no existe." ) 
               end if 

            next

         end if

         ::oArtDiv:Skip()

      end while

   end if

   /*
   Pasamos las im�genes de la tabla de art�culos-------------------------------
   */

   if len( aImages ) == 0

      nOrdAntImg     := ::oArtImg:OrdSetFocus( "cCodArt" )

      if ::oArtImg:Seek( id )

         while ::oArtImg:cCodArt == id .and. !::oArtImg:Eof()

            cImagen  := alltrim( ::oArtImg:cImgArt )

            if file( cImagen )
               if ascan( aImages, {|a| hGet( a, "name" ) == cImagen } ) == 0
                  aadd( aImages, { "name" => cImagen, "lDefault" => ::oArtImg:lDefImg } )
               end if   
            else
               ::treeSetText( "El fichero de imagen " + cImgToken + " no existe." ) 
            end if 

         ::oArtImg:Skip()

         end while

      end if 

      ::oArtImg:OrdSetFocus( nOrdAntImg )

   end if

   ::oArtDiv:OrdSetFocus( nOrdAntDiv )

   /*
   Nos aseguramos de que por lo menos una im�gen sea por defecto---------------
   */

   if Len( aImages ) != 0
      if aScan( aImages, {|a| hGet( a, "lDefault" ) == .t. } ) == 0
         hSet( aImages[1], "lDefault", .t. )
      end if   
   end if   

Return ( aImages )

//---------------------------------------------------------------------------//

METHOD buildPrecioArtitulo() CLASS TComercio

   local nPrecio

   if ::oArt:lIvaInc
      nPrecio  := Round( ::oArt:nImpIva1 / ( ( nIva( ::oIva:cAlias, ::oArt:TipoIva ) / 100 ) + 1 ), 6 )
   else
      nPrecio  := ::oArt:pVtaWeb
   end if

Return ( nPrecio )

//---------------------------------------------------------------------------//

METHOD buildPropiedadesPrestashop( id ) CLASS TComercio

   /*
   Primera propiedad--------------------------------------------------------
   */

   if ::oPro:SeekInOrd( ::oArt:cCodPrp1 )

      if ::lSyncAll .or. ::oPro:cCodWeb == 0
      
         if aScan( ::aPropiedadesCabeceraData, {|h| hGet( h, "id" ) == ::oPro:cCodPro } ) == 0

            aAdd( ::aPropiedadesCabeceraData, { "id"          => ::oPro:cCodPro,;
                                                "name"        => if( empty( ::oPro:cNomInt ), alltrim( ::oPro:cDesPro ), alltrim( ::oPro:cNomInt ) ),;
                                                "lColor"      => ::oPro:lColor } )

         end if

      end if

   end if

   /*
   Segunda propiedad--------------------------------------------------------
   */

   if ::oPro:SeekInOrd( ::oArt:cCodPrp2 )

      if ::lSyncAll .or. ::oPro:cCodWeb == 0

         if aScan( ::aPropiedadesCabeceraData, {|h| hGet( h, "id" ) == ::oPro:cCodPro } ) == 0
      
            aAdd( ::aPropiedadesCabeceraData, { "id"          => ::oPro:cCodPro,;
                                                "name"        => if( empty( ::oPro:cNomInt ), alltrim( ::oPro:cDesPro ), alltrim( ::oPro:cNomInt ) ),;
                                                "lColor"      => ::oPro:lColor } )

         end if

      end if

   end if

   /*
   L�neas de propiedades de un art�culo-------------------------------------
   */

   if ::oArtDiv:Seek( ::oArt:Codigo )

      while ::oArtDiv:cCodArt == ::oArt:Codigo .and. !::oArtDiv:Eof()

         if ::oTblPro:SeekInOrd( ::oArtDiv:cCodPr1 + ::oArtDiv:cValPr1, "cCodPro" )

            if ::lSyncAll .or. ::oTblPro:cCodWeb == 0

               if aScan( ::aPropiedadesLineasData, {|h| hGet( h, "id" ) == ::oTblPro:cCodTbl .and. hGet( h, "idparent" ) == ::oTblPro:cCodPro } ) == 0
      
                  aAdd( ::aPropiedadesLineasData, {"id"          => ::oTblPro:cCodTbl,;
                                                   "idparent"    => ::oTblPro:cCodPro,; 
                                                   "name"        => alltrim( ::oTblPro:cDesTbl ),;
                                                   "color"       => alltrim( RgbToRgbHex( ::oTblPro:nColor) ) } )

               end if

            end if

         end if

         if ::oTblPro:SeekInOrd( ::oArtDiv:cCodPr2 + ::oArtDiv:cValPr2, "cCodPro" )

            if ::lSyncAll .or. ::oTblPro:cCodWeb == 0

               if aScan( ::aPropiedadesLineasData, {|h| hGet( h, "id" ) == ::oTblPro:cCodTbl .and. hGet( h, "idparent" ) == ::oTblPro:cCodPro } ) == 0
      
                  aAdd( ::aPropiedadesLineasData, {"id"          => ::oTblPro:cCodTbl,;
                                                   "idparent"    => ::oTblPro:cCodPro,; 
                                                   "name"        => alltrim( ::oTblPro:cDesTbl ),;
                                                   "color"       => alltrim( RgbToRgbHex( ::oTblPro:nColor) ) } )

               end if

            end if

         end if

         ::oArtDiv:Skip()

      end while

   end if

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildInformacion() CLASS TComercio

   ::buildIvaPrestashop(         ::oArt:TipoIva )
   ::buildFabricantePrestashop(  ::oArt:cCodFab )
   ::buildFamiliaPrestashop(     ::oArt:Familia )
   ::buildPropiedadesPrestashop( ::oArt:Codigo )
   ::buildArticuloPrestashop(    ::oArt:Codigo )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildSubirInformacion() CLASS TComercio

   local hIvaData
   local hFabricantesData
   local hFamiliaData
   local hArticuloData
   local hPropiedadesCabData
   local hPropiedadesLinData

   // Subimos los tipos de IVA----------------------------------------------

   ::meterProcesoSetTotal( len(::aIvaData) )

   for each hIvaData in ::aIvaData

      ::buildInsertIvaPrestashop( hIvaData )

      ::meterProcesoText( "Subiendo impuestos " + alltrim(str(hb_enumindex())) + " de " + alltrim(str(len(::aIvaData))) )

   next

   // Subimos fabricantes---------------------------------------------------

   if ::TPrestashopConfig:getSyncronizeManufacturers()

      ::meterProcesoSetTotal( len(::aFabricantesData) )

      for each hFabricantesData in ::aFabricantesData

         ::buildInsertFabricantesPrestashop( hFabricantesData )

         ::meterProcesoText( "Subiendo fabricantes " + alltrim(str(hb_enumindex())) + " de " + alltrim(str(len(::aFabricantesData))) )

      next 

   end if 

   // Subimos familias------------------------------------------------------

   ::meterProcesoSetTotal( len(::aFamiliaData) )

   for each hFamiliaData in ::aFamiliaData

      ::buildInsertCategoriesPrestashop( hFamiliaData )

      ::meterProcesoText( "Subiendo categorias " + alltrim(str(hb_enumindex())) + " de " + alltrim(str(len(::aFamiliaData))) )

   next 

   /*
   Actualizamos padres de las familias-----------------------------------
   */

   ::meterProcesoSetTotal( len(::aFamiliaData) )

   for each hFamiliaData in ::aFamiliaData

      ::buildActualizaCaterogiaPadrePrestashop( hFamiliaData )

      ::meterProcesoText( "Relacionando categorias " + alltrim(str(hb_enumindex())) + " de " + alltrim(str(len(::aFamiliaData))) )

   next

   /*
   Recalculamos las posiciones de las categorias-------------------------
   */

   ::meterProcesoText( "Recalculando posiciones de categorias" )

   ::buildRecalculaPosicionesCategoriasPrestashop()

   /*
   Subimos las cabeceras de propiedades necesarias-----------------------
   */

   for each hPropiedadesCabData in ::aPropiedadesCabeceraData
      ::buildInsertPropiedadesPrestashop( hPropiedadesCabData )
   next

   /*
   Subimos las Lineas de propiedades necesarias--------------------------
   */

   ::meterProcesoSetTotal( len(::aPropiedadesLineasData) )

   for each hPropiedadesLinData in ::aPropiedadesLineasData

      ::buildInsertLineasPropiedadesPrestashop( hPropiedadesLinData, hb_enumindex() )

      ::meterProcesoText( "Subiendo propiedad " + alltrim(str(hb_enumindex())) + " de " + alltrim(str(len(::aPropiedadesLineasData))) )

   next
 
   /*
   Subimos los art�culos-------------------------------------------------
   */

   ::meterProcesoSetTotal( len(::aArticuloData) )
   
   for each hArticuloData in ::aArticuloData

      ::buildInsertProductsPrestashop( hArticuloData )
   
      ::meterProcesoText( "Subiendo art�culo " + alltrim(str(hb_enumindex())) + " de " + alltrim(str(len(::aArticuloData))) )
   
   next

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildProductPrestashop( idProduct, lShowDialogWait ) CLASS TComercio

   lShowDialogWait      := .f.

   if lShowDialogWait
      ::lShowDialogWait()
   end if   

   ::MeterTotalSetTotal( 8 )

   if !::filesOpen()
      Return ( self )
   end if 

   ::MeterTotalText( "Elaborando informaci�n de art�culos." )

   ::buildInitData()

   // Elabora la inormacion para uno o varios articulos---------------------

   if empty( idProduct )

      ::oArt:GoTop()
      while !::oArt:Eof()

         if ::productInCurrentWeb()
            ::buildInformacion()
         end if 

         ::oArt:Skip()

      end while

   else

      if ::oArt:Seek( idProduct ) .and. ::productInCurrentWeb()
         ::buildInformacion()
      end if

   end if   

   // Conectamos con la bases de datos de prestaShop------------------------

   ::MeterTotalText( "Conectando con la base de datos." )

   if ::prestaShopConnect()

      // Eliminamos las bases de datos--------------------------------------

      ::MeterTotalText( "Eliminando la bases de datos." )

      if ::lSyncAll
         ::buildEliminaTablas()
      end if

      if !empty( idProduct )
         ::buildDeleteProductPrestashop( idProduct )
      end if 

      // Subimos la informacion a mysql-------------------------------------

      ::MeterTotalText( "Subiendo la informaci�n." )

      ::buildSubirInformacion()

      // Pasamos las im�genes de los art�culos a prestashop-----------------

      ::MeterTotalText( "Generando imagenes." )

      ::buildImagenes()

      // Pasamos las im�genes de los art�culos a prestashop-----------------

      ::MeterTotalText( "Subiendo imagenes." )

      ::buildSubirImagenes()

      // Desconectamos mysql------------------------------------------------

      ::MeterTotalText( "Desconectando bases de datos." )

      ::prestashopDisConnect()  
      
   end if  

   ::filesClose()

   if lShowDialogWait
      ::lHideDialogWait()
   end if   

   ::MeterTotalText( "Proceso finalizado." )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildInsertIvaPrestashop( hIvaData ) CLASS TComercio

   local cCommand          := ""  
   local nCodigoWeb        := 0
   local nCodigoGrupoWeb   := 0

   cCommand := "INSERT INTO " + ::cPreFixtable( "tax") + ;
                  "( rate, " + ;
                  "active ) " + ;
               "VALUES " + ;
                  "('" + hGet( hIvaData, "rate" ) + "', " + ;  // rate
                  "'1' )"                                      // active

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      nCodigoWeb           := ::oCon:GetInsertId()
      ::buildTextOk( hGet( hIvaData, "name" ), ::cPrefixTable( "tax" ) )
   else
      ::buildTextCancel( hGet( hIvaData, "name" ), ::cPrefixTable( "tax" ) )
   end if

   /*
   Insertamos un tipo de IVA nuevo en la tabla tax_lang-----------------
   */

   cCommand := "INSERT INTO " + ::cPrefixTable( "tax_lang" ) + "( " +;
                  "id_tax, " + ;
                  "id_lang, " + ;
                  "name )" + ;
               " VALUES " + ;
                  "('" + str( nCodigoWeb ) + "', " + ;         // id_tax
                  "'" + str( ::nLanguage ) + "', " + ;         // id_lang
                  "'" + ::oCon:Escapestr( hGet( hIvaData, "name" ) ) + "' )"      // name

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::buildTextOk( hGet( hIvaData, "name" ), ::cPrefixTable( "tax_lang" ) )
   else
      ::buildTextCancel( hGet( hIvaData, "name" ), ::cPrefixTable( "tax_lang" ) )
   end if

   /*
   Insertamos un tipo de IVA nuevo en la tabla tax_rule_group-----------------
   */

   cCommand := "INSERT INTO "+ ::cPrefixTable( "tax_rules_group" ) + "( " + ;
                  "name, " + ;
                  "active )" + ;
               " VALUES " + ;
                  "('" + ::oCon:Escapestr( hGet( hIvaData, "name" ) ) + "', " + ; // name
                  "'1' )"                                      // active

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      nCodigoGrupoWeb           := ::oCon:GetInsertId()
      ::buildTextOk( hGet( hIvaData, "name" ), ::cPrefixTable( "tax_rule_group" ) )
   else
      ::buildTextError( hGet( hIvaData, "name" ), ::cPrefixTable( "tax_rule_group" ) )
   end if

   /*
   Insertamos un tipo de IVA nuevo en la tabla tax_rule------------------------
   */

   cCommand := "INSERT INTO " + ::cPrefixTable( "tax_rule" ) + "( " +;
                  "id_tax_rules_group, " + ;
                  "id_country, " + ;
                  "id_tax )" + ;
               " VALUES " + ;
                  "('" + str( nCodigoGrupoWeb ) + "', " + ;  // id_tax_rules_group
                  "'6', " + ;                                // id_country - 6 es el valor de Espa�a
                  "'" + str( nCodigoWeb ) + "' )"            // id_tax

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::buildTextError( hGet( hIvaData, "name" ), ::cPrefixTable( "tax_rule" ) )
   end if

   /*
   Insertamos un tipo de IVA nuevo en la tabla tax_rule------------------------
   */

   cCommand := "INSERT INTO " + ::cPrefixTable( "tax_rules_group_shop" ) + "( " +;
                  "id_tax_rules_group, " + ;
                  "id_shop )" + ;
               " VALUES " + ;
                  "('" + str( nCodigoGrupoWeb ) + "', " + ;
                  "'1' )"

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::buildTextError( hGet( hIvaData, "name" ), ::cPrefixTable( "tax_rules_group_shop" ) )
   end if

   // Guardo referencia a la web-----------------------------------------------

   if ::oIva:SeekInOrd( hGet( hIvaData, "id" ), "Tipo" )

      ::oIva:fieldPutByName( "cCodWeb", nCodigoWeb )
      ::oIva:fieldPutByName( "cGrpWeb", nCodigoGrupoWeb )

   end if

Return ( nCodigoweb )

//---------------------------------------------------------------------------//

METHOD buildInsertFabricantesPrestashop( hFabricantesData ) CLASS TComercio

   local oImagen
   local cCommand    := ""    
   local nCodigoWeb  := 0
   local nParent     := 1

   /*
   Insertamos un fabricante nuevo en las tablas de prestashop-----------------
   */

   cCommand := "INSERT INTO " + ::cPrefixTable( "manufacturer" ) + "( " +;
                  "name, " + ;
                  "date_add, " + ;
                  "date_upd, " + ;
                  "active )" + ;
               " VALUES " + ;
                  "('" + hGet( hFabricantesData, "name" ) + "', " + ;//name
                  "'" + dtos( GetSysDate() ) + "', " + ;             //date_add
                  "'" + dtos( GetSysDate() ) + "', " + ;             //date_upd
                  "'1' )"                                            //active

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      nCodigoWeb           := ::oCon:GetInsertId()
   else
      ::treeSetText( "Error al insertar el fabricante " + hGet( hFabricantesData, "name" ) + " en la tabla " + ::cPreFixtable( "manufacturer" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "manufacturer_shop" ) + "( "+ ;
                  "id_manufacturer, " + ;
                  "id_shop )" + ;
               " VALUES " + ;
                  "('" + alltrim( str( nCodigoWeb ) ) + "', " + ;     // id_manufacturer
                  "'1' )"                                             // id_shop                  


   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar el fabricante " + hGet( hFabricantesData, "name" ) + " en la tabla" + ::cPreFixtable( "manufacturer_shop" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPreFixtable( "manufacturer_lang" ) + "( " +;
                  "id_manufacturer, " + ;
                  "id_lang )" + ;
               " VALUES " + ;
                  "('" + alltrim( str( nCodigoWeb ) ) + "', " + ;    //id_manufacturer
                  "'" + str( ::nLanguage ) + "' )"                   //id_lang

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar el fabricante " + hGet( hFabricantesData, "name" ) + " en la tabla" + ::cPreFixtable( "manufacturer_lang" ), 3 )
   end if

   // Guardo referencia a la web-----------------------------------------------

   if ::oFab:SeekInOrd( hGet( hFabricantesData, "id" ), "cCodFab" )
      ::oFab:fieldPutByName( "cCodWeb", nCodigoWeb )
   end if

return nCodigoWeb

//---------------------------------------------------------------------------//

METHOD buildInsertCategoriesPrestashop( hFamiliaData ) CLASS TComercio

   local oImagen
   local oCategoria
   local nCodigoWeb           := 0
   local nParent              := 2
   local cCommand             := ""

   ::cTextoWait( "A�adiendo categor�a: " + hGet( hFamiliaData, "name" ) )

   //Insertamos una familia nueva en las tablas de prestashop-----------------

   cCommand := "INSERT INTO " + ::cPrefixTable( "category" ) + "( " + ;
                  "id_parent, " + ;
                  "level_depth, " + ;
                  "nleft, " + ;
                  "nright, " + ;
                  "active, " + ;
                  "date_add,  " + ;
                  "date_upd, " + ;
                  "position " + ;
               ") VALUES ( '" + ;
                  str( nParent ) + "', " + ;
                  "'2', " + ;
                  "'0', " + ;
                  "'0', " + ;
                  "'1', " + ;
                  "'" + dtos( GetSysDate() ) + "', " + ;
                  "'" + dtos( GetSysDate() ) + "', " + ;
                  "'0' ) "

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )

      nCodigoWeb           := ::oCon:GetInsertId()

      ::nNumeroCategorias++

      //Metemos en un array para luego calcular las coordenadas---------------

      oCategoria                       := SCategoria()
      oCategoria:id                    := nCodigoWeb
      oCategoria:idParent              := nParent
      oCategoria:nTipo                 := 2

      aAdd( ::aCategorias, oCategoria )

      ::treeSetText( "He insertado la familia " + hGet( hFamiliaData, "name" ) + " correctamente en la tabla " + ::cPrefixTable( "category" ), 3 )

   else
      ::treeSetText( "Error al insertar la familia " + hGet( hFamiliaData, "name" ) + " en la tabla " + ::cPrefixTable( "category" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + "( " + ;
                  "id_category, " + ;
                  "id_lang, " + ;
                  "name, " + ;
                  "description, " + ;
                  "link_rewrite, " + ;
                  "meta_title, " + ;
                  "meta_keywords, " + ;
                  "meta_description" + ;
                  " ) VALUES ( '" + ;
                  str( nCodigoWeb ) + "', '" +;
                  str( ::nLanguage ) + "', '" + ;
                  hGet( hFamiliaData, "name" ) + "', '" + ;
                  hGet( hFamiliaData, "description" ) + "', '" + ;
                  hGet( hFamiliaData, "link_rewrite" ) + "', " + ;
                  "'', " + ;
                  "'', " + ;
                  "'' )"

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar la familia " + hGet( hFamiliaData, "name" ) + " en la tabla " + ::cPrefixTable( "category_lang" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + "( id_category, id_shop, position ) VALUES ( '" + str( nCodigoWeb ) + "', '1', '0' )"

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar la categor�a inicio en " + ::cPrefixTable( "category_group" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( id_category, id_group ) VALUES ( '" + str( nCodigoWeb ) + "', '1' )"

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar la familia " + hGet( hFamiliaData, "name" ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( id_category, id_group ) VALUES ( '" + str( nCodigoWeb ) + "', '2' )"

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar la familia " + hGet( hFamiliaData, "name" ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( id_category, id_group ) VALUES ( '" + str( nCodigoWeb ) + "', '3' )"

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar la familia " + hGet( hFamiliaData, "name" ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

   SysRefresh()

   //Insertamos un registro en las tablas de im�genes----------------------

   if !empty( hGet( hFamiliaData, "image" ) )

      //A�adimos la imagen al array para pasarla a prestashop--------------

      oImagen                       := SImagen()
      oImagen:cNombreImagen         := hGet( hFamiliaData, "image" )
      oImagen:nTipoImagen           := tipoCategoria
      oImagen:cPrefijoNombre        := alltrim( str( nCodigoWeb ) )

      ::AddImages( oImagen )

   end if

   // Guardo referencia a la web-----------------------------------------------

   if ::oFam:SeekInOrd( hGet( hFamiliaData, "id" ), "cCodFam" )
      ::oFam:fieldPutByName( "cCodWeb", nCodigoWeb )
   end if

return nCodigoWeb

//---------------------------------------------------------------------------//

METHOD buildActualizaCaterogiaPadrePrestashop( hFamiliaData ) CLASS TComercio

   local lReturn  := .f.
   local cCommand := ""
   local nParent  := 2

   /*
   Actualizamos las familias padre en prestashop-------------------------------
   */

   nParent           := oRetFld( hGet( hFamiliaData, "id_parent" ), ::oFam, "cCodWeb" )
      
   if nParent == 0
      nParent        := 2
   end if

   if ::oFam:SeekInOrd( hGet( hFamiliaData, "id" ), "cCodFam" )

      cCommand       := "UPDATE " + ::cPrefixTable( "category" ) + " SET " + ;
                           "id_parent='" + alltrim( str( nParent ) ) + "' " +;
                           "WHERE id_category=" + alltrim( str( ::oFam:cCodWeb ) )

      ::cTextoWait( cCommand )

      lReturn        := TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   end if

   SysRefresh()

Return lReturn

//---------------------------------------------------------------------------//

METHOD buildRecalculaPosicionesCategoriasPrestashop() CLASS TComercio

   local nPos              := 0
   local nContador         := 2
   local oCategoria
   local oCat
   local oCat2
   local oQuery         
   local nTotalCategory
   local nLeft             := 0  
   local nRight            := 0

   /*
   Recorremos el Query con la consulta-----------------------------------------
   */

   oQuery               := TMSQuery():New( ::oCon, 'SELECT * FROM ' + ::cPrefixTable( "category" ) )
   if oQuery:Open()

      nTotalCategory    := oQuery:RecCount()

      if nTotalCategory > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            do case
               case oQuery:FieldGet( 1 ) == 1

                  if !TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "category" ) + " SET nLeft='1', nRight='" + alltrim( str( nTotalCategory * 2 ) ) + "' WHERE id_category=1" )
                     ::treeSetText( "Error al actualizar el grupo de familia en la tabla category", 3 )
                  end if

               case oQuery:FieldGet( 1 ) == 2

                  if !TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "category" ) + " SET nLeft='2', nRight='" + alltrim( str( ( nTotalCategory * 2 ) -1 ) ) + "' WHERE id_category=2" )
                     ::treeSetText( "Error al actualizar el grupo de familia en la tabla category", 3 )
                  end if

               otherwise

                  nLeft    := ++nContador
                  nRight   := ++nContador

                  if !TMSCommand():New( ::oCon ):ExecDirect( "UPDATE " + ::cPrefixTable( "category" ) + " SET nLeft='" + alltrim( str( nLeft ) ) + "', nRight='" + alltrim( str( nRight ) ) + "' WHERE id_category=" + alltrim( str( oQuery:FieldGet( 1 ) ) ) )
                     ::treeSetText( "Error al actualizar el grupo de familia en la tabla category", 3 )
                  end if

            end case               

            oQuery:Skip()

         end while

      else 

         ::meterProcesoText( "No hay elementos en la categor�a" )

      end if

   else 

      ::meterProcesoText( "Error al ejecutar " + "SELECT * FROM " + ::cPrefixTable( "category" ) )

   end if

return ( .t. )

//---------------------------------------------------------------------------//

METHOD BuildInsertProductsPrestashop( hArticuloData ) CLASS TComercio

   local nCodigoWeb           := 0
   local nCodigoImagen        := 0
   local oImagen
   local nOrdAnt
   local nPosition            := 1
   local nCodigoPropiedad     := 0
   local aPropiedades1        := {}
   local aPropiedades2        := {}
   local aPropiedad1
   local aPropiedad2
   local nPrecio              := 0
   local nParent              
   local cCommand             := ""
   local nTotStock
   local nOrdArtDiv           

   /*
   ----------------------------------------------------------------------------
   INSERTAMOS EL ART�CULO EN TODAS LAS TABLAS DE PRESTASHOP--------------------
   ----------------------------------------------------------------------------
   */

   nParent                    := ::buildGetParentCategories( hGet( hArticuloData, "id_category_default" ) )
   nOrdArtDiv                 := ::oArtDiv:OrdSetFocus( "cCodArt" )

   ::cTextoWait( "A�adiendo art�culo: " + alltrim( ::oArt:Nombre ) )

   /*
   Vemos el precio del art�culo------------------------------------------------
   */

   ::oArtDiv:OrdSetFocus( nOrdArtDiv )

   cCommand    := "INSERT INTO " + ::cPrefixTable( "product" ) + ;
                     " ( id_manufacturer, " + ;
                     "id_tax_rules_group, " + ;
                     "id_category_default, " + ;
                     "id_shop_default, " + ;
                     "quantity, " + ;
                     "minimal_quantity, " + ;
                     "price, " + ;
                     "reference, " + ;
                     "weight, " + ;
                     "active, " + ;
                     "date_add, " + ;
                     "date_upd )" + ;
                  " VALUES " + ;
                     "('" + alltrim( str( oRetFld( hGet( hArticuloData, "id_manufacturer" ), ::oFab, "cCodWeb", "cCodFab" ) ) ) + "', " + ; //id_manufacturer
                     "'" + alltrim( str( oRetFld( hGet( hArticuloData, "id_tax_rules_group" ), ::oIva, "CGRPWEB", "TIPO" ) ) ) + "', " + ;     //id_tax_rules_group  - tipo IVA
                     "'" + alltrim( str( nParent ) ) + "', " + ;                                                  //id_category_default
                     "'1', " + ;                                                                                  //id_shop_default
                     "'1', " + ;                                                                                  //quantity
                     "'1', " + ;                                                                                  //minimal_quantity
                     "'" + alltrim( str( hGet( hArticuloData, "price" ) ) ) + "', " + ;                           //price
                     "'" + alltrim( hGet( hArticuloData, "id" ) ) + "', " + ;                                     //reference
                     "'" + alltrim( str( hGet( hArticuloData, "weight" ) ) ) + "', " + ;                          //weight
                     "'1', " + ;                                                                                  //active
                     "'" + dtos( GetSysDate() ) + "', " + ;                                                       //date_add
                     "'" + dtos( GetSysDate() ) + "' )"

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )                                                                                                             //date_upd
      nCodigoWeb           := ::oCon:GetInsertId()
   else
      ::treeSetText( "Error al insertar el art�culo " + hGet( hArticuloData, "name" ) + " en la tabla " + ::cPrefixTable( "product" ), 3 )
   end if

   /*
   Insertamos un art�culo nuevo en la tabla category_product----------------
    */

   cCommand    := "INSERT INTO " + ::cPrefixTable( "category_product" ) + ;
                     " ( id_category, " + ;
                     "id_product )" + ;
                  " VALUES " + ;
                     "('" + alltrim( str( Max( nParent, 1 ) ) ) + "', " + ;
                     "'" + str( nCodigoWeb ) + "' )"

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar el art�culo " + hGet( hArticuloData, "name" ) + " en la tabla " + ::cPrefixTable( "category_product" ), 3 )
   end if

   /*
   Insertamos un art�culo como producto destacado------------------------------
   */

   if hGet( hArticuloData, "lPubPor" )

      cCommand    := "INSERT INTO " + ::cPrefixTable( "category_product" ) + ;
                     " ( id_category, " + ;
                     "id_product )" + ;
                  " VALUES " + ;
                     "('2', " + ;
                     "'" + str( nCodigoWeb ) + "' )"
   
      if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
         ::treeSetText( "Error al insertar el art�culo " + hGet( hArticuloData, "name" ) + " como producto destacado", 3 )
      end if

   end if

   /*
   Insertamos un art�culo nuevo en la tabla category_shop-------------------
   */

   cCommand    := "INSERT INTO " + ::cPrefixTable( "product_shop" ) + ;
                     " ( id_product, " + ;
                     "id_shop, " + ;
                     "id_category_default, " + ;
                     "id_tax_rules_group, " + ;
                     "on_sale, " + ;
                     "price, " + ;
                     "active, " + ;
                     "date_add, " + ;
                     "date_upd )" + ;
                  " VALUES " + ;
                     "('" + str( nCodigoWeb ) + "', " + ;
                     "'1', " + ;
                     "'" + alltrim( str( nParent ) ) + "', " + ;
                     "'" + alltrim( str( oRetFld( hGet( hArticuloData, "id_tax_rules_group" ), ::oIva, "CGRPWEB", "TIPO" ) ) ) + "', " + ;
                     "'0', " + ;
                     "'" + alltrim( str( hGet( hArticuloData, "price" ) ) ) + "', " + ;
                     "'1', " + ;
                     "'" + dtos( GetSysDate() ) + "', " + ;
                     "'" + dtos( GetSysDate() ) + "' )"

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar el art�culo " + hGet( hArticuloData, "name" ) + " en la tabla " + ::cPrefixTable( "product_shop" ), 3 )
   end if

   /*
   Insertamos un art�culo nuevo en la tabla product_lang--------------------
   */

   cCommand    := "INSERT INTO " + ::cPrefixTable( "product_lang" ) +;
                     " ( id_product, " + ;
                     "id_lang, " + ;
                     "description, " + ;
                     "description_short, " + ;
                     "link_rewrite, " + ;
                     "meta_title, " + ;
                     "meta_description, " + ;
                     "meta_keywords, " + ;
                     "name, " + ;
                     "available_now, " + ;
                     "available_later )" + ;
                  " VALUES " + ;
                     "('" + str( nCodigoWeb ) + "', " + ;                           // id_product
                     "'" + str( ::nLanguage ) + "', " + ;                           // id_lang
                     "'" + ::oCon:Escapestr( hGet( hArticuloData, "description" ) ) + "', " + ;        // description
                     "'" + hGet( hArticuloData, "description_short" ) + "', " + ;   // description_short
                     "'" + hGet( hArticuloData, "link_rewrite" ) + "', " + ;        // link_rewrite
                     "'" + hGet( hArticuloData, "meta_title" ) + "', " + ;          // Meta_t�tulo
                     "'" + hGet( hArticuloData, "meta_description" ) + "', " + ;    // Meta_description
                     "'" + hGet( hArticuloData, "meta_keywords" ) + "', " + ;       // Meta_keywords
                     "'" + hGet( hArticuloData, "name" ) + "', " + ;                // name
                     "'En stock', " + ;                                             // avatible_now
                     "'' )"

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar el art�culo " + hGet( hArticuloData, "name" ) + " en la tabla " + ::cPrefixTable( "product_lang" ), 3 )
   end if

   /*
   Metemos el stock total del art�culo-----------------------------------------
   */

   nTotStock   := ::oStock:nStockArticulo( hGet( hArticuloData, "id" ), ::TPrestashopConfig:getStore() )

   cCommand    :=    "INSERT INTO " + ::cPrefixTable( "stock_available" ) + " ( " + ;
                        "id_product, " + ;
                        "id_product_attribute, " + ;
                        "id_shop, " + ;
                        "id_shop_group, " + ;
                        "quantity, " + ;
                        "depends_on_stock, " + ;
                        "out_of_stock )" + ;
                     " VALUES " + ;
                        "('" + alltrim( str( nCodigoWeb ) ) + "', " + ;
                        "'0', " + ;   
                        "'1', " + ;
                        "'0', " + ;
                        "'" + alltrim( str( nTotStock ) ) + "', " + ;
                        "'0', " + ;
                        "'2' )"

      if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
         ::treeSetText( "Error al insertar el art�culo " + hGet( hArticuloData, "name" ) + " en la tabla " + ::cPrefixTable( "stock_available" ), 3 )
      end if

   SysRefresh()

   if ::oArt:SeekInOrd( hGet( hArticuloData, "id" ), "Codigo" )
      ::oArt:fieldPutByName( "cCodWeb", nCodigoWeb )
   end if

   ::cTextoWait( "A�adiendo im�genes art�culo: " + hGet( hArticuloData, "name" ) )
   ::buildInsertImageProductsPrestashop( hArticuloData, nCodigoWeb )

   ::cTextoWait( "A�adiendo propiedades del art�culo: " + hGet( hArticuloData, "name" ) )
   ::buildInsertPropiedadesProductPrestashop( hArticuloData, nCodigoWeb )

   ::cTextoWait( "A�adiendo ofertas del art�culo: " + hGet( hArticuloData, "name" ) )
   ::buildInsertOfertasPrestashop( hArticuloData, nCodigoWeb )

return nCodigoweb

//---------------------------------------------------------------------------//
/*
insertamos imagenes del art�culo en concreto--------------------------------
*/

METHOD buildInsertImageProductsPrestashop( hArticuloData, cCodWeb ) CLASS TComercio

   local cCommand          := ""
   local nCodigoImagen     := 0
   local oImagen
   local nOrdAnt
   local aImage

   ::nImagePosition        := 1

   nOrdAnt                 := ::oArtImg:OrdSetFocus( "cImgArt" )

   for each aImage in hGet( hArticuloData, "aImages" )
   
      if ::oArtImg:Seek( hGet( aImage, "name" ) )

         nCodigoImagen     := ::InsertImageProductImage( cCodWeb, hGet( aImage, "lDefault" ) )

         if nCodigoImagen != 0

            ::InsertImageProductImageLang( nCodigoImagen )

            ::InsertImageProductImageShop( nCodigoImagen, hGet( aImage, "lDefault" ) )

            // A�adimos la imagen al array para subirla a prestashop--------------

            oImagen                       := SImagen()
            oImagen:cNombreImagen         := alltrim( ::oArtImg:cImgArt )
            oImagen:nTipoImagen           := tipoProducto
            oImagen:cCarpeta              := alltrim( str( nCodigoImagen ) )
            oImagen:cPrefijoNombre        := alltrim( str( nCodigoImagen ) )

            ::addImages( oImagen )

         end if 

         ::nImagePosition++

      end if

   next

   ::oArtImg:OrdSetFocus( nOrdAnt )

Return .t.

//---------------------------------------------------------------------------//

METHOD buildInsertOfertasPrestashop( hArticuloData, nCodigoWeb ) CLASS TComercio

   local cCommand          := ""

   if hGet( hArticuloData, "lSbrInt" ) .and. hGet( hArticuloData, "nDtoInt1" ) != 0

      cCommand          := "INSERT INTO " + ::cPrefixTable( "specific_price" ) + ; 
                           " ( id_specific_price_rule, " + ;
                              "id_cart, " + ;
                              "id_product, " + ;
                              "id_shop, " + ;
                              "id_shop_group, " + ;
                              "id_currency, " + ;
                              "id_country, " + ;
                              "id_group, " + ;
                              "id_customer, " + ;
                              "id_product_attribute, " + ;
                              "price, " + ;
                              "from_quantity, " + ;
                              "reduction, " + ;
                              "reduction_type )" + ;
                           " VALUES " + ;
                              "('0', " + ;                                             //id_specific_price_rule
                              "'0', " + ;                                              //id_cart
                              "'" + alltrim( str( nCodigoWeb ) ) + "', " + ;           //id_product
                              "'1', " + ;                                              //id_shop
                              "'0', " + ;                                              //id_shop_group
                              "'0', " + ;                                              //id_currency
                              "'0', " + ;                                              //id_country
                              "'0', " + ;                                              //id_group
                              "'0', " + ;                                              //id_customer
                              "'0', " + ;                                              //id_product_attribute
                              "'-1', " + ;                                             //price
                              "'1', " + ;                                              //from_quantity
                              "'" + alltrim( str( hGet( hArticuloData, "nDtoInt1" ) / 100 ) ) + "', " + ;//reduction
                              "'percentage' )"                                         //reduction_type
   
      if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
         ::treeSetText( "Error al insertar una oferta de " + hGet( hArticuloData, "name" ), 3 )
      end if

   end if

return nil

//---------------------------------------------------------------------------//

METHOD buildInsertPropiedadesPrestashop( hPropiedadesCabData ) CLASS TComercio

   local oImagen
   local nCodigoGrupo      := 0
   local nCodigoPropiedad  := 0
   local nParent           := 1
   local cCommand          := ""

   /*
   Insertamos una propiedad nueva en las tablas de prestashop-----------------
   */

   cCommand          := "INSERT INTO " + ::cPrefixTable( "attribute_group" ) + ; 
                              " ( is_color_group, " + ;
                                  "group_type )" + ;
                              " VALUES " + ;
                                  "('" + if( hGet( hPropiedadesCabData, "lColor" ), "1", "0" ) + "', " + ;        //is_color_group
                                  "'" + if( hGet( hPropiedadesCabData, "lColor" ), "color", "select" ) + "' )"    //group_type                        

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      nCodigoGrupo   := ::oCon:GetInsertId()
   else
      ::treeSetText( "Error al insertar la propiedad " + hGet( hPropiedadesCabData, "name" ) + " en la tabla " + ::cPrefixTable( "attribute_group" ), 3 )
   end if

   cCommand          := "INSERT INTO " + ::cPrefixTable( "attribute_group_lang" ) + ; 
                              " ( id_attribute_group, " + ;
                                  "id_lang, " + ;
                                  "name, " + ;
                                  "public_name )" + ;
                              " VALUES " + ;
                                  "('" + alltrim( str( nCodigoGrupo ) ) + "', " + ;    //id_attribute_group
                                  "'" + str( ::nLanguage ) + "', " + ;                 //id_lang
                                  "'" + hGet( hPropiedadesCabData, "name" ) + "', " + ;//name
                                  "'" + hGet( hPropiedadesCabData, "name" ) + "' )"    //public_name

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar la propiedad " + hGet( hPropiedadesCabData, "name" ) + " en la tabla " + ::cPrefixTable( "attribute_group_lang" ), 3 )
   end if

   if ::oPro:SeekInOrd( hGet( hPropiedadesCabData, "id" ), "CCODPRO" )
      ::oPro:fieldPutByName( "cCodWeb", nCodigoGrupo )
   end if

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildInsertLineasPropiedadesPrestashop( hPropiedadesLinData, nPosition ) CLASS TComercio

   local nCodigoPropiedad  := 0
   local cCommand          := ""
   local nCodigoGrupo      := oRetFld( hGet( hPropiedadesLinData, "idparent" ), ::oPro, "cCodWeb" )

   /*
   Introducimos las l�neas-----------------------------------------------------
   */

   cCommand                := "INSERT INTO " + ::cPrefixTable( "attribute" ) + ; 
                                 "( id_attribute_group, " + ;
                                 "color, " + ;
                                 "position ) " + ;
                              "VALUES " + ;
                                 "('" + alltrim( str( nCodigoGrupo ) ) + "', " + ;
                                 "'" + hGet( hPropiedadesLinData, "color" ) + "' ," + ;
                                 "'" + alltrim( str( nPosition ) ) + "' )"             // posicion

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      nCodigoPropiedad   := ::oCon:GetInsertId()
   else
      ::treeSetText( "Error al insertar la propiedad " + hGet( hPropiedadesLinData, "name" ) + " en la tabla " + ::cPreFixtable( "attribute" ), 3 )
   end if

   cCommand    := "INSERT INTO " + ::cPrefixTable( "attribute_lang" ) + ;
                     " ( id_attribute, " + ;
                        "id_lang, " + ;
                        "name ) " + ;
                     "VALUES " + ;
                        "('" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;   //id_attribute
                        "'" + str( ::nLanguage ) + "', " + ;                    //id_lang
                        "'" + ::oCon:Escapestr( hGet( hPropiedadesLinData, "name" ) ) + "' )"              //name

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar la propiedad " + hGet( hPropiedadesLinData, "name" ) + " en la tabla " + ::cPrefixTable( "attribute_lang" ), 3 )
   end if

   cCommand    := "INSERT INTO " + ::cPrefixTable( "attribute_shop" ) + ;
                     " ( id_attribute, " + ;
                        "id_shop ) " + ;
                     "VALUES " + ;
                        "('" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;   //id_attribute
                        "'1' )"                                                 //id_shop

   if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( "Error al insertar la propiedad " + hGet( hPropiedadesLinData, "name" ) + " en la tabla " + ::cPrefixTable( "attribute_shop" ), 3 )
   end if

   if ::oTblPro:SeekInOrd( hGet( hPropiedadesLinData, "idparent" ) + hGet( hPropiedadesLinData, "id" ), "CCODPRO" )
      ::oTblPro:fieldPutByName( "cCodWeb", nCodigoPropiedad )
   end if

Return ( self )

//---------------------------------------------------------------------------//

METHOD buildInsertPropiedadesProductPrestashop( hArticuloData, nCodigoWeb ) CLASS TComercio

   local nCodigoImagen        := 0
   local oImagen
   local nPosition            := 1
   local nCodigoPropiedad     := 0
   local aPropiedades1        := {}
   local aPropiedades2        := {}
   local aPropiedad1
   local aPropiedad2
   local nOrdAnt
   local nPrecio              := 0
   local nParent              := ::buildGetParentCategories( hGet( hArticuloData, "id_category_default" ) )
   local cCommand             := ""
   local nOrdArtDiv           := ::oArtDiv:OrdSetFocus( "cCodArt" )
   local lDefault             := .t.
   local nTotStock            := 0
   local aImages
   local cImage

   /*
   Comprobamos si el art�culo tiene propiedades y metemos las propiedades
   */

   if ::oArtDiv:Seek( hGet( hArticuloData, "id" ) )

      while ::oArtDiv:cCodArt == hGet( hArticuloData, "id" ) .and. !::oArtDiv:Eof()

         /*
         -------------------------------------------------------------------
         Caso de tener una sola propiedad-----------------------------------
         -------------------------------------------------------------------
         */

         do case
            case !empty( ::oArtDiv:cValPr1 ) .and. empty( ::oArtDiv:cValPr2 )

               nOrdAnt        := ::oTblPro:OrdSetFocus( "cCodPro" )

               if ::oTblPro:Seek( ::oArtDiv:cCodPr1 + ::oArtDiv:cValPr1 )

                  nPrecio     := nPrePro( hGet( hArticuloData, "id" ), ::oArtDiv:cCodPr1, ::oArtDiv:cValPr1, Space( 20 ), Space( 20 ), 1, .f., ::oArtDiv:cAlias )

                  /*
                  Metemos la propiedad de �ste art�culo------------------------
                  */

                  cCommand    := "INSERT INTO " + ::cPrefixTable( "product_attribute" ) + " ( "                                     + ;
                                    if( ::lProductIdColumnProductAttribute, "id_product, ", "" )                                    + ;
                                    "price, "                                                                                       + ;
                                    "wholesale_price, "                                                                             + ;
                                    "quantity, "                                                                                    + ;
                                    "minimal_quantity ) "                                                                           + ;
                                 "VALUES ("                                                                                         + ;
                                    if( ::lProductIdColumnProductAttribute, "'" + alltrim( str( nCodigoWeb ) ) + "', ", "" )        + ;      //id_product
                                    "'" + alltrim( str( if( nPrecio != 0, nPrecio, hGet( hArticuloData, "nImpInt1" ) ) ) ) + "', "  + ;      //price
                                    "'" + alltrim( str( if( nPrecio != 0, nPrecio, hGet( hArticuloData, "nImpInt1" ) ) ) ) + "', "  + ;      //wholesale_price
                                    "'10000', "                                                                                     + ;      //quantity
                                    "'1' )"                                                                                                  //minimal_quantity

                  if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
                     nCodigoPropiedad           := ::oCon:GetInsertId()
                  else
                     ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPrefixTable( "product_attribute" ), 3 )
                  end if

                  /*
                  Metemos la relaci�n de la propiedad con el art�culo----------
                  */

                  cCommand    := "INSERT INTO " + ::cPrefixTable( "product_attribute_combination" ) + " ( " + ;
                                    "id_attribute, " + ;
                                    "id_product_attribute )" + ;
                                 " VALUES " + ;
                                    "('" + alltrim( str( ::oTblPro:cCodWeb ) ) + "', " + ;   //id_attribute
                                    "'" + alltrim( str( nCodigoPropiedad ) ) + "' )"         //id_product_attribute

                  if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
                     ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPrefixTable( "product_attribute_combination" ), 3 )
                  end if

                  /*
                  Metemos la relaci�n entre la propiedad y el shop-------------
                  */

                  cCommand    :=    "INSERT INTO " + ::cPrefixTable( "product_attribute_shop" ) + " ( " + ;
                                       "id_product_attribute, " + ;
                                       "id_shop, " + ;
                                       "wholesale_price, " + ;
                                       "price, " + ;
                                       "ecotax, " + ;
                                       "weight, " + ;
                                       "unit_price_impact, " + ;
                                       if( lDefault, "default_on, ", "" ) + ;
                                       "minimal_quantity )" + ;
                                    " VALUES " + ;
                                       "('" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;
                                       "'1', " + ;
                                       "'" + alltrim( str( if( nPrecio != 0, nPrecio, hGet( hArticuloData, "nImpInt1" ) ) ) ) + "', " + ;
                                       "'" + alltrim( str( if( nPrecio != 0, nPrecio, hGet( hArticuloData, "nImpInt1" ) ) ) ) + "', " + ;
                                       "'0', " + ;
                                       "'0', " + ;
                                       "'0', " + ;
                                       if( lDefault, "'1',", "" ) + ;
                                       "'1' )"

                  if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
                     ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPrefixTable( "product_attribute_shop" ), 3 )
                  end if

                  /*
                  Metemos el stock por cada propiedad--------------------------
                  */

                  nTotStock   := ::oStock:nStockAlmacen( ::oArt:Codigo, ::TPrestashopConfig:getStore(), ::oArtDiv:cValPr1 )

                  cCommand    :=    "INSERT INTO " + ::cPrefixTable( "stock_available" ) + " ( " + ;
                                       "id_product, " + ;
                                       "id_product_attribute, " + ;
                                       "id_shop, " + ;
                                       "id_shop_group, " + ;
                                       "quantity, " + ;
                                       "depends_on_stock, " + ;
                                       "out_of_stock )" + ;
                                    " VALUES " + ;
                                       "('" + alltrim( str( nCodigoWeb ) ) + "', " + ;
                                       "'" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;   
                                       "'1', " + ;
                                       "'0', " + ;
                                       "'" + alltrim( str( nTotStock ) ) + "', " + ;
                                       "'0', " + ;
                                       "'2' )"

                  if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
                     ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPrefixTable( "stock_available" ), 3 )
                  end if

                  /*
                  -------------------------------------------------------------
                  Im�genes para una sola propiedad-----------------------------
                  -------------------------------------------------------------
                  */

                  if !empty( ::oArtDiv:mImgWeb )

                     aImages  := hb_aTokens( ::oArtDiv:mImgWeb, "," )

                     for each cImage in aImages

                        if ::oArtImg:SeekInOrd( hGet( hArticuloData, "id" ), "cCodArt" )

                           while ::oArtImg:cCodArt == hGet( hArticuloData, "id" ) .and. !::oArtImg:Eof()

                              if alltrim( ::oArtImg:cImgArt ) == alltrim( cImage )

                                 cCommand    := "INSERT INTO " + ::cPrefixTable( "product_attribute_image" ) + " ( " + ;
                                                   "id_product_attribute, " + ;
                                                   "id_image )" + ;
                                                " VALUES " + ;
                                                   "('" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;    //id_product
                                                   "'" + alltrim( str( ::oArtImg:cCodWeb ) ) + "' )"        //cover
         
                                 if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
                                    ::treeSetText( "Error al insertar el art�culo " + hGet( hArticuloData, "name" ) + " en la tabla " + ::cPrefixTable( "product_attribute_image" ), 3 )
                                 end if

                              end if   

                              ::oArtImg:Skip()

                           end while   

                        end if

                     next   

                  end if

               end if

            /*
            -------------------------------------------------------------------
            Caso de tener dos propiedades--------------------------------------
            -------------------------------------------------------------------
            */

            case !empty( ::oArtDiv:cValPr1 ) .and. !empty( ::oArtDiv:cValPr2 )

               nPrecio     := nPrePro( hGet( hArticuloData, "id" ), ::oArtDiv:cCodPr1, ::oArtDiv:cValPr1, ::oArtDiv:cCodPr2, ::oArtDiv:cValPr2, 1, .f., ::oArtDiv:cAlias )

               /*
               Metemos la propiedad de �ste art�culo---------------------------
               */

               cCommand    := "INSERT INTO " + ::cPrefixTable( "product_attribute" ) + " ( "                                     + ;
                                 if( ::lProductIdColumnProductAttribute, "id_product, ", "" )                                    + ;
                                 "price, "                                                                                       + ;
                                 "wholesale_price, "                                                                             + ;
                                 "quantity, "                                                                                    + ;
                                 "minimal_quantity ) "                                                                           + ;
                              "VALUES ("                                                                                         + ;
                                 if( ::lProductIdColumnProductAttribute, "'" + alltrim( str( nCodigoWeb ) ) + "', ", "" )        + ;      //id_product
                                 "'" + alltrim( str( if( nPrecio != 0, nPrecio, hGet( hArticuloData, "nImpInt1" ) ) ) ) + "', "  + ;      //price
                                 "'" + alltrim( str( if( nPrecio != 0, nPrecio, hGet( hArticuloData, "nImpInt1" ) ) ) ) + "', "  + ;      //wholesale_price
                                 "'10000', "                                                                                     + ;      //quantity
                                 "'1' )"                                                                                                  //minimal_quantity

               ::treeSetText( cCommand )                                 

               if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
                  nCodigoPropiedad  := ::oCon:GetInsertId()
               else
                  ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oArtDiv:cValPr1 ) + " - " + alltrim( ::oArtDiv:cValPr2 ) + " en la tabla " + ::cPrefixTable( "product_attribute" ), 3 )
               end if

               /*
               Metemos la relaci�n de la propiedad1 con el art�culo------------
               */

               nOrdAnt        := ::oTblPro:OrdSetFocus( "cCodPro" )

               if ::oTblPro:Seek( ::oArtDiv:cCodPr1 + ::oArtDiv:cValPr1 )

                  cCommand    := "INSERT INTO " +  ::cPrefixtable( "product_attribute_combination" ) + "( " + ;
                                    "id_attribute, " + ;
                                    "id_product_attribute ) " + ;
                                 "VALUES " + ;
                                    "('" + alltrim( str( ::oTblPro:cCodWeb ) ) + "', " + ;  //id_attribute
                                    "'" + alltrim( str( nCodigoPropiedad ) ) + "' )"        //id_product_attribute

                  ::treeSetText( cCommand )                                 

                  if !TMSCommand():New( ::oCon ):ExecDirect( cCommand ) 
                     ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::PrefixTable( "product_attribute_combination" ), 3 )
                  end if

               else 
                  ::treeSetText( "Error al buscar en tabla de propiedades " + alltrim( ::oArtDiv:cCodPr1 ) + " : " + alltrim( ::oArtDiv:cValPr1 ), 3 )
               end if

               /*
               Metemos la relaci�n de la propiedad 2 con el art�culo-----------
               */

               if ::oTblPro:Seek( ::oArtDiv:cCodPr2 + ::oArtDiv:cValPr2 )

                  cCommand    := "INSERT INTO " + ::cPrefixTable( "product_attribute_combination" ) + " ( " + ;
                                    "id_attribute, " + ;
                                    "id_product_attribute ) " + ;
                                 "VALUES " + ;
                                    "('" + alltrim( str( ::oTblPro:cCodWeb ) ) + "', " + ;   //id_attribute
                                    "'" + alltrim( str( nCodigoPropiedad ) ) + "' )"         //id_product_attribute

                  ::treeSetText( cCommand )                                 

                  if !TMSCommand():New( ::oCon ):ExecDirect( cCommand ) 
                     ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPrefixTable( "product_attribute_combination" ), 3 )
                  end if

               else 
                  ::treeSetText( "Error al buscar en tabla de propiedades " + alltrim( ::oArtDiv:cCodPr2 ) + " : " + alltrim( ::oArtDiv:cValPr2 ), 3 )
               end if

               ::oTblPro:OrdSetFocus( nOrdAnt )

               /*
               Metemos la relaci�n entre la propiedad y el shop-------------
               */

               cCommand    := "INSERT INTO " + ::cPrefixTable( "product_attribute_shop" ) + " ( "  + ;
                                 if( ::isProductIdColumnProductAttributeShop, "id_product, ", "" ) + ;
                                 "id_product_attribute, "                                          + ;
                                 "id_shop, "                                                       + ;
                                 "wholesale_price, "                                               + ;
                                 "price, "                                                         + ;
                                 "ecotax, "                                                        + ;
                                 "weight, "                                                        + ;
                                 "unit_price_impact, "                                             + ;
                                 if( lDefault, "default_on, ", "" )                                + ;
                                 "minimal_quantity ) "                                             + ;
                              "VALUES ("                                                           + ;
                                 if( ::isProductIdColumnProductAttributeShop, "'" + alltrim( str( nCodigoWeb ) ) + "', ", "" ) + ;  // id_product
                                 "'" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;
                                 "'1', " + ;
                                 "'" + alltrim( str( if( nPrecio != 0, nPrecio, hGet( hArticuloData, "nImpInt1" ) ) ) ) + "', " + ;
                                 "'" + alltrim( str( if( nPrecio != 0, nPrecio, hGet( hArticuloData, "nImpInt1" ) ) ) ) + "', " + ;
                                 "'0', " + ;
                                 "'0', " + ;
                                 "'0', " + ;
                                 if( lDefault, "'1',", "" ) + ;
                                 "'1' )"

               ::treeSetText( cCommand )                                 

               if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
                  ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPrefixTable( "product_attribute_shop" ), 3 )
               end if

               /*
               Metemos el stock por cada propiedad--------------------------
               */

               nTotStock   := ::oStock:nStockAlmacen( hGet( hArticuloData, "id" ), ::TPrestashopConfig:getStore(), ::oArtDiv:cValPr1, ::oArtDiv:cValPr2 )

               cCommand    := "INSERT INTO " + ::cPrefixTable( "stock_available" ) + " ( " + ;
                                 "id_product, " + ;
                                 "id_product_attribute, " + ;
                                 "id_shop, " + ;
                                 "id_shop_group, " + ;
                                 "quantity, " + ;
                                 "depends_on_stock, " + ;
                                 "out_of_stock ) " + ;
                              "VALUES " + ;
                                 "('" + alltrim( str( nCodigoWeb ) ) + "', " + ;
                                 "'" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;   
                                 "'1', " + ;
                                 "'0', " + ;
                                 "'" + alltrim( str( nTotStock ) ) + "', " + ;
                                 "'0', " + ;
                                 "'2' )"

               ::treeSetText( cCommand )                                 

               if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
                  ::treeSetText( "Error al insertar la propiedad " + alltrim( ::oTblPro:cDesTbl ) + " en la tabla " + ::cPrefixTable( "stock_available" ), 3 )
               end if

               /*
               ----------------------------------------------------------------
               Im�genes para dos propiedades-----------------------------------
               ----------------------------------------------------------------
               */

               if !empty( ::oArtDiv:mImgWeb )

                  aImages  := hb_aTokens( ::oArtDiv:mImgWeb, "," )

                  for each cImage in aImages

                     if ::oArtImg:SeekInOrd( hGet( hArticuloData, "id" ), "cCodArt" )

                        while ::oArtImg:cCodArt == hGet( hArticuloData, "id" ) .and. !::oArtImg:Eof()

                           if alltrim( ::oArtImg:cImgArt ) == alltrim( cImage )

                              cCommand    := "INSERT INTO " + ::cPrefixTable( "product_attribute_image" ) + " ( " + ;
                                                "id_product_attribute, " + ;
                                                "id_image ) " + ;
                                             "VALUES " + ;
                                                "('" + alltrim( str( nCodigoPropiedad ) ) + "', " + ;    //id_product
                                                "'" + alltrim( str( ::oArtImg:cCodWeb ) ) + "' )"        //cover

                              ::treeSetText( cCommand )                                 
      
                              if !TMSCommand():New( ::oCon ):ExecDirect( cCommand )
                                 ::treeSetText( "Error al insertar el art�culo " + hGet( hArticuloData, "name" ) + " en la tabla " + ::cPrefixTable( "product_attribute_image" ), 3 )
                              end if

                           end if   

                           ::oArtImg:Skip()

                        end while   

                     end if

                  next   

               end if

         end case

         ::oArtDiv:Skip()

         lDefault    := .f.

      end while

   end if

   ::oArtDiv:OrdSetFocus( nOrdArtDiv )

Return ( self )

//---------------------------------------------------------------------------//

METHOD buildEliminaTablas() CLASS TComercio

   local cCommand

   /*
   Vaciamos las tablas de tipos de Iva-----------------------------------------
   */

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPreFixtable( "tax" ) )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "tax" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "tax" ), 3  )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPreFixtable( "tax_lang" ) )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "tax_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "tax_lang" ), 3  )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPreFixtable( "tax_rule" ) )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "tax_rule" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "tax_rule" ), 3  )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPreFixtable( "tax_rules_group" ) )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "tax_rules_group" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "tax_rules_group" ), 3  )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPreFixtable( "tax_rules_group_shop" ) )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "tax_rules_group_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "tax_rules_group_shop" ), 3  )
   end if

   /*
   Vaciamos las tablas de fabricantes------------------------------------------
   */

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPrefixTable( "manufacturer" ) )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "manufacturer" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "manufacturer" ), 3  )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPrefixTable( "manufacturer_shop" ) )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "manufacturer_shop" ) + ' borrada correctamente', 3 )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "manufacturer_shop" ), 3 )
   end if

   if TMSCommand():New( ::oCon ):ExecDirect( "TRUNCATE TABLE " + ::cPrefixTable( "manufacturer_lang" ) )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "manufacturer_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "manufacturer_lang" ), 3  )
   end if

   /*
   Vaciamos las tablas de Categorias-------------------------------------------
   */

   cCommand       := "TRUNCATE TABLE " + ::cPrefixtable( "category" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPreFixtable( "category" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPreFixtable( "category" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "category_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "category_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "category_lang" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "category_product" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "category_product" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "category_product" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "category_group" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "category_group" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "category_group" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "category_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "category_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla '+ ::cPrefixTable( "category_group" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "image" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "image" ) + 'borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla' + ::cPrefixTable( "image" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "image_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "image_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla '+ ::cPrefixTable( "image_shop" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "image_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "image_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "image_lang" ), 3  )
   end if

   /*
   Cargamos la categor�a raiz de la que colgar�n todas las dem�s---------------
   */

   ::AddCategoriaRaiz()

   /*
   Vaciamos las tablas de propiedades------------------------------------------
   */

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_lang" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_shop" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_impact" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_impact" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_impact" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_group" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_group" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_group" ), 3  )
   end if

   cCommand       := "TRUNCATE TABLE " + ::cPrefixTable( "attribute_group_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "attribute_group_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "attribute_group_lang" ), 3  )
   end if

   /*
   Vaciamos las tablas de Art�culos--------------------------------------------
   */

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_attachment" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attachment" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attachment" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_attribute" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attribute" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attribute" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_attribute_combination" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attribute_combination" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attribute_combination" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_attribute_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attribute_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attribute_shop" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPreFixTable( "product_attribute_image" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_attribute_image" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_attribute_image" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_country_tax" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_country_tax" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_country_tax" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_download" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_download" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la table ' + ::cPrefixTable( "product_download" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_group_reduction_cache" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_group_reduction_cache" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_group_reduction_cache" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_shop" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_shop" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_shop" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_lang" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_sale" ) 

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_sale" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_sale" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "product_tag" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "product_tag" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "product_tag" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "specific_price")

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "specific_price" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "specific_price" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla '  + ::cPrefixTable( "feature" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "feature_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature_lang" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature_product" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "feature_product" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature_product" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature_value" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "feature_value" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature_value" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "feature_value_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "feature_value_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "feature_value_lang" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "scene" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "scene " ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "scene" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "scene_category" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "scene_category" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla' + ::cPrefixTable( "scene_category" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "scene_lang" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "scene_lang" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "scene_lang" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "scene_products" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "scene_products" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "scene_products" ), 3  )
   end if

   cCommand          := "TRUNCATE TABLE " + ::cPrefixTable( "stock_available" )

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      ::treeSetText( 'Tabla ' + ::cPrefixTable( "stock_available" ) + ' borrada correctamente', 3  )
   else
      ::treeSetText( 'Error al borrar la tabla ' + ::cPrefixTable( "stock_available" ), 3  )
   end if

   /*
   Limpiamos las referencias de las tablas de gestool--------------------------
   */

   ::buildCleanPrestashop()

   /*
   limpiamos refencias de imagenes a la web------------------------------------
   */

   ::lLimpiaRefImgWeb()

Return ( self )

//---------------------------------------------------------------------------//

METHOD DelIdPropiedadesPrestashop() Class TComercio

   local nRec

   /*
   Cabeceras de propiedades----------------------------------------------------
   */

   nRec  := ::oPro:Recno()
   ::oPro:GoTop()

   while !::oPro:Eof()

      ::oPro:Load()
      ::oPro:cCodWeb := 0
      ::oPro:Save()

      ::treeSetText( 'Eliminando c�digo web en la propiedad ' + alltrim( ::oPro:cDesPro ), 3  )

      ::oPro:Skip()

   end while

   ::oPro:GoTo( nRec )

   /*
   Lineas de propiedades-------------------------------------------------------
   */

   nRec  := ::oTblPro:Recno()
   ::oTblPro:GoTop()

   while !::oTblPro:Eof()

      ::oTblPro:Load()
      ::oTblPro:cCodWeb := 0
      ::oTblPro:Save()

      ::treeSetText( 'Eliminando c�digo web en la propiedad ' + alltrim( ::oTblPro:cDesTbl ), 3  )

      ::oTblPro:Skip()

   end while

   ::oTblPro:GoTo( nRec )

RETURN ( .t. )

//---------------------------------------------------------------------------//

METHOD buildExportarPrestashop( idProduct ) Class TComercio

   local hWeb
   local hWebs
   local oBlock
   local oError

   hWebs             := ::TPrestashopConfig:getWebs()

   if empty(hWebs)
      msgStop( "No hay web definidas en el fichero de configuraci�n.")
      Return .f.
   end if 

   ::disableDialog()

   oBlock            := ErrorBlock( { | oError | Break( oError ) } )
   BEGIN SEQUENCE

      for each hWeb in hWebs
         
         ::TPrestashopConfig:setCurrentWeb( hWeb )

         if ::TPrestashopConfig:isActive()
            ::buildFTP()
            ::buildProductPrestashop( idProduct, .f. )
         end if 

      next

   RECOVER USING oError
      msgStop( ErrorMessage( oError ), "Error al exportar a Prestashop." )
   END SEQUENCE
   ErrorBlock( oBlock )

   ::EnableDialog()

Return .t.

//---------------------------------------------------------------------------//

METHOD buildCleanPrestashop() CLASS TComercio

   ::treeSetText( "Limpiamos las referencias de las tablas de tipos de impuestos" )
   ::buildCleanTable( ::oIva )

   ::treeSetText( "Limpiamos las referencias de las tablas de fabricantes" )
   ::buildCleanTable( ::oFab )

   ::treeSetText( "Limpiamos las referencias de las tablas de familias" )
   ::buildCleanTable( ::oFam )

   ::treeSetText( "Limpiamos las referencias de las tablas de propiedades" )
   ::buildCleanTable( ::oPro )

   ::treeSetText( "Limpiamos las referencias de las tablas de art�culos" )
   ::buildCleanTable( ::oArt )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildCleanTable( oTable ) CLASS TComercio

   oTable:GoTop()
   while !oTable:Eof()

      if oTable:FieldGetbyName( "cCodWeb" ) != 0
         oTable:fieldPutByName( "cCodWeb", 0 )
      endif

      oTable:Skip()

   end while

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildGetParentCategories( cCodFam ) CLASS TComercio

   local idCategories := 2

   if !empty( cCodFam )
      if ::oFam:Seek( cCodFam )
         if ::oFam:lPubInt
            idCategories := ::oFam:cCodWeb
         end if
      end if
   end if   

Return( idCategories )

//---------------------------------------------------------------------------//

METHOD BuildDeleteProductPrestashop( idProduct) CLASS TComercio

   local oQuery
   local oQuery2
   local cCodWeb 
   local idDelete    := 0
   local idDelete2   := 0
   local cCommand    := ""

   if !( ::oArt:Seek( idProduct ) )
      Return ( Self )
   end if 

   if empty( ::oArt:cCodWeb ) 
      Return ( Self )
   end if 

   cCodWeb           := alltrim( str( ::oArt:cCodWeb ) )

   ::cTextoWait( "Eliminando art�culo de Prestashop" )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando adjuntos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attachment" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando impuestos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_country_tax" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando archivos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_download" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando cache de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_group_reduction_cache" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando multitienda de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_shop" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando descripciones de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_lang" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando ofertas de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_sale" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando etiquetas de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_tag" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando complementos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_supplier" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando transporte de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "product_carrier" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando atributos de Prestashop"  )

   cCommand          := 'SELECT * FROM ' + ::cPrefixTable( "product_attribute" ) +  ' WHERE id_product=' + cCodWeb
   oQuery            := TMSQuery():New( ::oCon, cCommand )
   
   ::cTextoWait( "Eliminando lineas atributos de Prestashop"  )

   if oQuery:Open()
   
      if oQuery:RecCount() > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            idDelete    := oQuery:FieldGet( 1 )

            if !empty( idDelete )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attribute" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attribute_combination" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attribute_image" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "product_attribute_shop" ) + " WHERE id_product_attribute=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

            end if

            oQuery:Skip()

            SysRefresh()

         end while
   
      end if

   end if

   ::cTextoWait( "Eliminando precios especificos de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "specific_price" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando prioridad de precio de Prestashop"  )

   cCommand          := "DELETE FROM " + ::cPrefixTable( "specific_price_priority" ) + " WHERE id_product=" + cCodWeb
   TMSCommand():New( ::oCon ):ExecDirect( cCommand )

   ::cTextoWait( "Eliminando funciones de Prestashop"  )

   cCommand          := 'SELECT * FROM ' + ::cPrefixTable( "feature_product" ) +  ' WHERE id_product=' + cCodWeb
   oQuery            := TMSQuery():New( ::oCon, cCommand )
   
   ::cTextoWait( "Eliminando lineas funciones de Prestashop"  )

   if oQuery:Open()
   
      if oQuery:RecCount() > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            idDelete    := oQuery:FieldGet( 1 )

            if !empty( idDelete )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_product" ) + " WHERE id_product=" + cCodWeb
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "feature" ) + " WHERE id_feature=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_lang" ) + " WHERE id_feature=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_shop" ) + " WHERE id_feature=" + alltrim( str( idDelete ) )
               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

               cCommand          := 'SELECT * FROM ' + ::cPrefixTable( "feature_value" ) +  ' WHERE id_feature=' + alltrim( str( idDelete ) )
               oQuery2           := TMSQuery():New( ::oCon, cCommand )

               if oQuery2:Open()
         
                  if oQuery2:RecCount() > 0

                     oQuery2:GoTop()

                     while !oQuery2:Eof()

                     idDelete2    := oQuery:FieldGet( 1 )

                        if !empty( idDelete2 )

                           cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_value" ) + " WHERE id_feature_value=" + alltrim( str( idDelete2 ) )
                           TMSCommand():New( ::oCon ):ExecDirect( cCommand )

                           cCommand          := "DELETE FROM " + ::cPrefixTable( "feature_value_lang" ) + " WHERE id_feature_value=" + alltrim( str( idDelete2 ) )
                           TMSCommand():New( ::oCon ):ExecDirect( cCommand )

                        end if

                        oQuery2:Skip()

                        SysRefresh()

                     end while      

                  end if

               end if

            end if

            oQuery:Skip()

            SysRefresh()

         end while      
   
      end if

   end if

   SysRefresh()

   // Eliminamos las im�genes del art�culo---------------------------------------

   ::cTextoWait( "Eliminando im�genes de prestashop" )

   ::buildDeleteImagesProducts( cCodWeb )

   SysRefresh()

   // Quitamos la referencia de nuestra tabla-------------------------------------

   ::oArt:fieldPutByName( "cCodWeb", 0 )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildDeleteImagesProducts( cCodWeb ) CLASS TComercio 

   local oInt
   local oFtp
   local aDirectory
   local cDirectory
   local lError
   local idDelete
   local oQuery
   local cCommand    := ""
   local aDelImages  := {}
   local cCarpeta

   ::aDeletedImages  := {}

   if !empty( cCodWeb )
      
      /*
      Limpiamos la refecencia en la base de datos------------------------------
      */

      cCommand          := 'SELECT * FROM ' + ::cPrefixTable( "image" ) +  ' WHERE id_product=' + cCodWeb
      oQuery            := TMSQuery():New( ::oCon, cCommand )

      if oQuery:Open() .and. oQuery:RecCount() > 0

         oQuery:GoTop()

         while !oQuery:Eof()

            idDelete    := oQuery:FieldGet( 1 )

            aAdd( ::aDeletedImages, idDelete )

            cCommand          := "DELETE FROM " + ::cPrefixTable( "image" ) + " WHERE id_image=" + alltrim( str( idDelete ) )
            TMSCommand():New( ::oCon ):ExecDirect( cCommand )

            cCommand          := "DELETE FROM " + ::cPrefixTable( "image_shop" ) + " WHERE id_image=" + alltrim( str( idDelete ) )
            TMSCommand():New( ::oCon ):ExecDirect( cCommand )

            cCommand          := "DELETE FROM " + ::cPrefixTable( "image_lang" ) + " WHERE id_image=" + alltrim( str( idDelete ) )
            TMSCommand():New( ::oCon ):ExecDirect( cCommand )
         
            oQuery:Skip()

            SysRefresh()

         end while

      end if

      oQuery:Free()

   endif

Return nil

//---------------------------------------------------------------------------//

METHOD buildDeleteImagesFiles() CLASS TComercio

   local cDeleteImage

   for each cDeleteImage in ::aDeletedImages

      SysRefresh()

   next

Return nil

//---------------------------------------------------------------------------//

METHOD buildActualizaStock() Class TComercio

   local oBlock
   local oError

   ::oDlg:bValid     := {|| .f. }

   ::oBtnExportar:Hide()
   ::oBtnImportar:Hide()
   ::oBtnStock:Hide()

   ::oBtnCancel:Disable()

   oBlock            := ErrorBlock( { | oError | Break( oError ) } )
   BEGIN SEQUENCE

      ::treeSetText( 'Comenzamos la actualizaci�n', 1  )

      ::buildActualizaStockProductPrestashop()

   RECOVER USING oError

      msgStop( ErrorMessage( oError ), "Error al actualizar stock a prestashop." )

   END SEQUENCE

   ErrorBlock( oBlock )

   ::oDlg:bValid     := {|| .t. }

   ::oBtnCancel:Enable()

Return .t.

//---------------------------------------------------------------------------//

METHOD buildAddInformacionStockProductPrestashop() CLASS tComercio

   local aStockArticulo
   local nTotalStock          := 0
   local sStock

   ::treeSetText( "Recopilando informaci�n de " + alltrim( ::oArt:Nombre ) )

   /*
   Recopilamos la informaci�n del Stock-------------------------------
   */

   aStockArticulo   := ::oStock:aStockArticulo( ::oArt:Codigo, ::TPrestashopConfig:getStore() )
   aEval( aStockArticulo, {|o| nTotalStock += o:nUnidades } )

   /*
   Metemos el Stock global del art�culo-------------------------------
   */

   aAdd( ::aStockArticuloData, { "cCodArt"      => ::oArt:Codigo ,;
                                 "cNomArt"      => ::oArt:Nombre ,;
                                 "cCodPrp1"     => "" ,;
                                 "cCodPrp2"     => "" ,;
                                 "cValPrp1"     => "" ,;
                                 "cValPrp2"     => "" ,;
                                 "nStock"       => alltrim( str( nTotalStock ) ) ,;
                                 "cCodWebArt"   => ::oArt:cCodWeb,;
                                 "cCodWebVal1"  => 0 ,;
                                 "cCodWebVal2"  => 0 } )


   /*
   Recorremos el array con los stocks---------------------------------
   */

   for each sStock in aStockArticulo

      if aScan( ::aStockArticuloData, {|h|   hGet( h, "cCodArt" ) == ::oArt:Codigo .and.;
                                             hGet( h, "cCodPrp1" ) == sStock:cCodigoPropiedad1 .and.;
                                             hGet( h, "cCodPrp2" ) == sStock:cCodigoPropiedad2 .and.;
                                             hGet( h, "cValPrp1" ) == sStock:cValorPropiedad1 .and.;
                                             hGet( h, "cValPrp2" ) == sStock:cValorPropiedad2  } ) == 0
      
         aAdd( ::aStockArticuloData, { "cCodArt"      => ::oArt:Codigo ,;
                                       "cNomArt"      => ::oArt:Nombre ,;
                                       "cCodPrp1"     => sStock:cCodigoPropiedad1 ,;
                                       "cCodPrp2"     => sStock:cCodigoPropiedad2 ,;
                                       "cValPrp1"     => sStock:cValorPropiedad1 ,;
                                       "cValPrp2"     => sStock:cValorPropiedad2 ,;
                                       "nStock"       => alltrim( str( sStock:nUnidades ) ),;
                                       "cCodWebArt"   => ::oArt:cCodWeb,;
                                       "cCodWebVal1"  => oRetFld( sStock:cCodigoPropiedad1 + sStock:cValorPropiedad1, ::oTblPro, "cCodWeb" ),;
                                       "cCodWebVal2"  => oRetFld( sStock:cCodigoPropiedad2 + sStock:cValorPropiedad2, ::oTblPro, "cCodWeb" ) } )

      end if   

   next

Return .t.

//---------------------------------------------------------------------------//

METHOD buildInformacionStockProductPrestashop() CLASS TComercio

   local cCodArt

   ::meterProcesoSetTotal( ::oArt:OrdKeyCount() )

   if isArray( ::aArticulosActualizar ) .and. Len( ::aArticulosActualizar ) > 0

      for each cCodArt in ::aArticulosActualizar

         if ::oArt:Seek( cCodArt ) .and. ::oArt:cCodWeb != 0

            ::buildAddInformacionStockProductPrestashop()

         end if

      next   

   else

      while !::oArt:Eof()

         if ::oArt:cCodWeb != 0

            ::buildAddInformacionStockProductPrestashop()   

         end if

         ::oArt:Skip()

      end while

   end if   

return .t.

//---------------------------------------------------------------------------//

METHOD buildSubirStockPrestashop() CLASS TComercio

   local oQuery
   local cCommand
   local nIdProductAttribute
   local aStock

   if ::prestaShopConnect()

      for each aStock in ::aStockArticuloData

         if hGet( aStock, "cCodWebVal1" ) == 0 .and.;
            hGet( aStock, "cCodWebVal2" ) == 0

            ::treeSetText( "Actualizando stock de " + alltrim( hGet( aStock, "cNomArt" ) ) )        

            cCommand    := "UPDATE " + ::cPrefixTable( "stock_available" ) + " SET " + ;
                              "quantity='" + hGet( aStock, "nStock" ) + "' " + ;
                           "WHERE id_product=" + alltrim( str( hGet( aStock, "cCodWebArt" ) ) ) + " AND id_product_attribute=0 "

            TMSCommand():New( ::oCon ):ExecDirect( cCommand )

         else

            nIdProductAttribute := str( ::nIdProductAttribute( hGet( aStock, "cCodWebArt" ), hGet( aStock, "cCodWebVal1" ), hGet( aStock, "cCodWebVal2" ) ) )

            if !empty( nIdProductAttribute )

               cCommand    := "UPDATE " + ::cPrefixTable( "stock_available" ) + " SET " + ;
                                 "quantity='" + hGet( aStock, "nStock" ) + "' " + ;
                              "WHERE id_product=" + alltrim( str( hGet( aStock, "cCodWebArt" ) ) ) + " AND id_product_attribute=" + alltrim( nIdProductAttribute )

               TMSCommand():New( ::oCon ):ExecDirect( cCommand )

            end if

         end if
      
      next

      ::prestashopDisConnect()

   end if

Return .t.

//---------------------------------------------------------------------------//

METHOD buildActualizaStockProductPrestashop() CLASS TComercio

   /*
   Compruebo que podamos conectarnos-------------------------------------------
   */

   if !::lReady()
      Return .f.
   end if

   if ::filesOpen()

      /*
      Recopilamos informaci�n necesaria----------------------------------------
      */

      ::MeterTotalText( "Recopialando informaci�n de stocks" )
      
      ::buildInformacionStockProductPrestashop()

      /*
      Subimos la informaci�n recopilada----------------------------------------
      */

      ::treeSetText( "Actualizando stocks" )
      ::meterProcesoSetTotal( len(::aStockArticuloData) )
      ::buildSubirStockPrestashop()

      ::MeterTotalText( "Proceso finalizado" )

      ::filesClose()

   end if

   if !empty( ::oMeterTotal )
      ::oMeterTotal:Set( 100 )
   end if

   if !empty( ::oMeterProceso )
      ::oMeterProceso:Set( 100 )
   end if

Return .t.

//---------------------------------------------------------------------------//

METHOD BuildAddArticuloActualizar( cCodArt ) CLASS tComercio

   if !empty( cCodArt )             .and.;
      aScan( ::aArticulosActualizar, cCodArt ) == 0
      aAdd( ::aArticulosActualizar, cCodArt )
   end if

Return .t.   

//---------------------------------------------------------------------------//

METHOD controllerOrders() CLASS TComercio

   if ::loadOrders()
      ::processOrder()
   end if

Return ( nil )

//---------------------------------------------------------------------------//

METHOD loadOrders() CLASS TComercio

   local oQuery
   local nQueryRecCount

   ::nMeterProceso         := 0

   oQuery                  := TMSQuery():New( ::oCon, 'SELECT * FROM ' + ::cPrefixTable( "orders" ) )    
   if oQuery:Open()
      nQueryRecCount       := oQuery:RecCount()

      if nQueryRecCount > 0

         ::setMeterTotal( nQueryRecCount )
         ::treeSetText( "Descargando pedidos desde la web", 2 )

         oQuery:GoTop()
         while !oQuery:Eof()

            ::meterProcesoText( " Descargando pedido " + alltrim( str( ++::nMeterProceso ) ) + " de "  + alltrim( str( ::nTotMeter ) ) )

            ::processOrder( oQuery )

            oQuery:Skip()

         end while

      end if

   end if

   oQuery:Free()

   oQuery   := nil

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD processOrder( oQuery ) CLASS TComercio

   local cPrestashopModule

   if empty( oQuery )
      return .f.
   end if 

   if !::checkDate( oQuery:FieldGetByName( "date_add" ) )
      return .f.
   end if 

   if ::payOrder( oQuery:FieldGetByName( "module" ) )

      if !::orderRecived( oQuery )
         ::insertPedidoPrestashop( oQuery )
      end if

   else

      if !::estimateRecived( oQuery )
         ::insertPresupuestoPrestashop( oQuery )
      end if

   endif

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD getDate( cDatePrestashop ) CLASS TComercio

   local dFecha

   SET DATE FORMAT "yyyy/mm/dd"
   dFecha   := ctod( left( cDatePrestashop, 10 ) )
   SET DATE FORMAT "dd/mm/yyyy"

Return ( dFecha )

//---------------------------------------------------------------------------//

METHOD getDatePrestashop( dFecha, tHora ) CLASS TComercio

   local cFechaPrestashop

   SET DATE FORMAT "yyyy-mm-dd"
   cFechaPrestashop   := alltrim( dtoc( dFecha ) ) + " " + alltrim( trans( tHora, "@R ##:##:##" ) ) + ".0000000"
   SET DATE FORMAT "dd/mm/yyyy"

Return ( cFechaPrestashop )

//---------------------------------------------------------------------------//

METHOD getTime( ctimePrestashop ) CLASS TComercio

   local dHora

   dHora   := strtran( Substr( cTimePrestashop, 12, 8 ), ":", "" )
   
Return ( dHora )

//---------------------------------------------------------------------------//

METHOD checkDate( cDatePrestashop ) CLASS TComercio

   local dFecha   := ::getDate( cDatePrestashop )

Return ( dFecha >= uFieldEmpresa( "dIniOpe" ) .and. dFecha <= uFieldEmpresa( "dFinOpe" ) )

//---------------------------------------------------------------------------//

METHOD payOrder( cPrestashopModule ) CLASS TComercio

   local lPayOrder   := .f.
   local nRegAnt     := ::oFPago:Recno()
   local nOrdenAnt   := ::oFPago:ordSetFocus( "cCodWeb" ) 

   if ( ::oFPago:Seek( padr( cPrestashopModule, 200 ) ) ) .and. ( ::oFPago:nCobRec <= 1 )
         lPayOrder      := .t.
   endif

   ::oFPago:ordSetFocus( nOrdenAnt )
   ::oFPago:goTo( nRegAnt )

return ( lPayOrder )

//---------------------------------------------------------------------------//

METHOD insertPresupuestoPrestashop( oQuery ) CLASS TComercio
   
   ::getCountersPresupustoPrestashop( oQuery )
   ::insertDatosCabeceraPresupuestoPretashop ( oQuery )
   ::insertLineaPresupuestoPrestashop( oQuery )
   ::appendMessagePresupuesto( ::getDate( oQuery:FieldGetByName( "date_add" ) ) )
   ::appendStatePresupuestoPrestashop( oQuery )  

return ( .t. )

//---------------------------------------------------------------------------//

METHOD getCountersPresupustoPrestashop( oQuery ) CLASS TComercio

   ::idOrderPrestashop  := oQuery:FieldGet( 1 )
   ::cSeriePresupuesto  := ::TPrestashopConfig:getBudgetSerie()
   ::nNumeroPresupuesto := nNewDoc( ::cSeriePresupuesto, ::oPreCliT:cAlias, "nPreCli", , ::oCount:cAlias )
   ::cSufijoPresupuesto := retSufEmp()

return ( .t. )
 
//---------------------------------------------------------------------------//

METHOD insertDatosCabeceraPresupuestoPretashop ( oQuery ) CLASS TComercio

   ::oPreCliT:Append()
   ::oPreCliT:Blank()

   ::insertCabeceraPresupuestoPretashop( oQuery )

   ::insertClientePresupuestoPrestashop( oQuery )

   if ::oPreCliT:Save()
      ::treeSetText( "Presupuesto " + ::cSeriePresupuesto + "/" + alltrim( str( ::nNumeroPresupuesto ) ) + "/" + ::cSufijoPresupuesto + " introducido correctamente.", 3 )
   else
      ::treeSetText( "Error al descargar el presupuesto: " + ::cSeriePresupuesto + "/" + alltrim( str( ::nNumeroPresupuesto ) ) + "/" + ::cSufijoPresupuesto, 3 )
   end if   

Return ( .t. )
 
//---------------------------------------------------------------------------//

METHOD insertCabeceraPresupuestoPretashop( oQuery ) CLASS TComercio

   ::oPreCliT:cSerPre      := ::cSeriePresupuesto
   ::oPreCliT:nNumPre      := ::nNumeroPresupuesto
   ::oPreCliT:cSufPre      := ::cSufijoPresupuesto
   ::oPreCliT:cCodWeb      := ::idOrderPrestashop
   ::oPreCliT:dFecPre      := ::getDate( oQuery:FieldGetByName( "date_add" ) )
   ::oPreCliT:cSuPre       := oQuery:FieldGetByName( "reference" )
   ::oPreCliT:cTurPre      := cCurSesion()
   ::oPreCliT:cCodAlm      := oUser():cAlmacen()
   ::oPreCliT:cCodCaj      := oUser():cCaja()
   ::oPreCliT:cCodObr      := "@" + alltrim( str( oQuery:FieldGetByName( "id_address_delivery" ) ) )
   ::oPreCliT:cCodPgo      := cFPagoWeb( alltrim( oQuery:FieldGetByName( "module" ) ), ::oFPago:cAlias )
   ::oPreCliT:lEstado      := .t.
   ::oPreCliT:nTarifa      := 1
   ::oPreCliT:cDivPre      := cDivEmp()
   ::oPreCliT:nVdvPre      := nChgDiv( cDivEmp(), ::oDivisas:cAlias )
   ::oPreCliT:lSndDoc      := .t.
   ::oPreCliT:lIvaInc      := uFieldEmpresa( "lIvaInc" )
   ::oPreCliT:cManObr      := Padr( "Gastos envio", 250 )
   ::oPreCliT:nManObr      := oQuery:FieldGetByName( "total_shipping_tax_excl" )
   ::oPreCliT:nIvaMan      := oQuery:FieldGetByName( "carrier_tax_rate" )
   ::oPreCliT:lCloPre      := .f.
   ::oPreCliT:cCodUsr      := cCurUsr()
   ::oPreCliT:dFecCre      := GetSysDate()
   ::oPreCliT:cTimCre      := Time()
   ::oPreCliT:cCodDlg      := oUser():cDelegacion()
   ::oPreCliT:lWeb         := .t.
   ::oPreCliT:lInternet    := .t.
   ::oPreCliT:nTotNet      := oQuery:FieldGetByName( "total_products" )
   ::oPreCliT:nTotIva      := oQuery:FieldGetByName( "total_paid_tax_incl" ) - ( oQuery:FieldGetByName( "total_products" ) + oQuery:FieldGetByName( "total_shipping_tax_incl" ) )
   ::oPreCliT:nTotPre      := oQuery:FieldGetByName( "total_paid_tax_incl" )

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD insertClientePresupuestoPrestashop( oQuery ) CLASS TComercio

   if ::oCli:SeekInOrd( str( oQuery:FieldGetByName( "id_customer" ), 11 ) , "cCodWeb" )

      ::oPreCliT:cCodCli   := ::oCli:Cod
      ::oPreCliT:cNomCli   := ::oCli:Titulo
      ::oPreCliT:cDirCli   := ::oCli:Domicilio
      ::oPreCliT:cPobCli   := ::oCli:Poblacion
      ::oPreCliT:cPrvCli   := ::oCli:Provincia
      ::oPreCliT:cPosCli   := ::oCli:CodPostal
      ::oPreCliT:cDniCli   := ::oCli:Nif
      ::oPreCliT:lModCli   := .t.
      ::oPreCliT:cTlfCli   := ::oCli:Telefono
      ::oPreCliT:cCodGrp   := ::oCli:cCodGrp
      ::oPreCliT:nRegIva   := ::oCli:nRegIva

   end if

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD insertLineaPresupuestoPrestashop( oQuery ) CLASS TComercio

   local oQueryL           := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "order_detail" ) + " WHERE id_order=" + alltrim( str( ::idOrderPrestashop ) ) )
   local nNumLin           := 1

   if oQueryL:Open() .and. ( oQueryL:RecCount() > 0 )

      oQueryL:GoTop()
      while !oQueryL:Eof()

         ::oPreCliL:Append()
         ::oPreCliL:Blank()

         ::oPreCliL:cSerPre        := ::cSeriePresupuesto
         ::oPreCliL:nNumPre        := ::nNumeroPresupuesto
         ::oPreCliL:cSufPre        := ::cSufijoPresupuesto
         ::oPreCliL:dFecha         := ::getDate( oQuery:FieldGetByName( "date_add" ) )
         ::oPreCliL:cDetalle       := oQueryL:FieldGetByName( "product_name" )
         ::oPreCliL:mLngDes        := oQueryL:FieldGetByName( "product_name" )
         ::oPreCliL:nCanPre        := 1
         ::oPreCliL:nUniCaja       := oQueryL:FieldGetByName( "product_quantity" )
         ::oPreCliL:nPreDiv        := oQueryL:FieldGetByName( "product_price" )
         ::oPreCliL:nNumLin        := nNumLin
         ::oPreCliL:cAlmLin        := cDefAlm()
         ::oPreCliL:nTarLin        := 1
         ::oPreCliL:nDto           := oQueryL:FieldGetByName( "reduction_percent" )
         ::oPreCliL:nDtoDiv        := oQueryL:FieldGetByName( "reduction_amount" )
         ::oPreCliL:nIva           := ::nIvaProduct( oQueryL:FieldGetByName( "product_id" ) )

         if ::oArt:SeekInOrd( str( oQueryL:FieldGetByName( "product_id" ), 11 ) , "cCodWeb" )

            ::oPreCliL:cRef        := ::oArt:Codigo
            ::oPreCliL:cUnidad     := ::oArt:cUnidad
            ::oPreCliL:nPesoKg     := ::oArt:nPesoKg
            ::oPreCliL:cPesoKg     := ::oArt:cUnidad
            ::oPreCliL:nVolumen    := ::oArt:nVolumen
            ::oPreCliL:cVolumen    := ::oArt:cVolumen
            ::oPreCliL:nCtlStk     := ::oArt:nCtlStock
            ::oPreCliL:nCosDiv     := nCosto( ::oArt:Codigo, ::oArt:cAlias, ::oKit:cAlias )
            ::oPreCliL:cCodTip     := ::oArt:cCodTip
            ::oPreCliL:cCodFam     := ::oArt:Familia
            ::oPreCliL:cGrpFam     := RetFld( ::oArt:Familia, ::oFam:cAlias, "cCodGrp" )
            ::oPreCliL:cCodPr1     := ::oArt:cCodPrp1
            ::oPreCliL:cCodPr2     := ::oArt:cCodPrp2
            ::oPreCliL:cValPr1     := ::GetValPrp( oRetFld( ::oArt:cCodPrp1, ::oPro, "cCodWeb", "cCodPro" ), oQueryL:FieldGet( 7 ) )
            ::oPreCliL:cValPr2     := ::GetValPrp( oRetFld( ::oArt:cCodPrp2, ::oPro, "cCodWeb", "cCodPro" ), oQueryL:FieldGet( 7 ) )
            ::oPreCliL:lLote       := ::oArt:lLote 
            ::oPreCliL:cLote       := ::oArt:cLote 

         end if

         if !::oPreCliL:Save()
            ::treeSetText( "Error al descargar las lineas el pedido: " ;
                            + ::cSeriePresupuesto + "/" + alltrim( str( ::nNumeroPresupuesto ) ) ;
                            + "/" + ::cSufijoPresupuesto, 3 )
         end if

      oQueryL:Skip()

      nNumLin++

      end while

   end if

   oQueryL:Free()

Return ( .t. )
 
//---------------------------------------------------------------------------//

METHOD appendMessagePresupuesto ( dFecha ) CLASS TComercio

   local oQueryThead
   local oQueryMessage

   oQueryThead    := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "customer_thread" ) + " WHERE id_order=" + alltrim( str( ::idOrderPrestashop ) ) )

   if oQueryThead:Open() .and. ( oQueryThead:RecCount() > 0 )

      oQueryThead:GoTop()
      while !oQueryThead:Eof()

         oQueryMessage    := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "customer_message" ) + " WHERE id_customer_thread=" + alltrim( str( oQueryThead:FieldGet( 1 ) ) ) )

         if oQueryMessage:Open() .and. ( oQueryMessage:RecCount() > 0 )

            oQueryMessage:GoTop()
            while !oQueryMessage:Eof()

               ::oPreCliI:Append()
               ::oPreCliI:Blank()

               ::oPreCliI:cSerPre   := ::cSeriePresupuesto
               ::oPreCliI:nNumPre   := ::nNumeroPresupuesto
               ::oPreCliI:cSufPre   := ::cSufijoPresupuesto
               ::oPreCliI:dFecInc   := dFecha
               ::oPreCliI:mDesInc   := oQueryMessage:FieldGetByName( "message" )
               ::oPreCliI:lAviso    := .t.

               ::oPreCliI:Save()

               oQueryMessage:Skip()

            end while

         end if
            
         oQueryMessage:Free()    

         oQueryThead:Skip()

      end while

   end if   

   oQueryThead:Free()

Return ( .t. )
 
//---------------------------------------------------------------------------//

METHOD appendStatePresupuestoPrestashop( oQuery ) CLASS TComercio

   local oQueryState
   
   oQueryState    := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "order_history" ) + " h inner join "+ ::cPrefixtable( "order_state_lang" ) + " s on h.id_order_state = s.id_order_state WHERE s.id_lang = " + str( ::nLanguage ) + " and id_order = " + alltrim( str( ::idOrderPrestashop ) ) )

   if oQueryState:Open()

      if oQueryState:RecCount() > 0

         oQueryState:GoTop()

         while !oQueryState:Eof()

            ::oPreCliE:Append()
            ::oPreCliE:Blank()

            ::oPreCliE:cSerPre   := ::cSeriePresupuesto
            ::oPreCliE:nNumPre   := ::nNumeroPresupuesto
            ::oPreCliE:cSufPre   := ::cSufijoPresupuesto
            ::oPreCliE:cSitua    := oQueryState:FieldGetByName( "name" )
            ::oPreCliE:dFecSit   := ::getDate( oQueryState:FieldGetByName( "date_add" ) )
            ::oPreCliE:tFecSit   := ::getTime( oQueryState:FieldGetByName( "date_add" ) )
            ::oPreCliE:idPs      := oQueryState:FieldGetByName( "id_order_history" )
                     
            ::oPreCliE:Save()

         oQueryState:Skip()

          end while

      end if
               
   end if      

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD insertPedidoPrestashop( oQuery ) CLASS TComercio

   ::getCountersPedidoPrestashop( oQuery )
   ::insertDatosCabeceraPedidoPretashop ( oQuery )
   ::insertLineaPedidoPrestashop( oQuery )
   ::AppendMessagePedido( ::getDate( oQuery:FieldGetByName( "date_add" ) ) )
   ::appendStatePedidoPrestashop( oQuery )

return ( .t. )

//---------------------------------------------------------------------------//

METHOD documentRecived( oQuery, oDatabase ) CLASS TComercio

   local orderRecived         := .t.
   local cIdOrderPrestashop   := str( oQuery:FieldGet( 1 ), 11 )

   if ( oDatabase:SeekInOrd( cIdOrderPrestashop, "cCodWeb" ) )
      ::treeSetText( "El documento con el indentificador " + alltrim( cIdOrderPrestashop ) + " ya ha sido recibido.", 3 )
   else
      orderRecived      := .f.
   end if 

Return ( orderRecived )   

//---------------------------------------------------------------------------//

METHOD getCountersPedidoPrestashop( oQuery ) CLASS TComercio

   ::idOrderPrestashop  := oQuery:fieldGet( 1 )
   ::cSeriePedido       := ::TPrestashopConfig:getOrderSerie()
   ::nNumeroPedido      := nNewDoc( ::cSeriePedido, ::oPedCliT:cAlias, "nPedCli", , ::oCount:cAlias )
   ::cSufijoPedido      := retSufEmp()

return ( .t. )

//---------------------------------------------------------------------------//

METHOD insertDatosCabeceraPedidoPretashop( oQuery ) CLASS TComercio

   ::oPedCliT:Append()
   ::oPedCliT:Blank()

   ::insertCabeceraPedidoPretashop ( oQuery )

   ::insertClientePedidoPrestashop( oQuery )

   if ::oPedCliT:Save()
      ::treeSetText( "Pedido " + ::cSeriePedido + "/" + alltrim( str( ::nNumeroPedido ) ) + "/" + ::cSufijoPedido + " introducido correctamente.", 3 )
   else
      ::treeSetText( "Error al descargar el pedido: " + ::cSeriePedido + "/" + alltrim( str( ::nNumeroPedido ) ) + "/" + ::cSufijoPedido, 3 )
   end if   

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD insertCabeceraPedidoPretashop( oQuery ) CLASS TComercio
   
      ::oPedCliT:cSerPed      := ::cSeriePedido
      ::oPedCliT:nNumPed      := ::nNumeroPedido
      ::oPedCliT:cSufPed      := ::cSufijoPedido
      ::oPedCliT:cCodWeb      := ::idOrderPrestashop
      ::oPedCliT:dFecPed      := ::getDate( oQuery:FieldGetByName( "date_add" ) )
      ::oPedCliT:cSuPed       := oQuery:FieldGetByName( "reference" )
      ::oPedCliT:cTurPed      := cCurSesion()
      ::oPedCliT:cCodAlm      := oUser():cAlmacen()
      ::oPedCliT:cCodCaj      := oUser():cCaja()
      ::oPedCliT:cCodObr      := "@" + alltrim( str( oQuery:FieldGetByName( "id_address_delivery" ) ) )
      ::oPedCliT:cCodPgo      := cFPagoWeb( alltrim( oQuery:FieldGetByName( "module" ) ), ::oFPago:cAlias )
      ::oPedCliT:nEstado      := 1
      ::oPedCliT:nTarifa      := 1
      ::oPedCliT:cDivPed      := cDivEmp()
      ::oPedCliT:nVdvPed      := nChgDiv( cDivEmp(), ::oDivisas:cAlias )
      ::oPedCliT:lSndDoc      := .t.
      ::oPedCliT:lIvaInc      := uFieldEmpresa( "lIvaInc" )
      ::oPedCliT:cManObr      := Padr( "Gastos envio", 250 )
      ::oPedCliT:nManObr      := oQuery:FieldGetByName( "total_shipping_tax_excl" )
      ::oPedCliT:nIvaMan      := oQuery:FieldGetByName( "carrier_tax_rate" )
      ::oPedCliT:lCloPed      := .f.
      ::oPedCliT:cCodUsr      := cCurUsr()
      ::oPedCliT:dFecCre      := GetSysDate()
      ::oPedCliT:cTimCre      := Time()
      ::oPedCliT:cCodDlg      := oUser():cDelegacion()
      ::oPedCliT:lWeb         := .t.
      ::oPedCliT:lInternet    := .t.
      ::oPedCliT:nTotNet      := oQuery:FieldGetByName( "total_products" )
      ::oPedCliT:nTotIva      := oQuery:FieldGetByName( "total_paid_tax_incl" ) - ( oQuery:FieldGetByName( "total_products" ) + oQuery:FieldGetByName( "total_shipping_tax_incl" ) )
      ::oPedCliT:nTotPed      := oQuery:FieldGetByName( "total_paid_tax_incl" )

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD insertClientePedidoPrestashop( oQuery ) CLASS TComercio
   
   if ::oCli:SeekInOrd( str( oQuery:FieldGetByName( "id_customer" ), 11 ) , "cCodWeb" )

      ::oPedCliT:cCodCli   := ::oCli:Cod
      ::oPedCliT:cNomCli   := ::oCli:Titulo
      ::oPedCliT:cDirCli   := ::oCli:Domicilio
      ::oPedCliT:cPobCli   := ::oCli:Poblacion
      ::oPedCliT:cPrvCli   := ::oCli:Provincia
      ::oPedCliT:cPosCli   := ::oCli:CodPostal
      ::oPedCliT:cDniCli   := ::oCli:Nif
      ::oPedCliT:lModCli   := .t.
      ::oPedCliT:cTlfCli   := ::oCli:Telefono
      ::oPedCliT:cCodGrp   := ::oCli:cCodGrp
      ::oPedCliT:nRegIva   := ::oCli:nRegIva

   end if

return ( .t. )

//---------------------------------------------------------------------------//

METHOD insertLineaPedidoPrestashop( oQuery ) CLASS TComercio

   local oQueryL           := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "order_detail" ) + " WHERE id_order=" + alltrim( str( ::idOrderPrestashop ) ) )
   local nNumLin           := 1

      if oQueryL:Open()

         if oQueryL:RecCount() > 0

            oQueryL:GoTop()

            while !oQueryL:Eof()

               ::oPedCliL:Append()
               ::oPedCliL:Blank()

               ::oPedCliL:cSerPed        := ::cSeriePedido
               ::oPedCliL:nNumPed        := ::nNumeroPedido
               ::oPedCliL:cSufPed        := ::cSufijoPedido
               ::oPedCliL:dFecha         := ::getDate( oQuery:FieldGetByName( "date_add" ) )
               ::oPedCliL:cDetalle       := oQueryL:FieldGetByName( "product_name" )
               ::oPedCliL:mLngDes        := oQueryL:FieldGetByName( "product_name" )
               ::oPedCliL:nCanPed        := 1
               ::oPedCliL:nUniCaja       := oQueryL:FieldGetByName( "product_quantity" )
               ::oPedCliL:nPreDiv        := oQueryL:FieldGetByName( "product_price" )
               ::oPedCliL:nNumLin        := nNumLin
               ::oPedCliL:cAlmLin        := cDefAlm()
               ::oPedCliL:nTarLin        := 1
               ::oPedCliL:nDto           := oQueryL:FieldGetByName( "reduction_percent" )
               ::oPedCliL:nDtoDiv        := oQueryL:FieldGetByName( "reduction_amount" )
               ::oPedCliL:nIva           := ::nIvaProduct( oQueryL:FieldGetByName( "product_id" ) )

               if ::oArt:SeekInOrd( str( oQueryL:FieldGetByName( "product_id" ), 11 ) , "cCodWeb" )

                  ::oPedCliL:cRef        := ::oArt:Codigo
                  ::oPedCliL:cUnidad     := ::oArt:cUnidad
                  ::oPedCliL:nPesoKg     := ::oArt:nPesoKg
                  ::oPedCliL:cPesoKg     := ::oArt:cUnidad
                  ::oPedCliL:nVolumen    := ::oArt:nVolumen
                  ::oPedCliL:cVolumen    := ::oArt:cVolumen
                  ::oPedCliL:nCtlStk     := ::oArt:nCtlStock
                  ::oPedCliL:nCosDiv     := nCosto( ::oArt:Codigo, ::oArt:cAlias, ::oKit:cAlias )
                  ::oPedCliL:cCodTip     := ::oArt:cCodTip
                  ::oPedCliL:cCodFam     := ::oArt:Familia
                  ::oPedCliL:cGrpFam     := RetFld( ::oArt:Familia, ::oFam:cAlias, "cCodGrp" )
                  ::oPedCliL:cCodPr1     := ::oArt:cCodPrp1
                  ::oPedCliL:cCodPr2     := ::oArt:cCodPrp2
                  ::oPedCliL:cValPr1     := ::GetValPrp( oRetFld( ::oArt:cCodPrp1, ::oPro, "cCodWeb", "cCodPro" ), oQueryL:FieldGet( 7 ) )
                  ::oPedCliL:cValPr2     := ::GetValPrp( oRetFld( ::oArt:cCodPrp2, ::oPro, "cCodWeb", "cCodPro" ), oQueryL:FieldGet( 7 ) )
                  ::oPedCliL:lLote       := ::oArt:lLote 
                  ::oPedCliL:cLote       := ::oArt:cLote 

               end if

            if !::oPedCliL:Save()
               ::treeSetText( "Error al descargar las lineas el pedido: " ;
                               + ::cSeriePedido + "/" + alltrim( str( ::nNumeroPedido ) ) ;
                               + "/" + ::cSufijoPedido, 3 )
            end if

            oQueryL:Skip()

            nNumLin++

            end while

         end if

      end if

return ( .t. )

//---------------------------------------------------------------------------//

METHOD appendStatePedidoPrestashop( oQuery ) CLASS TComercio

   local oQueryState
   
   oQueryState    := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "order_history" ) + " h inner join "+ ::cPrefixtable( "order_state_lang" ) + " s on h.id_order_state = s.id_order_state WHERE s.id_lang = " + str( ::nLanguage ) + " and id_order = " + alltrim( str( ::idOrderPrestashop ) ) )

   if oQueryState:Open()

      if oQueryState:RecCount() > 0

         oQueryState:GoTop()

         while !oQueryState:Eof()

            ::oPedCliE:Append()
            ::oPedCliE:Blank()

            ::oPedCliE:cSerPed   := ::cSeriePedido
            ::oPedCliE:nNumPed   := ::nNumeroPedido
            ::oPedCliE:cSufPed   := ::cSufijoPedido
            ::oPedCliE:cSitua    := oQueryState:FieldGetByName( "name" )
            ::oPedCliE:dFecSit   := ::getDate( oQueryState:FieldGetByName( "date_add" ) )
            ::oPedCliE:tFecSit   := ::getTime( oQueryState:FieldGetByName( "date_add" ) )
            ::oPedCliE:idPs      := oQueryState:FieldGetByName( "id_order_history" )
                     
            ::oPedCliE:Save()

         oQueryState:Skip()

          end while

      end if
               
   end if      

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD syncSituacionesPresupuestoPrestashop( cCodWeb, cSerPre, nNumPre, cSufPre ) CLASS TComercio

   if !::connect()
      msginfo( "No ha sido posible la conexion" )
      Return .f.
   end if

   if !::filesOpen()
      Return .f.
   end if 

   ::syncronizeStatesPresupuestoGestool( cCodWeb, cSerPre, nNumPre, cSufPre )

   ::syncronizeStatesPresupuestoPrestashop( cSerPre, nNumPre, cSufPre, cCodWeb )

   ::filesClose()

   ::disconnect()

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD syncronizeStatesPresupuestoGestool( cCodWeb, cSerPre, nNumPre, cSufPre ) CLASS TComercio
   
   local oQueryState
   
   oQueryState   := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "order_history" ) +" where id_order = " + alltrim( str( cCodWeb ) ) )

   if oQueryState:Open() .and. oQueryState:RecCount() > 0

      while !oQueryState:eof()

         ::presupuestoCheckExistStateUp( oQueryState, cCodWeb, cSerPre, nNumPre, cSufPre )

         oQueryState:Skip()

      end while
      
   end if

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD presupuestoCheckExistStateUp( oQuery, cCodWeb, cSerPre, nNumPre, cSufPre ) CLASS TComercio

   if !::oPreCliE:SeekInOrd( str( oQuery:FieldGetByName( "id_order_history" ), 11 ), "idPs" )
      ::downloadStateToPresupuesto( oQuery, cSerPre, nNumPre, cSufPre )
   endif

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD downloadStateToPresupuesto( oQuery, cSerPre, nNumPre, cSufPre ) CLASS TComercio

   local oQueryState          := TMSQuery():New( ::oCon, "SELECT * FROM " +::cPrefixtable( "order_state_lang" ) + " WHERE id_lang = " + str( ::nLanguage ) + " and id_order_state = " + alltrim( str( oQuery:FieldGetByName( "id_order_state" ) ) ) ) 

   if oQueryState:Open() .and. oQueryState:RecCount() > 0

         ::oPreCliE:Append()
         ::oPreCliE:Blank()

         ::oPreCliE:cSerPre   := cSerPre
         ::oPreCliE:nNumPre   := nNumPre
         ::oPreCliE:cSufPre   := cSufPre
         ::oPreCliE:cSitua    := oQueryState:FieldGetByName( "name" )
         ::oPreCliE:dFecSit   := ::getDate( oQuery:FieldGetByName( "date_add" ) )
         ::oPreCliE:tFecSit   := ::getTime( oQuery:FieldGetByName( "date_add" ) )
         ::oPreCliE:idPs      := oQuery:FieldGetByName( "id_order_history" )
                  
         ::oPreCliE:Save()

   end if

Return( .t. )

//---------------------------------------------------------------------------//

METHOD syncronizeStatesPresupuestoPrestashop ( cSerPre, nNumPre, cSufPre, cCodWeb ) CLASS TComercio

   local nRec        := ::oPreCliE:Recno()
   local nOrdAnt     := ::oPreCliE:OrdSetFocus( "NNUMPRE" )
   local id
   local oQuery
   
   oQuery   := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "order_history" ) + " where id_order = " + alltrim( str( cCodWeb ) ) )

   
   if oQuery:Open() .and. oQuery:RecCount() > 0

      if ::oPreCliE:Seek( cSerPre + str( nNumPre ) + cSufPre )

         while ( ::oPreCliE:cSerPre + str( ::oPreCliE:nNumPre ) + ::oPreCliE:cSufPre ) == ( cSerPre + str( nNumPre ) + cSufPre ) .and. !::oPreCliE:eof()
        
            if empty( ::oPreCliE:idPs )
                 
               id       := ::UploadStatePrestashop( ::idOrderState( ::oPreCliE:cSitua ), ::oPreCliE:dFecSit, ::oPreCliE:tFecSit, cCodWeb )      

               if !empty( id )
                  ::oPreCliE:fieldPutByName( "idPs", id )
               end if 
            endif

            ::oPreCliE:Skip()  

         end while

      endif

   endif

   ::oPreCliE:OrdSetFocus( nOrdAnt )
   ::oPreCliE:GoTo( nRec )

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD UploadStatePrestashop( id_order_state, dFecSit, tFecSit, cCodWeb ) CLASS TComercio

   local id 
   local cCommand 

   cCommand      :=  "INSERT INTO " + ::cPrefixtable( "order_history" ) + " VALUES ( '', 1, " + alltrim( str( cCodWeb ) ) + ", " + alltrim( str( id_order_state ) ) + ", '" + ::getDatePrestashop( dFecSit, tFecSit ) + "' )" 

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      id             := ::oCon:GetInsertId()   
   end if 

Return ( id  )

//---------------------------------------------------------------------------//

METHOD syncSituacionesPedidoPrestashop( cCodWeb, cSerPed, nNumPed, cSufPed ) CLASS TComercio

   if !::connect()
      msginfo( "No ha sido posible la conexion" )
      Return .f.
   end if

   if !::filesOpen()
      Return .f.
   end if 

   ::syncronizeStatesGestool( cCodWeb, cSerPed, nNumPed, cSufPed )

   ::syncronizeStatesPrestashop( cSerPed, nNumPed, cSufPed, cCodWeb )

   ::filesClose()

   ::disconnect()

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD syncronizeStatesGestool( cCodWeb, cSerPed, nNumPed, cSufPed ) CLASS TComercio
   
   local oQueryState
   
   oQueryState   := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "order_history" ) +" where id_order = " + alltrim( str( cCodWeb ) ) )

   if oQueryState:Open() .and. oQueryState:RecCount() > 0

      while !oQueryState:eof()

         ::checkExistStateUp( oQueryState, cCodWeb, cSerPed, nNumPed, cSufPed )

         oQueryState:Skip()

      end while
      
   end if

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD checkExistStateUp( oQuery, cCodWeb, cSerPed, nNumPed, cSufPed ) CLASS TComercio

   if !::oPedCliE:SeekInOrd( str( oQuery:FieldGetByName( "id_order_history" ), 11 ), "idPs" )
      ::downloadState( oQuery, cSerPed, nNumPed, cSufPed)
   endif

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD downloadState( oQuery, cSerPed, nNumPed, cSufPed ) CLASS TComercio

   local oQueryState

   oQueryState          := TMSQuery():New( ::oCon, "SELECT * FROM " +::cPrefixtable( "order_state_lang" ) + " WHERE id_lang = " + str( ::nLanguage ) + " and id_order_state = " + alltrim( str( oQuery:FieldGetByName( "id_order_state" ) ) ) ) 

   if oQueryState:Open() .and. oQueryState:RecCount() > 0

         ::oPedCliE:Append()
         ::oPedCliE:Blank()

         ::oPedCliE:cSerPed   := cSerPed
         ::oPedCliE:nNumPed   := nNumPed
         ::oPedCliE:cSufPed   := cSufPed
         ::oPedCliE:cSitua    := oQueryState:FieldGetByName( "name" )
         ::oPedCliE:dFecSit   := ::getDate( oQuery:FieldGetByName( "date_add" ) )
         ::oPedCliE:tFecSit   := ::getTime( oQuery:FieldGetByName( "date_add" ) )
         ::oPedCliE:idPs      := oQuery:FieldGetByName( "id_order_history" )
                  
         ::oPedCliE:Save()

   end if

Return( .t. )

//---------------------------------------------------------------------------//

METHOD syncronizeStatesPrestashop ( cSerPed, nNumPed, cSufPed, cCodWeb ) CLASS TComercio

   local nRec        := ::oPedCliE:Recno()
   local nOrdAnt     := ::oPedCliE:OrdSetFocus( "NNUMPED" )
   local id
   local oQuery
   
   oQuery   := TMSQuery():New( ::oCon, "SELECT * FROM " + ::cPrefixtable( "order_history" ) + " where id_order = " + alltrim( str( cCodWeb ) ) )

   
   if oQuery:Open() .and. oQuery:RecCount() > 0

      if ::oPedCliE:Seek( cSerPed + str( nNumPed ) + cSufPed )

         while ( ::oPedCliE:cSerPed + str( ::oPedCliE:nNumPed ) + ::oPedCliE:cSufPed ) == ( cSerPed + str( nNumPed ) + cSufPed ) .and. !::oPedCliE:eof()
        
            if empty( ::oPedCliE:idPs )
                          
               id       := ::UploadState( ::idOrderState( ::oPedCliE:cSitua ), ::oPedCliE:dFecSit, ::oPedCliE:tFecSit, cCodWeb )      

               if !empty( id )
                  ::oPedCliE:fieldPutByName( "idPs", id )
               end if 
            endif

            ::oPedCliE:Skip()  

         end while

      endif

   endif

   ::oPedCliE:OrdSetFocus( nOrdAnt )
   ::oPedCliE:GoTo( nRec )

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD idOrderState( cSitua ) CLASS TComercio

   local oQuery2 
   local idState  

   oQuery2             := TMSQuery():New( ::oCon, "SELECT id_order_state FROM " + ::cPrefixtable( "order_state_lang" ) + " WHERE id_lang = " + str( ::nLanguage ) + " and name = '" + alltrim( cSitua ) + "'" )


   if oQuery2:Open() .and. oQuery2:RecCount() > 0

      idState := oQuery2:FieldGetByName( "id_order_state" )

   endif

Return ( idState )

//---------------------------------------------------------------------------//

METHOD UploadState( id_order_state, dFecSit, tFecSit, cCodWeb ) CLASS TComercio

   local id 
   local cCommand 

   cCommand      :=  "INSERT INTO " + ::cPrefixtable( "order_history" ) + " VALUES ( '', 1, " + alltrim( str( cCodWeb ) ) + ", " + alltrim( str( id_order_state ) ) + ", '" + ::getDatePrestashop(::oPedCliE:dFecSit, ::oPedCliE:tFecSit) + "' )" 

   if TMSCommand():New( ::oCon ):ExecDirect( cCommand )
      id         := ::oCon:GetInsertId()   
   end if 

Return ( id  )

//---------------------------------------------------------------------------//

METHOD buildFTP() CLASS TComercio

   if ::TPrestashopConfig:getFtpLinux()
      ::oFtp      := TFtpLinux():New( ::TPrestashopConfig )
   else 
      ::oFtp      := TFtpWindows():New( ::TPrestashopConfig )
   end if 

Return ( self )

//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//ESTRUCTURAS----------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//

CLASS SImagen

   DATA cNombreImagen      INIT ""
   DATA nTipoImagen        INIT ""
   DATA cCarpeta           INIT ""
   DATA cPrefijoNombre     INIT ""

END CLASS

//---------------------------------------------------------------------------//

CLASS STipoImagen

   DATA cNombreTipo        INIT ""
   DATA nAnchoTipo         INIT 0
   DATA nAltoTipo          INIT 0
   DATA lCategories        INIT .f.
   DATA lProducts          INIT .f.
   DATA lManufactures      INIT .f.
   DATA lSuppliers         INIT .f.
   DATA lScenes            INIT .f.
   DATA lStores            INIT .f.

END CLASS

//---------------------------------------------------------------------------//

CLASS SCategoria

   DATA id           INIT 0
   DATA idParent     INIT 0
   DATA nLeft        INIT 0
   DATA nRight       INIT 0
   DATA nTipo        INIT 0   //1-Grupo  -  2-Familia  -  3-Tipo

END CLASS

//---------------------------------------------------------------------------//
//FUNCIONES------------------------------------------------------------------//
//---------------------------------------------------------------------------//

function cLinkRewrite( cLink )

   local cCaracter   := ""
   local cResult     := ""
   local cCarAnt     := ""

   cLink             := alltrim( cLink )

   for each cCaracter in cLink

      do case
         case ( Asc( cCaracter ) >= 48 .and. Asc( cCaracter ) <= 57 ) .or.;
              ( Asc( cCaracter ) >= 65 .and. Asc( cCaracter ) <= 90 ) .or.;
              ( Asc( cCaracter ) >= 97 .and. Asc( cCaracter ) <= 122 )

            cResult     := cResult + cCaracter

         case Asc( cCaracter ) == 32

            if Asc( cCarAnt ) != 32
               cResult  := cResult + "-"
            end if   

         otherwise

            cResult     := cResult + ReemplazaAcento( cCaracter )

      end case

      cCarAnt           := cCaracter

   next

   if !empty( cResult )
      cResult           := lower( cResult )
   end if  

Return( cResult )

//---------------------------------------------------------------------------//

Function ReemplazaAcento( cCaracter )

   local nPos
   local cPatron     := "�����������������������������������������������������������"
   local cReemplazo  := "AAAAAAACEEEEIIIIDNOOOOOUUUUYaaaaaaaceeeeiiiinooooouuuuyySsY"
   local cResultado  := Space( 0 )

   nPos              := At( cCaracter, cPatron )

   if nPos != 0
      cResultado     := Substr( cReemplazo, nPos, 1 )
   end if

return ( cResultado )

//---------------------------------------------------------------------------//

Function SetAutoRecive()

   if empty( oComercio )
      oComercio   := TComercio():New()
   end if

   if !empty( oComercio )           .and. ;
      !empty( oComercio:cHost )     .and. ;
      !empty( oComercio:cUser )     .and. ;
      !empty( oComercio:cPasswd )   .and. ;
      !empty( oComercio:cDbName )   .and. ;
      ( oComercio:nSecondTimer != 0 )

      oTimer      := TTimer():New( oComercio:nSecondTimer, {|| oComercio:AutoRecive() } )
      oTimer:dialogActivate()

   end if

Return( nil )

//---------------------------------------------------------------------------//

Function KillAutoRecive()

   if !empty( oTimer )
      oTimer:End()
   end if

   oTimer         := nil
   oComercio      := nil

Return( nil )

//---------------------------------------------------------------------------//
