#include "FiveWin.Ch"
#include "Factu.ch" 

//---------------------------------------------------------------------------//

CLASS TGenMailingDatabaseAlbaranesClientes FROM TGenMailingDatabase 

   METHOD New( nView )

   METHOD columnPageDatabase( oDlg )   VIRTUAL

   METHOD getAdjunto()                 INLINE ( mailReportAlbCli( ::cFormatoDocumento ) )

END CLASS

//---------------------------------------------------------------------------//

METHOD New( nView ) CLASS TGenMailingDatabaseAlbaranesClientes

   ::Create()

   ::Super:New( nView )

   ::setItems( aItmAlbCli() )

   ::setWorkArea( D():AlbaranesClientes( nView ) )

   ::setTypeDocument( "nAlbCli" )

   ::setTypeFormat( "AC" )

   ::setFormatoDocumento( cFirstDoc( "AC", D():Documentos( nView ) ) )

   ::setBmpDatabase( "albaran_cliente_48_alpha" )

   ::setAsunto( "Envio de nuestro albar�n de cliente {Serie del albar�n}/{N�mero del albar�n}" )

   ::setBlockRecipients( {|| alltrim( retFld( ( D():AlbaranesClientes( ::nView ) )->cCodCli, D():Clientes( ::nView ), "cMeiInt" ) ) } )

Return ( Self )

//---------------------------------------------------------------------------//
