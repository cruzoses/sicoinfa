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
      METHOD insertCategoriesLang()
         METHOD insertCategoryLang()
      METHOD insertCategoryShop()
      METHOD insertCategoryGroup( hCategory, idCategory )

   METHOD insertRootCategory() 
      METHOD insertRootCategoryLangs()

   METHOD getParentCategory( idCategory ) 
   METHOD getNodeParentCategory( idCategory )

   METHOD updateCategoriesParent()
      METHOD updateCategoryParent( hCategory )

   METHOD recalculatePositionsCategory()

   METHOD truncateAllTables() 
      
   METHOD cleanGestoolReferences()

   METHOD buildImageCategory( hCategoryProduct )
   METHOD uploadImageCategory( hCategoryProduct )

END CLASS

//---------------------------------------------------------------------------//

METHOD buildCategory( id ) CLASS TComercioCategory

   local idLang
   local aLangs         := {}
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
                                       "cPrefijoNombre"  => "",;
                                       "aTypeImages"     => {} } )

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

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category" ) + " "                                                                  + ;
                        "( id_category, id_parent, id_shop_default, level_depth, nleft, nright, active, date_add, date_upd, position ) "  + ;
                     "VALUES "                                                                                                            + ;
                        "( 1, 0, 1, 0, 0, 0, 1, " + quoted( dtos( GetSysDate() ) ) + ", " + quoted( dtos( GetSysDate() ) ) + ", 0 ), "    + ;
                        "( 2, 1, 1, 0, 0, 0, 1, " + quoted( dtos( GetSysDate() ) ) + ", " + quoted( dtos( GetSysDate() ) ) + ", 0 )"   


   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categor�as la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + " ( id_category, id_shop, position ) VALUES ( '1', '1', '0' )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( 1, 1 ), ( 1, 2 ), ( 1, 3 )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a raiz", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + " "                      + ;
                        "( id_category, id_lang, name, description, link_rewrite, meta_title ) "   + ;
                     "VALUES "                                                                     + ;
                        "( 2, " + quoted( ::getLanguage() ) + ", 'Inicio', 'Inicio', 'Inicio')"         

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias lenguajes la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + " ( id_category, id_shop, position ) VALUES ( 2, 1, 0 )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a inicio", 3 )
   end if

   cCommand       := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " ( id_category, id_group ) VALUES ( 2, 1 ), ( 2, 2 ), ( 2, 3 )"

   if ::commandExecDirect( cCommand )
      ::writeText( "He insertado correctamente en la tabla categorias grupo la categor�a raiz", 3 )
   else
      ::writeText( "Error al insertar la categor�a inicio", 3 )
   end if

   SysRefresh()

Return ( Self )

//---------------------------------------------------------------------------//

METHOD insertRootCategoryLangs()

   ::insertCategoryLang( ::getLanguage() )

   if !empty( ::TComercioConfig():getLangs() )
      heval( ::TComercioConfig():getLangs(), {|k,v| ::insertCategoryLang( v ) } )
   end if 

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD insertCategoriesLang( hCategory )

   local hLang

   ::insertCategoryLang( ::getLanguage(), hGet( hCategory, "name" ), hGet( hCategory, "description" ), hGet( hCategory, "link_rewrite" ) )

   if empty( ::TComercioConfig():getLangs() )
      RETURN ( Self )
   end if 

   for each hLang in ( ::TComercioConfig():getLangs() )

      if ( D():FamiliasLenguaje() )->( dbseekinord( hget( hCategory, "id" ) + hLang:__enumKey, "cCodLen" ) )
         ::insertCategoryLang( hLang:__enumValue, ( D():FamiliasLenguaje() )->cDesFam, hGet( hCategory, "description" ), hGet( hCategory, "link_rewrite" ) )
      else 
         ::insertCategoryLang( hLang:__enumValue, hGet( hCategory, "name" ), hGet( hCategory, "description" ), hGet( hCategory, "link_rewrite" ) )
      end if 

   next 

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD insertCategoryLang( idLang, cName, cDescription, cLinkRewrite  )

   local cCommand

   default cName        := 'Root'
   default cDescription := 'Root'
   default cLinkRewrite := 'Root'

   cCommand             := "INSERT INTO " + ::cPrefixTable( "category_lang" ) + " ( "  + ;
                              "id_category, "                                          + ;
                              "id_lang, "                                              + ;
                              "name, "                                                 + ;
                              "description, "                                          + ;
                              "link_rewrite, "                                         + ;
                              "meta_title, "                                           + ;
                              "meta_keywords, "                                        + ;
                              "meta_description ) "                                    + ;
                           "VALUES ( "                                                 + ;
                              "'1', "                                                  + ;
                              quoted( idLang ) + ", "                                  + ;
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

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD insertCategories() CLASS TComercioCategory

   local idCategory
   local hCategoryProduct

   ::insertRootCategory()
   ::insertRootCategoryLangs()

   for each hCategoryProduct in ::aCategoriesProduct

      idCategory  := ::insertCategory( hCategoryProduct )
   
      if !empty( idCategory )

         ::insertCategoriesLang( hCategoryProduct, idCategory )
         ::insertCategoryShop( hCategoryProduct, idCategory )
         ::insertCategoryGroup( hCategoryProduct, idCategory )

         ::buildImageCategory( hCategoryProduct )
         ::uploadImageCategory( hCategoryProduct )
      
      end if 

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

   SysRefresh()

   //Insertamos un registro en las tablas de im�genes----------------------

   if !empty( hGet( hCategory, "image" ) )
      hset( hCategory, "cPrefijoNombre", alltrim( str( idCategory ) ) )
   end if

   // Guardo referencia a la web-----------------------------------------------

   if !empty( idCategory )
      ::TPrestashopId:setValueCategory( hget( hCategory, "id" ), ::getCurrentWebName(), idCategory )
   end if 

Return ( idCategory )

//---------------------------------------------------------------------------//

METHOD insertCategoryShop( hCategory, idCategory ) CLASS TComercioCategory

   local cCommand

   cCommand             := "INSERT INTO " + ::cPrefixTable( "category_shop" ) + "( "   + ;
                              "id_category, "                                          + ;
                              "id_shop, "                                              + ;
                              "position ) "                                            + ;
                           "VALUES ( "                                                 + ;
                              "'" + alltrim( str( idCategory ) ) + "', "               + ;
                              "'1', "                                                  + ;
                              "'0' )"

   if !::commandExecDirect( cCommand )
      ::writeText( "Error al insertar la categor�a inicio en " + ::cPrefixTable( "category_shop" ), 3 )
   end if

Return ( Self )

//---------------------------------------------------------------------------//

METHOD insertCategoryGroup( hCategory, idCategory ) CLASS TComercioCategory

   local cCommand

   cCommand             := "INSERT INTO " + ::cPrefixTable( "category_group" ) + " "   + ;
                              "( id_category, id_group ) "                             + ;
                           "VALUES "                                                   + ;
                              "( " + alltrim( str( idCategory ) ) + ", 1 ), "          + ;
                              "( " + alltrim( str( idCategory ) ) + ", 2 ), "          + ;
                              "( " + alltrim( str( idCategory ) ) + ", 3 ) "

   if !::commandExecDirect( cCommand )
      ::writeText( "Error al insertar la familia " + hGet( hCategory, "name" ) + " en la tabla " + ::cPrefixTable( "category_group" ), 3 )
   end if

Return ( Self )

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

METHOD buildImageCategory( hCategoryProduct )

   local oTipoImage
   local fileImage
   local cTmpFile

   fileImage   := hget( hCategoryProduct, "image" )

   if !File( fileImage )
      Return nil
   end if
   
   cTmpFile    := cPatTmp() + hget( hCategoryProduct, "cPrefijoNombre" ) + ".jpg"

   saveImage( fileImage, cTmpFile )

   aadd( hget( hCategoryProduct, "aTypeImages" ), cTmpFile )

   for each oTipoImage in ::aTypeImagesPrestashop()

      if !Empty( hget( hCategoryProduct, "image" ) ) .and. oTipoImage:lCategories

         if File( fileImage )

            cTmpFile    := cPatTmp() + hget( hCategoryProduct, "cPrefijoNombre" ) + "-" + oTipoImage:cNombreTipo + ".jpg"

            saveImage( fileImage, cTmpFile, oTipoImage:nAnchoTipo, oTipoImage:nAltoTipo )

            aadd( hget( hCategoryProduct, "aTypeImages" ), cTmpFile )

         end if

         SysRefresh()

      end if 

   next

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD uploadImageCategory( hCategoryProduct )

   local cTypeImage
   local cRemoteImage

   if !hhaskey( hCategoryProduct, "aTypeImages")
      Return ( nil )
   end if 

   for each cTypeImage in hget( hCategoryProduct, "aTypeImages" )

      ::meterProcesoText( "Subiendo imagen " + cTypeImage )

      ::oFtp():CreateFile( cTypeImage, ::cDirectoryCategories() + "/" )

      SysRefresh()

      ferase( cTypeImage )

      SysRefresh()

   next

Return ( .t. )

//---------------------------------------------------------------------------//