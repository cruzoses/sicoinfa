#include "FiveWin.Ch"
#include "Factu.ch"
#include "Xbrowse.ch"

CLASS ReceiptInvoiceCustomer FROM DocumentsSales  
  
   DATA cNumeroFactura                    INIT ""
   DATA nImporteAnterior                  INIT 0
   DATA nOrdenAnterior
   DATA lShowFilterCobrado                INIT .t.
   DATA lCloseFiles                       INIT .t.

   METHOD New()

   METHOD Play()

   METHOD getEditDocumento()

   METHOD onPreEnd()

   METHOD onPostGetDocumento()

   METHOD onViewSave()

   METHOD onPreSaveEdit()

   METHOD deleteLinesDocument()           INLINE ( .t. )

   METHOD assignLinesDocument()           INLINE ( .t. )

   METHOD setLinesDocument()              INLINE ( .t. )

   METHOD onPreEditDocumento()

   METHOD addReciboDiferencia()

   METHOD FilterTable()

   METHOD onPreRunNavigator()

END CLASS

//---------------------------------------------------------------------------//

METHOD New( oInvoice ) CLASS ReceiptInvoiceCustomer

   ::super:oSender         := self

   if Empty( oInvoice )

      if !::openFiles()
         return ( self )
      end if 

   else

      ::lCloseFiles           := .f.
      ::nView                 := oInvoice:nView
      ::cNumeroFactura        := oInvoice:GetId()
      ::lShowFilterCobrado    := Empty( oInvoice:GetId() )

   end if

   ::oViewSearchNavigator  := ReceiptDocumentSalesViewSearchNavigator():New( self )
   ::oViewSearchNavigator:setTitleDocumento( "Recibos de clientes" )  

   ::oViewEdit             := ReceiptDocumentSalesViewEdit():New( self )
   ::oViewEdit:setTitleDocumento( "Recibo cliente" )  

   ::setTypePrintDocuments( "RF" )

   ::setCounterDocuments( "NRECCLI" )

   // Areas--------------------------------------------------------------------

   ::setDataTable( "FacCliP" )

Return ( self )

//---------------------------------------------------------------------------//

METHOD play() CLASS ReceiptInvoiceCustomer

   if ::onPreRunNavigator()
      ::runNavigator()
   end if 

   if ::lCloseFiles
      ::closeFiles()
   end if

return ( self )

//---------------------------------------------------------------------------//

METHOD getEditDocumento() CLASS ReceiptInvoiceCustomer

   local id                := D():FacturasClientesCobrosId( ::nView )

   if Empty( id )
      Return .f.
   end if

   ::hDictionaryMaster     := D():getFacturaClienteCobros( ::nView )

   if empty( ::hDictionaryMaster )
      Return .f.
   end if 

Return ( .t. )

//----------------------------------------------------------------------------//

METHOD onViewSave() CLASS ReceiptInvoiceCustomer

   ::oViewEdit:oDlg:end( IDOK )

Return ( self )

//---------------------------------------------------------------------------//

METHOD onPreSaveEdit() CLASS ReceiptInvoiceCustomer

   local nNuevoImporte        := 0
   local nImporteReciboNuevo  := 0

   /*
   Convertimos el estado a Lógico----------------------------------------------
   */

   hSet( ::oSender:hDictionaryMaster, "LogicoCobrado", ( ::oViewEdit:cCbxEstado == "Cobrado" ) )

   /*
   Vemos si hay que generar un nuevo recibo------------------------------------
   */

   nNuevoImporte  := hGet( ::oSender:hDictionaryMaster, "TotalDocumento" )

   if nNuevoImporte != ::nImporteAnterior
      
      nImporteReciboNuevo     := ( ::nImporteAnterior - nNuevoImporte ) * if( ::nImporteAnterior < 0, - 1 , 1 )

      ::addReciboDiferencia( nImporteReciboNuevo )

   end if

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD onPostGetDocumento() CLASS ReceiptInvoiceCustomer

   ::oldSerie           := ::getSerie()   

   ::nImporteAnterior   := hGet( ::oSender:hDictionaryMaster, "TotalDocumento" )

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD onPreEditDocumento() CLASS ReceiptInvoiceCustomer

   ::nOrdenAnterior     := ( ::getDataTable() )->( OrdSetFocus() )

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD onPreEnd() CLASS ReceiptInvoiceCustomer

   local cNumeroFactura    := ( ::getDataTable() )->cSerie + Str( ( ::getDataTable() )->nNumFac ) + ( ::getDataTable() )->cSufFac

   /*
   Chequeamos el estado de la factura antes de terminar------------------------
   */

   if ( D():FacturasClientes( ::nView ) )->( dbSeek( cNumeroFactura ) )
      ChkLqdFacCli( nil, D():FacturasClientes( ::nView ), D():FacturasClientesLineas( ::nView ), D():FacturasClientesCobros( ::nView ), D():AnticiposClientes( ::nView ), D():TiposIva( ::nView ), D():Divisas( ::nView ), .f. )
   end if

   ( ::getDataTable() )->( OrdSetFocus( ::nOrdenAnterior ) )

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD addReciboDiferencia( nImporteRecibo ) CLASS ReceiptInvoiceCustomer

   local nRec        := ( ::getDataTable() )->( Recno() )
   local aTabla
   local nCount
   local cNumRec     := ""

   aTabla            := dbScatter( ::getDataTable() )

   cNumRec           += aTabla[ ( ::getDataTable() )->( fieldpos( "cSerie" ) ) ]
   cNumRec           += Str( aTabla[ ( ::getDataTable() )->( fieldpos( "nNumFac" ) ) ] )
   cNumRec           += aTabla[ ( ::getDataTable() )->( fieldpos( "cSufFac" ) ) ]

   nCount            := nNewReciboCliente( cNumRec, aTabla[ ( ::getDataTable() )->( fieldpos( "cTipRec" ) ) ], ::getDataTable() )

   /*
   Añadimos el nuevo recibo-------------------------------------------------
   */

   ( ::getDataTable() )->( dbAppend() )

   ( ::getDataTable() )->cTurRec    := cCurSesion()
   ( ::getDataTable() )->cTipRec    := aTabla[ ( ::getDataTable() )->( fieldpos( "cTipRec" ) ) ]
   ( ::getDataTable() )->cSerie     := aTabla[ ( ::getDataTable() )->( fieldpos( "cSerie" ) ) ]
   ( ::getDataTable() )->nNumFac    := aTabla[ ( ::getDataTable() )->( fieldpos( "nNumFac" ) ) ]
   ( ::getDataTable() )->cSufFac    := aTabla[ ( ::getDataTable() )->( fieldpos( "cSufFac" ) ) ]
   ( ::getDataTable() )->nNumRec    := nCount
   ( ::getDataTable() )->cCodCaj    := aTabla[ ( ::getDataTable() )->( fieldpos( "cCodCaj" ) ) ]
   ( ::getDataTable() )->cCodCli    := aTabla[ ( ::getDataTable() )->( fieldpos( "cCodCli" ) ) ]
   ( ::getDataTable() )->cNomCli    := aTabla[ ( ::getDataTable() )->( fieldpos( "cNomCli" ) ) ]
   ( ::getDataTable() )->cCodAge    := aTabla[ ( ::getDataTable() )->( fieldpos( "cCodAge" ) ) ] 
   ( ::getDataTable() )->dEntrada   := Ctod( "" )
   ( ::getDataTable() )->nImporte   := nImporteRecibo
   ( ::getDataTable() )->nImpCob    := nImporteRecibo
   ( ::getDataTable() )->cDescrip   := "Recibo nº" + AllTrim( str( nCount ) ) + " de factura " + if( !empty( aTabla[ ( ::getDataTable() )->( fieldpos( "cTipRec" ) ) ] ), "rectificativa ", "" ) + aTabla[ ( ::getDataTable() )->( fieldpos( "cSerie" ) ) ] + '/' + AllTrim( str( aTabla[ ( ::getDataTable() )->( fieldpos( "nNumFac" ) ) ] ) ) + '/' + aTabla[ ( ::getDataTable() )->( fieldpos( "cSufFac" ) ) ]
   ( ::getDataTable() )->dPreCob    := dFecFacCli( cNumRec, D():FacturasClientes( ::nView ) )
   ( ::getDataTable() )->cPgdoPor   := ""
   ( ::getDataTable() )->lCobrado   := .f.
   ( ::getDataTable() )->cDivPgo    := aTabla[ ( ::getDataTable() )->( fieldpos( "cDivPgo" ) ) ]
   ( ::getDataTable() )->nVdvPgo    := aTabla[ ( ::getDataTable() )->( fieldpos( "nVdvPgo" ) ) ]
   ( ::getDataTable() )->cCodPgo    := aTabla[ ( ::getDataTable() )->( fieldpos( "cCodPgo" ) ) ]
   ( ::getDataTable() )->lConPgo    := .f.
   ( ::getDataTable() )->dFecCre    := GetSysDate()
   ( ::getDataTable() )->cHorCre    := Substr( Time(), 1, 5 )

   ( ::getDataTable() )->( dbUnLock() )

   ( ::getDataTable() )->( dbGoTo( nRec ) )

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD FilterTable( cTextFilter ) CLASS ReceiptInvoiceCustomer

   do case
      case cTextFilter == "Todos"
         ( ::getDataTable() )->( dbClearFilter() )
      case cTextFilter == "Pendientes"
         ( ::getDataTable() )->( dbSetFilter( {|| !Field->lCobrado }, "!lCobrado" ) )
      case cTextFilter == "Cobrados"
         ( ::getDataTable() )->( dbSetFilter( {|| Field->lCobrado }, "lCobrado" ) )
   end case

   ( ::getDataTable() )->( dbGoTop() )

   ::oViewSearchNavigator:oBrowse:Refresh()

return ( .t. )

//---------------------------------------------------------------------------//

METHOD onPreRunNavigator() CLASS ReceiptInvoiceCustomer

   if empty( ::getWorkArea() )
      Return .t.
   end if 

   if !Empty( ::cNumeroFactura )
      
      if !( D():FacturasClientes( ::nView ) )->( dbSeek( ::cNumeroFactura ) )
         Return ( .f. )
      end if

   end if

   ( ::getWorkArea() )->( ordsetfocus( "dFecDes" ) )
   ( ::getWorkArea() )->( dbgotop() ) 

   if !Empty( ::cNumeroFactura )

      ( ::getWorkArea() )->( dbsetfilter( {|| Field->cSerie + Str( Field->nNumFac ) + Field->cSufFac == ::cNumeroFactura }, "Field->cSerie + Str( Field->nNumFac ) + Field->cSufFac == '" + ::cNumeroFactura + "'" ) )
      ( ::getWorkArea() )->( dbgotop() )

   else

      if ( accessCode():lFilterByAgent ) .and. !empty( accessCode():cAgente )
      
         ( ::getWorkArea() )->( dbsetfilter( {|| Field->cCodAge == accessCode():cAgente }, "Field->cCodAge == '" + accessCode():cAgente + "'" ) )
         ( ::getWorkArea() )->( dbgotop() )

         ( D():Clientes( ::nView ) )->( dbsetfilter( {|| Field->cAgente == accessCode():cAgente }, "Field->cCodAge == '" + accessCode():cAgente + "'" ) )
         ( D():Clientes( ::nView ) )->( dbgotop() )

      end if 

   end if

Return ( .t. )

//---------------------------------------------------------------------------//