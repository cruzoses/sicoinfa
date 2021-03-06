/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\Lenguajes.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TLENGUAJE );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TMANT );
HB_FUNC_STATIC( TLENGUAJE_DEFINEFILES );
HB_FUNC_STATIC( TLENGUAJE_RESOURCE );
HB_FUNC_STATIC( TLENGUAJE_LVALIDRESOURCE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( SPACE );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( LBLTITLE );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( RTRIM );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_LENGUAJES )
{ "TLENGUAJE", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TLENGUAJE )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TMANT", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMANT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TLENGUAJE_DEFINEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TLENGUAJE_DEFINEFILES )}, NULL },
{ "TLENGUAJE_RESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TLENGUAJE_RESOURCE )}, NULL },
{ "TLENGUAJE_LVALIDRESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TLENGUAJE_LVALIDRESOURCE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "_ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SPACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SPACE )}, NULL },
{ "ADDINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "LBLTITLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( LBLTITLE )}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "CCODLEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODLEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CNOMLEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMLEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "LVALIDRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDFASTKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSTART", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NRESULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEKINORD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "RTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( RTRIM )}, NULL },
{ "GETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_LENGUAJES, ".\\.\\Prg\\Lenguajes.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_LENGUAJES
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_LENGUAJES )
   #include "hbiniseg.h"
#endif

HB_FUNC( TLENGUAJE )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,51,0,36,7,0,103,2,0,100,8,
		29,111,1,176,1,0,104,2,0,12,1,29,100,1,
		166,38,1,0,122,80,1,48,2,0,176,3,0,12,
		0,106,10,84,76,101,110,103,117,97,106,101,0,108,
		4,4,1,0,108,0,112,3,80,2,36,9,0,48,
		5,0,95,2,100,106,19,103,99,95,117,115,101,114,
		95,109,101,115,115,97,103,101,95,49,54,0,95,1,
		121,72,121,72,121,72,106,5,99,77,114,117,0,4,
		1,0,9,112,5,73,36,11,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,11,111,66,
		114,119,68,105,97,108,111,103,0,4,1,0,9,112,
		5,73,36,13,0,48,5,0,95,2,100,4,0,0,
		95,1,121,72,121,72,121,72,106,21,97,76,101,110,
		103,117,97,106,101,115,80,114,101,115,116,97,115,104,
		111,112,0,4,1,0,9,112,5,73,36,15,0,48,
		6,0,95,2,106,12,68,101,102,105,110,101,70,105,
		108,101,115,0,108,7,95,1,121,72,121,72,121,72,
		112,3,73,36,17,0,48,6,0,95,2,106,9,82,
		101,115,111,117,114,99,101,0,108,8,95,1,121,72,
		121,72,121,72,112,3,73,36,18,0,48,6,0,95,
		2,106,15,108,86,97,108,105,100,82,101,115,111,117,
		114,99,101,0,108,9,95,1,121,72,121,72,121,72,
		112,3,73,36,20,0,48,10,0,95,2,112,0,73,
		167,14,0,0,176,11,0,104,2,0,95,2,20,2,
		168,48,12,0,95,2,112,0,80,3,176,13,0,95,
		3,106,10,73,110,105,116,67,108,97,115,115,0,12,
		2,28,12,48,14,0,95,3,164,146,1,0,73,95,
		3,110,7,48,12,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TLENGUAJE_DEFINEFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,26,0,95,1,100,8,28,10,48,15,
		0,102,112,0,80,1,36,27,0,95,2,100,8,28,
		9,176,16,0,12,0,80,2,36,29,0,48,17,0,
		102,48,2,0,176,18,0,106,13,76,69,78,71,85,
		65,74,69,46,68,66,70,0,106,9,76,69,78,71,
		85,65,74,69,0,12,2,106,13,76,69,78,71,85,
		65,74,69,46,68,66,70,0,100,95,2,106,10,76,
		101,110,103,117,97,106,101,115,0,95,1,112,5,112,
		1,73,36,31,0,48,19,0,48,20,0,102,112,0,
		106,8,99,67,111,100,76,101,110,0,106,2,67,0,
		92,4,121,100,176,21,0,92,4,12,1,100,100,106,
		7,67,243,100,105,103,111,0,9,92,80,9,4,0,
		0,112,13,73,36,32,0,48,19,0,48,20,0,102,
		112,0,106,8,99,78,111,109,76,101,110,0,106,2,
		67,0,92,50,121,100,176,21,0,93,200,0,12,1,
		100,100,106,7,78,111,109,98,114,101,0,9,93,200,
		0,9,4,0,0,112,13,73,36,34,0,48,22,0,
		48,20,0,102,112,0,106,8,67,67,79,68,76,69,
		78,0,106,13,76,69,78,71,85,65,74,69,46,67,
		68,88,0,106,8,67,67,79,68,76,69,78,0,100,
		100,9,9,106,7,67,243,100,105,103,111,0,100,100,
		120,9,112,12,73,36,35,0,48,22,0,48,20,0,
		102,112,0,106,8,67,78,79,77,76,69,78,0,106,
		13,76,69,78,71,85,65,74,69,46,67,68,88,0,
		106,8,67,78,79,77,76,69,78,0,100,100,9,9,
		106,7,78,111,109,98,114,101,0,100,100,120,9,112,
		12,73,36,39,0,48,20,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TLENGUAJE_RESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,1,36,43,0,102,80,2,36,48,0,48,2,
		0,176,23,0,12,0,100,100,100,100,176,24,0,95,
		1,12,1,106,10,108,101,110,103,117,97,106,101,115,
		0,72,106,10,76,101,110,103,117,97,106,101,115,0,
		100,9,100,100,100,100,100,9,100,100,100,100,100,9,
		100,106,5,111,68,108,103,0,100,100,112,24,80,3,
		36,55,0,48,25,0,176,26,0,12,0,92,100,89,
		47,0,1,0,1,0,2,0,176,27,0,12,0,121,
		8,28,16,48,28,0,48,20,0,95,255,112,0,112,
		0,25,16,48,29,0,48,20,0,95,255,112,0,95,
		1,112,1,6,95,3,100,106,3,64,33,0,100,100,
		100,100,100,100,120,89,14,0,0,0,1,0,1,0,
		95,255,122,8,6,100,9,9,100,100,100,100,100,100,
		100,100,100,112,25,80,4,36,60,0,48,25,0,176,
		26,0,12,0,92,110,89,47,0,1,0,1,0,2,
		0,176,27,0,12,0,121,8,28,16,48,30,0,48,
		20,0,95,255,112,0,112,0,25,16,48,31,0,48,
		20,0,95,255,112,0,95,1,112,1,6,95,3,100,
		100,100,100,100,100,100,100,120,89,15,0,0,0,1,
		0,1,0,95,255,92,3,69,6,100,9,9,100,100,
		100,100,100,100,100,100,100,112,25,73,36,66,0,48,
		25,0,176,32,0,12,0,122,89,29,0,0,0,4,
		0,2,0,4,0,3,0,1,0,48,33,0,95,255,
		95,254,95,253,95,252,112,3,6,95,3,100,100,9,
		89,15,0,0,0,1,0,1,0,95,255,92,3,69,
		6,100,100,9,112,10,73,36,72,0,48,25,0,176,
		32,0,12,0,92,2,89,17,0,0,0,1,0,3,
		0,48,34,0,95,255,112,0,6,95,3,100,100,9,
		100,100,100,120,112,10,73,36,74,0,95,1,92,3,
		69,28,44,36,75,0,48,35,0,95,3,92,116,89,
		29,0,0,0,4,0,2,0,4,0,3,0,1,0,
		48,33,0,95,255,95,254,95,253,95,252,112,3,6,
		112,2,73,36,78,0,48,36,0,95,3,89,17,0,
		0,0,1,0,4,0,48,37,0,95,255,112,0,6,
		112,1,73,36,80,0,48,38,0,95,3,48,39,0,
		95,3,112,0,48,40,0,95,3,112,0,48,41,0,
		95,3,112,0,120,100,100,100,48,42,0,95,3,112,
		0,100,100,100,112,11,73,36,82,0,48,43,0,95,
		3,112,0,122,8,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TLENGUAJE_LVALIDRESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,88,0,95,3,122,8,31,9,95,3,
		92,4,8,28,101,36,90,0,48,44,0,48,20,0,
		102,112,0,48,28,0,48,20,0,102,112,0,112,0,
		106,8,99,67,111,100,76,101,110,0,112,2,28,64,
		36,91,0,176,45,0,106,18,67,243,100,105,103,111,
		32,121,97,32,101,120,105,115,116,101,32,0,176,46,
		0,48,28,0,48,20,0,102,112,0,112,0,12,1,
		72,20,1,36,92,0,48,47,0,95,1,112,0,73,
		36,93,0,9,110,7,36,98,0,176,48,0,48,30,
		0,48,20,0,102,112,0,112,0,12,1,28,68,36,
		99,0,176,45,0,106,50,76,97,32,100,101,115,99,
		114,105,112,99,105,243,110,32,100,101,108,32,108,101,
		110,103,117,97,106,101,32,110,111,32,112,117,101,100,
		101,32,101,115,116,97,114,32,118,97,99,237,97,46,
		0,20,1,36,100,0,9,110,7,36,103,0,48,34,
		0,95,2,122,112,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,51,0,2,0,116,51,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

