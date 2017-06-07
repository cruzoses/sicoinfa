/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\Prg\Controllers\TiposNotasController.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TIPOSNOTASCONTROLLER );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( SQLBASECONTROLLER );
HB_FUNC_STATIC( TIPOSNOTASCONTROLLER_NEW );
HB_FUNC_EXTERN( TIPOSNOTASMODEL );
HB_FUNC_EXTERN( TIPOSNOTAS );
HB_FUNC_STATIC( TIPOSNOTASCONTROLLER_VALIDDIALOG );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TIPOSNOTASCONTROLLER )
{ "TIPOSNOTASCONTROLLER", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TIPOSNOTASCONTROLLER )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "SQLBASECONTROLLER", {HB_FS_PUBLIC}, {HB_FUNCNAME( SQLBASECONTROLLER )}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TIPOSNOTASCONTROLLER_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPOSNOTASCONTROLLER_NEW )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TIPOSNOTASMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIPOSNOTASMODEL )}, NULL },
{ "TIPOSNOTAS", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIPOSNOTAS )}, NULL },
{ "TIPOSNOTASCONTROLLER_VALIDDIALOG", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIPOSNOTASCONTROLLER_VALIDDIALOG )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_IDUSERMAP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETTITLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "HBUFFER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OMODEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "SETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHECKSFORVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ISDUPLICATEMODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TIPOSNOTASCONTROLLER, ".\\Prg\\Controllers\\TiposNotasController.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TIPOSNOTASCONTROLLER
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TIPOSNOTASCONTROLLER )
   #include "hbiniseg.h"
#endif

HB_FUNC( TIPOSNOTASCONTROLLER )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,29,0,36,7,0,103,2,0,100,8,
		29,48,1,176,1,0,104,2,0,12,1,29,37,1,
		166,231,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,21,84,105,112,111,115,78,111,116,97,115,67,
		111,110,116,114,111,108,108,101,114,0,108,4,4,1,
		0,108,0,112,3,80,2,36,9,0,48,5,0,95,
		2,106,4,78,101,119,0,108,6,95,1,121,72,121,
		72,121,72,112,3,73,36,11,0,48,7,0,95,2,
		106,14,98,117,105,108,100,83,81,76,77,111,100,101,
		108,0,89,20,0,2,0,0,0,48,2,0,176,8,
		0,12,0,95,2,112,1,6,95,1,121,72,121,72,
		121,72,112,3,73,36,13,0,48,7,0,95,2,106,
		13,98,117,105,108,100,83,81,76,86,105,101,119,0,
		89,20,0,2,0,0,0,48,2,0,176,9,0,12,
		0,95,2,112,1,6,95,1,121,72,121,72,121,72,
		112,3,73,36,15,0,48,5,0,95,2,106,12,118,
		97,108,105,100,68,105,97,108,111,103,0,108,10,95,
		1,121,72,121,72,121,72,112,3,73,36,17,0,48,
		11,0,95,2,112,0,73,167,14,0,0,176,12,0,
		104,2,0,95,2,20,2,168,48,13,0,95,2,112,
		0,80,3,176,14,0,95,3,106,10,73,110,105,116,
		67,108,97,115,115,0,12,2,28,12,48,15,0,95,
		3,164,146,1,0,73,95,3,110,7,48,13,0,103,
		2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPOSNOTASCONTROLLER_NEW )
{
	static const HB_BYTE pcode[] =
	{
		36,23,0,48,16,0,102,106,6,48,49,48,57,55,
		0,112,1,73,36,25,0,48,17,0,102,106,15,84,
		105,112,111,115,32,100,101,32,110,111,116,97,115,0,
		112,1,73,36,27,0,48,2,0,48,18,0,102,112,
		0,112,0,73,36,29,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIPOSNOTASCONTROLLER_VALIDDIALOG )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,37,0,176,19,0,48,20,0,48,21,
		0,102,112,0,112,0,106,7,110,111,109,98,114,101,
		0,1,12,1,28,72,36,38,0,176,22,0,106,43,
		69,108,32,110,111,109,98,114,101,32,100,101,32,108,
		97,32,110,111,116,97,32,110,111,32,112,117,101,100,
		101,32,101,115,116,97,114,32,118,97,99,237,111,46,
		0,20,1,36,39,0,48,23,0,95,2,112,0,73,
		36,40,0,9,110,7,36,43,0,48,24,0,48,21,
		0,102,112,0,106,7,110,111,109,98,114,101,0,112,
		1,80,3,36,45,0,176,19,0,95,3,12,1,32,
		163,0,36,46,0,95,3,48,20,0,48,21,0,102,
		112,0,112,0,106,3,105,100,0,1,69,28,57,48,
		25,0,102,112,0,31,49,36,47,0,176,22,0,106,
		20,69,115,116,97,32,110,111,116,97,32,121,97,32,
		101,120,105,115,116,101,0,20,1,36,48,0,48,23,
		0,95,2,112,0,73,36,49,0,9,110,7,36,52,
		0,95,3,48,20,0,48,21,0,102,112,0,112,0,
		106,3,105,100,0,1,8,28,57,48,25,0,102,112,
		0,28,49,36,53,0,176,22,0,106,20,69,115,116,
		97,32,110,111,116,97,32,121,97,32,101,120,105,115,
		116,101,0,20,1,36,54,0,48,23,0,95,2,112,
		0,73,36,55,0,9,110,7,36,59,0,48,26,0,
		95,1,122,112,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,29,0,2,0,116,29,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

