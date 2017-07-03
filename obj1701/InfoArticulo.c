/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\InfoArticulo.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( CREATEINFOARTICULO );
HB_FUNC( CLOSEINFOARTICULO );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC( TINFOARTICULO );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_STATIC( TINFOARTICULO_NEW );
HB_FUNC_STATIC( TINFOARTICULO_OPENFILES );
HB_FUNC_STATIC( TINFOARTICULO_CLOSEFILES );
HB_FUNC_STATIC( TINFOARTICULO_LOADARTICULO );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( APOLOBREAK );
HB_FUNC_EXTERN( CPATEMP );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( CPATART );
HB_FUNC_EXTERN( CPATDAT );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( SPACE );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( BRWARTICULO );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( CSEEKCODEBAR );
HB_FUNC_EXTERN( NRETPREART );
HB_FUNC_EXTERN( CDIVEMP );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_INFOARTICULO )
{ "CREATEINFOARTICULO", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( CREATEINFOARTICULO )}, NULL },
{ "CLOSEINFOARTICULO", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( CLOSEINFOARTICULO )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TINFOARTICULO", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( TINFOARTICULO )}, NULL },
{ "CLOSEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TINFOARTICULO_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TINFOARTICULO_NEW )}, NULL },
{ "TINFOARTICULO_OPENFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TINFOARTICULO_OPENFILES )}, NULL },
{ "TINFOARTICULO_CLOSEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TINFOARTICULO_CLOSEFILES )}, NULL },
{ "TINFOARTICULO_LOADARTICULO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TINFOARTICULO_LOADARTICULO )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "APOLOBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( APOLOBREAK )}, NULL },
{ "CPATEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATEMP )}, NULL },
{ "_ODBFARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWOPEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "CPATART", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATART )}, NULL },
{ "ADDBAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBFARTCODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFARTCODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBFIVA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATDAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATDAT )}, NULL },
{ "ODBFIVA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBFDIVISA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFDIVISA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBFKIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFKIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SPACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SPACE )}, NULL },
{ "OPENFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "_OCODIGOARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCODIGOARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LOADARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BHELP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRWARTICULO", {HB_FS_PUBLIC}, {HB_FUNCNAME( BRWARTICULO )}, NULL },
{ "ONOMBREARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ONOMBREARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OPRECIOARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "_BSTART", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VARGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSEEKCODEBAR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CSEEKCODEBAR )}, NULL },
{ "CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDESTIK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NOMBRE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPRECIOARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NRETPREART", {HB_FS_PUBLIC}, {HB_FUNCNAME( NRETPREART )}, NULL },
{ "CDIVEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDIVEMP )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00003)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_INFOARTICULO, ".\\.\\Prg\\InfoArticulo.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_INFOARTICULO
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_INFOARTICULO )
   #include "hbiniseg.h"
#endif

HB_FUNC( CREATEINFOARTICULO )
{
	static const HB_BYTE pcode[] =
	{
		116,75,0,36,11,0,176,1,0,20,0,36,13,0,
		176,2,0,103,2,0,12,1,28,18,36,14,0,48,
		3,0,176,4,0,12,0,112,0,82,2,0,36,17,
		0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( CLOSEINFOARTICULO )
{
	static const HB_BYTE pcode[] =
	{
		116,75,0,36,23,0,103,2,0,100,69,28,14,36,
		24,0,48,5,0,103,2,0,112,0,73,36,27,0,
		100,82,2,0,36,29,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( TINFOARTICULO )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,75,0,36,33,0,103,3,0,100,8,
		29,92,2,176,6,0,104,3,0,12,1,29,81,2,
		166,19,2,0,122,80,1,48,3,0,176,7,0,12,
		0,106,14,84,73,110,102,111,65,114,116,105,99,117,
		108,111,0,108,8,4,1,0,108,4,112,3,80,2,
		36,35,0,48,9,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,5,111,68,108,103,0,4,1,0,
		9,112,5,73,36,37,0,48,9,0,95,2,100,100,
		95,1,121,72,121,72,121,72,106,13,111,68,98,102,
		65,114,116,105,99,117,108,111,0,4,1,0,9,112,
		5,73,36,38,0,48,9,0,95,2,100,100,95,1,
		121,72,121,72,121,72,106,8,111,68,98,102,73,118,
		97,0,4,1,0,9,112,5,73,36,39,0,48,9,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		8,111,68,98,102,75,105,116,0,4,1,0,9,112,
		5,73,36,40,0,48,9,0,95,2,100,100,95,1,
		121,72,121,72,121,72,106,11,111,68,98,102,68,105,
		118,105,115,97,0,4,1,0,9,112,5,73,36,41,
		0,48,9,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,12,111,68,98,102,65,114,116,67,111,100,
		101,0,4,1,0,9,112,5,73,36,43,0,48,9,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		16,111,67,111,100,105,103,111,65,114,116,105,99,117,
		108,111,0,4,1,0,9,112,5,73,36,44,0,48,
		9,0,95,2,100,100,95,1,121,72,121,72,121,72,
		106,16,111,78,111,109,98,114,101,65,114,116,105,99,
		117,108,111,0,4,1,0,9,112,5,73,36,45,0,
		48,9,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,16,111,80,114,101,99,105,111,65,114,116,105,
		99,117,108,111,0,4,1,0,9,112,5,73,36,47,
		0,48,10,0,95,2,106,4,78,101,119,0,108,11,
		95,1,121,72,121,72,121,72,112,3,73,36,49,0,
		48,10,0,95,2,106,10,79,112,101,110,70,105,108,
		101,115,0,108,12,95,1,121,72,121,72,121,72,112,
		3,73,36,50,0,48,10,0,95,2,106,11,67,108,
		111,115,101,70,105,108,101,115,0,108,13,95,1,121,
		72,121,72,121,72,112,3,73,36,52,0,48,10,0,
		95,2,106,13,76,111,97,100,65,114,116,105,99,117,
		108,111,0,108,14,95,1,121,72,121,72,121,72,112,
		3,73,36,54,0,48,15,0,95,2,112,0,73,167,
		14,0,0,176,16,0,104,3,0,95,2,20,2,168,
		48,17,0,95,2,112,0,80,3,176,18,0,95,3,
		106,10,73,110,105,116,67,108,97,115,115,0,12,2,
		28,12,48,19,0,95,3,164,146,1,0,73,95,3,
		110,7,48,17,0,103,3,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TINFOARTICULO_OPENFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,36,60,0,120,80,2,36,61,0,176,20,
		0,89,15,0,1,0,0,0,176,21,0,95,1,12,
		1,6,12,1,80,3,36,63,0,95,1,100,8,28,
		9,176,22,0,12,0,80,1,36,65,0,113,71,2,
		0,36,67,0,48,23,0,102,48,24,0,176,25,0,
		106,13,65,114,116,105,99,117,108,111,46,68,98,102,
		0,100,12,2,106,13,65,114,116,105,99,117,108,111,
		46,68,98,102,0,100,176,26,0,12,0,100,176,27,
		0,12,0,9,120,9,9,112,9,112,1,73,48,28,
		0,48,29,0,102,112,0,106,13,65,114,116,105,99,
		117,108,111,46,67,100,120,0,112,1,73,48,28,0,
		48,29,0,102,112,0,112,0,73,48,30,0,48,29,
		0,102,112,0,112,0,73,36,69,0,48,31,0,102,
		48,24,0,176,25,0,106,15,65,114,116,67,111,100,
		101,98,97,114,46,68,98,102,0,100,12,2,106,15,
		65,114,116,67,111,100,101,98,97,114,46,68,98,102,
		0,100,176,26,0,12,0,100,176,27,0,12,0,9,
		120,9,9,112,9,112,1,73,48,28,0,48,32,0,
		102,112,0,106,15,65,114,116,67,111,100,101,98,97,
		114,46,67,100,120,0,112,1,73,48,28,0,48,32,
		0,102,112,0,112,0,73,48,30,0,48,32,0,102,
		112,0,112,0,73,36,71,0,48,33,0,102,48,24,
		0,176,25,0,106,9,84,105,118,97,46,68,98,102,
		0,100,12,2,106,9,84,105,118,97,46,68,98,102,
		0,100,176,26,0,12,0,100,176,34,0,12,0,9,
		120,9,9,112,9,112,1,73,48,28,0,48,35,0,
		102,112,0,106,9,84,105,118,97,46,67,100,120,0,
		112,1,73,48,28,0,48,35,0,102,112,0,112,0,
		73,48,30,0,48,35,0,102,112,0,112,0,73,36,
		73,0,48,36,0,102,48,24,0,176,25,0,106,12,
		68,105,118,105,115,97,115,46,68,98,102,0,100,12,
		2,106,12,68,105,118,105,115,97,115,46,68,98,102,
		0,100,176,26,0,12,0,100,176,34,0,12,0,9,
		120,9,9,112,9,112,1,73,48,28,0,48,37,0,
		102,112,0,106,12,68,105,118,105,115,97,115,46,67,
		100,120,0,112,1,73,48,28,0,48,37,0,102,112,
		0,112,0,73,48,30,0,48,37,0,102,112,0,112,
		0,73,36,75,0,48,38,0,102,48,24,0,176,25,
		0,106,11,65,114,116,75,105,116,46,68,98,102,0,
		100,12,2,106,11,65,114,116,75,105,116,46,68,98,
		102,0,100,176,26,0,12,0,100,176,27,0,12,0,
		9,120,9,9,112,9,112,1,73,48,28,0,48,39,
		0,102,112,0,106,11,65,114,116,75,105,116,46,67,
		100,120,0,112,1,73,48,28,0,48,39,0,102,112,
		0,112,0,73,48,30,0,48,39,0,102,112,0,112,
		0,73,114,76,0,0,36,77,0,115,73,36,79,0,
		176,40,0,106,41,73,109,112,111,115,105,98,108,101,
		32,97,98,114,105,114,32,116,111,100,97,115,32,108,
		97,115,32,98,97,115,101,115,32,100,101,32,100,97,
		116,111,115,0,20,1,36,81,0,48,5,0,102,112,
		0,73,36,83,0,9,80,2,36,87,0,176,20,0,
		95,3,20,1,36,89,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TINFOARTICULO_CLOSEFILES )
{
	static const HB_BYTE pcode[] =
	{
		116,75,0,36,99,0,176,2,0,48,29,0,102,112,
		0,12,1,31,17,36,100,0,48,41,0,48,29,0,
		102,112,0,112,0,73,36,103,0,176,2,0,48,32,
		0,102,112,0,12,1,31,17,36,104,0,48,41,0,
		48,32,0,102,112,0,112,0,73,36,107,0,176,2,
		0,48,35,0,102,112,0,12,1,31,17,36,108,0,
		48,41,0,48,35,0,102,112,0,112,0,73,36,111,
		0,176,2,0,48,37,0,102,112,0,12,1,31,17,
		36,112,0,48,41,0,48,37,0,102,112,0,112,0,
		73,36,115,0,176,2,0,48,39,0,102,112,0,12,
		1,31,17,36,116,0,48,41,0,48,39,0,102,112,
		0,112,0,73,36,119,0,48,23,0,102,100,112,1,
		73,36,120,0,48,31,0,102,100,112,1,73,36,121,
		0,48,33,0,102,100,112,1,73,36,122,0,48,36,
		0,102,100,112,1,73,36,123,0,48,38,0,102,100,
		112,1,73,36,125,0,100,82,2,0,36,127,0,120,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TINFOARTICULO_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,4,0,36,131,0,102,80,1,36,133,0,176,42,
		0,92,18,12,1,80,2,36,134,0,176,42,0,92,
		100,12,1,80,3,36,135,0,121,80,4,36,137,0,
		48,43,0,95,1,112,0,29,29,2,36,139,0,48,
		44,0,95,1,48,3,0,176,45,0,12,0,100,100,
		100,100,100,106,15,83,101,97,114,99,104,65,114,116,
		105,99,117,108,111,0,100,9,100,100,100,100,100,9,
		100,100,100,100,100,9,100,106,7,58,58,111,68,108,
		103,0,100,100,112,24,112,1,73,36,144,0,48,46,
		0,95,1,48,47,0,176,48,0,12,0,92,100,89,
		28,0,1,0,1,0,2,0,176,49,0,12,0,121,
		8,28,6,95,255,25,7,95,1,165,80,255,6,48,
		50,0,95,1,112,0,100,100,100,100,100,100,100,100,
		9,100,100,9,9,100,100,100,100,100,100,106,5,76,
		85,80,65,0,100,100,112,25,112,1,73,36,146,0,
		48,51,0,48,52,0,95,1,112,0,89,17,0,0,
		0,1,0,1,0,48,53,0,95,255,112,0,6,112,
		1,73,36,147,0,48,54,0,48,52,0,95,1,112,
		0,89,29,0,0,0,1,0,1,0,176,55,0,48,
		52,0,95,255,112,0,48,56,0,95,255,112,0,12,
		2,6,112,1,73,36,151,0,48,57,0,95,1,48,
		47,0,176,48,0,12,0,92,110,89,28,0,1,0,
		1,0,3,0,176,49,0,12,0,121,8,28,6,95,
		255,25,7,95,1,165,80,255,6,48,50,0,95,1,
		112,0,100,100,100,100,100,100,100,100,9,100,100,9,
		9,100,100,100,100,100,100,100,100,100,112,25,112,1,
		73,36,156,0,48,58,0,95,1,48,47,0,176,48,
		0,12,0,92,120,89,28,0,1,0,1,0,4,0,
		176,49,0,12,0,121,8,28,6,95,255,25,7,95,
		1,165,80,255,6,48,50,0,95,1,112,0,100,106,
		14,64,69,32,57,57,57,44,57,57,57,46,57,57,
		0,100,100,100,100,100,100,9,100,100,9,9,100,100,
		100,100,100,100,100,100,100,112,25,112,1,73,36,161,
		0,48,47,0,176,59,0,12,0,93,130,0,89,23,
		0,0,0,1,0,1,0,48,41,0,48,50,0,95,
		255,112,0,122,112,1,6,48,50,0,95,1,112,0,
		100,100,9,100,100,100,9,112,10,73,36,163,0,48,
		60,0,48,50,0,95,1,112,0,89,22,0,0,0,
		1,0,1,0,48,61,0,48,52,0,95,255,112,0,
		112,0,6,112,1,73,36,165,0,48,62,0,48,50,
		0,95,1,112,0,100,100,100,120,89,17,0,0,0,
		1,0,1,0,48,5,0,95,255,112,0,6,9,112,
		6,73,36,169,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TINFOARTICULO_LOADARTICULO )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,175,0,48,63,0,48,52,0,102,112,
		0,112,0,80,1,36,181,0,176,64,0,95,1,48,
		65,0,48,32,0,102,112,0,112,0,48,65,0,48,
		29,0,102,112,0,112,0,12,3,80,1,36,187,0,
		48,66,0,48,29,0,102,112,0,95,1,112,1,29,
		168,0,36,189,0,48,67,0,48,52,0,102,112,0,
		95,1,112,1,73,36,191,0,176,2,0,48,68,0,
		48,29,0,102,112,0,112,0,12,1,31,30,36,192,
		0,48,67,0,48,56,0,102,112,0,48,68,0,48,
		29,0,102,112,0,112,0,112,1,73,25,28,36,194,
		0,48,67,0,48,56,0,102,112,0,48,69,0,48,
		29,0,102,112,0,112,0,112,1,73,36,197,0,48,
		67,0,48,70,0,102,112,0,176,71,0,122,176,72,
		0,12,0,120,48,65,0,48,29,0,102,112,0,112,
		0,48,65,0,48,37,0,102,112,0,112,0,48,65,
		0,48,39,0,102,112,0,112,0,48,65,0,48,35,
		0,102,112,0,112,0,12,7,112,1,73,25,35,36,
		201,0,176,40,0,106,23,65,114,116,237,99,117,108,
		111,32,110,111,32,101,110,99,111,110,116,114,97,100,
		111,0,20,1,36,205,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,75,0,3,0,116,75,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}
