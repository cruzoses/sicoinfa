/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\InfNotas.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( INFNOTAS );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TINFGEN );
HB_FUNC_STATIC( INFNOTAS_CREATE );
HB_FUNC_STATIC( INFNOTAS_LRESOURCE );
HB_FUNC_STATIC( INFNOTAS_LGENERATE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( CCURUSR );
HB_FUNC_EXTERN( GETFILENOEXT );
HB_FUNC_EXTERN( CTEXTDOCUMENT );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_INFNOTAS )
{ "INFNOTAS", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( INFNOTAS )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TINFGEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( TINFGEN )}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INFNOTAS_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( INFNOTAS_CREATE )}, NULL },
{ "INFNOTAS_LRESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( INFNOTAS_LRESOURCE )}, NULL },
{ "INFNOTAS_LGENERATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( INFNOTAS_LGENERATE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDTMPINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDEFDIVINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDEFSERINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STDRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETTOTAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OMTRINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LASTREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "XOTHERS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATEFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RECNO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DISABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OBTNCANCEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ZAP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_AHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "DINIINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DFININF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDSETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "CEXPRESIONFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCURUSR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CCURUSR )}, NULL },
{ "GETFILENOEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETFILENOEXT )}, NULL },
{ "CFILE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LBREAK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DFECNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "APPEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DFECNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CHORNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHORNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CTEXNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTEXNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NINTNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CINTNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CINTNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMBRE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CNOMNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CTIPNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTIPNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DVCTNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DVCTNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CESTNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CESTNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CUSRNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CUSRNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CTIPDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTEXTDOCUMENT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CTEXTDOCUMENT )}, NULL },
{ "CTIPDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNUMDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CNUMDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_MDESNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDESNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_MOBSNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "COBSNOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDKEYNO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "IDXDELETE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_INFNOTAS, ".\\.\\Prg\\InfNotas.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_INFNOTAS
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_INFNOTAS )
   #include "hbiniseg.h"
#endif

HB_FUNC( INFNOTAS )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,85,0,36,8,0,103,2,0,100,8,
		29,217,0,176,1,0,104,2,0,12,1,29,206,0,
		166,144,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,9,73,110,102,78,111,116,97,115,0,108,4,
		4,1,0,108,0,112,3,80,2,36,10,0,48,5,
		0,95,2,106,7,67,114,101,97,116,101,0,108,6,
		95,1,121,72,121,72,121,72,112,3,73,36,12,0,
		48,5,0,95,2,106,10,108,82,101,115,111,117,114,
		99,101,0,108,7,95,1,121,72,121,72,121,72,112,
		3,73,36,14,0,48,5,0,95,2,106,10,108,71,
		101,110,101,114,97,116,101,0,108,8,95,1,121,72,
		121,72,121,72,112,3,73,36,16,0,48,9,0,95,
		2,112,0,73,167,14,0,0,176,10,0,104,2,0,
		95,2,20,2,168,48,11,0,95,2,112,0,80,3,
		176,12,0,95,3,106,10,73,110,105,116,67,108,97,
		115,115,0,12,2,28,12,48,13,0,95,3,164,146,
		1,0,73,95,3,110,7,48,11,0,103,2,0,112,
		0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( INFNOTAS_CREATE )
{
	static const HB_BYTE pcode[] =
	{
		36,22,0,48,14,0,102,106,8,100,70,101,99,78,
		111,116,0,106,2,68,0,92,8,121,90,8,106,3,
		64,33,0,6,106,6,70,101,99,104,97,0,120,106,
		6,70,101,99,104,97,0,92,12,112,9,73,36,23,
		0,48,14,0,102,106,8,99,72,111,114,78,111,116,
		0,106,2,67,0,92,4,121,90,8,106,3,64,33,
		0,6,106,5,72,111,114,97,0,9,106,5,72,111,
		114,97,0,92,10,112,9,73,36,24,0,48,14,0,
		102,106,8,99,84,101,120,78,111,116,0,106,2,67,
		0,92,100,121,90,8,106,3,64,33,0,6,106,7,
		65,115,117,110,116,111,0,120,106,7,65,115,117,110,
		116,111,0,92,50,112,9,73,36,25,0,48,14,0,
		102,106,8,99,73,110,116,78,111,116,0,106,2,67,
		0,92,35,121,90,8,106,3,64,33,0,6,106,11,
		73,110,116,101,114,101,115,97,100,111,0,9,106,11,
		73,110,116,101,114,101,115,97,100,111,0,92,20,112,
		9,73,36,26,0,48,14,0,102,106,8,99,67,111,
		100,105,103,111,0,106,2,67,0,92,12,121,90,8,
		106,3,64,33,0,6,106,7,67,243,100,105,103,111,
		0,120,106,7,67,243,100,105,103,111,0,92,12,112,
		9,73,36,27,0,48,14,0,102,106,8,99,78,111,
		109,98,114,101,0,106,2,67,0,92,100,121,90,8,
		106,3,64,33,0,6,106,7,78,111,109,98,114,101,
		0,120,106,7,78,111,109,98,114,101,0,92,35,112,
		9,73,36,28,0,48,14,0,102,106,8,99,84,105,
		112,78,111,116,0,106,2,67,0,92,30,121,90,8,
		106,3,64,33,0,6,106,5,84,105,112,111,0,120,
		106,5,84,105,112,111,0,92,20,112,9,73,36,29,
		0,48,14,0,102,106,8,100,86,99,116,78,111,116,
		0,106,2,68,0,92,8,121,90,8,106,3,64,33,
		0,6,106,8,86,101,110,99,105,109,46,0,9,106,
		12,86,101,110,99,105,109,105,101,110,116,111,0,92,
		12,112,9,73,36,30,0,48,14,0,102,106,8,99,
		69,115,116,78,111,116,0,106,2,67,0,92,50,121,
		90,8,106,3,64,33,0,6,106,7,69,115,116,97,
		100,111,0,120,106,7,69,115,116,97,100,111,0,92,
		25,112,9,73,36,31,0,48,14,0,102,106,8,99,
		85,115,114,78,111,116,0,106,2,67,0,92,3,121,
		90,8,106,3,64,33,0,6,106,8,85,115,117,97,
		114,105,111,0,9,106,8,85,115,117,97,114,105,111,
		0,92,5,112,9,73,36,32,0,48,14,0,102,106,
		8,99,84,105,112,68,111,99,0,106,2,67,0,92,
		20,121,90,8,106,3,64,33,0,6,106,10,84,105,
		112,111,32,100,111,99,46,0,9,106,18,84,105,112,
		111,32,100,101,32,100,111,99,117,109,101,110,116,111,
		0,92,20,112,9,73,36,33,0,48,14,0,102,106,
		8,99,78,117,109,68,111,99,0,106,2,67,0,92,
		12,121,90,8,106,3,64,33,0,6,106,10,68,111,
		99,117,109,101,110,116,111,0,120,106,10,68,111,99,
		117,109,101,110,116,111,0,92,18,112,9,73,36,34,
		0,48,14,0,102,106,8,109,68,101,115,78,111,116,
		0,106,2,77,0,92,10,121,90,8,106,3,64,33,
		0,6,106,9,68,101,115,99,114,105,112,46,0,9,
		106,17,84,101,120,116,111,32,108,97,114,103,111,32,
		110,111,116,97,0,92,20,112,9,73,36,35,0,48,
		14,0,102,106,8,109,79,98,115,78,111,116,0,106,
		2,77,0,92,10,121,90,8,106,3,64,33,0,6,
		106,9,79,98,115,101,114,118,97,46,0,9,106,14,
		79,98,115,101,114,118,97,99,105,111,110,101,115,0,
		92,20,112,9,73,36,37,0,48,15,0,102,106,8,
		100,70,101,99,78,111,116,0,106,8,100,70,101,99,
		78,111,116,0,112,2,73,36,39,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( INFNOTAS_LRESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,45,0,48,16,0,102,9,112,1,73,
		36,46,0,48,17,0,102,9,112,1,73,36,48,0,
		48,18,0,102,106,10,73,78,70,95,69,78,84,48,
		49,0,112,1,31,8,36,49,0,9,110,7,36,52,
		0,48,19,0,48,20,0,102,112,0,48,21,0,48,
		22,0,102,112,0,112,0,112,1,73,36,54,0,48,
		23,0,102,100,48,22,0,102,112,0,112,2,73,36,
		56,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( INFNOTAS_LGENERATE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,0,36,63,0,102,80,1,36,65,0,48,24,
		0,48,22,0,95,1,112,0,112,0,80,2,36,66,
		0,106,1,0,80,3,36,68,0,48,25,0,48,26,
		0,95,1,112,0,112,0,73,36,69,0,48,27,0,
		48,28,0,95,1,112,0,112,0,73,36,70,0,48,
		29,0,48,30,0,95,1,112,0,112,0,73,36,73,
		0,48,31,0,95,1,90,29,106,13,70,101,99,104,
		97,32,32,32,32,32,58,32,0,176,32,0,176,33,
		0,12,0,12,1,72,6,89,58,0,0,0,1,0,
		1,0,106,13,80,101,114,105,111,100,111,32,32,32,
		58,32,0,176,32,0,48,34,0,95,255,112,0,12,
		1,72,106,4,32,62,32,0,72,176,32,0,48,35,
		0,95,255,112,0,12,1,72,6,4,2,0,112,1,
		73,36,75,0,48,36,0,48,22,0,95,1,112,0,
		106,8,68,70,69,67,78,79,84,0,112,1,73,36,
		77,0,176,37,0,48,38,0,48,39,0,95,1,112,
		0,112,0,12,1,31,21,36,78,0,48,38,0,48,
		39,0,95,1,112,0,112,0,80,3,25,13,36,80,
		0,106,4,46,116,46,0,80,3,36,83,0,48,15,
		0,48,22,0,95,1,112,0,176,40,0,12,0,176,
		41,0,48,42,0,48,22,0,95,1,112,0,112,0,
		12,1,48,43,0,48,22,0,95,1,112,0,112,0,
		95,3,100,100,100,100,100,100,100,120,112,12,73,36,
		85,0,48,44,0,48,22,0,95,1,112,0,112,0,
		73,36,87,0,48,45,0,95,1,112,0,32,244,2,
		48,46,0,48,22,0,95,1,112,0,112,0,32,229,
		2,36,89,0,48,47,0,48,22,0,95,1,112,0,
		112,0,48,34,0,95,1,112,0,16,29,156,2,48,
		47,0,48,22,0,95,1,112,0,112,0,48,35,0,
		95,1,112,0,34,29,133,2,36,91,0,48,48,0,
		48,30,0,95,1,112,0,112,0,73,36,93,0,48,
		49,0,48,30,0,95,1,112,0,48,47,0,48,22,
		0,95,1,112,0,112,0,112,1,73,36,94,0,48,
		50,0,48,30,0,95,1,112,0,48,51,0,48,22,
		0,95,1,112,0,112,0,112,1,73,36,95,0,48,
		52,0,48,30,0,95,1,112,0,48,53,0,48,22,
		0,95,1,112,0,112,0,112,1,73,36,98,0,48,
		54,0,48,22,0,95,1,112,0,112,0,122,8,28,
		31,36,99,0,48,55,0,48,30,0,95,1,112,0,
		106,8,67,108,105,101,110,116,101,0,112,1,73,26,
		196,0,36,100,0,48,54,0,48,22,0,95,1,112,
		0,112,0,92,2,8,28,33,36,101,0,48,55,0,
		48,30,0,95,1,112,0,106,10,80,114,111,118,101,
		101,100,111,114,0,112,1,73,26,145,0,36,102,0,
		48,54,0,48,22,0,95,1,112,0,112,0,92,3,
		8,28,31,36,103,0,48,55,0,48,30,0,95,1,
		112,0,106,9,65,114,116,237,99,117,108,111,0,112,
		1,73,25,95,36,104,0,48,54,0,48,22,0,95,
		1,112,0,112,0,92,4,8,28,29,36,105,0,48,
		55,0,48,30,0,95,1,112,0,106,7,65,103,101,
		110,116,101,0,112,1,73,25,48,36,106,0,48,54,
		0,48,22,0,95,1,112,0,112,0,92,5,8,28,
		28,36,107,0,48,55,0,48,30,0,95,1,112,0,
		106,8,65,108,109,97,99,233,110,0,112,1,73,36,
		110,0,48,56,0,48,30,0,95,1,112,0,48,57,
		0,48,22,0,95,1,112,0,112,0,112,1,73,36,
		111,0,48,58,0,48,30,0,95,1,112,0,48,59,
		0,48,22,0,95,1,112,0,112,0,112,1,73,36,
		112,0,48,60,0,48,30,0,95,1,112,0,48,61,
		0,48,22,0,95,1,112,0,112,0,112,1,73,36,
		113,0,48,62,0,48,30,0,95,1,112,0,48,63,
		0,48,22,0,95,1,112,0,112,0,112,1,73,36,
		114,0,48,64,0,48,30,0,95,1,112,0,48,65,
		0,48,22,0,95,1,112,0,112,0,112,1,73,36,
		115,0,48,66,0,48,30,0,95,1,112,0,48,67,
		0,48,22,0,95,1,112,0,112,0,112,1,73,36,
		116,0,48,68,0,48,30,0,95,1,112,0,176,69,
		0,48,70,0,48,22,0,95,1,112,0,112,0,12,
		1,112,1,73,36,117,0,48,71,0,48,30,0,95,
		1,112,0,48,72,0,48,22,0,95,1,112,0,112,
		0,112,1,73,36,118,0,48,73,0,48,30,0,95,
		1,112,0,48,74,0,48,22,0,95,1,112,0,112,
		0,112,1,73,36,119,0,48,75,0,48,30,0,95,
		1,112,0,48,76,0,48,22,0,95,1,112,0,112,
		0,112,1,73,36,121,0,48,77,0,48,30,0,95,
		1,112,0,112,0,73,36,125,0,48,78,0,48,22,
		0,95,1,112,0,112,0,73,36,127,0,48,79,0,
		48,20,0,95,1,112,0,48,80,0,48,22,0,95,
		1,112,0,112,0,112,1,73,26,5,253,36,131,0,
		48,81,0,48,22,0,95,1,112,0,176,40,0,12,
		0,176,41,0,48,42,0,48,22,0,95,1,112,0,
		112,0,12,1,112,2,73,36,133,0,48,79,0,48,
		20,0,95,1,112,0,48,21,0,48,22,0,95,1,
		112,0,112,0,112,1,73,36,135,0,48,27,0,48,
		26,0,95,1,112,0,112,0,73,36,137,0,48,82,
		0,48,22,0,95,1,112,0,95,2,112,1,73,36,
		139,0,48,21,0,48,30,0,95,1,112,0,112,0,
		121,15,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,85,0,2,0,116,85,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

