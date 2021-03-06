/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\Operaci.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TOPERACION );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TMANT );
HB_FUNC_STATIC( TOPERACION_NEW );
HB_FUNC_STATIC( TOPERACION_CREATEINIT );
HB_FUNC_STATIC( TOPERACION_OPENFILES );
HB_FUNC_STATIC( TOPERACION_CLOSEFILES );
HB_FUNC_STATIC( TOPERACION_DEFINEFILES );
HB_FUNC_STATIC( TOPERACION_RESOURCE );
HB_FUNC_STATIC( TOPERACION_LPRESAVE );
HB_FUNC_STATIC( TOPERACION_CSTRCOLOR );
HB_FUNC_STATIC( TOPERACION_CSTRTIPO );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( CPATEMP );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( GETWNDFRAME );
HB_FUNC_EXTERN( NLEVELUSR );
HB_FUNC_EXTERN( MASUND );
HB_FUNC_EXTERN( TTIPOPERA );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( APOLOBREAK );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( ERRORMESSAGE );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( LBLTITLE );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( NOTVALID );
HB_FUNC_EXTERN( TCOMBOBOX );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( MSGINFO );
HB_FUNC_EXTERN( RTRIM );
HB_FUNC_EXTERN( ORETFLD );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_OPERACI )
{ "TOPERACION", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TMANT", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMANT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TOPERACION_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION_NEW )}, NULL },
{ "TOPERACION_CREATEINIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION_CREATEINIT )}, NULL },
{ "TOPERACION_OPENFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION_OPENFILES )}, NULL },
{ "TOPERACION_CLOSEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION_CLOSEFILES )}, NULL },
{ "TOPERACION_DEFINEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION_DEFINEFILES )}, NULL },
{ "TOPERACION_RESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION_RESOURCE )}, NULL },
{ "TOPERACION_LPRESAVE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION_LPRESAVE )}, NULL },
{ "TOPERACION_CSTRCOLOR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION_CSTRCOLOR )}, NULL },
{ "TOPERACION_CSTRTIPO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TOPERACION_CSTRTIPO )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATEMP )}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "GETWNDFRAME", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETWNDFRAME )}, NULL },
{ "NLEVEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NLEVEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEVELUSR", {HB_FS_PUBLIC}, {HB_FUNCNAME( NLEVELUSR )}, NULL },
{ "_CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CDRIVER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OWNDPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LAUTOBUTTONS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LCREATESHELL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CPICUND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MASUND", {HB_FS_PUBLIC}, {HB_FUNCNAME( MASUND )}, NULL },
{ "_OTIPOPERA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TTIPOPERA", {HB_FS_PUBLIC}, {HB_FUNCNAME( TTIPOPERA )}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "APOLOBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( APOLOBREAK )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFINEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OTIPOPERA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPENFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "ERRORMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORMESSAGE )}, NULL },
{ "CLOSEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "USED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSTRTIPO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CSTRCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "ARGBCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ASTRCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "LBLTITLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( LBLTITLE )}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "CCODOPE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODOPE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NOTVALID", {HB_FS_PUBLIC}, {HB_FUNCNAME( NOTVALID )}, NULL },
{ "CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDESOPE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CDESOPE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTIPOPE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CTIPOPE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BHELP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BUSCAR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EXISTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OHELPTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMBOBOX", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCOMBOBOX )}, NULL },
{ "ARESCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "LPRESAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGINFO", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGINFO )}, NULL },
{ "ADDFASTKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSTART", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NRESULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEKINORD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( RTRIM )}, NULL },
{ "_NCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NAT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORETFLD", {HB_FS_PUBLIC}, {HB_FUNCNAME( ORETFLD )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_OPERACI, ".\\.\\Prg\\Operaci.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_OPERACI
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_OPERACI )
   #include "hbiniseg.h"
#endif

HB_FUNC( TOPERACION )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,100,0,36,7,0,103,2,0,100,8,
		29,30,4,176,1,0,104,2,0,12,1,29,19,4,
		166,213,3,0,122,80,1,48,2,0,176,3,0,12,
		0,106,11,84,79,112,101,114,97,99,105,111,110,0,
		108,4,4,1,0,108,0,112,3,80,2,36,9,0,
		48,5,0,95,2,100,106,21,103,99,95,119,111,114,
		107,101,114,50,95,104,97,109,109,101,114,95,49,54,
		0,95,1,121,72,121,72,121,72,106,5,99,77,114,
		117,0,4,1,0,9,112,5,73,36,10,0,48,5,
		0,95,2,100,97,250,161,52,0,95,1,121,72,121,
		72,121,72,106,8,99,66,105,116,109,97,112,0,4,
		1,0,9,112,5,73,36,11,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,10,111,84,
		105,112,79,112,101,114,97,0,4,1,0,9,112,5,
		73,36,13,0,48,6,0,95,2,100,106,6,78,101,
		103,114,111,0,106,12,82,111,106,111,32,111,115,99,
		117,114,111,0,106,13,86,101,114,100,101,32,111,115,
		99,117,114,111,0,106,6,79,108,105,118,97,0,106,
		12,65,122,117,108,32,109,97,114,105,110,111,0,106,
		8,80,250,114,112,117,114,97,0,106,14,86,101,114,
		100,101,32,97,122,117,108,97,100,111,0,106,5,71,
		114,105,115,0,106,9,80,108,97,116,101,97,100,111,
		0,106,5,82,111,106,111,0,106,6,86,101,114,100,
		101,0,106,9,65,109,97,114,105,108,108,111,0,106,
		5,65,122,117,108,0,106,7,70,117,99,115,105,97,
		0,106,11,65,103,117,97,109,97,114,105,110,97,0,
		106,7,66,108,97,110,99,111,0,4,16,0,95,1,
		121,72,92,32,72,121,72,121,72,106,10,97,83,116,
		114,67,111,108,111,114,0,4,1,0,9,112,5,73,
		36,14,0,48,6,0,95,2,100,106,7,67,79,76,
		95,48,48,0,106,7,67,79,76,95,48,49,0,106,
		7,67,79,76,95,48,50,0,106,7,67,79,76,95,
		48,51,0,106,7,67,79,76,95,48,52,0,106,7,
		67,79,76,95,48,53,0,106,7,67,79,76,95,48,
		54,0,106,7,67,79,76,95,48,55,0,106,7,67,
		79,76,95,48,56,0,106,7,67,79,76,95,48,57,
		0,106,7,67,79,76,95,49,48,0,106,7,67,79,
		76,95,49,49,0,106,7,67,79,76,95,49,50,0,
		106,7,67,79,76,95,49,51,0,106,7,67,79,76,
		95,49,52,0,106,7,67,79,76,95,49,53,0,4,
		16,0,95,1,121,72,92,32,72,121,72,121,72,106,
		10,97,82,101,115,67,111,108,111,114,0,4,1,0,
		9,112,5,73,36,15,0,48,6,0,95,2,100,121,
		93,128,0,97,0,128,0,0,97,128,128,128,0,97,
		0,0,128,0,97,128,0,128,0,97,0,128,128,0,
		97,128,128,128,0,97,192,192,192,0,93,255,0,97,
		0,255,0,0,97,255,255,0,0,97,0,0,255,0,
		97,255,0,255,0,97,0,255,255,0,97,255,255,255,
		0,4,16,0,95,1,121,72,92,32,72,121,72,121,
		72,106,10,97,82,103,98,67,111,108,111,114,0,4,
		1,0,9,112,5,73,36,17,0,48,7,0,95,2,
		106,4,78,101,119,0,108,8,95,1,121,72,121,72,
		121,72,112,3,73,36,19,0,48,7,0,95,2,106,
		11,67,114,101,97,116,101,73,110,105,116,0,108,9,
		95,1,121,72,121,72,121,72,112,3,73,36,21,0,
		48,7,0,95,2,106,10,79,112,101,110,70,105,108,
		101,115,0,108,10,95,1,121,72,121,72,121,72,112,
		3,73,36,23,0,48,7,0,95,2,106,11,67,108,
		111,115,101,70,105,108,101,115,0,108,11,95,1,121,
		72,121,72,121,72,112,3,73,36,25,0,48,7,0,
		95,2,106,12,68,101,102,105,110,101,70,105,108,101,
		115,0,108,12,95,1,121,72,121,72,121,72,112,3,
		73,36,27,0,48,7,0,95,2,106,9,82,101,115,
		111,117,114,99,101,0,108,13,95,1,121,72,121,72,
		121,72,112,3,73,36,29,0,48,7,0,95,2,106,
		9,108,80,114,101,83,97,118,101,0,108,14,95,1,
		121,72,121,72,121,72,112,3,73,36,31,0,48,7,
		0,95,2,106,10,99,83,116,114,67,111,108,111,114,
		0,108,15,95,1,121,72,121,72,121,72,112,3,73,
		36,33,0,48,7,0,95,2,106,9,99,83,116,114,
		84,105,112,111,0,108,16,95,1,121,72,121,72,121,
		72,112,3,73,36,35,0,48,17,0,95,2,112,0,
		73,167,14,0,0,176,18,0,104,2,0,95,2,20,
		2,168,48,19,0,95,2,112,0,80,3,176,20,0,
		95,3,106,10,73,110,105,116,67,108,97,115,115,0,
		12,2,28,12,48,21,0,95,3,164,146,1,0,73,
		95,3,110,7,48,19,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TOPERACION_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,4,36,41,0,95,1,100,8,28,9,176,22,
		0,12,0,80,1,36,42,0,95,2,100,8,28,9,
		176,23,0,12,0,80,2,36,43,0,95,3,100,8,
		28,9,176,24,0,12,0,80,3,36,45,0,95,4,
		100,69,28,29,48,25,0,102,112,0,100,8,28,19,
		36,46,0,48,26,0,102,176,27,0,95,4,12,1,
		112,1,73,36,49,0,48,28,0,102,95,1,112,1,
		73,36,50,0,48,29,0,102,95,2,112,1,73,36,
		51,0,48,30,0,102,95,3,112,1,73,36,52,0,
		48,31,0,102,100,112,1,73,36,54,0,48,32,0,
		102,120,112,1,73,36,55,0,48,33,0,102,9,112,
		1,73,36,57,0,48,34,0,102,176,35,0,12,0,
		112,1,73,36,59,0,48,36,0,102,48,17,0,176,
		37,0,12,0,112,0,112,1,73,36,61,0,102,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TOPERACION_CREATEINIT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,67,0,95,1,100,8,28,9,176,22,
		0,12,0,80,1,36,68,0,95,2,100,8,28,9,
		176,23,0,12,0,80,2,36,70,0,48,28,0,102,
		95,1,112,1,73,36,71,0,48,29,0,102,95,2,
		112,1,73,36,73,0,48,36,0,102,48,17,0,176,
		37,0,12,0,95,1,112,1,112,1,73,36,75,0,
		102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TOPERACION_OPENFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,3,1,36,81,0,120,80,2,36,85,0,95,1,
		100,8,28,5,9,80,1,36,87,0,176,38,0,89,
		15,0,1,0,0,0,176,39,0,95,1,12,1,6,
		12,1,80,4,36,88,0,113,84,0,0,36,90,0,
		176,40,0,48,41,0,102,112,0,12,1,28,12,36,
		91,0,48,42,0,102,112,0,73,36,94,0,48,43,
		0,48,41,0,102,112,0,9,95,1,68,112,2,73,
		36,96,0,48,44,0,102,112,0,100,69,28,17,36,
		97,0,48,45,0,48,44,0,102,112,0,112,0,73,
		36,98,0,114,87,0,0,36,100,0,115,80,3,36,
		102,0,176,46,0,106,43,73,109,112,111,115,105,98,
		108,101,32,97,98,114,105,114,32,116,111,100,97,115,
		32,108,97,115,32,98,97,115,101,115,32,100,101,32,
		100,97,116,111,115,13,10,0,176,47,0,95,3,12,
		1,72,20,1,36,104,0,48,48,0,102,112,0,73,
		36,106,0,9,80,2,36,110,0,176,38,0,95,4,
		20,1,36,112,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TOPERACION_CLOSEFILES )
{
	static const HB_BYTE pcode[] =
	{
		36,118,0,48,41,0,102,112,0,100,69,28,41,48,
		49,0,48,41,0,102,112,0,112,0,28,28,36,119,
		0,48,50,0,48,41,0,102,112,0,112,0,73,36,
		120,0,48,31,0,102,100,112,1,73,36,123,0,48,
		44,0,102,112,0,100,69,28,17,36,124,0,48,50,
		0,48,44,0,102,112,0,112,0,73,36,127,0,48,
		36,0,102,100,112,1,73,36,129,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TOPERACION_DEFINEFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,133,0,102,80,3,36,135,0,95,1,
		100,8,28,11,48,51,0,95,3,112,0,80,1,36,
		136,0,95,2,100,8,28,9,176,23,0,12,0,80,
		2,36,138,0,48,31,0,95,3,48,2,0,176,52,
		0,106,13,79,112,101,114,97,99,105,111,46,68,98,
		102,0,106,10,79,112,101,114,97,99,105,111,110,0,
		12,2,106,13,79,112,101,114,97,99,105,111,46,68,
		98,102,0,106,10,79,112,101,114,97,99,105,111,110,
		0,95,2,106,12,79,112,101,114,97,99,105,111,110,
		101,115,0,95,1,112,5,112,1,73,36,140,0,48,
		53,0,48,41,0,95,3,112,0,106,8,99,67,111,
		100,79,112,101,0,106,2,67,0,92,3,121,100,100,
		100,100,106,7,67,243,100,105,103,111,0,9,92,100,
		9,4,0,0,112,13,73,36,141,0,48,53,0,48,
		41,0,95,3,112,0,106,8,99,68,101,115,79,112,
		101,0,106,2,67,0,92,35,121,100,100,100,100,106,
		7,78,111,109,98,114,101,0,9,93,144,1,9,4,
		0,0,112,13,73,36,142,0,48,53,0,48,41,0,
		95,3,112,0,106,8,99,84,105,112,79,112,101,0,
		106,2,67,0,92,3,121,100,100,100,100,106,5,84,
		105,112,111,0,9,100,120,4,0,0,112,13,73,36,
		143,0,48,53,0,48,41,0,95,3,112,0,106,8,
		84,105,112,111,79,112,101,0,106,2,66,0,92,20,
		121,100,100,100,89,17,0,0,0,1,0,3,0,48,
		54,0,95,255,112,0,6,106,5,84,105,112,111,0,
		9,92,100,9,4,0,0,112,13,73,36,144,0,48,
		53,0,48,41,0,95,3,112,0,106,7,110,67,111,
		108,111,114,0,106,2,78,0,92,10,121,100,100,100,
		100,106,22,67,111,108,111,114,32,100,101,32,108,97,
		32,111,112,101,114,97,99,105,243,110,0,9,100,120,
		4,0,0,112,13,73,36,145,0,48,53,0,48,41,
		0,95,3,112,0,106,7,99,67,111,108,111,114,0,
		106,2,66,0,92,20,121,100,100,100,89,17,0,0,
		0,1,0,3,0,48,55,0,95,255,112,0,6,106,
		6,67,111,108,111,114,0,9,92,120,9,4,0,0,
		112,13,73,36,147,0,48,56,0,48,41,0,95,3,
		112,0,106,8,99,67,111,100,79,112,101,0,106,13,
		79,112,101,114,97,99,105,111,46,67,100,120,0,106,
		8,99,67,111,100,79,112,101,0,100,100,9,9,106,
		7,67,243,100,105,103,111,0,100,100,120,9,112,12,
		73,36,148,0,48,56,0,48,41,0,95,3,112,0,
		106,8,99,68,101,115,79,112,101,0,106,13,79,112,
		101,114,97,99,105,111,46,67,100,120,0,106,8,99,
		68,101,115,79,112,101,0,100,100,9,9,106,7,78,
		111,109,98,114,101,0,100,100,120,9,112,12,73,36,
		152,0,48,41,0,95,3,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TOPERACION_RESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,7,1,36,156,0,102,80,2,36,165,0,95,1,
		122,8,28,26,36,166,0,176,57,0,48,58,0,95,
		2,112,0,97,255,255,255,0,12,2,80,8,25,31,
		36,168,0,176,57,0,48,58,0,95,2,112,0,48,
		59,0,48,41,0,95,2,112,0,112,0,12,2,80,
		8,36,171,0,95,8,121,69,28,17,36,172,0,48,
		60,0,95,2,112,0,95,8,1,80,7,36,175,0,
		48,2,0,176,61,0,12,0,100,100,100,100,176,62,
		0,95,1,12,1,106,12,111,112,101,114,97,99,105,
		111,110,101,115,0,72,106,10,79,112,101,114,97,99,
		105,111,110,0,100,9,100,100,100,100,100,9,100,100,
		100,100,100,9,100,106,5,111,68,108,103,0,100,100,
		112,24,80,3,36,182,0,48,63,0,176,64,0,12,
		0,92,110,89,47,0,1,0,1,0,2,0,176,65,
		0,12,0,121,8,28,16,48,66,0,48,41,0,95,
		255,112,0,112,0,25,16,48,67,0,48,41,0,95,
		255,112,0,95,1,112,1,6,95,3,100,106,3,64,
		33,0,89,36,0,0,0,2,0,4,0,2,0,176,
		68,0,95,255,48,69,0,48,41,0,95,254,112,0,
		112,0,120,106,2,48,0,12,4,6,100,100,100,100,
		100,9,89,14,0,0,0,1,0,1,0,95,255,122,
		8,6,100,9,9,100,100,100,100,100,100,100,100,100,
		112,25,80,4,36,187,0,48,63,0,176,64,0,12,
		0,92,120,89,47,0,1,0,1,0,2,0,176,65,
		0,12,0,121,8,28,16,48,70,0,48,41,0,95,
		255,112,0,112,0,25,16,48,71,0,48,41,0,95,
		255,112,0,95,1,112,1,6,95,3,100,100,100,100,
		100,100,100,100,9,89,15,0,0,0,1,0,1,0,
		95,255,92,3,69,6,100,9,9,100,100,100,100,100,
		100,100,100,100,112,25,73,36,194,0,48,63,0,176,
		64,0,12,0,93,130,0,89,47,0,1,0,1,0,
		2,0,176,65,0,12,0,121,8,28,16,48,72,0,
		48,41,0,95,255,112,0,112,0,25,16,48,73,0,
		48,41,0,95,255,112,0,95,1,112,1,6,95,3,
		100,100,100,100,100,100,100,100,9,89,15,0,0,0,
		1,0,1,0,95,255,92,3,69,6,100,9,9,100,
		100,100,100,100,100,106,5,76,85,80,65,0,100,93,
		131,0,112,25,80,5,36,196,0,48,74,0,95,5,
		89,26,0,0,0,2,0,2,0,5,0,48,75,0,
		48,44,0,95,255,112,0,95,254,112,1,6,112,1,
		73,36,197,0,48,76,0,95,5,89,49,0,0,0,
		2,0,2,0,5,0,48,77,0,48,44,0,95,255,
		112,0,95,254,48,78,0,95,254,112,0,106,8,99,
		68,101,115,84,105,112,0,120,120,106,2,48,0,112,
		6,6,112,1,73,36,204,0,48,63,0,176,79,0,
		12,0,93,140,0,89,28,0,1,0,1,0,7,0,
		176,65,0,12,0,121,8,28,6,95,255,25,7,95,
		1,165,80,255,6,48,60,0,95,2,112,0,95,3,
		100,100,100,100,100,100,9,89,15,0,0,0,1,0,
		1,0,95,255,92,3,69,6,48,80,0,95,2,112,
		0,100,100,100,100,112,17,80,6,36,210,0,48,63,
		0,176,81,0,12,0,122,89,40,0,0,0,4,0,
		2,0,6,0,1,0,3,0,48,82,0,95,255,95,
		254,95,253,112,2,28,12,48,50,0,95,252,122,112,
		1,25,3,100,6,95,3,100,100,9,89,15,0,0,
		0,1,0,1,0,95,255,92,3,69,6,100,100,9,
		112,10,73,36,216,0,48,63,0,176,81,0,12,0,
		92,2,89,17,0,0,0,1,0,3,0,48,50,0,
		95,255,112,0,6,95,3,100,100,9,100,100,100,120,
		112,10,73,36,222,0,48,63,0,176,81,0,12,0,
		93,47,2,90,28,176,83,0,106,18,65,121,117,100,
		97,32,110,111,32,100,101,102,105,110,105,100,97,0,
		12,1,6,95,3,100,100,9,100,100,100,120,112,10,
		73,36,224,0,95,1,92,3,69,28,55,36,225,0,
		48,84,0,95,3,92,116,89,40,0,0,0,4,0,
		2,0,6,0,1,0,3,0,48,82,0,95,255,95,
		254,95,253,112,2,28,12,48,50,0,95,252,122,112,
		1,25,3,100,6,112,2,73,36,228,0,48,85,0,
		95,3,89,27,0,0,0,2,0,4,0,5,0,48,
		86,0,95,255,112,0,73,48,87,0,95,254,112,0,
		6,112,1,73,36,230,0,48,43,0,95,3,48,88,
		0,95,3,112,0,48,89,0,95,3,112,0,48,90,
		0,95,3,112,0,120,100,100,100,48,91,0,95,3,
		112,0,100,100,100,112,11,73,36,232,0,48,92,0,
		95,3,112,0,122,8,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TOPERACION_LPRESAVE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,238,0,95,2,122,8,31,9,95,2,
		92,4,8,28,90,36,240,0,48,93,0,48,41,0,
		102,112,0,48,66,0,48,41,0,102,112,0,112,0,
		106,8,67,67,79,68,79,80,69,0,112,2,28,53,
		36,241,0,176,46,0,106,18,67,243,100,105,103,111,
		32,121,97,32,101,120,105,115,116,101,32,0,176,94,
		0,48,66,0,48,41,0,102,112,0,112,0,12,1,
		72,20,1,36,242,0,9,110,7,36,247,0,176,40,
		0,48,70,0,48,41,0,102,112,0,112,0,12,1,
		28,71,36,248,0,176,46,0,106,53,76,97,32,100,
		101,115,99,114,105,112,99,105,243,110,32,100,101,32,
		108,97,32,111,112,101,114,97,99,105,243,110,32,110,
		111,32,112,117,101,100,101,32,101,115,116,97,114,32,
		118,97,99,237,97,46,0,20,1,36,249,0,9,110,
		7,36,252,0,48,95,0,48,41,0,102,112,0,48,
		58,0,102,112,0,48,96,0,95,1,112,0,1,112,
		1,73,36,254,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TOPERACION_CSTRCOLOR )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,5,1,106,1,0,80,2,36,7,1,
		176,40,0,48,60,0,102,112,0,12,1,28,9,36,
		8,1,95,2,110,7,36,11,1,176,40,0,48,58,
		0,102,112,0,12,1,28,9,36,12,1,95,2,110,
		7,36,15,1,176,40,0,48,41,0,102,112,0,12,
		1,28,9,36,16,1,95,2,110,7,36,19,1,176,
		57,0,48,58,0,102,112,0,48,59,0,48,41,0,
		102,112,0,112,0,12,2,80,1,36,20,1,95,1,
		121,69,28,16,36,21,1,48,60,0,102,112,0,95,
		1,1,80,2,36,24,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TOPERACION_CSTRTIPO )
{
	static const HB_BYTE pcode[] =
	{
		36,30,1,48,72,0,48,41,0,102,112,0,112,0,
		106,4,32,45,32,0,72,176,97,0,48,72,0,48,
		41,0,102,112,0,112,0,48,41,0,48,44,0,102,
		112,0,112,0,12,2,72,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,100,0,2,0,116,100,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

