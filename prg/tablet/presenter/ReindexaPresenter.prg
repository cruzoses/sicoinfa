#include "FiveWin.Ch"
#include "Factu.ch"

CLASS ReindexaPresenter FROM DocumentsSales

   DATA oReindexaView

   METHOD New()

   METHOD runNavigator()

   METHOD onPreRunNavigator()    INLINE ( .t. )

   METHOD play()

   METHOD runReindexa()

END CLASS

//---------------------------------------------------------------------------//

METHOD New() CLASS ReindexaPresenter

   ::oReindexaView    := ReindexaView():New( self )
   ::oReindexaView:setTitleDocumento( "Regeneraci�n de indices" )

Return( self )

//---------------------------------------------------------------------------//

METHOD runNavigator() CLASS ReindexaPresenter

   if !empty( ::oReindexaView )
      ::oReindexaView:Resource()
   end if

Return( self )

//---------------------------------------------------------------------------//

METHOD play() CLASS ReindexaPresenter

   if ::onPreRunNavigator()
      ::runNavigator()
   end if 

return ( self )

//---------------------------------------------------------------------------//

METHOD runReindexa() CLASS ReindexaPresenter
 
   local oClassReindexa

   if nUsrInUse() > 1
      ApoloMsgStop( "Hay m�s de un usuario conectado a la aplicaci�n", "Atenci�n" )
      return nil
   end if

   if !TReindex():lCreateHandle()
      ApoloMsgStop( "Esta opci�n ya ha sido inicada por otro usuario", "Atenci�n" )
      return nil
   end if

   oClassReindexa                      := TDataCenter()

   if !Empty( oClassReindexa )

      oClassReindexa:aLgcIndices[ 1 ]  := .t.
      oClassReindexa:aLgcIndices[ 2 ]  := .t.
      oClassReindexa:aLgcIndices[ 3 ]  := .t.

      oClassReindexa:aProgress[ 1 ]    := ::oReindexaView:oMeterSistema
      oClassReindexa:aProgress[ 2 ]    := ::oReindexaView:oMeterEmpresa
      oClassReindexa:aProgress[ 3 ]    := ::oReindexaView:oMeterSincronizacion
      oClassReindexa:nProgress[ 1 ]    := ::oReindexaView:nMeterSistema
      oClassReindexa:nProgress[ 2 ]    := ::oReindexaView:nMeterEmpresa
      oClassReindexa:nProgress[ 3 ]    := ::oReindexaView:nMeterSincronizacion

      oClassReindexa:oMsg              := ::oReindexaView:oSayInformacion

      oClassReindexa:BuildData()
      oClassReindexa:BuildEmpresa()
      oClassReindexa:Reindex()
      
      oClassReindexa:Syncronize()

      ApoloMsgStop( "Proceso finalizado con �xito." )

   end if

Return ( self )

//---------------------------------------------------------------------------//