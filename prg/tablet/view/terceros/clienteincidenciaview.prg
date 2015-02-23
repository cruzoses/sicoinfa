#include "FiveWin.Ch"
#include "Factu.ch" 
#include "Xbrowse.ch"

CLASS ClienteIncidenciaView FROM ViewBase
  
   METHOD New()

   METHOD insertControls()

   METHOD defineTipo()

   METHOD defineFecha()

   METHOD defineIncidencia()

   METHOD defineCombo()

END CLASS

//---------------------------------------------------------------------------//

METHOD New( oSender ) CLASS ClienteIncidenciaView

   ::oSender               := oSender

Return ( self )

//---------------------------------------------------------------------------//

METHOD insertControls( nMode ) CLASS ClienteIncidenciaView

   ::defineTipo()

   ::defineCombo()

   ::defineFecha()

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineCombo() CLASS ClienteIncidenciaView

   local oCombo

   oCombo   := TGridComboBox():Build(  {  "nRow"      => 70,;
                                          "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                                          "bSetGet"   => {|u| ::SetGetValue( u, "Tipo" ) },;
                                          "oWnd"      => ::oDlg,;
                                          "nWidth"    => {|| GridWidth( 6, ::oDlg ) },;
                                          "nHeight"   => 25,;
                                          "aItems"    => D():getTiposIncicencias( ::getView() ) } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineTipo() CLASS ClienteIncidenciaView

   local getCodigo

   TGridUrllink():Build(            {  "nTop"      => 40,;
                                       "nLeft"     => {|| GridWidth( 0.5, ::oDlg ) },;
                                       "cURL"      => "Tipo",;
                                       "oWnd"      => ::oDlg,;
                                       "oFont"     => oGridFont(),;
                                       "lPixel"    => .t.,;
                                       "nClrInit"  => nGridColor(),;
                                       "nClrOver"  => nGridColor(),;
                                       "nClrVisit" => nGridColor(),;
                                       "bAction"   => {|| msgAlert("getLastNum") } } )

   getCodigo   := TGridGet():Build( {  "nRow"      => 40,;
                                       "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                                       "bSetGet"   => {|u| ::SetGetValue( u, "Tipo" ) },;
                                       "oWnd"      => ::oDlg,;
                                       "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                                       "bWhen"     => {|| ::nMode == APPD_MODE .or. ::nMode == DUPL_MODE },;
                                       "nHeight"   => 23,;
                                       "cPict"     => "@!",;
                                       "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineFecha() CLASS ClienteIncidenciaView

   local getFecha

   TGridUrllink():Build(            {  "nTop"      => 100,;
                                       "nLeft"     => {|| GridWidth( 0.5, ::oDlg ) },;
                                       "cURL"      => "Fecha",;
                                       "oWnd"      => ::oDlg,;
                                       "oFont"     => oGridFont(),;
                                       "lPixel"    => .t.,;
                                       "nClrInit"  => nGridColor(),;
                                       "nClrOver"  => nGridColor(),;
                                       "nClrVisit" => nGridColor() } )

   getFecha   := TGridGet():Build( {  "nRow"      => 100,;
                                       "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                                       "bSetGet"   => {|u| ::SetGetValue( u, "Fecha" ) },;
                                       "oWnd"      => ::oDlg,;
                                       "nWidth"    => {|| GridWidth( 9.0, ::oDlg ) },;
                                       "nHeight"   => 23,;
                                       "cPict"     => "@!",;
                                       "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineIncidencia() CLASS ClienteIncidenciaView

   local getIncidencia

   TGridUrllink():Build(               {  "nTop"      => 70,;
                                          "nLeft"     => {|| GridWidth( 0.5, ::oDlg ) },;
                                          "cURL"      => "Nombre",;
                                          "oWnd"      => ::oDlg,;
                                          "oFont"     => oGridFont(),;
                                          "lPixel"    => .t.,;
                                          "nClrInit"  => nGridColor(),;
                                          "nClrOver"  => nGridColor(),;
                                          "nClrVisit" => nGridColor() } )

   getIncidencia  := TGridGet():Build( {  "nRow"      => 70,;
                                          "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                                          "bSetGet"   => {|u| ::SetGetValue( u, "Nombre" ) },;
                                          "oWnd"      => ::oDlg,;
                                          "nWidth"    => {|| GridWidth( 9.0, ::oDlg ) },;
                                          "nHeight"   => 23,;
                                          "cPict"     => "@!",;
                                          "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

