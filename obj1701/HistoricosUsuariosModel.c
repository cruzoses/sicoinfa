/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\Prg\Models\HistoricosUsuariosModel.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HISTORICOSUSUARIOSMODEL );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( SQLBASEMODEL );
HB_FUNC_STATIC( HISTORICOSUSUARIOSMODEL_NEW );
HB_FUNC_STATIC( HISTORICOSUSUARIOSMODEL_GETHISTORY );
HB_FUNC_STATIC( HISTORICOSUSUARIOSMODEL_SAVEHISTORY );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( TOSQLSTRING );
HB_FUNC_EXTERN( OUSER );
HB_FUNC_EXTERN( BREAK );
HB_FUNC_EXTERN( GETSQLDATABASE );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( HB_VALTOEXP );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HB_ISARRAY );
HB_FUNC_EXTERN( ATAIL );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( CVALTOSTR );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HISTORICOSUSUARIOSMODEL )
{ "HISTORICOSUSUARIOSMODEL", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( HISTORICOSUSUARIOSMODEL )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "SQLBASEMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( SQLBASEMODEL )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HISTORICOSUSUARIOSMODEL_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HISTORICOSUSUARIOSMODEL_NEW )}, NULL },
{ "HISTORICOSUSUARIOSMODEL_GETHISTORY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HISTORICOSUSUARIOSMODEL_GETHISTORY )}, NULL },
{ "HISTORICOSUSUARIOSMODEL_SAVEHISTORY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HISTORICOSUSUARIOSMODEL_SAVEHISTORY )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HCOLUMNS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTABLENAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TOSQLSTRING", {HB_FS_PUBLIC}, {HB_FUNCNAME( TOSQLSTRING )}, NULL },
{ "CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OUSER", {HB_FS_PUBLIC}, {HB_FUNCNAME( OUSER )}, NULL },
{ "BREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( BREAK )}, NULL },
{ "QUERY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETSQLDATABASE", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETSQLDATABASE )}, NULL },
{ "FETCHALL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "HB_VALTOEXP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_VALTOEXP )}, NULL },
{ "ERRORINFO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "FREE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HB_ISARRAY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ISARRAY )}, NULL },
{ "ATAIL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ATAIL )}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "CVALTOSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CVALTOSTR )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HISTORICOSUSUARIOSMODEL, ".\\Prg\\Models\\HistoricosUsuariosModel.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HISTORICOSUSUARIOSMODEL
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HISTORICOSUSUARIOSMODEL )
   #include "hbiniseg.h"
#endif

HB_FUNC( HISTORICOSUSUARIOSMODEL )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,36,0,36,7,0,103,2,0,100,8,
		29,35,1,176,1,0,104,2,0,12,1,29,24,1,
		166,218,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,24,72,105,115,116,111,114,105,99,111,115,85,
		115,117,97,114,105,111,115,77,111,100,101,108,0,108,
		4,4,1,0,108,0,112,3,80,2,36,9,0,48,
		5,0,95,2,100,106,20,104,105,115,116,111,114,105,
		99,111,115,95,117,115,117,97,114,105,111,115,0,95,
		1,121,72,121,72,121,72,106,11,99,84,97,98,108,
		101,78,97,109,101,0,4,1,0,9,112,5,73,36,
		11,0,48,6,0,95,2,106,4,78,101,119,0,108,
		7,95,1,121,72,121,72,121,72,112,3,73,36,13,
		0,48,6,0,95,2,106,11,103,101,116,72,105,115,
		116,111,114,121,0,108,8,95,1,121,72,121,72,121,
		72,112,3,73,36,15,0,48,6,0,95,2,106,12,
		115,97,118,101,72,105,115,116,111,114,121,0,108,9,
		95,1,121,72,121,72,121,72,112,3,73,36,17,0,
		48,10,0,95,2,112,0,73,167,14,0,0,176,11,
		0,104,2,0,95,2,20,2,168,48,12,0,95,2,
		112,0,80,3,176,13,0,95,3,106,10,73,110,105,
		116,67,108,97,115,115,0,12,2,28,12,48,14,0,
		95,3,164,146,1,0,73,95,3,110,7,48,12,0,
		103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HISTORICOSUSUARIOSMODEL_NEW )
{
	static const HB_BYTE pcode[] =
	{
		36,29,0,48,15,0,102,106,3,105,100,0,106,7,
		99,114,101,97,116,101,0,106,34,73,78,84,69,71,
		69,82,32,80,82,73,77,65,82,89,32,75,69,89,
		32,65,85,84,79,73,78,67,82,69,77,69,78,84,
		0,177,1,0,106,11,117,115,117,97,114,105,111,95,
		105,100,0,106,7,99,114,101,97,116,101,0,106,25,
		67,72,65,82,65,67,84,69,82,32,40,32,51,32,
		41,32,78,79,84,32,78,85,76,76,0,177,1,0,
		106,11,99,84,97,98,108,101,78,97,109,101,0,106,
		7,99,114,101,97,116,101,0,106,23,86,65,82,67,
		72,65,82,40,32,51,48,32,41,32,78,79,84,32,
		78,85,76,76,0,177,1,0,106,13,99,66,114,111,
		119,115,101,83,116,97,116,101,0,106,7,99,114,101,
		97,116,101,0,106,13,86,65,82,67,72,65,82,40,
		50,53,48,41,0,177,1,0,106,13,99,67,111,108,
		117,109,110,79,114,100,101,114,0,106,7,99,114,101,
		97,116,101,0,106,23,86,65,82,67,72,65,82,40,
		32,51,48,32,41,32,78,79,84,32,78,85,76,76,
		0,177,1,0,106,13,99,79,114,105,101,110,116,97,
		116,105,111,110,0,106,7,99,114,101,97,116,101,0,
		106,25,67,72,65,82,65,67,84,69,82,32,40,32,
		49,32,41,32,78,79,84,32,78,85,76,76,0,177,
		1,0,106,12,110,73,100,70,111,114,82,101,99,110,
		111,0,106,7,99,114,101,97,116,101,0,106,13,73,
		78,84,32,78,79,84,32,78,85,76,76,0,177,1,
		0,177,7,0,112,1,73,36,32,0,48,2,0,48,
		16,0,102,112,0,112,0,73,36,34,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HISTORICOSUSUARIOSMODEL_GETHISTORY )
{
	static const HB_BYTE pcode[] =
	{
		13,3,1,36,44,0,106,67,83,69,76,69,67,84,
		32,99,66,114,111,119,115,101,83,116,97,116,101,44,
		32,99,67,111,108,117,109,110,79,114,100,101,114,44,
		32,99,79,114,105,101,110,116,97,116,105,111,110,44,
		32,110,73,100,70,111,114,82,101,99,110,111,32,70,
		82,79,77,32,0,48,17,0,102,112,0,72,106,2,
		32,0,72,106,20,87,72,69,82,69,32,99,84,97,
		98,108,101,78,97,109,101,32,61,32,0,72,176,18,
		0,95,1,12,1,72,106,19,32,65,78,68,32,117,
		115,117,97,114,105,111,95,105,100,32,61,32,0,72,
		176,18,0,48,19,0,176,20,0,12,0,112,0,12,
		1,72,80,4,36,46,0,166,88,0,0,113,56,0,
		0,89,15,0,1,0,0,0,176,21,0,95,1,12,
		1,6,178,36,47,0,48,22,0,176,23,0,12,0,
		95,4,112,1,80,2,36,48,0,48,24,0,95,2,
		92,2,112,1,80,3,73,114,32,0,0,36,49,0,
		115,73,36,51,0,176,25,0,176,26,0,48,27,0,
		176,23,0,12,0,112,0,12,1,20,1,167,30,0,
		0,36,55,0,176,28,0,95,2,12,1,31,13,36,
		56,0,48,29,0,95,2,112,0,73,36,57,0,168,
		36,61,0,176,28,0,95,3,12,1,31,22,176,30,
		0,95,3,12,1,28,13,36,62,0,176,31,0,95,
		3,20,1,7,36,65,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HISTORICOSUSUARIOSMODEL_SAVEHISTORY )
{
	static const HB_BYTE pcode[] =
	{
		13,2,5,36,74,0,176,28,0,95,5,12,1,28,
		8,36,75,0,102,110,7,36,81,0,106,18,40,32,
		83,69,76,69,67,84,32,105,100,32,70,82,79,77,
		32,0,48,17,0,102,112,0,72,106,21,32,87,72,
		69,82,69,32,99,84,97,98,108,101,78,97,109,101,
		32,61,32,0,72,176,18,0,95,1,12,1,72,106,
		6,32,65,78,68,32,0,72,106,15,32,117,115,117,
		97,114,105,111,95,105,100,32,61,32,0,72,176,18,
		0,48,19,0,176,20,0,12,0,112,0,12,1,72,
		106,3,32,41,0,72,80,7,36,97,0,106,14,82,
		69,80,76,65,67,69,32,73,78,84,79,32,0,48,
		17,0,102,112,0,72,106,10,32,32,40,32,32,105,
		100,44,32,0,72,106,13,117,115,117,97,114,105,111,
		95,105,100,44,32,0,72,106,13,99,84,97,98,108,
		101,78,97,109,101,44,32,0,72,106,15,99,66,114,
		111,119,115,101,83,116,97,116,101,44,32,0,72,106,
		15,99,67,111,108,117,109,110,79,114,100,101,114,44,
		32,0,72,106,15,99,79,114,105,101,110,116,97,116,
		105,111,110,44,32,0,72,106,15,110,73,100,70,111,
		114,82,101,99,110,111,32,41,32,0,72,106,11,32,
		32,86,65,76,85,69,83,32,40,0,72,95,7,72,
		106,3,44,32,0,72,176,18,0,48,19,0,176,20,
		0,12,0,112,0,12,1,72,106,3,44,32,0,72,
		176,18,0,95,1,12,1,72,106,2,44,0,72,95,
		2,72,106,3,44,32,0,72,176,18,0,95,3,12,
		1,72,106,3,44,32,0,72,176,18,0,95,4,12,
		1,72,106,3,44,32,0,72,176,32,0,176,33,0,
		95,5,12,1,12,1,72,106,2,41,0,72,80,6,
		36,99,0,48,22,0,102,95,6,112,1,73,36,101,
		0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,36,0,2,0,116,36,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

