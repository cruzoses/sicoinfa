/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\EInfDiaTActuaciones.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( EINFDIAACTUACIONES );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TINFGEN );
HB_FUNC_EXTERN( CTOD );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( YEAR );
HB_FUNC_EXTERN( DATE );
HB_FUNC_STATIC( EINFDIAACTUACIONES_CREATE );
HB_FUNC_STATIC( EINFDIAACTUACIONES_OPENFILES );
HB_FUNC_STATIC( EINFDIAACTUACIONES_CLOSEFILES );
HB_FUNC_STATIC( EINFDIAACTUACIONES_LRESOURCE );
HB_FUNC_STATIC( EINFDIAACTUACIONES_LGENERATE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( RTRIM );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( APOLOBREAK );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( CPATEMP );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( ERRORMESSAGE );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( TCHECKBOX );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( AITMACTUA );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( CCURUSR );
HB_FUNC_EXTERN( GETFILENOEXT );
HB_FUNC_EXTERN( LCHKSER );
HB_FUNC_EXTERN( ORETFLD );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_EINFDIATACTUACIONES )
{ "EINFDIAACTUACIONES", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( EINFDIAACTUACIONES )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TINFGEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( TINFGEN )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTOD", {HB_FS_PUBLIC}, {HB_FUNCNAME( CTOD )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "YEAR", {HB_FS_PUBLIC}, {HB_FUNCNAME( YEAR )}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EINFDIAACTUACIONES_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EINFDIAACTUACIONES_CREATE )}, NULL },
{ "EINFDIAACTUACIONES_OPENFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EINFDIAACTUACIONES_OPENFILES )}, NULL },
{ "EINFDIAACTUACIONES_CLOSEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EINFDIAACTUACIONES_CLOSEFILES )}, NULL },
{ "EINFDIAACTUACIONES_LRESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EINFDIAACTUACIONES_LRESOURCE )}, NULL },
{ "EINFDIAACTUACIONES_LGENERATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EINFDIAACTUACIONES_LGENERATE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDTMPINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDGROUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTIPACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( RTRIM )}, NULL },
{ "CNOMACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDEFDIVINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDEFFECINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "APOLOBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( APOLOBREAK )}, NULL },
{ "_OEXPEDIENTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWOPEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "CPATEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATEMP )}, NULL },
{ "ADDBAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OEXPEDIENTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OACTUACION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OACTUACION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OTIPOACTUACION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OTIPOACTUACION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "ERRORMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORMESSAGE )}, NULL },
{ "CLOSEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "USED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STDRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODEFCLIINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODEFTIPACTINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCHECKBOX", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCHECKBOX )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "LALLACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LALLACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADIALOGS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OFLD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OINIACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "DINIACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DINIACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OFINACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DFINACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DFINACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LPENDIENTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LPENDIENTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATEFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AITMACTUA", {HB_FS_PUBLIC}, {HB_FUNCNAME( AITMACTUA )}, NULL },
{ "CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETTOTAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OMTRINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LASTREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DISABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OBTNCANCEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ZAP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_AHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "DINIINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DFININF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LALLCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "CCLIORG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCLIDES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LALLTIPACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTIPACTORG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTIPACTDES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CEXPRESIONFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCURUSR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CCURUSR )}, NULL },
{ "GETFILENOEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETFILENOEXT )}, NULL },
{ "CFILE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDKEYCOUNT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LBREAK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LCHKSER", {HB_FS_PUBLIC}, {HB_FUNCNAME( LCHKSER )}, NULL },
{ "CSEREXP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ASER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NNUMEXP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSUFEXP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "APPEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CTIPACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORETFLD", {HB_FS_PUBLIC}, {HB_FUNCNAME( ORETFLD )}, NULL },
{ "_CNUMDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CPERCTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CTLFCTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CMVLCTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CFAXCTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DFECINI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DFECINI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CHORINI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHORINI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DFECFIN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DFECFIN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CHORFIN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHORFIN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_MMEMACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MMEMACT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "IDXDELETE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_EINFDIATACTUACIONES, ".\\.\\Prg\\EInfDiaTActuaciones.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_EINFDIATACTUACIONES
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_EINFDIATACTUACIONES )
   #include "hbiniseg.h"
#endif

HB_FUNC( EINFDIAACTUACIONES )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,137,0,36,8,0,103,2,0,100,8,
		29,202,2,176,1,0,104,2,0,12,1,29,191,2,
		166,129,2,0,122,80,1,48,2,0,176,3,0,12,
		0,106,19,69,73,110,102,68,105,97,65,99,116,117,
		97,99,105,111,110,101,115,0,108,4,4,1,0,108,
		0,112,3,80,2,36,10,0,48,5,0,95,2,106,
		7,79,66,74,69,67,84,0,100,95,1,121,72,121,
		72,121,72,106,12,111,69,120,112,101,100,105,101,110,
		116,101,0,4,1,0,9,112,5,73,36,11,0,48,
		5,0,95,2,106,7,79,66,74,69,67,84,0,100,
		95,1,121,72,121,72,121,72,106,11,111,65,99,116,
		117,97,99,105,111,110,0,4,1,0,9,112,5,73,
		36,12,0,48,5,0,95,2,106,7,79,66,74,69,
		67,84,0,100,95,1,121,72,121,72,121,72,106,15,
		111,84,105,112,111,65,99,116,117,97,99,105,111,110,
		0,4,1,0,9,112,5,73,36,13,0,48,5,0,
		95,2,106,6,76,79,71,73,67,0,120,95,1,121,
		72,121,72,121,72,106,12,108,80,101,110,100,105,101,
		110,116,101,115,0,4,1,0,9,112,5,73,36,14,
		0,48,5,0,95,2,106,6,76,79,71,73,67,0,
		120,95,1,121,72,121,72,121,72,106,8,108,65,108,
		108,65,99,116,0,4,1,0,9,112,5,73,36,15,
		0,48,5,0,95,2,106,7,79,66,74,69,67,84,
		0,100,95,1,121,72,121,72,121,72,106,8,111,73,
		110,105,65,99,116,0,4,1,0,9,112,5,73,36,
		16,0,48,5,0,95,2,106,7,79,66,74,69,67,
		84,0,100,95,1,121,72,121,72,121,72,106,8,111,
		70,105,110,65,99,116,0,4,1,0,9,112,5,73,
		36,17,0,48,5,0,95,2,100,176,6,0,106,7,
		48,49,47,48,49,47,0,176,7,0,176,8,0,176,
		9,0,12,0,12,1,12,1,72,12,1,95,1,121,
		72,121,72,121,72,106,8,100,73,110,105,65,99,116,
		0,4,1,0,9,112,5,73,36,18,0,48,5,0,
		95,2,100,176,9,0,12,0,95,1,121,72,121,72,
		121,72,106,8,100,70,105,110,65,99,116,0,4,1,
		0,9,112,5,73,36,20,0,48,10,0,95,2,106,
		7,67,114,101,97,116,101,0,108,11,95,1,121,72,
		121,72,121,72,112,3,73,36,22,0,48,10,0,95,
		2,106,10,79,112,101,110,70,105,108,101,115,0,108,
		12,95,1,121,72,121,72,121,72,112,3,73,36,24,
		0,48,10,0,95,2,106,11,67,108,111,115,101,70,
		105,108,101,115,0,108,13,95,1,121,72,121,72,121,
		72,112,3,73,36,26,0,48,10,0,95,2,106,10,
		108,82,101,115,111,117,114,99,101,0,108,14,95,1,
		121,72,121,72,121,72,112,3,73,36,28,0,48,10,
		0,95,2,106,10,108,71,101,110,101,114,97,116,101,
		0,108,15,95,1,121,72,121,72,121,72,112,3,73,
		36,30,0,48,16,0,95,2,112,0,73,167,14,0,
		0,176,17,0,104,2,0,95,2,20,2,168,48,18,
		0,95,2,112,0,80,3,176,19,0,95,3,106,10,
		73,110,105,116,67,108,97,115,115,0,12,2,28,12,
		48,20,0,95,3,164,146,1,0,73,95,3,110,7,
		48,18,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( EINFDIAACTUACIONES_CREATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,34,0,102,80,1,36,36,0,48,21,
		0,95,1,106,8,99,84,105,112,65,99,116,0,106,
		2,67,0,92,3,121,90,6,106,1,0,6,106,10,
		84,105,112,46,32,65,99,116,46,0,9,106,15,84,
		105,112,111,32,97,99,116,117,97,99,105,243,110,0,
		92,10,9,112,10,73,36,37,0,48,21,0,95,1,
		106,8,99,78,111,109,65,99,116,0,106,2,67,0,
		92,35,121,90,6,106,1,0,6,106,10,65,99,116,
		117,97,99,105,243,110,0,9,106,17,78,111,109,98,
		114,101,32,97,99,116,117,97,99,105,243,110,0,92,
		10,9,112,10,73,36,38,0,48,21,0,95,1,106,
		8,99,78,117,109,68,111,99,0,106,2,67,0,92,
		14,121,90,6,106,1,0,6,106,10,68,111,99,117,
		109,101,110,116,111,0,120,106,17,78,250,109,101,114,
		111,32,100,111,99,117,109,101,110,116,111,0,92,14,
		9,112,10,73,36,39,0,48,21,0,95,1,106,8,
		100,70,101,99,73,110,105,0,106,2,68,0,92,8,
		121,90,6,106,1,0,6,106,7,73,110,105,99,105,
		111,0,120,106,13,70,101,99,104,97,32,105,110,105,
		99,105,111,0,92,10,9,112,10,73,36,40,0,48,
		21,0,95,1,106,8,99,72,111,114,73,110,105,0,
		106,2,67,0,92,5,121,90,6,106,1,0,6,106,
		12,72,111,114,97,32,105,110,105,99,105,111,0,9,
		106,12,72,111,114,97,32,105,110,105,99,105,111,0,
		92,10,9,112,10,73,36,41,0,48,21,0,95,1,
		106,8,100,70,101,99,70,105,110,0,106,2,68,0,
		92,8,121,90,6,106,1,0,6,106,7,76,237,109,
		105,116,101,0,120,106,13,70,101,99,104,97,32,108,
		237,109,105,116,101,0,92,10,9,112,10,73,36,42,
		0,48,21,0,95,1,106,8,99,72,111,114,70,105,
		110,0,106,2,67,0,92,5,121,90,6,106,1,0,
		6,106,9,72,111,114,97,32,102,105,110,0,9,106,
		9,72,111,114,97,32,102,105,110,0,92,10,9,112,
		10,73,36,43,0,48,21,0,95,1,106,8,109,77,
		101,109,65,99,116,0,106,2,77,0,92,10,121,90,
		6,106,1,0,6,106,12,68,101,115,99,114,105,112,
		99,105,243,110,0,9,106,12,68,101,115,99,114,105,
		112,99,105,243,110,0,92,50,9,112,10,73,36,44,
		0,48,21,0,95,1,106,8,99,67,111,100,67,108,
		105,0,106,2,67,0,92,12,121,90,6,106,1,0,
		6,106,8,67,108,105,101,110,116,101,0,120,106,8,
		67,108,105,101,110,116,101,0,92,14,9,112,10,73,
		36,45,0,48,21,0,95,1,106,8,99,78,111,109,
		67,108,105,0,106,2,67,0,92,80,121,90,6,106,
		1,0,6,106,15,78,111,109,98,114,101,32,99,108,
		105,101,110,116,101,0,120,106,15,78,111,109,98,114,
		101,32,99,108,105,101,110,116,101,0,92,50,9,112,
		10,73,36,46,0,48,21,0,95,1,106,8,99,80,
		101,114,67,116,111,0,106,2,67,0,92,30,121,90,
		6,106,1,0,6,106,9,67,111,110,116,97,99,116,
		111,0,120,106,20,80,101,114,115,111,110,97,32,100,
		101,32,99,111,110,116,97,99,116,111,0,92,30,9,
		112,10,73,36,47,0,48,21,0,95,1,106,8,99,
		84,108,102,67,116,111,0,106,2,67,0,92,20,121,
		90,6,106,1,0,6,106,9,84,101,108,233,102,111,
		110,111,0,120,106,9,84,101,108,233,102,111,110,111,
		0,92,25,9,112,10,73,36,48,0,48,21,0,95,
		1,106,8,99,77,118,108,67,116,111,0,106,2,67,
		0,92,20,121,90,6,106,1,0,6,106,6,77,111,
		118,105,108,0,9,106,6,77,111,118,105,108,0,92,
		25,9,112,10,73,36,49,0,48,21,0,95,1,106,
		8,99,70,97,120,67,116,111,0,106,2,67,0,92,
		20,121,90,6,106,1,0,6,106,4,70,97,120,0,
		9,106,4,70,97,120,0,92,25,9,112,10,73,36,
		51,0,48,22,0,95,1,106,8,99,78,117,109,68,
		111,99,0,106,18,99,84,105,112,65,99,116,32,43,
		32,99,78,117,109,68,111,99,0,112,2,73,36,53,
		0,48,23,0,95,1,89,22,0,0,0,1,0,1,
		0,48,24,0,48,25,0,95,255,112,0,112,0,6,
		89,72,0,0,0,1,0,1,0,106,19,84,105,112,
		111,32,97,99,116,117,97,99,105,243,110,32,32,58,
		32,0,176,26,0,48,24,0,48,25,0,95,255,112,
		0,112,0,12,1,72,106,2,45,0,72,176,26,0,
		48,27,0,48,25,0,95,255,112,0,112,0,12,1,
		72,6,90,29,106,24,84,111,116,97,108,32,116,105,
		112,111,32,97,99,116,117,97,99,105,243,110,46,46,
		46,0,6,112,3,73,36,55,0,48,28,0,95,1,
		9,112,1,73,36,56,0,48,29,0,95,1,9,112,
		1,73,36,58,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( EINFDIAACTUACIONES_OPENFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,3,0,36,64,0,120,80,1,36,66,0,176,30,
		0,89,15,0,1,0,0,0,176,31,0,95,1,12,
		1,6,12,1,80,3,36,68,0,113,127,1,0,36,
		70,0,48,32,0,102,48,33,0,176,34,0,106,11,
		69,88,80,67,65,66,46,68,66,70,0,100,12,2,
		106,11,69,88,80,67,65,66,46,68,66,70,0,106,
		7,69,120,112,67,97,98,0,176,35,0,12,0,100,
		176,36,0,12,0,9,120,9,9,112,9,112,1,73,
		48,37,0,48,38,0,102,112,0,106,11,69,88,80,
		67,65,66,46,67,68,88,0,112,1,73,48,37,0,
		48,38,0,102,112,0,112,0,73,48,39,0,48,38,
		0,102,112,0,112,0,73,36,72,0,48,40,0,102,
		48,33,0,176,34,0,106,11,69,88,80,68,69,84,
		46,68,66,70,0,100,12,2,106,11,69,88,80,68,
		69,84,46,68,66,70,0,106,7,69,120,112,68,101,
		116,0,176,35,0,12,0,100,176,36,0,12,0,9,
		120,9,9,112,9,112,1,73,48,37,0,48,41,0,
		102,112,0,106,11,69,88,80,68,69,84,46,67,68,
		88,0,112,1,73,48,37,0,48,41,0,102,112,0,
		112,0,73,48,39,0,48,41,0,102,112,0,112,0,
		73,36,74,0,48,42,0,102,48,33,0,176,34,0,
		106,16,65,67,84,85,65,67,73,79,78,69,83,46,
		68,66,70,0,100,12,2,106,16,65,67,84,85,65,
		67,73,79,78,69,83,46,68,66,70,0,106,7,65,
		99,116,117,97,99,0,176,35,0,12,0,100,176,36,
		0,12,0,9,120,9,9,112,9,112,1,73,48,37,
		0,48,43,0,102,112,0,106,16,65,67,84,85,65,
		67,73,79,78,69,83,46,67,68,88,0,112,1,73,
		48,37,0,48,43,0,102,112,0,112,0,73,48,39,
		0,48,43,0,102,112,0,112,0,73,114,84,0,0,
		36,76,0,115,80,2,36,79,0,176,44,0,176,45,
		0,95,2,12,1,106,41,73,109,112,111,115,105,98,
		108,101,32,97,98,114,105,114,32,116,111,100,97,115,
		32,108,97,115,32,98,97,115,101,115,32,100,101,32,
		100,97,116,111,115,0,20,2,36,80,0,48,46,0,
		102,112,0,73,36,81,0,9,80,1,36,85,0,176,
		30,0,95,3,20,1,36,87,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( EINFDIAACTUACIONES_CLOSEFILES )
{
	static const HB_BYTE pcode[] =
	{
		36,93,0,176,47,0,48,38,0,102,112,0,12,1,
		31,30,48,48,0,48,38,0,102,112,0,112,0,28,
		17,36,94,0,48,49,0,48,38,0,102,112,0,112,
		0,73,36,97,0,176,47,0,48,41,0,102,112,0,
		12,1,31,30,48,48,0,48,41,0,102,112,0,112,
		0,28,17,36,98,0,48,49,0,48,41,0,102,112,
		0,112,0,73,36,101,0,176,47,0,48,43,0,102,
		112,0,12,1,31,30,48,48,0,48,43,0,102,112,
		0,112,0,28,17,36,102,0,48,49,0,48,43,0,
		102,112,0,112,0,73,36,105,0,48,32,0,102,100,
		112,1,73,36,106,0,48,40,0,102,100,112,1,73,
		36,107,0,48,42,0,102,100,112,1,73,36,109,0,
		102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( EINFDIAACTUACIONES_LRESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,113,0,102,80,2,36,115,0,48,50,
		0,95,2,106,16,73,78,70,84,65,67,84,85,65,
		67,73,79,78,69,83,0,112,1,31,8,36,116,0,
		9,110,7,36,119,0,48,51,0,95,2,92,110,92,
		111,92,120,92,121,100,93,130,0,112,6,31,8,36,
		120,0,9,110,7,36,123,0,48,52,0,95,2,93,
		150,0,93,151,0,93,160,0,93,161,0,93,140,0,
		112,5,31,8,36,124,0,9,110,7,36,129,0,48,
		53,0,176,54,0,12,0,93,170,0,89,37,0,1,
		0,1,0,2,0,176,55,0,12,0,121,8,28,11,
		48,56,0,95,255,112,0,25,11,48,57,0,95,255,
		95,1,112,1,6,48,58,0,48,59,0,95,2,112,
		0,112,0,122,1,100,100,100,100,100,100,9,100,9,
		112,12,73,36,136,0,48,60,0,95,2,48,53,0,
		176,61,0,12,0,93,180,0,89,37,0,1,0,1,
		0,2,0,176,55,0,12,0,121,8,28,11,48,62,
		0,95,255,112,0,25,11,48,63,0,95,255,95,1,
		112,1,6,48,58,0,48,59,0,95,2,112,0,112,
		0,122,1,100,100,100,100,100,100,100,100,9,89,18,
		0,0,0,1,0,2,0,48,56,0,95,255,112,0,
		68,6,100,9,120,100,100,100,100,100,100,100,100,100,
		112,25,112,1,73,36,143,0,48,64,0,95,2,48,
		53,0,176,61,0,12,0,93,190,0,89,37,0,1,
		0,1,0,2,0,176,55,0,12,0,121,8,28,11,
		48,65,0,95,255,112,0,25,11,48,66,0,95,255,
		95,1,112,1,6,48,58,0,48,59,0,95,2,112,
		0,112,0,122,1,100,100,100,100,100,100,100,100,9,
		89,18,0,0,0,1,0,2,0,48,56,0,95,255,
		112,0,68,6,100,9,120,100,100,100,100,100,100,100,
		100,100,112,25,112,1,73,36,147,0,48,53,0,176,
		54,0,12,0,93,200,0,89,37,0,1,0,1,0,
		2,0,176,55,0,12,0,121,8,28,11,48,67,0,
		95,255,112,0,25,11,48,68,0,95,255,95,1,112,
		1,6,48,58,0,48,59,0,95,2,112,0,112,0,
		122,1,100,100,100,100,100,100,9,100,9,112,12,73,
		36,149,0,48,69,0,95,2,176,70,0,12,0,48,
		71,0,48,41,0,95,2,112,0,112,0,112,2,73,
		36,151,0,48,72,0,48,73,0,95,2,112,0,48,
		74,0,48,41,0,95,2,112,0,112,0,112,1,73,
		36,153,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( EINFDIAACTUACIONES_LGENERATE )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,157,0,102,80,1,36,159,0,106,4,
		46,116,46,0,80,2,36,161,0,48,75,0,48,76,
		0,95,1,112,0,112,0,73,36,162,0,48,77,0,
		48,78,0,95,1,112,0,112,0,73,36,164,0,48,
		79,0,48,25,0,95,1,112,0,112,0,73,36,169,
		0,48,80,0,95,1,90,29,106,13,70,101,99,104,
		97,32,32,32,32,32,58,32,0,176,81,0,176,9,
		0,12,0,12,1,72,6,89,58,0,0,0,1,0,
		1,0,106,13,80,101,114,105,111,100,111,32,32,32,
		58,32,0,176,81,0,48,82,0,95,255,112,0,12,
		1,72,106,4,32,62,32,0,72,176,81,0,48,83,
		0,95,255,112,0,12,1,72,6,89,77,0,0,0,
		1,0,1,0,106,13,67,108,105,101,110,116,101,115,
		32,32,58,32,0,48,84,0,95,255,112,0,28,12,
		106,6,84,111,100,111,115,0,25,34,176,85,0,48,
		86,0,95,255,112,0,12,1,106,4,32,62,32,0,
		72,176,85,0,48,87,0,95,255,112,0,12,1,72,
		72,6,89,77,0,0,0,1,0,1,0,106,13,65,
		99,116,117,97,99,105,243,110,32,58,32,0,48,88,
		0,95,255,112,0,28,12,106,6,84,111,100,111,115,
		0,25,34,176,85,0,48,89,0,95,255,112,0,12,
		1,106,4,32,62,32,0,72,176,85,0,48,90,0,
		95,255,112,0,12,1,72,72,6,4,4,0,112,1,
		73,36,171,0,48,67,0,95,1,112,0,28,27,36,
		172,0,96,2,0,106,16,32,46,97,110,100,46,32,
		33,108,65,99,116,69,110,100,0,135,36,175,0,48,
		56,0,95,1,112,0,31,102,36,176,0,96,2,0,
		106,26,32,46,97,110,100,46,32,100,70,101,99,70,
		105,110,32,62,61,32,67,116,111,100,40,32,34,0,
		176,81,0,48,62,0,95,1,112,0,12,1,72,106,
		29,34,32,41,32,46,97,110,100,46,32,100,70,101,
		99,70,105,110,32,60,61,32,67,116,111,100,40,32,
		34,0,72,176,81,0,48,65,0,95,1,112,0,12,
		1,72,106,4,34,32,41,0,72,135,36,179,0,48,
		88,0,95,1,112,0,31,86,36,180,0,96,2,0,
		106,20,32,46,97,110,100,46,32,99,67,111,100,65,
		99,116,32,62,61,32,34,0,176,26,0,48,89,0,
		95,1,112,0,12,1,72,106,21,34,32,46,97,110,
		100,46,32,99,67,111,100,65,99,116,32,60,61,32,
		34,0,72,176,26,0,48,90,0,95,1,112,0,12,
		1,72,106,2,34,0,72,135,36,183,0,176,47,0,
		48,91,0,48,92,0,95,1,112,0,112,0,12,1,
		31,32,36,184,0,96,2,0,106,8,32,46,97,110,
		100,46,32,0,48,91,0,48,92,0,95,1,112,0,
		112,0,72,135,36,187,0,48,22,0,48,41,0,95,
		1,112,0,176,93,0,12,0,176,94,0,48,95,0,
		48,41,0,95,1,112,0,112,0,12,1,48,96,0,
		48,41,0,95,1,112,0,112,0,95,2,100,100,100,
		100,100,100,100,120,112,12,73,36,189,0,48,72,0,
		48,73,0,95,1,112,0,48,97,0,48,41,0,95,
		1,112,0,112,0,112,1,73,36,195,0,48,98,0,
		48,41,0,95,1,112,0,112,0,73,36,197,0,48,
		99,0,95,1,112,0,32,37,3,48,100,0,48,41,
		0,95,1,112,0,112,0,32,22,3,36,199,0,176,
		101,0,48,102,0,48,41,0,95,1,112,0,112,0,
		48,103,0,95,1,112,0,12,2,29,213,2,36,202,
		0,48,104,0,48,38,0,95,1,112,0,48,102,0,
		48,41,0,95,1,112,0,112,0,176,7,0,48,105,
		0,48,41,0,95,1,112,0,112,0,12,1,72,48,
		106,0,48,41,0,95,1,112,0,112,0,72,112,1,
		29,152,2,48,84,0,95,1,112,0,31,58,48,107,
		0,48,38,0,95,1,112,0,112,0,176,26,0,48,
		86,0,95,1,112,0,12,1,16,29,115,2,48,107,
		0,48,38,0,95,1,112,0,112,0,176,26,0,48,
		87,0,95,1,112,0,12,1,34,29,87,2,36,204,
		0,48,108,0,48,25,0,95,1,112,0,112,0,73,
		36,206,0,48,109,0,48,25,0,95,1,112,0,48,
		110,0,48,41,0,95,1,112,0,112,0,112,1,73,
		36,207,0,48,111,0,48,25,0,95,1,112,0,176,
		112,0,48,110,0,48,41,0,95,1,112,0,112,0,
		48,43,0,95,1,112,0,106,8,99,68,101,115,65,
		99,116,0,12,3,112,1,73,36,208,0,48,113,0,
		48,25,0,95,1,112,0,48,102,0,48,41,0,95,
		1,112,0,112,0,106,2,47,0,72,176,85,0,176,
		7,0,48,105,0,48,41,0,95,1,112,0,112,0,
		12,1,12,1,72,106,2,47,0,72,48,106,0,48,
		41,0,95,1,112,0,112,0,72,112,1,73,36,209,
		0,48,114,0,48,25,0,95,1,112,0,48,107,0,
		48,38,0,95,1,112,0,112,0,112,1,73,36,210,
		0,48,115,0,48,25,0,95,1,112,0,176,112,0,
		48,107,0,48,38,0,95,1,112,0,112,0,48,116,
		0,95,1,112,0,106,7,84,105,116,117,108,111,0,
		12,3,112,1,73,36,211,0,48,117,0,48,25,0,
		95,1,112,0,176,112,0,48,107,0,48,38,0,95,
		1,112,0,112,0,48,116,0,95,1,112,0,106,8,
		99,80,101,114,67,116,111,0,12,3,112,1,73,36,
		212,0,48,118,0,48,25,0,95,1,112,0,176,112,
		0,48,107,0,48,38,0,95,1,112,0,112,0,48,
		116,0,95,1,112,0,106,9,84,101,108,101,102,111,
		110,111,0,12,3,112,1,73,36,213,0,48,119,0,
		48,25,0,95,1,112,0,176,112,0,48,107,0,48,
		38,0,95,1,112,0,112,0,48,116,0,95,1,112,
		0,106,6,77,111,118,105,108,0,12,3,112,1,73,
		36,214,0,48,120,0,48,25,0,95,1,112,0,176,
		112,0,48,107,0,48,38,0,95,1,112,0,112,0,
		48,116,0,95,1,112,0,106,4,70,97,120,0,12,
		3,112,1,73,36,215,0,48,121,0,48,25,0,95,
		1,112,0,48,122,0,48,41,0,95,1,112,0,112,
		0,112,1,73,36,216,0,48,123,0,48,25,0,95,
		1,112,0,48,124,0,48,41,0,95,1,112,0,112,
		0,112,1,73,36,217,0,48,125,0,48,25,0,95,
		1,112,0,48,126,0,48,41,0,95,1,112,0,112,
		0,112,1,73,36,218,0,48,127,0,48,25,0,95,
		1,112,0,48,128,0,48,41,0,95,1,112,0,112,
		0,112,1,73,36,219,0,48,129,0,48,25,0,95,
		1,112,0,48,130,0,48,41,0,95,1,112,0,112,
		0,112,1,73,36,221,0,48,131,0,48,25,0,95,
		1,112,0,112,0,73,36,227,0,48,132,0,48,41,
		0,95,1,112,0,112,0,73,36,229,0,48,133,0,
		48,73,0,95,1,112,0,112,0,73,26,212,252,36,
		233,0,48,134,0,48,41,0,95,1,112,0,176,93,
		0,12,0,176,94,0,48,95,0,48,41,0,95,1,
		112,0,112,0,12,1,112,2,73,36,235,0,48,133,
		0,48,73,0,95,1,112,0,48,74,0,48,41,0,
		95,1,112,0,112,0,112,1,73,36,237,0,48,77,
		0,48,76,0,95,1,112,0,112,0,73,36,239,0,
		48,74,0,48,25,0,95,1,112,0,112,0,121,15,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,137,0,2,0,116,137,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

