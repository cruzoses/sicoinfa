#include "FiveWin.Ch"
#include "Factu.ch" 
#include "Font.ch"
#include "Report.ch"
#include "MesDbf.ch"
#include "DbInfo.ch"
#include "Xbrowse.ch"

//---------------------------------------------------------------------------//

CLASS TDlgFlt

   DATA oDbf

   DATA aTField

   DATA cExpresionFilter
   DATA bExpFilter
   DATA aExpFilter
   DATA cExpresionFilter

   DATA aTblConditionNumerico 
   DATA aTblConditionCaracter 
   DATA aTblConditionFecha
   DATA aTblConditionLogico

   DATA cTipFilter            INIT ""
   DATA cTexFilter            INIT ""

   DATA cDbfFilter

   DATA oWndBrw

   DATA lDefaultFilter        INIT .f.
   DATA cDefaultFilter

   DATA lAllUser              INIT .f.

   DATA lMultyExpresion       INIT .f.

   DATA aTblMask              INIT {}
   DATA aTblField             INIT {}
   DATA aTblType              INIT {}

   DATA aTblNexo              INIT {  "", "Y", "O" }
   DATA aTblExpresion         INIT {  "", " .and. ", " .or. " }
   DATA aTblSimbolos          INIT {   " == ",;
                                       " != ",;
                                       " > ",;
                                       " < ",;
                                       " >= ",;
                                       " <= ",;
                                       " $ " }

   DATA aTblCondition         INIT {   "Igual",;
                                       "Distinto",;
                                       "Mayor",;
                                       "Menor",;
                                       "Mayor igual",;
                                       "Menor igual",;
                                       "Contenga" }

   DATA aTblConditionNumerico INIT {   "Igual",;
                                       "Distinto",;
                                       "Mayor",;
                                       "Menor",;
                                       "Mayor igual",;
                                       "Menor igual" }
      
   DATA aTblConditionCaracter INIT  {  "Igual",;
                                       "Distinto",;
                                       "Contenga" }

   DATA aTblConditionFecha    INIT  {  "Igual",;
                                       "Distinto",;
                                       "Mayor",;
                                       "Menor",;
                                       "Mayor igual",;
                                       "Menor igual" }

   DATA aTblConditionLogico   INIT  {  "Igual",;
                                       "Distinto" }

   DATA oReplace
   DATA cReplace
   DATA cFldReplace
   DATA oExpReplace
   DATA cExpReplace           INIT Space( 100 )

   DATA oMtrReplace
   DATA nMtrReplace           INIT 0
   DATA lAllRecno             INIT .f.

   DATA oWebBtn

   DATA lAplyFilter

   DATA bOnAplyFilter
   DATA bOnKillFilter

   DATA cPath

   DATA lAppendFilter         INIT .f.

   DATA oDlg
   DATA oFld
   DATA cResource             INIT "FastFiltros"
   DATA oBrwFilter
   DATA oBrwAlmacenados

   DATA oColCondicion
   DATA oColValor

   DATA aFiltersName          INIT {}

   CLASSDATA aFilter          INIT {}

   CLASSDATA cOrdAnterior
   CLASSDATA nRecAnterior
   CLASSDATA cBagAnterior
   CLASSDATA cNamAnterior

   // Contructores-------------------------------------------------------------

   METHOD New( aTField, oDbf )
   METHOD Init( oDbf, oWndBrw )
   METHOD Create( aTField, oDbf )
   METHOD Default()

   // Operaciones con los filtros----------------------------------------------

   METHOD SaveFilter()
   METHOD DeleteFilter()
   METHOD CleanFilter()                INLINE ( ::aFilter := {}, ::AppendLine(), ::oBrwFilter:SetArray( ::aFilter, , , .f. ) )

   METHOD SetFields( aTField )

   METHOD SetFilter( cText )
   METHOD SetFilterType( cTipFilter )  INLINE ( ::cTipFilter   := cTipFilter )

   METHOD lBuildFilter()
   METHOD AplyFilter()
   METHOD KillFilter( oDlg )

   METHOD lBuildAplyFilter()           INLINE ( if( ::ExpresionBuilder(), ::AplyFilter(), ) )

   METHOD AddFilter()                  INLINE ( ::lAppendFilter := .t., ::Dialog() )
   METHOD EditFilter()                 INLINE ( ::lAppendFilter := .f., ::Dialog() )

   METHOD BrwFilter( oDlg )

   // Dialogo para montar el filtro--------------------------------------------

   METHOD Dialog()
   METHOD InitDialog()
   METHOD ValidDialog()

   METHOD NexoOnPostEdit( o, x, n ) 
   METHOD CampoOnPostEdit( o, x, n )
  
   METHOD ReturnFilter()               INLINE ( if( ::ExpresionBuilder(), ::oDlg:End( IDOK ), ) )

   METHOD LoadFilter()
   METHOD LoadTypeFilter()
   METHOD LoadDefaultFilter()          VIRTUAL 

   METHOD ChgFields()

   METHOD ExecuteReplace()

   METHOD ChgGet( cType, nLen, nDec )

   // Obtener el nombre del filtro---------------------------------------------

   METHOD lGetFilterName()
   METHOD lValidFilterName( oDlg )

   METHOD ExpresionBuilder( oDlg )   
   METHOD AppendExpresion( aFilter )   

   METHOD cField( aField )             INLINE ( ::aTblField[ Min( Max( aScan( ::aTblMask, Alltrim( aField[ 1 ] ) ), 0 ), len( ::aTblField ) ) ] )

   METHOD cFieldType( aField )         INLINE ( ::aTblType[ Min( Max( aScan( ::aTblMask, Alltrim( aField[ 1 ] ) ), 0 ), len( ::aTblType ) ) ] )

   METHOD cCondition( aField )         INLINE ( ::aTblSimbolos[ Min( Max( aScan( ::aTblCondition, aField[ 2 ] ), 0 ), len( ::aTblSimbolos ) ) ] )

   METHOD uValue( aField )             INLINE ( cCharToVal( aField[ 3 ], ::aTblType[ Min( Max( aScan( ::aTblMask, Alltrim( aField[ 1 ] ) ), 0 ), len( ::aTblType ) ) ] ) )

   METHOD cValue( aField )             INLINE ( cGetValue( aField[ 3 ], ::aTblType[ Min( Max( aScan( ::aTblMask, Alltrim( aField[ 1 ] ) ), 0 ), len( ::aTblType ) ) ] ) )

   METHOD cNexo( aField )              INLINE ( ::aTblExpresion[ Min( Max( aScan( ::aTblNexo, Alltrim( aField[ 4 ] ) ), 0 ), len( ::aTblExpresion ) ) ] )

   METHOD AppendLine()                 INLINE ( aAdd( ::aFilter, { ::aTblMask[ 1 ], ::aTblCondition[ 1 ], Space( 100 ), ::aTblNexo[ 1 ] } ) )

   INLINE METHOD cExpresionField( aField )

      local cField   := ::cField( aField )
      local cType    := ::cFieldType( aField )

      if cType == "C" .or. cType == "M"
         cField      := 'Rtrim( ' + Rtrim( cField ) + ' )'
      end if 

      RETURN ( cField )

   ENDMETHOD

   INLINE METHOD cSerializeFilter()

      local cFilter
      local aFilter
      local cSerializeFilter  := ""

      for each aFilter in ::aFilter
         for each cFilter in aFilter
            cSerializeFilter  += Alltrim( cValToChar( cFilter ) ) + ","
         next
      next

      RETURN ( cSerializeFilter )

   ENDMETHOD

   INLINE METHOD cDeSerializeFilter( cFilterSerialized )

      local cFilter
      local aFilter           := hb_ATokens( cFilterSerialized, "," )

      ::aFilter               := { {} }

      for each cFilter in aFilter
         
         aAdd( aTail( ::aFilter ), cFilter )

         if ( mod( hb_EnumIndex(), 4 ) == 0 )
            aAdd( ::aFilter, {} )
         end if 

      next 

      aSize( ::aFilter, len( ::aFilter ) - 1 )

      RETURN ( Self )

   ENDMETHOD

   INLINE METHOD SetFilterDatabase( uDbfFilter )

      do case
         case IsObject( uDbfFilter )
            ::cDbfFilter   := uDbfFilter:nArea
         case IsChar(  uDbfFilter )
            ::cDbfFilter   := uDbfFilter
      end case

      RETURN ( Self )

   ENDMETHOD

   INLINE METHOD SetScopeFilter( uScope )

      ( ::cDbfFilter )->( OrdScope( 0, uScope ) )
      ( ::cDbfFilter )->( OrdScope( 1, uScope ) )
      ( ::cDbfFilter )->( dbGoTop() )

      RETURN ( Self )

   ENDMETHOD

   INLINE METHOD SelectTable()

      do case
         case IsObject( ::oDbf )
            ::oDbf:SetFocus()
         case IsChar( ::oDbf )
            Select( ::oDbf )
      end case 

      RETURN ( Self )

   ENDMETHOD

   INLINE METHOD DeleteLine()

      local nLineasFilter  := len( ::aFilter )

      if ( nLineasFilter > 1 ) .and. ( ::oBrwFilter:nArrayAt <= nLineasFilter )
         aDel( ::aFilter, ::oBrwFilter:nArrayAt, .t. ) 
         ::oBrwFilter:Refresh()
      end if 

      RETURN ( Self )

   ENDMETHOD

   INLINE METHOD InitExpresion()

      ::cExpresionFilter   := ""
      ::cExpresionFilter   := ""
      ::bExpFilter   := nil

      RETURN ( Self )

   ENDMETHOD

END CLASS

//---------------------------------------------------------------------------//

METHOD New( aTField, oDbf, oWebBtn, lAplyFilter, oWndBrw ) CLASS TDlgFlt

   local n

   DEFAULT aTField      := dbStruct()
   DEFAULT lAplyFilter  := .t.

   ::SetFields( aTField )

   if Empty( ::aTField )
      MsgStop( "No hay tabla definida." )
      return ( Self )
   end if

   ::oDbf               := oDbf
   ::oWebBtn            := oWebBtn
   ::lAplyFilter        := lAplyFilter
   ::oWndBrw            := oWndBrw

   ::Default()

RETURN Self

//---------------------------------------------------------------------------//

METHOD Create( oDbf, oWebBtn, lAplyFilter, oWndBrw ) CLASS TDlgFlt

   local n

   DEFAULT lAplyFilter  := .t.

   ::oDbf               := oDbf
   ::oWebBtn            := oWebBtn
   ::lAplyFilter        := lAplyFilter
   ::oWndBrw            := oWndBrw

   ::SetFields( aClone( oDbf:aTField ) )

   if Empty( ::aTField )
      MsgStop( "No hay tabla definida." )
      return ( Self )
   end if

   ::aFilter            := {}

RETURN Self

//---------------------------------------------------------------------------//

METHOD Init( oWndBrw ) CLASS TDlgFlt

   ::oWndBrw            := oWndBrw
   ::oDbf               := oWndBrw:xAlias

   ::aFilter            := {}

   ::lAplyFilter        := .t.

RETURN Self

//---------------------------------------------------------------------------//

Method Default()

   local oFld

   ::SetFields( ::aTField )                              

   if Empty( ::aFilter )
      ::AppendLine()
   end if 

Return ( Self )

//---------------------------------------------------------------------------//

METHOD SetFields( aTField )

   local oFld

   ::aTField      := aTField

   if !Empty( ::aTField )                              
   
      for each oFld in ::aTField

         do case
         case IsObject( oFld )

            if !Empty( oFld:cComment ) .and. !( oFld:lCalculate ) .and. !( oFld:lHide )
               aAdd( ::aTblField,      oFld:cName )
               aAdd( ::aTblType,       oFld:cType )
               aAdd( ::aTblMask,       oFld:cComment )
            end if

         case IsArray( oFld )

            if !Empty( oFld[ 5 ] )
               aAdd( ::aTblField,      oFld[ 1 ] )
               aAdd( ::aTblType,       oFld[ 2 ] )
               aAdd( ::aTblMask,       oFld[ 5 ] )
            end if

         end case

      next
   
   end if

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD BrwFilter( oDlg )

   DEFAULT oDlg                  := ::oFld:aDialogs[ 1 ]

   REDEFINE BUTTON ;
      ID       100 ;
      OF       ( oDlg );
      ACTION   ( ::CleanFilter() )

   REDEFINE BUTTON ;
      ID       110 ;
      OF       ( oDlg );
      ACTION   ( ::SaveFilter() )

   REDEFINE BUTTON ;
      ID       120 ;
      OF       ( oDlg );
      ACTION   ( ::DeleteLine() )

   /*
   Browse de los rangos----------------------------------------------------------
   */

   ::oBrwFilter                  := IXBrowse():New( oDlg )

   ::oBrwFilter:bClrSel          := {|| { CLR_BLACK, Rgb( 229, 229, 229 ) } }
   ::oBrwFilter:bClrSelFocus     := {|| { CLR_BLACK, Rgb( 167, 205, 240 ) } }

   ::oBrwFilter:SetArray( ::aFilter, , , .f. )

   ::oBrwFilter:lHScroll         := .f.
   ::oBrwFilter:lVScroll         := .f.
   ::oBrwFilter:lRecordSelector  := .t.
   ::oBrwFilter:lFastEdit        := .t.

   ::oBrwFilter:nFreeze          := 1
   ::oBrwFilter:nMarqueeStyle    := 3

   ::oBrwFilter:bChange          := {|| ::CampoOnPostEdit() }

   ::oBrwFilter:CreateFromResource( 200 )

   with object ( ::oBrwFilter:AddCol() )
      :cHeader          := "Campo"
      :bEditValue       := {|| ::aFilter[ ::oBrwFilter:nArrayAt, 1 ] }
      :nEditType        := EDIT_LISTBOX
      :aEditListTxt     := ::aTblMask
      :nWidth           := 240
      :bOnPostEdit      := {|o,x,n| ::CampoOnPostEdit( o, x, n ) } 
   end with

   with object ( ::oColCondicion := ::oBrwFilter:AddCol() )
      :cHeader          := "Condicion"
      :bEditValue       := {|| ::aFilter[ ::oBrwFilter:nArrayAt, 2 ] }
      :nEditType        := EDIT_LISTBOX
      :aEditListTxt     := ::aTblCondition
      :nWidth           := 100
      :bOnPostEdit      := {|o,x,n| If( n != VK_ESCAPE, ::aFilter[ ::oBrwFilter:nArrayAt, 2 ] := x, ) } 
   end with

   with object ( ::oColValor := ::oBrwFilter:AddCol() )
      :cHeader          := "Valor"
      :bEditValue       := {|| ::aFilter[ ::oBrwFilter:nArrayAt, 3 ] }
      :nEditType        := EDIT_GET
      :nWidth           := 200
      :bOnPostEdit      := {|o,x,n| If( n != VK_ESCAPE, ::aFilter[ ::oBrwFilter:nArrayAt, 3 ] := x, ) } 
   end with

   with object ( ::oBrwFilter:AddCol() )
      :cHeader          := "Nexo"
      :bEditValue       := {|| ::aFilter[ ::oBrwFilter:nArrayAt, 4 ] }
      :nEditType        := EDIT_LISTBOX
      :aEditListTxt     := ::aTblNexo
      :nWidth           := 60
      :bOnPostEdit      := {|o,x,n| ::NexoOnPostEdit( o, x, n ) } 
   end with

RETURN ( Self )

//---------------------------------------------------------------------------//
//
// Caja de dialogo para creal el filtro
//

Method Dialog()

   local oBmp

   ::Default()

   /*
   Caja de dialogo-------------------------------------------------------------
   */

   DEFINE DIALOG ::oDlg RESOURCE "FastFiltros"

      REDEFINE FOLDER ::oFld ;
         ID       100 ;
         OF       ::oDlg ;
         PROMPT   "&Generador",;
                  "&Almacenados";
         DIALOGS  "FastFiltros_Definicion",;
                  "FastFiltros_Almacenados"

      REDEFINE BITMAP oBmp ;
         ID       500 ;
         RESOURCE "Funnel_48_alpha" ;
         TRANSPARENT ;
         OF       ::oDlg


      ::BrwFilter( ::oFld:aDialogs[ 1 ] )

      /*
      Browse de los filtros almacenados-------------------------------------------
      */
      
      REDEFINE BUTTON ;
         ID       100 ;
         OF       ( ::oFld:aDialogs[ 2 ] );
         ACTION   ( ::LoadFilter( ( ::cDbfFilter )->cTexFlt ) )

      REDEFINE BUTTON ;
         ID       110 ;
         OF       ( ::oFld:aDialogs[ 2 ] );
         ACTION   ( ::DeleteFilter() )
   
      ::oBrwAlmacenados                   := IXBrowse():New( ::oFld:aDialogs[ 2 ] )
   
      ::oBrwAlmacenados:bClrSel           := {|| { CLR_BLACK, Rgb( 229, 229, 229 ) } }
      ::oBrwAlmacenados:bClrSelFocus      := {|| { CLR_BLACK, Rgb( 167, 205, 240 ) } }
   
      ::oBrwAlmacenados:nMarqueeStyle     := 5
   
      ::oBrwAlmacenados:lHScroll          := .f.
      ::oBrwAlmacenados:lVScroll          := .t.
      ::oBrwAlmacenados:lRecordSelector   := .t.
   
      ::oBrwAlmacenados:cAlias            := ::cDbfFilter
   
      ::oBrwAlmacenados:bLDblClick        := {|| ::LoadFilter( ( ::cDbfFilter )->cTexFlt ) }
   
      ::oBrwAlmacenados:CreateFromResource( 200 )
   
      with object ( ::oBrwAlmacenados:AddCol() )
         :cHeader          := "Filtro"
         :bEditValue       := {|| ( ::cDbfFilter )->cTexFlt }
         :nWidth           := 600
      end with

      /*
      Botones de los filtros almacenados---------------------------------------
      */

      REDEFINE BUTTON ;
         ID       IDOK ;
         OF       ( ::oDlg );
         ACTION   ( ::ReturnFilter() )

      REDEFINE BUTTON ;
         ID       IDCANCEL ;
         OF       ( ::oDlg );
         ACTION   ( ::oDlg:End() )

      ::oDlg:AddFastKey( VK_F5, {|| ::ReturnFilter() } )

   ::oDlg:Activate( , , , .t., , , {|| ::InitDialog() } )

   ::ValidDialog( oBmp )

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD InitDialog()

   if !Empty( ::cTipFilter )
      ::SetScopeFilter( ::cTipFilter )
   end if

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD ValidDialog( oBmp )

   if ::oDlg:nResult != IDOK
      ::InitExpresion()
   end if

   ::SetScopeFilter()

   oBmp:End()

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD NexoOnPostEdit( o, x, n ) 

   local nAt               := ::oBrwFilter:nArrayAt

   if IsNum( n ) .and. ( n != VK_ESCAPE )

      if !Empty( x )
      
         ::aFilter[ nAt, 4 ]  := x

         if ( nAt ) == len( ::aFilter ) 
            ::AppendLine()
         end if 

         ::oBrwFilter:Refresh()

      end if 

   end if

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD CampoOnPostEdit( o, x, n )

   local nPos
   local lCambio                          := .f.
   local nAt                              := ::oBrwFilter:nArrayAt

   if IsNum( n ) .and. ( n != VK_ESCAPE )

      if !IsNil( x )
         if ::aFilter[ nAt, 1 ] != x
            ::aFilter[ nAt, 1 ]           := x
            lCambio                       := .t.
         end if 
      end if

      nPos                                := aScan( ::aTblMask, ::aFilter[ nAt, 1 ] )
      if nPos != 0

         do case
            case ::aTblType[ nPos ] == "C"

               ::oColCondicion:aEditListTxt     := ::aTblConditionCaracter

               ::oColValor:nEditType            := EDIT_GET              

               if Empty( ::aFilter[ nAt, 3 ] ) .or. lCambio
                  ::aFilter[ nAt, 3 ]           := Space( 100 )
               end if 

            case ::aTblType[ nPos ] == "N"

               ::oColCondicion:aEditListTxt   := ::aTblConditionNumerico

               ::oColValor:nEditType            := EDIT_GET              

               if Empty( ::aFilter[ nAt, 3 ] ) .or. lCambio
                  ::aFilter[ nAt, 3 ]           := 0
               end if 

            case ::aTblType[ nPos ] == "D"
               
               ::oColCondicion:aEditListTxt   := ::aTblConditionFecha

               ::oColValor:nEditType            := EDIT_DATE       
               
               if Empty( ::aFilter[ nAt, 3 ] ) .or. lCambio
                  ::aFilter[ nAt, 3 ]           := Date()
               end if 
               
            case ::aTblType[ nPos ] == "L"

               ::oColCondicion:aEditListTxt   := ::aTblConditionLogico

               ::oColValor:aEditListTxt         := { "Si", "No" }

               ::oColValor:nEditType            := EDIT_GET_LISTBOX

               if Empty( ::aFilter[ nAt, 3 ] ) .or. lCambio
                  ::aFilter[ nAt, 3 ]           := "Si"
               end if 

            otherwise

               ::oColCondicion:aEditListTxt     := ::aTblCondition

         end case 

         ::oBrwFilter:Refresh()

      end if

   end if 

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD ExpresionBuilder()

   local oBlock
   local oError
   local aFilter
   local lExpMaker   := .f.

   oBlock            := ErrorBlock( {| oError | ApoloBreak( oError ) } )
   BEGIN SEQUENCE

      ::InitExpresion()

      for each aFilter in ::aFilter

         if len( aFilter ) > 0

            ::AppendExpresion( aFilter )            
   
            ::cExpresionFilter         += ::cNexo( aFilter )

         end if 

      next

      /*
      Seleccionamos la tabla--------------------------------------------------
      */

      ::SelectTable( ::oDbf )

      /*
      Construimos el filtro----------------------------------------------------
      */

      ::bExpFilter               := Compile( ::cExpresionFilter )
      if Empty( ::bExpFilter )
         msgStop( "Expresion erronea " + ::cExpresionFilter, "Error!" )
         ::InitExpresion()
      end if

   RECOVER USING oError

      msgStop( ErrorMessage( oError ), "Error!" )

   END SEQUENCE

   ErrorBlock( oBlock )

Return ( !IsNil( ::bExpFilter ) )

//--------------------------------------------------------------------------//

METHOD AppendExpresion( aFilter )

   local cCondition  := ::cCondition( aFilter )

   if cCondition == " $ "
      ::cExpresionFilter   += ::cValue( aFilter ) + cCondition + ::cExpresionField( aFilter )  
   else
      ::cExpresionFilter   += ::cExpresionField( aFilter ) + cCondition + ::cValue( aFilter )
   end if 

Return ( Self )

//--------------------------------------------------------------------------//

METHOD ChgFields()

   local oDlg

   if Empty( ::aTField )
      MsgStop( "No hay tabla definida." )
      return ( Self )
   end if

   DEFINE DIALOG oDlg RESOURCE "ChangeFields"

   REDEFINE COMBOBOX ::oReplace ;
      VAR      ::cReplace ;
      ITEMS    ::aTblMask ;
      ID       80 ;
      OF       oDlg

   ::oReplace:bChange   := {|| ::cFldReplace := ::aTblField[ ::oReplace:nAt ] }

   REDEFINE GET ::oExpReplace VAR ::cExpReplace ;
      ID       90 ;
      OF       oDlg

   REDEFINE CHECKBOX ::lAllRecno ;
      ID       70 ;
      ON CHANGE( if( ::lAllRecno, ::oBrwFilter:Hide(), ::oBrwFilter:Show() ) );
      OF       oDlg

   /*
   Browse de los rangos--------------------------------------------------------
   */

   ::BrwFilter( oDlg )

   /*
   Botones del dialogo---------------------------------------------------------
   */

 REDEFINE APOLOMETER ::oMtrReplace VAR ::nMtrReplace ;
      PROMPT   "Procesando" ;
      ID       290 ;
      OF       oDlg

   REDEFINE BUTTON ;
      ID       IDOK ;
      OF       oDlg ;
      ACTION   ( if( ::ExpresionBuilder(), ( ::ExecuteReplace(), oDlg:end( IDOK ) ), ) )

   REDEFINE BUTTON ;
      ID       IDCANCEL ;
      OF       oDlg ;
      ACTION   ( oDlg:end() )

   oDlg:AddFastKey( VK_F5, {|| if( ::ExpresionBuilder(), ( ::ExecuteReplace(), oDlg:end( IDOK ) ), ) } )

   ACTIVATE DIALOG oDlg CENTER

   if oDlg:nResult != IDOK
      ::InitExpresion()
   end if

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD ExecuteReplace()

   local nRpl     := 0
   local cGetVal
   local nOrdAnt
   local nDbfRec
   local nFldPos

   if Empty( ::cFldReplace ) .or. Empty( ::cExpReplace )
      Return nil
   end if

   ::oMtrReplace:SetTotal( ( ::oDbf )->( LastRec() ) )

   nDbfRec        := ( ::oDbf )->( Recno() )
   nOrdAnt        := ( ::oDbf )->( OrdSetFocus( 0 ) )
   nFldPos        := ( ::oDbf )->( FieldPos( Rtrim( ::cFldReplace ) ) )

   if nFldPos != 0

      ( ::oDbf )->( dbGoTop() )
      while !( ::oDbf )->( eof() )

         cGetVal  := ( ::oDbf )->( Eval( Compile( cGetVal( ::cExpReplace, ValType( ( ::oDbf )->( FieldGet( nFldPos ) ) ) ) ) ) )

         if ::lAllRecno .or. ( ::oDbf )->( Eval( ::bExpFilter ) )
            
            if ( ::oDbf )->( dbRLock() )
               ( ::oDbf )->( FieldPut( nFldPos, cGetVal ) )
               ( ::oDbf )->( dbUnLock() )
            end if
            
            ++nRpl

         end if

         ::oMtrReplace:Set( ( ::oDbf )->( RecNo() ) )

         ( ::oDbf )->( dbSkip() )

      end while

   end if

   ( ::oDbf )->( OrdSetFocus( nOrdAnt ) )
   ( ::oDbf )->( dbGoTo( nDbfRec ) )

   msgInfo( "Total de registros reemplazados " + Str( nRpl ), "Proceso finalizado." )

RETURN ( nil )

//---------------------------------------------------------------------------//

METHOD AplyFilter()

   local oBlock
   local oError
   local nEvery
   local cOrdKey
   local bOrdKey

   oBlock               := ErrorBlock( {| oError | ApoloBreak( oError ) } )
   BEGIN SEQUENCE

   /*
   Borramos el filtro anterior si los hubiera--------------------------------
   */

   if !Empty( ::bOnAplyFilter )
      Eval( ::bOnAplyFilter )
   end if

   if ::cExpresionFilter != nil .and. ::lAplyFilter

      do case
         case IsObject( ::oDbf )

            if Empty( ::nRecAnterior )
               ::nRecAnterior := ( ::oDbf:cAlias )->( Recno() )
            end if

            if lAdsRdd()

               ( ::oDbf:cAlias )->( dbSetFilter( c2Block( ::cExpresionFilter + " .and. !Deleted()" ), ::cExpresionFilter + " .and. !Deleted()" ) )

               if !Empty( ::oWndBrw )
                  ::oWndBrw:ShowButtonFilter()
                  ::oWndBrw:ShowEditButtonFilter()
                  ::oWndBrw:Refresh()
               end if

            else

               SysRefresh()

               cOrdKey           := ( ::oDbf:cAlias )->( OrdKey() )

               if cOrdKey != nil

                  bOrdKey        := c2Block( cOrdKey )

                  if !Empty( ::oMtrReplace )
                     ::oMtrReplace:SetTotal( ( ::oDbf:cAlias )->( Lastrec() ) )
                     nEvery      := Int( ::oMtrReplace:nTotal / 10 )
                  end if

                  if Empty( ::cOrdAnterior )
                     ::cOrdAnterior := ( ::oDbf:cAlias )->( OrdSetFocus() )
                  end if

                  if Empty( ::nRecAnterior )
                     ::nRecAnterior := ( ::oDbf:cAlias )->( Recno() )
                  end if

                  if Empty( ::cBagAnterior )
                     ::cBagAnterior := ( ::oDbf:cAlias )->( dbOrderInfo( DBOI_FULLPATH ) )
                  end if

                  if Empty( ::cNamAnterior )
                     ::cNamAnterior := "OrdTmp" + cCurUsr()
                  end if

                  if !Empty( ::oMtrReplace )
                     ( ::oDbf:cAlias )->( OrdCondSet( ::cExpresionFilter + " .and. !Deleted()", c2Block( ::cExpresionFilter + " .and. !Deleted()" ),,, {|| ::oMtrReplace:Set( ( ::oDbf:cAlias )->( RecNo() ) ), SysRefresh() }, nEvery ) )
                  else
                     ( ::oDbf:cAlias )->( OrdCondSet( ::cExpresionFilter + " .and. !Deleted()", c2Block( ::cExpresionFilter + " .and. !Deleted()" ),,, {|| SysRefresh() } ) )
                  end if

                  ( ::oDbf:cAlias )->( OrdCreate( ::cBagAnterior, ::cNamAnterior, cOrdKey, bOrdKey ) )
                  ( ::oDbf:cAlias )->( OrdSetFocus( ::cNamAnterior, ::cBagAnterior ) )
                  ( ::oDbf:cAlias )->( dbGoTop() )

                  if !Empty( ::oWndBrw )
                     ::oWndBrw:ShowButtonFilter()
                     ::oWndBrw:ShowEditButtonFilter()
                     ::oWndBrw:Refresh()
                  end if

               else

                  MsgStop( "No existe indice para la busqueda" )

               end if

            end if

         case IsChar( ::oDbf )

            if Empty( ::nRecAnterior )
               ::nRecAnterior := ( ::oDbf )->( Recno() )
            end if

            if lAdsRdd()

               ( ::oDbf )->( dbSetFilter( c2Block( ::cExpresionFilter + " .and. !Deleted()" ), ::cExpresionFilter + " .and. !Deleted()" ) )

               if !Empty( ::oWndBrw )
                  ::oWndBrw:ShowButtonFilter()
                  ::oWndBrw:ShowEditButtonFilter()
                  ::oWndBrw:Refresh()
               end if

            else

               SysRefresh()

               cOrdKey           := ( ::oDbf )->( OrdKey() )

               if !Empty( cOrdKey )

                  bOrdKey        := c2Block( cOrdKey )

                  if !Empty( ::oMtrReplace )
                     ::oMtrReplace:SetTotal( ( ::oDbf )->( Lastrec() ) )
                     nEvery      := Int( ::oMtrReplace:nTotal / 10 )
                  end if

                  if Empty( ::cOrdAnterior )
                     ::cOrdAnterior := ( ::oDbf )->( OrdSetFocus() )
                  end if

                  if Empty( ::cBagAnterior )
                     ::cBagAnterior := ( ::oDbf )->( dbOrderInfo( DBOI_FULLPATH ) )
                  end if

                  if Empty( ::nRecAnterior )
                     ::nRecAnterior := ( ::oDbf )->( Recno() )
                  end if

                  if Empty( ::cNamAnterior )
                     ::cNamAnterior := "OrdTmp" + cCurUsr()
                  end if

                  if !Empty( ::oMtrReplace )
                     ( ::oDbf )->( OrdCondSet( ::cExpresionFilter + " .and. !Deleted()", c2Block( ::cExpresionFilter + " .and. !Deleted()" ),,, {|| ::oMtrReplace:Set( ( ::oDbf )->( RecNo() ) ), SysRefresh() }, nEvery ) )
                  else
                     ( ::oDbf )->( OrdCondSet( ::cExpresionFilter + " .and. !Deleted()", c2Block( ::cExpresionFilter + " .and. !Deleted()" ),,, {|| SysRefresh() } ) )
                  end if

                  ( ::oDbf )->( OrdCreate( ::cBagAnterior, ::cNamAnterior, cOrdKey, bOrdKey ) )
                  ( ::oDbf )->( OrdSetFocus( ::cNamAnterior, ::cBagAnterior ) )
                  ( ::oDbf )->( dbGoTop() )

                  if !Empty( ::oWndBrw )
                     ::oWndBrw:ShowButtonFilter()
                     ::oWndBrw:ShowEditButtonFilter()
                     ::oWndBrw:Refresh()
                  end if

               else

                  MsgStop( "No existe indice para la busqueda" )

               end if

            end if

      end case

      if !Empty( ::oMtrReplace )
         ::oMtrReplace:SetTotal( 0 )
      end if

   end if

   RECOVER USING oError

      msgStop( "Imposible establecer filtros " + CRLF + ErrorMessage( oError ) )

   END SEQUENCE

   ErrorBlock( oBlock )

Return ( Self )

//---------------------------------------------------------------------------//

METHOD KillFilter( oDlg )

   if !Empty( ::bOnKillFilter )
      Eval( ::bOnKillFilter )
   end if

   do case
      case IsObject( ::oDbf )

         if lAdsRdd()

            ( ::oDbf:cAlias )->( dbClearFilter() )

         else

            if !Empty( ::cBagAnterior )
               ( ::oDbf:cAlias )->( OrdSetFocus( ::cOrdAnterior, ::cBagAnterior ) )
               ( ::oDbf:cAlias )->( OrdDestroy( ::cNamAnterior, ::cBagAnterior ) )
            end if

         end if

      case IsChar( ::oDbf )

         if lAdsRdd()

            ( ::oDbf )->( dbClearFilter() )

         else

            if !Empty( ::cBagAnterior )
               ( ::oDbf )->( OrdSetFocus( ::cOrdAnterior, ::cBagAnterior ) )
               ( ::oDbf )->( OrdDestroy( ::cNamAnterior, ::cBagAnterior ) )
            end if

         end if

   end case

   ::cOrdAnterior := nil
   ::nRecAnterior := nil
   ::cBagAnterior := nil
   ::cNamAnterior := nil

   ::InitExpresion()

   do case
      case IsObject( ::oDbf )

         if !Empty( ::nRecAnterior )
            ( ::oDbf:cAlias )->( dbGoTo( ::nRecAnterior ) )
         else
            ( ::oDbf:cAlias )->( dbGoTop() )
         end if

      case IsChar( ::oDbf )

         if !Empty( ::nRecAnterior )
            ( ::oDbf )->( dbGoTo( ::nRecAnterior ) )
         else
            ( ::oDbf )->( dbGoTop() )
         end if

   end case

   if !Empty( ::oWndBrw )
      ::oWndBrw:HideButtonFilter()
      ::oWndBrw:HideEditButtonFilter()
      ::oWndBrw:Refresh()
   end if

   if !Empty( oDlg )
      oDlg:End()
   end if

RETURN ( Self )

//--------------------------------------------------------------------------//

METHOD SaveFilter()

   local aFilter
   local n        := 1
   local c        := ""
   local lExiste  := .t.

   if !::ExpresionBuilder() // !::ExpMaker() .or. 
      Return ( .f. )
   end if

   // Tomamos un nombre para el filtro-----------------------------------------

   if ::lGetFilterName()

      if !Empty( ::oDlg )
         ::oDlg:Disable()
      end if 

      // Si el nuevo es un filtro por defecto quitamos todos-------------------

      if ::lDefaultFilter

         if ( ::cDbfFilter )->( dbSeek( ::cTipFilter ) )

            while ( ( ::cDbfFilter)->cTipDoc == ::cTipFilter .and. !( ::cDbfFilter )->( eof() ) )

               if ( ::cDbfFilter )->( dbRLock() )
                  ( ::cDbfFilter )->lDefFlt  := .f.
                  ( ::cDbfFilter )->( dbUnLock() )
               end if

               ( ::cDbfFilter )->( dbSkip() )

            end while

         end if

      end if

      // Anotamos el filtro----------------------------------------------------

      lExiste     := ( ::cDbfFilter)->( dbSeek( ::cTipFilter + Upper( ::cTexFilter ) ) )

      if dbDialogLock( ::cDbfFilter, !lExiste )

         ( ::cDbfFilter )->cCodUsr     := if( !::lAllUser, cCurUsr(), Space( 3 ) )
         ( ::cDbfFilter )->cTipDoc     := ::cTipFilter
         ( ::cDbfFilter )->cTexFlt     := ::cTexFilter
         ( ::cDbfFilter )->cExpFlt     := ::cExpresionFilter
         ( ::cDbfFilter )->lDefFlt     := ::lDefaultFilter
         ( ::cDbfFilter )->cFldFlt     := ::cSerializeFilter()

         ( ::cDbfFilter )->( dbUnLock() )

      end if

      if !Empty( ::oDlg )
         ::oDlg:Enable()
      end if 

   end if

Return ( .t. )

//---------------------------------------------------------------------------//

METHOD DeleteFilter( oDlg )

   if oUser():lNotConfirmDelete() .or. ApoloMsgNoYes( "� Desea eliminar el filtro : " + Alltrim( ( ::cDbfFilter)->cTexFlt ) + " ?", "Confirme supresi�n" )

      if !Empty( ::oWndBrw )
         ::oWndBrw:EnableComboFilter( ::aFilter )
         ::KillFilter()
      end if
      
      if !Empty( oDlg )
         oDlg:End()
      end if 
      
      if !Empty( ::oBrwAlmacenados )
         ::oBrwAlmacenados:Refresh()
      end if 

      Return ( .t. )

   end if

Return ( .f. )

//---------------------------------------------------------------------------//

Method lGetFilterName()

   local oDlg

   ::cTexFilter   := Padr( ::cTexFilter, 100 )

   DEFINE DIALOG oDlg RESOURCE "Nombre_Filtro"

   REDEFINE GET ::cTexFilter ;
      ID          100 ;
      OF          oDlg

   REDEFINE CHECKBOX ::lDefaultFilter ;
      ID          110 ;
      OF          oDlg

   REDEFINE CHECKBOX ::lAllUser ;
      WHEN        ( oUser():lAdministrador() );
      ID          120 ;
      OF          oDlg

   REDEFINE BUTTON ;
      ID          IDOK ;
      OF          oDlg ;
      ACTION      ( if( ::lValidFilterName(), oDlg:end( IDOK ), ) )

   REDEFINE BUTTON ;
      ID          IDCANCEL ;
      OF          oDlg ;
      ACTION      ( oDlg:end() )

   oDlg:AddFastKey( VK_F5, {|| oDlg:end( IDOK ) } )

   ACTIVATE DIALOG oDlg CENTER

Return ( oDlg:nResult == IDOK )

//---------------------------------------------------------------------------//

Method lValidFilterName()

   if Empty( ::cTexFilter )
      MsgStop( "El nombre del filtro no puede estar vacio" )
      Return ( .f. )
   end if

Return ( .t. )

//---------------------------------------------------------------------------//

Method LoadFilter( cExpresionFilter )

   if Empty( ::cTipFilter )
      msgStop( "El tipo del filtro esta vacio")
      Return .f.
   end if

   if Empty( cExpresionFilter )
      msgStop( "El texto del filtro esta vacio")
      Return .f.
   end if

   if ( ::cDbfFilter )->( dbSeek( ::cTipFilter + Rtrim( Upper( cExpresionFilter ) ) ) )

      CursorWait()

      // Deserializamos el filtro-------------------------------------------
      
      ::cDeSerializeFilter( ( ::cDbfFilter )->cFldFlt )
      
      // Colocamos los campos segun su tipo---------------------------------

      aEval( ::aFilter, {| a | if( len( a ) > 0, a[ 3 ] := ::uValue( a ), ) } )
      
      if !Empty( ::oBrwFilter )
         ::oBrwFilter:SetArray( ::aFilter )
      end if 
      
      if !Empty( ::oDlg ) .and. !Empty( ::oDlg:oTop )
         ::oDlg:oTop:SetOption( 1 )
         ::oDlg:oTop:Refresh()
      end if
      
      if !Empty( ::oFld )
         ::oFld:SetOption( 1 )
      end if 

      CursorWE()

   else
      
      MsgStop( "C�digo de filtro " + ::cTipFilter + " - " + Rtrim( Upper( cExpresionFilter ) ) + " no encontrado" )
      
      Return .f.

   end if 

Return ( .t. )

//---------------------------------------------------------------------------//

Method lBuildFilter()

   local lBuild      := .f.

   if Empty( ::cExpresionFilter )
      Return ( lBuild )
   end if

   ::SelectTable( ::oDbf )

   if At( Type( ::cExpresionFilter ), "UEUI" ) != 0

      msgStop( "Expresi�n " + Rtrim( ::cExpresionFilter ) + " no valida" )

      ::cExpresionFilter   := ""
      ::cExpresionFilter   := ""
      ::bExpFilter   := nil
   
   else
   
      ::bExpFilter   := Compile( ::cExpresionFilter )
   
      lBuild         := .t.
   
   end if

Return ( lBuild )

//---------------------------------------------------------------------------//

METHOD LoadTypeFilter()

   if Empty( ::cDbfFilter )
      Return .f.
   end if

   if Empty( ::cTipFilter )   
      Return .f.
   endif

   ::aFiltersName    := {}

   if ( ::cDbfFilter )->( dbSeek( ::cTipFilter ) )

      while ( ::cDbfFilter )->cTipDoc == ::cTipFilter .and. !( ::cDbfFilter )->( eof() )

         aAdd( ::aFiltersName, Rtrim( ( ::cDbfFilter )->cTexFlt ) )

         ( ::cDbfFilter )->( dbSkip() )

      end do

   end if

Return .t. 

//---------------------------------------------------------------------------//

METHOD SetFilter( cText )

   local nFilter        := 0

   if !Empty( cText )

      nFilter           := aScan( ::aFilter, {|a| a[ 1 ] == cText } )
      if nFilter != 0

         ::cTexFilter   := ::aFilter[ nFilter, 1 ]
         ::cExpresionFilter   := ::aFilter[ nFilter, 2 ]

         ::lBuildAplyFilter()

      else

         ::KillFilter()

      end if

   end if

return nil

//---------------------------------------------------------------------------//

Static Function bFiltro( aItems, dbfFlt, dbf, oButton, oWndBrw )

   local cTip     := by( ( dbfFlt )->cTipDoc )
   local cTxt     := by( ( dbfFlt )->cTexFlt )
   local bGen     := {|| TDlgFlt():New( aItems, dbf, oButton, .t., oWndBrw ):Resource( cTip, cTxt, dbfFlt ) }

Return ( bGen )

//---------------------------------------------------------------------------//

FUNCTION mkFilter( cPath, oMeter )

   DEFAULT cPath     := cPatDat()

   if oMeter != NIL
      oMeter:cText   := "Generando Bases"
      sysrefresh()
   end if

   dbCreate( cPath + "CnfFlt.Dbf", aSqlStruct( aItmFilter() ), cDriver() )

   rxFilter( cPath, oMeter )

RETURN .t.

//--------------------------------------------------------------------------//

FUNCTION rxFilter( cPath, oMeter )

   local dbfFilter

   DEFAULT cPath     := cPatDat()

   if !lExistTable( cPath + "CnfFlt.Dbf" )
      dbCreate( cPath + "CnfFlt.Dbf", aSqlStruct( aItmFilter() ), cDriver() )
   end if

   fEraseIndex( cPath + "CnfFlt.Cdx" )

   dbUseArea( .t., cDriver(), cPath + "CnfFlt.Dbf", cCheckArea( "CnfFlt", @dbfFilter ), .f. )

   if !( dbfFilter )->( neterr() )

      ( dbfFilter )->( __dbPack() )

      ( dbfFilter )->( ordCondSet( "!Deleted()", {||!Deleted()}  ) )
      ( dbfFilter )->( ordCreate( cPath + "CnfFlt.Cdx", "cTipDoc", "cTipDoc + Upper( cTexFlt )", {|| Field->cTipDoc + Upper( Field->cTexFlt ) } ) )

      ( dbfFilter )->( dbCloseArea() )

   else

      msgStop( "Imposible abrir en modo exclusivo la tabla de filtros" )

   end if

RETURN NIL

//--------------------------------------------------------------------------//

FUNCTION aItmFilter()

   local aBase := {}

   aAdd( aBase, { "cTipDoc",  "C",  2, 0, "Tipo de documento" }            )
   aAdd( aBase, { "cCodUsr",  "C",  3, 0, "Usuario" }                      )
   aAdd( aBase, { "cTexFlt",  "C",100, 0, "Descripci�n" }                  )
   aAdd( aBase, { "cFldFlt",  "M", 10, 0, "Texto largo de la nota" }       )
   aAdd( aBase, { "cExpFlt",  "M", 10, 0, "Expresi�n del filtro" }         )
   aAdd( aBase, { "lDefFlt",  "L",  1, 0, "L�gico de filtro por defecto" } )

RETURN ( aBase )

//----------------------------------------------------------------------------//

STATIC FUNCTION cGetValue( xVal, cType )

   local cTemp    := ""

   DEFAULT cType  := ValType( xVal )

   do case
      case cType == "C" .or. cType == "M"

         if !Empty( xVal )
            xVal  := Rtrim( xVal )
         end if
         
         if ( '"' $ xVal ) .or. ( "'" $ xVal )
            cTemp := Rtrim( cValToChar( xVal ) )
         else
            cTemp := '"' + Rtrim( cValToChar( xVal ) ) + '"'
         end if

      case cType == "N"
         cTemp    := cValToChar( xVal )

      case cType == "D"

         cTemp    := 'Ctod( "' + Rtrim( cValToChar( xVal ) ) + '" )'

      case cType == "L"
         if "S" $ Rtrim( Upper( xVal ) )
            cTemp := ".t."
         else
            cTemp := ".f."
         end if

   end case

RETURN ( Rtrim( cTemp ) )

//--------------------------------------------------------------------------//

METHOD ChgGet( cType, nLen, nDec, n )

   ::oValFilter[n]:bValid       := {|| .t. }
   ::oValFilter[n]:oGet:Picture := ""

   if cType == "L"
      ::oValFilter[n]:bValid := {| oVal | oVal:varGet() $ "SN" }
   end if

   ::oValFilter[n]:refresh()

RETURN ( Self )

//--------------------------------------------------------------------------//

STATIC FUNCTION retGet( cType, nLen, nDec )

   local cRet  := ""

   do case
      case cType == "L"
         cRet  := "S"
      case cType == "C"
         cRet  := Space( nLen )
      case cType == "N"
         cRet  := 0
      case cType == "D"
         cRet  := date()
   end case

RETURN cRet

//--------------------------------------------------------------------------//

STATIC FUNCTION cGetVal( xVal, cType, cNexo )

   local cTemp    := ""

   DEFAULT cType  := ValType( xVal )

   if "$" $ xVal
      xVal        := Rtrim( StrTran( xVal, "$", "" ) )
      xVal        := &( xVal )
   end if

   if SubStr( xVal, 1, 1 ) == "&"
      Return ( cGetVal( Eval( bChar2Block( SubStr( xVal, 2 ) ) ), cType ) )
   end if

   do case
      case cType == "C" .or. cType == "M"
         if !Empty( xVal )
            xVal  := Rtrim( xVal )
         end if
         if ( '"' $ xVal ) .or. ( "'" $ xVal )
            cTemp := Rtrim( cValToChar( xVal ) )
         else
            cTemp := '"' + Rtrim( cValToChar( xVal ) ) + '"'
         end if

      case cType == "N"
         cTemp    := cValToChar( xVal )

      case cType == "D"

         do case
            case cNexo == "Dow()"
               cTemp := Rtrim( cValToChar( xVal ) )
            case cNexo == "Month()"
               cTemp := Rtrim( cValToChar( xVal ) )
            case cNexo == "Year()"
               cTemp := Rtrim( cValToChar( xVal ) )
            otherwise
               cTemp := 'Ctod( "' + Rtrim( cValToChar( xVal ) ) + '" )'
         end case

      case cType == "L"
         if "S" $ Rtrim( Upper( xVal ) )
            cTemp := ".t."
         else
            cTemp := ".f."
         end if

   end case

RETURN ( Rtrim( cTemp ) )

//---------------------------------------------------------------------------//

STATIC FUNCTION cGetField( xField, cType )

   local cTemp    := ""

   DEFAULT cType  := ValType( xField )

   if cType == "C" .or. cType == "M"
      cTemp       := 'Rtrim( ' + Rtrim( xField ) + ' )'
   else
      cTemp       := xField
   end case

RETURN ( cTemp )

//---------------------------------------------------------------------------//


