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

   METHOD updateCategoriesParent()
      METHOD updateCategoryParent( hCategory )

   METHOD recalculatePositionsCategory()

   METHOD truncateAllTables() 
      
   METHOD cleanGestoolReferences()


END CLASS

//---------------------------------------------------------------------------//

METHOD buildCategory( id ) CLASS TComercioCategory

   local categoryName 
   local statusFamilias

   if !( ::isSyncronizeAll() )
      Return .f. 
   end if 

   if ascan( ::aCategoriesProduct, {|h| hGet( h, "id" ) == id } ) != 0
      Return .f.
   end if

   statusFamilias       := aGetStatus( D():Familias( ::getView() ) ) 

   if ( D():Familias( ::getView() ) )->( dbseekinord( id, "cCodFam" ) )  

      if !empty( ( D():Familias( ::getView() ) )->cFamCmb )
         ::buildCategory( ( D():Familias( ::getView() ) )->cFamCmb )
      end if

      if empty( (D():Familias( ::getView() ) )->cDesWeb )
         categoryName   := alltrim( ( D():Familias( ::getView() ) )->cNomFam )
      else
         categoryName   := alltrim( ( D():Familias( ::getView() ) )->cDesWeb )
      end if  

      aAdd( ::aCategoriesProduct,   {  "id"              => id,;
                                       "id_parent"       => alltrim( ( D():Familias( ::getView() ) )->cFamCmb ),;
                                       "name"            => categoryName,;
                                       "description"     => categoryName,;
                                       "link_rewrite"    => cLinkRewrite( categoryName ),;
                                       "image"           => cFileBmpName( alltrim( ( D():Familias( ::getView() ) )->cImgBtn ) ),;
                                       "cPrefijoNombre"  => "" } )

   end if   

   setStatus( D():Familias( ::getView() ), statusFamilias ) 

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

   local cCommand := ""

   /*
   Insertamos el root en la tabla de categorias------------------------------
   */

   ::writeText( "A�adiendo categor�a raiz" )

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category" ) + " ( " + ;
                        "id_category, "                                    + ;
                        "id_parent, "                                      + ;
                        "id_shop_default, "                                + ;
                        "level_depth, "                                    + ;
                        "nleft, "                                          + ;
                        "nright, "                                         + ;
                        "active, "                                         + ;
                        "date_add, "                                       + ;
                        "date_upd, "                                       + ;
                        "position ) "                                      + ;
                     "VALUES ( "                                           + ;
                        "'1', "                                            + ;
                        "'0', "                                            + ;
                        "'1', "                                            + ;
                        "'0', "                                            + ;
                        "'0', "                                            + ;
                        "'0', "                                            + ;
                        "'1', "                                            + ;
                        "'" + dtos( GetSysDate() ) + "',"                  + ;
                        "'" + dtos( GetSysDate() ) + "', "                 + ;
                        "'0' ) "

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categor�as la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + " ( "  + ;
                        "id_category, "                                          + ;
                        "id_lang, name, "                                        + ;
                        "description, "                                          + ;
                        "link_rewrite, "                                         + ;
                        "meta_title, "                                           + ;
                        "meta_keywords, "                                        + ;
                        "meta_description ) "                                    + ;
                     "VALUES ( "                                                 + ;
                        "'1', "                                                  + ;
                        "'" + ::getLanguage() + "', "                            + ;
                        "'Root',  "                                              + ;
                        "'Root',  "                                              + ;
                        "'Root',  "                                              + ;
                        "'',  "                                                  + ;
                        "'',  "                                                  + ;
                        "'' )" 

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias lenguajes la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + " ( id_category, id_shop, position ) VALUES ( '1', '1', '0' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '1', '1' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '1', '2' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '1', '3' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a root en category_group", 3 )
   end if

   /*
   Metemos la categor�a de inicio de la que colgar�n los grupos y las categorias
   */

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category" ) + " ( " + ;
                        "id_parent, "                                      + ; 
                        "id_shop_default, "                                + ; 
                        "level_depth, "                                    + ; 
                        "nleft, "                                          + ; 
                        "nright, "                                         + ; 
                        "active, "                                         + ; 
                        "date_add, "                                       + ; 
                        "date_upd, "                                       + ; 
                        "position, "                                       + ; 
                        "is_root_category ) "                              + ; 
                     "VALUES ( "                                           + ;
                        "'1', "                                            + ;
                        "'1', "                                            + ;
                        "'1', "                                            + ;
                        "'0', "                                            + ;
                        "'0', "                                            + ;
                        "'1', "                                            + ;
                        "'" + dtos( GetSysDate() ) + "', "                 + ;
                        "'" + dtos( GetSysDate() ) + "', "                 + ;
                        "'0', "                                            + ;
                        "'1' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + " ( "  + ;
                        "id_category, "                                          + ;
                        "id_lang, "                                              + ;
                        "name, "                                                 + ;
                        "description, "                                          + ;
                        "link_rewrite, "                                         + ;
                        "meta_title, "                                           + ;
                        "meta_keywords, "                                        + ;
                        "meta_description ) "                                    + ;
                     "VALUES ( "                                                 + ;
                        "'2', "                                                  + ; 
                        "'" + ::getLanguage() + "', "                            + ; 
                        "'Inicio', "                                             + ; 
                        "'Inicio', "                                             + ; 
                        "'Inicio', "                                             + ; 
                        "'', "                                                   + ; 
                        "'', "                                                   + ; 
                        "'' )"         

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias lenguajes la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + " ( id_category, id_shop, position ) VALUES ( '2', '1', '0' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '2', '1' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '2', '2' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( '2', '3' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a inicio", 3 )
   end if

   SysRefresh()

Return ( Self )

//---------------------------------------------------------------------------//

METHOD insertCategories() CLASS TComercioCategory

   local hCategoryProduct

   ::insertRootCategory()

   for each hCategoryProduct in ::aCategoriesProduct
      ::insertCategory( hCategoryProduct )
   next 

Return ( Self )

//---------------------------------------------------------------------------//

METHOD updateCategoriesParent() CLASS TComercioCategory

   local hCategoryProduct

   for each hCategoryProduct in ::aCategoriesProduct
      ::updateCategoryParent( hCategoryProduct )
   next 

Return ( Self )

//---------------------------------------------------------------------------//

METHOD updateCategoryParent( hCategoryProduct ) CLASS TComercioCategory

   local nParent  
   local cCommand    
   local nCategory   

   nParent           := ::TPrestashopId():getValueCategory( hGet( hCategoryProduct, "id_parent" ), ::getCurrentWebName(), 2 )
   nCategory         := ::TPrestashopId():getValueCategory( hGet( hCategoryProduct, "id" ), ::getCurrentWebName() )

   cCommand          := "UPDATE " + ::cPrefixTable( "category" )              + " " + ;
                           "SET id_parent = '" + alltrim( str( nParent ) )    + "' " + ;
                        "WHERE id_category = " + alltrim( str( nCategory ) )

   if ::commandExecDirect( cCommand )
      ::writeText( "He relacionado la familia " + hGet( hCategoryProduct, "name" ) + " correctamente en la tabla " + ::cPrefixTable( "category" ) )
   else
      ::writeText( "Error al relacionar la familia " + hGet( hCategoryProduct, "name" ) + " en la tabla " + ::cPrefixTable( "category" ) )
   end if

   SysRefresh()

Return ( Self )

//---------------------------------------------------------------------------//

METHOD insertCategory( hCategory ) CLASS TComercioCategory

   local oImagen
   local nParent        := 2
   local cCommand       := ""
   local idCategory     := 0

   ::writeText( "A�adiendo categor�a: " + hGet( hCategory, "name" ) )

   //Insertamos una familia nueva en las tablas de prestashop-----------------

   cCommand             := "INSERT INTO " + ::cPrefixTable( "category" ) + "( "  + ;
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

   cCommand             := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + "( "   + ;
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
                              "'" + ::getLanguage() + "', "                            + ;
                              "'" + hGet( hCategory, "name" ) + "', "                  + ;
                              "'" + hGet( hCategory, "description" ) + "', "           + ;
                              "'" + hGet( hCategory, "link_rewrite" ) + "', "          + ;
                              "'', "                                                   + ;
                              "'', "                                                   + ;
                              "'' )"

   if !::commandExecDirect( cCommand )
      ::writeText( "Error al insertar la familia " + hGet( hCategory, "name" ) + " en la tabla " + ::cPrefixTable( "category_lang" ), 3 )
   end if

   cCommand             := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + "( "   + ;
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

   cCommand             := "INSERT INTO " + ::cPrefixTable( "category_group" ) + "( "  + ;
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

   if D():gotoFamilias( idCategory, ::getView() ) 
      idParentCategory       := ::TPrestashopId():getValueCategory( idCategory, ::getCurrentWebName() )  
   end if

Return ( idParentCategory )

//---------------------------------------------------------------------------//

METHOD getNodeParentCategory( idCategory ) CLASS TComercioCategory

   local idNode            := ""

   if !empty( idCategory ) .and. D():gotoFamilias( idCategory, ::getView() ) 
      idNode               := ( D():Familias( ::getView() ) )->cFamCmb
   end if   

Return ( idNode )

//---------------------------------------------------------------------------//

METHOD recalculatePositionsCategory() CLASS TComercioCategory

   local nPos              := 0
   local nContador         := 2
   local cQuery
   local oQuery         
   local cCommand
   local nTotalCategory
   local nLeft             := 0  
   local nRight            := 0

   /*
   Recorremos el Query con la consulta-----------------------------------------
   */

   cQuery                  := 'SELECT * FROM ' + ::cPrefixTable( "category" )
   oQuery                  := ::queryExecDirect( cQuery )
   if !( oQuery:Open() )
      ::meterProcesoText( "Error al ejecutar " + "SELECT * FROM " + ::cPrefixTable( "category" ) )
      Return ( .f. )
   end if

   nTotalCategory          := oQuery:RecCount()

   if nTotalCategory == 0
      ::writeText( "No hay elementos en la categor�a" )
      Return ( .f. )
   end if

   oQuery:GoTop()
   while !oQuery:Eof()

      do case
         case oQuery:FieldGet( 1 ) == 1

            cCommand    := "UPDATE " + ::cPrefixTable( "category" ) + " SET nLeft = '1', nRight='" + alltrim( str( nTotalCategory * 2 ) ) + "' WHERE id_category = 1" 
            if !::commandExecDirect( cCommand )
               ::writeText( "Error al actualizar el grupo de familia en la tabla category", 3 )
            end if

         case oQuery:FieldGet( 1 ) == 2

            cCommand    := "UPDATE " + ::cPrefixTable( "category" ) + " SET nLeft = '2', nRight='" + alltrim( str( ( nTotalCategory * 2 ) -1 ) ) + "' WHERE id_category = 2"
            if !::commandExecDirect( cCommand )
               ::writeText( "Error al actualizar el grupo de familia en la tabla category", 3 )
            end if

         otherwise

            nLeft       := ++nContador
            nRight      := ++nContador

            cCommand    := "UPDATE " + ::cPrefixTable( "category" ) + " SET nLeft = '" + alltrim( str( nLeft ) ) + "', nRight='" + alltrim( str( nRight ) ) + "' WHERE id_category = " + alltrim( str( oQuery:FieldGet( 1 ) ) )
            if !::commandExecDirect( cCommand )
               ::writeText( "Error al actualizar el grupo de familia en la tabla category", 3 )
            end if

      end case               

      oQuery:Skip()

   end while

Return ( .t. )

//---------------------------------------------------------------------------//


