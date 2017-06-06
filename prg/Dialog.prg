#include "FiveWin.ch"
#include "Constant.ch"

#define LTGRAY_BRUSH     1
#define GRAY_BRUSH       2

#define WM_CTLCOLOR     25  // 0x19       // Don't remove Color Control
#define WM_ERASEBKGND   20  // 0x0014     // or controls will not shown
                                          // colors !!!
#define WM_DRAWITEM     43  // 0x002B
#define WM_MEASUREITEM  44  // 0x002C
#define WM_SETFONT      48
#define WM_SETICON     128
#define WM_NCPAINT     133    // 0x085
#define WM_PRINTCLIENT 792

#define CBN_SELCHANGE      1
#define CBN_CLOSEUP        8

#define GWL_STYLE        -16
#define GW_CHILD           5
#define GW_HWNDNEXT        2
#define GWL_EXSTYLE      -20

#define COLOR_BTNFACE     15
#define COLOR_BTNTEXT     18
#define SC_HELP        61824
#define FN_ZIP         15001

#define WS_EX_CONTEXTHELP   1024

#define SWP_NOZORDER       4
#define SWP_NOREDRAW       8
#define SWP_NOACTIVATE    16

#define SC_CLOSE       61536   // 0xF060
#define SW_HIDE            0

extern Set

static aGradColors // Colors to use to GRADIENT dialogs

//----------------------------------------------------------------------------//

CLASS TDialog FROM TWindow

   CLASSDATA lRegistered AS LOGICAL

   DATA   cResName, cResData
   DATA   hResources
   DATA   lCentered, lCenterInWnd, lModal, lModify
   DATA   bStart
   DATA   lHelpIcon  // Windows 95 help icon pressed
   DATA   lResize16  // resize 32 bits resources to look like 16 bits ones
   DATA   lTransparent // transparent controls when using bitmaped brushes
   DATA   bNcActivate

   METHOD New( nTop, nLeft, nBottom, nRight, cCaption, cResName, hResources,;
               lVbx, nStyle, nClrText, nClrBack, oBrush, oWnd, lPixels,;
               oIco, oFont, nHelpId, nWidth, nHeight, lTransparent, aNewGradColors,;
               cVarName ) CONSTRUCTOR

   METHOD Define( nTop, nLeft, nBottom, nRight, cCaption, nStyle,;
                  nClrText, nClrPane, oBrush ) CONSTRUCTOR

   METHOD Activate( bClicked, bMoved, bPainted, lCentered, bValid, lModal,;
                    bInit, bRClicked, bWhen, lResize16, lCenterInWnd )

   METHOD AdjTop() INLINE WndAdjTop( ::hWnd )

   METHOD ChangeFocus() INLINE ::PostMsg( FM_CHANGEFOCUS )

   METHOD Close( nResult )

   METHOD Command( nWParam, nLParam )

   METHOD CtlColor( hWndChild, hDCChild )

   METHOD cGenPrg()

   METHOD cToChar( hActiveWnd )
   METHOD DefControl( oControl )

   METHOD Destroy() INLINE ::Super:Destroy(), If( ! ::lModal, .t., nil )

   METHOD Display() INLINE ::BeginPaint(), ::Paint(), ::EndPaint(),;
                           If( ::bStart != nil,;
                               Eval( ::bStart, ::bStart := nil ),), .f.

   METHOD ReSize( nSizeType, nWidth, nHeight ) INLINE ( ::Super:Resize( nSizeType, nWidth, nHeight ), ::Refresh() )

   METhod End( nResult )

   METHOD EraseBkGnd( hDC )

   METHOD GetHotPos( nChar, hCtrlAt )

   METHOD GetItem( nId ) INLINE  GetDlgItem( ::hWnd, nId )

   METHOD GotFocus() INLINE ::lFocused := .t.,;
                            If( ::bGotFocus != nil, Eval( ::bGotFocus ), nil )

   METHOD HandleEvent( nMsg, nWParam, nLParam )

   METHOD Help( nWParam, nLParam )

   METHOD Initiate( hWndFocus, hWnd )

   METHOD KeyChar( nKey, nFlags )

   METHOD KeyDown( nKey, nFlags )

   METHOD LostFocus() INLINE ::lFocused := .f.,;
                             If( ::bLostFocus != nil, Eval( ::bLostFocus ), nil )

   METHOD MouseMove( nRow, nCol, nKeyFlags )

   METHOD NCActivate( lOnOff ) INLINE If( ! Empty( ::bNcActivate ), Eval( ::bNcActivate, lOnOff, Self ),)

   METHOD Paint()

   METHOD PrintClient( hDC ) INLINE 1

   METHOD QueryEndSession() INLINE  ! ::End()

   METHOD SetControl( oCtrl ) INLINE ;
          ::oClient := oCtrl, ::ReSize()

   METHOD SetFont( oFont )

   METHOD SetSize( nWidth, nHeight, lRepaint ) INLINE ;
              ::Super:SetSize( nWidth, nHeight, lRepaint ),;
              If( aGradColors != nil, ::Gradient( aGradColors ),)

   METHOD SysCommand( nWParam, nLParam )

   METHOD VbxFireEvent( pEventInfo ) INLINE VBXEvent( pEventInfo )

   METHOD Help95()

ENDCLASS

//----------------------------------------------------------------------------//

METHOD New( nTop, nLeft, nBottom, nRight, cCaption, cResName, hResources,;
            lVbx, nStyle, nClrText, nClrBack, oBrush, oWnd, lPixels,;
            oIco, oFont, nHelpId, nWidth, nHeight, lTransparent, aNewGradColors,;
            cVarName ) CLASS TDialog

   DEFAULT hResources := GetResources(), lVbx := .f.,;
           nClrText   := GetSysColor( COLOR_BTNTEXT ), nClrBack := GetSysColor( COLOR_BTNFACE ),;
           lPixels    := .f., nTop := 0, nLeft := 0, nBottom := 10, nRight := 40,;
           nWidth     := 0, nHeight := 0, lTransparent := .f.,;
           nStyle     := nOR( DS_MODALFRAME, WS_POPUP, WS_CAPTION, WS_SYSMENU ),;
           cVarName   := "oDlg"

   if nWidth != 0 .or. nHeight != 0
      if ! lPixels
         lPixels = .t.
      endif
      nBottom = nHeight
      nRight  = nWidth
   endif

   if ! Empty( aNewGradColors ) .or. ! Empty( aGradColors )
      lTransparent = .T.
   endif

   ::aControls  = {}
   ::cResName   = cResName
   ::cCaption   = If( cCaption != nil, SubStr( cCaption, 1, Min( Len( cCaption ), 140 ) ), nil )
   ::hResources = hResources
   ::lModify    = .t.
   ::lVbx       = lVbx
   ::lVisible   = .f.
   ::nResult    = 0
   ::nStyle     = nStyle
   ::oWnd       = oWnd
   ::oIcon      = oIco
   if oFont != nil
      oFont:nCount++
      ::oFont      = oFont
   endif
   ::nLastKey   = 0
   ::nHelpId    = nHelpId
   ::lResize16  = .f.
   ::lTransparent = lTransparent
   ::aGradColors  = aNewGradColors
   // ::lHelpIcon  = .t.
   ::cVarName   = cVarName

   if ValType( oIco ) == "C"
      if File( oIco )
         DEFINE ICON oIco FILENAME oIco
      else
         DEFINE ICON oIco RESOURCE oIco
      endif
      ::oIcon := oIco
   endif

   ::SetColor( nClrText, nClrBack, oBrush )

   if lPixels  // New PIXELS Clausule
      ::nTop       = nTop
      ::nLeft      = nLeft
      ::nBottom    = nBottom
      ::nRight     = nRight
   else
      // Compatibility
      ::nTop    := int( nTop    * DLG_CHARPIX_H )
      ::nLeft   := int( nLeft   * DLG_CHARPIX_W )
      ::nBottom := int( nBottom * DLG_CHARPIX_H  )
      ::nRight  := int( nRight  * DLG_CHARPIX_W  )
   endif

   if lVbx
     if ! VbxInit( GetInstance(), "" )
         MsgAlert( "VBX support not available" )
      endif
   endif

   ::Register( nOr( CS_VREDRAW, CS_HREDRAW ) )

   SetWndDefault( Self )          //  Set Default DEFINEd Window

return Self

//----------------------------------------------------------------------------//

METHOD Activate( bLClicked, bMoved, bPainted, lCentered, ;
                 bValid, lModal, bInit, bRClicked, bWhen, lResize16, ;
                 lCenterInWnd ) CLASS TDialog

   static nDlgCount := 0

   local hActiveWnd, hWnd, bDlgProc

   DEFAULT lCentered := .f., lModal := .t., ::hWnd := 0, lResize16 := .f., lCenterInWnd := .f.

   ::nLastKey = 0

   ++nDlgCount

   hActiveWnd = If( ::oWnd != nil, ::oWnd:hWnd,;
                If( nDlgCount > 1 .or. lWRunning(),;
                    GetActiveWindow(), GetWndApp() ) )

   ::lCentered   = lCentered
   ::lCenterInWnd = lCenterInWnd
   ::lModal      = lModal
   ::bLClicked   = bLClicked
   ::bRClicked   = bRClicked
   ::bWhen       = bWhen
   ::bValid      = bValid
   ::bInit       = bInit
   ::bPainted    = bPainted
   ::bMoved      = bMoved
   ::nResult     = nil
   ::lValidating = .f.
   ::lVisible    = .t.
   ::lResize16   = lResize16

   if ::bWhen != nil
      if ! Eval( ::bWhen, Self )
          ::nResult  = IDCANCEL
          ::lVisible = .F.
          return nil
      endif
   endif

   if lModal
      ::nResult = if( ! Empty( ::cResName ),;
                      DialogBox( ::hResources, ::cResName,;
                                 hActiveWnd, Self ),;
                      DialogBoxIndirect( GetInstance(),;
                                         If( ! Empty( ::cResData ), ::cResData, ::cToChar( hActiveWnd ) ),;
                                         hActiveWnd, Self ) )

      if ::nResult == 65535
         CreateDlgError( Self )
      endif

   else
      if ( Len( ::aControls ) > 0 .and. CanRegDialog() ) .or. ;
           Len( ::aControls ) == 0

         if ! Empty( ::cResName )
            ::hWnd = CreateDlg( ::hResources, ::cResName, hActiveWnd )
         else
            ::hWnd = CreateDlgIndirect( GetInstance(), ::cToChar( hActiveWnd ),;
                                        hActiveWnd )
         endif

         if ::hWnd == 0
            CreateDlgError( Self )
         else
            ShowWindow( ::hWnd, SW_HIDE )
         endif

         if Len( ::aControls ) > 0 .and. ! RegDialog( ::hWnd )
            ::SendMsg( WM_CLOSE )
            MsgAlert( "Not possible to create more non-modal Dialogs" )
         endif

         if ::Initiate()
            ::SetFocus()
         endif

         ::Show()
         ::Refresh() // needed for resource dialogs
      else
         MsgAlert( "Not possible to create more non-modal Dialogs" )
      endif
   endif

   nDlgCount--

   if ::lModal
      ::lVisible = .f.
   endif

return nil

//---------------------------------------------------------------------------//

METHOD DefControl( oCtrl ) CLASS TDialog

   DEFAULT oCtrl:nId := oCtrl:GetNewId()

   if AScan( ::aControls, { | o | o:nId == oCtrl:nId } ) > 0
      #define DUPLICATED_CONTROLID  2
      Eval( ErrorBlock(), _FWGenError( DUPLICATED_CONTROLID, ;
                          "No: " + Str( oCtrl:nId, 6 ) ) )
   else
      AAdd( ::aControls, oCtrl )
      oCtrl:hWnd = 0
   endif

return nil

//----------------------------------------------------------------------------//

METHOD Command( nWParam, nLParam ) CLASS TDialog

   local oWnd, nNotifyCode, nID, hWndCtl

   nNotifyCode = nHiWord( nWParam )
   nID         = nLoWord( nWParam )
   hWndCtl     = nLParam

   do case
      case ::oPopup != nil
           ::oPopup:Command( nID )

      case hWndCtl == 0 .and. ::oMenu != nil .and. ;
           If( nNotifyCode == BN_CLICKED, nID != IDCANCEL, .f. )
           ::oMenu:Command( nID )

      case GetClassName( hWndCtl ) == "ToolbarWindow32"
           oWndFromHwnd( hWndCtl ):Command( nWParam, nLParam )
           return .T. // otherwise a child dialog gets closed

      case ::oMenu != nil .and. nId != 2 .and. nNotifyCode != BN_CLICKED
           if nNotifyCode == 1
              ::oMenu:Command( nID )
           endif

      case nID != 0
           do case
              case nNotifyCode == BN_CLICKED
                   if hWndCtl != 0 .and. nID != IDCANCEL
                      oWnd := oWndFromhWnd( hWndCtl )
                      if ValType( ::nResult ) == "O" // latest control which had focus
                         // There is a pending Valid, it is not a clicked button
                         if oWnd != nil
                            if ! oWnd:lCancel
                               if ::nResult:nID != nID .and. ! ::nResult:lValid()
                                  return nil
                               endif
                            endif
                         else
                            if ::nResult:nID != nID .and. ! ::nResult:lValid()
                               return nil
                            endif
                         endif
                      endif

                      if AScan( ::aControls, { |o| o:nID == nID } ) > 0
                         #ifdef __XPP__
                            PostMessage( hWndCtl, FM_CLICK, 0, 0 )
                         #else
                            SendMessage( hWndCtl, FM_CLICK, 0, 0 )
                         #endif
                      elseif nID == IDOK
                         ::End( IDOK )
                      endif
                   else
                      if nID == IDOK
                         ::GoNextCtrl( GetFocus() )
                         if ! ::lModal
                            return 0
                         endif
                      elseif hWndCtl != 0 .and. ; // There is a control for IDCANCEL
                             AScan( ::aControls, { |o| o:nID == nID } ) > 0
                             SendMessage( hWndCtl, FM_CLICK, 0, 0 )
                             return .F.
                      else
                         ::End( IDCANCEL )
                      endif
                   endif

              case nNotifyCode == CBN_SELCHANGE
                   SendMessage( hWndCtl, FM_CHANGE, 0, 0 )

              case nNotifyCode == CBN_CLOSEUP
                   SendMessage( hWndCtl, FM_CLOSEUP, 0, 0 )

           endcase
   endcase

return nil

//----------------------------------------------------------------------------//

METHOD CtlColor( hWndChild, hDCChild ) CLASS TDialog

   local uVal

   if ::oWnd != nil .and. Upper( ::oWnd:ClassName() ) $ "TFOLDER,TFOLDEREX,TPAGES" ;
      .and. GetClassName( hWndChild ) $ "Button,Static" ;
      .and. IsAppThemed()
      uVal = DrawThemed( hWndChild, hDCChild )
      SendMessage( hWndChild, FM_COLOR, hDCChild )
      return uVal
   endif

return ::Super:CtlColor( hWndChild, hDCChild )

//----------------------------------------------------------------------------//

METHOD cGenPrg() CLASS TDialog

   local cSource := ::Super:cGenPrg( , .T. ) // use dialog units

   cSource = StrTran( cSource, "WINDOW", "DIALOG" )
   cSource = StrTran( cSource, "oWnd", "oDlg" )

return cSource

//----------------------------------------------------------------------------//

METHOD cToChar( hActiveWnd ) CLASS TDialog

   local cResult
   local aControls := ::aControls
   local n     := GetDlgBaseUnits()
   local aRect := GetWndRect( hActiveWnd )

   DEFAULT ::cCaption := ""

   cResult = cDlg2Chr( Len( aControls ),;
                       Int( 8 * ( ::nTop  - aRect[ 1 ]   ) / nHiWord( n ) ),;
                       Int( 4 * ( ::nLeft - aRect[ 2 ]   ) / nLoWord( n ) ),;
                       Int( 8 * ( ::nBottom - aRect[ 1 ] ) / nHiWord( n ) ),;
                       Int( 4 * ( ::nRight  - aRect[ 2 ] ) / nLoWord( n ) ),;
                       ::cCaption, ::nStyle )

   for n = 1 to Len( aControls )
      cResult += aControls[ n ]:cToChar()
   next

return cResult

//----------------------------------------------------------------------------//

METHOD Define( nTop, nLeft, nBottom, nRight, cCaption, nStyle, lVbx,;
               nClrText, nClrBack, oBrush ) CLASS TDialog

   DEFAULT lVbx     := .f.,;
           nClrText := GetSysColor( COLOR_BTNTEXT ), nClrBack := GetSysColor( COLOR_BTNFACE )

   ::hWnd      = 0
   ::nTop      = nTop
   ::nLeft     = nLeft
   ::nBottom   = nBottom
   ::nRight    = nRight
   ::cCaption  = If( cCaption != nil, SubStr( cCaption, 1, Min( Len( cCaption ), 140 ) ), nil )
   ::nStyle    = nStyle
   ::lVbx      = lVbx
   ::nLastKey  = 0
   // ::lHelpIcon = .t.

   ::SetColor( nClrText, nClrBack, oBrush )

return Self

//----------------------------------------------------------------------------//

METHOD End( nResult ) CLASS TDialog

   DEFAULT nResult := 2              // Cancel

   if ! ::lModal
      ::PostMsg( WM_CLOSE, nResult )
   else
      if ValType( ::bValid ) == "B"
         if ! Eval( ::bValid, Self )
            return .f.
         endif
      endif
      ::nResult = nResult
      EndDialog( ::hWnd, nResult )
   endif

   SysRefresh()
   // hb_gcAll()         // Garbage collector

return .T.

//----------------------------------------------------------------------------//
// Conection with Borland's VBX DLL - at run-time !!!

DLL STATIC FUNCTION VbxInitDialog( hWnd AS WORD, hInstance AS WORD,;
                       cResName AS STRING ) AS BOOL PASCAL LIB "BIVBX10.DLL"

DLL STATIC FUNCTION VbxInit( hInstance AS WORD, cPrefix AS STRING ) ;
                    AS BOOL PASCAL LIB "BIVBX10.DLL"

DLL STATIC FUNCTION VbxTerm() AS VOID PASCAL LIB "BIVBX10.DLL"

//----------------------------------------------------------------------------//

static function CreateDlgError( Self )

   local cRes := If( ValType( ::cResName ) == "N", Str( ::cResName ), ::cResName )
   local cPad := Replicate( Chr( 32 ), 22 )

   #define CANNOTCREATE_DIALOG 3
   Eval( ErrorBlock(), ;
        _FwGenError( CANNOTCREATE_DIALOG, CRLF + cPad + ;
                     If( ! Empty( cRes ), "Resource: " + cRes,;
                     "Title: " + If( Empty( ::cCaption ), "", ::cCaption ) ) ) )
return nil

//----------------------------------------------------------------------------//

METHOD GetHotPos( nChar, hCtrlAt ) CLASS TDialog

   local hCtrl := GetWindow( ::hWnd, GW_CHILD )
   local nAt, cText

   while hCtrl != 0
      if hCtrl != hCtrlAt .and. GetParent( hCtrl ) == ::hWnd .and. ;
         IsWindowEnabled( hCtrl ) .and. ;
         ( nAt := At( "&", cText := GetWindowText( hCtrl ) ) ) != 0 .and. ;
         Lower( SubStr( cText, nAt + 1, 1 ) ) == Lower( Chr( nChar ) )
         while Upper( GetClassName( hCtrl ) ) == "STATIC" .and. hCtrl != 0
            hCtrl = GetWindow( hCtrl, GW_HWNDNEXT )
         end
         return hCtrl
      else
         hCtrl = GetWindow( hCtrl, GW_HWNDNEXT )
      endif
   end

return 0

//----------------------------------------------------------------------------//

METHOD Help( nWParam, nLParam ) CLASS TDialog

   local hWndChild := HelpCtrlHwnd( nLParam ), nAtChild

   static lShow := .f.

   ::lHelpIcon = .f.

   if ! lShow
      lShow = .t.
      if ( nAtChild := AScan( ::aControls, { | o | o:hWnd == hWndChild } ) ) != 0 .and. ;
         ! Empty( ::aControls[ nAtChild ]:nHelpID )
         ::aControls[ nAtChild ]:HelpTopic()
      else
         ::HelpTopic()
      endif
      lShow = .f.
      return 1
   endif

return nil

//----------------------------------------------------------------------------//

METHOD Initiate( hWndFocus, hWnd ) CLASS TDialog

   local lFocus := .t., lResult, hCtrl, lEnd := .f., aRect
   local oParentWnd

   if hWnd != nil
      ::hWnd = hWnd
   endif

   if ! ::lModal
      ::Link()
   endif

   if ::lVbx
      if ! VbxInitDialog( ::hWnd, GetResources(), ::cResName )
         MsgAlert( "Error on VBX's initialization" )
      endif
   endif

   if ::oFont == nil
      ::GetFont()
   else
      ::SetFont( ::oFont )
   endif

   if ! Empty( ::aGradColors )
      ::Gradient( ::aGradColors )
   elseif ! Empty( aGradColors )
      ::Gradient( aGradColors )
   endif


   if ::lTransparent
      FixSays( ::hWnd, ::oBrush:hBrush )
      AEval( ::aControls,;
             { | o | If( ! Upper( o:ClassName() ) $ ;
             "TGET;TMULTIGET;TBTNBMP;TCOMBOBOX;TWBROWSE;TCBROWSE;TXBROWSE;TLISTBOX;TDBCOMBO;TDATEPICK" .and. ;
               ! o:IsKindOf( 'TXBROWSE' ) .and. ! o:isKindOf( "TBTNFLAT" ), o:lTransparent := .T., ) } )
   endif

   ASend( ::aControls, "INITIATE()", ::hWnd )

   #define SCALE_FACTOR 1.16668

   if ::lResize16 .and. ! Empty( ::cResName )
      ::nWidth = ::nWidth * SCALE_FACTOR
      hCtrl = GetWindow( ::hWnd, GW_CHILD )
      if hCtrl != 0
         while ! lEnd
            aRect = GetCoors( hCtrl )
            SetWindowPos( hCtrl, 0, aRect[ 1 ], aRect[ 2 ] * SCALE_FACTOR,;
                          ( aRect[ 4 ] - aRect[ 2 ] ) * SCALE_FACTOR,;
                          aRect[ 3 ] - aRect[ 1 ], nOr( SWP_NOZORDER,;
                          SWP_NOREDRAW, SWP_NOACTIVATE ) )
            hCtrl = GetWindow( hCtrl, GW_HWNDNEXT )
            lEnd = ! ( ( hCtrl != 0 ) .and. ( GetParent( hCtrl ) == ::hWnd ) )
         end
      endif
   endif

   if ::lCentered
      if SetCenterOnParent() .or. ::lCenterInWnd
         oParentWnd := If( ::oWnd != nil, ::oWnd, WndMain() )
      endif
      WndCenter( ::hWnd, If( oParentWnd != nil, oParentWnd:hWnd, 0 ) )

   else
      if Empty( ::cResName ) .and. Empty( ::cResData )
         ::Move( ::nTop, ::nLeft )
      endif
   endif

   if ::cCaption != nil
      ::SetText( ::cCaption )
   endif

   if ! Empty( ::cResName )
      ::nStyle := GetWindowLong( ::hWnd, GWL_STYLE )
   endif

   if lAnd( ::nStyle, WS_VSCROLL )
      DEFINE SCROLLBAR ::oVScroll VERTICAL OF Self
   endif

   if lAnd( ::nStyle, WS_HSCROLL )
      DEFINE SCROLLBAR ::oHScroll HORIZONTAL OF Self
   endif

   if ::oIcon != nil
      ::SendMsg( WM_SETICON, 0, ::oIcon:hIcon )
   endif

   ::SetAlphaLevel()

   if ::bInit != nil
      lResult = Eval( ::bInit, Self )
      if ValType( lResult ) == "L" .and. ! lResult
         lFocus = .f.
      endif
   endif

   ::Help95()  // activates the help icon on the caption

   ::AEvalWhen()

return lFocus              // .t. for default focus

//----------------------------------------------------------------------------//

METHOD EraseBkGnd( hDC ) CLASS TDialog

   if ! Empty( ::bEraseBkGnd )
      return Eval( ::bEraseBkGnd, hDC )
   endif

   if ::oBrush != nil
      ::PaintBack( hDC )
      return 1
   endif

return nil

//----------------------------------------------------------------------------//

METHOD Close( nResult ) CLASS TDialog

   if ! ::lModal
      if ValType( ::bValid ) == "B"
         if ! Eval( ::bValid, Self )
            return .F.
         endif
      endif
      if ValType( nResult ) $ "NU"
         ::nResult = nResult
      endif
      ::lVisible = .F.
      DestroyWindow( ::hWnd )
      return .T.
   endif

return nil

//----------------------------------------------------------------------------//

METHOD KeyChar( nKey, nFlags ) CLASS TDialog

   if nKey == VK_ESCAPE
      if ::oWnd != nil .and. ( ::oWnd:IsKindOf( "TMDICHILD" ) .or. ;
         ::oWnd:IsKindOf( "TDIALOG" ) .or. ::oWnd:IsKindOf( "TMDIFRAME" ) )
         if SetDialogEsc()
            ::End()
         endif
      endif
      return nil
   endif

return ::Super:KeyChar( nKey, nFlags )

//----------------------------------------------------------------------------//

METHOD KeyDown( nKey, nFlags ) CLASS TDialog

   if nKey == VK_ESCAPE
      if ::oWnd == nil
         if SetDialogEsc()
            ::End()
         endif
      else
         if ::oWnd:IsKindOf( "TMDICHILD" )
            if SetDialogEsc()
               ::End()
            endif
         else
            if ::oWnd:IsKindOf( "TDIALOG" )
               if SetDialogEsc()
                  ::End()
               endif
            elseif Upper( ::oWnd:ClassName() ) == "TMDIFRAME"
               if SetDialogEsc() // To avoid ESC being ignored
                  ::End()
               endif
            else
               return ::Super:KeyDown( nKey, nFlags )
            endif
         endif
      endif
   else
      return ::Super:KeyDown( nKey, nFlags )
   endif

return nil

//----------------------------------------------------------------------------//

METHOD MouseMove( nRow, nCol, nKeyFlags ) CLASS TDialog

   if ::lHelpIcon != nil .and. ! ::lHelpIcon
      if ::oCursor != nil
         SetCursor( ::oCursor:hCursor )
      else
         CursorArrow()
      endif
   endif

   ::SetMsg( ::cMsg )

   ::CheckToolTip()

   if ::bMMoved != nil
      return Eval( ::bMMoved, nRow, nCol, nKeyFlags )
   endif

return .f.

//----------------------------------------------------------------------------//

METHOD Paint() CLASS TDialog

   local uVal

   if ValType( ::bPainted ) == "B"
      uVal = Eval( ::bPainted, ::hDC, ::cPS, Self )
   endif

return uVal

//----------------------------------------------------------------------------//

METHOD SetFont( oFont ) CLASS TDialog

   local hDlg  := ::hWnd
   local hCtrl := GetWindow( hDlg, GW_CHILD )
   local hFont := If( ::oFont != nil, ::oFont:hFont, 0 )

   ::Super:SetFont( oFont )

   if hFont != 0
      while hCtrl != 0 .and. GetParent( hCtrl ) == hDlg
         SendMessage( hCtrl, WM_SETFONT, hFont, 1 )
         hCtrl = GetWindow( hCtrl, GW_HWNDNEXT )
      end
   endif

return nil

//----------------------------------------------------------------------------//

METHOD SysCommand( nWParam, nLParam ) CLASS TDialog

   if nWParam == SC_CLOSE .and. ::lModal
      if GetCapture() != 0
         ReleaseCapture()
      endif
      return .f.
   endif

   if nWParam == SC_HELP
      ::lHelpIcon = .t.
      return .f.
   endif

return ::Super:SysCommand( nWParam, nLParam )

//----------------------------------------------------------------------------//

METHOD Help95() CLASS TDialog

   if ::lHelpIcon == nil .or. ::lHelpIcon
      SetWindowLong( ::hWnd, GWL_EXSTYLE,;
                    nOr( GetWindowLong( ::hWnd, GWL_EXSTYLE ), WS_EX_CONTEXTHELP ) )
   endif

return nil

//----------------------------------------------------------------------------//

METHOD HandleEvent( nMsg, nWParam, nLParam ) CLASS TDialog

   if ::oMenu != nil .and. ::oMenu:oAccTable != nil
      TranslateAccelerator( ::hWnd, ::oMenu:oAccTable:nHandle,;
                            GetFocus(), nMsg, nWParam, nLParam )
   endif

   do case
      case nMsg == WM_INITDIALOG
           return ::Initiate( nWParam, nLParam )

      case nMsg == WM_PAINT
           return ::Display()

      case nMsg == WM_PRINTCLIENT
           return ::PrintClient( nWParam )

      case nMsg == WM_LBUTTONDOWN
           if ::lHelpIcon != nil .and. ::lHelpIcon
              ::Help()
           else
              return ::Super:HandleEvent( nMsg, nWParam, nLParam )
           endif

      otherwise
           return ::Super:HandleEvent( nMsg, nWParam, nLParam )
   endcase

return nil

//----------------------------------------------------------------------------//

function SetDialogEsc( lOnOff )

   local lOldStatus

   static lStatus := .T.

   lOldStatus = lStatus

   if PCount() == 1 .and. ValType( lOnOff ) == "L"
      lStatus = lOnOff
   endif

return lOldStatus

//----------------------------------------------------------------------------//

function SetCenterOnParent( lOnOff )

   local lOldStatus

   static lStatus := .F.

   lOldStatus = lStatus

   if PCount() == 1 .and. ValType( lOnOff ) == "L"
      lStatus = lOnOff
   endif

return lOldStatus

//----------------------------------------------------------------------------//

function SetDlgGradient( aNewGradColors )

   local aOldGradColors := aGradColors

   aGradColors = aNewGradColors

return aOldGradColors

//----------------------------------------------------------------------------//
