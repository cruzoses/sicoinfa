#include "FiveWin.Ch"
#include "Factu.ch" 
#include "MesDbf.ch"

//---------------------------------------------------------------------------//

CLASS PropiedadesController FROM SQLHeaderController

	DATA 		oPropiedadesLineasController

   METHOD   New()

   METHOD   buildSQLModel( this )         INLINE ( PropiedadesModel():New( this ) )
   
   METHOD   buildSQLView( this )				INLINE ( Propiedades():New( this ) )
  
   METHOD   getFieldFromBrowse()          INLINE ( ::getRowSet():fieldGet( "id" ) )
 
   METHOD   initAppendMode()              INLINE ( ::oPropiedadesLineasController:oModel:buildRowSetWhitForeignKey( 0 ) )

   METHOD   initEditMode()                INLINE ( ::oPropiedadesLineasController:oModel:buildRowSetWhitForeignKey( ::oModel:hBuffer[ "id" ] ) )

   METHOD   initZoomMode()                INLINE ( ::oPropiedadesLineasController:oModel:buildRowSetWhitForeignKey( ::oModel:hBuffer[ "id" ] ) )

   METHOD   New()

   METHOD   buildSQLModel( this )                  INLINE ( PropiedadesModel():New( this ) )
   
   METHOD   buildSQLView( this )				         INLINE ( Propiedades():New( this ) )
  
   METHOD   getFieldFromBrowse()                   INLINE ( padr( ::getRowSet():fieldGet( "codigo" ), ::oModel:hColumns[ "codigo" ][ "len" ] ) )
 
   METHOD   validCodigo( oGetCodigo )

   METHOD   validNombre( oGetNombre )

   METHOD   createEditControl( uValue, hControl )  INLINE ( ::oView:createEditControl( @uValue, hControl ) )

END CLASS

//---------------------------------------------------------------------------//

METHOD New()

   ::idUserMap            				:= "01015"

 	::setTitle( "Propiedades" )

   ::Super:New()

   ::ControllerContainer:add( 'lineas', PropiedadesLineasController():New( Self ) )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD validCodigo( oGetCodigo )

   local idCodigo
   local cErrorText  := ""

   oGetCodigo:setColor( Rgb( 0, 0, 0 ), Rgb( 255, 255, 255 ) )

   if empty( ::oModel:hBuffer[ "codigo" ] )
      cErrorText     += "El c�digo de la propiedad no puede estar vac�o." 
   end if

   idCodigo          := ::oModel:ChecksForValid( "codigo" )
   
   if ( !empty( idCodigo ) )

      if ( idCodigo != ::oModel:hBuffer[ "id" ] .and. !::isDuplicateMode() )
         cErrorText  += "El c�digo de la propiedad ya existe." 
      end if
   
      if ( idCodigo == ::oModel:hBuffer[ "id" ] .and. ::isDuplicateMode() )
         cErrorText  += "El c�digo de la propiedad ya existe."
      end if
   
   end if

   if !empty( cErrorText )
      msgStop( cErrorText )
      oGetCodigo:setColor( Rgb( 255, 255, 255 ), Rgb( 255, 102, 102 ) )
      oGetCodigo:setFocus()
      RETURN ( .f. )
   end if

RETURN ( .t. )

//---------------------------------------------------------------------------//

METHOD validNombre( oGetNombre )

   local idNombre
   local cErrorText  := ""

   oGetNombre:setColor( Rgb( 0, 0, 0 ), Rgb( 255, 255, 255 ) )

   if empty( ::oModel:hBuffer[ "nombre" ] )
      cErrorText     += "El nombre de la propiedad no puede estar vac�o." 
   end if

   idNombre          := ::oModel:ChecksForValid( "nombre" )
   
   if ( !empty( idNombre ) )

      if ( idNombre != ::oModel:hBuffer[ "id" ] .and. !::isDuplicateMode() )
         cErrorText  += "El nombre de la propiedad ya existe." 
      end if
   
      if ( idNombre == ::oModel:hBuffer[ "id" ] .and. ::isDuplicateMode() )
         cErrorText  += "El nombre de la propiedad ya existe."
      end if
   
   end if

   if !empty( cErrorText )
      msgStop( cErrorText )
      oGetNombre:setColor( Rgb( 255, 255, 255 ), Rgb( 255, 102, 102 ) )
      oGetNombre:setFocus()
      RETURN ( .f. )
   end if

RETURN ( .t. )

//---------------------------------------------------------------------------//
