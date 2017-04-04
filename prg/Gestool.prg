#include "FiveWin.Ch"
#include "Factu.ch" 
#include "Menu.ch" 
#include "Font.ch"
#include "Inkey.ch"
#include "Ads.ch"
#include "Xbrowse.ch"
#include "dbInfo.ch" 
#include "directry.ch"
#include "hbcurl.ch"
#include "hdo.ch"

#require "hbcurl"

#define GR_GDIOBJECTS         0
#define GR_USEROBJECTS        1   

#define CS_DBLCLKS            8

#define HKEY_LOCAL_MACHINE    2147483650

#define FONT_NAME             "Segoe UI"     

ANNOUNCE RDDSYS

REQUEST ADS
REQUEST DBFCDX
REQUEST DBFFPT

REQUEST AdsKeyNo
REQUEST AdsKeyCount
REQUEST AdsGetRelKeyPos 
REQUEST AdsSetRelKeyPos

static hDLLRich

//---------------------------------------------------------------------------//
/*
-------------------------------------------------------------------------------
//Comenzamos la parte de c�digo que se compila para el ejecutable normal-------
-------------------------------------------------------------------------------
*/

function Main( paramsMain, paramsSecond, paramsThird )

   local oIndex
   local oIconApp
   
   appParamsMain( paramsMain )

   appParamsSecond( paramsSecond )
   
   appParamsThird( paramsThird )

   appSettings()
   
   appDialogExtend() 

   mainTest()

   appLoadAds()

   // Motor de bases de datos--------------------------------------------------

   if ( "ADMINISTRADOR" $ appParamsMain() )
      TDataCenter():lAdministratorTask()
      Return nil
   end if 

   // Motor de bases de datos--------------------------------------------------

   if ( "ADSINTERNET" $ cAdsType() )

      if !( appConnectADS() )
         msgStop( "Imposible conectar con GstApolo ADS data dictionary" )
         Return nil
      end if

   else 
      
      appConnectCDX()

   end if

   TDataCenter():BuildData()

   // Icono--------------------------------------------------------------------

   DEFINE ICON oIconApp RESOURCE "Gestool"

   // Opciones especiales de arranque hace la operacion y salir----------------

   do case
      case ( "ENVIO" $ appParamsMain() )

         if ( ":" $ appParamsMain() )
            cEmpUsr( Right( appParamsMain(), 2 ) )
         end if

         if lInitCheck()
            TSndRecInf():Init():AutoExecute()
         end if

         return nil

      case ( "REINDEXA" $ appParamsMain() )

         if ( ":" $ appParamsMain() )
            cEmpUsr( Right( appParamsMain(), 2 ) )
         end if

         if lInitCheck()
            oIndex               := TReindex():New()
            oIndex:lMessageEnd   := .f.
            oIndex:Resource( .t. )
         end if

         return nil

      case ( "EMPRESA" $ appParamsMain() )

         if ( ":" $ appParamsMain() )
            cEmpUsr( Right( appParamsMain(), 2 ) )
         end if

      case ( !empty( appParamsSecond() ) .and. !empty( appParamsThird() ) )

         oUser( appParamsMain(), .f. )

         setEmpresa( appParamsSecond() )

         controllerReportGallery( appParamsThird() )

         return nil

   end case

   // Obtenemos la versi�n del programa----------------------------------------

   IsStandard()
   IsProfesional()
   IsOsCommerce()

   cNameVersion()

   // Chequeamos los datos de los usuarios-------------------------------------

   if !TReindex():lFreeHandle()
      msgStop( "Existen procesos exclusivos, no se puede acceder a la aplicaci�n" + CRLF + ;
               "en estos momentos, reintentelo pasados unos segundos." )
      Return .f.
   end if

   XbrNumFormat( "E", .t. )

   do case
      case ( "TACTIL" $ appParamsMain() )
         
         if AccessCode():TactilResource()
            InitMainTactilWindow( oIconApp )
         end if

      case ( "PDA" $ appParamsMain() )
         
         if AccessCode():Resource()
            CreateMainPdaWindow( oIconApp )
         end if

      case ( "TABLET" $ appParamsMain() )
         
         if AccessCode():loadTableConfiguration()
            CreateMainTabletWindow( oIconApp )
         end if

      otherwise
         
         if AccessCode():Resource()
            CreateMainWindow( oIconApp )
         end if

   end case

   if !empty( oIconApp )
      oIconApp:end()
   end if

Return Nil

//----------------------------------------------------------------------------//

Static Function controllerReportGallery( cInitOptions )

   local hReportGallery    

   do case
      case cInitOptions == "ARTICULOS"

         if validRunReport( "01118" )
            TFastVentasArticulos():New():Play()
         end if 

      case cInitOptions == "CLIENTES"

         if validRunReport( "01120" )
            TFastVentasClientes():New():Play()
         end if 

      case cInitOptions == "PROVEEDORES"

         if validRunReport( "01121" )
            TFastComprasProveedores():New():Play()
         end if 

      case cInitOptions == "PRODUCCION"

         if validRunReport( "01123" )
            TFastProduccion():New():Play()
         end if 

   end case

Return nil

//---------------------------------------------------------------------------//

Function HelpTopic()

   msgStop( "Help wanted!" )

Return Nil

//----------------------------------------------------------------------------//

Function HelpIndex()

   goWeb( __GSTHELP__ )

Return Nil

//----------------------------------------------------------------------------//

Static Function CreateMainTabletWindow()

   lDemoMode( .f. )

   if lInitCheck()
      MainTablet()
   end if 

Return ( .t. )

//---------------------------------------------------------------------------//


init procedure InitAplication()

   REQUEST HB_LANG_ES         // Para establecer idioma de Mensajes, fechas, etc..
   REQUEST HB_CODEPAGE_ESWIN  // Para establecer c�digo de p�gina a Espa�ol (Ordenaci�n, etc..)

   hb_langselect( "ES" )      // Para mensajes, fechas, etc..
   hb_setcodepage( "ESWIN" )  // Para ordenaci�n (arrays, cadenas, etc..) *Requiere CodePage.lib

   loadLibrary( "Riched20.dll" ) // Cargamos la libreria para richedit

return

//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//

#ifdef __HARBOUR__

Static Function CreateMainPdaWindow( oIconApp )

   /*
   Chequeo inicial de la aplicacion--------------------------------------------
   */

   lInitCheck()

Return nil

//---------------------------------------------------------------------------//

Static Function ExecuteMainPdaWindow( oListView, oDlg )

Return nil

//---------------------------------------------------------------------------//

Static Function InitMainTactilWindow()

   lDemoMode( .f. )

   selCajTactil( , .t. )

   // Colocamos la sesion actual-----------------------------------------------

   chkTurno()

   TpvTactil():New():Activate( .t. )

Return nil

//--------------------------------------------------------------------------//
// Controla los accesos al programa

FUNCTION AccesTctCode()

   local oBlock
   local oError
   local oDlg
   local oBrush
   local dbfUser
   local dbfCajas
   local oImgUsr
   local oLstUsr
   local cPath
   local cPcnUsr

   /*
   Comprobamos que exista el direcotrio USR------------------------------------
   */

   if( !lIsDir( cPatUsr() ), MakeDir( cNamePath( cPatUsr() ) ), )

   cPath          := cPatDat()
   cPcnUsr        := Rtrim( NetName() )

   // Comprobamos q exista al menos un usuario master--------------------------

   IF !File( cPath + "USERS.DBF" ) .or. ;
      !File( cPath + "MAPAS.DBF" )
		mkUsuario()
	END IF

   IF !File( cPath + "USERS.CDX" ) .or. ;
      !File( cPath + "MAPAS.CDX" )
      rxUsuario()
	END IF

   While !IsMaster()
      rxUsuario()
   End While

   // Comprobamos q exista al menos una caja-----------------------------------

   While !IsCaja()
      rxCajas()
   End While

   // Comprobamos q exista al menos una impresora de ticket--------------------

   while !IsImpTik()
      rxImpTik( cPatDat() )
   end while

   // Comprobamos q exista al menos un visor-----------------------------------

   while !IsVisor()
      rxVisor( cPatDat() )
   end while

   // Comprobamos q exista al menos un cajon portamonedas----------------------

   IsCajPorta()

   // Comprobamos q exista al menos una divisa---------------------------------

   while !IsDiv()
      rxDiv()
   end while

   //Abrimos la tabla de usuarios----------------------------------------------

   oBlock            := ErrorBlock( {| oError | ApoloBreak( oError ) } )
   BEGIN SEQUENCE

      USE ( cPath + "USERS.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "USERS", @dbfUser ) )
      SET ADSINDEX TO ( cPath + "USERS.CDX" ) ADDITIVE

      USE ( cPatDat() + "CAJAS.DBF" ) NEW VIA ( cDriver() ) SHARED ALIAS ( cCheckArea( "CAJAS", @dbfCajas ) )
      SET ADSINDEX TO ( cPatDat() + "CAJAS.CDX" ) ADDITIVE

      nUsrInUse( dbfUser )

      //Cargamos la imagen de fondo de la pantalla de bienvenida------------------

      if !Os_IsWTSClient()
         DEFINE BRUSH oBrush FILE ( cBmpVersion() )
      end if

      //Montamos el di�logo con la im�gen de fondo--------------------------------

      DEFINE DIALOG  oDlg ;
         RESOURCE    "WelSerTactil" ;
         TITLE       __GSTROTOR__ + Space( 1 ) + __GSTVERSION__ + " - " + __GSTFACTORY__ ;
         BRUSH       oBrush

      /*
      Montamos la lista con los usuarios-------------------------------------
      */

         oImgUsr           := TImageList():New( 50, 50 ) //

         oLstUsr           := TListView():Redefine( 100, oDlg )
         oLstUsr:nOption   := 0
         oLstUsr:bClick    := {| nOpt | if( clickAccessTctCode( nOpt, oLstUsr, dbfUser ), oDlg:End( IDOK ), ) }

      /*
      Botones de la caja de di�logo--------------------------------------------
      */

      REDEFINE BUTTON ;
            ID       IDCANCEL ;
            OF       oDlg ;
            ACTION   ( oDlg:end() )

      /*
      Al iniciar el di�logo cargamos las im�genes de los usuarios--------------
      */

      ACTIVATE DIALOG oDlg ;
         CENTER ;
         ON INIT     ( InitBrw( oDlg, oImgUsr, oLstUsr, dbfUser ) ) ;

      SysRefresh()

      if oDlg:nResult == IDOK
         oSetUsr( ( dbfUser )->cCodUse, .t. ):Save( dbfUser, dbfCajas )
      end if

   RECOVER USING oError

      msgStop( "Imposible abrir todas las bases de datos " + CRLF + ErrorMessage( oError ) )

   END SEQUENCE

   ErrorBlock( oBlock )

   if !Empty( dbfUser )
      ( dbfUser )->( dbCloseArea() )
   end if

   if !Empty( dbfCajas )
      ( dbfCajas )->( dbCloseArea() )
   end if

   if oBrush != nil
      oBrush:End()
   end if

RETURN ( oDlg:nResult == IDOK )

//---------------------------------------------------------------------------//

Function InitBrw( oDlg, oImgUsr, oLstUsr, dbfUsr )

   local nImg     := -1
   local nUser    := 0

   if !Empty( oImgUsr ) .and. !Empty( oLstUsr )

      oImgUsr:AddMasked( TBitmap():Define( "GC_BUSINESSMAN2_50" ),   Rgb( 255, 0, 255 ) )
      oImgUsr:AddMasked( TBitmap():Define( "GC_USER2_50" ),    Rgb( 255, 0, 255 ) )

      oLstUsr:SetImageList( oImgUsr )

      oLstUsr:EnableGroupView()

      oLstUsr:SetIconSpacing( 120, 140 )

      with object ( TListViewGroup():New() )
         :cHeader := "Administradores"
         :Create( oLstUsr )
      end with

      with object ( TListViewGroup():New() )
         :cHeader := "Usuarios"
         :Create( oLstUsr )
      end with

      ( dbfUsr )->( dbGoTop() )
      while !( dbfUsr )->( eof() )

         if !( dbfUsr )->lUseUse .and. !( dbfUsr )->lGrupo

            if !Empty( ( dbfUsr )->cImagen ) .and. File( Rtrim( ( dbfUsr )->cImagen ) )

               oImgUsr:Add( TBitmap():Define( , Rtrim( ( dbfUsr )->cImagen ) ) )

               nImg++

               with object ( TListViewItem():New() )
                  :Cargo   := ( dbfUsr )->cCodUse
                  :cText   := Capitalize( ( dbfUsr )->cNbrUse )
                  :nImage  := nImg
                  :nGroup  := if( ( dbfUsr )->nGrpUse <= 1, 1, 2 )
                  :Create( oLstUsr )
               end with

            else

               with object ( TListViewItem():New() )
                  :Cargo   := ( dbfUsr )->cCodUse
                  :cText   := Capitalize( ( dbfUsr )->cNbrUse )
                  :nImage  := if( ( dbfUsr )->nGrpUse <= 1, 0, 1 )
                  :nGroup  := if( ( dbfUsr )->nGrpUse <= 1, 1, 2 )
                  :Create( oLstUsr )
               end with

            end if

         end if


         ( dbfUsr )->( dbSkip() )

      end while

      oLstUsr:Refresh()

   end if

RETURN ( nil )

//---------------------------------------------------------------------------//
//Funci�n que chequea el usuario, la clave y nos deja pasar

Static Function clickAccessTctCode( nOpt, oLstUsr, dbfUsr )

   local oItem

   // Chequeamos que seleccione almenos un usuario-----------------------------

   if Empty( nOpt )
      MsgStop( "Seleccione usuario" )
      Return .f.
   end if

   oItem       := oLstUsr:GetItem( nOpt )

   if !Empty( oItem ) .and. dbSeekInOrd( oItem:Cargo, "cCodUse", dbfUsr )

      if !( dbfUsr )->lUseUse

         // Comprobamos la clave del usuario-----------------------------------

         if lGetPsw( dbfUsr, .t. )
            Return .t.
         end if

      else

         MsgStop( "Usuario en uso" )

         Return .f.

      end if

   else

      MsgStop( "El usuario no existe" )

   end if

Return ( .f. )

//---------------------------------------------------------------------------//

STATIC FUNCTION lTctInitCheck( lDir, oMessage, oProgress )

   local oError
   local oBlock
   local lCheck   := .t.

   DEFAULT lDir   := .f.

   CursorWait()

   oMsgText( 'Comprobando directorios' )

   oBlock         := ErrorBlock( {| oError | ApoloBreak( oError ) } )
   BEGIN SEQUENCE

      lDemoMode( .f. )

      // Comprobamos que exista los directorios necesarios------------------------

      appCheckDirectory()

      // Borrar los ficheros de los directorios temporales------------------------

      oMsgText( 'Borrando ficheros temporales' )

      EraseFilesInDirectory( cPatTmp(), "*.*" )

      // Cargamos los datos de la empresa-----------------------------------------

      oMsgText( 'Control de tablas de empresa' )

      TstEmpresa()

      // Chequea los cambios de las bases de datos--------------------------------

      oMsgText( 'Control de actualizaciones' )

      ChkAllEmp()

      // Apertura de ficheros-----------------------------------------------------

      SetEmpresa()

      // Inicializamos classes----------------------------------------------------

      oMsgText( 'Inicializamos las clases de la aplicaci�n' )

      InitClasses()

      // Comprobamos q exista al menos un almacen---------------------------------

      oMsgText( 'Control de tablas de almac�n' )

      IsAlmacen()

      // Comprobamos q exista al menos una forma de pago--------------------------

      oMsgText( 'Control de formas de pagos' )

      IsFPago()

      // Chequea q exista los contadores------------------------------------------

      oMsgText( 'Control de contadores' )

      mkCount( cPatEmp() )

      oMsgText()

      // Opciones de inicio-------------------------------------------------------

      CursorWe()

   RECOVER USING oError

      msgStop( ErrorMessage( oError ), 'Imposible realizar comprobaciones iniciales' )

      lCheck   := .f.

   END SEQUENCE
   ErrorBlock( oBlock )

RETURN ( lCheck )

//---------------------------------------------------------------------------//

function lCheckSaasMode()

   local oCon
   local oQuery
   local oQuery2
   local nIdClient
   local nDaySaas          := nDaySaas()
   local lCheck            := .f.

   oCon                    := TMSConnect():New()

   if oCon:Connect( "gestool.serveftp.com", "root", "nidorino", "gestool_saas", "3306" )

      oQuery               := TMSQuery():New( oCon, "SELECT * FROM numerosserie WHERE serial='" + AllTrim( Str( Abs( nSerialHD() ) ) ) + "'" )

      if oQuery:Open() 

         // Existe el registro en la base de datos-----------------------------

         if oQuery:RecCount() > 0

            // El numero de serie no esta activo-------------------------------

            if oQuery:FieldGetByName( "activo" ) != 0

               nIdClient      := oQuery:FieldGetByName( "id_client" )

               oQuery2        := TMSQuery():New( oCon, "SELECT * FROM clientes WHERE id='" + AllTrim( Str( nIdClient ) ) + "' AND activo" )

               if oQuery2:Open() .and. oQuery2:RecCount() > 0

                  lCheck      := .t.

                  cTypeVersion( "[Saas]")

                  DeleteDaySaas()

               else 

                  // Cliente esta bloqueado------------------------------------

                  if nDaySaas > 0
                     
                     lCheck   := .t.

                     cTypeVersion( "[Saas dias: " + Alltrim( Str( nDaySaas ) ) +" ]")
                     
                     msgStop( "Le quedan " + Alltrim( Str( nDaySaas ) ) + " dias para activar su licencia", "Cliente inactivo." )

                  else 

                     cTypeVersion( "[Demo finalizaci�n licencia]" )

                     // msgStop( "Periodo de gracia expirado, el programa pasara a modo demo", "�Atenci�n!")

                  end if 

               end if   

            else

               // Numero de serie no esta activo ver numeros de gracia---------------


               if nDaySaas > 0
                  
                  lCheck      := .t.

                  cTypeVersion( "[Saas dias: " + Alltrim( Str( nDaySaas ) ) +" ]")
                  
                  msgStop( "Le quedan " + Alltrim( Str( nDaySaas ) ) + " dias para activar su licencia", "Licencia inactiva." )

               else 

                  cTypeVersion( "[Demo finalizaci�n licencia]" )

                  // msgStop( "Periodo de gracia expirado, el programa pasara a modo demo", "�Atenci�n!")

               end if 

            end if 

         end if

      end if

      oCon:Destroy()

   end if

Return ( lCheck )

//---------------------------------------------------------------------------//

Static Function SetFidelity( oBtnFidelity )

   local lFidelity            := !uFieldEmpresa( "lFidelity" )

   SetFieldEmpresa( lFidelity, "lFidelity" )

   if !Empty( oBtnFidelity )
      oBtnFidelity:lSelected  := lFidelity
      if lFidelity
         oBtnFidelity:cCaption( "Fidelity activado" )
      else
         oBtnFidelity:cCaption( "Fidelity desactivado" )
      end if
   end if

Return ( lFidelity )

//--------------------------------------------------------------------------//   

Static Function nDaySaas()

   local cRef  := "SOFTWARE\" + HB_Crypt( "Gestool", SERIALNUMBER )
   local oReg  := TReg32():Create( HKEY_LOCAL_MACHINE, cRef )
   local uVar  := oReg:Get( "Date", Date() )

   if Empty( uVar ) 
      oReg:Set( "Date", Date() )
   end if

   oReg:Close()

   if Empty( uVar )
      uVar  := Date()
   end if 
      
Return ( uVar + __DAYS__ - Date() )

//---------------------------------------------------------------------------//

Static Function DeleteDaySaas()

   local oReg
   local cRef

   cRef     := "SOFTWARE\" + HB_Crypt( "Gestool", SERIALNUMBER )
   oReg     := TReg32():Create( HKEY_LOCAL_MACHINE )
   oReg:Delete( cRef )
   oReg:Close()

Return ( nil )
 
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//

Function MainTablet()

	local oDlg
   local nRow           
   local oGridTree
   local cAgente        := GetPvProfString( "Tablet", "Agente", "", cIniAplication() )

   nRow                 := 0
   oDlg                 := TDialog():New( 1, 5, 40, 100, "GESTOOL TABLET",,, .f., nOR( DS_MODALFRAME, WS_POPUP, WS_CAPTION, WS_SYSMENU, WS_MINIMIZEBOX, WS_MAXIMIZEBOX ),, rgb( 255, 255, 255 ),,, .F.,, oGridFont(),,,, .f.,, "oDlg" )  

	/*
	Cabeceras------------------------------------------------------------------
   */

   TGridSay():Build(    { 	"nRow"      => nRow,;
                     		"nCol"      => {|| GridWidth( 0.5, oDlg ) },;
                     		"bText"     => {|| "Gestool tablet" },;
                     		"oWnd"      => oDlg,;
                     		"oFont"     => oGridFontBold(),;
                     		"lPixels"   => .t.,;
                     		"nClrText"  => Rgb( 0, 0, 0 ),;
                     		"nClrBack"  => Rgb( 255, 255, 255 ),;
                     		"nWidth"    => {|| GridWidth( 5, oDlg ) },;
                     		"nHeight"   => {|| GridRow() },;
                     		"lDesign"   => .f. } )

   TGridImage():Build(  {  "nTop"      => 4,;
                           "nLeft"     => {|| GridWidth( 11.5, oDlg ) - 138 },;
                           "nWidth"    => 138,;
                           "nHeight"   => 64,;
                           "cResName"  => "Gestool",;
                           "oWnd"      => oDlg } )

   //----------------Clientes

   TGridImage():Build(  {  "nTop"      => {|| GridRow( 3 ) },;
                           "nLeft"     => {|| GridWidth( 0.5, oDlg ) },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "gc_user_64",;
                           "bLClicked" => {|| Customer():New():runNavigatorCustomer() },;
                           "oWnd"      => oDlg } )

   TGridUrllink():Build({  "nTop"      => {|| GridRow( 3 ) },;
                           "nLeft"     => {|| GridWidth( 1.5, oDlg ) },;
                           "cURL"      => "Clientes",;
                           "oWnd"      => oDlg,;
                           "oFont"     => oGridFont(),;
                           "lPixel"    => .t.,;
                           "nClrInit"  => nGridColor(),;
                           "nClrOver"  => nGridColor(),;
                           "nClrVisit" => nGridColor(),;
                           "bAction"   => {|| Customer():New():runNavigatorCustomer() } } )

   //----------------Salir

   TGridImage():Build(  {  "nTop"      => {|| GridRow( 3 ) },;
                           "nLeft"     => {|| GridWidth( 11.5, oDlg ) - 64 },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "gc_door_open_64",;
                           "bLClicked" => {|| oDlg:End() },;
                           "oWnd"      => oDlg } )
   
   //----------------Pedidos de clientes

   TGridImage():Build(  {  "nTop"      => {|| GridRow( 6 ) },;
                           "nLeft"     => {|| GridWidth( 0.5, oDlg ) },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "gc_clipboard_empty_user_64",;
                           "bLClicked" => {|| OrderCustomer():New():Play() },;
                           "oWnd"      => oDlg } )

   TGridUrllink():Build({  "nTop"      => {|| GridRow( 6 ) },;
                           "nLeft"     => {|| GridWidth( 1.5, oDlg ) },;
                           "cURL"      => getConfigTraslation("Pedidos de clientes"),;
                           "oWnd"      => oDlg,;
                           "oFont"     => oGridFont(),;
                           "lPixel"    => .t.,;
                           "nClrInit"  => nGridColor(),;
                           "nClrOver"  => nGridColor(),;
                           "nClrVisit" => nGridColor(),;
                           "bAction"   => {|| OrderCustomer():New():Play() } } )

   //----------------Resumen diario

   if AccessCode():lSalesView

   TGridImage():Build(  {  "nTop"      => {|| GridRow( 6 ) },;
                           "nLeft"     => {|| GridWidth( 11.5, oDlg ) - 64 },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "gc_speech_balloon_answer_64",;
                           "bLClicked" => {|| DailySummarySales():New():Play() },;
                           "oWnd"      => oDlg } )

   end if 

   /*
   GALER�A DE INFORMES*********************************************************
   */

   TGridImage():Build(  {  "nTop"      => {|| GridRow( 9 ) },;
                           "nLeft"     => {|| GridWidth( 11.5, oDlg ) - 64 },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "gc_cabinet_open_64",;
                           "bLClicked" => {|| Reporting():New():Resource() },;
                           "oWnd"      => oDlg } )

   //----------------Albaranes de clientes
   
   TGridImage():Build(  {  "nTop"      => {|| GridRow( 9 ) },;
                           "nLeft"     => {|| GridWidth( 0.5, oDlg ) },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "gc_document_empty_user_64",;
                           "bLClicked" => {|| DeliveryNoteCustomer():New():Play() },;
                           "oWnd"      => oDlg } )

   TGridUrllink():Build({  "nTop"      => {|| GridRow( 9 ) },;
                           "nLeft"     => {|| GridWidth( 1.5, oDlg ) },;
                           "cURL"      => "Albaranes de clientes",;
                           "oWnd"      => oDlg,;
                           "oFont"     => oGridFont(),;
                           "lPixel"    => .t.,;
                           "nClrInit"  => nGridColor(),;
                           "nClrOver"  => nGridColor(),;
                           "nClrVisit" => nGridColor(),;
                           "bAction"   => {|| DeliveryNoteCustomer():New():Play() } } )

   /*
   Copias de Seguridad*********************************************************
   */

   TGridImage():Build(  {  "nTop"      => {|| GridRow( 12 ) },;
                           "nLeft"     => {|| GridWidth( 11.5, oDlg ) - 64 },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "gc_shield_64",;
                           "bLClicked" => {|| BackupPresenter():New():Play() },;
                           "oWnd"      => oDlg } )


   //----------------Facturas
   
   TGridImage():Build(  {  "nTop"      => {|| GridRow( 12 ) },;
                     		"nLeft"     => {|| GridWidth( 0.5, oDlg ) },;
                     		"nWidth"    => 64,;
                     		"nHeight"   => 64,;
                     		"cResName"  => "gc_document_text_user_64",;
                     		"bLClicked" => {|| InvoiceCustomer():New():play() },;
                     		"oWnd"      => oDlg } )

   TGridUrllink():Build({  "nTop"      => {|| GridRow( 12 ) },;
                           "nLeft"     => {|| GridWidth( 1.5, oDlg ) },;
                           "cURL"      => "Facturas de clientes",;
                           "oWnd"      => oDlg,;
                           "oFont"     => oGridFont(),;
                           "lPixel"    => .t.,;
                           "nClrInit"  => nGridColor(),;
                           "nClrOver"  => nGridColor(),;
                           "nClrVisit" => nGridColor(),;
                           "bAction"   => {|| InvoiceCustomer():New():play() } } )

   //----------------Recibos---------------------------------------------------
   
   TGridImage():Build(  {  "nTop"      => {|| GridRow( 15 ) },;
                           "nLeft"     => {|| GridWidth( 0.5, oDlg ) },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "gc_briefcase2_user_64",;
                           "bLClicked" => {|| ReceiptInvoiceCustomer():New():play() },;
                           "oWnd"      => oDlg } )

   TGridUrllink():Build({  "nTop"      => {|| GridRow( 15 ) },;
                           "nLeft"     => {|| GridWidth( 1.5, oDlg ) },;
                           "cURL"      => "Recibos de clientes",;
                           "oWnd"      => oDlg,;
                           "oFont"     => oGridFont(),;
                           "lPixel"    => .t.,;
                           "nClrInit"  => nGridColor(),;
                           "nClrOver"  => nGridColor(),;
                           "nClrVisit" => nGridColor(),;
                           "bAction"   => {|| ReceiptInvoiceCustomer():New():play() } } )

   //----------------Envio y recepcion

   TGridImage():Build(  {  "nTop"      => {|| GridRow( 18 ) },;
                           "nLeft"     => {|| GridWidth( 0.5, oDlg ) },;
                           "nWidth"    => 64,;
                           "nHeight"   => 64,;
                           "cResName"  => "gc_satellite_dish_64",;
                           "bLClicked" => {|| TSndRecInf():New():ActivateTablet() },;
                           "oWnd"      => oDlg } )

   TGridUrllink():Build({  "nTop"      => {|| GridRow( 18 ) },;
                           "nLeft"     => {|| GridWidth( 1.5, oDlg ) },;
                           "cURL"      => "Env�o y recepci�n",;
                           "oWnd"      => oDlg,;
                           "oFont"     => oGridFont(),;
                           "lPixel"    => .t.,;
                           "nClrInit"  => nGridColor(),;
                           "nClrOver"  => nGridColor(),;
                           "nClrVisit" => nGridColor(),;
                           "bAction"   => {|| TSndRecInf():New():ActivateTablet() } } )

   //----------------Informacion empresa

   oGridTree   := TGridTreeView():Build( ;
                        {  "nTop"      => {|| GridRow( 10 ) },;
                           "nLeft"     => {|| GridWidth( 0.5, oDlg ) },;
                           "oWnd"      => oDlg,;
                           "lPixel"    => .t.,;
                           "nWidth"    => {|| GridWidth( 17, oDlg ) },;
                           "nHeight"   => {|| GridRow( 21, oDlg ) } } )

	// Redimensionamos y activamos el di�logo----------------------------------- 

   oDlg:bResized       := {|| GridResize( oDlg ) }
   oDlg:bStart         := {|| oGridTree:Add( "Empresa : "      + uFieldEmpresa( "CodEmp" ) + "-" + uFieldEmpresa( "cNombre" ) ),;
                              oGridTree:Add( "Usuario : "      + Rtrim( oUser():cNombre() ) ),;
                              oGridTree:Add( "Delegaci�n : "   + Rtrim( oUser():cDelegacion() ) ),;
                              oGridTree:Add( "Caja : "         + oUser():cCaja() ),;
                              oGridTree:Add( "Almac�n : "      + Rtrim( oUser():cAlmacen() ) + "-" + RetAlmacen( oUser():cAlmacen() ) ),;
                              oGridTree:Add( "Agente : "       + Rtrim( cAgente ) + "-" + AllTrim( RetNbrAge( cAgente ) ) ),;
                              oGridTree:Add( "Sesi�n : "       + Alltrim( Transform( cCurSesion(), "######" ) ) ) } 

	ACTIVATE DIALOG oDlg CENTER ON INIT ( GridMaximize( oDlg ) )

RETURN ( .t. )

//---------------------------------------------------------------------------//

Function nextRow( nRow )

   nRow := nRow + 3

Return ( by( nRow ) )

//---------------------------------------------------------------------------//

Function mainTest()

   local i
   local e
   local oDb
   local cDb
   local oCur
   local oStmt
   local cTabla      := "test"
   local cSql        := "SELECT * FROM " + cTabla + ";"
   local cIns        := "INSERT INTO " + cTabla + ;
                           " ( first, last, street, city, state, zip, hiredate, married, age, salary, notes ) "  + ;
                           "VALUES ( 'Manu', 'Exposito', 'Pico de Almanzor, 35', 'Avila', 'ES', 41700, 20161231, 0, 52, 40456.89, 'Esta es una nota cualquiera' );"
   local cCreaTabla  := "CREATE TABLE " + cTabla  + " ( " + ;
                           "idreg INTEGER PRIMARY KEY,"    + ;
                           "first       VARCHAR( 20 ),"     + ;
                           "last        VARCHAR( 20 ),"     + ;
                           "street      VARCHAR( 30 ),"     + ;
                           "city        VARCHAR( 30 ),"     + ;
                           "state       VARCHAR( 2 ),"      + ;
                           "zip         VARCHAR( 20 ),"     + ;
                           "hiredate    DATE,"             + ;
                           "married     BOOLEAN,"          + ;
                           "age         INTEGER,"          + ;
                           "salary      DECIMAL( 9, 2 ),"   + ;
                           "notes       VARCHAR( 70 ) );"

   oDb   := THDO():new( "sqlite" )
   
   cDb   := "demo.db"

   if file( cDb )
      msgalert( "El archivo: " + cDb + " ya existe" )
   else
      msgalert( "El archivo: " + cDb + " no existe" )
   endif

   if oDb:connect( cDb )
      msgalert( cDb + " abierta" )
      try
         oDb:exec( cCreaTabla )
         msgalert( "La tabla " + cTabla + " se ha creado correctamente" )
      catch
         msgalert( "Error al crear la tabla " + cTabla )
         msgstop( oDb:errorInfo() )
      end

      try
         msgalert( if( oDb:inTransaction(), "Esta ", "No esta " ) + "en una trasaccion" )
         
         oDb:beginTransaction()

            msgalert( "Ahora " + if( oDb:inTransaction(), "esta ", "no esta " ) + "en una trasaccion" )
         
            i := oDb:exec( cIns )

         oDb:commit()
         
         msgalert( hb_ntos( i ) + " - " + hb_ntos( oDb:lastInsertId() ), "Columnas afectadas y lastInsertId" )

      catch
         msgalert( e:SubSystem + ";" + padl( e:SubCode, 4 ) + ";" + ;
               e:Operation + ";" + e:Description, "Error desde Harbour" )
         msgalert( oDb:errorInfo(), "Datos del error" )
         oDb:rollBack()
      end

      oStmt := oDb:prepare( cSql )
      oStmt:execute()
         
      oCur  := THashCursor():new( oStmt:fetchAll( FETCH_HASH ) )

      oStmt:free()
      
      oCur:free()

      msgalert( hb_valtoexp( oStmt ) )

   endif

   if oDb:disconnect()
      msgalert( cDb + " cerrada" )
   endif

Return ( nil )

//---------------------------------------------------------------------------//




