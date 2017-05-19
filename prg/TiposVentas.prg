#include "FiveWin.Ch"
#include "Factu.ch" 
#include "MesDbf.ch"

//---------------------------------------------------------------------------//

CLASS TiposVentas FROM SQLBaseView

   METHOD   New()

   METHOD   buildSQLShell()
  
   METHOD   buildSQLBrowse( oGet )

   METHOD   buildSQLModel()               INLINE ( TiposVentasModel():New() )

   METHOD   getFieldFromBrowse()          INLINE ( ::oModel:getRowSet():fieldGet( "codigo" ) )
 
   METHOD   Dialog()

   METHOD   validDialog( oDlg, oGetNombre )

END CLASS

//---------------------------------------------------------------------------//

METHOD New()

   ::idUserMap            := "01043"

   ::Super:New()

Return ( Self )

//---------------------------------------------------------------------------//

METHOD buildSQLShell()

   disableAcceso()

   ::oShell                := SQLTShell():New( 2, 10, 18, 70, "Tipos de ventas", , oWnd(), , , .f., , , ::oModel, , , , , {}, {|| ::Edit( ::oShell:getBrowse() ) },, {|| ::Delete( ::oShell:getBrowse() ) },, nil, ::nLevel, "gc_wallet_16", ( 104 + ( 0 * 256 ) + ( 63 * 65536 ) ),,, .t. )

      with object ( ::oShell:AddCol() )
         :cHeader          := "Id"
         :cSortOrder       := "id"
         :bEditValue       := {|| ::oModel:getRowSet():fieldGet( "id" ) }
         :nWidth           := 80
         :bLClickHeader    := {| nMRow, nMCol, nFlags, oCol | ::clickOnHeader( oCol, ::oShell:getBrowse(), ::oShell:getCombobox() ) }
      end with

      with object ( ::oShell:AddCol() )
         :cHeader          := "Nombre"
         :cSortOrder       := "nombre"
         :bEditValue       := {|| ::oModel:getRowSet():fieldGet( "nombre" ) }
         :nWidth           := 200
         :bLClickHeader    := {| nMRow, nMCol, nFlags, oCol | ::clickOnHeader( oCol, ::oShell:getBrowse(), ::oShell:getCombobox() ) }
      end with

      ::oShell:createXFromCode()

      ::oShell:setDClickData( {|| ::Edit( ::oShell:getBrowse() ) } )

      ::AutoButtons()

   ACTIVATE WINDOW ::oShell

   ::oShell:bValid   := {|| ::saveHistory( ::getHistoryNameShell() , ::oShell:getBrowse() ), .t. }
   ::oShell:bEnd     := {|| ::destroySQLModel() }

   ::oShell:setComboBoxChange( {|| ::changeCombo( ::oShell:getBrowse(), ::oShell:getCombobox() ) } )

   enableAcceso()

Return ( Self )

//----------------------------------------------------------------------------//

METHOD Dialog( lZoom )

   local oDlg
   local oGetNombre
   local oGetCodigo

   DEFINE DIALOG oDlg RESOURCE "TIPO_VENTA" TITLE ::lblTitle() + "tipo de venta"

   REDEFINE GET   oGetCodigo ;
      VAR         ::oModel:hBuffer[ "codigo" ] ;
      MEMO ;
      ID          100 ;
      WHEN        ( ! ::isZoomMode() ) ;
      OF          oDlg

   REDEFINE GET   oGetNombre ;
      VAR         ::oModel:hBuffer[ "nombre" ] ;
      MEMO ;
      ID          110 ;
      WHEN        ( !::isZoomMode() ) ;
      OF          oDlg

   REDEFINE BUTTON ;
      ID          IDOK ;
      OF          oDlg ;
      WHEN        ( !::isZoomMode() ) ;
      ACTION      ( ::validDialog( oDlg, oGetNombre, oGetCodigo ) )

   REDEFINE BUTTON ;
      ID          IDCANCEL ;
      OF          oDlg ;
      CANCEL ;
      ACTION      ( oDlg:end() )

   // Teclas rpidas-----------------------------------------------------------

   oDlg:AddFastKey( VK_F5, {|| oDlg:end( IDOK ) } )

   // evento bstart-----------------------------------------------------------

   oDlg:bStart    := {|| oGetNombre:setFocus() }

   ACTIVATE DIALOG oDlg CENTER

RETURN ( oDlg:nResult == IDOK )

//---------------------------------------------------------------------------//

METHOD buildSQLBrowse()

   local oDlg
   local oBrowse
   local oFind
   local cFind       := space( 200 )
   local oCombobox
   local cOrder
   local aOrden      := { "nombre" }

   DEFINE DIALOG oDlg RESOURCE "HELP_BROWSE_SQL" TITLE "Seleccionar tipo de venta"

      REDEFINE GET   oFind ; 
         VAR         cFind ;
         ID          104 ;
         BITMAP      "FIND" ;
         OF          oDlg

      oFind:bChange  := {|| ::changeFind( oFind, oBrowse ) }

      REDEFINE COMBOBOX oCombobox ;
         VAR         cOrder ;
         ID          102 ;
         ITEMS       aOrden ;
         OF          oDlg

      oCombobox:bChange       := {|| ::changeCombo( oBrowse, oCombobox ) }

      oBrowse                 := SQLXBrowse():New( oDlg )

      oBrowse:bClrSel         := {|| { CLR_BLACK, Rgb( 229, 229, 229 ) } }
      oBrowse:bClrSelFocus    := {|| { CLR_BLACK, Rgb( 167, 205, 240 ) } }

      oBrowse:lHScroll        := .f.
      oBrowse:nMarqueeStyle   := 6

      oBrowse:setModel( ::oModel )

      with object ( oBrowse:AddCol() )
         :cHeader             := "Id"
         :cSortOrder          := "id"
         :bEditValue          := {|| ::oModel:getRowSet():fieldGet( "id" ) }
         :nWidth              := 80
         :bLClickHeader       := {| nMRow, nMCol, nFlags, oCol | ::clickOnHeader( oCol, oBrowse, oCombobox ) }
      end with

      with object ( oBrowse:AddCol() )
         :cHeader             := "Nombre"
         :cSortOrder          := "nombre"
         :bEditValue          := {|| ::oModel:getRowSet():fieldGet( "nombre" ) }
         :nWidth              := 200
         :bLClickHeader       := {| nMRow, nMCol, nFlags, oCol | ::clickOnHeader( oCol, oBrowse, oCombobox ) }
      end with

      oBrowse:bLDblClick      := {|| oDlg:end( IDOK ) }
      oBrowse:bRClicked       := {| nRow, nCol, nFlags | oBrowse:RButtonDown( nRow, nCol, nFlags ) }

      oBrowse:CreateFromResource( 105 )

      REDEFINE BUTTON ;
         ID          IDOK ;
         OF          oDlg ;
         ACTION      ( oDlg:end( IDOK ) )

      REDEFINE BUTTON ;
         ID          IDCANCEL ;
         OF          oDlg ;
         CANCEL ;
         ACTION      ( oDlg:end() )

      REDEFINE BUTTON ;
         ID          500 ;
         OF          oDlg ;
         ACTION      ( ::Append( oBrowse ) )

      REDEFINE BUTTON ;
         ID          501 ;
         OF          oDlg ;
         ACTION      ( ::Edit( oBrowse ) )

      oDlg:AddFastKey( VK_RETURN,   {|| oDlg:end( IDOK ) } )
      oDlg:AddFastKey( VK_F5,       {|| oDlg:end( IDOK ) } )
      oDlg:AddFastKey( VK_F2,       {|| ::Append( oBrowse ) } )
      oDlg:AddFastKey( VK_F3,       {|| ::Edit( oBrowse ) } )

      oDlg:bStart    := {|| ::startBrowse( oCombobox, oBrowse ) }

   oDlg:Activate( , , , .t., {|| ::saveHistory( ::getHistoryNameBrowse(), oBrowse ) } )

RETURN ( oDlg:nResult == IDOK )

//---------------------------------------------------------------------------//

METHOD validDialog( oDlg, oGetNombre, oGetCodigo )

   if empty( ::oModel:hBuffer[ "nombre" ] )
      msgStop( "El nombre de la venta no puede estar vac�o." )
      oGetNombre:setFocus()
      RETURN ( .f. )
   end if

   if ::oModel:getRowSet():find( ::oModel:hBuffer[ "nombre" ], "nombre" ) != 0 .and. ( ::oModel:getRowSet():find( ::oModel:hBuffer[ "id" ], "id" ) == 0 .or. ::isDuplicateMode() )
      msgStop( "El nombre de la venta ya existe" )
      oGetNombre:setFocus()
      RETURN ( .f. )
   end if

   if empty( ::oModel:hBuffer[ "codigo" ] )
      MsgStop( "El codigo del tipo de venta no puede estar vac�o." )
      oGetCodigo:setFocus()
      Return ( .f. )
   end if

   if ::oModel:getRowSet():find( ::oModel:hBuffer[ "codigo" ], "codigo" ) != 0 .and. ( ::oModel:getRowSet():find( ::oModel:hBuffer[ "id" ], "id" ) == 0 .or. ::isDuplicateMode() )
      msgStop( "El codigo de la venta ya existe" )
      oGetCodigo:setFocus()
      RETURN ( .f. )
   end if

RETURN ( oDlg:end( IDOK ) )