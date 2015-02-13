#include "FiveWin.Ch"
#include "Factu.ch" 

CLASS ClienteViewSearchNavigator FROM ViewSearchNavigator

   METHOD setTextoTipoDocumento()      INLINE ( ::cTextoTipoDocumento := "Clientes" ) 

   METHOD setItemsBusqueda( aItems )   INLINE ( ::aItemsBusqueda := { "C�digo", "Nombre" } )   

   METHOD setColumns()

END CLASS

//---------------------------------------------------------------------------//

METHOD setColumns() CLASS ClienteViewSearchNavigator

   ::setBrowseConfigurationName( "Grid clientes" )

   with object ( ::addColumn() )
      :cHeader           := "Cliente"
      :bEditValue        := {|| ( D():ClientesId( ::getView() ) + CRLF + D():ClientesNombre( ::getView() ) )  }
      :nWidth            := 320
   end with

Return ( self )

//---------------------------------------------------------------------------//