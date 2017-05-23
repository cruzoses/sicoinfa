#include "fivewin.ch"
#include "factu.ch" 
#include "hdo.ch"

//---------------------------------------------------------------------------//

CLASS TiposVentasModel FROM SQLBaseModel

   DATA     cTableName               INIT "tipos_ventas"

   DATA     cDbfTableName

   DATA     hColumns

   METHOD   New()

   METHOD   arrayTiposVentas()

   METHOD   arrayNombres()

END CLASS

//---------------------------------------------------------------------------//

METHOD New()

   ::cTitle                      := "Tipos ventas"

   ::cDbfTableName				 	:= "TVTA"

   ::hColumns                   	:= {  "id"        => {  "create"    => "INTEGER PRIMARY KEY AUTOINCREMENT"    ,;
                                                         "text"		=> "Identificador"                        ,;
   															         "dbfField" 	=> ""}                                    ,;
                                       "codigo"    => {  "create"    => "VARCHAR( 2 )"                         ,;
                                                         "text"      => "C�digo de identificaci�n en DBF"      ,; 
                                                         "dbfField"  => "CCODMOV"}                             ,;
                                       "nombre"    => {  "create"    => "VARCHAR( 20 ) NOT NULL"               ,;
   															         "text"		=> "Descripci�n del movimiento"           ,;
   															         "dbfField" 	=> "CDESMOV"}                             }

   ::Super:New()

RETURN ( Self )

//---------------------------------------------------------------------------//

METHOD arrayNombres()

   local cSentence               := "SELECT nombre FROM " + ::cTableName
   local aResult                 := ::selectFetchArray( cSentence ) 

RETURN ( aResult )

//---------------------------------------------------------------------------//

METHOD arrayTiposVentas()

   local cSentence               := "SELECT id, codigo FROM " + ::cTableName
   local aResult                 := ::selectFetchHash( cSentence ) 

RETURN ( aResult )

//---------------------------------------------------------------------------//

