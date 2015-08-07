#include "FiveWin.Ch"
#include "Factu.ch" 
#include "Xbrowse.ch"

CLASS DailySummarySalesView FROM ViewBase

   DATA oFecIni
   DATA dFecIni               INIT GetSysDate()
   DATA oFecFin
   DATA dFecFin               INIT GetSysDate()
   DATA oPedido               INIT ""
   DATA oPedidoTotal          INIT ""
   DATA oAlbaran              INIT ""
   DATA oAlbaranTotal         INIT ""
   DATA oFactura              INIT ""
   DATA oFacturaTotal         INIT ""
   DATA oTotal                INIT ""

   DATA oCbxRango
   DATA aCbxRango             INIT {}
   DATA cCbxRango             INIT "Hoy"

   METHOD New()

   METHOD insertControls()

   METHOD defineAceptarCancelar()

   METHOD defineFechas()

   METHOD defineCabecera()

   METHOD definePedidos()

   METHOD defineAlbaranes()
   
   METHOD defineFacturas()

   METHOD defineTotal()

   METHOD cargaPeriodo()

   METHOD getTitleTipoDocumento()   INLINE ( ::getTextoTipoDocumento() )

END CLASS

//---------------------------------------------------------------------------//

METHOD New( oSender ) CLASS DailySummarySalesView

   ::oSender   := oSender

Return ( self )

//---------------------------------------------------------------------------//

METHOD insertControls() CLASS DailySummarySalesView

   ::cargaPeriodo()

   ::defineFechas()

   ::defineCabecera()

   ::definePedidos()

   ::defineAlbaranes()

   ::defineFacturas()

   ::defineTotal()

Return( Self )

//---------------------------------------------------------------------------//

METHOD defineAceptarCancelar() CLASS DailySummarySalesView

   
   TGridImage():Build(  {  "nTop"      => 5,;
                           "nLeft"     => {|| GridWidth( 10.5, ::oDlg ) },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "flat_check_64",;
                           "bLClicked" => {|| ::oDlg:End() },;
                           "oWnd"      => ::oDlg } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineFechas() CLASS DailySummarySalesView

   ::oCbxRango    := TGridComboBox():Build(  {  "nRow"      => 50,;
                                                "nCol"      => {|| GridWidth( 0.5, ::oDlg ) },;
                                                "bSetGet"   => {|u| if( PCount() == 0, ::cCbxRango, ::cCbxRango := u ) },;
                                                "oWnd"      => ::oDlg,;
                                                "nWidth"    => {|| GridWidth( 3.5, ::oDlg ) },;
                                                "nHeight"   => 25,;
                                                "aItems"    => ::aCbxRango,;
                                                "bChange"   => {|| MsgInfo( "Cambio el combo" ) } } )

   ::oFecIni      := TGridGet():Build( {        "nRow"      => 50,;
                                                "nCol"      => {|| GridWidth( 5, ::oDlg ) },;
                                                "bSetGet"   => {|u| if( PCount() == 0, ::dFecIni, ::dFecIni := u ) },;
                                                "oWnd"      => ::oDlg,;
                                                "lPixels"   => .t.,;
                                                "nWidth"    => {|| GridWidth( 2.5, ::oDlg ) },;
                                                "nHeight"   => 23,;
                                                "lRight"    => .t. } ) 

   ::oFecFin      := TGridGet():Build( {        "nRow"      => 50,;
                                                "nCol"      => {|| GridWidth( 8, ::oDlg ) },;
                                                "bSetGet"   => {|u| if( PCount() == 0, ::dFecFin, ::dFecFin := u ) },;
                                                "oWnd"      => ::oDlg,;
                                                "lPixels"   => .t.,;
                                                "nWidth"    => {|| GridWidth( 2.5, ::oDlg ) },;
                                                "nHeight"   => 23,;
                                                "lRight"    => .t. } )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD defineCabecera() CLASS DailySummarySalesView

   
   TGridSay():Build( {  "nRow"      => 87,;
                        "nCol"      => {|| GridWidth( 5, ::oDlg ) },;
                        "bText"     => {|| "Documentos" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFontBold(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( 3, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )


   TGridSay():Build( {  "nRow"      => 87,;
                        "nCol"      => {|| GridWidth( 8, ::oDlg ) },;
                        "bText"     => {|| "Total" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFontBold(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( 1.5, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   
Return ( self )

//---------------------------------------------------------------------------//

METHOD definePedidos() CLASS DailySummarySalesView

   ::oSender:CalculatePedido()

   TGridSay():Build( {  "nRow"      => 120,;
                        "nCol"      => {|| GridWidth( 0.5, ::oDlg ) },;
                        "bText"     => {|| "Pedidos de clientes: " },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => 120,;
                        "nCol"      => {|| GridWidth( 5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::oPedido },;
                        "oWnd"      => ::oDlg,;
                        "lPixels"   => .t.,;
                        "nWidth"    => {|| GridWidth( 2.5, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lRight"    => .t.,;
                        "bWhen"     => {|| .f. } } )

   TGridGet():Build( {  "nRow"      => 120,;
                        "nCol"      => {|| GridWidth( 8, ::oDlg ) },;
                        "bSetGet"   => {|u| ::oPedidoTotal },;
                        "oWnd"      => ::oDlg,;
                        "lPixels"   => .t.,;
                        "cPict"     => cPorDiv(),;
                        "nWidth"    => {|| GridWidth( 2.5, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lRight"    => .t.,;
                        "bWhen"     => {|| .f. } } )


Return( Self )

//---------------------------------------------------------------------------//

METHOD defineAlbaranes() CLASS DailySummarySalesView

   ::oSender:CalculateAlbaran()

   TGridSay():Build( {  "nRow"      => 148,;
                        "nCol"      => {|| GridWidth( 0.5, ::oDlg ) },;
                        "bText"     => {|| "Albaranes de clientes: " },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => 148,;
                        "nCol"      => {|| GridWidth( 5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::oAlbaran },;
                        "oWnd"      => ::oDlg,;
                        "lPixels"   => .t.,;
                        "nWidth"    => {|| GridWidth( 2.5, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lRight"    => .t.,;
                        "bWhen"     => {|| .f. } } )

   TGridGet():Build( {  "nRow"      => 148,;
                        "nCol"      => {|| GridWidth( 8, ::oDlg ) },;
                        "bSetGet"   => {|u| ::oAlbaranTotal },;
                        "oWnd"      => ::oDlg,;
                        "lPixels"   => .t.,;
                        "cPict"     => cPorDiv(),;
                        "nWidth"    => {|| GridWidth( 2.5, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lRight"    => .t.,;
                        "bWhen"     => {|| .f. } } )


Return( Self )

//---------------------------------------------------------------------------//

METHOD defineFacturas() CLASS DailySummarySalesView

   ::oSender:CalculateFactura()

   TGridSay():Build( {  "nRow"      => 176,;
                        "nCol"      => {|| GridWidth( 0.5, ::oDlg ) },;
                        "bText"     => {|| "Facturas de clientes: " },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => 176,;
                        "nCol"      => {|| GridWidth( 5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::oFactura },;
                        "oWnd"      => ::oDlg,;
                        "lPixels"   => .t.,;
                        "nWidth"    => {|| GridWidth( 2.5, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lRight"    => .t.,;
                        "bWhen"     => {|| .f. } } )

   TGridGet():Build( {  "nRow"      => 176,;
                        "nCol"      => {|| GridWidth( 8, ::oDlg ) },;
                        "bSetGet"   => {|u| ::oFacturaTotal },;
                        "oWnd"      => ::oDlg,;
                        "lPixels"   => .t.,;
                        "cPict"     => cPorDiv(),;
                        "nWidth"    => {|| GridWidth( 2.5, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lRight"    => .t.,;
                        "bWhen"     => {|| .f. } } )


Return( Self )

//---------------------------------------------------------------------------//

METHOD defineTotal() CLASS DailySummarySalesView

   ::oSender:CalculateTotal()

   TGridSay():Build(    {  "nRow"      => 204,;
                           "nCol"      => {|| GridWidth( 0.5, ::oDlg ) },;
                           "bText"     => {|| "Totales: " },;
                           "oWnd"      => ::oDlg,;
                           "oFont"     => oGridFontBold(),;
                           "lPixels"   => .t.,;
                           "nClrText"  => Rgb( 0, 0, 0 ),;
                           "nClrBack"  => Rgb( 255, 255, 255 ),;
                           "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                           "nHeight"   => 23,;
                           "lDesign"   => .f. } )

   TGridGet():Build(   {   "nRow"      => 204,;
                           "nCol"      => {|| GridWidth( 8, ::oDlg ) },;
                           "bSetGet"   => {|u| ::oTotal },;
                           "oWnd"      => ::oDlg,;
                           "oFont"     => oGridFontBold(),;
                           "lPixels"   => .t.,;
                           "cPict"     => cPorDiv(),;
                           "nWidth"    => {|| GridWidth( 2.5, ::oDlg ) },;
                           "nHeight"   => 23,;
                           "lRight"    => .t.,;
                           "bWhen"     => {|| .f. } } )

Return( Self )

//---------------------------------------------------------------------------//

METHOD cargaPeriodo() CLASS DailySummarySalesView 

   ::aCbxRango                 := {}

   aAdd( ::aCbxRango, "Hoy" )
   aAdd( ::aCbxRango, "Ayer" )
   aAdd( ::aCbxRango, "Mes en curso" )
   aAdd( ::aCbxRango, "Mes anterior" )
   aAdd( ::aCbxRango, "Primer trimestre" )
   aAdd( ::aCbxRango, "Segundo trimestre" )
   aAdd( ::aCbxRango, "Tercer trimestre" )
   aAdd( ::aCbxRango, "Cuatro trimestre" )
   aAdd( ::aCbxRango, "Doce �ltimos meses" )
   aAdd( ::aCbxRango, "A�o en curso" )
   aAdd( ::aCbxRango, "A�o anterior" )

RETURN ( Self )

//---------------------------------------------------------------------------//