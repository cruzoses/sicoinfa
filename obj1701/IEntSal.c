/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\IEntSal.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( IENTSAL );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TINFGEN );
HB_FUNC_STATIC( IENTSAL_CREATE );
HB_FUNC_STATIC( IENTSAL_OPENFILES );
HB_FUNC_STATIC( IENTSAL_CLOSEFILES );
HB_FUNC_STATIC( IENTSAL_LRESOURCE );
HB_FUNC_STATIC( IENTSAL_LGENERATE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( APOLOBREAK );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( CPATEMP );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( AITMENTSAL );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_IENTSAL )
{ "IENTSAL", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( IENTSAL )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TINFGEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( TINFGEN )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "IENTSAL_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( IENTSAL_CREATE )}, NULL },
{ "IENTSAL_OPENFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( IENTSAL_OPENFILES )}, NULL },
{ "IENTSAL_CLOSEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( IENTSAL_CLOSEFILES )}, NULL },
{ "IENTSAL_LRESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( IENTSAL_LRESOURCE )}, NULL },
{ "IENTSAL_LGENERATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( IENTSAL_LGENERATE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDTMPINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDEFSERINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDEFDIVINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "APOLOBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( APOLOBREAK )}, NULL },
{ "_ODBFENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWOPEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "CPATEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATEMP )}, NULL },
{ "ADDBAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "CLOSEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "USED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STDRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETTOTAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OMTRINF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LASTREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATEFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AITMENTSAL", {HB_FS_PUBLIC}, {HB_FUNCNAME( AITMENTSAL )}, NULL },
{ "CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
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
{ "GOTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LBREAK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DFECENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EVALFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "APPEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DFECENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTIPENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CTIPENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CDESENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDESENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NIMPENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NIMPENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDKEYNO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_IENTSAL, ".\\.\\Prg\\IEntSal.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_IENTSAL
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_IENTSAL )
   #include "hbiniseg.h"
#endif

HB_FUNC( IENTSAL )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,74,0,36,8,0,103,2,0,100,8,
		29,70,1,176,1,0,104,2,0,12,1,29,59,1,
		166,253,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,8,73,69,110,116,83,97,108,0,108,4,4,
		1,0,108,0,112,3,80,2,36,10,0,48,5,0,
		95,2,106,7,79,66,74,69,67,84,0,100,95,1,
		121,72,121,72,121,72,106,8,111,68,98,102,69,110,
		116,0,4,1,0,9,112,5,73,36,12,0,48,6,
		0,95,2,106,7,67,114,101,97,116,101,0,108,7,
		95,1,121,72,121,72,121,72,112,3,73,36,14,0,
		48,6,0,95,2,106,10,79,112,101,110,70,105,108,
		101,115,0,108,8,95,1,121,72,121,72,121,72,112,
		3,73,36,16,0,48,6,0,95,2,106,11,67,108,
		111,115,101,70,105,108,101,115,0,108,9,95,1,121,
		72,121,72,121,72,112,3,73,36,18,0,48,6,0,
		95,2,106,10,108,82,101,115,111,117,114,99,101,0,
		108,10,95,1,121,72,121,72,121,72,112,3,73,36,
		20,0,48,6,0,95,2,106,10,108,71,101,110,101,
		114,97,116,101,0,108,11,95,1,121,72,121,72,121,
		72,112,3,73,36,22,0,48,12,0,95,2,112,0,
		73,167,14,0,0,176,13,0,104,2,0,95,2,20,
		2,168,48,14,0,95,2,112,0,80,3,176,15,0,
		95,3,106,10,73,110,105,116,67,108,97,115,115,0,
		12,2,28,12,48,16,0,95,3,164,146,1,0,73,
		95,3,110,7,48,14,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( IENTSAL_CREATE )
{
	static const HB_BYTE pcode[] =
	{
		36,28,0,48,17,0,102,106,8,100,70,101,99,69,
		110,116,0,106,2,68,0,92,8,121,90,6,106,1,
		0,6,106,6,70,101,99,104,97,0,120,106,6,70,
		101,99,104,97,0,92,12,9,112,10,73,36,29,0,
		48,17,0,102,106,8,99,84,105,112,69,110,116,0,
		106,2,67,0,92,20,121,90,6,106,1,0,6,106,
		5,84,105,112,111,0,120,106,5,84,105,112,111,0,
		92,15,9,112,10,73,36,30,0,48,17,0,102,106,
		8,99,68,101,115,69,110,116,0,106,2,67,0,92,
		50,121,90,6,106,1,0,6,106,12,68,101,115,99,
		114,105,112,99,105,243,110,0,120,106,12,68,101,115,
		99,114,105,112,99,105,243,110,0,92,50,9,112,10,
		73,36,31,0,48,17,0,102,106,8,110,73,109,112,
		69,110,116,0,106,2,78,0,92,16,92,6,90,6,
		106,1,0,6,106,8,73,109,112,111,114,116,101,0,
		120,106,8,73,109,112,111,114,116,101,0,92,16,9,
		112,10,73,36,33,0,48,18,0,102,106,8,100,70,
		101,99,69,110,116,0,106,8,100,70,101,99,69,110,
		116,0,112,2,73,36,35,0,48,19,0,102,9,112,
		1,73,36,36,0,48,20,0,102,9,112,1,73,36,
		38,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( IENTSAL_OPENFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,44,0,120,80,1,36,45,0,176,21,
		0,89,15,0,1,0,0,0,176,22,0,95,1,12,
		1,6,12,1,80,2,36,47,0,113,120,0,0,36,
		49,0,48,23,0,102,48,24,0,176,25,0,106,11,
		69,78,84,83,65,76,46,68,66,70,0,100,12,2,
		106,11,69,78,84,83,65,76,46,68,66,70,0,100,
		176,26,0,12,0,100,176,27,0,12,0,9,120,9,
		9,112,9,112,1,73,48,28,0,48,29,0,102,112,
		0,106,11,69,78,84,83,65,76,46,67,68,88,0,
		112,1,73,48,28,0,48,29,0,102,112,0,112,0,
		73,48,30,0,48,29,0,102,112,0,112,0,73,114,
		76,0,0,36,51,0,115,73,36,53,0,176,31,0,
		106,41,73,109,112,111,115,105,98,108,101,32,97,98,
		114,105,114,32,116,111,100,97,115,32,108,97,115,32,
		98,97,115,101,115,32,100,101,32,100,97,116,111,115,
		0,20,1,36,54,0,48,32,0,102,112,0,73,36,
		55,0,9,80,1,36,59,0,176,21,0,95,2,20,
		1,36,61,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( IENTSAL_CLOSEFILES )
{
	static const HB_BYTE pcode[] =
	{
		36,67,0,176,33,0,48,29,0,102,112,0,12,1,
		31,30,48,34,0,48,29,0,102,112,0,112,0,28,
		17,36,68,0,48,35,0,48,29,0,102,112,0,112,
		0,73,36,71,0,48,23,0,102,100,112,1,73,36,
		73,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( IENTSAL_LRESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,79,0,48,36,0,102,106,10,73,78,
		70,95,69,78,84,48,49,0,112,1,31,8,36,80,
		0,9,110,7,36,83,0,48,37,0,48,38,0,102,
		112,0,48,39,0,48,29,0,102,112,0,112,0,112,
		1,73,36,85,0,48,40,0,102,176,41,0,12,0,
		48,42,0,48,29,0,102,112,0,112,0,112,2,73,
		36,87,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( IENTSAL_LGENERATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,94,0,102,80,1,36,96,0,48,43,
		0,48,44,0,95,1,112,0,112,0,73,36,97,0,
		48,45,0,48,46,0,95,1,112,0,112,0,73,36,
		98,0,48,47,0,48,48,0,95,1,112,0,112,0,
		73,36,101,0,48,49,0,95,1,90,27,106,11,70,
		101,99,104,97,32,32,32,58,32,0,176,50,0,176,
		51,0,12,0,12,1,72,6,89,56,0,0,0,1,
		0,1,0,106,11,80,101,114,105,111,100,111,32,58,
		32,0,176,50,0,48,52,0,95,255,112,0,12,1,
		72,106,4,32,62,32,0,72,176,50,0,48,53,0,
		95,255,112,0,12,1,72,6,4,2,0,112,1,73,
		36,103,0,48,54,0,48,29,0,95,1,112,0,106,
		8,68,70,69,67,69,78,84,0,112,1,73,36,105,
		0,48,55,0,48,29,0,95,1,112,0,112,0,73,
		36,106,0,48,56,0,95,1,112,0,32,56,1,48,
		57,0,48,29,0,95,1,112,0,112,0,32,41,1,
		36,108,0,48,58,0,48,29,0,95,1,112,0,112,
		0,48,52,0,95,1,112,0,16,29,224,0,48,58,
		0,48,29,0,95,1,112,0,112,0,48,53,0,95,
		1,112,0,34,29,201,0,48,59,0,95,1,112,0,
		29,191,0,36,110,0,48,60,0,48,48,0,95,1,
		112,0,112,0,73,36,112,0,48,61,0,48,48,0,
		95,1,112,0,48,58,0,48,29,0,95,1,112,0,
		112,0,112,1,73,36,113,0,48,62,0,48,29,0,
		95,1,112,0,112,0,122,8,28,30,36,114,0,48,
		63,0,48,48,0,95,1,112,0,106,8,69,110,116,
		114,97,100,97,0,112,1,73,25,27,36,116,0,48,
		63,0,48,48,0,95,1,112,0,106,7,83,97,108,
		105,100,97,0,112,1,73,36,118,0,48,64,0,48,
		48,0,95,1,112,0,48,65,0,48,29,0,95,1,
		112,0,112,0,112,1,73,36,119,0,48,66,0,48,
		48,0,95,1,112,0,48,67,0,48,29,0,95,1,
		112,0,112,0,112,1,73,36,121,0,48,68,0,48,
		48,0,95,1,112,0,112,0,73,36,125,0,48,69,
		0,48,29,0,95,1,112,0,112,0,73,36,127,0,
		48,70,0,48,38,0,95,1,112,0,48,71,0,48,
		29,0,95,1,112,0,112,0,112,1,73,26,193,254,
		36,131,0,48,70,0,48,38,0,95,1,112,0,48,
		39,0,48,29,0,95,1,112,0,112,0,112,1,73,
		36,133,0,48,45,0,48,44,0,95,1,112,0,112,
		0,73,36,135,0,48,39,0,48,48,0,95,1,112,
		0,112,0,121,15,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,74,0,2,0,116,74,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

