/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\Prg\Models\BaseModel.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( BASEMODEL );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_EXTERN( CPATEMP );
HB_FUNC_EXTERN( CPATDAT );
HB_FUNC_STATIC( BASEMODEL_EXECUTESQLSTATEMENT );
HB_FUNC_EXTERN( SELECT );
HB_FUNC_EXTERN( DBCLOSEAREA );
HB_FUNC_EXTERN( DBSELECTAREA );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( TRIMEDSECONDS );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( APOLOBREAK );
HB_FUNC_EXTERN( ADSCREATESQLSTATEMENT );
HB_FUNC_EXTERN( ADSEXECUTESQLDIRECT );
HB_FUNC_EXTERN( ADSGETLASTERROR );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( ADSCACHEOPENCURSORS );
HB_FUNC_EXTERN( ADSCLRCALLBACK );
HB_FUNC_EXTERN( ERRORMESSAGE );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_BASEMODEL )
{ "BASEMODEL", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( BASEMODEL )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATEMP )}, NULL },
{ "CPATDAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATDAT )}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BASEMODEL_EXECUTESQLSTATEMENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( BASEMODEL_EXECUTESQLSTATEMENT )}, NULL },
{ "SELECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( SELECT )}, NULL },
{ "DBCLOSEAREA", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBCLOSEAREA )}, NULL },
{ "DBSELECTAREA", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBSELECTAREA )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TRIMEDSECONDS", {HB_FS_PUBLIC}, {HB_FUNCNAME( TRIMEDSECONDS )}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "APOLOBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( APOLOBREAK )}, NULL },
{ "CLOSEAREA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADSCREATESQLSTATEMENT", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADSCREATESQLSTATEMENT )}, NULL },
{ "ADSEXECUTESQLDIRECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADSEXECUTESQLDIRECT )}, NULL },
{ "ADSGETLASTERROR", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADSGETLASTERROR )}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "ADSCACHEOPENCURSORS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADSCACHEOPENCURSORS )}, NULL },
{ "ADSCLRCALLBACK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ADSCLRCALLBACK )}, NULL },
{ "ERRORMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORMESSAGE )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_BASEMODEL, ".\\Prg\\Models\\BaseModel.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_BASEMODEL
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_BASEMODEL )
   #include "hbiniseg.h"
#endif

HB_FUNC( BASEMODEL )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,32,0,36,7,0,103,2,0,100,8,
		29,88,1,176,1,0,104,2,0,12,1,29,77,1,
		166,15,1,0,122,80,1,48,2,0,176,3,0,12,
		0,106,10,66,97,115,101,77,111,100,101,108,0,108,
		4,4,1,0,108,0,112,3,80,2,36,9,0,48,
		5,0,95,2,106,20,103,101,116,69,109,112,114,101,
		115,97,84,97,98,108,101,78,97,109,101,0,89,16,
		0,2,0,0,0,176,6,0,12,0,95,2,72,6,
		95,1,121,72,121,72,121,72,112,3,73,36,11,0,
		48,5,0,95,2,106,18,103,101,116,68,97,116,111,
		115,84,97,98,108,101,78,97,109,101,0,89,16,0,
		2,0,0,0,176,7,0,12,0,95,2,72,6,95,
		1,121,72,121,72,121,72,112,3,73,36,13,0,48,
		8,0,95,2,106,20,69,120,101,99,117,116,101,83,
		113,108,83,116,97,116,101,109,101,110,116,0,108,9,
		95,1,121,72,121,72,121,72,112,3,73,36,15,0,
		48,5,0,95,2,106,10,67,108,111,115,101,65,114,
		101,97,0,89,36,0,2,0,0,0,176,10,0,95,
		2,12,1,121,15,28,12,85,95,2,74,176,11,0,
		20,0,74,176,12,0,121,20,1,120,6,95,1,121,
		72,121,72,121,72,112,3,73,36,17,0,48,13,0,
		95,2,112,0,73,167,14,0,0,176,14,0,104,2,
		0,95,2,20,2,168,48,15,0,95,2,112,0,80,
		3,176,16,0,95,3,106,10,73,110,105,116,67,108,
		97,115,115,0,12,2,28,12,48,17,0,95,3,164,
		146,1,0,73,95,3,110,7,48,15,0,103,2,0,
		112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( BASEMODEL_EXECUTESQLSTATEMENT )
{
	static const HB_BYTE pcode[] =
	{
		13,5,3,36,29,0,95,2,100,8,28,16,106,4,
		65,68,83,0,176,18,0,12,0,72,80,2,36,30,
		0,95,3,100,8,28,6,92,2,80,3,36,32,0,
		176,19,0,89,15,0,1,0,0,0,176,20,0,95,
		1,12,1,6,12,1,80,7,36,33,0,113,13,1,
		0,36,35,0,48,21,0,102,95,2,112,1,73,36,
		37,0,176,12,0,121,20,1,36,39,0,176,22,0,
		95,2,95,3,12,2,80,4,36,40,0,95,4,28,
		108,36,42,0,176,23,0,95,1,12,1,80,4,36,
		43,0,95,4,32,175,0,36,44,0,176,24,0,96,
		8,0,12,1,80,5,36,45,0,176,25,0,106,9,
		69,114,114,111,114,32,58,32,0,176,26,0,95,5,
		12,1,72,106,2,91,0,72,95,8,72,106,2,93,
		0,72,106,29,69,82,82,79,82,32,101,110,32,65,
		100,115,69,120,101,99,117,116,101,83,113,108,68,105,
		114,101,99,116,0,20,2,25,88,36,50,0,176,24,
		0,96,8,0,12,1,80,5,36,51,0,176,25,0,
		106,9,69,114,114,111,114,32,58,32,0,176,26,0,
		95,5,12,1,72,106,2,91,0,72,95,8,72,106,
		2,93,0,72,106,31,69,82,82,79,82,32,101,110,
		32,65,68,83,67,114,101,97,116,101,83,81,76,83,
		116,97,116,101,109,101,110,116,0,20,2,36,55,0,
		95,4,28,19,36,56,0,176,27,0,121,20,1,36,
		57,0,176,28,0,20,0,36,58,0,114,50,0,0,
		36,60,0,115,80,6,36,62,0,176,25,0,176,29,
		0,95,6,12,1,106,23,69,114,114,111,114,32,101,
		110,32,115,101,110,116,101,110,99,105,97,32,83,81,
		76,0,20,2,36,66,0,176,19,0,95,7,20,1,
		36,68,0,95,4,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,32,0,2,0,116,32,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

