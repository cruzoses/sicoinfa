#include "FiveWin.Ch" 
#include "Struct.ch"
#include "Factu.ch" 
#include "Ini.ch"
#include "MesDbf.ch" 

#define __tipoProducto__      1
#define __tipoCategoria__     2     

//---------------------------------------------------------------------------//

CLASS TComercioCategory FROM TComercioConector

   DATA  idCategoryDefault  

   DATA  aCategoriesProduct                                 INIT {}

   METHOD buildCategory( id )

   METHOD insertCategories( hCategory )
      METHOD insertCategory()
      METHOD insertRootCategory() 
         METHOD getParentCategory( idCategory ) 
         METHOD getNodeParentCategory( idCategory )

   METHOD truncateAllTables() 
      
   METHOD cleanGestoolReferences()


END CLASS

//---------------------------------------------------------------------------//

METHOD buildCategory( id ) CLASS TComercioCategory

   if !( ::isSyncronizeAll() )
      Return .f. 
   end if 

   if ascan( ::aCategoriesProduct, {|h| hGet( h, "id" ) == id } ) != 0
      Return .f.
   end if

   if ::oCategoryDatabase():SeekInOrd( id, "cCodFam" ) 

      aAdd( ::aCategoriesProduct,   {  "id"              => id,;
                                       "id_parent"       => alltrim( ::oCategoryDatabase():cFamCmb ),;
                                       "name"            => if( empty( ::oCategoryDatabase():cDesWeb ), alltrim( ::oCategoryDatabase():cNomFam ), alltrim( ::oCategoryDatabase():cDesWeb ) ),;
                                       "description"     => if( empty( ::oCategoryDatabase():cDesWeb ), alltrim( ::oCategoryDatabase():cNomFam ), alltrim( ::oCategoryDatabase():cDesWeb ) ),;
                                       "link_rewrite"    => cLinkRewrite( if( empty( ::oCategoryDatabase():cDesWeb ), alltrim( ::oCategoryDatabase():cNomFam ), alltrim( ::oCategoryDatabase():cDesWeb ) ) ),;
                                       "image"           => alltrim( ::oCategoryDatabase():cImgBtn ),;
                                       "cPrefijoNombre"  => "" } )

   end if   

   if !empty( ::oCategoryDatabase():cFamCmb )
      ::buildCategory( ::oCategoryDatabase():cFamCmb )
   end if

Return ( Self )

//---------------------------------------------------------------------------//

METHOD truncateAllTables() CLASS TComercioCategory

   local tableToDelete
   local tablesToDelete := {  "category",;
                              "category_lang",;
                              "category_product",;
                              "category_group",;
                              "category_shop" }

   for each tableToDelete in tablesToDelete
      ::truncateTable( tableToDelete )
   next 

Return ( self )

//---------------------------------------------------------------------------//
// Insertamos el root en la tabla de categorias------------------------------

METHOD cleanGestoolReferences() CLASS TComercioCategory

   ::writeText( "Limpiamos las referencias de las tablas de familias" )

   ::TPrestashopId():deleteDocumentValuesCategory( ::getCurrentWebName() )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD insertRootCategory() CLASS TComercioCategory

   local hCategory   := {  "id"              => '1',;
                           "id_parent"       => '',;
                           "name"            => 'Root',;
                           "description"     => 'Root',;
                           "link_rewrite"    => 'Root',;
                           "image"           => '',;
                           "cPrefijoNombre"  => '' }

   ::insertCategory( hCategory )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD insertCategories() CLASS TComercioCategory

   local hCategoryProduct

   ::insertRootCategory()

   debug( ::aCategoriesProduct )

   for each hCategoryProduct in ::aCategoriesProduct
      ::insertCategory( hCategoryProduct )
   next 

Return ( Self )

//---------------------------------------------------------------------------//

METHOD insertCategory( hCategory ) CLASS TComercioCategory

   local oImagen
   local nParent        := 2
   local cCommand       := ""
   local idCategory     := 0

   ::writeText( "A�adiendo categor�a: " + hGet( hCategory, "name" ) )

   //Insertamos una familia nueva en las tablas de prestashop-----------------

   cCommand := "INSERT INTO " + ::cPrefixTable( "category" ) + "( "  + ;
                  "id_parent, "                                      + ;
                  "level_depth, "                                    + ;
                  "nleft, "                                          + ;
                  "nright, "                                         + ;
                  "active, "                                         + ;
                  "date_add,  "                                      + ;
                  "date_upd, "                                       + ;
                  "position ) "                                      + ;
               "VALUES ( "                                           + ;
                  "'" + alltrim( str( nParent ) ) + "', "            + ;
                  "'2', "                                            + ;
                  "'0', "                                            + ;
                  "'0', "                                            + ;
                  "'1', "                                            + ;
                  "'" + dtos( GetSysDate() ) + "', "                 + ;
                  "'" + dtos( GetSysDate() ) + "', "                 + ;
                  "'0' ) "

   if ::commandExecDirect( cCommand )
      idCategory  := ::oConexionMySQLDatabase():GetInsertId()
      ::writeText( "He insertado la familia " + hGet( hCategory, "name" ) + " correctamente en la tabla " + ::cPrefixTable( "category" ), 3 )
   else
      ::writeText( "Error al insertar la familia " + hGet( hCategory, "name" ) + " en la tabla " + ::cPrefixTable( "category" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + "( "   + ;
                  "id_category, "                                          + ;
                  "id_lang, "                                              + ;
                  "name, "                                                 + ;
                  "description, "                                          + ;
                  "link_rewrite, "                                         + ;
                  "meta_title, "                                           + ;
                  "meta_keywords, "                                        + ;
                  "meta_description ) "                                    + ;
               "VALUES ( "                                                 + ;
                  "'" + alltrim( str( idCategory ) ) + "', "               + ;
                  "'" + alltrim( str( ::getLanguage() ) ) + "', "          + ;
                  "'" + hGet( hCategory, "name" ) + "', "                  + ;
                  "'" + hGet( hCategory, "description" ) + "', "           + ;
                  "'" + hGet( hCategory, "link_rewrite" ) + "', "          + ;
                  "'', "                                                   + ;
                  "'', "                                                   + ;
                  "'' )"

   if !::commandExecDirect( cCommand )
      ::writeText( "Error al insertar la familia " + hGet( hCategory, "name" ) + " en la tabla " + ::cPrefixTable( "category_lang" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + "( "   + ;
                  "id_category, "                                          + ;
                  "id_shop, "                                              + ;
                  "position ) "                                            + ;
               "VALUES ( "                                                 + ;
                  "'" + alltrim( str( idCategory ) ) + "', "               + ;
                  "'1', "                                                  + ;
                  "'0' )"

   if !::commandExecDirect( cCommand )
      ::writeText( "Error al insertar la categor�a inicio en " + ::cPrefixTable( "category_group" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( "  + ;
                  "id_category, id_group ) "                               + ;
               "VALUES ( "                                                 + ;
                  "'" + alltrim( str( idCategory ) ) + "', "               + ;
                  "'1' )"

   if !::commandExecDirect( cCommand )
      ::writeText( "Error al insertar la familia " + hGet( hCategory, "name" ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( "  + ; 
                  "id_category, "                                          + ;
                  " id_group ) "                                           + ;
               "VALUES ( "                                                 + ;
                  "'" + alltrim( str( idCategory ) ) + "', "               + ;
                  "'2' )"

   if !::commandExecDirect( cCommand )
      ::writeText( "Error al insertar la familia " + hGet( hCategory, "name" ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

   cCommand := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( "  + ;
                  "id_category, "                                          + ;
                  "id_group ) "                                            + ;
               "VALUES ( "                                                 + ;
                  "'" + alltrim( str( idCategory ) ) + "', "               + ;
                  "'3' )"

   if !::commandExecDirect( cCommand )
      ::writeText( "Error al insertar la familia " + hGet( hCategory, "name" ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

   SysRefresh()

   //Insertamos un registro en las tablas de im�genes----------------------

   if !empty( hGet( hCategory, "image" ) )
      hset( hCategory, "cPrefijoNombre", alltrim( str( idCategory ) ) )
   end if

   // Guardo referencia a la web-----------------------------------------------

   if !empty( idCategory )
      ::TPrestashopId:setValueCategory( hget( hCategory, "id" ), ::getCurrentWebName(), idCategory )
   end if 

Return idCategory

//---------------------------------------------------------------------------//

METHOD getParentCategory( idCategory ) CLASS TComercioCategory

   local idParentCategory    := 2

   if ::oCategoryDatabase():Seek( idCategory ) // .and. ::oCategoryDatabase():lPubInt
      idParentCategory       := ::TPrestashopId():getValueCategory( idCategory, ::getCurrentWebName() )  
   end if

Return ( idParentCategory )

//---------------------------------------------------------------------------//

METHOD getNodeParentCategory( idCategory ) CLASS TComercioCategory

   local idNode            := ""

   if !empty( idCategory ) .and. ::oCategoryDatabase():Seek( idCategory )
      idNode               := ::oCategoryDatabase():cFamCmb
   end if   

Return ( idNode )

//---------------------------------------------------------------------------//
