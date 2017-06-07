/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\Tiremage.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( INFREMAGE );
HB_FUNC_EXTERN( AADD );
HB_FUNC( TINFREMAGE );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( RTRIM );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TINFGEN );
HB_FUNC_STATIC( TINFREMAGE_OPENFILES );
HB_FUNC_STATIC( TINFREMAGE_RESOURCE );
HB_FUNC_STATIC( TINFREMAGE_LGENERATE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( CPATDAT );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( RETCLIENT );
HB_FUNC_EXTERN( NTOTRECCLI );
HB_FUNC_EXTERN( CDIVEMP );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TIREMAGE )
{ "INFREMAGE", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( INFREMAGE )}, NULL },
{ "GETSTATUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "CPICOUT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TINFREMAGE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( TINFREMAGE )}, NULL },
{ "_OREMAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OFACCLIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OCLIENTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OAGENTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDGROUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "NNUMCOB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSUFCOB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( RTRIM )}, NULL },
{ "CNOMAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETSTATUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TINFGEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( TINFGEN )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TINFREMAGE_OPENFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TINFREMAGE_OPENFILES )}, NULL },
{ "TINFREMAGE_RESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TINFREMAGE_RESOURCE )}, NULL },
{ "TINFREMAGE_LGENERATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TINFREMAGE_LGENERATE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBFDIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWOPEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "CPATDAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATDAT )}, NULL },
{ "ADDBAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFDIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NCOBDES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OREMAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NCOBHAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CSUFDES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CSUFHAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDEFFECINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDEFDIVINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDEFSERINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STDRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LLOADDIVISA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "NCOBDES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADIALOGS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OFLD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSUFDES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCOBHAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSUFHAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DISABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ZAP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_AHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "SEEK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OFACCLIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "APPEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLANK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NNUMCOB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CSUFCOB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNUMREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSERIE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NNUMFAC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSUFFAC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NNUMREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DFECREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DPRECOB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RETCLIENT", {HB_FS_PUBLIC}, {HB_FUNCNAME( RETCLIENT )}, NULL },
{ "OCLIENTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NIMPREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOTRECCLI", {HB_FS_PUBLIC}, {HB_FUNCNAME( NTOTRECCLI )}, NULL },
{ "CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDIVEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDIVEMP )}, NULL },
{ "SAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OMTRINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDKEYNO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LASTREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TIREMAGE, ".\\.\\Prg\\Tiremage.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TIREMAGE
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TIREMAGE )
   #include "hbiniseg.h"
#endif

HB_FUNC( INFREMAGE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,5,36,11,0,4,0,0,80,7,36,12,0,
		4,0,0,80,8,36,14,0,48,1,0,95,1,112,
		0,73,36,16,0,176,2,0,95,7,106,8,78,78,
		85,77,67,79,66,0,106,2,78,0,92,9,121,90,
		8,106,3,64,33,0,6,106,7,78,250,109,101,114,
		111,0,9,106,17,78,250,109,101,114,111,32,100,101,
		108,32,99,111,98,114,111,0,92,9,4,9,0,20,
		2,36,17,0,176,2,0,95,7,106,8,67,83,85,
		70,67,79,66,0,106,2,67,0,92,2,121,90,8,
		106,3,64,33,0,6,106,5,83,117,102,46,0,9,
		106,17,83,117,102,105,106,111,32,100,101,108,32,99,
		111,98,114,111,0,92,2,4,9,0,20,2,36,18,
		0,176,2,0,95,7,106,8,67,67,79,68,65,71,
		69,0,106,2,67,0,92,3,121,90,8,106,3,64,
		33,0,6,106,5,65,103,101,46,0,9,106,14,67,
		243,100,105,103,111,32,97,103,101,110,116,101,0,92,
		6,4,9,0,20,2,36,19,0,176,2,0,95,7,
		106,8,67,78,79,77,65,71,69,0,106,2,67,0,
		92,40,121,90,8,106,3,64,33,0,6,106,7,65,
		103,101,110,116,101,0,9,106,14,78,111,109,98,114,
		101,32,97,103,101,110,116,101,0,92,20,4,9,0,
		20,2,36,20,0,176,2,0,95,7,106,8,67,78,
		85,77,82,69,67,0,106,2,67,0,92,18,121,90,
		8,106,3,64,33,0,6,106,7,82,101,99,105,98,
		111,0,120,106,7,82,101,99,105,98,111,0,92,18,
		4,9,0,20,2,36,21,0,176,2,0,95,7,106,
		8,68,70,69,67,82,69,67,0,106,2,68,0,92,
		8,121,90,6,106,1,0,6,106,6,70,101,99,104,
		97,0,120,106,6,70,101,99,104,97,0,92,10,4,
		9,0,20,2,36,22,0,176,2,0,95,7,106,8,
		67,67,79,68,67,76,73,0,106,2,67,0,92,12,
		121,90,6,106,1,0,6,106,10,67,111,100,46,32,
		67,108,105,46,0,120,106,18,67,243,100,105,103,111,
		32,100,101,32,99,108,105,101,110,116,101,0,92,10,
		4,9,0,20,2,36,23,0,176,2,0,95,7,106,
		8,67,78,79,77,67,76,73,0,106,2,67,0,92,
		40,121,90,6,106,1,0,6,106,10,78,111,109,46,
		32,67,108,105,46,0,120,106,18,78,111,109,98,114,
		101,32,100,101,32,99,108,105,101,110,116,101,0,92,
		36,4,9,0,20,2,36,24,0,176,2,0,95,7,
		106,8,78,73,77,80,82,69,67,0,106,2,78,0,
		92,19,92,6,89,17,0,0,0,1,0,6,0,48,
		3,0,95,255,112,0,6,106,8,73,109,112,111,114,
		116,101,0,120,106,8,73,109,112,111,114,116,101,0,
		92,12,4,9,0,20,2,36,26,0,176,2,0,95,
		8,106,8,78,78,85,77,67,79,66,0,106,25,83,
		116,114,40,32,78,78,85,77,67,79,66,32,41,32,
		43,32,67,83,85,70,67,79,66,0,4,2,0,20,
		2,36,28,0,48,4,0,176,5,0,12,0,106,19,
		82,101,109,101,115,97,115,32,100,101,32,97,103,101,
		110,116,101,115,0,95,7,95,8,106,6,48,49,48,
		52,52,0,112,4,80,6,36,30,0,48,6,0,95,
		6,95,1,112,1,73,36,31,0,48,7,0,95,6,
		95,2,112,1,73,36,32,0,48,8,0,95,6,95,
		3,112,1,73,36,33,0,48,9,0,95,6,95,4,
		112,1,73,36,34,0,48,10,0,95,6,95,5,112,
		1,73,36,36,0,48,11,0,95,6,89,40,0,0,
		0,1,0,6,0,176,12,0,48,13,0,48,14,0,
		95,255,112,0,112,0,12,1,48,15,0,48,14,0,
		95,255,112,0,112,0,72,6,89,90,0,0,0,1,
		0,6,0,106,11,82,101,109,101,115,97,115,32,58,
		32,0,176,16,0,176,12,0,48,13,0,48,14,0,
		95,255,112,0,112,0,12,1,12,1,72,106,2,47,
		0,72,48,15,0,48,14,0,95,255,112,0,112,0,
		72,106,10,32,65,103,101,110,116,101,58,32,0,72,
		48,17,0,48,14,0,95,255,112,0,112,0,72,6,
		90,20,106,15,84,111,116,97,108,32,99,111,98,114,
		111,46,46,46,0,6,112,3,73,36,38,0,48,18,
		0,95,6,112,0,73,36,40,0,48,19,0,95,6,
		112,0,73,36,42,0,48,20,0,95,6,112,0,73,
		36,44,0,48,21,0,95,1,112,0,73,36,46,0,
		100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( TINFREMAGE )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,105,0,36,50,0,103,2,0,100,8,
		29,25,2,176,22,0,104,2,0,12,1,29,14,2,
		166,208,1,0,122,80,1,48,4,0,176,23,0,12,
		0,106,11,84,73,110,102,82,101,109,65,103,101,0,
		108,24,4,1,0,108,5,112,3,80,2,36,52,0,
		48,25,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,8,110,67,111,98,68,101,115,0,4,1,0,
		9,112,5,73,36,53,0,48,25,0,95,2,100,100,
		95,1,121,72,121,72,121,72,106,8,110,67,111,98,
		72,97,115,0,4,1,0,9,112,5,73,36,54,0,
		48,25,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,8,99,83,117,102,68,101,115,0,4,1,0,
		9,112,5,73,36,55,0,48,25,0,95,2,100,100,
		95,1,121,72,121,72,121,72,106,8,99,83,117,102,
		72,97,115,0,4,1,0,9,112,5,73,36,56,0,
		48,25,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,8,111,82,101,109,65,103,101,0,4,1,0,
		9,112,5,73,36,57,0,48,25,0,95,2,100,100,
		95,1,121,72,121,72,121,72,106,9,111,70,97,99,
		67,108,105,80,0,4,1,0,9,112,5,73,36,58,
		0,48,25,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,10,111,67,108,105,101,110,116,101,115,0,
		4,1,0,9,112,5,73,36,59,0,48,25,0,95,
		2,100,100,95,1,121,72,121,72,121,72,106,9,111,
		65,103,101,110,116,101,115,0,4,1,0,9,112,5,
		73,36,60,0,48,25,0,95,2,100,100,95,1,121,
		72,121,72,121,72,106,5,111,68,105,118,0,4,1,
		0,9,112,5,73,36,62,0,48,26,0,95,2,106,
		10,79,112,101,110,70,105,108,101,115,0,108,27,95,
		1,121,72,121,72,121,72,112,3,73,36,64,0,48,
		26,0,95,2,106,9,82,101,115,111,117,114,99,101,
		0,108,28,95,1,121,72,121,72,121,72,112,3,73,
		36,66,0,48,26,0,95,2,106,10,108,71,101,110,
		101,114,97,116,101,0,108,29,95,1,121,72,121,72,
		121,72,112,3,73,36,68,0,48,30,0,95,2,112,
		0,73,167,14,0,0,176,31,0,104,2,0,95,2,
		20,2,168,48,32,0,95,2,112,0,80,3,176,33,
		0,95,3,106,10,73,110,105,116,67,108,97,115,115,
		0,12,2,28,12,48,34,0,95,3,164,146,1,0,
		73,95,3,110,7,48,32,0,103,2,0,112,0,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TINFREMAGE_OPENFILES )
{
	static const HB_BYTE pcode[] =
	{
		36,74,0,48,35,0,102,48,36,0,176,37,0,106,
		12,68,73,86,73,83,65,83,46,68,66,70,0,100,
		12,2,106,12,68,73,86,73,83,65,83,46,68,66,
		70,0,100,176,38,0,12,0,100,176,39,0,12,0,
		9,120,9,9,112,9,112,1,73,48,40,0,48,41,
		0,102,112,0,106,12,68,73,86,73,83,65,83,46,
		67,68,88,0,112,1,73,48,40,0,48,41,0,102,
		112,0,112,0,73,48,42,0,48,41,0,102,112,0,
		112,0,73,36,76,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TINFREMAGE_RESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,80,0,102,80,2,36,82,0,48,43,
		0,95,2,48,13,0,48,44,0,95,2,112,0,112,
		0,112,1,73,36,83,0,48,45,0,95,2,48,13,
		0,48,44,0,95,2,112,0,112,0,112,1,73,36,
		84,0,48,46,0,95,2,48,15,0,48,44,0,95,
		2,112,0,112,0,112,1,73,36,85,0,48,47,0,
		95,2,48,15,0,48,44,0,95,2,112,0,112,0,
		112,1,73,36,87,0,48,48,0,95,2,9,112,1,
		73,36,88,0,48,49,0,95,2,9,112,1,73,36,
		89,0,48,50,0,95,2,9,112,1,73,36,91,0,
		48,51,0,95,2,106,14,73,78,70,95,71,69,78,
		79,82,68,67,65,82,0,112,1,31,8,36,92,0,
		9,110,7,36,95,0,48,52,0,95,2,112,0,73,
		36,105,0,48,53,0,176,54,0,12,0,92,100,89,
		37,0,1,0,1,0,2,0,176,55,0,12,0,121,
		8,28,11,48,56,0,95,255,112,0,25,11,48,43,
		0,95,255,95,1,112,1,6,48,57,0,48,58,0,
		95,2,112,0,112,0,122,1,100,106,10,57,57,57,
		57,57,57,57,57,57,0,100,100,100,100,100,100,9,
		100,100,9,120,100,100,100,100,100,100,100,100,100,112,
		25,73,36,109,0,48,53,0,176,54,0,12,0,92,
		110,89,37,0,1,0,1,0,2,0,176,55,0,12,
		0,121,8,28,11,48,59,0,95,255,112,0,25,11,
		48,46,0,95,255,95,1,112,1,6,48,57,0,48,
		58,0,95,2,112,0,112,0,122,1,100,100,100,100,
		100,100,100,100,9,100,100,9,9,100,100,100,100,100,
		100,100,100,100,112,25,73,36,115,0,48,53,0,176,
		54,0,12,0,92,120,89,37,0,1,0,1,0,2,
		0,176,55,0,12,0,121,8,28,11,48,60,0,95,
		255,112,0,25,11,48,45,0,95,255,95,1,112,1,
		6,48,57,0,48,58,0,95,2,112,0,112,0,122,
		1,100,106,10,57,57,57,57,57,57,57,57,57,0,
		100,100,100,100,100,100,9,100,100,9,120,100,100,100,
		100,100,100,100,100,100,112,25,73,36,119,0,48,53,
		0,176,54,0,12,0,93,130,0,89,37,0,1,0,
		1,0,2,0,176,55,0,12,0,121,8,28,11,48,
		61,0,95,255,112,0,25,11,48,47,0,95,255,95,
		1,112,1,6,48,57,0,48,58,0,95,2,112,0,
		112,0,122,1,100,100,100,100,100,100,100,100,9,100,
		100,9,9,100,100,100,100,100,100,100,100,100,112,25,
		73,36,121,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TINFREMAGE_LGENERATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,128,0,102,80,1,36,130,0,48,62,
		0,48,63,0,95,1,112,0,112,0,73,36,132,0,
		48,64,0,48,14,0,95,1,112,0,112,0,73,36,
		135,0,48,65,0,95,1,90,25,106,9,70,101,99,
		104,97,32,58,32,0,176,66,0,176,67,0,12,0,
		12,1,72,6,89,90,0,0,0,1,0,1,0,106,
		9,82,97,110,103,111,32,58,32,0,176,68,0,176,
		12,0,48,56,0,95,255,112,0,12,1,106,2,47,
		0,72,48,59,0,95,255,112,0,72,12,1,72,106,
		4,32,62,32,0,72,176,68,0,176,12,0,48,60,
		0,95,255,112,0,12,1,106,2,47,0,72,48,61,
		0,95,255,112,0,72,12,1,72,6,4,2,0,112,
		1,73,36,137,0,48,69,0,48,44,0,95,1,112,
		0,176,12,0,48,56,0,95,1,112,0,12,1,48,
		59,0,95,1,112,0,72,112,1,29,152,2,36,139,
		0,176,12,0,48,13,0,48,44,0,95,1,112,0,
		112,0,12,1,48,15,0,48,44,0,95,1,112,0,
		112,0,72,176,12,0,48,60,0,95,1,112,0,12,
		1,48,61,0,95,1,112,0,72,34,29,95,2,48,
		70,0,48,44,0,95,1,112,0,112,0,32,80,2,
		36,145,0,48,69,0,48,71,0,95,1,112,0,176,
		12,0,48,13,0,48,44,0,95,1,112,0,112,0,
		12,1,48,15,0,48,44,0,95,1,112,0,112,0,
		72,112,1,29,241,1,36,147,0,176,12,0,48,13,
		0,48,71,0,95,1,112,0,112,0,12,1,48,15,
		0,48,71,0,95,1,112,0,112,0,72,176,12,0,
		48,13,0,48,44,0,95,1,112,0,112,0,12,1,
		48,15,0,48,44,0,95,1,112,0,112,0,72,8,
		29,174,1,48,70,0,48,71,0,95,1,112,0,112,
		0,32,159,1,36,149,0,48,72,0,48,14,0,95,
		1,112,0,112,0,73,36,150,0,48,73,0,48,14,
		0,95,1,112,0,112,0,73,36,152,0,48,74,0,
		48,14,0,95,1,112,0,48,13,0,48,71,0,95,
		1,112,0,112,0,112,1,73,36,153,0,48,75,0,
		48,14,0,95,1,112,0,48,15,0,48,71,0,95,
		1,112,0,112,0,112,1,73,36,154,0,48,76,0,
		48,14,0,95,1,112,0,48,77,0,48,44,0,95,
		1,112,0,112,0,112,1,73,36,155,0,48,78,0,
		48,14,0,95,1,112,0,48,17,0,48,44,0,95,
		1,112,0,112,0,112,1,73,36,156,0,48,79,0,
		48,14,0,95,1,112,0,48,80,0,48,71,0,95,
		1,112,0,112,0,106,2,47,0,72,176,12,0,48,
		81,0,48,71,0,95,1,112,0,112,0,12,1,72,
		106,2,47,0,72,48,82,0,48,71,0,95,1,112,
		0,112,0,72,106,2,45,0,72,176,12,0,48,83,
		0,48,71,0,95,1,112,0,112,0,12,1,72,112,
		1,73,36,157,0,48,84,0,48,14,0,95,1,112,
		0,48,85,0,48,71,0,95,1,112,0,112,0,112,
		1,73,36,158,0,48,86,0,48,14,0,95,1,112,
		0,48,87,0,48,71,0,95,1,112,0,112,0,112,
		1,73,36,159,0,48,88,0,48,14,0,95,1,112,
		0,176,89,0,48,87,0,48,71,0,95,1,112,0,
		112,0,48,90,0,95,1,112,0,12,2,112,1,73,
		36,160,0,48,91,0,48,14,0,95,1,112,0,176,
		92,0,48,71,0,95,1,112,0,48,93,0,48,94,
		0,95,1,112,0,112,0,176,95,0,12,0,12,3,
		112,1,73,36,162,0,48,96,0,48,14,0,95,1,
		112,0,112,0,73,36,164,0,48,97,0,48,71,0,
		95,1,112,0,112,0,73,26,21,254,36,170,0,48,
		97,0,48,44,0,95,1,112,0,112,0,73,36,171,
		0,48,98,0,48,99,0,95,1,112,0,48,100,0,
		48,44,0,95,1,112,0,112,0,112,1,73,26,110,
		253,36,177,0,48,101,0,48,63,0,95,1,112,0,
		112,0,73,36,179,0,48,102,0,48,14,0,95,1,
		112,0,112,0,121,15,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,105,0,2,0,116,105,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

