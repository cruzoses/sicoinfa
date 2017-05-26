#include "FiveWin.Ch"
#include "Factu.ch" 
#include "MesDbf.ch"

//---------------------------------------------------------------------------//

CLASS TiposVentasController FROM SQLBaseController

   METHOD   New()

   METHOD   buildSQLModel( this )         INLINE ( TiposVentasModel():New( this ) )
   
   METHOD   buildSQLView( this )				INLINE ( TiposVentas():New( this ) )
  
   METHOD   getFieldFromBrowse()          INLINE ( ::getRowSet():fieldGet( "id" ) )
 
   METHOD   validDialog( oDlg, oGetCodigo, oGetNombre )

END CLASS

//---------------------------------------------------------------------------//

METHOD New()

   ::idUserMap            := "01043"

   ::setTitle( "Tipos de ventas" )

   ::Super:New()

Return ( Self )

//---------------------------------------------------------------------------//

METHOD validDialog( oDlg, oGetCodigo, oGetNombre )

   local idForNombre

   if empty( ::oModel:hBuffer[ "codigo" ] )
      msgStop( "El c�digo del tipo de venta no puede estar vac�o." )
      oGetCodigo:setFocus()
      RETURN ( .f. )
   end if

   if empty( ::oModel:hBuffer[ "nombre" ] )
      msgStop( "El nombre del tipo de venta no puede estar vac�o." )
      oGetNombre:setFocus()
      RETURN ( .f. )
   end if

   idForNombre    := ::oModel:ChecksForValid( "nombre" )

   if ( !empty( idForNombre ) )

      if ( idForNombre != ::oModel:hBuffer[ "id" ] .and. !::isDuplicateMode() )
         msgStop( "El nombre de la venta ya existe" )
         oGetNombre:setFocus()
         RETURN ( .f. )
      end if

      if ( idForNombre == ::oModel:hBuffer[ "id" ] .and. ::isDuplicateMode() )  
         msgStop( "El nombre de la venta ya existe" )
         oGetNombre:setFocus()
         RETURN ( .f. )
      end if

   end if

RETURN ( oDlg:end( IDOK ) )

//---------------------------------------------------------------------------//

