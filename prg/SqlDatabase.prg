#include "fiveWin.ch"
#include "hdo.ch"

//----------------------------------------------------------------------------//

static oSqlDatabase

//----------------------------------------------------------------------------//

CLASS SQLDatabase

   DATA oConexion

   DATA cDatabaseSQLite    

   DATA cPathDatabaseSQLite    

   DATA aModels

   METHOD New()                    CONSTRUCTOR

   METHOD Conexion()               INLINE  ( ::oConexion )

   METHOD Connect() 
   METHOD Disconnect()             INLINE  ( ::oConexion:disconnect() )
        
   METHOD Exec( cSql )             
   METHOD Query( cSql )            INLINE ( ::oConexion:Query( cSql ) )
   METHOD Prepare( cSql )          INLINE ( ::oConexion:Prepare( cSql ) )

   METHOD LastInsertId()           INLINE ( ::oConexion:LASTINSERTID() )

   METHOD errorInfo()              INLINE ( ::oConexion:errorInfo() )

   METHOD checkModelsExistence()   

ENDCLASS

//----------------------------------------------------------------------------//

METHOD New() 

   ::aModels                  := {  TiposImpresorasModel():New():getSQLCreateTable(),     ;
                                    TiposNotasModel():New():getSQLCreateTable(),          ;
                                    TiposIncidenciasModel():New():getSQLCreateTable(),    ;
                                    EtiquetasModel():New():getSQLCreateTable(),           ;
                                    SituacionesModel():New():getSQLCreateTable(),         ;
                                    HistoricosUsuariosModel():New():getSQLCreateTable(),  ;
                                    RelacionesEtiquetasModel():New():getSQLCreateTable(), ;
                                    TiposVentasModel():New():getSQLCreateTable()          }

   ::cPathDatabaseSQLite      := fullCurDir() + "Database\" 

   ::cDatabaseSQLite          := ::cPathDatabaseSQLite + "Gestool.db"

   ::oConexion                := THDO():new( "sqlite" )

Return ( Self )

//----------------------------------------------------------------------------//

METHOD Connect()

   if !lIsDir( ::cPathDatabaseSQLite )
      makedir( ::cPathDatabaseSQLite )
   end if 
    
Return ( ::oConexion:Connect( ::cDatabaseSQLite ) )

//----------------------------------------------------------------------------//

METHOD Exec( cSql )

   local lExec    := .t.

   try
      ::oConexion:Exec( cSql )
   catch
      lExec       := .f.
   end

Return ( lExec )

//----------------------------------------------------------------------------//

METHOD checkModelsExistence()
    
Return ( aeval( ::aModels, { |cModel| ::Exec( cModel ) } ) )

//----------------------------------------------------------------------------//

Function getSQLDatabase()

   if empty( oSqlDatabase )
      oSqlDatabase            := SQLDatabase():New()
   end if

Return ( oSqlDatabase )

//----------------------------------------------------------------------------//
