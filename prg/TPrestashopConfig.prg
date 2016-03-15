#include "FiveWin.Ch" 
#include "Struct.ch"
#include "Factu.ch" 
#include "Ini.ch"
#include "MesDbf.ch" 

//---------------------------------------------------------------------------//

// debug( ::cHost, ::TPrestashopConfig:getMySqlServer() )
// debug( ::cUser, ::TPrestashopConfig:getMySqlUser() )
// debug( ::cPasswd, ::TPrestashopConfig:getMySqlPassword() )
// debug( ::cDbName, ::TPrestashopConfig:getMySqlDatabase() )
// debug( ::nPort, ::TPrestashopConfig:getMySqlPort() )

CLASS TPrestashopConfig

   CLASSDATA oInstance
   CLASSDATA hConfig                   INIT {=>}

   DATA idEmpresa
   DATA hShops                         INIT {=>}

   DATA hCurrentWeb
   
   METHOD New()                        CONSTRUCTOR
   METHOD getInstance()
   METHOD loadJSON() 

   METHOD getWebs()

   METHOD setCurrentWeb( hCurrentWeb ) INLINE ( ::hCurrentWeb := hCurrentWeb )
   METHOD getCurrentWeb( hCurrentWeb ) INLINE ( ::hCurrentWeb )
   
   METHOD getFromCurrentWeb( key )     INLINE ( if( hhaskey( ::getCurrentWeb(), key ), hget( ::getCurrentWeb(), key ), msgStop( key + "no presente en configuraci�n de web" ) ) )
   
   METHOD getActive()                  INLINE ( ::getFromCurrentWeb( "Active" ) )

   METHOD getMySqlServer()             INLINE ( ::getFromCurrentWeb( "MySqlServer" ) )
   METHOD getMySqlUser()               INLINE ( ::getFromCurrentWeb( "MySqlUser" ) )
   METHOD getMySqlPassword()           INLINE ( ::getFromCurrentWeb( "MySqlPassword") )
   METHOD getMySqlDatabase()           INLINE ( ::getFromCurrentWeb( "MySqlDatabase") )
   METHOD getMySqlPort()               INLINE ( ::getFromCurrentWeb( "MySqlPort") )

   METHOD getPrefixDatabase()          INLINE ( ::getFromCurrentWeb( "PrefixDatabase") )

   METHOD getFtpServer()               INLINE ( ::getFromCurrentWeb( "FtpServer") )
   METHOD getFtpUser()                 INLINE ( ::getFromCurrentWeb( "FtpUser") )
   METHOD getFtpPassword()             INLINE ( ::getFromCurrentWeb( "FtpPassword") )
   METHOD getFtpPassive()              INLINE ( ::getFromCurrentWeb( "FtpPassive") )
   METHOD getFtpPort()                 INLINE ( ::getFromCurrentWeb( "FtpPort") )

   METHOD getCookieKey()               INLINE ( ::getFromCurrentWeb( "CookieKey") )

   METHOD getStore()                   INLINE ( ::getFromCurrentWeb( "Store") )
   
   METHOD getOrderSerie()              INLINE ( ::getFromCurrentWeb( "OrderSerie") )
   METHOD getBudgetSerie()             INLINE ( ::getFromCurrentWeb( "BudgetSerie") )

   METHOD getImagesDirectory()         INLINE ( ::getValidDirectoryFtp( ::getFromCurrentWeb( "ImagesDirectory") ) )
   METHOD getValidDirectoryFtp( cDirectory )

   METHOD getRealTimeConexion()        INLINE ( if( hhaskey( ::hConfig, "RealTimeConexion" ), hget( ::hConfig, "RealTimeConexion" ), .f. ) )
   METHOD getHideExportButton()        INLINE ( if( hhaskey( ::hConfig, "HideExportButton" ), hget( ::hConfig, "HideExportButton" ), .f. ) )
   METHOD getHideHideExportButton()    INLINE ( if( hhaskey( ::hConfig, "HideExportButton" ), hget( ::hConfig, "HideExportButton" ), .f. ) )

   METHOD getFullFileName()            INLINE ( cPatConfig() + ::idEmpresa + "\prestashop.json" )

END CLASS

//---------------------------------------------------------------------------//

METHOD New( idEmpresa ) CLASS TPrestashopConfig

   DEFAULT idEmpresa    := cCodEmp()

   ::idEmpresa          := idEmpresa

Return ( Self )

//----------------------------------------------------------------//

METHOD GetInstance() CLASS TPrestashopConfig

   if empty( ::oInstance )
      ::oInstance       := ::New()
   end if

RETURN ( ::oInstance )

//---------------------------------------------------------------------------//

METHOD LoadJSON() CLASS TPrestashopConfig

   local cConfig
   local hConfig
   local cFileConfigEmpresa   := ::getFullFileName()

   if file( cFileConfigEmpresa )
      
      cConfig                 := memoread( cFileConfigEmpresa )
      hb_jsonDecode( cConfig, @hConfig )      

      if !empty( hConfig )
         ::hConfig            := hConfig
      end if 

   else 

      msgStop( "Fichero " + alltrim( cFileConfigEmpresa ) + " no encontrado.", "Stop" )   

   end if 

Return ( Self )

//----------------------------------------------------------------//

METHOD getWebs() CLASS TPrestashopConfig

   local hWebs    := {=>}

   if hhaskey( ::hConfig, "Webs" )
      hWebs       := hget( ::hConfig, "Webs" )
   end if 

Return ( hWebs )

//----------------------------------------------------------------//

METHOD getValidDirectoryFtp( cDirectory ) CLASS TPrestashopConfig

   local cResult

   /*
   Cambiamos todas las contrabarras por barras normales------------------------
   */

   cResult     := StrTran( alltrim( cDirectory ), "\", "/" )

   /*
   Si empieza por barra la quitamos--------------------------------------------
   */

   if Left( cResult, 1 ) == "/"
      cResult  := Substr( cResult, 2 )
   end if

   /*
   Si termina por barra la quitamos--------------------------------------------
   */

   if Right( cResult, 1 ) == "/"
      cResult  := Substr( cResult, 1, Len( cResult ) - 1 )
   end if

Return ( cResult )

//---------------------------------------------------------------------------//






   