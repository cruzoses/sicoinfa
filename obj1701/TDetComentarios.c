/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\TDetComentarios.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TDETCOMENTARIOS );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TDET );
HB_FUNC_STATIC( TDETCOMENTARIOS_CREATE );
HB_FUNC_STATIC( TDETCOMENTARIOS_DEFINEFILES );
HB_FUNC_STATIC( TDETCOMENTARIOS_OPENFILES );
HB_FUNC_STATIC( TDETCOMENTARIOS_CLOSEFILES );
HB_FUNC_STATIC( TDETCOMENTARIOS_RESOURCE );
HB_FUNC_STATIC( TDETCOMENTARIOS_REINDEXA );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( CGETNEWFILENAME );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( CPATART );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( APOLOBREAK );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( ERRORMESSAGE );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TDETCOMENTARIOS )
{ "TDETCOMENTARIOS", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TDETCOMENTARIOS )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TDET", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDET )}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDETCOMENTARIOS_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDETCOMENTARIOS_CREATE )}, NULL },
{ "TDETCOMENTARIOS_DEFINEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDETCOMENTARIOS_DEFINEFILES )}, NULL },
{ "TDETCOMENTARIOS_OPENFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDETCOMENTARIOS_OPENFILES )}, NULL },
{ "TDETCOMENTARIOS_CLOSEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDETCOMENTARIOS_CLOSEFILES )}, NULL },
{ "TDETCOMENTARIOS_RESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDETCOMENTARIOS_RESOURCE )}, NULL },
{ "TDETCOMENTARIOS_REINDEXA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDETCOMENTARIOS_REINDEXA )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "CGETNEWFILENAME", {HB_FS_PUBLIC}, {HB_FUNCNAME( CGETNEWFILENAME )}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATART", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATART )}, NULL },
{ "_CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "APOLOBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( APOLOBREAK )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFINEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLOSEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "ERRORMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORMESSAGE )}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFVIR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "CDESCRI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CDESCRI", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "ADDFASTKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NRESULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "IDXFDEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPENFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TDETCOMENTARIOS, ".\\.\\Prg\\TDetComentarios.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TDETCOMENTARIOS
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TDETCOMENTARIOS )
   #include "hbiniseg.h"
#endif

HB_FUNC( TDETCOMENTARIOS )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,58,0,36,9,0,103,2,0,100,8,
		29,68,1,176,1,0,104,2,0,12,1,29,57,1,
		166,251,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,16,84,68,101,116,67,111,109,101,110,116,97,
		114,105,111,115,0,108,4,4,1,0,108,0,112,3,
		80,2,36,11,0,48,5,0,95,2,106,7,67,114,
		101,97,116,101,0,108,6,95,1,121,72,121,72,121,
		72,112,3,73,36,13,0,48,5,0,95,2,106,12,
		68,101,102,105,110,101,70,105,108,101,115,0,108,7,
		95,1,121,72,121,72,121,72,112,3,73,36,15,0,
		48,5,0,95,2,106,10,79,112,101,110,70,105,108,
		101,115,0,108,8,95,1,121,72,121,72,121,72,112,
		3,73,36,17,0,48,5,0,95,2,106,11,67,108,
		111,115,101,70,105,108,101,115,0,108,9,95,1,121,
		72,121,72,121,72,112,3,73,36,19,0,48,5,0,
		95,2,106,9,82,101,115,111,117,114,99,101,0,108,
		10,95,1,121,72,121,72,121,72,112,3,73,36,21,
		0,48,5,0,95,2,106,9,82,101,105,110,100,101,
		120,97,0,108,11,95,1,121,72,121,72,121,72,112,
		3,73,36,23,0,48,12,0,95,2,112,0,73,167,
		14,0,0,176,13,0,104,2,0,95,2,20,2,168,
		48,14,0,95,2,112,0,80,3,176,15,0,95,3,
		106,10,73,110,105,116,67,108,97,115,115,0,12,2,
		28,12,48,16,0,95,3,164,146,1,0,73,95,3,
		110,7,48,14,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDETCOMENTARIOS_DEFINEFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,1,4,36,31,0,95,1,100,8,28,10,48,17,
		0,102,112,0,80,1,36,32,0,95,3,100,8,28,
		5,9,80,3,36,33,0,95,4,100,8,28,19,106,
		13,67,111,109,101,110,116,97,114,105,111,115,76,0,
		80,4,36,34,0,95,2,100,8,28,9,176,18,0,
		12,0,80,2,36,36,0,95,3,28,18,36,37,0,
		176,19,0,95,4,100,100,95,1,12,4,80,4,36,
		40,0,48,2,0,176,20,0,95,4,95,4,12,2,
		95,4,106,8,67,111,109,101,110,116,76,0,95,2,
		106,12,67,111,109,101,110,116,97,114,105,111,115,0,
		95,1,112,5,80,5,36,42,0,48,21,0,95,5,
		106,8,99,67,111,100,105,103,111,0,106,2,67,0,
		92,3,121,100,100,100,100,106,7,67,243,100,105,103,
		111,0,9,92,60,9,4,0,0,112,13,73,36,43,
		0,48,21,0,95,5,106,8,99,68,101,115,99,114,
		105,0,106,2,67,0,93,200,0,121,100,100,100,100,
		106,12,68,101,115,99,114,105,112,99,105,243,110,0,
		9,92,100,9,4,0,0,112,13,73,36,45,0,48,
		22,0,95,5,106,8,99,67,111,100,105,103,111,0,
		95,4,106,8,99,67,111,100,105,103,111,0,100,100,
		9,9,100,100,100,120,9,112,12,73,36,46,0,48,
		22,0,95,5,106,8,99,67,111,100,68,101,115,0,
		95,4,106,18,99,67,111,100,105,103,111,32,43,32,
		99,68,101,115,99,114,105,0,100,100,9,9,100,100,
		100,120,9,112,12,73,36,50,0,95,5,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDETCOMENTARIOS_CREATE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,56,0,95,1,100,8,28,9,176,23,
		0,12,0,80,1,36,58,0,48,24,0,102,95,1,
		112,1,73,36,60,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDETCOMENTARIOS_OPENFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,3,2,36,66,0,120,80,3,36,70,0,95,1,
		100,8,28,5,9,80,1,36,71,0,95,2,100,8,
		28,10,48,17,0,102,112,0,80,2,36,73,0,176,
		25,0,89,15,0,1,0,0,0,176,26,0,95,1,
		12,1,6,12,1,80,5,36,74,0,113,61,0,0,
		36,76,0,176,27,0,48,28,0,102,112,0,12,1,
		28,20,36,77,0,48,29,0,102,48,30,0,102,95,
		2,112,1,112,1,73,36,80,0,48,31,0,48,28,
		0,102,112,0,9,95,1,68,112,2,73,114,103,0,
		0,36,82,0,115,80,4,36,84,0,9,80,3,36,
		86,0,48,32,0,102,112,0,73,36,88,0,176,33,
		0,176,34,0,95,4,12,1,106,60,73,109,112,111,
		115,105,98,108,101,32,97,98,114,105,114,32,108,97,
		115,32,98,97,115,101,115,32,100,101,32,100,97,116,
		111,115,32,100,101,32,108,105,110,101,97,115,32,100,
		101,32,99,111,109,101,110,116,97,114,105,111,115,0,
		20,2,36,92,0,176,25,0,95,5,20,1,36,94,
		0,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDETCOMENTARIOS_CLOSEFILES )
{
	static const HB_BYTE pcode[] =
	{
		36,100,0,176,27,0,48,28,0,102,112,0,12,1,
		31,17,36,101,0,48,35,0,48,28,0,102,112,0,
		112,0,73,36,104,0,48,29,0,102,100,112,1,73,
		36,106,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDETCOMENTARIOS_RESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,1,36,110,0,102,80,2,36,117,0,9,80,
		4,36,119,0,48,36,0,48,37,0,95,2,112,0,
		48,38,0,48,28,0,48,39,0,95,2,112,0,112,
		0,112,0,112,1,73,36,125,0,48,2,0,176,40,
		0,12,0,100,100,100,100,100,106,13,67,111,109,101,
		110,116,97,114,105,111,115,76,0,100,9,100,100,100,
		100,100,9,100,100,100,100,100,9,100,106,5,111,68,
		108,103,0,100,100,112,24,80,3,36,130,0,48,41,
		0,176,42,0,12,0,92,110,89,47,0,1,0,1,
		0,2,0,176,43,0,12,0,121,8,28,16,48,44,
		0,48,37,0,95,255,112,0,112,0,25,16,48,45,
		0,48,37,0,95,255,112,0,95,1,112,1,6,95,
		3,100,100,100,100,100,100,100,100,9,89,15,0,0,
		0,1,0,1,0,95,255,92,3,69,6,100,9,9,
		100,100,100,100,100,100,100,100,100,112,25,73,36,136,
		0,48,41,0,176,46,0,12,0,122,89,18,0,0,
		0,1,0,3,0,48,35,0,95,255,122,112,1,6,
		95,3,100,100,9,89,15,0,0,0,1,0,1,0,
		95,255,92,3,69,6,100,100,9,112,10,73,36,142,
		0,48,41,0,176,46,0,12,0,92,2,89,17,0,
		0,0,1,0,3,0,48,35,0,95,255,112,0,6,
		95,3,100,100,9,100,100,100,120,112,10,73,36,144,
		0,95,1,92,3,69,28,33,36,145,0,48,47,0,
		95,3,92,116,89,18,0,0,0,1,0,3,0,48,
		35,0,95,255,122,112,1,6,112,2,73,36,148,0,
		48,31,0,95,3,48,48,0,95,3,112,0,48,49,
		0,95,3,112,0,48,50,0,95,3,112,0,120,100,
		100,100,48,51,0,95,3,112,0,100,100,100,112,11,
		73,36,150,0,48,52,0,95,3,112,0,122,8,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDETCOMENTARIOS_REINDEXA )
{
	static const HB_BYTE pcode[] =
	{
		36,160,0,176,27,0,48,28,0,102,112,0,12,1,
		28,18,36,161,0,48,29,0,102,48,30,0,102,112,
		0,112,1,73,36,164,0,48,53,0,48,28,0,102,
		112,0,112,0,73,36,166,0,48,54,0,102,120,112,
		1,28,17,36,167,0,48,55,0,48,28,0,102,112,
		0,112,0,73,36,170,0,48,32,0,102,112,0,73,
		36,172,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,58,0,2,0,116,58,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

