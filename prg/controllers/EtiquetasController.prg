#include "FiveWin.Ch"
#include "Factu.ch" 
#include "MesDbf.ch"

#define  __special_mode__              9

//---------------------------------------------------------------------------//

CLASS EtiquetasController FROM SQLBaseController

	DATA     nSelectedNode

   DATA     allSelectedNode

   METHOD   New()

   METHOD   buildSQLModel( this )         						INLINE ( EtiquetasModel():New( this ) )
   
   METHOD   buildSQLView( this )										INLINE ( Etiquetas():New( this ) )

   METHOD   getFieldFromBrowse()                				INLINE ( ::allSelectedNode )
 
   METHOD   validDialog( oDlg, oTree, oGetNombre )

   METHOD   loadChildBuffer()

   METHOD   AppendChild( oBrowse )

   METHOD   checkValidParent()

   METHOD   startDialog()

   METHOD   loadTree( oTree, id )
   	METHOD   setTree()
   	METHOD   changeTree()
   	METHOD   changeFindTree( oFind, oTree )

   METHOD   checkSelectedNode()
   	METHOD   getSelectedNode()                            INLINE ( ::nSelectedNode )
   	METHOD   setSelectedNode( nNode )                     INLINE ( ::nSelectedNode := nNode )

   METHOD   validBrowse()


   METHOD   initTree( oTree )                               INLINE ( oTree:deleteAll(), oTree:Refresh() )

   METHOD   setTreeSelectedItems( oTree )
   METHOD   setTreeSelectedItem()

   METHOD   appendOnBrowse( oTree )                         
   METHOD   editOnBrowse( oTree )

   METHOD   fillAllSelectedNode( oTree, aItems )
   METHOD   setAllSelectedNode( aSelectedItmes )            INLINE ( iif(  hb_isarray( aSelectedItmes ),;
                                                                           ::allSelectedNode := aSelectedItmes,;
                                                                           ::allSelectedNode := {} ) )

   METHOD 	isSpecialMode()                             		INLINE ( ::nMode == __special_mode__ )


END CLASS

//---------------------------------------------------------------------------// 

METHOD New()

   ::idUserMap            	:= "01101"

   ::nSelectedNode         := nil

   ::Super:New()

RETURN ( self )

//---------------------------------------------------------------------------// 

METHOD validDialog( oDlg, oTree, oGetNombre )

	local idForNombre

   ::setSelectedNode( nil )

   if empty( ::oModel:hBuffer[ "nombre" ] )
      msgStop( "Nombre de la etiqueta no puede estar vac�o." )
      oGetNombre:setFocus()
      RETURN ( .f. )
   end if

   idForNombre := ::oModel:ChecksForValid( "nombre" )

   if ( !empty( idForNombre ) )
      if ( idForNombre != ::oModel:hBuffer[ "id" ] .and. !::isDuplicateMode() )
         msgStop( "El nombre de la etiqueta ya existe" )
         oGetNombre:setFocus()
         RETURN ( .f. )
      end if
      if ( idForNombre == ::oModel:hBuffer[ "id" ] .and. ::isDuplicateMode() )
         msgStop( "El nombre de la etiqueta ya existe" )
         oGetNombre:setFocus()
         RETURN ( .f. )
      end if
   end if

   ::checkSelectedNode( oTree )

   if ( ::isEditMode() )

      if ::oModel:hBuffer[ "id" ] == ::getSelectedNode()
         msgStop( "Referencia a si mismo. Una etiqueta no puede ser padre de si misma.")
         RETURN ( .f. )
      end if

      if !::checkValidParent()
         msgStop( "Referencia c�clica. Una etiqueta hijo no puede ser padre de su padre")
         RETURN ( .f. )
      endif

   end if 

   ::oModel:hBuffer[ "id_padre" ] := ::getSelectedNode( oTree )

RETURN ( oDlg:end( IDOK ) )

//---------------------------------------------------------------------------//

METHOD loadChildBuffer()

   local aColumnNames := hb_hkeys( ::oModel:hColumns )

   if empty( ::oModel:oRowSet )
      Return ( .f. )
   end if

   ::oModel:hBuffer  := {=>}

   aeval( aColumnNames, {| k | hset( ::oModel:hBuffer, k , if ( k == "id_padre", ::oModel:oRowSet:fieldget( "id" ), if (k == "id", 0, ) ) ) } )

Return ( .t. )

//----------------------------------------------------------------------------//

METHOD AppendChild( oBrowse )

   if ::notUserAppend()
      msgStop( "Acceso no permitido." )
      RETURN ( Self )
   end if 

   ::setMode( __special_mode__ )

   ::oModel:setIdForRecno( ::oModel:getKeyFieldOfRecno() )

   ::loadChildBuffer()

   if ::oView:Dialog()
      ::oModel:insertChildBuffer()
   end if

   if !empty( oBrowse )
      oBrowse:refreshCurrent()
      oBrowse:setFocus()
   end if 

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD startDialog( oTree )

   ::loadTree( oTree )

   ::setTree( ::oModel:hBuffer[ "id_padre" ], oTree )

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD loadTree( oTree, id )

   local oNode
   local nRecno
   local nPosition

   default id     := ""

   id             := cValToStr( id )

   nRecno         := ::getRowSet():Recno()

   nPosition      := ::getRowSet():find( id, "id_padre" )

   if nPosition == 0
      nPosition      := ::getRowSet():find( 0, "id_padre" )      
   end if
       
   while ( nPosition != 0 )

      oNode       := oTree:add( ::getRowSet():fieldGet( "nombre" ) )
      oNode:Cargo := ::getRowSet():fieldGet( "id" )

      ::loadTree( oNode, oNode:Cargo )

      ::getRowSet():goto( nPosition )

      nPosition   := ::getRowSet():findNext( id, "id_padre" )
   
   end while

   ::getRowSet():goTo( nRecno )

   oTree:Expand()

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD setTree( Id, oTree, aItems )

   local oItem

   if empty( aItems )
      aItems      := oTree:aItems
   end if

   for each oItem in aItems

      if ( alltrim( cValToStr( id ) ) == alltrim( cValToStr( oItem:Cargo ) ) )

         oTree:Select( oItem )
         oTree:SetCheck( oItem, .t. )

         sysRefresh()

      end if

      if len( oItem:aItems ) > 0
         ::setTree( Id, oTree, oItem:aItems )
      end if

   next

RETURN ( .t. )

//---------------------------------------------------------------------------//

METHOD checkSelectedNode( oTree, aItems )

   local oItem

   if empty( aItems )
      aItems      := oTree:aItems
   end if

   for each oItem in aItems

      if oTree:GetCheck( oItem )
         ::setSelectedNode( oItem:Cargo )
      end if

      if len( oItem:aItems ) > 0
         ::checkSelectedNode( oTree, oItem:aItems )
      end if

   next

RETURN ( nil )

//---------------------------------------------------------------------------//

METHOD checkValidParent( oTree, nCargo )

   local idTarget    := ::getSelectedNode()

   if empty(idTarget)
      RETURN ( .t. )
   end if 

   while idTarget != 0

      if ::getRowSet():find( idTarget, "id" ) != 0

         idTarget := val( ::getRowSet():fieldget( "id_padre" ) )

      end if

      if alltrim( cValtoStr( idTarget ) ) == alltrim( cValtoStr( ::oModel:hBuffer[ "id" ] ) )

         RETURN ( .f. )
          
      endif

   end while

RETURN ( .t. )

//---------------------------------------------------------------------------//

METHOD changeTree( oTree, aItems )

   local oItem

   if empty( aItems )
      aItems      := oTree:aItems
   end if

   for each oItem in aItems

      SysRefresh()

      oTree:SetCheck( oItem, .f. )

      if len( oItem:aItems ) > 0
         ::changeTree( oTree, oItem:aItems )
      end if

   next

RETURN ( .t. )

//---------------------------------------------------------------------------//

METHOD changeFindTree( oFind, oTree )

   local oItem
   local cFind    := alltrim( oFind:cText )

   if !empty(cFind)
      oItem       := oTree:Scan( { | o | cFind $ o:cPrompt } )
   end if 

   if !empty(oItem)
      oTree:Select( oItem )
   end if 

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD validBrowse( oDlg, oTree )

   ::setAllSelectedNode()

   ::fillAllSelectedNode( oTree )
   
RETURN ( oDlg:end( IDOK ) )

//---------------------------------------------------------------------------//

METHOD fillAllSelectedNode( oTree, aItems )

   local oItem

   if empty( aItems )
      aItems      := oTree:aItems
   end if

   for each oItem in aItems

      if oTree:GetCheck( oItem )
         aadd( ::allSelectedNode, ( oItem:cPrompt ) )  
      end if

      if len( oItem:aItems ) > 0
         ::fillAllSelectedNode( oTree, oItem:aItems )
      end if

   next

RETURN ( nil )

//---------------------------------------------------------------------------//

METHOD setTreeSelectedItems( oTree )

RETURN ( aeval( ::allSelectedNode, {|cName| ::setTreeSelectedItem( cName, oTree ) } ) )

//---------------------------------------------------------------------------//

METHOD setTreeSelectedItem( cName, oTree, aItems )

   local oItem

   if empty( aItems )
      aItems      := oTree:aItems
   end if

   for each oItem in aItems

      if ( alltrim( cValToStr( cName ) ) == alltrim( cValToStr( oItem:cPrompt ) ) )

         oTree:Select( oItem )
         oTree:SetCheck( oItem, .t. )

         sysRefresh()

      end if

      if len( oItem:aItems ) > 0
         ::setTreeSelectedItem( cName, oTree, oItem:aItems )
      end if

   next

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD appendOnBrowse( oTree )

   ::fillAllSelectedNode( oTree )

   if ( ::append() )
      ::initTree( oTree )
      ::loadTree( oTree )
      ::setTreeSelectedItems( oTree )
   endif

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD editOnBrowse( oTree, aSelectedItems )

   ::getrowset():find( oTree:GetSelected():Cargo, "id" )

   ::fillAllSelectedNode( oTree )

   if ( ::edit() )
      ::initTree( oTree )
      ::loadTree( oTree )
      ::setTreeSelectedItems( oTree )
   endif

RETURN ( Self )

//---------------------------------------------------------------------------//