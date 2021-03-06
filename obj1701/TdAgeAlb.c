/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\TdAgeAlb.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TDAGEALB );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TINFGEN );
HB_FUNC_STATIC( TDAGEALB_CREATE );
HB_FUNC_STATIC( TDAGEALB_OPENFILES );
HB_FUNC_STATIC( TDAGEALB_CLOSEFILES );
HB_FUNC_STATIC( TDAGEALB_RESOURCE );
HB_FUNC_STATIC( TDAGEALB_LGENERATE );
HB_FUNC_STATIC( TDAGEALB_APPENDLINE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( CIMP );
HB_FUNC_EXTERN( RTRIM );
HB_FUNC_EXTERN( ORETFLD );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( APOLOBREAK );
HB_FUNC_EXTERN( TDATACENTER );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( CPATEMP );
HB_FUNC_EXTERN( CPATCLI );
HB_FUNC_EXTERN( CPATDAT );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( TCOMBOBOX );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( LCHKSER );
HB_FUNC_EXTERN( ATOTALBCLI );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( LFACTURADO );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TDAGEALB )
{ "TDAGEALB", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TDAGEALB )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TINFGEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( TINFGEN )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDAGEALB_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDAGEALB_CREATE )}, NULL },
{ "TDAGEALB_OPENFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDAGEALB_OPENFILES )}, NULL },
{ "TDAGEALB_CLOSEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDAGEALB_CLOSEFILES )}, NULL },
{ "TDAGEALB_RESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDAGEALB_RESOURCE )}, NULL },
{ "TDAGEALB_LGENERATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDAGEALB_LGENERATE )}, NULL },
{ "TDAGEALB_APPENDLINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDAGEALB_APPENDLINE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FLDCLIENTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPICOUT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CIMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CIMP )}, NULL },
{ "CPICPNT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDTMPINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDGROUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CNOMAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( RTRIM )}, NULL },
{ "ORETFLD", {HB_FS_PUBLIC}, {HB_FUNCNAME( ORETFLD )}, NULL },
{ "ODBFAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "APOLOBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( APOLOBREAK )}, NULL },
{ "_OALBCLIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OALBCLIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDATACENTER", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDATACENTER )}, NULL },
{ "_OALBCLIL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWOPEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "CPATEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATEMP )}, NULL },
{ "ADDBAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OALBCLIL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBFCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATCLI", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATCLI )}, NULL },
{ "ODBFCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBFIVA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATDAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATDAT )}, NULL },
{ "ODBFIVA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "CLOSEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "USED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STDRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODEFAGEINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETTOTAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OMTRINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LASTREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODEFRESINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OESTADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMBOBOX", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCOMBOBOX )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "CESTADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CESTADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AESTADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADIALOGS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OFLD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OORDENADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CORDENADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CORDENADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AORDENADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DISABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ZAP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_AHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "DINIINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DFININF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CAGEORG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CAGEDES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DFECALB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LCHKSER", {HB_FS_PUBLIC}, {HB_FUNCNAME( LCHKSER )}, NULL },
{ "CSERALB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ASER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ATOTALBCLI", {HB_FS_PUBLIC}, {HB_FUNCNAME( ATOTALBCLI )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "NNUMALB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSUFALB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFDIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NAT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OESTADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LFACTURADO", {HB_FS_PUBLIC}, {HB_FUNCNAME( LFACTURADO )}, NULL },
{ "APPENDLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OORDENADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDSETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "APPEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CAPEAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CNBRAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CNOMCLI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDCLIENTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DFECDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNUMDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "_NTOTNET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOTIVA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOTREQ", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOTDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOTPNT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOTTRN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NCOMAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOTCOS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NMARGEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NRENTAB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TDAGEALB, ".\\.\\Prg\\TdAgeAlb.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TDAGEALB
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TDAGEALB )
   #include "hbiniseg.h"
#endif

HB_FUNC( TDAGEALB )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,132,0,36,8,0,103,2,0,100,8,
		29,162,3,176,1,0,104,2,0,12,1,29,151,3,
		166,89,3,0,122,80,1,48,2,0,176,3,0,12,
		0,106,9,84,100,65,103,101,65,108,98,0,108,4,
		4,1,0,108,0,112,3,80,2,36,10,0,48,5,
		0,95,2,106,6,76,79,71,73,67,0,9,95,1,
		121,72,121,72,121,72,106,9,108,82,101,115,117,109,
		101,110,0,4,1,0,9,112,5,73,36,11,0,48,
		5,0,95,2,106,6,76,79,71,73,67,0,9,95,
		1,121,72,121,72,121,72,106,9,108,69,120,99,67,
		101,114,111,0,4,1,0,9,112,5,73,36,12,0,
		48,5,0,95,2,106,7,79,66,74,69,67,84,0,
		100,95,1,121,72,121,72,121,72,106,8,111,69,115,
		116,97,100,111,0,4,1,0,9,112,5,73,36,13,
		0,48,5,0,95,2,106,10,67,72,65,82,65,67,
		84,69,82,0,106,6,84,111,100,111,115,0,95,1,
		121,72,121,72,121,72,106,8,99,69,115,116,97,100,
		111,0,4,1,0,9,112,5,73,36,14,0,48,5,
		0,95,2,106,6,65,82,82,65,89,0,106,14,78,
		111,32,102,97,99,116,117,114,97,100,111,115,0,106,
		11,70,97,99,116,117,114,97,100,111,115,0,106,6,
		84,111,100,111,115,0,4,3,0,95,1,121,72,121,
		72,121,72,106,8,97,69,115,116,97,100,111,0,4,
		1,0,9,112,5,73,36,15,0,48,5,0,95,2,
		106,7,79,66,74,69,67,84,0,100,95,1,121,72,
		121,72,121,72,106,9,111,65,108,98,67,108,105,84,
		0,4,1,0,9,112,5,73,36,16,0,48,5,0,
		95,2,106,7,79,66,74,69,67,84,0,100,95,1,
		121,72,121,72,121,72,106,9,111,65,108,98,67,108,
		105,76,0,4,1,0,9,112,5,73,36,17,0,48,
		5,0,95,2,106,7,79,66,74,69,67,84,0,100,
		95,1,121,72,121,72,121,72,106,8,111,68,98,102,
		73,118,97,0,4,1,0,9,112,5,73,36,18,0,
		48,5,0,95,2,106,6,76,79,71,73,67,0,9,
		95,1,121,72,121,72,121,72,106,6,108,84,118,116,
		97,0,4,1,0,9,112,5,73,36,19,0,48,5,
		0,95,2,106,7,79,66,74,69,67,84,0,100,95,
		1,121,72,121,72,121,72,106,10,111,79,114,100,101,
		110,97,100,111,0,4,1,0,9,112,5,73,36,20,
		0,48,5,0,95,2,106,10,67,72,65,82,65,67,
		84,69,82,0,106,7,70,101,99,104,97,115,0,95,
		1,121,72,121,72,121,72,106,10,99,79,114,100,101,
		110,97,100,111,0,4,1,0,9,112,5,73,36,21,
		0,48,5,0,95,2,106,6,65,82,82,65,89,0,
		106,9,67,108,105,101,110,116,101,115,0,106,7,70,
		101,99,104,97,115,0,106,10,68,111,99,117,109,101,
		110,116,111,0,4,3,0,95,1,121,72,121,72,121,
		72,106,10,97,79,114,100,101,110,97,100,111,0,4,
		1,0,9,112,5,73,36,23,0,48,6,0,95,2,
		106,7,67,114,101,97,116,101,0,108,7,95,1,121,
		72,121,72,121,72,112,3,73,36,25,0,48,6,0,
		95,2,106,10,79,112,101,110,70,105,108,101,115,0,
		108,8,95,1,121,72,121,72,121,72,112,3,73,36,
		27,0,48,6,0,95,2,106,11,67,108,111,115,101,
		70,105,108,101,115,0,108,9,95,1,121,72,121,72,
		121,72,112,3,73,36,29,0,48,6,0,95,2,106,
		9,82,101,115,111,117,114,99,101,0,108,10,95,1,
		121,72,121,72,121,72,112,3,73,36,31,0,48,6,
		0,95,2,106,10,108,71,101,110,101,114,97,116,101,
		0,108,11,95,1,121,72,121,72,121,72,112,3,73,
		36,33,0,48,6,0,95,2,106,11,65,112,112,101,
		110,100,76,105,110,101,0,108,12,95,1,121,72,121,
		72,121,72,112,3,73,36,35,0,48,13,0,95,2,
		112,0,73,167,14,0,0,176,14,0,104,2,0,95,
		2,20,2,168,48,15,0,95,2,112,0,80,3,176,
		16,0,95,3,106,10,73,110,105,116,67,108,97,115,
		115,0,12,2,28,12,48,17,0,95,3,164,146,1,
		0,73,95,3,110,7,48,15,0,103,2,0,112,0,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDAGEALB_CREATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,39,0,102,80,1,36,41,0,48,18,
		0,95,1,106,8,99,67,111,100,65,103,101,0,106,
		2,67,0,92,3,121,90,8,106,3,64,33,0,6,
		106,10,67,243,100,46,32,97,103,101,46,0,9,106,
		12,67,111,100,46,32,97,103,101,110,116,101,0,92,
		3,112,9,73,36,42,0,48,18,0,95,1,106,8,
		99,78,111,109,65,103,101,0,106,2,67,0,92,50,
		121,90,8,106,3,64,33,0,6,106,7,65,103,101,
		110,116,101,0,9,106,12,78,111,109,46,32,97,103,
		101,110,116,101,0,92,25,112,9,73,36,43,0,48,
		19,0,95,1,112,0,73,36,44,0,48,18,0,95,
		1,106,8,99,78,117,109,68,111,99,0,106,2,67,
		0,92,12,121,90,6,106,1,0,6,106,5,68,111,
		99,46,0,120,106,10,68,111,99,117,109,101,110,116,
		111,0,92,12,112,9,73,36,45,0,48,18,0,95,
		1,106,8,100,70,101,99,68,111,99,0,106,2,68,
		0,92,8,121,90,6,106,1,0,6,106,6,70,101,
		99,104,97,0,120,106,6,70,101,99,104,97,0,92,
		12,112,9,73,36,46,0,48,18,0,95,1,106,8,
		110,84,111,116,78,101,116,0,106,2,78,0,92,16,
		92,6,89,17,0,0,0,1,0,1,0,48,20,0,
		95,255,112,0,6,106,5,78,101,116,111,0,120,106,
		5,78,101,116,111,0,92,12,112,9,73,36,47,0,
		48,18,0,95,1,106,8,110,84,111,116,73,118,97,
		0,106,2,78,0,92,16,92,6,89,17,0,0,0,
		1,0,1,0,48,20,0,95,255,112,0,6,176,21,
		0,12,0,120,176,21,0,12,0,92,12,112,9,73,
		36,48,0,48,18,0,95,1,106,8,110,84,111,116,
		82,101,113,0,106,2,78,0,92,16,92,3,89,17,
		0,0,0,1,0,1,0,48,20,0,95,255,112,0,
		6,106,4,82,101,99,0,120,106,4,82,101,99,0,
		92,12,112,9,73,36,49,0,48,18,0,95,1,106,
		8,110,84,111,116,80,110,116,0,106,2,78,0,92,
		16,92,6,89,17,0,0,0,1,0,1,0,48,22,
		0,95,255,112,0,6,106,9,80,110,116,46,86,101,
		114,46,0,120,106,12,80,117,110,116,111,32,118,101,
		114,100,101,0,92,12,112,9,73,36,50,0,48,18,
		0,95,1,106,8,110,84,111,116,84,114,110,0,106,
		2,78,0,92,16,92,6,89,17,0,0,0,1,0,
		1,0,48,20,0,95,255,112,0,6,106,8,84,114,
		97,110,115,112,46,0,120,106,11,84,114,97,110,115,
		112,111,114,116,101,0,92,12,112,9,73,36,51,0,
		48,18,0,95,1,106,8,110,84,111,116,68,111,99,
		0,106,2,78,0,92,16,92,6,89,17,0,0,0,
		1,0,1,0,48,20,0,95,255,112,0,6,106,6,
		84,111,116,97,108,0,120,106,6,84,111,116,97,108,
		0,92,12,112,9,73,36,52,0,48,18,0,95,1,
		106,8,110,84,111,116,67,111,115,0,106,2,78,0,
		92,16,92,6,89,17,0,0,0,1,0,1,0,48,
		20,0,95,255,112,0,6,106,6,67,111,115,116,111,
		0,120,106,6,67,111,115,116,111,0,92,12,112,9,
		73,36,53,0,48,18,0,95,1,106,8,110,77,97,
		114,71,101,110,0,106,2,78,0,92,16,92,6,89,
		17,0,0,0,1,0,1,0,48,20,0,95,255,112,
		0,6,106,7,77,97,114,103,101,110,0,120,106,7,
		77,97,114,103,101,110,0,92,12,112,9,73,36,54,
		0,48,18,0,95,1,106,8,110,82,101,110,84,97,
		98,0,106,2,78,0,92,16,92,6,89,17,0,0,
		0,1,0,1,0,48,20,0,95,255,112,0,6,106,
		7,37,32,82,101,110,46,0,120,106,15,37,32,114,
		101,110,116,97,98,105,108,105,100,97,100,0,92,12,
		112,9,73,36,55,0,48,18,0,95,1,106,8,110,
		67,111,109,65,103,101,0,106,2,78,0,92,13,92,
		6,89,17,0,0,0,1,0,1,0,48,20,0,95,
		255,112,0,6,106,9,67,111,109,46,65,103,101,46,
		0,120,106,16,67,111,109,105,115,105,243,110,32,97,
		103,101,110,116,101,0,92,12,112,9,73,36,57,0,
		48,23,0,95,1,106,8,99,67,111,100,67,108,105,
		0,106,18,99,67,111,100,65,103,101,32,43,32,99,
		67,111,100,67,108,105,0,112,2,73,36,58,0,48,
		23,0,95,1,106,8,99,67,111,100,70,101,99,0,
		106,26,99,67,111,100,65,103,101,32,43,32,68,116,
		111,83,40,32,100,70,101,99,68,111,99,32,41,0,
		112,2,73,36,59,0,48,23,0,95,1,106,8,99,
		67,111,100,78,117,109,0,106,18,99,67,111,100,65,
		103,101,32,43,32,99,78,117,109,68,111,99,0,112,
		2,73,36,61,0,48,24,0,95,1,89,22,0,0,
		0,1,0,1,0,48,25,0,48,26,0,95,255,112,
		0,112,0,6,89,71,0,0,0,1,0,1,0,106,
		11,65,103,101,110,116,101,32,32,58,32,0,176,27,
		0,48,25,0,48,26,0,95,255,112,0,112,0,12,
		1,72,106,2,45,0,72,176,28,0,48,25,0,48,
		26,0,95,255,112,0,112,0,48,29,0,95,255,112,
		0,12,2,72,6,90,21,106,16,84,111,116,97,108,
		32,97,103,101,110,116,101,46,46,46,0,6,112,3,
		73,36,63,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDAGEALB_OPENFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,3,0,36,71,0,120,80,3,36,77,0,176,30,
		0,89,15,0,1,0,0,0,176,31,0,95,1,12,
		1,6,12,1,80,1,36,78,0,113,105,1,0,36,
		80,0,48,32,0,102,48,33,0,176,34,0,12,0,
		112,0,112,1,73,36,82,0,48,35,0,102,48,36,
		0,176,37,0,106,12,65,76,66,67,76,73,76,46,
		68,66,70,0,100,12,2,106,12,65,76,66,67,76,
		73,76,46,68,66,70,0,100,176,38,0,12,0,100,
		176,39,0,12,0,9,120,9,9,112,9,112,1,73,
		48,40,0,48,41,0,102,112,0,106,12,65,76,66,
		67,76,73,76,46,67,68,88,0,112,1,73,48,40,
		0,48,41,0,102,112,0,112,0,73,48,42,0,48,
		41,0,102,112,0,112,0,73,36,84,0,48,43,0,
		102,48,36,0,176,37,0,106,11,67,76,73,69,78,
		84,46,68,66,70,0,100,12,2,106,11,67,76,73,
		69,78,84,46,68,66,70,0,100,176,38,0,12,0,
		100,176,44,0,12,0,9,120,9,9,112,9,112,1,
		73,48,40,0,48,45,0,102,112,0,106,11,67,76,
		73,69,78,84,46,67,68,88,0,112,1,73,48,40,
		0,48,45,0,102,112,0,112,0,73,48,42,0,48,
		45,0,102,112,0,112,0,73,36,86,0,48,46,0,
		102,48,36,0,176,37,0,106,9,84,73,86,65,46,
		68,66,70,0,100,12,2,106,9,84,73,86,65,46,
		68,66,70,0,100,176,38,0,12,0,100,176,47,0,
		12,0,9,120,9,9,112,9,112,1,73,48,40,0,
		48,48,0,102,112,0,106,9,84,73,86,65,46,67,
		68,88,0,112,1,73,48,40,0,48,48,0,102,112,
		0,112,0,73,48,42,0,48,48,0,102,112,0,112,
		0,73,114,77,0,0,36,88,0,115,80,2,36,90,
		0,9,80,3,36,92,0,176,49,0,106,41,73,109,
		112,111,115,105,98,108,101,32,97,98,114,105,114,32,
		116,111,100,97,115,32,108,97,115,32,98,97,115,101,
		115,32,100,101,32,100,97,116,111,115,0,20,1,36,
		93,0,48,50,0,102,112,0,73,36,97,0,176,30,
		0,95,1,20,1,36,99,0,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDAGEALB_CLOSEFILES )
{
	static const HB_BYTE pcode[] =
	{
		36,105,0,176,51,0,48,33,0,102,112,0,12,1,
		31,30,48,52,0,48,33,0,102,112,0,112,0,28,
		17,36,106,0,48,53,0,48,33,0,102,112,0,112,
		0,73,36,109,0,176,51,0,48,41,0,102,112,0,
		12,1,31,30,48,52,0,48,41,0,102,112,0,112,
		0,28,17,36,110,0,48,53,0,48,41,0,102,112,
		0,112,0,73,36,113,0,176,51,0,48,45,0,102,
		112,0,12,1,31,30,48,52,0,48,45,0,102,112,
		0,112,0,28,17,36,114,0,48,53,0,48,45,0,
		102,112,0,112,0,73,36,117,0,176,51,0,48,48,
		0,102,112,0,12,1,31,30,48,52,0,48,48,0,
		102,112,0,112,0,28,17,36,118,0,48,53,0,48,
		48,0,102,112,0,112,0,73,36,121,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDAGEALB_RESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,125,0,102,80,2,36,127,0,48,54,
		0,95,2,106,10,73,78,70,95,71,69,78,50,53,
		0,112,1,31,8,36,128,0,9,110,7,36,135,0,
		48,55,0,95,2,92,70,92,80,92,90,92,100,112,
		4,73,36,141,0,48,56,0,48,57,0,95,2,112,
		0,48,58,0,48,33,0,95,2,112,0,112,0,112,
		1,73,36,143,0,48,59,0,95,2,112,0,73,36,
		149,0,48,60,0,95,2,48,61,0,176,62,0,12,
		0,93,218,0,89,37,0,1,0,1,0,2,0,176,
		63,0,12,0,121,8,28,11,48,64,0,95,255,112,
		0,25,11,48,65,0,95,255,95,1,112,1,6,48,
		66,0,95,2,112,0,48,67,0,48,68,0,95,2,
		112,0,112,0,122,1,100,100,100,100,100,100,9,100,
		100,100,100,100,100,112,17,112,1,73,36,155,0,48,
		69,0,95,2,48,61,0,176,62,0,12,0,93,219,
		0,89,37,0,1,0,1,0,2,0,176,63,0,12,
		0,121,8,28,11,48,70,0,95,255,112,0,25,11,
		48,71,0,95,255,95,1,112,1,6,48,72,0,95,
		2,112,0,48,67,0,48,68,0,95,2,112,0,112,
		0,122,1,100,100,100,100,100,100,9,100,100,100,100,
		100,100,112,17,112,1,73,36,157,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDAGEALB_LGENERATE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,0,36,164,0,102,80,1,36,166,0,90,4,
		120,6,80,2,36,169,0,48,73,0,48,74,0,95,
		1,112,0,112,0,73,36,171,0,48,75,0,48,26,
		0,95,1,112,0,112,0,73,36,172,0,48,76,0,
		48,33,0,95,1,112,0,112,0,73,36,178,0,48,
		77,0,95,1,90,27,106,11,70,101,99,104,97,32,
		32,32,58,32,0,176,78,0,176,79,0,12,0,12,
		1,72,6,89,56,0,0,0,1,0,1,0,106,11,
		80,101,114,105,111,100,111,32,58,32,0,176,78,0,
		48,80,0,95,255,112,0,12,1,72,106,4,32,62,
		32,0,72,176,78,0,48,81,0,95,255,112,0,12,
		1,72,6,89,46,0,0,0,1,0,1,0,106,11,
		65,103,101,110,116,101,115,32,58,32,0,48,82,0,
		95,255,112,0,72,106,4,32,62,32,0,72,48,83,
		0,95,255,112,0,72,6,89,31,0,0,0,1,0,
		1,0,106,11,69,115,116,97,100,111,32,32,58,32,
		0,48,64,0,95,255,112,0,72,6,89,31,0,0,
		0,1,0,1,0,106,11,79,114,100,101,110,97,100,
		111,58,32,0,48,70,0,95,255,112,0,72,6,4,
		5,0,112,1,73,36,184,0,48,84,0,48,33,0,
		95,1,112,0,112,0,32,168,1,36,190,0,48,85,
		0,48,33,0,95,1,112,0,112,0,48,80,0,95,
		1,112,0,16,29,107,1,48,85,0,48,33,0,95,
		1,112,0,112,0,48,81,0,95,1,112,0,34,29,
		84,1,48,86,0,48,33,0,95,1,112,0,112,0,
		48,82,0,95,1,112,0,16,29,61,1,48,86,0,
		48,33,0,95,1,112,0,112,0,48,83,0,95,1,
		112,0,34,29,38,1,176,87,0,48,88,0,48,33,
		0,95,1,112,0,112,0,48,89,0,95,1,112,0,
		12,2,29,11,1,36,192,0,176,90,0,48,88,0,
		48,33,0,95,1,112,0,112,0,176,91,0,48,92,
		0,48,33,0,95,1,112,0,112,0,12,1,72,48,
		93,0,48,33,0,95,1,112,0,112,0,72,48,94,
		0,48,33,0,95,1,112,0,112,0,48,94,0,48,
		41,0,95,1,112,0,112,0,48,94,0,48,48,0,
		95,1,112,0,112,0,48,94,0,48,95,0,95,1,
		112,0,112,0,12,5,80,3,36,195,0,48,96,0,
		48,97,0,95,1,112,0,112,0,122,8,28,48,36,
		196,0,89,23,0,0,0,1,0,1,0,176,98,0,
		48,33,0,95,255,112,0,12,1,68,6,165,80,2,
		28,115,36,197,0,48,99,0,95,1,95,3,112,1,
		73,25,100,36,199,0,48,96,0,48,97,0,95,1,
		112,0,112,0,92,2,8,28,47,36,200,0,89,22,
		0,0,0,1,0,1,0,176,98,0,48,33,0,95,
		255,112,0,12,1,6,165,80,2,28,50,36,201,0,
		48,99,0,95,1,95,3,112,1,73,25,35,36,203,
		0,48,96,0,48,97,0,95,1,112,0,112,0,92,
		3,8,28,15,36,204,0,48,99,0,95,1,95,3,
		112,1,73,36,209,0,48,100,0,48,33,0,95,1,
		112,0,112,0,73,36,211,0,48,101,0,48,57,0,
		95,1,112,0,112,0,73,26,76,254,36,216,0,48,
		96,0,48,102,0,95,1,112,0,112,0,122,8,28,
		30,36,217,0,48,103,0,48,26,0,95,1,112,0,
		106,8,67,67,79,68,67,76,73,0,112,1,73,25,
		96,36,218,0,48,96,0,48,102,0,95,1,112,0,
		112,0,92,2,8,28,30,36,219,0,48,103,0,48,
		26,0,95,1,112,0,106,8,67,67,79,68,70,69,
		67,0,112,1,73,25,48,36,220,0,48,96,0,48,
		102,0,95,1,112,0,112,0,92,3,8,28,28,36,
		221,0,48,103,0,48,26,0,95,1,112,0,106,8,
		67,67,79,68,78,85,77,0,112,1,73,36,224,0,
		48,104,0,48,74,0,95,1,112,0,112,0,73,36,
		226,0,48,58,0,48,26,0,95,1,112,0,112,0,
		121,15,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDAGEALB_APPENDLINE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,232,0,48,105,0,48,26,0,102,112,
		0,112,0,73,36,234,0,48,106,0,48,26,0,102,
		112,0,48,86,0,48,33,0,102,112,0,112,0,112,
		1,73,36,236,0,48,107,0,48,29,0,102,112,0,
		48,86,0,48,33,0,102,112,0,112,0,112,1,28,
		51,36,237,0,48,108,0,48,26,0,102,112,0,176,
		27,0,48,109,0,48,29,0,102,112,0,112,0,12,
		1,106,3,44,32,0,72,48,110,0,48,29,0,102,
		112,0,112,0,72,112,1,73,36,240,0,48,108,0,
		48,26,0,102,112,0,48,86,0,48,33,0,102,112,
		0,112,0,112,1,73,36,241,0,48,111,0,48,26,
		0,102,112,0,48,112,0,48,33,0,102,112,0,112,
		0,112,1,73,36,242,0,48,113,0,48,26,0,102,
		112,0,48,114,0,48,33,0,102,112,0,112,0,112,
		1,73,36,244,0,48,115,0,102,48,112,0,48,33,
		0,102,112,0,112,0,48,33,0,102,112,0,9,112,
		3,73,36,246,0,176,90,0,48,88,0,48,33,0,
		102,112,0,112,0,176,91,0,48,92,0,48,33,0,
		102,112,0,112,0,12,1,72,48,93,0,48,33,0,
		102,112,0,112,0,72,48,94,0,48,33,0,102,112,
		0,112,0,48,94,0,48,41,0,102,112,0,112,0,
		48,94,0,48,48,0,102,112,0,112,0,48,94,0,
		48,95,0,102,112,0,112,0,12,5,80,1,36,248,
		0,48,116,0,48,26,0,102,112,0,48,85,0,48,
		33,0,102,112,0,112,0,112,1,73,36,249,0,48,
		117,0,48,26,0,102,112,0,48,88,0,48,33,0,
		102,112,0,112,0,106,2,47,0,72,176,118,0,176,
		91,0,48,92,0,48,33,0,102,112,0,112,0,12,
		1,12,1,72,106,2,47,0,72,48,93,0,48,33,
		0,102,112,0,112,0,72,112,1,73,36,250,0,48,
		119,0,48,26,0,102,112,0,95,1,122,1,95,1,
		92,5,1,49,95,1,92,6,1,49,112,1,73,36,
		251,0,48,120,0,48,26,0,102,112,0,95,1,92,
		2,1,112,1,73,36,252,0,48,121,0,48,26,0,
		102,112,0,95,1,92,3,1,112,1,73,36,253,0,
		48,122,0,48,26,0,102,112,0,95,1,92,4,1,
		112,1,73,36,254,0,48,123,0,48,26,0,102,112,
		0,95,1,92,5,1,112,1,73,36,255,0,48,124,
		0,48,26,0,102,112,0,95,1,92,6,1,112,1,
		73,36,0,1,48,125,0,48,26,0,102,112,0,95,
		1,92,7,1,112,1,73,36,2,1,48,126,0,48,
		26,0,102,112,0,95,1,92,9,1,112,1,73,36,
		3,1,48,127,0,48,26,0,102,112,0,95,1,92,
		4,1,95,1,92,9,1,49,112,1,73,36,4,1,
		48,128,0,48,26,0,102,112,0,95,1,92,4,1,
		95,1,92,9,1,18,122,49,92,100,65,112,1,73,
		36,6,1,48,129,0,48,26,0,102,112,0,112,0,
		73,36,8,1,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,132,0,2,0,116,132,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

