/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\Prg\mail\TGenMailDatabaseFacturasClientes.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TGENMAILINGDATABASEFACTURASCLIENTES );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TGENMAILINGDATABASE );
HB_FUNC_STATIC( TGENMAILINGDATABASEFACTURASCLIENTES_NEW );
HB_FUNC_STATIC( TGENMAILINGDATABASEFACTURASCLIENTES_COLUMNPAGEDATABASE );
HB_FUNC_EXTERN( MAILREPORTFACCLI );
HB_FUNC_STATIC( TGENMAILINGDATABASEFACTURASCLIENTES_SETFACTURASCLIENTESSEND );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( AITMFACCLI );
HB_FUNC_EXTERN( D );
HB_FUNC_EXTERN( CFORMATOFACTURASCLIENTES );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( RETFLD );
HB_FUNC_EXTERN( ORDSETFOCUS );
HB_FUNC_EXTERN( DBGOTOP );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( CPORDIV );
HB_FUNC_EXTERN( HHASKEY );
HB_FUNC_EXTERN( HGET );
HB_FUNC_EXTERN( DBSEEKINORD );
HB_FUNC_EXTERN( DBRLOCK );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( TIMETOSTRING );
HB_FUNC_EXTERN( DBUNLOCK );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TGENMAILDATABASEFACTURASCLIENTES )
{ "TGENMAILINGDATABASEFACTURASCLIENTES", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TGENMAILINGDATABASEFACTURASCLIENTES )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TGENMAILINGDATABASE", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGENMAILINGDATABASE )}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGENMAILINGDATABASEFACTURASCLIENTES_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TGENMAILINGDATABASEFACTURASCLIENTES_NEW )}, NULL },
{ "TGENMAILINGDATABASEFACTURASCLIENTES_COLUMNPAGEDATABASE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TGENMAILINGDATABASEFACTURASCLIENTES_COLUMNPAGEDATABASE )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MAILREPORTFACCLI", {HB_FS_PUBLIC}, {HB_FUNCNAME( MAILREPORTFACCLI )}, NULL },
{ "CFORMATODOCUMENTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGENMAILINGDATABASEFACTURASCLIENTES_SETFACTURASCLIENTESSEND", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TGENMAILINGDATABASEFACTURASCLIENTES_SETFACTURASCLIENTESSEND )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETITEMS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AITMFACCLI", {HB_FS_PUBLIC}, {HB_FUNCNAME( AITMFACCLI )}, NULL },
{ "SETWORKAREA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FACTURASCLIENTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "D", {HB_FS_PUBLIC}, {HB_FUNCNAME( D )}, NULL },
{ "SETTYPEDOCUMENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETTYPEFORMAT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETFORMATODOCUMENTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CFORMATOFACTURASCLIENTES", {HB_FS_PUBLIC}, {HB_FUNCNAME( CFORMATOFACTURASCLIENTES )}, NULL },
{ "NVIEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSERIE", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "SETORDERDATABASE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETBMPDATABASE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETASUNTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETBLOCKRECIPIENTS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "RETFLD", {HB_FS_PUBLIC}, {HB_FUNCNAME( RETFLD )}, NULL },
{ "CCODCLI", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CLIENTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETPOSTSEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETFACTURASCLIENTESSEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETCARGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FACTURASCLIENTESID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETWORKAREA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDSETFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ORDSETFOCUS )}, NULL },
{ "DBGOTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBGOTOP )}, NULL },
{ "ADDCOL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OBRWDATABASE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CSORTORDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSTRDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BEDITVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LMAIL", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETCHECK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "NNUMFAC", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "_BLCLICKHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OORDERDATABASE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "DFECFAC", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CNOMCLI", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "NTOTFAC", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "_CEDITPICTURE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPORDIV", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPORDIV )}, NULL },
{ "_NDATASTRALIGN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHEADSTRALIGN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HHASKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HHASKEY )}, NULL },
{ "HGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGET )}, NULL },
{ "DBSEEKINORD", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBSEEKINORD )}, NULL },
{ "DBRLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBRLOCK )}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "DMAIL", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "TIMETOSTRING", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIMETOSTRING )}, NULL },
{ "TMAIL", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "DBUNLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBUNLOCK )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TGENMAILDATABASEFACTURASCLIENTES, ".\\Prg\\mail\\TGenMailDatabaseFacturasClientes.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TGENMAILDATABASEFACTURASCLIENTES
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TGENMAILDATABASEFACTURASCLIENTES )
   #include "hbiniseg.h"
#endif

HB_FUNC( TGENMAILINGDATABASEFACTURASCLIENTES )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,78,0,36,6,0,103,2,0,100,8,
		29,60,1,176,1,0,104,2,0,12,1,29,49,1,
		166,243,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,36,84,71,101,110,77,97,105,108,105,110,103,
		68,97,116,97,98,97,115,101,70,97,99,116,117,114,
		97,115,67,108,105,101,110,116,101,115,0,108,4,4,
		1,0,108,0,112,3,80,2,36,8,0,48,5,0,
		95,2,106,4,78,101,119,0,108,6,95,1,121,72,
		121,72,121,72,112,3,73,36,10,0,48,5,0,95,
		2,106,19,99,111,108,117,109,110,80,97,103,101,68,
		97,116,97,98,97,115,101,0,108,7,95,1,121,72,
		121,72,121,72,112,3,73,36,12,0,48,8,0,95,
		2,106,11,103,101,116,65,100,106,117,110,116,111,0,
		89,20,0,1,0,0,0,176,9,0,48,10,0,95,
		1,112,0,12,1,6,95,1,121,72,121,72,121,72,
		112,3,73,36,14,0,48,5,0,95,2,106,24,115,
		101,116,70,97,99,116,117,114,97,115,67,108,105,101,
		110,116,101,115,83,101,110,100,0,108,11,95,1,121,
		72,121,72,121,72,112,3,73,36,16,0,48,12,0,
		95,2,112,0,73,167,14,0,0,176,13,0,104,2,
		0,95,2,20,2,168,48,14,0,95,2,112,0,80,
		3,176,15,0,95,3,106,10,73,110,105,116,67,108,
		97,115,115,0,12,2,28,12,48,16,0,95,3,164,
		146,1,0,73,95,3,110,7,48,14,0,103,2,0,
		112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TGENMAILINGDATABASEFACTURASCLIENTES_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,20,0,102,80,2,36,22,0,48,12,
		0,95,2,112,0,73,36,24,0,48,2,0,48,17,
		0,95,2,112,0,95,1,112,1,73,36,26,0,48,
		18,0,95,2,176,19,0,12,0,112,1,73,36,28,
		0,48,20,0,95,2,48,21,0,176,22,0,12,0,
		95,1,112,1,112,1,73,36,30,0,48,23,0,95,
		2,106,8,110,70,97,99,67,108,105,0,112,1,73,
		36,32,0,48,24,0,95,2,106,3,70,67,0,112,
		1,73,36,34,0,48,25,0,95,2,176,26,0,48,
		21,0,176,22,0,12,0,48,27,0,95,2,112,0,
		112,1,88,28,0,12,1,112,1,73,36,36,0,48,
		29,0,95,2,106,7,78,250,109,101,114,111,0,106,
		6,70,101,99,104,97,0,106,7,67,243,100,105,103,
		111,0,106,7,78,111,109,98,114,101,0,4,4,0,
		112,1,73,36,38,0,48,30,0,95,2,106,26,103,
		99,95,100,111,99,117,109,101,110,116,95,116,101,120,
		116,95,117,115,101,114,50,95,52,56,0,112,1,73,
		36,40,0,48,31,0,95,2,106,81,69,110,118,105,
		111,32,100,101,32,110,117,101,115,116,114,97,32,102,
		97,99,116,117,114,97,32,100,101,32,99,108,105,101,
		110,116,101,32,123,83,101,114,105,101,32,100,101,32,
		108,97,32,102,97,99,116,117,114,97,125,47,123,78,
		250,109,101,114,111,32,100,101,32,108,97,32,102,97,
		99,116,117,114,97,125,0,112,1,73,36,42,0,48,
		32,0,95,2,89,67,0,0,0,1,0,2,0,176,
		33,0,176,34,0,48,21,0,176,22,0,12,0,48,
		27,0,95,255,112,0,112,1,88,35,0,48,36,0,
		176,22,0,12,0,48,27,0,95,255,112,0,112,1,
		106,8,99,77,101,105,73,110,116,0,12,3,12,1,
		6,112,1,73,36,44,0,48,37,0,95,2,89,19,
		0,1,0,1,0,2,0,48,38,0,95,255,95,1,
		112,1,6,112,1,73,36,46,0,48,39,0,95,2,
		89,22,0,0,0,1,0,1,0,48,40,0,176,22,
		0,12,0,95,255,112,1,6,112,1,73,36,48,0,
		85,48,41,0,95,2,112,0,74,176,42,0,106,6,
		108,77,97,105,108,0,20,1,74,36,49,0,85,48,
		41,0,95,2,112,0,74,176,43,0,20,0,74,36,
		51,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TGENMAILINGDATABASEFACTURASCLIENTES_COLUMNPAGEDATABASE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,55,0,102,80,2,36,57,0,48,44,
		0,48,45,0,95,2,112,0,112,0,143,36,58,0,
		144,46,0,106,17,83,101,46,32,115,101,108,101,99,
		99,105,111,110,97,100,111,0,112,1,73,36,59,0,
		144,47,0,106,6,108,77,97,105,108,0,112,1,73,
		36,60,0,144,48,0,90,6,106,1,0,6,112,1,
		73,36,61,0,144,49,0,89,20,0,0,0,1,0,
		2,0,48,41,0,95,255,112,0,88,50,0,6,112,
		1,73,36,62,0,144,51,0,92,20,112,1,73,36,
		63,0,144,52,0,106,6,83,101,108,49,54,0,106,
		6,78,105,108,49,54,0,4,2,0,112,1,73,145,
		36,66,0,48,44,0,48,45,0,95,2,112,0,112,
		0,143,36,67,0,144,46,0,106,7,78,250,109,101,
		114,111,0,112,1,73,36,68,0,144,47,0,106,8,
		110,78,117,109,70,97,99,0,112,1,73,36,69,0,
		144,49,0,89,46,0,0,0,1,0,2,0,48,41,
		0,95,255,112,0,88,28,0,106,2,47,0,72,176,
		33,0,176,53,0,48,41,0,95,255,112,0,88,54,
		0,12,1,12,1,72,6,112,1,73,36,70,0,144,
		51,0,92,80,112,1,73,36,71,0,144,55,0,89,
		29,0,4,0,1,0,2,0,48,56,0,48,57,0,
		95,255,112,0,48,58,0,95,4,112,0,112,1,6,
		112,1,73,145,36,74,0,48,44,0,48,45,0,95,
		2,112,0,112,0,143,36,75,0,144,46,0,106,6,
		70,101,99,104,97,0,112,1,73,36,76,0,144,47,
		0,106,8,100,70,101,99,68,101,115,0,112,1,73,
		36,77,0,144,49,0,89,25,0,0,0,1,0,2,
		0,176,59,0,48,41,0,95,255,112,0,88,60,0,
		12,1,6,112,1,73,36,78,0,144,51,0,92,80,
		112,1,73,36,79,0,144,55,0,89,29,0,4,0,
		1,0,2,0,48,56,0,48,57,0,95,255,112,0,
		48,58,0,95,4,112,0,112,1,6,112,1,73,145,
		36,82,0,48,44,0,48,45,0,95,2,112,0,112,
		0,143,36,83,0,144,46,0,106,7,67,243,100,105,
		103,111,0,112,1,73,36,84,0,144,47,0,106,8,
		99,67,111,100,67,108,105,0,112,1,73,36,85,0,
		144,49,0,89,20,0,0,0,1,0,2,0,48,41,
		0,95,255,112,0,88,35,0,6,112,1,73,36,86,
		0,144,51,0,92,70,112,1,73,36,87,0,144,55,
		0,89,29,0,4,0,1,0,2,0,48,56,0,48,
		57,0,95,255,112,0,48,58,0,95,4,112,0,112,
		1,6,112,1,73,145,36,90,0,48,44,0,48,45,
		0,95,2,112,0,112,0,143,36,91,0,144,46,0,
		106,7,78,111,109,98,114,101,0,112,1,73,36,92,
		0,144,47,0,106,8,99,78,111,109,67,108,105,0,
		112,1,73,36,93,0,144,49,0,89,20,0,0,0,
		1,0,2,0,48,41,0,95,255,112,0,88,61,0,
		6,112,1,73,36,94,0,144,51,0,93,44,1,112,
		1,73,36,95,0,144,55,0,89,29,0,4,0,1,
		0,2,0,48,56,0,48,57,0,95,255,112,0,48,
		58,0,95,4,112,0,112,1,6,112,1,73,145,36,
		98,0,48,44,0,48,45,0,95,2,112,0,112,0,
		143,36,99,0,144,46,0,106,6,84,111,116,97,108,
		0,112,1,73,36,100,0,144,49,0,89,20,0,0,
		0,1,0,2,0,48,41,0,95,255,112,0,88,62,
		0,6,112,1,73,36,101,0,144,63,0,176,64,0,
		12,0,112,1,73,36,102,0,144,51,0,92,80,112,
		1,73,36,103,0,144,65,0,122,112,1,73,36,104,
		0,144,66,0,122,112,1,73,145,36,107,0,95,2,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TGENMAILINGDATABASEFACTURASCLIENTES_SETFACTURASCLIENTESSEND )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,115,0,176,67,0,95,1,106,6,99,
		97,114,103,111,0,12,2,31,8,36,116,0,9,110,
		7,36,119,0,176,68,0,95,1,106,6,99,97,114,
		103,111,0,12,2,80,2,36,121,0,176,69,0,95,
		2,106,8,110,78,117,109,70,97,99,0,48,21,0,
		176,22,0,12,0,48,27,0,102,112,0,112,1,12,
		3,29,136,0,36,123,0,85,48,21,0,176,22,0,
		12,0,48,27,0,102,112,0,112,1,74,176,70,0,
		12,0,119,28,106,36,124,0,9,48,21,0,176,22,
		0,12,0,48,27,0,102,112,0,112,1,77,50,0,
		36,125,0,176,71,0,12,0,48,21,0,176,22,0,
		12,0,48,27,0,102,112,0,112,1,77,72,0,36,
		126,0,176,73,0,12,0,48,21,0,176,22,0,12,
		0,48,27,0,102,112,0,112,1,77,74,0,36,127,
		0,85,48,21,0,176,22,0,12,0,48,27,0,102,
		112,0,112,1,74,176,75,0,20,0,74,36,132,0,
		120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,78,0,2,0,116,78,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}
