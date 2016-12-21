#include "FiveWin.Ch"
#include "Factu.ch"
#include "Xbrowse.ch"

CLASS DeliveryNoteCustomer FROM DocumentsSales  

   METHOD New()
   METHOD Build()

   METHOD getAppendDocumento()
   METHOD getEditDocumento()

   METHOD getLinesDocument( id )
   METHOD getDocumentLine()

   METHOD getLines()                   INLINE ( ::oDocumentLines:getLines() )
   METHOD getLineDetail()              INLINE ( ::oDocumentLines:getLineDetail( ::nPosDetail ) )

   METHOD getAppendDetail()
   METHOD deleteLinesDocument()

   METHOD printDocument()

END CLASS

//---------------------------------------------------------------------------//

METHOD New() CLASS DeliveryNoteCustomer

   ::super:New( self )

   ::hTextDocuments                    := {  "textMain"     => "Albaranes de clientes",;
                                             "textShort"    => "Albar�n",;
                                             "textTitle"    => "lineas de albaranes",;
                                             "textSummary"  => "Resumen albar�n",;
                                             "textGrid"     => "Grid albar�n clientes" }

  // Vistas--------------------------------------------------------------------

   ::oViewSearchNavigator:setTitleDocumento( "Albaranes de clientes" )  

   ::oViewEdit:setTitleDocumento( "Albar�n" )  

   ::oViewEditResumen:setTitleDocumento( "Resumen albar�n" )

   // Tipos--------------------------------------------------------------------

   ::setTypePrintDocuments( "AC" )

   ::setCounterDocuments( "nAlbCli" )

   // Areas--------------------------------------------------------------------

   ::setDataTable( "AlbCliT" )
   ::setDataTableLine( "AlbCliL" )

Return ( self )

//---------------------------------------------------------------------------//

METHOD Build() CLASS DeliveryNoteCustomer

   ::super:Build( self )

Return ( self )

//---------------------------------------------------------------------------//

METHOD GetAppendDocumento() CLASS DeliveryNoteCustomer

   ::hDictionaryMaster      := D():GetDefaultHashAlbaranCliente( ::nView )

Return ( self )

//---------------------------------------------------------------------------//

METHOD getEditDocumento() CLASS DeliveryNoteCustomer

   local id                := D():AlbaranesClientesId( ::nView )

   if empty( id )
      Return .f.
   end if  

   ::hDictionaryMaster     := D():getHashAlbaranCliente( ::nView )

   if empty( ::hDictionaryMaster )
      Return .f.
   end if 

   ::getLinesDocument( id )

Return ( .t. )

//---------------------------------------------------------------------------//
//
// Convierte las lineas del albaran en objetos
//

METHOD getLinesDocument( id ) CLASS DeliveryNoteCustomer

   ::oDocumentLines:reset()

   D():getStatusAlbaranesClientesLineas( ::nView )

   ( D():AlbaranesClientesLineas( ::nView ) )->( ordSetFocus( 1 ) )

   if ( D():AlbaranesClientesLineas( ::nView ) )->( dbSeek( id ) )  

      while ( D():AlbaranesClientesLineasId( ::nView ) == id ) .and. !( D():AlbaranesClientesLineas( ::nView ) )->( eof() ) 

         ::addDocumentLine()
      
         ( D():AlbaranesClientesLineas( ::nView ) )->( dbSkip() ) 
      
      end while

   end if 
   
   D():setStatusAlbaranesClientesLineas( ::nView ) 

RETURN ( self ) 

//---------------------------------------------------------------------------//

METHOD getDocumentLine() CLASS DeliveryNoteCustomer

   local hLine    := D():GetAlbaranClienteLineasHash( ::nView )

   if empty( hLine )
      Return ( nil )
   end if 

Return ( DictionaryDocumentLine():New( self, hLine ) )

//---------------------------------------------------------------------------//

METHOD GetAppendDetail() CLASS DeliveryNoteCustomer

   local hLine             := D():getAlbaranClienteLineaDefaultValues( ::nView )
   
   ::oDocumentLineTemporal := DictionaryDocumentLine():New( self, hLine )

Return ( self )

//---------------------------------------------------------------------------//

METHOD deleteLinesDocument() CLASS DeliveryNoteCustomer

   D():getStatusAlbaranesClientesLineas( ::nView )

   ( D():AlbaranesClientesLineas( ::nView ) )->( ordSetFocus( 1 ) )

   while ( D():AlbaranesClientesLineas( ::nView ) )->( dbSeek( ::getID() ) ) 
      ::delDocumentLine()
   end while

   D():setStatusAlbaranesClientesLineas( ::nView ) 

Return ( Self )

//---------------------------------------------------------------------------//

METHOD printDocument() CLASS DeliveryNoteCustomer

   imprimeAlbaranCliente( ::getID(), ::cFormatToPrint )

Return ( .t. )

//---------------------------------------------------------------------------//