/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\Propiedades.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( PROPIEDADES );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( SQLBASEVIEW );
HB_FUNC_STATIC( PROPIEDADES_NEW );
HB_FUNC_STATIC( PROPIEDADES_DIALOG );
HB_FUNC_STATIC( PROPIEDADES_CREATEEDITCONTROL );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( TCHECKBOX );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( VALIDATEDIALOG );
HB_FUNC_EXTERN( HB_ISNIL );
HB_FUNC_EXTERN( HHASKEY );
HB_FUNC_EXTERN( HGET );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_PROPIEDADES )
{ "PROPIEDADES", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( PROPIEDADES )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "SQLBASEVIEW", {HB_FS_PUBLIC}, {HB_FUNCNAME( SQLBASEVIEW )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PROPIEDADES_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( PROPIEDADES_NEW )}, NULL },
{ "PROPIEDADES_DIALOG", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( PROPIEDADES_DIALOG )}, NULL },
{ "PROPIEDADES_CREATEEDITCONTROL", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( PROPIEDADES_CREATEEDITCONTROL )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OCONTROLLER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CIMAGENAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "LBLTITLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "HBUFFER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OMODEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCONTROLLER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALIDCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ISZOOMMODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALIDNOMBRE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCHECKBOX", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCHECKBOX )}, NULL },
{ "SHOWBROWSEINDIALOG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPROPIEDADESLINEASCONTROLLER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BUILDSQLNUCLEARBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OVIEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETCONTROLLER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "APPEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EDIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DELETE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "UPDET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DOWNDET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALIDATEDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALIDATEDIALOG )}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDFASTKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSTART", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NRESULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HB_ISNIL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ISNIL )}, NULL },
{ "HHASKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HHASKEY )}, NULL },
{ "HGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGET )}, NULL },
{ "_OEDITCONTROL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BWHEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OEDITCONTROL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BHELP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ASSIGNBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ISVALIDCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_PROPIEDADES, ".\\.\\Prg\\Propiedades.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_PROPIEDADES
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_PROPIEDADES )
   #include "hbiniseg.h"
#endif

HB_FUNC( PROPIEDADES )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,65,0,36,7,0,103,2,0,100,8,
		29,46,1,176,1,0,104,2,0,12,1,29,35,1,
		166,229,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,12,80,114,111,112,105,101,100,97,100,101,115,
		0,108,4,4,1,0,108,0,112,3,80,2,36,9,
		0,48,5,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,13,111,69,100,105,116,67,111,110,116,114,
		111,108,0,4,1,0,9,112,5,73,36,11,0,48,
		5,0,95,2,100,100,95,1,121,72,121,72,121,72,
		106,13,99,69,100,105,116,67,111,110,116,114,111,108,
		0,4,1,0,9,112,5,73,36,13,0,48,6,0,
		95,2,106,4,78,101,119,0,108,7,95,1,121,72,
		121,72,121,72,112,3,73,36,15,0,48,6,0,95,
		2,106,7,68,105,97,108,111,103,0,108,8,95,1,
		121,72,121,72,121,72,112,3,73,36,17,0,48,6,
		0,95,2,106,18,99,114,101,97,116,101,69,100,105,
		116,67,111,110,116,114,111,108,0,108,9,95,1,121,
		72,121,72,121,72,112,3,73,36,19,0,48,10,0,
		95,2,112,0,73,167,14,0,0,176,11,0,104,2,
		0,95,2,20,2,168,48,12,0,95,2,112,0,80,
		3,176,13,0,95,3,106,10,73,110,105,116,67,108,
		97,115,115,0,12,2,28,12,48,14,0,95,3,164,
		146,1,0,73,95,3,110,7,48,12,0,103,2,0,
		112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( PROPIEDADES_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,25,0,48,15,0,102,95,1,112,1,
		73,36,27,0,48,16,0,102,106,17,103,99,95,99,
		111,97,116,104,97,110,103,101,114,95,49,54,0,112,
		1,73,36,29,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( PROPIEDADES_DIALOG )
{
	static const HB_BYTE pcode[] =
	{
		13,6,0,36,33,0,102,80,1,36,41,0,48,2,
		0,176,17,0,12,0,100,100,100,100,48,18,0,95,
		1,112,0,106,12,112,114,111,112,105,101,100,97,100,
		101,115,0,72,106,9,80,82,79,80,95,83,81,76,
		0,100,9,100,100,100,100,100,9,100,100,100,100,100,
		9,100,106,5,111,68,108,103,0,100,100,112,24,80,
		2,36,48,0,48,19,0,176,20,0,12,0,92,100,
		89,78,0,1,0,1,0,1,0,176,21,0,12,0,
		121,8,28,31,48,22,0,48,23,0,48,24,0,95,
		255,112,0,112,0,112,0,106,7,99,111,100,105,103,
		111,0,1,25,32,95,1,165,48,22,0,48,23,0,
		48,24,0,95,255,112,0,112,0,112,0,106,7,99,
		111,100,105,103,111,0,2,6,95,2,100,100,89,26,
		0,0,0,2,0,1,0,5,0,48,25,0,48,24,
		0,95,255,112,0,95,254,112,1,6,100,100,100,100,
		100,9,89,23,0,0,0,1,0,1,0,48,26,0,
		48,24,0,95,255,112,0,112,0,68,6,100,9,9,
		100,100,100,100,100,100,100,100,100,112,25,80,5,36,
		55,0,48,19,0,176,20,0,12,0,92,110,89,78,
		0,1,0,1,0,1,0,176,21,0,12,0,121,8,
		28,31,48,22,0,48,23,0,48,24,0,95,255,112,
		0,112,0,112,0,106,7,110,111,109,98,114,101,0,
		1,25,32,95,1,165,48,22,0,48,23,0,48,24,
		0,95,255,112,0,112,0,112,0,106,7,110,111,109,
		98,114,101,0,2,6,95,2,100,100,89,26,0,0,
		0,2,0,1,0,4,0,48,27,0,48,24,0,95,
		255,112,0,95,254,112,1,6,100,100,100,100,100,9,
		89,23,0,0,0,1,0,1,0,48,26,0,48,24,
		0,95,255,112,0,112,0,68,6,100,9,9,100,100,
		100,100,100,100,100,100,100,112,25,80,4,36,60,0,
		48,19,0,176,28,0,12,0,93,200,0,89,82,0,
		1,0,1,0,1,0,176,21,0,12,0,121,8,28,
		33,48,22,0,48,23,0,48,24,0,95,255,112,0,
		112,0,112,0,106,9,105,115,95,99,111,108,111,114,
		0,1,25,34,95,1,165,48,22,0,48,23,0,48,
		24,0,95,255,112,0,112,0,112,0,106,9,105,115,
		95,99,111,108,111,114,0,2,6,95,2,100,100,100,
		100,100,100,9,89,23,0,0,0,1,0,1,0,48,
		26,0,48,24,0,95,255,112,0,112,0,68,6,9,
		112,12,73,36,62,0,48,29,0,48,30,0,48,24,
		0,95,1,112,0,112,0,92,120,95,2,112,2,80,
		6,36,64,0,48,31,0,48,32,0,48,33,0,48,
		24,0,95,1,112,0,106,7,108,105,110,101,97,115,
		0,112,1,112,0,92,120,95,2,112,2,73,36,70,
		0,48,19,0,176,34,0,12,0,93,244,1,89,36,
		0,0,0,1,0,1,0,48,35,0,48,33,0,48,
		24,0,95,255,112,0,106,7,108,105,110,101,97,115,
		0,112,1,112,0,6,95,2,100,100,9,89,23,0,
		0,0,1,0,1,0,48,26,0,48,24,0,95,255,
		112,0,112,0,68,6,100,100,9,112,10,73,36,76,
		0,48,19,0,176,34,0,12,0,93,245,1,89,36,
		0,0,0,1,0,1,0,48,36,0,48,33,0,48,
		24,0,95,255,112,0,106,7,108,105,110,101,97,115,
		0,112,1,112,0,6,95,2,100,100,9,89,23,0,
		0,0,1,0,1,0,48,26,0,48,24,0,95,255,
		112,0,112,0,68,6,100,100,9,112,10,73,36,82,
		0,48,19,0,176,34,0,12,0,93,246,1,89,49,
		0,0,0,1,0,1,0,48,37,0,48,30,0,48,
		24,0,95,255,112,0,112,0,48,38,0,48,32,0,
		48,30,0,48,24,0,95,255,112,0,112,0,112,0,
		112,0,112,1,6,95,2,100,100,9,89,23,0,0,
		0,1,0,1,0,48,26,0,48,24,0,95,255,112,
		0,112,0,68,6,100,100,9,112,10,73,36,88,0,
		48,19,0,176,34,0,12,0,93,247,1,89,36,0,
		0,0,1,0,1,0,48,37,0,48,33,0,48,24,
		0,95,255,112,0,106,7,108,105,110,101,97,115,0,
		112,1,112,0,6,95,2,100,100,9,89,23,0,0,
		0,1,0,1,0,48,26,0,48,24,0,95,255,112,
		0,112,0,68,6,100,100,9,112,10,73,36,94,0,
		48,19,0,176,34,0,12,0,93,247,1,89,36,0,
		0,0,1,0,1,0,48,39,0,48,33,0,48,24,
		0,95,255,112,0,106,7,108,105,110,101,97,115,0,
		112,1,112,0,6,95,2,100,100,9,89,23,0,0,
		0,1,0,1,0,48,26,0,48,24,0,95,255,112,
		0,112,0,68,6,100,100,9,112,10,73,36,100,0,
		48,19,0,176,34,0,12,0,93,248,1,89,36,0,
		0,0,1,0,1,0,48,40,0,48,33,0,48,24,
		0,95,255,112,0,106,7,108,105,110,101,97,115,0,
		112,1,112,0,6,95,2,100,100,9,89,23,0,0,
		0,1,0,1,0,48,26,0,48,24,0,95,255,112,
		0,112,0,68,6,100,100,9,112,10,73,36,106,0,
		48,19,0,176,34,0,12,0,122,89,36,0,0,0,
		1,0,1,0,48,40,0,48,33,0,48,24,0,95,
		255,112,0,106,7,108,105,110,101,97,115,0,112,1,
		112,0,6,95,2,100,100,9,89,23,0,0,0,1,
		0,1,0,48,26,0,48,24,0,95,255,112,0,112,
		0,68,6,100,100,9,112,10,73,36,112,0,48,19,
		0,176,34,0,12,0,122,89,30,0,0,0,1,0,
		2,0,176,41,0,95,255,12,1,28,12,48,42,0,
		95,255,122,112,1,25,3,100,6,95,2,100,100,9,
		89,23,0,0,0,1,0,1,0,48,26,0,48,24,
		0,95,255,112,0,112,0,68,6,100,100,9,112,10,
		80,3,36,118,0,48,19,0,176,34,0,12,0,92,
		2,89,17,0,0,0,1,0,2,0,48,42,0,95,
		255,112,0,6,95,2,100,100,9,100,100,100,120,112,
		10,73,36,122,0,48,43,0,95,2,92,116,89,18,
		0,0,0,1,0,2,0,48,42,0,95,255,122,112,
		1,6,112,2,73,36,126,0,48,44,0,95,2,89,
		17,0,0,0,1,0,4,0,48,45,0,95,255,112,
		0,6,112,1,73,36,128,0,48,43,0,95,2,92,
		113,89,36,0,0,0,1,0,1,0,48,35,0,48,
		33,0,48,24,0,95,255,112,0,106,7,108,105,110,
		101,97,115,0,112,1,112,0,6,112,2,73,36,129,
		0,48,43,0,95,2,92,114,89,36,0,0,0,1,
		0,1,0,48,36,0,48,33,0,48,24,0,95,255,
		112,0,106,7,108,105,110,101,97,115,0,112,1,112,
		0,6,112,2,73,36,130,0,48,43,0,95,2,92,
		115,89,36,0,0,0,1,0,1,0,48,37,0,48,
		33,0,48,24,0,95,255,112,0,106,7,108,105,110,
		101,97,115,0,112,1,112,0,6,112,2,73,36,131,
		0,48,43,0,95,2,92,116,89,17,0,0,0,1,
		0,3,0,48,46,0,95,255,112,0,6,112,2,73,
		36,135,0,48,44,0,95,2,89,17,0,0,0,1,
		0,5,0,48,45,0,95,255,112,0,6,112,1,73,
		36,137,0,48,47,0,95,2,48,48,0,95,2,112,
		0,48,49,0,95,2,112,0,48,50,0,95,2,112,
		0,120,100,100,100,48,51,0,95,2,112,0,100,100,
		100,112,11,73,36,139,0,48,52,0,95,2,112,0,
		122,8,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( PROPIEDADES_CREATEEDITCONTROL )
{
	static const HB_BYTE pcode[] =
	{
		13,2,2,36,143,0,102,80,3,36,147,0,176,53,
		0,95,1,12,1,28,9,36,148,0,95,3,110,7,
		36,151,0,176,54,0,95,2,106,6,105,100,83,97,
		121,0,12,2,28,22,36,152,0,176,55,0,95,2,
		106,6,105,100,83,97,121,0,12,2,80,4,36,155,
		0,176,54,0,95,2,106,6,105,100,71,101,116,0,
		12,2,31,9,36,156,0,95,3,110,7,36,159,0,
		176,54,0,95,2,106,7,105,100,84,101,120,116,0,
		12,2,31,9,36,160,0,95,3,110,7,36,163,0,
		176,54,0,95,2,106,7,100,105,97,108,111,103,0,
		12,2,31,9,36,164,0,95,3,110,7,36,167,0,
		176,54,0,95,2,106,5,119,104,101,110,0,12,2,
		31,9,36,168,0,95,3,110,7,36,177,0,48,56,
		0,95,3,48,19,0,176,20,0,12,0,176,55,0,
		95,2,106,6,105,100,71,101,116,0,12,2,89,28,
		0,1,0,1,0,1,0,176,21,0,12,0,121,8,
		28,6,95,255,25,7,95,1,165,80,255,6,176,55,
		0,95,2,106,7,100,105,97,108,111,103,0,12,2,
		100,100,100,100,100,100,100,100,9,100,100,9,9,100,
		100,100,100,100,100,106,5,76,117,112,97,0,95,4,
		176,55,0,95,2,106,7,105,100,84,101,120,116,0,
		12,2,112,25,112,1,73,36,179,0,48,57,0,48,
		58,0,95,3,112,0,176,55,0,95,2,106,5,119,
		104,101,110,0,12,2,112,1,73,36,180,0,48,59,
		0,48,58,0,95,3,112,0,89,29,0,0,0,1,
		0,3,0,48,60,0,48,24,0,95,255,112,0,48,
		58,0,95,255,112,0,112,1,6,112,1,73,36,181,
		0,48,61,0,48,58,0,95,3,112,0,89,29,0,
		0,0,1,0,3,0,48,62,0,48,24,0,95,255,
		112,0,48,58,0,95,255,112,0,112,1,6,112,1,
		73,36,183,0,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,65,0,2,0,116,65,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

