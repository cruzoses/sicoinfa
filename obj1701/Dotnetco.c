/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\Dotnetco.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TDOTNETCOLUMN );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_STATIC( TDOTNETCOLUMN_NEW );
HB_FUNC_EXTERN( AADD );
HB_FUNC_STATIC( TDOTNETCOLUMN_PAINT );
HB_FUNC_STATIC( TDOTNETCOLUMN_MAXWIDTHOFCOL );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( MAX );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_DOTNETCO )
{ "TDOTNETCOLUMN", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TDOTNETCOLUMN )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDOTNETCOLUMN_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDOTNETCOLUMN_NEW )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "AITEMS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDOTNETCOLUMN_PAINT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDOTNETCOLUMN_PAINT )}, NULL },
{ "TDOTNETCOLUMN_MAXWIDTHOFCOL", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TDOTNETCOLUMN_MAXWIDTHOFCOL )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OGRUPO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OCARPETA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCARPETA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACOLUMNS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OGRUPO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MAX", {HB_FS_PUBLIC}, {HB_FUNCNAME( MAX )}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_DOTNETCO, ".\\.\\Prg\\Dotnetco.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_DOTNETCO
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_DOTNETCO )
   #include "hbiniseg.h"
#endif

HB_FUNC( TDOTNETCOLUMN )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,30,0,36,3,0,103,2,0,100,8,
		29,163,1,176,1,0,104,2,0,12,1,29,152,1,
		166,90,1,0,122,80,1,48,2,0,176,3,0,12,
		0,106,14,84,68,111,116,78,101,116,67,111,108,117,
		109,110,0,108,4,4,1,0,108,0,112,3,80,2,
		36,5,0,48,5,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,7,111,71,114,117,112,111,0,4,
		1,0,9,112,5,73,36,6,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,9,111,67,
		97,114,112,101,116,97,0,4,1,0,9,112,5,73,
		36,7,0,48,5,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,8,111,80,97,114,101,110,116,0,
		4,1,0,9,112,5,73,36,8,0,48,5,0,95,
		2,106,6,65,82,82,65,89,0,4,0,0,95,1,
		121,72,121,72,121,72,106,7,97,73,116,101,109,115,
		0,4,1,0,9,112,5,73,36,10,0,48,6,0,
		95,2,106,4,78,101,119,0,108,7,95,1,92,8,
		72,121,72,121,72,112,3,73,36,11,0,48,8,0,
		95,2,106,8,65,100,100,73,116,101,109,0,89,22,
		0,2,0,0,0,176,9,0,48,10,0,95,1,112,
		0,95,2,12,2,6,95,1,121,72,121,72,121,72,
		112,3,73,36,12,0,48,6,0,95,2,106,6,80,
		97,105,110,116,0,108,11,95,1,121,72,121,72,121,
		72,112,3,73,36,13,0,48,6,0,95,2,106,14,
		77,97,120,87,105,100,116,104,79,102,67,111,108,0,
		108,12,95,1,121,72,121,72,121,72,112,3,73,36,
		15,0,48,13,0,95,2,112,0,73,167,14,0,0,
		176,14,0,104,2,0,95,2,20,2,168,48,15,0,
		95,2,112,0,80,3,176,16,0,95,3,106,10,73,
		110,105,116,67,108,97,115,115,0,12,2,28,12,48,
		17,0,95,3,164,146,1,0,73,95,3,110,7,48,
		15,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDOTNETCOLUMN_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,21,0,48,18,0,102,95,1,112,1,
		73,36,22,0,48,19,0,102,48,20,0,95,1,112,
		0,112,1,73,36,23,0,48,21,0,102,48,22,0,
		48,20,0,95,1,112,0,112,0,112,1,73,36,25,
		0,176,9,0,48,23,0,48,24,0,102,112,0,112,
		0,102,20,2,36,27,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDOTNETCOLUMN_PAINT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,35,0,121,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TDOTNETCOLUMN_MAXWIDTHOFCOL )
{
	static const HB_BYTE pcode[] =
	{
		13,2,0,36,40,0,121,80,1,36,43,0,122,165,
		80,2,25,34,36,44,0,176,25,0,95,1,48,26,
		0,48,10,0,102,112,0,95,2,1,112,0,12,2,
		80,1,36,43,0,175,2,0,176,27,0,48,10,0,
		102,112,0,12,1,15,28,212,36,47,0,95,1,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,30,0,2,0,116,30,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}
