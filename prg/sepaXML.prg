/* v.1.0 31/12/2013
 * SEPA ISO 20022 http://http://www.iso20022.org/
 * pain.008.001.02 Direct Debit Core y B2B 
 * pain.001.001.03 Credit Transfer 
 *
 * Para lenguaje Harbour - http://harbour-project.org
 * (c) Joaquim Ferrer Godoy <quim_ferrer@yahoo.es>
 *
 * Características :
 * Generacion de formato XML
 * Control de errores en campos requeridos
 * Verifica importes y numero total de efectos
 * 
 * Reglas de uso locales AEB:
 * (1) TRUE = Un apunte en cuenta por la suma de los importes de todas las operaciones del mensaje.
 *    FALSE= Un apunte en cuenta por cada una de las operaciones incluidas en el mensaje.
 * (2) FNAL=Último adeudo de una serie de adeudos recurrentes.
 *     FRST=Primer adeudo de una serie de adeudos recurrentes.
 *    OOFF=Adeudo correspondiente a una operación con un único pago(*).
 *    RCUR=Adeudo de una serie de adeudos recurrentes, cuando no se trata ni del primero ni del último.
 *    (*) Para este tipo de operaciones el mandato y su referencia deben ser únicos y no pueden utilizarse para operaciones 
 *    puntuales posteriores. Si siempre se factura a los mismos clientes, aunque varie el importe de los adeudos y la periodicidad
 *    de los mismos, es necesario utilizar el tipo de adeudo recurrente si se utiliza la misma referencia, creando para cada 
 *    cliente deudor un solo mandato que ampare todos los adeudos que se emitan. 
 *    El primer adeudo deberá ser FRST y los siguientes RCUR.
 * (3) Esta etiqueta sólo debe usarse cuando un mismo número de cuenta cubra diferentes divisas y el presentador 
 *       necesite identificar en cuál de estas divisas debe realizarse el asiento sobre su cuenta.
 * (4) Regla de uso: Solamente se admite el código ‘SLEV’
 * (5) La etiqueta ‘Cláusula de gastos’ puede aparecer, bien en el nodo ‘Información del pago’ (2.0), bien en el 
 *       nodo ‘Información de la operación de adeudo directo’ (2.28), pero solamente en uno de ellos. 
 *       Se recomienda que se recoja en el bloque ‘Información del pago’ (2.0).
 * (6) Regla de uso: Para el sistema de adeudos SEPA se utilizará exclusivamente la etiqueta 'Otra' estructurada 
 *    según lo definido en el epígrafe 'Identificador del presentador' de la sección 3.3 del cuaderno.
 * (7) Regla de uso: Solamente se admite el código 'SEPA'
 */

#include "hbclass.ch"
#include "hbmxml.ch"

#include "hbxml.ch"
#include "fileio.ch"

#define CRLF                  chr( 13 ) + chr( 10 )

#define SEPA_DIRECT_DEBIT     0
#define SEPA_CREDIT_TRANSFER  1

#define SEPA_SCHEME_CORE      0
#define SEPA_SCHEME_COR1      1
#define SEPA_SCHEME_B2B       2

#define ENTIDAD_JURIDICA      0
#define ENTIDAD_FISICA        1
#define ENTIDAD_OTRA          2

//--------------------------------------------------------------------------------------//

CLASS SepaXml

   DATA hXmlDoc

   DATA oXml
   DATA oXmlDocument
   DATA oXmlFinancial
   DATA oXmlHeader
   DATA oXmlPmtInf
   DATA oXmlPmtTpInf
   DATA oXmlSvcLvl
   DATA oXmlLclInstrm
   DATA oXmlCtgyPurp

   DATA FinancialMessage   AS CHARACTER   INIT "CstmrDrctDbtInitn" 
   DATA DocumentType       AS CHARACTER   INIT "pain.008.001.02" 

   DATA SchmeNm            AS CHARACTER   INIT "COR1"
   DATA cFileOut           
   DATA lMinified          AS LOGICAL     INIT .t.             // Documento compactado o con espacios y tabuladores
   DATA aErrors            AS ARRAY       INIT {}              // Control de errores
   DATA ErrorMessages      AS ARRAY       INIT {=>}            // Hash mensajes de error multilenguaje
   DATA aDebtors           AS ARRAY       INIT {}              // Lista de deudores

   DATA MsgId                                                  // Identificación del mensaje
   DATA CreDtTm                                                // Fecha y hora de creación
   DATA NbOfTxs            AS NUMERIC     INIT 0               // Número de operaciones 
   DATA CtrlSum            AS NUMERIC     INIT 0.00            // Control de suma

   DATA ServiceLevel       AS CHARACTER   INIT "SEPA"          // Código Nivel de servicio (7)
   DATA SeqTp              AS CHARACTER   INIT "RCUR"          // Tipo de secuencia (2)
   DATA PurposeCd                                              // Código categoria proposito
   DATA PurposePrtry                                           // Propietario categoria proposito

   DATA oInitPart
   DATA oCreditor
   DATA oUltimateCreditor
   DATA oDebtor
   DATA oUltimateDebtor
   DATA ReqdColltnDt

   DATA PmtInfId
   DATA PmtMtd             AS CHARACTER INIT "DD" READONLY     // Método de pago Regla de uso: Solamente se admite el código ‘DD’
   DATA BtchBookg          AS CHARACTER INIT "false"           // Indicador de apunte en cuenta (1)

   METHOD New()
   METHOD setFinancialMessage( nFinancialMessage )
   METHOD setScheme( nScheme )
   METHOD setRequestedCollectionDate( sDate )                     INLINE ( ::ReqdColltnDt := sDate )
   METHOD setPaymentInformationIdentification( informationId )    INLINE ( ::PmtInfId := informationId )
   METHOD setOriginalMessageIdentification( messageId )           INLINE ( ::MsgId := messageId )

   METHOD getRquiredPayDateXML()                                  INLINE ( TXmlParseNode():New( "ReqdColltnDt", ::ReqdColltnDt, 10 ) )

   METHOD CreateDocumentXML()
   METHOD CreateFinancialNode()                                   INLINE ( ::oXmlFinancial   := TXmlNode():new( , ::FinancialMessage ),;
                                                                           ::oXmlDocument:addBelow( ::oXmlFinancial ) )

   METHOD getInfoPaymentXML()
   METHOD getTypePaymentXML()

   METHOD CalculateOperationsNumber()   

   METHOD ProcessDebtors()
   METHOD SaveDocumentXML()

   METHOD DebtorAdd( oDebtor )                                    INLINE aadd( ::aDebtors, oDebtor )

   METHOD GroupHeader()
   METHOD InfoPayment()
   METHOD InitPart()

   METHOD SetLanguage()
   METHOD Activate()

   METHOD resetErrors()                         INLINE ( ::aErrors := {} )
   METHOD addError( cError )                    INLINE ( aadd( ::aErrors, cError ) )

ENDCLASS

//--------------------------------------------------------------------------------------//

METHOD New( cFileOut ) CLASS SepaXml

   ::cFileOut           := cFileOut
   ::CreDtTm            := IsoDateTime()  // Fecha y hora de creación

   ::oInitPart          := SepaDebitActor():New( Self, "InitgPty" )     
   ::oCreditor          := SepaDebitActor():New( Self )
   ::oUltimateCreditor  := SepaDebitActor():New( Self )
   ::oDebtor            := SepaDebitActor():New( Self )
   ::oUltimateDebtor    := SepaDebitActor():New( Self )

return Self

//--------------------------------------------------------------------------------------//

METHOD setFinancialMessage( nFinancialMessage ) CLASS SepaXml

   if nFinancialMessage == SEPA_DIRECT_DEBIT 
      ::FinancialMessage   := "CstmrDrctDbtInitn" 
      ::DocumentType       := "pain.008.001.02" 
   end if 

   if nFinancialMessage == SEPA_CREDIT_TRANSFER 
      ::FinancialMessage   := "CstmrCdtTrfInitn"  
      ::DocumentType       := "pain.001.001.03" 
   end if 

RETURN ( Self )

//------------------------------------------------------------------------//

METHOD setScheme( uScheme ) CLASS SepaXml

   if valtype( uScheme ) == "C"
      ::SchmeNm         := uScheme
      Return ( Self )
   end if 

   if valtype( uScheme ) == "N"
      switch uScheme
         case SEPA_SCHEME_CORE  
            ::SchmeNm   := "CORE" ; exit
         case SEPA_SCHEME_COR1  
            ::SchmeNm   := "COR1" ; exit
         case SEPA_SCHEME_B2B   
            ::SchmeNm   := "B2B"  ; exit
         otherwise              
            ::SchmeNm   := "SEPA"
      end
   end if 

RETURN ( Self )

//------------------------------------------------------------------------//

METHOD GroupHeader( hParent ) CLASS SepaXml

   local hItem
   local lError   := .f.

   if empty( ::MsgId )
      ::addError( "Identificación del mensaje no puede estar vacio." )
      lError      := .t.
   endif

   if empty( ::CreDtTm )
      ::addError( "Fecha y hora de creación no puede estar vacio." )
      lError      := .t.
   endif

   if empty( ::NbOfTxs )
      ::addError( "Número de operaciones no puede estar vacia." )
      lError      := .t.
   endif

   if empty( ::CtrlSum )
      ::addError( "Control de suma no puede estar vacio." )
      lError      := .t.
   endif

   if !lError

      ::oXmlHeader   := TXmlNode():new( , "GrpHdr" )
         ::oXmlHeader:addBelow( TXmlParseNode():New( "MsgId", ::MsgId, 35 ) )         
         ::oXmlHeader:addBelow( TXmlParseNode():New( "CreDtTm", ::CreDtTm, 19 ) )         
         ::oXmlHeader:addBelow( TXmlParseNode():New( "NbOfTxs", str( ::NbOfTxs, 0 ), 15 ) )         
         ::oXmlHeader:addBelow( TXmlParseNode():New( "CtrlSum", ::CtrlSum, 18 ) )         

      ::oXmlFinancial:addBelow( ::oXmlHeader )                                          

      ::oXmlHeader:addBelow( ::oInitPart:getNodeXML() )

   endif 

Return ( nil )

//--------------------------------------------------------------------------------------//

METHOD getInfoPaymentXML() CLASS SepaXml

   ::oXmlPmtInf      := TXmlNode():New( , "PmtInf" )
   ::oXmlPmtInf:addBelow( TXmlParseNode():New( "PmtInfId",  ::PmtInfId, 35 ) )
   ::oXmlPmtInf:addBelow( TXmlParseNode():New( "PmtMtd",    ::PmtMtd, 2 ) )
   ::oXmlPmtInf:addBelow( TXmlParseNode():New( "BtchBookg", ::BtchBookg, 5 ) )
   ::oXmlPmtInf:addBelow( TXmlParseNode():New( "NbOfTxs",   str( ::NbOfTxs, 0 ), 15 ) )
   ::oXmlPmtInf:addBelow( TXmlParseNode():New( "CtrlSum",   ::CtrlSum, 18 ) )

Return ( ::oXmlPmtInf )

//--------------------------------------------------------------------------------------//

METHOD SetLanguage() CLASS SepaXml

   ::ErrorMessages['SEPA_DEBTOR_AGENT']      := "La entidad del cliente no existe"
   ::ErrorMessages['SEPA_DEBTOR_NAME']       := "El nombre del deudor no existe"
   ::ErrorMessages['SEPA_DEBTOR_ACCOUNT']    := "La cuenta del deudor no existe"

return nil

//--------------------------------------------------------------------------------------//

METHOD Activate() CLASS SepaXml

   local hItem, oDebtor

   ::SetLanguage()

   ::ResetErrors()

   ::CalculateOperationsNumber()

   ::CreateDocumentXML()

   ::CreateFinancialNode()

   ::GroupHeader()                                               // Cabecera

   ::InfoPayment()

   ::ProcessDebtors()

   ::SaveDocumentXML()

return nil

//--------------------------------------------------------------------------------------//

METHOD CreateDocumentXML()

   ::oXml            := TXmlDocument():new( '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>' )

   ::oXmlDocument    := TXmlNode():new( , "Document", { "xmlns" => "urn:iso:std:iso:20022:tech:xsd:" + ::DocumentType } )
   ::oXml:oRoot:addBelow( ::oXmlDocument )   

return ( nil )

//--------------------------------------------------------------------------------------//

METHOD SaveDocumentXML()

   local fileHandle

   ferase( ::cFileOut )

   fileHandle       := fCreate( ::cFileOut )

   ::oXml:Write( fileHandle, HBXML_STYLE_NONEWLINE )

   fClose( fileHandle )

return nil

//--------------------------------------------------------------------------------------//
// Comprobar numero de operaciones y suma total de importes

METHOD CalculateOperationsNumber()

   local oDebtor

   for each oDebtor in ::aDebtors
      ::NbOfTxs         += 1
      ::CtrlSum         += oDebtor:InstdAmt
   next

return nil

//--------------------------------------------------------------------------------------//

METHOD InfoPayment()

   ::oXmlPmtInf         := ::getInfoPaymentXML()
   ::oXmlPmtInf:addBelow( ::getTypePaymentXML() )
   ::oXmlPmtInf:addBelow( ::getRquiredPayDateXML() ) 

   ::InitPart()

   ::oXmlFinancial:addBelow( ::oXmlPmtInf )   

return nil

//--------------------------------------------------------------------------------------//

METHOD InitPart()

   ::oXmlPmtInf:addBelow( ::oInitPart:getCreditorXML() ) 
   ::oXmlPmtInf:addBelow( ::oInitPart:getCreditorIBANXML() )
   ::oXmlPmtInf:addBelow( ::oInitPart:getCreditorBICXML() )
   ::oXmlPmtInf:addBelow( ::oInitPart:getChrgBrXML() )
   ::oXmlPmtInf:addBelow( ::oInitPart:getIdCreditorXML() )

return nil

//--------------------------------------------------------------------------------------//

/*
La informacion del pago puede incluir varios adeudos por fecha de cobro
Aqui se asume fecha de cobro distinta para cada adeudo, no realizando agrupacion.
*/

METHOD ProcessDebtors( hItem )

   local oDebtor

   for each oDebtor in ::aDebtors
      
      ::oDebtor            := oDebtor // __objClone( oDebtor )

      ::oXmlPmtInf:addBelow( ::oDebtor:getDirectDebitTransactionInformationXml() )

   next

return nil

//--------------------------------------------------------------------------------------//

METHOD getTypePaymentXML() 

   ::oXmlPmtTpInf       := TXmlNode():New( , "PmtTpInf")                         // Información del tipo de pago 

      ::oXmlSvcLvl      := TXmlNode():New( , "SvcLvl")                           // Nivel de servicio 
      if ::ServiceLevel != nil
         ::oXmlSvcLvl:addBelow( TXmlParseNode():New( "Cd", ::ServiceLevel, 4 ) )
      end if 

   ::oXmlPmtTpInf:addBelow( ::oXmlSvcLvl )

      ::oXmlLclInstrm   := TXmlNode():New( , "LclInstrm" )   
      if ::SchmeNm != nil                 // Instrumento local
         ::oXmlLclInstrm:addBelow( TXmlParseNode():New( "Cd", ::SchmeNm, 35 ) )  // Código Instrumento local
      end if 

   ::oXmlPmtTpInf:addBelow( ::oXmlLclInstrm )

   ::oXmlPmtTpInf:addBelow( TXmlParseNode():New( "SeqTp", ::SeqTp, 4 ) )        // Tipo de secuencia

   // Lista de códigos recogidos en la norma ISO 20022----------------------------------- 
   // Ex: CASH=CashManagementTransfer (Transaction is a general cash management instruction) 

   if ::PurposeCd != nil
   
      ::oXmlCtgyPurp    := TXmlNode():New( , "CtgyPurp" )                               // Categoría del propósito 
      if ::PurposeCd != nil
         ::oXmlCtgyPurp:addBelow( TXmlParseNode():New( "Cd", ::PurposeCd, 4 ) )         // Código 
      end if 
      ::oXmlCtgyPurp:addBelow( TXmlParseNode():New( "Prtry", ::PurposePrtry, 35 ) )     // Propietario

      ::oXmlPmtTpInf:addBelow( ::oXmlCtgyPurp )

   endif

Return ( ::oXmlPmtTpInf )

//--------------------------------------------------------------------------------------//

CLASS SepaDebitActor

   DATA oSender
   DATA cName

   DATA nEntity

   DATA Nm                                   // Nombre
   DATA Ctry                                    // Pais
   DATA AdrLine1                                // Dirección en texto libre
   DATA AdrLine2                                // Se permiten 2 etiquetas para direccion
   DATA IBAN                                    // IBAN
   DATA BIC                                  // BIC
   DATA BICOrBEI                                // BIC o BEI 
   DATA BirthDt                                 // Fecha de nacimiento 
   DATA PrvcOfBirth                             // Provincia de nacimiento
   DATA CityOfBirth                             // Ciudad de nacimiento 
   DATA CtryOfBirth                             // País de nacimiento
   DATA Id                                      // Identificación 
   DATA Issr                                    // Emisor 
   DATA Cd                                   // Codigo
   DATA Prtry           AS CHARACTER INIT "SEPA"  // Propietario

   DATA PmtInfId                                // Identificación de la información del pago 
   DATA BtchBookg       AS CHARACTER INIT "false"         // Indicador de apunte en cuenta (1)
   DATA ReqdColltnDt                               // Fecha de cobro (Vencimiento)
   DATA Ustrd                                    // Informacion no estructurada, p.e., concepto del cobro
   DATA NbOfTxs         AS NUMERIC INIT 0             // Número de operaciones 
   DATA CtrlSum         AS NUMERIC INIT 0.00             // Control de suma 
   DATA PmtMtd          AS CHARACTER INIT "DD"   READONLY   // Método de pago Regla de uso: Solamente se admite el código ‘DD’
   DATA ChrgBr          AS CHARACTER INIT "SLEV" READONLY   // Cláusula de gastos (4)
   DATA InstrId                                 // Identificación de la instrucción
   DATA EndToEndId                              // Identificación de extremo a extremo 
   DATA InstdAmt        AS NUMERIC INIT 0.00             // Importe ordenado 
   DATA MndtId                                     // Identificación del mandato 
   DATA DtOfSgntr                                  // Fecha de firma 
   DATA AmdmntInd       AS CHARACTER INIT "false"  // Indicador de modificación 
   DATA OrgnlMndtId                                // Identificación del mandato original 

   DATA oXmlActor
   DATA oXmlId
   DATA oXmlOrgId
   DATA oXmlOthr
   DATA oXmlSchmeNm
   DATA oXmlPrvId
   DATA oXmlDtAndPlcOfBirth
   DATA oXmlPmtInf
   DATA oXmlCdrt
   DATA oXmlPstlAdr
   DATA oXmlCdtrAcct
   DATA oXmlIdIBAN
   DATA oXmlCdtrAgt
   DATA oXmlFinInstnId
   DATA oXmlCdtrSchmeId
   DATA oXmlDrctDbtTxInf

   METHOD New()

   METHOD getNodeXML()
   METHOD getOtherNodeXML()
   METHOD getRquiredPayDateXML()    INLINE ( TXmlParseNode():New( "ReqdColltnDt", ::ReqdColltnDt, 10 ) )
   METHOD getCreditorXML()
   METHOD getCreditorIBANXML()
   METHOD getCreditorBICXML()
   METHOD getChrgBrXML()            INLINE ( TXmlParseNode():New( "ChrgBr", ::ChrgBr, 4 ) )
   METHOD getIdCreditorXML()
   METHOD getDirectDebitTransactionInformationXml()

ENDCLASS

//--------------------------------------------------------------------------------------//

METHOD New( oSender, cName ) CLASS SepaDebitActor

   ::oSender   := oSender
   ::cName     := cName

Return ( Self )

//--------------------------------------------------------------------------------------//

METHOD getNodeXML() CLASS SepaDebitActor

   ::oXmlActor       := TXmlNode():new( , ::cName ) 
   ::oXmlActor:addBelow( TXmlParseNode():New( "Nm", ::Nm, 70 ) )

   ::oXmlId          := TXmlNode():new( , "Id" )                               // Identificación 
      ::oXmlActor:addBelow( ::oXmlId )

   do case
   case ( ::nEntity == ENTIDAD_JURIDICA )

      ::oXmlOrgId    := TXmlNode():new( , "OrgId" )                          // Persona jurídica

      if !empty( ::BICOrBEI )
         ::oXmlOrgId:addBelow( TXmlParseNode():New( "BICOrBEI", ::BICOrBEI, 11 ) )         // BIC o BEI 
      else 
         ::oSender:addError( "BIC o BEI no puede estar vacio." )
      end if 

      ::oXmlId:addBelow( ::oXmlOrgId )

      ::getOtherNodeXML() 

   case ( ::nEntity == ENTIDAD_FISICA )

      ::oXmlOrgId    := TXmlNode():New( , "PrvtId" )

         ::oXmlDtAndPlcOfBirth    := TXmlNode():New( , "DtAndPlcOfBirth" )
         ::oXmlDtAndPlcOfBirth:addBelow( TXmlParseNode():New( "BirthDt", ::BirthDt, 8 ) )
         ::oXmlDtAndPlcOfBirth:addBelow( TXmlParseNode():New( "PrvcOfBirth", ::PrvcOfBirth, 35 ) )
         ::oXmlDtAndPlcOfBirth:addBelow( TXmlParseNode():New( "CityOfBirth", ::CityOfBirth, 35 ) )
         ::oXmlDtAndPlcOfBirth:addBelow( TXmlParseNode():New( "CtryOfBirth", ::CtryOfBirth, 2 ) )

         ::oXmlOrgId:addBelow( ::oXmlDtAndPlcOfBirth )

      ::oXmlId:addBelow( ::oXmlOrgId )            

      ::getOtherNodeXML() 

   otherwise 

      ::oSender:addError( "No se ha especificado el tipo de entidad juridica o física." )

   end case

Return ( ::oXmlActor )

//--------------------------------------------------------------------------------------//

METHOD getOtherNodeXML() CLASS SepaDebitActor

   if empty( ::Id )
      Return ( nil )
   end if 

   ::oXmlOthr        := TXmlNode():new( , "Othr" ) 
   ::oXmlOthr:addBelow( TXmlParseNode():New( "Id", ::Id, 35 ) )

      ::oXmlSchmeNm  := TXmlNode():new( , "SchmeNm" )
         if ::Cd != nil
            ::oXmlSchmeNm:addBelow( TXmlParseNode():New( "Cd", ::Cd, 4 ) ) 
         end if 
         ::oXmlSchmeNm:addBelow( TXmlParseNode():New( "Prtry", ::Prtry, 35 ) ) 

   ::oXmlOthr:addBelow( ::oXmlSchmeNm )

   if ::Issr != nil
      ::oXmlOthr:addBelow( TXmlParseNode():New( "Issr", ::Issr, 35 ) )
   end if

   ::oXmlOrgId:addBelow( ::oXmlOthr )

Return ( nil )

//--------------------------------------------------------------------------------------//

METHOD getCreditorXML()

   ::oXmlCdrt     := TXmlNode():New( , "Cdtr" )

   if ::Nm != nil

      ::oXmlCdrt:addBelow( TXmlParseNode():New( "Nm", ::Nm, 70 ) )

      if ::Ctry != nil .or. ::AdrLine1 != nil
         ::oXmlPstlAdr  := TXmlNode():New( , "PstlAdr" )                               // Dirección postal
         ::oXmlPstlAdr:addBelow( TXmlParseNode():New( "Ctry", ::oCtry, 2 ) )           // País
         ::oXmlPstlAdr:addBelow( TXmlParseNode():New( "AdrLine", ::AdrLine1, 70 ) )    // Dirección en texto libre
         ::oXmlPstlAdr:addBelow( TXmlParseNode():New( "AdrLine", ::AdrLine2, 70 ) )    // Dirección en texto libre
      endif

   else
      ::oSender:addError( "Nombre del acreedor no existe" )
   endif

Return ( ::oXmlCdrt )

//--------------------------------------------------------------------------------------//

METHOD getCreditorIBANXML()

   ::oXmlCdtrAcct    := TXmlNode():New( , "CdtrAcct" )

   if ::IBAN != nil
      ::oXmlIdIBAN   := TXmlNode():New( , "Id" )
         ::oXmlIdIBAN:addBelow( TXmlParseNode():New( "IBAN", ::IBAN, 34 ) )

      ::oXmlCdtrAcct:addBelow( ::oXmlIdIBAN )
   else
      ::oSender:addError( "IBAN del acreedor no existe" )
   endif

Return ( ::oXmlCdtrAcct )

//--------------------------------------------------------------------------------------//

METHOD getCreditorBICXML()

   ::oXmlCdtrAgt        := TXmlNode():New( , "CdtrAgt" )

   if ::BICOrBEI != nil
      ::oXmlFinInstnId  := TXmlNode():New( , "FinInstnId" )
         ::oXmlFinInstnId:addBelow( TXmlParseNode():New( "BIC", ::BICOrBEI, 11 ) )

      ::oXmlCdtrAgt:addBelow( ::oXmlFinInstnId )
   else
      ::oSender:addError( "BIC del acreedor no existe" )
   endif

Return ( ::oXmlCdtrAgt )

//--------------------------------------------------------------------------------------//

METHOD getIdCreditorXML()

   local oXmlId
   local oXmlPrvtId
   local oXmlOthr
   local oXmlSchmeNm

   ::oXmlCdtrSchmeId    := TXmlNode():New( , "CdtrSchmeId" )

   if ::Id != nil
      oXmlId            := TXmlNode():New( , "Id" )
   
         oXmlPrvtId     := TXmlNode():New( , "PrvtId" ) 

            oXmlOthr    := TXmlNode():New( , "Othr" ) 
            oXmlOthr:addBelow( TXmlParseNode():New( "Id", ::Id, 35 ) )    

            if ::Prtry != nil
               oXmlSchmeNm    := TXmlNode():New( , "SchmeNm" )                      // Nombre del esquema 
               oXmlSchmeNm:addBelow( TXmlParseNode():New( "Prtry", ::Prtry, 35 ) )  // Propietario 

               oXmlOthr:addBelow( oXmlSchmeNm )
            endif

         oXmlPrvtId:addBelow( oXmlOthr )

      oXmlId:addBelow( oXmlPrvtId )

      ::oXmlCdtrSchmeId:addBelow( oXmlId )

   else
      ::oSender:addError( "Identificador del acreedor no existe" )
   end if 

Return ( ::oXmlCdtrSchmeId )

//--------------------------------------------------------------------------------------//

METHOD getDirectDebitTransactionInformationXml()

   local oXmlPmtId
   local oXmlDrctDbtTx
   local oXmlMndtRltdInf
   local oXmlAmdmntInd
   local oXmlAmdmntInfDtls   
   local oXmlDbtrAgt
   local oXmlFinInstnId
   local oXmlDbtr
   local oXmlDbtrAcct
   local oXmlId
   local oXmlPurp
   local oXmlRmtInf

   ::oXmlDrctDbtTxInf   := TXmlNode():New( , "DrctDbtTxInf" )

   if ::InstdAmt > 0
      
      // Importe ordenado------------------------------------------------------
      
      if ::InstrId != nil .or. ::EndToEndId != nil

         oXmlPmtId      := TXmlNode():New( , "PmtId")                                  // Identificación del pago  
         
         if ::InstrId != nil         
            oXmlPmtId:addBelow( TXmlParseNode():New( "InstrId", ::InstrId, 35 ) )         // Identificación de la instrucción
         end if 
         
         if ::EndToEndId != nil
            oXmlPmtId:addBelow( TXmlParseNode():New( "EndToEndId", ::EndToEndId, 35 ) )   // Identificación de extremo a extremo 
         end if 

         ::oXmlDrctDbtTxInf:addBelow( oXmlPmtId )

      endif

      ::oXmlDrctDbtTxInf:addBelow( TXmlParseNode():New( "InstdAmt", ::InstdAmt, 12, .t. ) )  // Importe ordenado

      if ::MndtId != nil .or. ::DtOfSgntr != nil 

         oXmlDrctDbtTx        := TXmlNode():New( , "DrctDbtTx" )                             // Operación de adeudo directo 
            oXmlMndtRltdInf   := TXmlNode():New( , "MndtRltdInf" )                           // Información del mandato 

            if ::MndtId != nil
               oXmlMndtRltdInf:addBelow( TXmlParseNode():New( "MndtId", ::MndtId, 35 ) )        
            end if 
            
            if ::DtOfSgntr != nil
               oXmlMndtRltdInf:addBelow( TXmlParseNode():New( "DtOfSgntr", ::DtOfSgntr, 10 ) )   // Fecha de firma 
            end if 

            oXmlAmdmntInd     := TXmlParseNode():New( "AmdmntInd", ::AmdmntInd, 5 )

            if ::OrgnlMndtId != nil
               oXmlAmdmntInfDtls := TXmlNode():New( , "AmdmntInfDtls" )                               // Detalles de la modificación 
               oXmlAmdmntInfDtls:addBelow( TXmlParseNode():New( "OrgnlMndtId", ::OrgnlMndtId, 35 ) )  // Identificación del mandato original 

               oXmlAmdmntInd:addBelow( oXmlAmdmntInfDtls )
            endif

            oXmlMndtRltdInf:addBelow( oXmlAmdmntInd )

         oXmlDrctDbtTx:addBelow( oXmlMndtRltdInf )

      ::oXmlDrctDbtTxInf:addBelow( oXmlDrctDbtTx )

      endif

      // Entidad del deudor original-------------------------------------------

      if ::BICOrBEI != nil
         oXmlDbtrAgt       := TXmlNode():New( , "DbtrAgt" )          // Entidad del deudor 
            oXmlFinInstnId := TXmlNode():New( , "FinInstnId" )       // Identificación de la entidad 
            oXmlFinInstnId:addBelow( TXmlParseNode():New( "BIC", ::BICOrBEI, 11 ) )
         oXmlDbtrAgt:addBelow( oXmlFinInstnId )

         ::oXmlDrctDbtTxInf:addBelow( oXmlDbtrAgt )
      
      else
         ::oSender:addError( ::oSender:ErrorMessages[ 'SEPA_DEBTOR_AGENT' ] )
      
      endif

      // Deudor----------------------------------------------------------------

      if ::Nm != nil
         ::oXmlDrctDbtTxInf:addBelow( ::getNodeXML() )         
      else
         ::oSender:addError( ::oSender:ErrorMessages[ 'SEPA_DEBTOR_NAME' ] )
      endif

      // Cuenta del deudor-----------------------------------------------------

      if ::IBAN != nil 
         oXmlDbtrAcct   := TXmlNode():New( , "DbtrAcct" )
            oXmlId      := TXmlNode():New( , "Id" )
            oXmlId:addBelow( TXmlParseNode():New( "IBAN", ::IBAN, 34 ) )   // IBAN
         oXmlDbtrAcct:addBelow( oXmlId )

         ::oXmlDrctDbtTxInf:addBelow( oXmlDbtrAcct )
      else
         ::oSender:addError( ::oSender:ErrorMessages[ 'SEPA_DEBTOR_ACCOUNT' ] )
      endif

      // Propósito ------------------------------------------------------------

      if ::oSender:PurposeCd != nil
         oXmlPurp       := TXmlNode():New( , "Purp" )

         if ::oSender:PurposeCd != nil
            oXmlPurp:addBelow( TXmlParseNode():New( "Cd", ::oSender:PurposeCd, 4 ) )
         end if 

         ::oXmlDrctDbtTxInf:addBelow( oXmlPurp )
      endif

      // Concepto--------------------------------------------------------------

      if ::Ustrd != nil
         oXmlRmtInf     := TXmlNode():New( , "RmtInf" )                       // Concepto
         oXmlRmtInf:addBelow( TXmlParseNode():New( "Ustrd", ::Ustrd, 140 ) )  // No estructurado

         ::oXmlDrctDbtTxInf:addBelow( oXmlRmtInf )
      endif

   else
      ::oSender:addError( 'Recibo sin importe' )
   endif

Return ( ::oXmlDrctDbtTxInf )

//--------------------------------------------------------------------//

CLASS TXmlParseNode FROM TXmlNode

   METHOD New()

ENDCLASS

//--------------------------------------------------------------------------------------//

METHOD new( cName, xValue, nLen, lCurrency ) CLASS TXmlParseNode

   local cType 
   local cData
   local hAttributes

   if nLen == nil
      nLen        := 0
   end if 

   cType          := valtype( xValue )

   do case
   case cType == "N"
      cData       := ltrim( str( xValue, nLen, 2 ) )
   case cType == "D"
      cData       := sDate( xValue )
   case cType == "C"
      if nLen != 0
         cData    := alltrim( padr( xValue, nLen ) )
      else
         cData    := alltrim( xValue )
      end if
   end case

   if lCurrency != nil
      hAttributes := { "Ccy" => "EUR" }
   endif

   ::Super:New( , cName, hAttributes, cData )

Return ( Self )

//--------------------------------------------------------------------//

/* v.1.0 14/11/2013
 * Funciones misceláneas de apoyo a formatos SEPA
 * (c) Joaquim Ferrer Godoy <quim_ferrer@yahoo.es>
 */

function cTime()
   local strTime := time()
   strTime := substr(strTime,1,2) + substr(strTime,4,2) + substr(strTime,7,2)
return strTime


function fDate( d )
   local cDateFrm := Set( 4, "yyyy/mm/dd" )
   local strDate  := If( d != nil, dtos(d), dtos(date()) )
   Set( 4, cDateFrm )
return( strDate )


function sDate( d )
   local cDateFrm := Set( 4, "yyyy-mm-dd" )
   local strDate  := If( d != nil, dtoc(d), dtoc(date()) )
   Set( 4, cDateFrm )
return( strDate )


function Dec2Str(nVal, nLen)
   local strVal
   strVal := str( nVal, nLen +1, 2 )     // +1 espacio que resta punto decimal
   strVal := strtran( strVal, "." )      // Quitar punto decimal
   strVal := strtran( strVal, " ", "0" ) // Reemplazar espacios por 0
return( strVal )


function IsoDateTime()
return( sDate() +"T"+ time() )     // YYYY-MM-DDThh:mm:ss


function OutFile(nHandle, a)
   local strRec := ""
   aeval( a, {|e|  strRec += e } )
   fwrite(nHandle, strRec + CRLF)
return nil


function Id_Name( cCountry, cCode, cNif )
/*
Identificador del Presentador / Acreedor
Este identificador es una referencia con un máximo de 35 caracteres que contiene los siguientes elementos:
   a) Código del país3: (Posiciones 1ª y 2ª)
   Código ISO 3166 del país que ha emitido el identificador nacional del acreedor. “ES” en el caso español.
   b) Dígitos de control: (Posiciones 3ª y 4ª)
   Código que hace referencia a los componentes a y d. Para su cálculo se requiere la siguiente operación:
   • Excluir las posiciones 5 a 7 de esta referencia
   • Entre las posiciones 8 y 35, eliminar todos los espacios y caracteres no alfanuméricos. Esto es: “/ - ? : ( ) . , ' +”.
   • Añadir el código ISO del país, y ‘00’ a la derecha, y
   • Convertir las letras en dígitos, de acuerdo a la tabla de conversión 1
   • Aplicar el sistema de dígitos de control MOD 97-10.
      A=10, B=11... Z=35 
   c) Código comercial del Acreedor (Sufijo): (Posiciones 5 a 7) Número de tres cifras comprendido entre 000 y 999. 
   Contiene información necesaria en la relación entre la entidad del acreedor y el acreedor y permite al acreedor identificar 
   diferentes líneas comerciales o servicios.
   d) Identificación del Acreedor específica de cada país: (Posiciones 8 a 35) Para los acreedores españoles, se indicará 
   el NIF o NIE del acreedor utilizando para ello las posiciones 8 a 16.
*/
 local cId, n, nLen, cValue
 local cAlgorithm := "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

   cId  := ""
   nLen := len( cNif )
   for n:= 1 to nLen
      cValue := substr( cNif, n, 1 )
      if isDigit(cValue)
         cId += cValue
      else
         cId += str( at( cValue, cAlgorithm ) +9, 2, 0 )
      endif
   next

   cId += str( at( substr(cCountry,1,1), cAlgorithm ) +9, 2, 0 )
   cId += str( at( substr(cCountry,2,1), cAlgorithm ) +9, 2, 0 )
   cId += "00"
   cId := cCountry + strzero(98 - ( val(cId) % 97 ), 2) + cCode + cNif
return padR(cId, 35)


function id_File( cRef )
/*
Identificación del fichero: referencia que asigna el presentador al fichero, para su envío a la entidad receptora. 
Esta referencia se estructurará de la siguiente manera, tomando los datos generados por el ordenador del presentador 
en el momento de la creación del fichero: 
   Indicador del tipo de mensaje (3 caracteres) -> PRE Fichero de Presentación de adeudos 
    AAAAMMDD (año, mes y día) = (8 caracteres) 
    HHMMSSmmmmm (hora minuto segundo y 5 posiciones de milisegundos = 11 caracteres) 
    Referencia identificativa que asigne el presentador (13 caracteres) 
*/
   local cId   := "PRE" + fDate() + cTime() + strzero( seconds(), 5 ) + cRef

return padR(cId, 35)


