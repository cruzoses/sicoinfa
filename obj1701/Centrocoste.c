/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\Centrocoste.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TCENTROCOSTE );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TMANT );
HB_FUNC_STATIC( TCENTROCOSTE_NEW );
HB_FUNC_STATIC( TCENTROCOSTE_CREATE );
HB_FUNC_STATIC( TCENTROCOSTE_DEFAULT );
HB_FUNC_STATIC( TCENTROCOSTE_DEFINEFILES );
HB_FUNC_STATIC( TCENTROCOSTE_RESOURCE );
HB_FUNC_STATIC( TCENTROCOSTE_LPRESAVE );
HB_FUNC_STATIC( TCENTROCOSTE_LOADVALUES );
HB_FUNC_STATIC( TCENTROCOSTE_VALIDCODIGO );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_STATIC( TCENTROCOSTE_LOADGET );
HB_FUNC_STATIC( TCENTROCOSTE_CLEARGET );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( CPATDAT );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( CCLIENT );
HB_FUNC_EXTERN( CARTICULO );
HB_FUNC_EXTERN( CPROVEE );
HB_FUNC_EXTERN( BRWCLIENT );
HB_FUNC_EXTERN( BRWARTICULO );
HB_FUNC_EXTERN( BRWPROVEE );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( SPACE );
HB_FUNC_EXTERN( CPORDIV );
HB_FUNC_EXTERN( CPIRDIV );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( LBLTITLE );
HB_FUNC_EXTERN( TBITMAP );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( TCOMBOBOX );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( MAX );
HB_FUNC_EXTERN( HGET );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_CENTROCOSTE )
{ "TCENTROCOSTE", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TMANT", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMANT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCENTROCOSTE_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_NEW )}, NULL },
{ "TCENTROCOSTE_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_CREATE )}, NULL },
{ "TCENTROCOSTE_DEFAULT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_DEFAULT )}, NULL },
{ "TCENTROCOSTE_DEFINEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_DEFINEFILES )}, NULL },
{ "TCENTROCOSTE_RESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_RESOURCE )}, NULL },
{ "TCENTROCOSTE_LPRESAVE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_LPRESAVE )}, NULL },
{ "TCENTROCOSTE_LOADVALUES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_LOADVALUES )}, NULL },
{ "TCENTROCOSTE_VALIDCODIGO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_VALIDCODIGO )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "TCENTROCOSTE_LOADGET", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_LOADGET )}, NULL },
{ "TCENTROCOSTE_CLEARGET", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCENTROCOSTE_CLEARGET )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATDAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATDAT )}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFAULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCLIENT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CCLIENT )}, NULL },
{ "OGETDOCUMENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OHELPTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CARTICULO", {HB_FS_PUBLIC}, {HB_FUNCNAME( CARTICULO )}, NULL },
{ "CPROVEE", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPROVEE )}, NULL },
{ "_HHELP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRWCLIENT", {HB_FS_PUBLIC}, {HB_FUNCNAME( BRWCLIENT )}, NULL },
{ "BRWARTICULO", {HB_FS_PUBLIC}, {HB_FUNCNAME( BRWARTICULO )}, NULL },
{ "BRWPROVEE", {HB_FS_PUBLIC}, {HB_FUNCNAME( BRWPROVEE )}, NULL },
{ "CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SPACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SPACE )}, NULL },
{ "CPORDIV", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPORDIV )}, NULL },
{ "CPIRDIV", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPIRDIV )}, NULL },
{ "ADDINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LOADVALUES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "LBLTITLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( LBLTITLE )}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBITMAP )}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CNOMBRE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMBRE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NVENTAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NVENTAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCOMPRAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NCOMPRAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OTIPO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMBOBOX", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCOMBOBOX )}, NULL },
{ "CTIPO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CTIPO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ATIPO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BCHANGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OTIPO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLEARGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LOADGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OGETDOCUMENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CGETDOCUMENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CGETDOCUMENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "LPRESAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDFASTKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSTART", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NRESULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALIDCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALIDNAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NTIPODOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NAT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VARGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEKINORD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MAX", {HB_FS_PUBLIC}, {HB_FUNCNAME( MAX )}, NULL },
{ "NTIPODOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODDOC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGET )}, NULL },
{ "HVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BHELP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HHELP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_CENTROCOSTE, ".\\.\\Prg\\Centrocoste.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_CENTROCOSTE
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_CENTROCOSTE )
   #include "hbiniseg.h"
#endif

HB_FUNC( TCENTROCOSTE )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,106,0,36,7,0,103,2,0,100,8,
		29,233,3,176,1,0,104,2,0,12,1,29,222,3,
		166,160,3,0,122,80,1,48,2,0,176,3,0,12,
		0,106,13,84,67,101,110,116,114,111,67,111,115,116,
		101,0,108,4,4,1,0,108,0,112,3,80,2,36,
		9,0,48,5,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,11,108,79,112,101,110,70,105,108,101,
		115,0,4,1,0,9,112,5,73,36,10,0,48,5,
		0,95,2,100,106,24,103,99,95,102,111,108,100,101,
		114,95,111,112,101,110,95,109,111,110,101,121,95,49,
		54,0,95,1,121,72,121,72,121,72,106,5,99,77,
		114,117,0,4,1,0,9,112,5,73,36,11,0,48,
		5,0,95,2,100,106,12,67,101,110,116,114,111,67,
		111,115,116,101,0,95,1,121,72,121,72,121,72,106,
		6,99,78,97,109,101,0,4,1,0,9,112,5,73,
		36,13,0,48,5,0,95,2,100,106,9,67,108,105,
		101,110,116,101,115,0,106,10,65,114,116,237,99,117,
		108,111,115,0,106,12,80,114,111,118,101,101,100,111,
		114,101,115,0,4,3,0,95,1,121,72,121,72,121,
		72,106,6,97,84,105,112,111,0,4,1,0,9,112,
		5,73,36,14,0,48,5,0,95,2,100,106,10,65,
		114,116,237,99,117,108,111,115,0,95,1,121,72,121,
		72,121,72,106,6,99,84,105,112,111,0,4,1,0,
		9,112,5,73,36,15,0,48,5,0,95,2,100,100,
		95,1,121,72,121,72,121,72,106,6,111,84,105,112,
		111,0,4,1,0,9,112,5,73,36,17,0,48,5,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		13,99,71,101,116,68,111,99,117,109,101,110,116,0,
		4,1,0,9,112,5,73,36,18,0,48,5,0,95,
		2,100,100,95,1,121,72,121,72,121,72,106,13,111,
		71,101,116,68,111,99,117,109,101,110,116,0,4,1,
		0,9,112,5,73,36,20,0,48,5,0,95,2,100,
		177,0,0,95,1,121,72,121,72,121,72,106,7,104,
		86,97,108,105,100,0,4,1,0,9,112,5,73,36,
		21,0,48,5,0,95,2,100,177,0,0,95,1,121,
		72,121,72,121,72,106,6,104,72,101,108,112,0,4,
		1,0,9,112,5,73,36,23,0,48,6,0,95,2,
		106,4,78,101,119,0,108,7,95,1,121,72,121,72,
		121,72,112,3,73,36,24,0,48,6,0,95,2,106,
		7,67,114,101,97,116,101,0,108,8,95,1,121,72,
		121,72,121,72,112,3,73,36,26,0,48,6,0,95,
		2,106,8,68,101,102,97,117,108,116,0,108,9,95,
		1,121,72,121,72,121,72,112,3,73,36,28,0,48,
		6,0,95,2,106,12,68,101,102,105,110,101,70,105,
		108,101,115,0,108,10,95,1,121,72,121,72,121,72,
		112,3,73,36,30,0,48,6,0,95,2,106,9,82,
		101,115,111,117,114,99,101,0,108,11,95,1,121,72,
		121,72,121,72,112,3,73,36,32,0,48,6,0,95,
		2,106,9,108,80,114,101,83,97,118,101,0,108,12,
		95,1,121,72,121,72,121,72,112,3,73,36,34,0,
		48,6,0,95,2,106,11,108,111,97,100,86,97,108,
		117,101,115,0,108,13,95,1,121,72,121,72,121,72,
		112,3,73,36,36,0,48,6,0,95,2,106,12,118,
		97,108,105,100,67,111,100,105,103,111,0,108,14,95,
		1,121,72,121,72,121,72,112,3,73,36,40,0,48,
		15,0,95,2,106,10,118,97,108,105,100,78,97,109,
		101,0,89,85,0,2,0,0,0,176,16,0,95,2,
		12,1,28,69,176,17,0,106,57,76,97,32,100,101,
		115,99,114,105,112,99,105,243,110,32,100,101,108,32,
		99,101,110,116,114,111,32,100,101,32,99,111,115,116,
		101,32,110,111,32,112,117,101,100,101,32,101,115,116,
		97,114,32,118,97,99,237,97,46,0,20,1,9,25,
		3,120,6,95,1,121,72,121,72,121,72,112,3,73,
		36,41,0,48,6,0,95,2,106,8,108,111,97,100,
		71,101,116,0,108,18,95,1,121,72,121,72,121,72,
		112,3,73,36,43,0,48,6,0,95,2,106,9,99,
		108,101,97,114,71,101,116,0,108,19,95,1,121,72,
		121,72,121,72,112,3,73,36,45,0,48,20,0,95,
		2,112,0,73,167,14,0,0,176,21,0,104,2,0,
		95,2,20,2,168,48,22,0,95,2,112,0,80,3,
		176,23,0,95,3,106,10,73,110,105,116,67,108,97,
		115,115,0,12,2,28,12,48,24,0,95,3,164,146,
		1,0,73,95,3,110,7,48,22,0,103,2,0,112,
		0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,51,0,95,1,100,8,28,9,176,25,
		0,12,0,80,1,36,52,0,95,2,100,8,28,9,
		176,26,0,12,0,80,2,36,54,0,48,2,0,48,
		27,0,102,112,0,95,1,95,2,112,2,73,36,56,
		0,48,28,0,102,112,0,73,36,58,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_CREATE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,64,0,95,1,100,8,28,9,176,25,
		0,12,0,80,1,36,65,0,95,2,100,8,28,9,
		176,26,0,12,0,80,2,36,67,0,48,20,0,48,
		27,0,102,112,0,95,1,95,2,112,2,73,36,69,
		0,48,28,0,102,112,0,73,36,71,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_DEFAULT )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,75,0,102,80,1,36,79,0,48,29,
		0,95,1,106,9,67,108,105,101,110,116,101,115,0,
		89,35,0,0,0,1,0,1,0,176,30,0,48,31,
		0,95,255,112,0,100,48,32,0,48,31,0,95,255,
		112,0,112,0,12,3,6,106,10,65,114,116,237,99,
		117,108,111,115,0,89,35,0,0,0,1,0,1,0,
		176,33,0,48,31,0,95,255,112,0,100,48,32,0,
		48,31,0,95,255,112,0,112,0,12,3,6,106,12,
		80,114,111,118,101,101,100,111,114,101,115,0,89,35,
		0,0,0,1,0,1,0,176,34,0,48,31,0,95,
		255,112,0,100,48,32,0,48,31,0,95,255,112,0,
		112,0,12,3,6,177,3,0,112,1,73,36,83,0,
		48,35,0,95,1,106,9,67,108,105,101,110,116,101,
		115,0,89,34,0,0,0,1,0,1,0,176,36,0,
		48,31,0,95,255,112,0,48,32,0,48,31,0,95,
		255,112,0,112,0,12,2,6,106,10,65,114,116,237,
		99,117,108,111,115,0,89,34,0,0,0,1,0,1,
		0,176,37,0,48,31,0,95,255,112,0,48,32,0,
		48,31,0,95,255,112,0,112,0,12,2,6,106,12,
		80,114,111,118,101,101,100,111,114,101,115,0,89,34,
		0,0,0,1,0,1,0,176,38,0,48,31,0,95,
		255,112,0,48,32,0,48,31,0,95,255,112,0,112,
		0,12,2,6,177,3,0,112,1,73,36,85,0,95,
		1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_DEFINEFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,91,0,95,1,100,8,28,10,48,39,
		0,102,112,0,80,1,36,92,0,95,2,100,8,28,
		9,176,26,0,12,0,80,2,36,94,0,48,40,0,
		102,48,2,0,176,41,0,106,11,67,67,111,115,116,
		101,46,68,98,102,0,106,12,67,69,78,84,82,79,
		67,79,83,84,69,0,12,2,106,11,67,67,111,115,
		116,101,46,68,98,102,0,100,95,2,106,16,67,101,
		110,116,114,111,32,100,101,32,99,111,115,116,101,0,
		95,1,112,5,112,1,73,36,96,0,48,42,0,48,
		43,0,102,112,0,106,8,99,67,111,100,105,103,111,
		0,106,2,67,0,92,9,121,100,176,44,0,92,9,
		12,1,100,100,106,7,67,243,100,105,103,111,0,9,
		92,80,9,4,0,0,112,13,73,36,97,0,48,42,
		0,48,43,0,102,112,0,106,8,99,78,111,109,98,
		114,101,0,106,2,67,0,92,50,121,100,176,44,0,
		92,50,12,1,100,100,106,7,78,111,109,98,114,101,
		0,9,93,200,0,9,4,0,0,112,13,73,36,98,
		0,48,42,0,48,43,0,102,112,0,106,8,110,86,
		101,110,116,97,115,0,106,2,78,0,92,15,92,6,
		176,45,0,12,0,100,100,100,106,19,79,98,106,101,
		116,105,118,111,32,100,101,32,86,101,110,116,97,115,
		0,120,93,150,0,9,4,0,0,112,13,73,36,99,
		0,48,42,0,48,43,0,102,112,0,106,9,110,67,
		111,109,112,114,97,115,0,106,2,78,0,92,15,92,
		6,176,46,0,12,0,100,100,100,106,20,79,98,106,
		101,116,105,118,111,32,100,101,32,99,111,109,112,114,
		97,115,0,120,93,150,0,9,4,0,0,112,13,73,
		36,100,0,48,42,0,48,43,0,102,112,0,106,9,
		110,84,105,112,111,68,111,99,0,106,2,78,0,92,
		2,121,100,100,100,100,106,24,84,105,112,111,32,100,
		111,99,117,109,101,110,116,111,32,97,115,111,99,105,
		97,100,111,0,9,100,120,4,0,0,112,13,73,36,
		101,0,48,42,0,48,43,0,102,112,0,106,8,99,
		67,111,100,68,111,99,0,106,2,67,0,92,30,121,
		100,100,100,100,106,19,68,111,99,117,109,101,110,116,
		111,32,97,115,111,99,105,97,100,111,0,9,100,120,
		4,0,0,112,13,73,36,103,0,48,47,0,48,43,
		0,102,112,0,106,8,99,67,111,100,105,103,111,0,
		106,11,67,67,111,115,116,101,46,67,68,88,0,106,
		8,99,67,111,100,105,103,111,0,100,100,9,9,106,
		7,67,243,100,105,103,111,0,100,100,120,9,112,12,
		73,36,104,0,48,47,0,48,43,0,102,112,0,106,
		8,99,78,111,109,98,114,101,0,106,11,67,67,111,
		115,116,101,46,67,68,88,0,106,8,99,78,111,109,
		98,114,101,0,100,100,9,9,106,7,78,111,109,98,
		114,101,0,100,100,120,9,112,12,73,36,108,0,48,
		43,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_RESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,4,1,36,112,0,102,80,2,36,118,0,48,48,
		0,95,2,112,0,73,36,120,0,48,2,0,176,49,
		0,12,0,100,100,100,100,176,50,0,95,1,12,1,
		106,16,99,101,110,116,114,111,32,100,101,32,99,111,
		115,116,101,0,72,106,12,67,101,110,116,114,111,67,
		111,115,116,101,0,100,9,100,100,100,100,100,9,100,
		100,100,100,100,9,100,106,5,111,68,108,103,0,100,
		100,112,24,80,3,36,127,0,48,51,0,176,52,0,
		12,0,93,32,3,106,19,103,99,95,102,111,108,100,
		101,114,95,109,111,110,101,121,95,52,56,0,100,95,
		3,100,100,9,9,100,100,9,100,100,120,112,14,80,
		5,36,133,0,48,51,0,176,53,0,12,0,92,100,
		89,47,0,1,0,1,0,2,0,176,54,0,12,0,
		121,8,28,16,48,55,0,48,43,0,95,255,112,0,
		112,0,25,16,48,56,0,48,43,0,95,255,112,0,
		95,1,112,1,6,95,3,100,106,3,64,33,0,100,
		100,100,100,100,100,9,89,14,0,0,0,1,0,1,
		0,95,255,122,8,6,100,9,9,100,100,100,100,100,
		100,100,100,100,112,25,80,4,36,138,0,48,51,0,
		176,53,0,12,0,92,110,89,47,0,1,0,1,0,
		2,0,176,54,0,12,0,121,8,28,16,48,57,0,
		48,43,0,95,255,112,0,112,0,25,16,48,58,0,
		48,43,0,95,255,112,0,95,1,112,1,6,95,3,
		100,100,100,100,100,100,100,100,9,89,15,0,0,0,
		1,0,1,0,95,255,92,3,69,6,100,9,9,100,
		100,100,100,100,100,100,100,100,112,25,73,36,144,0,
		48,51,0,176,53,0,12,0,92,120,89,47,0,1,
		0,1,0,2,0,176,54,0,12,0,121,8,28,16,
		48,59,0,48,43,0,95,255,112,0,112,0,25,16,
		48,60,0,48,43,0,95,255,112,0,95,1,112,1,
		6,95,3,100,176,45,0,12,0,100,100,100,100,100,
		100,9,89,15,0,0,0,1,0,1,0,95,255,92,
		3,69,6,100,9,9,100,100,100,100,100,100,100,100,
		100,112,25,73,36,150,0,48,51,0,176,53,0,12,
		0,93,130,0,89,47,0,1,0,1,0,2,0,176,
		54,0,12,0,121,8,28,16,48,61,0,48,43,0,
		95,255,112,0,112,0,25,16,48,62,0,48,43,0,
		95,255,112,0,95,1,112,1,6,95,3,100,176,46,
		0,12,0,100,100,100,100,100,100,9,89,15,0,0,
		0,1,0,1,0,95,255,92,3,69,6,100,9,9,
		100,100,100,100,100,100,100,100,100,112,25,73,36,157,
		0,48,63,0,95,2,48,51,0,176,64,0,12,0,
		93,140,0,89,37,0,1,0,1,0,2,0,176,54,
		0,12,0,121,8,28,11,48,65,0,95,255,112,0,
		25,11,48,66,0,95,255,95,1,112,1,6,48,67,
		0,95,2,112,0,95,3,100,100,100,100,100,100,9,
		89,15,0,0,0,1,0,1,0,95,255,92,3,69,
		6,100,100,100,100,100,112,17,112,1,73,36,159,0,
		48,68,0,48,69,0,95,2,112,0,89,25,0,0,
		0,1,0,2,0,48,70,0,95,255,112,0,73,48,
		71,0,95,255,112,0,6,112,1,73,36,167,0,48,
		72,0,95,2,48,51,0,176,53,0,12,0,93,150,
		0,89,37,0,1,0,1,0,2,0,176,54,0,12,
		0,121,8,28,11,48,73,0,95,255,112,0,25,11,
		48,74,0,95,255,95,1,112,1,6,95,3,100,100,
		100,100,100,100,100,100,9,89,15,0,0,0,1,0,
		1,0,95,255,92,3,69,6,100,9,9,100,100,100,
		100,100,100,106,5,76,85,80,65,0,100,93,160,0,
		112,25,112,1,73,36,173,0,48,51,0,176,75,0,
		12,0,122,89,29,0,0,0,4,0,2,0,4,0,
		3,0,1,0,48,76,0,95,255,95,254,95,253,95,
		252,112,3,6,95,3,100,100,9,89,15,0,0,0,
		1,0,1,0,95,255,92,3,69,6,100,100,9,112,
		10,73,36,179,0,48,51,0,176,75,0,12,0,92,
		2,89,17,0,0,0,1,0,3,0,48,77,0,95,
		255,112,0,6,95,3,100,100,9,100,100,100,120,112,
		10,73,36,181,0,95,1,92,3,69,28,44,36,182,
		0,48,78,0,95,3,92,116,89,29,0,0,0,4,
		0,2,0,4,0,3,0,1,0,48,76,0,95,255,
		95,254,95,253,95,252,112,3,6,112,2,73,36,185,
		0,48,79,0,95,3,89,40,0,0,0,2,0,2,
		0,4,0,48,71,0,95,255,112,0,73,48,80,0,
		48,31,0,95,255,112,0,112,0,73,48,81,0,95,
		254,112,0,6,112,1,73,36,187,0,48,82,0,95,
		3,48,83,0,95,3,112,0,48,84,0,95,3,112,
		0,48,85,0,95,3,112,0,120,100,100,100,48,86,
		0,95,3,112,0,100,100,100,112,11,73,36,189,0,
		176,16,0,95,5,12,1,31,13,36,190,0,48,77,
		0,95,5,112,0,73,36,193,0,48,87,0,95,3,
		112,0,122,8,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_LPRESAVE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,199,0,48,88,0,102,95,1,48,55,
		0,48,43,0,102,112,0,112,0,95,3,112,3,31,
		8,36,200,0,9,110,7,36,203,0,48,89,0,102,
		48,57,0,48,43,0,102,112,0,112,0,112,1,31,
		8,36,204,0,9,110,7,36,207,0,48,80,0,48,
		31,0,102,112,0,112,0,31,8,36,208,0,9,110,
		7,36,211,0,48,90,0,48,43,0,102,112,0,48,
		91,0,48,69,0,102,112,0,112,0,112,1,73,36,
		212,0,48,92,0,48,43,0,102,112,0,48,93,0,
		48,31,0,102,112,0,112,0,112,1,73,36,214,0,
		48,77,0,95,2,122,112,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_VALIDCODIGO )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,220,0,95,3,122,8,31,9,95,3,
		92,4,8,28,92,36,222,0,48,94,0,48,43,0,
		102,112,0,95,2,106,8,99,67,111,100,105,103,111,
		0,112,2,28,64,36,223,0,176,17,0,106,34,69,
		108,32,99,243,100,105,103,111,32,105,110,116,114,111,
		100,117,99,105,100,111,32,121,97,32,101,120,105,115,
		116,101,58,32,0,48,55,0,48,43,0,102,112,0,
		112,0,72,20,1,36,224,0,9,110,7,36,230,0,
		120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_LOADVALUES )
{
	static const HB_BYTE pcode[] =
	{
		36,236,0,48,66,0,102,48,67,0,102,112,0,176,
		95,0,48,96,0,48,43,0,102,112,0,112,0,122,
		12,2,1,112,1,73,36,237,0,48,74,0,102,48,
		97,0,48,43,0,102,112,0,112,0,112,1,73,36,
		239,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_LOADGET )
{
	static const HB_BYTE pcode[] =
	{
		36,245,0,48,98,0,48,31,0,102,112,0,176,99,
		0,48,100,0,102,112,0,48,65,0,102,112,0,12,
		2,112,1,73,36,246,0,48,101,0,48,31,0,102,
		112,0,176,99,0,48,102,0,102,112,0,48,65,0,
		102,112,0,12,2,112,1,73,36,248,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCENTROCOSTE_CLEARGET )
{
	static const HB_BYTE pcode[] =
	{
		36,254,0,48,103,0,48,31,0,102,112,0,176,44,
		0,92,30,12,1,112,1,73,36,255,0,48,103,0,
		48,32,0,48,31,0,102,112,0,112,0,176,44,0,
		93,200,0,12,1,112,1,73,36,1,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,106,0,2,0,116,106,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

