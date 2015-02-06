#include "FiveWin.Ch"
#include "Factu.ch" 
#include "Xbrowse.ch"

CLASS ViewEditResumen FROM ViewBase

   DATA oDlg
   DATA oSender

   METHOD New()

   METHOD ResourceViewEditResumen()

   METHOD defineBotonesGenerales()

   METHOD defineCliente()

   METHOD defineFormaPago()

   METHOD defineComboImpresion()

END CLASS

//---------------------------------------------------------------------------//

METHOD New( oSender ) CLASS ViewEditResumen

   ::oSender   := oSender

Return ( self )

//---------------------------------------------------------------------------//

METHOD ResourceViewEditResumen( oDlgMaster ) CLASS ViewEditResumen

   ::oDlg   := TDialog():New( 1, 5, 40, 100, "GESTOOL TABLET",,, .f., ::Style,, rgb( 255, 255, 255 ),,, .F.,, oGridFont(),,,, .f.,, "oDlg" )

   ::TituloBrowse()

   ::defineBotonesGenerales()

   ::defineCliente()

   ::defineFormaPago()

   ::defineComboImpresion()

   ::oDlg:bResized         := {|| ::DialogResize() }

   ::oDlg:Activate( ,,,.t.,,, {|| ::InitDialog() } )

Return ( ::oDlg:nResult == IDOK )

//---------------------------------------------------------------------------//

METHOD defineBotonesGenerales() CLASS ViewEditResumen


   TGridImage():Build(  {  "nTop"      => 5,;
                           "nLeft"     => {|| GridWidth( 7.5, ::oDlg ) },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "flat_del_64",;
                           "bLClicked" => {|| MsgInfo( "Cancelamos" ), ::oDlg:End() },;
                           "oWnd"      => ::oDlg } )

   TGridImage():Build(  {  "nTop"      => 5,;
                           "nLeft"     => {|| GridWidth( 9, ::oDlg ) },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "flat_printer_64",;
                           "bLClicked" => {|| MsgInfo( "Aceptamos" ), ::oDlg:End() },;
                           "oWnd"      => ::oDlg } )

   TGridImage():Build(  {  "nTop"      => 5,;
                           "nLeft"     => {|| GridWidth( 10.5, ::oDlg ) },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "flat_check_64",;
                           "bLClicked" => {|| MsgInfo( "Aceptamos e imprimimos" ), ::oDlg:End() },;
                           "oWnd"      => ::oDlg } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineCliente() CLASS ViewEditResumen

   local cCodCliente    := ""
   local cNomCliente    := ""

   TGridSay():Build( {  "nRow"      => 40,;
                        "nCol"      => {|| GridWidth( 0.5, ::oDlg ) },;
                        "bText"     => {|| "Cliente: " },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => 40,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "oWnd"      => ::oDlg,;
                        "bSetGet"   => {|u| if( PCount() == 0, cCodCliente, cCodCliente := u ) },;
                        "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "bWhen"     => {|| .f. },;
                        "lPixels"   => .t. } )
   
   TGridGet():Build( {  "nRow"      => 40,;
                        "nCol"      => {|| GridWidth( 4.5, ::oDlg ) },;
                        "oWnd"      => ::oDlg,;
                        "bSetGet"   => {|u| if( PCount() == 0, cNomCliente, cNomCliente := u ) },;
                        "lPixels"   => .t.,;
                        "nWidth"    => {|| GridWidth( 7, ::oDlg ) },;
                        "bWhen"     => {|| .f.},;
                        "nHeight"   => 23 } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineFormaPago() CLASS ViewEditResumen

   local cCodFPago      := ""
   local cNomFPago      := ""

   TGridUrllink():Build({  "nTop"      => 65,;
                           "nLeft"     => {|| GridWidth( 0.5, ::oDlg ) },;
                           "cURL"      => "F. pago",;
                           "oWnd"      => ::oDlg,;
                           "oFont"     => oGridFont(),;
                           "lPixel"    => .t.,;
                           "nClrInit"  => nGridColor(),;
                           "nClrOver"  => nGridColor(),;
                           "nClrVisit" => nGridColor(),;
                           "bAction"   => {|| MsgInfo( "Browse de formas de pago" )  } } ) // GridBrwfPago( aGet[ _CCODPAGO ], oGetNombrePago ) } } )

   TGridGet():Build( {     "nRow"      => 65,;
                           "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                           "bSetGet"   => {|u| if( PCount() == 0, cCodFPago, cCodFPago := u ) },;
                           "oWnd"      => ::oDlg,;
                           "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                           "nHeight"   => 23,;
                           "lPixels"   => .t.,;
                           "bValid"    => {|| .t. } } )  //cFpago( aGet[ _CCODPAGO ], dbfFPago, oGetNombrePago ) } } )

   TGridGet():Build(  {    "nRow"      => 65,;
                           "nCol"      => {|| GridWidth( 4.5, ::oDlg ) },;
                           "bSetGet"   => {|u| if( PCount() == 0, cNomFPago, cNomFPago := u ) },;
                           "oWnd"      => ::oDlg,;
                           "nWidth"    => {|| GridWidth( 7, ::oDlg ) },;
                           "lPixels"   => .t.,;
                           "nHeight"   => 23 } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineComboImpresion() CLASS ViewEditResumen

   TGridSay():Build(    {     "nRow"      => 90,;
                              "nCol"      => {|| GridWidth( 0.5, ::oDlg ) },;
                              "bText"     => {|| "Impresi�n:" },;
                              "oWnd"      => ::oDlg,;
                              "oFont"     => oGridFont(),;
                              "lPixels"   => .t.,;
                              "nClrText"  => Rgb( 0, 0, 0 ),;
                              "nClrBack"  => Rgb( 255, 255, 255 ),;
                              "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                              "nHeight"   => 25,;
                              "lDesign"   => .f. } )

   /*TGridComboBox():Build(  {  "nRow"      => 90,;
                              "nCol"      => {|| GridWidth( 2.5, oDlg ) },;
                              "bSetGet"   => {|u| if( PCount() == 0, cCbxOrd, cCbxOrd := u ) },;
                              "oWnd"      => oDlg,;
                              "nWidth"    => {|| GridWidth( 9, oDlg ) },;
                              "nHeight"   => 25,;
                              "aItems"    => aCbxOrd } )*/

Return ( self )

//---------------------------------------------------------------------------//