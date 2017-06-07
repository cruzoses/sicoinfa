/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\TpvPunto.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( STPVPUNTO );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_STATIC( STPVPUNTO_CREATEFROMSALA );
HB_FUNC_STATIC( STPVPUNTO_CREATEFROMSALON );
HB_FUNC_STATIC( STPVPUNTO_CREATEMESA );
HB_FUNC_STATIC( STPVPUNTO_LOADMESA );
HB_FUNC_STATIC( STPVPUNTO_LLEVAR );
HB_FUNC_STATIC( STPVPUNTO_ENCARGAR );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_STATIC( STPVPUNTO_CTEXTOPUNTO );
HB_FUNC_STATIC( STPVPUNTO_CIMAGENPUNTO );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_STATIC( STPVPUNTO_LMULTIPLETICKET );
HB_FUNC_STATIC( STPVPUNTO_NTOTALMULTIPLETICKET );
HB_FUNC_STATIC( STPVPUNTO_CTEXTOTOTALTIKET );
HB_FUNC_STATIC( STPVPUNTO_NIMAGENTIKET );
HB_FUNC_STATIC( STPVPUNTO_CALIASTIKET );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( TTPVMESA );
HB_FUNC_EXTERN( ISCHAR );
HB_FUNC_EXTERN( ISTRUE );
HB_FUNC_EXTERN( ISFALSE );
HB_FUNC_EXTERN( UFIELDEMPRESA );
HB_FUNC_EXTERN( MAX );
HB_FUNC_EXTERN( PADR );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( TRANSFORM );
HB_FUNC_EXTERN( CPORDIV );
HB_FUNC_EXTERN( CSIMDIV );
HB_FUNC_EXTERN( UPPER );
HB_FUNC_EXTERN( RTRIM );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TPVPUNTO )
{ "STPVPUNTO", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STPVPUNTO_CREATEFROMSALA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_CREATEFROMSALA )}, NULL },
{ "STPVPUNTO_CREATEFROMSALON", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_CREATEFROMSALON )}, NULL },
{ "STPVPUNTO_CREATEMESA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_CREATEMESA )}, NULL },
{ "STPVPUNTO_LOADMESA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_LOADMESA )}, NULL },
{ "STPVPUNTO_LLEVAR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_LLEVAR )}, NULL },
{ "STPVPUNTO_ENCARGAR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_ENCARGAR )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODIGOSALA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPUNTOVENTA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSERIE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CNUMERO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSUFIJO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "STPVPUNTO_CTEXTOPUNTO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_CTEXTOPUNTO )}, NULL },
{ "STPVPUNTO_CIMAGENPUNTO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_CIMAGENPUNTO )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "CTEXTOPUNTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTEXTOTIKET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NUBICACION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OTIKETCABECERA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSENDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STPVPUNTO_LMULTIPLETICKET", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_LMULTIPLETICKET )}, NULL },
{ "STPVPUNTO_NTOTALMULTIPLETICKET", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_NTOTALMULTIPLETICKET )}, NULL },
{ "STPVPUNTO_CTEXTOTOTALTIKET", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_CTEXTOTOTALTIKET )}, NULL },
{ "STPVPUNTO_NIMAGENTIKET", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_NIMAGENTIKET )}, NULL },
{ "STPVPUNTO_CALIASTIKET", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STPVPUNTO_CALIASTIKET )}, NULL },
{ "_OSALON", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSALON", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCLIENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OWND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NNUMERO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OSENDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETSALON", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CPUNTOVENTA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FIELDGETBYNAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODETSALAVTA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTYPE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODIGOSALA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NPRECIO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NPRECIO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NPRECMB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NPRECMB", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LCOMENSAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LCOMENSAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LMULTIPLICAR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LMULTIPLICAR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NUBICACION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CIMAGEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CIMAGENPUNTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTYPE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TTPVMESA", {HB_FS_PUBLIC}, {HB_FUNCNAME( TTPVMESA )}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETSALONWND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LOADFROMPUNTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ISCHAR", {HB_FS_PUBLIC}, {HB_FUNCNAME( ISCHAR )}, NULL },
{ "ISTRUE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ISTRUE )}, NULL },
{ "NESTADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DISABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ISFALSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ISFALSE )}, NULL },
{ "_OMESA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CSERIE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNUMERO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CSUFIJO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DFECHA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CHORA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMBRE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTOTAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LABIERTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "UFIELDEMPRESA", {HB_FS_PUBLIC}, {HB_FUNCNAME( UFIELDEMPRESA )}, NULL },
{ "CSERTIK", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CNUMTIK", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CSUFTIK", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "DFECTIK", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CHORTIK", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "CALIASTIK", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "MAX", {HB_FS_PUBLIC}, {HB_FUNCNAME( MAX )}, NULL },
{ "_OSALA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSALA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDESCRIPCION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NESTADO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LMULTIPLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETSTATUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEKINORD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPUNTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LMULTIPLETICKET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LMULTIPLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOTALMULTIPLETICKET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETSTATUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDSETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PADR", {HB_FS_PUBLIC}, {HB_FUNCNAME( PADR )}, NULL },
{ "EOF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "SKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "TRANSFORM", {HB_FS_PUBLIC}, {HB_FUNCNAME( TRANSFORM )}, NULL },
{ "NTOTAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPORDIV", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPORDIV )}, NULL },
{ "CSIMDIV", {HB_FS_PUBLIC}, {HB_FUNCNAME( CSIMDIV )}, NULL },
{ "CTIKET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LABIERTO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "UPPER", {HB_FS_PUBLIC}, {HB_FUNCNAME( UPPER )}, NULL },
{ "RTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( RTRIM )}, NULL },
{ "CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TPVPUNTO, ".\\.\\Prg\\TpvPunto.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TPVPUNTO
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TPVPUNTO )
   #include "hbiniseg.h"
#endif

HB_FUNC( STPVPUNTO )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,127,0,36,96,0,103,2,0,100,8,
		29,146,9,176,1,0,104,2,0,12,1,29,135,9,
		166,73,9,0,122,80,1,48,2,0,176,3,0,12,
		0,106,10,115,84,112,118,80,117,110,116,111,0,108,
		4,4,1,0,108,0,112,3,80,2,36,98,0,48,
		5,0,95,2,100,100,95,1,121,72,121,72,121,72,
		106,8,111,83,101,110,100,101,114,0,4,1,0,9,
		112,5,73,36,100,0,48,5,0,95,2,100,121,95,
		1,121,72,121,72,121,72,106,8,110,78,117,109,101,
		114,111,0,4,1,0,9,112,5,73,36,102,0,48,
		5,0,95,2,100,100,95,1,121,72,121,72,121,72,
		106,6,111,83,97,108,97,0,4,1,0,9,112,5,
		73,36,104,0,48,5,0,95,2,100,100,95,1,121,
		72,121,72,121,72,106,12,99,67,111,100,105,103,111,
		83,97,108,97,0,4,1,0,9,112,5,73,36,105,
		0,48,5,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,12,99,80,117,110,116,111,86,101,110,116,
		97,0,4,1,0,9,112,5,73,36,107,0,48,5,
		0,95,2,100,106,1,0,95,1,121,72,121,72,121,
		72,106,7,99,65,108,105,97,115,0,4,1,0,9,
		112,5,73,36,108,0,48,5,0,95,2,100,106,1,
		0,95,1,121,72,121,72,121,72,106,8,99,78,111,
		109,98,114,101,0,4,1,0,9,112,5,73,36,110,
		0,48,5,0,95,2,100,122,95,1,121,72,121,72,
		121,72,106,8,110,69,115,116,97,100,111,0,4,1,
		0,9,112,5,73,36,112,0,48,5,0,95,2,100,
		106,1,0,95,1,121,72,121,72,121,72,106,7,99,
		83,101,114,105,101,0,4,1,0,9,112,5,73,36,
		113,0,48,5,0,95,2,100,106,1,0,95,1,121,
		72,121,72,121,72,106,8,99,78,117,109,101,114,111,
		0,4,1,0,9,112,5,73,36,114,0,48,5,0,
		95,2,100,106,1,0,95,1,121,72,121,72,121,72,
		106,8,99,83,117,102,105,106,111,0,4,1,0,9,
		112,5,73,36,116,0,48,5,0,95,2,100,134,0,
		0,0,0,95,1,121,72,121,72,121,72,106,7,100,
		70,101,99,104,97,0,4,1,0,9,112,5,73,36,
		117,0,48,5,0,95,2,100,106,1,0,95,1,121,
		72,121,72,121,72,106,6,99,72,111,114,97,0,4,
		1,0,9,112,5,73,36,119,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,8,99,73,
		109,97,103,101,110,0,4,1,0,9,112,5,73,36,
		120,0,48,5,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,8,110,80,114,101,99,105,111,0,4,
		1,0,9,112,5,73,36,121,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,8,110,80,
		114,101,67,109,98,0,4,1,0,9,112,5,73,36,
		123,0,48,5,0,95,2,100,9,95,1,121,72,121,
		72,121,72,106,10,108,67,111,109,101,110,115,97,108,
		0,4,1,0,9,112,5,73,36,124,0,48,5,0,
		95,2,100,106,1,0,95,1,121,72,121,72,121,72,
		106,10,99,65,114,116,105,99,117,108,111,0,4,1,
		0,9,112,5,73,36,125,0,48,5,0,95,2,100,
		9,95,1,121,72,121,72,121,72,106,13,108,77,117,
		108,116,105,112,108,105,99,97,114,0,4,1,0,9,
		112,5,73,36,127,0,48,5,0,95,2,100,121,95,
		1,121,72,121,72,121,72,106,7,110,84,111,116,97,
		108,0,4,1,0,9,112,5,73,36,128,0,48,5,
		0,95,2,100,106,1,0,95,1,121,72,121,72,121,
		72,106,7,99,84,111,116,97,108,0,4,1,0,9,
		112,5,73,36,130,0,48,5,0,95,2,100,106,1,
		0,95,1,121,72,121,72,121,72,106,9,99,84,111,
		111,108,84,105,112,0,4,1,0,9,112,5,73,36,
		132,0,48,5,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,9,108,65,98,105,101,114,116,111,0,
		4,1,0,9,112,5,73,36,133,0,48,5,0,95,
		2,100,100,95,1,121,72,121,72,121,72,106,11,110,
		85,98,105,99,97,99,105,111,110,0,4,1,0,9,
		112,5,73,36,135,0,48,5,0,95,2,100,9,95,
		1,121,72,121,72,121,72,106,10,108,77,117,108,116,
		105,112,108,101,0,4,1,0,9,112,5,73,36,137,
		0,48,5,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,6,110,84,121,112,101,0,4,1,0,9,
		112,5,73,36,139,0,48,5,0,95,2,100,121,95,
		1,121,72,121,72,121,72,106,5,110,84,111,112,0,
		4,1,0,9,112,5,73,36,140,0,48,5,0,95,
		2,100,121,95,1,121,72,121,72,121,72,106,6,110,
		76,101,102,116,0,4,1,0,9,112,5,73,36,141,
		0,48,5,0,95,2,100,93,160,0,95,1,121,72,
		121,72,121,72,106,8,110,72,101,105,103,104,116,0,
		4,1,0,9,112,5,73,36,142,0,48,5,0,95,
		2,100,92,100,95,1,121,72,121,72,121,72,106,7,
		110,87,105,100,116,104,0,4,1,0,9,112,5,73,
		36,144,0,48,5,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,7,111,83,97,108,111,110,0,4,
		1,0,9,112,5,73,36,146,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,6,111,77,
		101,115,97,0,4,1,0,9,112,5,73,36,148,0,
		48,6,0,95,2,106,15,67,114,101,97,116,101,70,
		114,111,109,83,97,108,97,0,108,7,95,1,121,72,
		121,72,121,72,112,3,73,36,149,0,48,6,0,95,
		2,106,16,67,114,101,97,116,101,70,114,111,109,83,
		97,108,111,110,0,108,8,95,1,121,72,121,72,121,
		72,112,3,73,36,151,0,48,6,0,95,2,106,11,
		67,114,101,97,116,101,77,101,115,97,0,108,9,95,
		1,121,72,121,72,121,72,112,3,73,36,152,0,48,
		6,0,95,2,106,9,76,111,97,100,77,101,115,97,
		0,108,10,95,1,121,72,121,72,121,72,112,3,73,
		36,154,0,48,6,0,95,2,106,7,76,108,101,118,
		97,114,0,108,11,95,1,121,72,121,72,121,72,112,
		3,73,36,156,0,48,6,0,95,2,106,9,69,110,
		99,97,114,103,97,114,0,108,12,95,1,121,72,121,
		72,121,72,112,3,73,36,158,0,48,13,0,95,2,
		106,7,99,80,117,110,116,111,0,89,23,0,1,0,
		0,0,48,14,0,95,1,112,0,48,15,0,95,1,
		112,0,72,6,95,1,121,72,121,72,121,72,112,3,
		73,36,159,0,48,13,0,95,2,106,6,99,83,97,
		108,97,0,89,15,0,1,0,0,0,48,14,0,95,
		1,112,0,6,95,1,121,72,121,72,121,72,112,3,
		73,36,161,0,48,13,0,95,2,106,7,99,84,105,
		107,101,116,0,89,31,0,1,0,0,0,48,16,0,
		95,1,112,0,48,17,0,95,1,112,0,72,48,18,
		0,95,1,112,0,72,6,95,1,121,72,121,72,121,
		72,112,3,73,36,162,0,48,13,0,95,2,106,12,
		99,84,101,120,116,111,84,105,107,101,116,0,89,51,
		0,1,0,0,0,48,16,0,95,1,112,0,106,2,
		47,0,72,176,19,0,48,17,0,95,1,112,0,12,
		1,72,106,2,47,0,72,176,19,0,48,18,0,95,
		1,112,0,12,1,72,6,95,1,121,72,121,72,121,
		72,112,3,73,36,164,0,48,6,0,95,2,106,12,
		99,84,101,120,116,111,80,117,110,116,111,0,108,20,
		95,1,121,72,121,72,121,72,112,3,73,36,165,0,
		48,6,0,95,2,106,13,99,73,109,97,103,101,110,
		80,117,110,116,111,0,108,21,95,1,121,72,121,72,
		121,72,112,3,73,36,167,0,48,13,0,95,2,106,
		7,99,84,101,120,116,111,0,89,38,0,1,0,0,
		0,176,22,0,48,15,0,95,1,112,0,12,1,31,
		11,48,23,0,95,1,112,0,25,9,48,24,0,95,
		1,112,0,6,95,1,121,72,121,72,121,72,112,3,
		73,36,169,0,48,13,0,95,2,106,10,108,71,101,
		110,101,114,105,99,111,0,89,17,0,1,0,0,0,
		48,25,0,95,1,112,0,121,8,6,95,1,121,72,
		121,72,121,72,112,3,73,36,170,0,48,13,0,95,
		2,106,8,108,76,108,101,118,97,114,0,89,17,0,
		1,0,0,0,48,25,0,95,1,112,0,122,8,6,
		95,1,121,72,121,72,121,72,112,3,73,36,171,0,
		48,13,0,95,2,106,9,108,82,101,99,111,103,101,
		114,0,89,18,0,1,0,0,0,48,25,0,95,1,
		112,0,92,3,8,6,95,1,121,72,121,72,121,72,
		112,3,73,36,172,0,48,13,0,95,2,106,10,108,
		69,110,99,97,114,103,97,114,0,89,18,0,1,0,
		0,0,48,25,0,95,1,112,0,92,4,8,6,95,
		1,121,72,121,72,121,72,112,3,73,36,174,0,48,
		13,0,95,2,106,15,111,84,105,107,101,116,67,97,
		98,101,99,101,114,97,0,89,30,0,1,0,0,0,
		48,26,0,48,27,0,48,27,0,48,27,0,95,1,
		112,0,112,0,112,0,112,0,6,95,1,121,72,121,
		72,121,72,112,3,73,36,176,0,48,6,0,95,2,
		106,16,108,77,117,108,116,105,112,108,101,84,105,99,
		107,101,116,0,108,28,95,1,121,72,121,72,121,72,
		112,3,73,36,178,0,48,6,0,95,2,106,21,110,
		84,111,116,97,108,77,117,108,116,105,112,108,101,84,
		105,99,107,101,116,0,108,29,95,1,121,72,121,72,
		121,72,112,3,73,36,180,0,48,6,0,95,2,106,
		17,99,84,101,120,116,111,84,111,116,97,108,84,105,
		107,101,116,0,108,30,95,1,121,72,121,72,121,72,
		112,3,73,36,181,0,48,6,0,95,2,106,13,110,
		73,109,97,103,101,110,84,105,107,101,116,0,108,31,
		95,1,121,72,121,72,121,72,112,3,73,36,182,0,
		48,6,0,95,2,106,12,99,65,108,105,97,115,84,
		105,107,101,116,0,108,32,95,1,121,72,121,72,121,
		72,112,3,73,36,184,0,48,13,0,95,2,106,9,
		83,101,116,83,97,108,111,110,0,89,17,0,2,0,
		0,0,48,33,0,95,1,95,2,112,1,6,95,1,
		121,72,121,72,121,72,112,3,73,36,185,0,48,13,
		0,95,2,106,9,71,101,116,83,97,108,111,110,0,
		89,15,0,2,0,0,0,48,34,0,95,1,112,0,
		6,95,1,121,72,121,72,121,72,112,3,73,36,186,
		0,48,13,0,95,2,106,12,71,101,116,83,97,108,
		111,110,87,110,100,0,89,25,0,1,0,0,0,48,
		35,0,48,36,0,48,34,0,95,1,112,0,112,0,
		112,0,6,95,1,121,72,121,72,121,72,112,3,73,
		36,190,0,48,37,0,95,2,112,0,73,167,14,0,
		0,176,38,0,104,2,0,95,2,20,2,168,48,39,
		0,95,2,112,0,80,3,176,40,0,95,3,106,10,
		73,110,105,116,67,108,97,115,115,0,12,2,28,12,
		48,41,0,95,3,164,146,1,0,73,95,3,110,7,
		48,39,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_CREATEFROMSALA )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,200,0,48,42,0,102,95,1,112,1,
		73,36,201,0,48,43,0,102,95,2,112,1,73,36,
		203,0,48,44,0,102,48,34,0,48,27,0,48,27,
		0,102,112,0,112,0,112,0,112,1,73,36,205,0,
		48,45,0,102,48,46,0,48,47,0,48,48,0,48,
		27,0,48,27,0,102,112,0,112,0,112,0,112,0,
		106,9,99,68,101,115,99,114,105,112,0,112,1,112,
		1,73,36,206,0,48,49,0,102,48,46,0,48,47,
		0,48,48,0,48,27,0,48,27,0,102,112,0,112,
		0,112,0,112,0,106,6,110,84,105,112,111,0,112,
		1,112,1,73,36,207,0,48,50,0,102,48,46,0,
		48,47,0,48,48,0,48,27,0,48,27,0,102,112,
		0,112,0,112,0,112,0,106,6,110,70,105,108,97,
		0,112,1,112,1,73,36,208,0,48,51,0,102,48,
		46,0,48,47,0,48,48,0,48,27,0,48,27,0,
		102,112,0,112,0,112,0,112,0,106,9,110,67,111,
		108,117,109,110,97,0,112,1,112,1,73,36,210,0,
		48,52,0,102,48,53,0,48,27,0,102,112,0,112,
		0,112,1,73,36,211,0,48,54,0,102,48,55,0,
		48,27,0,102,112,0,112,0,112,1,73,36,212,0,
		48,56,0,102,48,57,0,48,27,0,102,112,0,112,
		0,112,1,73,36,213,0,48,58,0,102,48,59,0,
		48,27,0,102,112,0,112,0,112,1,73,36,214,0,
		48,60,0,102,48,61,0,48,27,0,102,112,0,112,
		0,112,1,73,36,215,0,48,62,0,102,48,63,0,
		48,27,0,102,112,0,112,0,112,1,73,36,217,0,
		48,64,0,102,92,2,112,1,73,36,219,0,48,65,
		0,102,48,66,0,102,48,67,0,102,112,0,112,1,
		112,1,73,36,221,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_CREATEMESA )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,230,0,48,2,0,176,68,0,12,0,
		48,69,0,102,112,0,48,70,0,102,112,0,48,67,
		0,102,112,0,48,71,0,102,112,0,112,4,80,2,
		36,232,0,48,72,0,95,2,102,112,1,73,36,234,
		0,176,22,0,95,2,12,1,31,94,176,73,0,48,
		15,0,95,2,112,0,12,1,28,80,36,236,0,176,
		74,0,95,1,12,1,28,23,48,75,0,102,112,0,
		122,34,28,13,36,237,0,48,76,0,95,2,112,0,
		73,36,240,0,176,77,0,95,1,12,1,28,23,48,
		75,0,102,112,0,122,15,28,13,36,241,0,48,76,
		0,95,2,112,0,73,36,244,0,48,78,0,102,95,
		2,112,1,73,36,248,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_CREATEFROMSALON )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,254,0,48,42,0,102,95,1,112,1,
		73,36,0,1,48,43,0,102,95,2,112,1,73,36,
		2,1,48,44,0,102,95,2,112,1,73,36,4,1,
		48,50,0,102,48,69,0,95,2,112,0,112,1,73,
		36,5,1,48,51,0,102,48,70,0,95,2,112,0,
		112,1,73,36,6,1,48,49,0,102,48,67,0,95,
		2,112,0,112,1,73,36,8,1,48,79,0,102,48,
		46,0,48,26,0,48,27,0,48,27,0,95,2,112,
		0,112,0,112,0,106,8,99,83,101,114,84,105,107,
		0,112,1,112,1,73,36,9,1,48,80,0,102,48,
		46,0,48,26,0,48,27,0,48,27,0,95,2,112,
		0,112,0,112,0,106,8,99,78,117,109,84,105,107,
		0,112,1,112,1,73,36,10,1,48,81,0,102,48,
		46,0,48,26,0,48,27,0,48,27,0,95,2,112,
		0,112,0,112,0,106,8,99,83,117,102,84,105,107,
		0,112,1,112,1,73,36,11,1,48,82,0,102,48,
		46,0,48,26,0,48,27,0,48,27,0,95,2,112,
		0,112,0,112,0,106,8,100,70,101,99,84,105,107,
		0,112,1,112,1,73,36,12,1,48,83,0,102,48,
		46,0,48,26,0,48,27,0,48,27,0,95,2,112,
		0,112,0,112,0,106,8,99,72,111,114,84,105,107,
		0,112,1,112,1,73,36,13,1,48,52,0,102,48,
		46,0,48,26,0,48,27,0,48,27,0,95,2,112,
		0,112,0,112,0,106,9,99,67,111,100,83,97,108,
		97,0,112,1,112,1,73,36,14,1,48,45,0,102,
		48,46,0,48,26,0,48,27,0,48,27,0,95,2,
		112,0,112,0,112,0,106,10,99,80,110,116,86,101,
		110,116,97,0,112,1,112,1,73,36,15,1,48,84,
		0,102,48,46,0,48,26,0,48,27,0,48,27,0,
		95,2,112,0,112,0,112,0,106,10,99,65,108,105,
		97,115,84,105,107,0,112,1,112,1,73,36,16,1,
		48,85,0,102,48,46,0,48,26,0,48,27,0,48,
		27,0,95,2,112,0,112,0,112,0,106,8,99,78,
		111,109,84,105,107,0,112,1,112,1,73,36,17,1,
		48,54,0,102,48,46,0,48,26,0,48,27,0,48,
		27,0,95,2,112,0,112,0,112,0,106,8,110,84,
		97,114,105,102,97,0,112,1,112,1,73,36,18,1,
		48,86,0,102,48,46,0,48,26,0,48,27,0,48,
		27,0,95,2,112,0,112,0,112,0,106,8,110,84,
		111,116,84,105,107,0,112,1,112,1,73,36,19,1,
		48,87,0,102,48,46,0,48,26,0,48,27,0,48,
		27,0,95,2,112,0,112,0,112,0,106,9,108,65,
		98,105,101,114,116,111,0,112,1,112,1,73,36,20,
		1,48,64,0,102,48,46,0,48,26,0,48,27,0,
		48,27,0,95,2,112,0,112,0,112,0,106,8,110,
		85,98,105,84,105,107,0,112,1,112,1,73,36,22,
		1,48,56,0,102,176,88,0,106,9,110,80,114,101,
		84,67,109,98,0,12,1,112,1,73,36,24,1,102,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_LLEVAR )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,30,1,48,42,0,102,121,112,1,73,
		36,32,1,176,22,0,95,1,12,1,31,94,36,33,
		1,48,79,0,102,95,1,88,89,0,112,1,73,36,
		34,1,48,80,0,102,95,1,88,90,0,112,1,73,
		36,35,1,48,81,0,102,95,1,88,91,0,112,1,
		73,36,36,1,48,82,0,102,95,1,88,92,0,112,
		1,73,36,37,1,48,83,0,102,95,1,88,93,0,
		112,1,73,36,38,1,48,84,0,102,95,1,88,94,
		0,112,1,73,25,82,36,41,1,48,79,0,102,106,
		1,0,112,1,73,36,42,1,48,80,0,102,106,1,
		0,112,1,73,36,43,1,48,81,0,102,106,1,0,
		112,1,73,36,44,1,48,82,0,102,134,0,0,0,
		0,112,1,73,36,45,1,48,83,0,102,106,1,0,
		112,1,73,36,46,1,48,84,0,102,106,1,0,112,
		1,73,36,49,1,48,52,0,102,106,1,0,112,1,
		73,36,50,1,48,45,0,102,106,7,76,108,101,118,
		97,114,0,112,1,73,36,52,1,176,22,0,176,88,
		0,106,9,110,80,114,101,84,80,114,111,0,12,1,
		12,1,31,36,36,53,1,48,54,0,102,176,95,0,
		176,88,0,106,9,110,80,114,101,84,80,114,111,0,
		12,1,122,12,2,112,1,73,25,13,36,55,1,48,
		54,0,102,122,112,1,73,36,58,1,176,22,0,176,
		88,0,106,9,110,80,114,101,84,67,109,98,0,12,
		1,12,1,31,36,36,59,1,48,56,0,102,176,95,
		0,176,88,0,106,9,110,80,114,101,84,67,109,98,
		0,12,1,122,12,2,112,1,73,25,13,36,61,1,
		48,56,0,102,122,112,1,73,36,64,1,48,58,0,
		102,9,112,1,73,36,66,1,48,65,0,102,106,20,
		103,99,95,109,111,116,111,114,95,115,99,111,111,116,
		101,114,95,51,50,0,112,1,73,36,67,1,48,96,
		0,102,100,112,1,73,36,69,1,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_ENCARGAR )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,75,1,48,42,0,102,121,112,1,73,
		36,77,1,176,22,0,95,1,12,1,31,94,36,78,
		1,48,79,0,102,95,1,88,89,0,112,1,73,36,
		79,1,48,80,0,102,95,1,88,90,0,112,1,73,
		36,80,1,48,81,0,102,95,1,88,91,0,112,1,
		73,36,81,1,48,82,0,102,95,1,88,92,0,112,
		1,73,36,82,1,48,83,0,102,95,1,88,93,0,
		112,1,73,36,83,1,48,84,0,102,95,1,88,94,
		0,112,1,73,25,82,36,85,1,48,79,0,102,106,
		1,0,112,1,73,36,86,1,48,80,0,102,106,1,
		0,112,1,73,36,87,1,48,81,0,102,106,1,0,
		112,1,73,36,88,1,48,82,0,102,134,0,0,0,
		0,112,1,73,36,89,1,48,83,0,102,106,1,0,
		112,1,73,36,90,1,48,84,0,102,106,1,0,112,
		1,73,36,93,1,48,52,0,102,106,1,0,112,1,
		73,36,94,1,48,45,0,102,106,9,69,110,99,97,
		114,103,97,114,0,112,1,73,36,96,1,176,22,0,
		176,88,0,106,9,110,80,114,101,84,80,114,111,0,
		12,1,12,1,31,36,36,97,1,48,54,0,102,176,
		95,0,176,88,0,106,9,110,80,114,101,84,80,114,
		111,0,12,1,122,12,2,112,1,73,25,13,36,99,
		1,48,54,0,102,122,112,1,73,36,102,1,176,22,
		0,176,88,0,106,9,110,80,114,101,84,67,109,98,
		0,12,1,12,1,31,36,36,103,1,48,56,0,102,
		176,95,0,176,88,0,106,9,110,80,114,101,84,67,
		109,98,0,12,1,122,12,2,112,1,73,25,13,36,
		105,1,48,56,0,102,122,112,1,73,36,108,1,48,
		58,0,102,9,112,1,73,36,110,1,48,65,0,102,
		106,16,103,99,95,110,111,116,101,98,111,111,107,50,
		95,51,50,0,112,1,73,36,111,1,48,96,0,102,
		100,112,1,73,36,113,1,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_CTEXTOPUNTO )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,119,1,106,1,0,80,1,36,121,1,
		176,22,0,48,15,0,102,112,0,12,1,31,22,36,
		122,1,96,1,0,176,19,0,48,15,0,102,112,0,
		12,1,135,25,41,36,124,1,176,22,0,48,97,0,
		102,112,0,12,1,31,25,36,125,1,96,1,0,176,
		19,0,48,98,0,48,97,0,102,112,0,112,0,12,
		1,135,36,129,1,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_CIMAGENPUNTO )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,136,1,95,1,122,8,28,25,36,137,
		1,106,16,83,104,97,112,101,95,99,105,114,99,108,
		101,95,51,50,0,110,7,36,139,1,95,1,92,2,
		8,28,26,36,140,1,106,17,83,104,97,112,101,95,
		101,108,108,105,112,115,101,95,51,50,0,110,7,36,
		142,1,95,1,92,3,8,28,25,36,143,1,106,16,
		83,104,97,112,101,95,115,113,117,97,114,101,95,51,
		50,0,110,7,36,145,1,95,1,92,4,8,28,28,
		36,146,1,106,19,83,104,97,112,101,95,114,101,99,
		116,97,110,103,108,101,95,51,50,0,110,7,36,148,
		1,95,1,92,5,8,28,23,36,149,1,106,14,66,
		97,114,95,99,101,110,116,101,114,95,51,50,0,110,
		7,36,151,1,95,1,92,6,8,28,21,36,152,1,
		106,12,66,97,114,95,108,101,102,116,95,51,50,0,
		110,7,36,154,1,95,1,92,7,8,28,28,36,155,
		1,106,19,66,97,114,95,99,111,114,110,101,114,95,
		108,101,102,116,95,51,50,0,110,7,36,157,1,95,
		1,92,8,8,28,29,36,158,1,106,20,66,97,114,
		95,99,111,114,110,101,114,95,114,105,103,104,116,95,
		51,50,0,110,7,36,160,1,95,1,92,9,8,28,
		32,36,161,1,106,23,66,97,114,95,99,111,114,110,
		101,114,95,116,111,112,95,108,101,102,116,95,51,50,
		0,110,7,36,163,1,95,1,92,10,8,28,33,36,
		164,1,106,24,66,97,114,95,99,111,114,110,101,114,
		95,116,111,112,95,114,105,103,104,116,95,51,50,0,
		110,7,36,168,1,106,1,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_LOADMESA )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,176,1,48,79,0,102,106,1,0,112,
		1,73,36,177,1,48,80,0,102,106,1,0,112,1,
		73,36,178,1,48,81,0,102,106,1,0,112,1,73,
		36,179,1,48,82,0,102,134,0,0,0,0,112,1,
		73,36,180,1,48,83,0,102,106,1,0,112,1,73,
		36,181,1,48,84,0,102,106,1,0,112,1,73,36,
		182,1,48,85,0,102,106,1,0,112,1,73,36,183,
		1,48,86,0,102,121,112,1,73,36,184,1,48,99,
		0,102,122,112,1,73,36,185,1,48,100,0,102,9,
		112,1,73,36,187,1,48,101,0,48,26,0,102,112,
		0,112,0,80,1,36,189,1,48,102,0,48,26,0,
		102,112,0,48,103,0,102,112,0,106,8,99,67,111,
		100,83,97,108,0,112,2,29,82,1,36,191,1,48,
		79,0,102,48,46,0,48,26,0,102,112,0,106,8,
		99,83,101,114,84,105,107,0,112,1,112,1,73,36,
		192,1,48,80,0,102,48,46,0,48,26,0,102,112,
		0,106,8,99,78,117,109,84,105,107,0,112,1,112,
		1,73,36,193,1,48,81,0,102,48,46,0,48,26,
		0,102,112,0,106,8,99,83,117,102,84,105,107,0,
		112,1,112,1,73,36,194,1,48,82,0,102,48,46,
		0,48,26,0,102,112,0,106,8,100,70,101,99,84,
		105,107,0,112,1,112,1,73,36,195,1,48,83,0,
		102,48,46,0,48,26,0,102,112,0,106,8,99,72,
		111,114,84,105,107,0,112,1,112,1,73,36,196,1,
		48,84,0,102,48,46,0,48,26,0,102,112,0,106,
		10,99,65,108,105,97,115,84,105,107,0,112,1,112,
		1,73,36,197,1,48,85,0,102,48,46,0,48,26,
		0,102,112,0,106,8,99,78,111,109,84,105,107,0,
		112,1,112,1,73,36,198,1,48,99,0,102,48,46,
		0,48,26,0,102,112,0,106,9,108,65,98,105,101,
		114,116,111,0,112,1,28,6,92,2,25,4,92,3,
		112,1,73,36,199,1,48,100,0,102,48,104,0,102,
		112,0,112,1,73,36,201,1,48,105,0,102,112,0,
		28,20,36,202,1,48,86,0,102,48,106,0,102,112,
		0,112,1,73,25,33,36,204,1,48,86,0,102,48,
		46,0,48,26,0,102,112,0,106,8,110,84,111,116,
		84,105,107,0,112,1,112,1,73,36,209,1,48,107,
		0,48,26,0,102,112,0,95,1,112,1,73,36,211,
		1,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_LMULTIPLETICKET )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,217,1,120,80,1,36,218,1,4,0,
		0,80,2,36,220,1,48,26,0,102,112,0,143,36,
		222,1,144,101,0,112,0,73,36,224,1,144,108,0,
		106,8,99,67,111,100,83,97,108,0,112,1,73,36,
		226,1,144,109,0,48,14,0,102,112,0,176,110,0,
		48,15,0,102,112,0,92,30,12,2,72,112,1,29,
		139,0,36,228,1,144,46,0,106,9,99,67,111,100,
		83,97,108,97,0,112,1,144,46,0,106,10,99,80,
		110,116,86,101,110,116,97,0,112,1,72,48,14,0,
		102,112,0,176,110,0,48,15,0,102,112,0,92,30,
		12,2,72,8,28,78,144,111,0,112,0,31,71,36,
		230,1,176,112,0,95,2,144,46,0,106,8,99,83,
		101,114,84,105,107,0,112,1,144,46,0,106,8,99,
		78,117,109,84,105,107,0,112,1,72,144,46,0,106,
		8,99,83,117,102,84,105,107,0,112,1,72,20,2,
		36,232,1,144,113,0,112,0,73,26,123,255,36,238,
		1,144,107,0,112,0,73,145,36,242,1,176,114,0,
		95,2,12,1,122,15,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_NTOTALMULTIPLETICKET )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,248,1,121,80,1,36,250,1,48,26,
		0,102,112,0,143,36,252,1,144,101,0,112,0,73,
		36,254,1,144,108,0,106,8,99,67,111,100,83,97,
		108,0,112,1,73,36,0,2,144,109,0,48,14,0,
		102,112,0,176,110,0,48,15,0,102,112,0,92,30,
		12,2,72,112,1,28,102,36,2,2,144,46,0,106,
		9,99,67,111,100,83,97,108,97,0,112,1,144,46,
		0,106,10,99,80,110,116,86,101,110,116,97,0,112,
		1,72,48,14,0,102,112,0,176,110,0,48,15,0,
		102,112,0,92,30,12,2,72,8,28,42,144,111,0,
		112,0,31,35,36,4,2,96,1,0,144,46,0,106,
		8,110,84,111,116,84,105,107,0,112,1,135,36,6,
		2,144,113,0,112,0,73,25,158,36,12,2,144,107,
		0,112,0,73,145,36,16,2,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_CTEXTOTOTALTIKET )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,22,2,48,24,0,102,112,0,106,2,
		13,0,72,106,2,10,0,72,80,1,36,23,2,96,
		1,0,106,11,91,32,84,111,116,97,108,32,58,32,
		0,176,115,0,176,116,0,48,117,0,102,112,0,176,
		118,0,12,0,12,2,12,1,72,176,119,0,12,0,
		72,106,3,32,93,0,72,135,36,25,2,95,1,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_NIMAGENTIKET )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,31,2,95,1,122,72,92,2,65,92,
		2,49,80,2,36,33,2,176,22,0,48,120,0,102,
		112,0,12,1,31,16,48,121,0,102,112,0,28,8,
		36,34,2,174,2,0,36,37,2,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( STPVPUNTO_CALIASTIKET )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,43,2,176,122,0,176,123,0,48,124,
		0,102,112,0,12,1,12,1,106,2,13,0,72,106,
		2,10,0,72,80,2,36,44,2,96,2,0,106,11,
		91,32,84,111,116,97,108,32,58,32,0,176,115,0,
		176,116,0,48,117,0,102,112,0,176,118,0,12,0,
		12,2,12,1,72,176,119,0,12,0,72,106,3,32,
		93,0,72,135,36,46,2,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,127,0,2,0,116,127,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

