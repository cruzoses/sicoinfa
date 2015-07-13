#include "FiveWin.Ch"
#include "Factu.ch" 
#include "Xbrowse.ch"

CLASS CustomerView FROM ViewBase
  
   METHOD New()

   METHOD getTextoTipoDocumento()      INLINE ( LblTitle( ::getMode() ) + "cliente" ) 

   METHOD insertControls()

   METHOD defineCodigo()

   METHOD defineNombre()

   METHOD defineNIF()

   METHOD defineDomicilio()

   METHOD definePoblacion()

   METHOD defineCodigoPostal()

   METHOD defineProvincia()

   METHOD defineEstablecimiento()

   METHOD defineTipoCliente()

   METHOD defineTelefono()

   METHOD defineEmail()

END CLASS

//---------------------------------------------------------------------------//

METHOD New( oSender ) CLASS CustomerView

   ::oSender               := oSender

Return ( self )

//---------------------------------------------------------------------------//

METHOD insertControls() CLASS CustomerView

   ::defineCodigo(40)

   ::defineTipoCliente(70)
   
   ::defineNombre(100)

   ::defineNIF(130)

   ::defineDomicilio(160)

   ::definePoblacion(190)

   ::defineCodigoPostal(220)

   ::defineProvincia(250)
   
   ::defineTelefono(280)

   ::defineEmail(310)

   ::defineEstablecimiento(340)

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineCodigo(nRow) CLASS CustomerView

   local oCodigo

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "C�digo *" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23 } )
   
   oCodigo  := TGridGet():Build( {  "nRow"      => nRow,;
                                    "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                                    "bSetGet"   => {|u| ::SetGetValue( u, "Codigo" ) },;
                                    "oWnd"      => ::oDlg,;
                                    "nWidth"    => {|| GridWidth( 2, ::oDlg ) },;
                                    "bWhen"     => {|| ::getMode() == APPD_MODE },;
                                    "bValid"    => {|| iif( !validKey( oCodigo, ( D():Clientes( ::getView() ) ), .t., "0", 1, RetNumCodCliEmp() ),;
                                                            ::setErrorValidator( "El c�digo ya existe" ),;
                                                            .t. ) },;
                                    "nHeight"   => 23,;
                                    "cPict"     => Replicate( "X", RetNumCodCliEmp() ),;
                                    "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineNIF(nRow) CLASS CustomerView

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "NIF *" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::SetGetValue( u, "NIF" ) },;
                        "oWnd"      => ::oDlg,;
                        "nWidth"    => {|| GridWidth( 9.0, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "cPict"     => "@!",;
                        "bValid"    => {||   iif( empty( hGet( ::oSender:hDictionaryMaster, "NIF" ) ),;
                                                ::setErrorValidator( "El campo NIF es un dato obligatorio" ),;
                                                .t. ) },;
                        "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineNombre(nRow) CLASS CustomerView

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "Nombre *" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::SetGetValue( u, "Nombre" ) },;
                        "oWnd"      => ::oDlg,;
                        "nWidth"    => {|| GridWidth( 9.0, ::oDlg ) },;
                        "bValid"    => {||   iif( empty( hGet( ::oSender:hDictionaryMaster, "Nombre" ) ),;
                                                ::setErrorValidator( "El nombre es un dato obligatorio" ),;
                                                .t. ) },;
                        "nHeight"   => 23,;
                        "cPict"     => "@!",;
                        "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineDomicilio(nRow) CLASS CustomerView

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "Domicilio" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::SetGetValue( u, "Domicilio" ) },;
                        "oWnd"      => ::oDlg,;
                        "nWidth"    => {|| GridWidth( 9, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "cPict"     => "@!",;
                        "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineCodigoPostal(nRow) CLASS CustomerView

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "Cod postal" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::SetGetValue( u, "CodigoPostal" ) },;
                        "oWnd"      => ::oDlg,;
                        "nWidth"    => {|| GridWidth( 9, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "cPict"     => "@!",;
                        "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD definePoblacion(nRow) CLASS CustomerView

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "Poblaci�n" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::SetGetValue( u, "Poblacion" ) },;
                        "oWnd"      => ::oDlg,;
                        "nWidth"    => {|| GridWidth( 9, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "cPict"     => "@!",;
                        "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineProvincia(nRow) CLASS CustomerView

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "Provincia" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::SetGetValue( u, "Provincia" ) },;
                        "oWnd"      => ::oDlg,;
                        "nWidth"    => {|| GridWidth( 9, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "cPict"     => "@!",;
                        "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineEstablecimiento(nRow) CLASS CustomerView

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "Establec." },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::SetGetValue( u, "NombreEstablecimiento" ) },;
                        "oWnd"      => ::oDlg,;
                        "nWidth"    => {|| GridWidth( 9, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "cPict"     => "@!",;
                        "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineTipoCliente( nRow ) CLASS CustomerView

   TGridSay():Build( {  "nRow"      =>  nRow ,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "Tipo" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )


   TGridComboBox():Build(  {  "nRow"      =>  nRow ,;
                              "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                              "bSetGet"   => {|u| iif( empty( u ), ::oSender:cTipoCliente, ::oSender:cTipoCliente := u ) },;
                              "oWnd"      => ::oDlg,;
                              "nWidth"    => {|| GridWidth( 9, ::oDlg ) },;
                              "nHeight"   => 25,;
                              "aItems"    => hGetValues( ::oSender:hTipoCliente ) } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineTelefono(nRow) CLASS CustomerView

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "Tel�fono" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::SetGetValue( u, "Telefono" ) },;
                        "oWnd"      => ::oDlg,;
                        "nWidth"    => {|| GridWidth( 9, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "cPict"     => "@!",;
                        "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//

METHOD defineEmail(nRow) CLASS CustomerView

   TGridSay():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( ::columnLabel, ::oDlg ) },;
                        "bText"     => {|| "email" },;
                        "oWnd"      => ::oDlg,;
                        "oFont"     => oGridFont(),;
                        "lPixels"   => .t.,;
                        "nClrText"  => Rgb( 0, 0, 0 ),;
                        "nClrBack"  => Rgb( 255, 255, 255 ),;
                        "nWidth"    => {|| GridWidth( ::widthLabel, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lDesign"   => .f. } )

   TGridGet():Build( {  "nRow"      => nRow,;
                        "nCol"      => {|| GridWidth( 2.5, ::oDlg ) },;
                        "bSetGet"   => {|u| ::SetGetValue( u, "Email" ) },;
                        "oWnd"      => ::oDlg,;
                        "nWidth"    => {|| GridWidth( 9, ::oDlg ) },;
                        "nHeight"   => 23,;
                        "lPixels"   => .t. } )

Return ( self )

//---------------------------------------------------------------------------//
