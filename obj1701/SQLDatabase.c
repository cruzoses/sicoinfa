/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\SQLDatabase.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( SQLDATABASE );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_STATIC( SQLDATABASE_NEW );
HB_FUNC_STATIC( SQLDATABASE_CONNECT );
HB_FUNC_STATIC( SQLDATABASE_EXEC );
HB_FUNC_STATIC( SQLDATABASE_CHECKMODELSEXISTENCE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( TIPOSIMPRESORASMODEL );
HB_FUNC_EXTERN( TIPOSNOTASMODEL );
HB_FUNC_EXTERN( ETIQUETASMODEL );
HB_FUNC_EXTERN( SITUACIONESMODEL );
HB_FUNC_EXTERN( HISTORICOSUSUARIOSMODEL );
HB_FUNC_EXTERN( RELACIONESETIQUETASMODEL );
HB_FUNC_EXTERN( TIPOSVENTASMODEL );
HB_FUNC_EXTERN( CONFIGURACIONEMPRESASMODEL );
HB_FUNC_EXTERN( PROPIEDADESMODEL );
HB_FUNC_EXTERN( PROPIEDADESLINEASMODEL );
HB_FUNC_EXTERN( MOVIMIENTOSALMACENMODEL );
HB_FUNC_EXTERN( FULLCURDIR );
HB_FUNC_EXTERN( THDO );
HB_FUNC_EXTERN( LISDIR );
HB_FUNC_EXTERN( MAKEDIR );
HB_FUNC_EXTERN( BREAK );
HB_FUNC_EXTERN( AEVAL );
HB_FUNC( GETSQLDATABASE );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_SQLDATABASE )
{ "SQLDATABASE", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( SQLDATABASE )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLDATABASE_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLDATABASE_NEW )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCONEXION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLDATABASE_CONNECT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLDATABASE_CONNECT )}, NULL },
{ "DISCONNECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLDATABASE_EXEC", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLDATABASE_EXEC )}, NULL },
{ "QUERY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PREPARE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LASTINSERTID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BEGINTRANSACTION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "COMMIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ROLLBACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORINFO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLDATABASE_CHECKMODELSEXISTENCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLDATABASE_CHECKMODELSEXISTENCE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "AMODELS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETSQLCREATETABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TIPOSIMPRESORASMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIPOSIMPRESORASMODEL )}, NULL },
{ "TIPOSNOTASMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIPOSNOTASMODEL )}, NULL },
{ "ETIQUETASMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ETIQUETASMODEL )}, NULL },
{ "SITUACIONESMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( SITUACIONESMODEL )}, NULL },
{ "HISTORICOSUSUARIOSMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HISTORICOSUSUARIOSMODEL )}, NULL },
{ "RELACIONESETIQUETASMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( RELACIONESETIQUETASMODEL )}, NULL },
{ "TIPOSVENTASMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIPOSVENTASMODEL )}, NULL },
{ "CONFIGURACIONEMPRESASMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( CONFIGURACIONEMPRESASMODEL )}, NULL },
{ "PROPIEDADESMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROPIEDADESMODEL )}, NULL },
{ "PROPIEDADESLINEASMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( PROPIEDADESLINEASMODEL )}, NULL },
{ "MOVIMIENTOSALMACENMODEL", {HB_FS_PUBLIC}, {HB_FUNCNAME( MOVIMIENTOSALMACENMODEL )}, NULL },
{ "_CPATHDATABASESQLITE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FULLCURDIR", {HB_FS_PUBLIC}, {HB_FUNCNAME( FULLCURDIR )}, NULL },
{ "_CDATABASESQLITE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATHDATABASESQLITE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OCONEXION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "THDO", {HB_FS_PUBLIC}, {HB_FUNCNAME( THDO )}, NULL },
{ "SETATTRIBUTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LISDIR", {HB_FS_PUBLIC}, {HB_FUNCNAME( LISDIR )}, NULL },
{ "MAKEDIR", {HB_FS_PUBLIC}, {HB_FUNCNAME( MAKEDIR )}, NULL },
{ "CONNECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDATABASESQLITE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( BREAK )}, NULL },
{ "EXEC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AEVAL", {HB_FS_PUBLIC}, {HB_FUNCNAME( AEVAL )}, NULL },
{ "GETSQLDATABASE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETSQLDATABASE )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00003)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_SQLDATABASE, ".\\.\\Prg\\SQLDatabase.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_SQLDATABASE
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_SQLDATABASE )
   #include "hbiniseg.h"
#endif

HB_FUNC( SQLDATABASE )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,58,0,36,10,0,103,3,0,100,8,
		29,10,4,176,1,0,104,3,0,12,1,29,255,3,
		166,193,3,0,122,80,1,48,2,0,176,3,0,12,
		0,106,12,83,81,76,68,97,116,97,98,97,115,101,
		0,108,4,4,1,0,108,0,112,3,80,2,36,12,
		0,48,5,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,10,111,67,111,110,101,120,105,111,110,0,
		4,1,0,9,112,5,73,36,14,0,48,5,0,95,
		2,100,100,95,1,121,72,121,72,121,72,106,16,99,
		68,97,116,97,98,97,115,101,83,81,76,105,116,101,
		0,4,1,0,9,112,5,73,36,16,0,48,5,0,
		95,2,100,100,95,1,121,72,121,72,121,72,106,20,
		99,80,97,116,104,68,97,116,97,98,97,115,101,83,
		81,76,105,116,101,0,4,1,0,9,112,5,73,36,
		18,0,48,5,0,95,2,100,4,0,0,95,1,121,
		72,121,72,121,72,106,8,97,77,111,100,101,108,115,
		0,4,1,0,9,112,5,73,36,20,0,48,6,0,
		95,2,106,4,78,101,119,0,108,7,95,1,92,8,
		72,121,72,121,72,112,3,73,36,22,0,48,8,0,
		95,2,106,9,67,111,110,101,120,105,111,110,0,89,
		15,0,1,0,0,0,48,9,0,95,1,112,0,6,
		95,1,121,72,121,72,121,72,112,3,73,36,24,0,
		48,6,0,95,2,106,8,67,111,110,110,101,99,116,
		0,108,10,95,1,121,72,121,72,121,72,112,3,73,
		36,25,0,48,8,0,95,2,106,11,68,105,115,99,
		111,110,110,101,99,116,0,89,20,0,1,0,0,0,
		48,11,0,48,9,0,95,1,112,0,112,0,6,95,
		1,121,72,121,72,121,72,112,3,73,36,27,0,48,
		6,0,95,2,106,5,69,120,101,99,0,108,12,95,
		1,121,72,121,72,121,72,112,3,73,36,28,0,48,
		8,0,95,2,106,6,81,117,101,114,121,0,89,22,
		0,2,0,0,0,48,13,0,48,9,0,95,1,112,
		0,95,2,112,1,6,95,1,121,72,121,72,121,72,
		112,3,73,36,29,0,48,8,0,95,2,106,8,80,
		114,101,112,97,114,101,0,89,22,0,2,0,0,0,
		48,14,0,48,9,0,95,1,112,0,95,2,112,1,
		6,95,1,121,72,121,72,121,72,112,3,73,36,31,
		0,48,8,0,95,2,106,13,76,97,115,116,73,110,
		115,101,114,116,73,100,0,89,20,0,1,0,0,0,
		48,15,0,48,9,0,95,1,112,0,112,0,6,95,
		1,121,72,121,72,121,72,112,3,73,36,33,0,48,
		8,0,95,2,106,17,98,101,103,105,110,84,114,97,
		110,115,97,99,116,105,111,110,0,89,20,0,1,0,
		0,0,48,16,0,48,9,0,95,1,112,0,112,0,
		6,95,1,121,72,121,72,121,72,112,3,73,36,34,
		0,48,8,0,95,2,106,7,99,111,109,109,105,116,
		0,89,20,0,1,0,0,0,48,17,0,48,9,0,
		95,1,112,0,112,0,6,95,1,121,72,121,72,121,
		72,112,3,73,36,35,0,48,8,0,95,2,106,9,
		114,111,108,108,98,97,99,107,0,89,20,0,1,0,
		0,0,48,18,0,48,9,0,95,1,112,0,112,0,
		6,95,1,121,72,121,72,121,72,112,3,73,36,37,
		0,48,8,0,95,2,106,16,115,116,97,114,116,70,
		111,114,101,105,103,110,75,101,121,0,89,42,0,1,
		0,0,0,48,13,0,95,1,106,25,112,114,97,103,
		109,97,32,102,111,114,101,105,103,110,95,107,101,121,
		115,32,61,32,79,78,0,112,1,6,95,1,121,72,
		121,72,121,72,112,3,73,36,38,0,48,8,0,95,
		2,106,14,101,110,100,70,111,114,101,105,103,110,75,
		101,121,0,89,43,0,1,0,0,0,48,13,0,95,
		1,106,26,112,114,97,103,109,97,32,102,111,114,101,
		105,103,110,95,107,101,121,115,32,61,32,79,70,70,
		0,112,1,6,95,1,121,72,121,72,121,72,112,3,
		73,36,40,0,48,8,0,95,2,106,10,101,114,114,
		111,114,73,110,102,111,0,89,20,0,1,0,0,0,
		48,19,0,48,9,0,95,1,112,0,112,0,6,95,
		1,121,72,121,72,121,72,112,3,73,36,42,0,48,
		6,0,95,2,106,21,99,104,101,99,107,77,111,100,
		101,108,115,69,120,105,115,116,101,110,99,101,0,108,
		20,95,1,121,72,121,72,121,72,112,3,73,36,44,
		0,48,21,0,95,2,112,0,73,167,14,0,0,176,
		22,0,104,3,0,95,2,20,2,168,48,23,0,95,
		2,112,0,80,3,176,24,0,95,3,106,10,73,110,
		105,116,67,108,97,115,115,0,12,2,28,12,48,25,
		0,95,3,164,146,1,0,73,95,3,110,7,48,23,
		0,103,3,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLDATABASE_NEW )
{
	static const HB_BYTE pcode[] =
	{
		36,50,0,176,26,0,48,27,0,102,112,0,48,28,
		0,48,2,0,176,29,0,12,0,112,0,112,0,20,
		2,36,52,0,176,26,0,48,27,0,102,112,0,48,
		28,0,48,2,0,176,30,0,12,0,112,0,112,0,
		20,2,36,54,0,176,26,0,48,27,0,102,112,0,
		48,28,0,48,2,0,176,31,0,12,0,112,0,112,
		0,20,2,36,56,0,176,26,0,48,27,0,102,112,
		0,48,28,0,48,2,0,176,32,0,12,0,112,0,
		112,0,20,2,36,58,0,176,26,0,48,27,0,102,
		112,0,48,28,0,48,2,0,176,33,0,12,0,112,
		0,112,0,20,2,36,60,0,176,26,0,48,27,0,
		102,112,0,48,28,0,48,2,0,176,34,0,12,0,
		112,0,112,0,20,2,36,62,0,176,26,0,48,27,
		0,102,112,0,48,28,0,48,2,0,176,35,0,12,
		0,112,0,112,0,20,2,36,64,0,176,26,0,48,
		27,0,102,112,0,48,28,0,48,2,0,176,36,0,
		12,0,112,0,112,0,20,2,36,66,0,176,26,0,
		48,27,0,102,112,0,48,28,0,48,2,0,176,37,
		0,12,0,112,0,112,0,20,2,36,68,0,176,26,
		0,48,27,0,102,112,0,48,28,0,48,2,0,176,
		38,0,12,0,112,0,112,0,20,2,36,70,0,176,
		26,0,48,27,0,102,112,0,48,28,0,48,2,0,
		176,39,0,12,0,112,0,112,0,20,2,36,72,0,
		48,40,0,102,176,41,0,12,0,106,10,68,97,116,
		97,98,97,115,101,92,0,72,112,1,73,36,74,0,
		48,42,0,102,48,43,0,102,112,0,106,11,71,101,
		115,116,111,111,108,46,100,98,0,72,112,1,73,36,
		76,0,48,44,0,102,48,2,0,176,45,0,12,0,
		106,7,115,113,108,105,116,101,0,112,1,112,1,73,
		36,78,0,48,46,0,48,9,0,102,112,0,92,5,
		120,112,2,73,36,80,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLDATABASE_CONNECT )
{
	static const HB_BYTE pcode[] =
	{
		36,86,0,176,47,0,48,43,0,102,112,0,12,1,
		31,16,36,87,0,176,48,0,48,43,0,102,112,0,
		20,1,36,90,0,48,49,0,48,9,0,102,112,0,
		48,50,0,102,112,0,112,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLDATABASE_EXEC )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,96,0,120,80,2,36,98,0,113,42,
		0,0,89,15,0,1,0,0,0,176,51,0,95,1,
		12,1,6,178,36,99,0,48,52,0,48,9,0,102,
		112,0,95,1,112,1,73,73,114,15,0,0,36,100,
		0,115,73,36,101,0,9,80,2,36,104,0,95,2,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLDATABASE_CHECKMODELSEXISTENCE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,108,0,102,80,1,36,110,0,176,53,
		0,48,27,0,95,1,112,0,89,19,0,1,0,1,
		0,1,0,48,52,0,95,255,95,1,112,1,6,20,
		2,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( GETSQLDATABASE )
{
	static const HB_BYTE pcode[] =
	{
		116,58,0,36,116,0,176,55,0,103,2,0,12,1,
		28,18,36,117,0,48,2,0,176,0,0,12,0,112,
		0,82,2,0,36,120,0,103,2,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,58,0,3,0,116,58,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

