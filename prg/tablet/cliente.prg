#include "FiveWin.Ch"
#include "Factu.ch" 

CLASS Cliente FROM Ventas

   METHOD New()

   METHOD setEnviroment()        INLINE ( ::setDataTable( "Client" ) ) 
   
   METHOD setNavigator() 
   
   METHOD propiedadesBrowse()
/*
   METHOD getAppendDocumento() 

   METHOD getEditDocumento() 

   METHOD setAppendDocumento()

   METHOD setEditDocumento()
*/
   METHOD Resource()

ENDCLASS

//---------------------------------------------------------------------------//

METHOD New() CLASS Cliente

   if ::OpenFiles()
      
      ::setEnviroment()

      ::setNavigator()

      ::CloseFiles()

   end if   

return ( self )

//---------------------------------------------------------------------------//

METHOD setNavigator() CLASS Cliente

   ::oViewNavigator       := ViewNavigator():New( self )

   if !Empty( ::oViewNavigator )

      ::oViewNavigator:setTextoTipoDocuento( "Clientes" )

      ::oViewNavigator:setItemsBusqueda( { "C�digo", "Nombre" } )
      
      ::oViewNavigator:ResourceViewNavigator()

   end if

return ( self )

//---------------------------------------------------------------------------//

METHOD propiedadesBrowse() CLASS Cliente

   ::oViewNavigator:setBrowseConfigurationName( "Grid clientes" )

   with object ( ::oViewNavigator:oBrowse:AddCol() )
      :cHeader           := "C�digo"
      :bEditValue        := {|| D():ClientesId( ::nView ) }
      :nWidth            := 160
   end with

   with object ( ::oViewNavigator:oBrowse:AddCol() )
      :cHeader           := "Cliente"
      :bEditValue        := {|| D():ClientesNombre( ::nView )  }
      :nWidth            := 320
   end with

Return ( self )

//---------------------------------------------------------------------------//
/*
METHOD GetAppendDocumento() CLASS Cliente

   ::hDictionaryMaster      := D():getHashRecordDefaultValues( ::getWorkArea(), ::nView )

Return ( self )

//---------------------------------------------------------------------------//

METHOD GetEditDocumento() CLASS Cliente

   ::hDictionaryMaster      := D():getHashRecord( ::getWorkArea(), ::nView ) 

Return ( self )

//---------------------------------------------------------------------------//

METHOD setAppendDocumento() CLASS Cliente

   D():appendHashRecord( ::hDictionaryMaster, ::getWorkArea(), ::nView )

Return ( self )

//---------------------------------------------------------------------------//

METHOD setEditDocumento() CLASS Cliente

   D():editHashRecord( ::hDictionaryMaster, ::getWorkArea(), ::nView )

Return ( self )
*/
//---------------------------------------------------------------------------//

METHOD Resource( nMode ) CLASS Cliente

   ::oViewEdit       := ViewCliente():New( self )

   if !Empty( ::oViewEdit )

      ::oViewEdit:setTextoTipoDocuento( LblTitle( nMode ) + "cliente" )
      
      ::oViewEdit:ResourceViewEdit( nMode )

   end if

Return ( .t. )   

//---------------------------------------------------------------------------//


