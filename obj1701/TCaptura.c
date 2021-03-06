/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\TCaptura.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TCAPTURA );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TMASDET );
HB_FUNC_STATIC( TCAPTURA_NEW );
HB_FUNC_STATIC( TCAPTURA_OPENFILES );
HB_FUNC_STATIC( TCAPTURA_OPENSERVICE );
HB_FUNC_STATIC( TCAPTURA_CLOSEFILES );
HB_FUNC_STATIC( TCAPTURA_CLOSESERVICE );
HB_FUNC_STATIC( TCAPTURA_REINDEXA );
HB_FUNC_STATIC( TCAPTURA_ACTIVATE );
HB_FUNC_STATIC( TCAPTURA_DEFINEFILES );
HB_FUNC_STATIC( TCAPTURA_RESOURCE );
HB_FUNC_STATIC( TCAPTURA_LPRESAVE );
HB_FUNC_STATIC( TCAPTURA_REFRESHGET );
HB_FUNC_STATIC( TCAPTURA_CREATEFIELDS );
HB_FUNC_STATIC( TCAPTURA_CREATETITLES );
HB_FUNC_STATIC( TCAPTURA_CREATESIZES );
HB_FUNC_STATIC( TCAPTURA_CREATEJUSTIFY );
HB_FUNC_STATIC( TCAPTURA_CREATECOLUMNS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( CPATDAT );
HB_FUNC_EXTERN( GETWNDFRAME );
HB_FUNC_EXTERN( NLEVELUSR );
HB_FUNC_EXTERN( TDETCAPTURA );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( LBLTITLE );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( NOTVALID );
HB_FUNC_EXTERN( TWBROWSE );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( TCHECKBOX );
HB_FUNC_EXTERN( TRADMENU );
HB_FUNC_EXTERN( RTRIM );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( NAMETOFIELD );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( APOLOBREAK );
HB_FUNC_EXTERN( NAND );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TCAPTURA )
{ "TCAPTURA", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TMASDET", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMASDET )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCAPTURA_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_NEW )}, NULL },
{ "TCAPTURA_OPENFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_OPENFILES )}, NULL },
{ "TCAPTURA_OPENSERVICE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_OPENSERVICE )}, NULL },
{ "TCAPTURA_CLOSEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_CLOSEFILES )}, NULL },
{ "TCAPTURA_CLOSESERVICE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_CLOSESERVICE )}, NULL },
{ "TCAPTURA_REINDEXA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_REINDEXA )}, NULL },
{ "TCAPTURA_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_ACTIVATE )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCAPCAMPOS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCAPTURA_DEFINEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_DEFINEFILES )}, NULL },
{ "TCAPTURA_RESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_RESOURCE )}, NULL },
{ "TCAPTURA_LPRESAVE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_LPRESAVE )}, NULL },
{ "TCAPTURA_REFRESHGET", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_REFRESHGET )}, NULL },
{ "TCAPTURA_CREATEFIELDS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_CREATEFIELDS )}, NULL },
{ "TCAPTURA_CREATETITLES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_CREATETITLES )}, NULL },
{ "TCAPTURA_CREATESIZES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_CREATESIZES )}, NULL },
{ "TCAPTURA_CREATEJUSTIFY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_CREATEJUSTIFY )}, NULL },
{ "TCAPTURA_CREATECOLUMNS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCAPTURA_CREATECOLUMNS )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATDAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATDAT )}, NULL },
{ "GETWNDFRAME", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETWNDFRAME )}, NULL },
{ "_NLEVEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEVELUSR", {HB_FS_PUBLIC}, {HB_FUNCNAME( NLEVELUSR )}, NULL },
{ "_CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OWNDPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LREPORT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BFIRSTKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OCAPCAMPOS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDETCAPTURA", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDETCAPTURA )}, NULL },
{ "ADDDETAIL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BDEFAULTVALUES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHECKDEFAULTVIR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BONPREEDIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "DEFINEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "APPEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CNOMBRE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPENDETAILS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "USED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLOSEDETAILS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "LBLTITLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( LBLTITLE )}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "NOTVALID", {HB_FS_PUBLIC}, {HB_FUNCNAME( NOTVALID )}, NULL },
{ "CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CNOMBRE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TWBROWSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( TWBROWSE )}, NULL },
{ "ODBFVIR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BGOTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BGOBOTTOM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOBOTTOM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SKIPPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BLOGICLEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LASTREC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BCHANGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REFRESHGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LDRAWHEADERS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "SWAPUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SWAPDOWN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GODOWN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OVISIBLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCHECKBOX", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCHECKBOX )}, NULL },
{ "LVISIBLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LVISIBLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OCAPTURA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TRADMENU", {HB_FS_PUBLIC}, {HB_FUNCNAME( TRADMENU )}, NULL },
{ "NCAPTURA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NCAPTURA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OTITULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTITULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CTITULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OANCHO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NANCHO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NANCHO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OCHKBITMAP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LBITMAP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LBITMAP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LPRESAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDFASTKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSTART", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NRESULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEKINORD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( RTRIM )}, NULL },
{ "OVISIBLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEDITABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BWHEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DISABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCAPTURA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OTITULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OANCHO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCHKBITMAP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NAMETOFIELD", {HB_FS_PUBLIC}, {HB_FUNCNAME( NAMETOFIELD )}, NULL },
{ "SKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LALIGN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDCOL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BEDITVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETCHECK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NDATASTRALIGN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHEADSTRALIGN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CARGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "APOLOBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( APOLOBREAK )}, NULL },
{ "CLOSESERVICE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "IDXFDEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPENSERVICE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PACK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NAND", {HB_FS_PUBLIC}, {HB_FUNCNAME( NAND )}, NULL },
{ "NLEVEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OWNDPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLOSEALL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPENFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LCREATESHELL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATESHELL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWAT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OWNDBRW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEARCHSETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDSEABAR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RECADD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RECDUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RECEDIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RECZOOM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RECDEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENDBUTTONS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHTMLHELP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CHTMLHELP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLOSEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TCAPTURA, ".\\.\\Prg\\TCaptura.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TCAPTURA
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TCAPTURA )
   #include "hbiniseg.h"
#endif

HB_FUNC( TCAPTURA )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,171,0,36,9,0,103,2,0,100,8,
		29,20,4,176,1,0,104,2,0,12,1,29,9,4,
		166,203,3,0,122,80,1,48,2,0,176,3,0,12,
		0,106,9,84,67,97,112,116,117,114,97,0,108,4,
		4,1,0,108,0,112,3,80,2,36,11,0,48,5,
		0,95,2,100,100,95,1,121,72,121,72,121,72,106,
		11,111,67,97,112,67,97,109,112,111,115,0,4,1,
		0,9,112,5,73,36,13,0,48,5,0,95,2,100,
		100,95,1,121,72,121,72,121,72,106,9,111,86,105,
		115,105,98,108,101,0,4,1,0,9,112,5,73,36,
		14,0,48,5,0,95,2,100,100,95,1,121,72,121,
		72,121,72,106,9,111,67,97,112,116,117,114,97,0,
		4,1,0,9,112,5,73,36,15,0,48,5,0,95,
		2,100,100,95,1,121,72,121,72,121,72,106,8,111,
		84,105,116,117,108,111,0,4,1,0,9,112,5,73,
		36,16,0,48,5,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,7,111,65,110,99,104,111,0,4,
		1,0,9,112,5,73,36,17,0,48,5,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,11,111,67,
		104,107,66,105,116,109,97,112,0,4,1,0,9,112,
		5,73,36,19,0,48,5,0,95,2,100,106,20,103,
		99,95,119,105,110,100,111,119,95,112,101,110,99,105,
		108,95,49,54,0,95,1,121,72,121,72,121,72,106,
		5,99,77,114,117,0,4,1,0,9,112,5,73,36,
		20,0,48,5,0,95,2,100,106,12,87,101,98,84,
		111,112,71,114,101,101,110,0,95,1,121,72,121,72,
		121,72,106,8,99,66,105,116,109,97,112,0,4,1,
		0,9,112,5,73,36,22,0,48,6,0,95,2,106,
		4,78,101,119,0,108,7,95,1,121,72,121,72,121,
		72,112,3,73,36,24,0,48,6,0,95,2,106,10,
		79,112,101,110,70,105,108,101,115,0,108,8,95,1,
		121,72,121,72,121,72,112,3,73,36,25,0,48,6,
		0,95,2,106,12,79,112,101,110,83,101,114,118,105,
		99,101,0,108,9,95,1,121,72,121,72,121,72,112,
		3,73,36,27,0,48,6,0,95,2,106,11,67,108,
		111,115,101,70,105,108,101,115,0,108,10,95,1,121,
		72,121,72,121,72,112,3,73,36,28,0,48,6,0,
		95,2,106,13,67,108,111,115,101,83,101,114,118,105,
		99,101,0,108,11,95,1,121,72,121,72,121,72,112,
		3,73,36,30,0,48,6,0,95,2,106,9,82,101,
		105,110,100,101,120,97,0,108,12,95,1,121,72,121,
		72,121,72,112,3,73,36,32,0,48,6,0,95,2,
		106,9,65,99,116,105,118,97,116,101,0,108,13,95,
		1,121,72,121,72,121,72,112,3,73,36,34,0,48,
		14,0,95,2,106,14,108,69,120,105,115,116,67,97,
		112,116,117,114,97,0,89,27,0,2,0,0,0,48,
		15,0,48,16,0,48,17,0,95,1,112,0,112,0,
		95,2,112,1,6,95,1,121,72,121,72,121,72,112,
		3,73,36,36,0,48,6,0,95,2,106,12,68,101,
		102,105,110,101,70,105,108,101,115,0,108,18,95,1,
		121,72,121,72,121,72,112,3,73,36,38,0,48,6,
		0,95,2,106,9,82,101,115,111,117,114,99,101,0,
		108,19,95,1,121,72,121,72,121,72,112,3,73,36,
		40,0,48,6,0,95,2,106,9,108,80,114,101,83,
		97,118,101,0,108,20,95,1,121,72,121,72,121,72,
		112,3,73,36,42,0,48,6,0,95,2,106,11,82,
		101,102,114,101,115,104,71,101,116,0,108,21,95,1,
		121,72,121,72,121,72,112,3,73,36,44,0,48,6,
		0,95,2,106,13,67,114,101,97,116,101,70,105,101,
		108,100,115,0,108,22,95,1,121,72,121,72,121,72,
		112,3,73,36,45,0,48,6,0,95,2,106,13,67,
		114,101,97,116,101,84,105,116,108,101,115,0,108,23,
		95,1,121,72,121,72,121,72,112,3,73,36,46,0,
		48,6,0,95,2,106,12,67,114,101,97,116,101,83,
		105,122,101,115,0,108,24,95,1,121,72,121,72,121,
		72,112,3,73,36,47,0,48,6,0,95,2,106,14,
		67,114,101,97,116,101,74,117,115,116,105,102,121,0,
		108,25,95,1,121,72,121,72,121,72,112,3,73,36,
		49,0,48,6,0,95,2,106,14,67,114,101,97,116,
		101,67,111,108,117,109,110,115,0,108,26,95,1,121,
		72,121,72,121,72,112,3,73,36,51,0,48,27,0,
		95,2,112,0,73,167,14,0,0,176,28,0,104,2,
		0,95,2,20,2,168,48,29,0,95,2,112,0,80,
		3,176,30,0,95,3,106,10,73,110,105,116,67,108,
		97,115,115,0,12,2,28,12,48,31,0,95,3,164,
		146,1,0,73,95,3,110,7,48,29,0,103,2,0,
		112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,1,3,36,55,0,102,80,4,36,57,0,95,1,
		100,8,28,9,176,32,0,12,0,80,1,36,58,0,
		95,2,100,8,28,9,176,33,0,12,0,80,2,36,
		59,0,95,3,100,8,28,12,106,6,48,49,48,56,
		51,0,80,3,36,61,0,48,34,0,95,4,176,35,
		0,95,3,12,1,112,1,73,36,63,0,48,36,0,
		95,4,95,1,112,1,73,36,64,0,48,37,0,95,
		4,95,2,112,1,73,36,65,0,48,38,0,95,4,
		9,112,1,73,36,67,0,48,39,0,95,4,89,22,
		0,0,0,1,0,4,0,48,40,0,48,16,0,95,
		255,112,0,112,0,6,112,1,73,36,69,0,48,41,
		0,95,4,48,2,0,176,42,0,12,0,95,1,100,
		95,4,112,3,112,1,73,36,70,0,48,43,0,95,
		4,48,17,0,95,4,112,0,112,1,73,36,73,0,
		48,44,0,48,17,0,95,4,112,0,89,22,0,0,
		0,1,0,4,0,48,45,0,48,17,0,95,255,112,
		0,112,0,6,112,1,73,36,74,0,48,46,0,95,
		4,89,87,0,0,0,1,0,4,0,48,40,0,48,
		16,0,95,255,112,0,112,0,106,4,48,48,48,0,
		8,28,57,176,47,0,106,45,78,111,32,115,101,32,
		112,117,101,100,101,32,109,111,100,105,102,105,99,97,
		114,32,108,97,32,99,97,112,116,117,114,97,32,112,
		111,114,32,100,101,102,101,99,116,111,0,20,1,9,
		25,3,120,6,112,1,73,36,76,0,95,4,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_OPENFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,82,0,95,1,100,8,28,5,9,80,
		1,36,84,0,176,48,0,48,16,0,102,112,0,12,
		1,28,12,36,85,0,48,49,0,102,112,0,73,36,
		88,0,48,50,0,48,16,0,102,112,0,9,95,1,
		68,112,2,73,36,90,0,48,15,0,48,16,0,102,
		112,0,106,4,48,48,48,0,112,1,31,90,36,91,
		0,48,51,0,48,16,0,102,112,0,112,0,73,36,
		92,0,48,52,0,48,16,0,102,112,0,106,4,48,
		48,48,0,112,1,73,36,93,0,48,53,0,48,16,
		0,102,112,0,106,20,67,97,112,116,117,114,97,32,
		112,111,114,32,100,101,102,101,99,116,111,0,112,1,
		73,36,94,0,48,54,0,48,16,0,102,112,0,112,
		0,73,36,97,0,48,55,0,102,112,0,73,36,99,
		0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_CLOSEFILES )
{
	static const HB_BYTE pcode[] =
	{
		36,105,0,176,48,0,48,16,0,102,112,0,12,1,
		31,41,48,56,0,48,16,0,102,112,0,112,0,28,
		28,36,106,0,48,57,0,48,16,0,102,112,0,112,
		0,73,36,107,0,48,58,0,102,100,112,1,73,36,
		110,0,48,59,0,102,112,0,73,36,112,0,48,57,
		0,48,17,0,102,112,0,112,0,73,36,114,0,120,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_DEFINEFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,120,0,95,1,100,8,28,10,48,60,
		0,102,112,0,80,1,36,121,0,95,2,100,8,28,
		9,176,61,0,12,0,80,2,36,123,0,48,58,0,
		102,48,2,0,176,62,0,106,12,67,97,112,116,117,
		114,97,46,68,98,102,0,106,8,67,97,112,116,117,
		114,97,0,12,2,106,12,67,97,112,116,117,114,97,
		46,68,98,102,0,106,8,67,97,112,116,117,114,97,
		0,95,2,106,15,67,97,112,116,117,114,97,32,100,
		101,32,84,80,86,0,95,1,112,5,112,1,73,36,
		125,0,48,63,0,48,16,0,102,112,0,106,8,99,
		67,111,100,105,103,111,0,106,2,67,0,92,3,121,
		100,100,100,100,106,7,67,243,100,105,103,111,0,9,
		92,100,9,4,0,0,112,13,73,36,126,0,48,63,
		0,48,16,0,102,112,0,106,8,99,78,111,109,98,
		114,101,0,106,2,67,0,92,35,121,100,100,100,100,
		106,7,78,111,109,98,114,101,0,9,93,144,1,9,
		4,0,0,112,13,73,36,128,0,48,64,0,48,16,
		0,102,112,0,106,8,99,67,111,100,105,103,111,0,
		106,12,67,97,112,116,117,114,97,46,67,100,120,0,
		106,8,99,67,111,100,105,103,111,0,100,100,9,9,
		106,7,67,243,100,105,103,111,0,100,100,120,9,112,
		12,73,36,129,0,48,64,0,48,16,0,102,112,0,
		106,8,99,78,111,109,98,114,101,0,106,12,67,97,
		112,116,117,114,97,46,67,100,120,0,106,8,99,78,
		111,109,98,114,101,0,100,100,9,9,106,7,78,111,
		109,98,114,101,0,100,100,120,9,112,12,73,36,133,
		0,48,16,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_RESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,4,1,36,137,0,102,80,2,36,143,0,48,2,
		0,176,65,0,12,0,100,100,100,100,176,66,0,95,
		1,12,1,106,19,99,97,112,116,117,114,97,115,32,
		100,101,32,84,46,80,46,86,46,0,72,106,8,67,
		97,112,116,117,114,97,0,100,9,100,100,100,100,100,
		9,100,100,100,100,100,9,100,106,5,111,68,108,103,
		0,100,100,112,24,80,3,36,150,0,48,67,0,176,
		68,0,12,0,92,100,89,47,0,1,0,1,0,2,
		0,176,69,0,12,0,121,8,28,16,48,40,0,48,
		16,0,95,255,112,0,112,0,25,16,48,52,0,48,
		16,0,95,255,112,0,95,1,112,1,6,95,3,100,
		106,3,64,33,0,89,31,0,0,0,2,0,5,0,
		2,0,176,70,0,95,255,48,71,0,48,16,0,95,
		254,112,0,112,0,12,2,6,100,100,100,100,100,9,
		89,14,0,0,0,1,0,1,0,95,255,122,8,6,
		100,9,9,100,100,100,100,100,100,100,100,100,112,25,
		80,5,36,155,0,48,67,0,176,68,0,12,0,92,
		110,89,47,0,1,0,1,0,2,0,176,69,0,12,
		0,121,8,28,16,48,72,0,48,16,0,95,255,112,
		0,112,0,25,16,48,53,0,48,16,0,95,255,112,
		0,95,1,112,1,6,95,3,100,100,100,100,100,100,
		100,100,9,89,15,0,0,0,1,0,1,0,95,255,
		92,3,69,6,100,9,9,100,100,100,100,100,100,100,
		100,100,112,25,73,36,162,0,48,67,0,176,73,0,
		12,0,92,120,89,30,0,0,0,1,0,2,0,48,
		72,0,48,74,0,48,17,0,95,255,112,0,112,0,
		112,0,4,1,0,6,95,3,106,1,0,4,1,0,
		92,120,4,1,0,100,100,100,100,100,100,100,100,100,
		100,100,9,100,100,100,100,100,112,22,80,4,36,164,
		0,48,75,0,95,4,89,27,0,0,0,1,0,2,
		0,48,76,0,48,74,0,48,17,0,95,255,112,0,
		112,0,112,0,6,112,1,73,36,165,0,48,77,0,
		95,4,89,27,0,0,0,1,0,2,0,48,78,0,
		48,74,0,48,17,0,95,255,112,0,112,0,112,0,
		6,112,1,73,36,166,0,48,79,0,95,4,89,29,
		0,1,0,1,0,2,0,48,80,0,48,74,0,48,
		17,0,95,255,112,0,112,0,95,1,112,1,6,112,
		1,73,36,167,0,48,81,0,95,4,89,27,0,0,
		0,1,0,2,0,48,82,0,48,74,0,48,17,0,
		95,255,112,0,112,0,112,0,6,112,1,73,36,168,
		0,48,83,0,95,4,89,21,0,0,0,2,0,2,
		0,1,0,48,84,0,95,255,95,254,112,1,6,112,
		1,73,36,169,0,48,85,0,95,4,9,112,1,73,
		36,175,0,48,67,0,176,86,0,12,0,93,130,0,
		89,37,0,0,0,2,0,2,0,4,0,48,87,0,
		48,74,0,48,17,0,95,255,112,0,112,0,112,0,
		73,48,88,0,95,254,112,0,6,95,3,100,100,9,
		89,15,0,0,0,1,0,1,0,95,255,92,3,69,
		6,100,100,9,112,10,73,36,181,0,48,67,0,176,
		86,0,12,0,93,140,0,89,37,0,0,0,2,0,
		2,0,4,0,48,89,0,48,74,0,48,17,0,95,
		255,112,0,112,0,112,0,73,48,90,0,95,254,112,
		0,6,95,3,100,100,9,89,15,0,0,0,1,0,
		1,0,95,255,92,3,69,6,100,100,9,112,10,73,
		36,186,0,48,91,0,95,2,48,67,0,176,92,0,
		12,0,93,150,0,89,57,0,1,0,1,0,2,0,
		176,69,0,12,0,121,8,28,21,48,93,0,48,74,
		0,48,17,0,95,255,112,0,112,0,112,0,25,21,
		48,94,0,48,74,0,48,17,0,95,255,112,0,112,
		0,95,1,112,1,6,95,3,100,100,100,100,100,100,
		9,89,15,0,0,0,1,0,1,0,95,255,92,3,
		69,6,9,112,12,112,1,73,36,191,0,48,95,0,
		95,2,48,67,0,176,96,0,12,0,89,57,0,1,
		0,1,0,2,0,176,69,0,12,0,121,8,28,21,
		48,97,0,48,74,0,48,17,0,95,255,112,0,112,
		0,112,0,25,21,48,98,0,48,74,0,48,17,0,
		95,255,112,0,112,0,95,1,112,1,6,95,3,100,
		93,160,0,93,161,0,93,162,0,4,3,0,100,100,
		100,100,9,89,15,0,0,0,1,0,1,0,95,255,
		92,3,69,6,100,112,11,112,1,73,36,196,0,48,
		99,0,95,2,48,67,0,176,68,0,12,0,93,170,
		0,89,57,0,1,0,1,0,2,0,176,69,0,12,
		0,121,8,28,21,48,100,0,48,74,0,48,17,0,
		95,255,112,0,112,0,112,0,25,21,48,101,0,48,
		74,0,48,17,0,95,255,112,0,112,0,95,1,112,
		1,6,95,3,100,100,100,100,100,100,100,100,9,89,
		15,0,0,0,1,0,1,0,95,255,92,3,69,6,
		100,9,9,100,100,100,100,100,100,100,100,100,112,25,
		112,1,73,36,203,0,48,102,0,95,2,48,67,0,
		176,68,0,12,0,93,180,0,89,57,0,1,0,1,
		0,2,0,176,69,0,12,0,121,8,28,21,48,103,
		0,48,74,0,48,17,0,95,255,112,0,112,0,112,
		0,25,21,48,104,0,48,74,0,48,17,0,95,255,
		112,0,112,0,95,1,112,1,6,95,3,100,106,4,
		57,57,57,0,100,100,100,100,100,100,9,89,15,0,
		0,0,1,0,1,0,95,255,92,3,69,6,100,9,
		120,100,100,100,100,100,100,100,100,100,112,25,112,1,
		73,36,208,0,48,105,0,95,2,48,67,0,176,92,
		0,12,0,93,190,0,89,57,0,1,0,1,0,2,
		0,176,69,0,12,0,121,8,28,21,48,106,0,48,
		74,0,48,17,0,95,255,112,0,112,0,112,0,25,
		21,48,107,0,48,74,0,48,17,0,95,255,112,0,
		112,0,95,1,112,1,6,95,3,100,100,100,100,100,
		100,9,89,15,0,0,0,1,0,1,0,95,255,92,
		3,69,6,9,112,12,112,1,73,36,214,0,48,67,
		0,176,86,0,12,0,122,89,36,0,0,0,3,0,
		2,0,1,0,3,0,48,108,0,95,255,95,254,112,
		1,28,12,48,57,0,95,253,122,112,1,25,3,100,
		6,95,3,100,100,9,89,15,0,0,0,1,0,1,
		0,95,255,92,3,69,6,100,100,9,112,10,73,36,
		220,0,48,67,0,176,86,0,12,0,92,2,89,17,
		0,0,0,1,0,3,0,48,57,0,95,255,112,0,
		6,95,3,100,100,9,100,100,100,120,112,10,73,36,
		222,0,95,1,92,3,69,28,51,36,223,0,48,109,
		0,95,3,92,116,89,36,0,0,0,3,0,2,0,
		1,0,3,0,48,108,0,95,255,95,254,112,1,28,
		12,48,57,0,95,253,122,112,1,25,3,100,6,112,
		2,73,36,226,0,48,110,0,95,3,89,31,0,0,
		0,3,0,2,0,1,0,5,0,48,84,0,95,255,
		95,254,112,1,73,48,111,0,95,253,112,0,6,112,
		1,73,36,228,0,48,50,0,95,3,48,112,0,95,
		3,112,0,48,113,0,95,3,112,0,48,114,0,95,
		3,112,0,120,100,100,100,48,115,0,95,3,112,0,
		100,100,100,112,11,73,36,230,0,48,116,0,95,3,
		112,0,122,8,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_LPRESAVE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,236,0,95,1,122,8,31,10,95,1,
		92,4,8,29,160,0,36,238,0,176,48,0,48,40,
		0,48,16,0,102,112,0,112,0,12,1,28,50,36,
		239,0,176,47,0,106,32,69,108,32,99,243,100,105,
		103,111,32,110,111,32,112,117,101,100,101,32,101,115,
		116,97,114,32,118,97,99,237,111,46,0,20,1,36,
		240,0,9,110,7,36,243,0,48,117,0,48,16,0,
		102,112,0,48,40,0,48,16,0,102,112,0,112,0,
		106,8,99,67,111,100,105,103,111,0,112,2,28,53,
		36,244,0,176,47,0,106,18,67,243,100,105,103,111,
		32,121,97,32,101,120,105,115,116,101,32,0,176,118,
		0,48,40,0,48,16,0,102,112,0,112,0,12,1,
		72,20,1,36,245,0,9,110,7,36,250,0,176,48,
		0,48,72,0,48,16,0,102,112,0,112,0,12,1,
		28,50,36,251,0,176,47,0,106,32,69,108,32,110,
		111,109,98,114,101,32,110,111,32,112,117,101,100,101,
		32,101,115,116,97,114,32,118,97,99,237,111,46,0,
		20,1,36,252,0,9,110,7,36,255,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_REFRESHGET )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,5,1,176,48,0,48,119,0,102,112,
		0,12,1,31,118,36,7,1,95,1,92,3,69,28,
		93,36,9,1,48,120,0,48,74,0,48,17,0,102,
		112,0,112,0,112,0,28,38,36,10,1,48,121,0,
		48,119,0,102,112,0,90,4,120,6,112,1,73,36,
		11,1,48,122,0,48,119,0,102,112,0,112,0,73,
		25,36,36,13,1,48,121,0,48,119,0,102,112,0,
		90,4,9,6,112,1,73,36,14,1,48,123,0,48,
		119,0,102,112,0,112,0,73,36,19,1,48,124,0,
		48,119,0,102,112,0,112,0,73,36,23,1,176,48,
		0,48,125,0,102,112,0,12,1,31,17,36,24,1,
		48,124,0,48,125,0,102,112,0,112,0,73,36,27,
		1,176,48,0,48,126,0,102,112,0,12,1,31,17,
		36,28,1,48,124,0,48,126,0,102,112,0,112,0,
		73,36,31,1,176,48,0,48,127,0,102,112,0,12,
		1,31,17,36,32,1,48,124,0,48,127,0,102,112,
		0,112,0,73,36,35,1,176,48,0,48,128,0,102,
		112,0,12,1,31,17,36,36,1,48,124,0,48,128,
		0,102,112,0,112,0,73,36,39,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_CREATEFIELDS )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,45,1,4,0,0,80,2,36,47,1,
		95,1,100,8,28,10,106,4,48,48,48,0,80,1,
		36,49,1,48,15,0,48,16,0,48,17,0,102,112,
		0,112,0,95,1,112,1,29,137,0,36,51,1,48,
		40,0,48,16,0,48,17,0,102,112,0,112,0,112,
		0,95,1,8,28,99,48,129,0,48,16,0,48,17,
		0,102,112,0,112,0,112,0,31,81,36,53,1,48,
		93,0,48,16,0,48,17,0,102,112,0,112,0,112,
		0,28,38,36,54,1,176,130,0,95,2,48,131,0,
		176,132,0,48,72,0,48,16,0,48,17,0,102,112,
		0,112,0,112,0,12,1,112,0,20,2,36,57,1,
		48,133,0,48,16,0,48,17,0,102,112,0,112,0,
		112,0,73,25,137,36,61,1,176,130,0,95,2,106,
		1,0,20,2,36,65,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_CREATETITLES )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,71,1,4,0,0,80,2,36,73,1,
		95,1,100,8,28,10,106,4,48,48,48,0,80,1,
		36,75,1,48,15,0,48,16,0,48,17,0,102,112,
		0,112,0,95,1,112,1,29,132,0,36,77,1,48,
		40,0,48,16,0,48,17,0,102,112,0,112,0,112,
		0,95,1,8,28,94,48,129,0,48,16,0,48,17,
		0,102,112,0,112,0,112,0,31,76,36,79,1,48,
		93,0,48,16,0,48,17,0,102,112,0,112,0,112,
		0,28,33,36,80,1,176,130,0,95,2,176,118,0,
		48,100,0,48,16,0,48,17,0,102,112,0,112,0,
		112,0,12,1,20,2,36,83,1,48,133,0,48,16,
		0,48,17,0,102,112,0,112,0,112,0,73,25,142,
		36,87,1,176,130,0,95,2,106,1,0,20,2,36,
		91,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_CREATESIZES )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,97,1,4,0,0,80,2,36,99,1,
		95,1,100,8,28,10,106,4,48,48,48,0,80,1,
		36,101,1,48,15,0,48,16,0,48,17,0,102,112,
		0,112,0,95,1,112,1,28,126,36,103,1,48,40,
		0,48,16,0,48,17,0,102,112,0,112,0,112,0,
		95,1,8,28,89,48,129,0,48,16,0,48,17,0,
		102,112,0,112,0,112,0,31,71,36,105,1,48,93,
		0,48,16,0,48,17,0,102,112,0,112,0,112,0,
		28,28,36,106,1,176,130,0,95,2,48,103,0,48,
		16,0,48,17,0,102,112,0,112,0,112,0,20,2,
		36,109,1,48,133,0,48,16,0,48,17,0,102,112,
		0,112,0,112,0,73,25,147,36,113,1,176,130,0,
		95,2,93,200,0,20,2,36,117,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_CREATEJUSTIFY )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,123,1,4,0,0,80,2,36,125,1,
		95,1,100,8,28,10,106,4,48,48,48,0,80,1,
		36,127,1,48,15,0,48,16,0,48,17,0,102,112,
		0,112,0,95,1,112,1,28,126,36,129,1,48,40,
		0,48,16,0,48,17,0,102,112,0,112,0,112,0,
		95,1,8,28,89,48,129,0,48,16,0,48,17,0,
		102,112,0,112,0,112,0,31,71,36,131,1,48,93,
		0,48,16,0,48,17,0,102,112,0,112,0,112,0,
		28,28,36,132,1,176,130,0,95,2,48,134,0,48,
		16,0,48,17,0,102,112,0,112,0,112,0,20,2,
		36,135,1,48,133,0,48,16,0,48,17,0,102,112,
		0,112,0,112,0,73,25,147,36,139,1,176,130,0,
		95,2,93,200,0,20,2,36,143,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_CREATECOLUMNS )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,149,1,95,1,100,8,28,10,106,4,
		48,48,48,0,80,1,36,151,1,48,15,0,48,16,
		0,48,17,0,102,112,0,112,0,95,1,112,1,29,
		83,1,36,153,1,48,40,0,48,16,0,48,17,0,
		102,112,0,112,0,112,0,95,1,8,29,58,1,48,
		129,0,48,16,0,48,17,0,102,112,0,112,0,112,
		0,32,39,1,36,155,1,48,93,0,48,16,0,48,
		17,0,102,112,0,112,0,112,0,29,250,0,36,157,
		1,48,135,0,95,2,112,0,143,36,159,1,144,136,
		0,176,118,0,48,100,0,48,16,0,48,17,0,102,
		112,0,112,0,112,0,12,1,112,1,73,36,160,1,
		144,137,0,48,103,0,48,16,0,48,17,0,102,112,
		0,112,0,112,0,112,1,73,36,161,1,144,138,0,
		176,132,0,48,72,0,48,16,0,48,17,0,102,112,
		0,112,0,112,0,12,1,112,1,73,36,163,1,48,
		106,0,48,16,0,48,17,0,102,112,0,112,0,112,
		0,28,41,36,164,1,144,139,0,106,17,103,99,95,
		115,116,97,114,50,95,98,108,117,101,95,49,54,0,
		106,6,78,105,108,49,54,0,4,2,0,112,1,73,
		36,167,1,48,134,0,48,16,0,48,17,0,102,112,
		0,112,0,112,0,28,22,36,168,1,144,140,0,122,
		112,1,73,36,169,1,144,141,0,122,112,1,73,36,
		172,1,144,142,0,176,118,0,48,72,0,48,16,0,
		48,17,0,102,112,0,112,0,112,0,12,1,48,97,
		0,48,16,0,48,17,0,102,112,0,112,0,112,0,
		4,2,0,112,1,73,145,36,178,1,48,133,0,48,
		16,0,48,17,0,102,112,0,112,0,112,0,73,26,
		179,254,36,184,1,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_OPENSERVICE )
{
	static const HB_BYTE pcode[] =
	{
		13,2,2,36,190,1,120,80,3,36,191,1,176,143,
		0,89,15,0,1,0,0,0,176,144,0,95,1,12,
		1,6,12,1,80,4,36,193,1,95,1,100,8,28,
		5,9,80,1,36,195,1,113,55,0,0,36,197,1,
		176,48,0,48,16,0,102,112,0,12,1,28,14,36,
		198,1,48,49,0,102,95,2,112,1,73,36,201,1,
		48,50,0,48,16,0,102,112,0,9,95,1,68,112,
		2,73,114,88,0,0,36,203,1,115,73,36,205,1,
		9,80,3,36,207,1,48,145,0,102,112,0,73,36,
		209,1,176,47,0,106,53,73,109,112,111,115,105,98,
		108,101,32,97,98,114,105,114,32,116,111,100,97,115,
		32,108,97,115,32,98,97,115,101,115,32,100,101,32,
		100,97,116,111,115,32,100,101,32,99,97,112,116,117,
		114,97,115,0,20,1,36,213,1,176,143,0,95,4,
		20,1,36,215,1,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_CLOSESERVICE )
{
	static const HB_BYTE pcode[] =
	{
		36,221,1,176,48,0,48,16,0,102,112,0,12,1,
		31,17,36,222,1,48,57,0,48,16,0,102,112,0,
		112,0,73,36,225,1,48,58,0,102,100,112,1,73,
		36,227,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_REINDEXA )
{
	static const HB_BYTE pcode[] =
	{
		36,237,1,176,48,0,48,16,0,102,112,0,12,1,
		28,18,36,238,1,48,58,0,102,48,49,0,102,112,
		0,112,1,73,36,241,1,48,146,0,48,16,0,102,
		112,0,112,0,73,36,243,1,48,147,0,102,120,112,
		1,28,17,36,244,1,48,148,0,48,16,0,102,112,
		0,112,0,73,36,247,1,48,145,0,102,112,0,73,
		36,249,1,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCAPTURA_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,253,1,102,80,1,36,255,1,176,149,
		0,48,150,0,95,1,112,0,122,12,2,121,8,29,
		116,2,36,5,2,48,151,0,95,1,112,0,100,69,
		28,18,36,6,2,48,152,0,48,151,0,95,1,112,
		0,112,0,73,36,9,2,176,48,0,48,16,0,95,
		1,112,0,12,1,28,20,36,10,2,48,153,0,95,
		1,112,0,31,8,36,11,2,100,110,7,36,19,2,
		48,154,0,95,1,112,0,31,20,36,20,2,48,155,
		0,95,1,48,150,0,95,1,112,0,112,1,73,36,
		28,2,48,156,0,48,157,0,95,1,112,0,106,4,
		66,85,83,0,100,100,89,22,0,0,0,1,0,1,
		0,48,158,0,48,157,0,95,255,112,0,112,0,6,
		106,9,40,66,41,117,115,99,97,114,0,106,2,66,
		0,100,100,100,100,9,112,11,73,36,29,2,48,159,
		0,48,157,0,95,1,112,0,112,0,73,36,37,2,
		48,156,0,48,157,0,95,1,112,0,106,4,78,69,
		87,0,100,100,89,22,0,0,0,1,0,1,0,48,
		160,0,48,157,0,95,255,112,0,112,0,6,106,9,
		40,65,41,241,97,100,105,114,0,106,2,65,0,100,
		100,92,2,100,9,112,11,73,36,46,2,48,156,0,
		48,157,0,95,1,112,0,106,4,68,85,80,0,100,
		100,89,22,0,0,0,1,0,1,0,48,161,0,48,
		157,0,95,255,112,0,112,0,6,106,11,40,68,41,
		117,112,108,105,99,97,114,0,106,2,68,0,100,100,
		92,2,100,9,112,11,73,36,53,2,48,156,0,48,
		157,0,95,1,112,0,106,5,69,68,73,84,0,100,
		100,89,22,0,0,0,1,0,1,0,48,162,0,48,
		157,0,95,255,112,0,112,0,6,106,12,40,77,41,
		111,100,105,102,105,99,97,114,0,106,2,77,0,100,
		100,92,4,100,9,112,11,73,36,60,2,48,156,0,
		48,157,0,95,1,112,0,106,5,90,79,79,77,0,
		100,100,89,22,0,0,0,1,0,1,0,48,163,0,
		48,157,0,95,255,112,0,112,0,6,106,7,40,90,
		41,111,111,109,0,106,2,90,0,100,100,92,8,100,
		9,112,11,73,36,68,2,48,156,0,48,157,0,95,
		1,112,0,106,4,68,69,76,0,100,100,89,22,0,
		0,0,1,0,1,0,48,164,0,48,157,0,95,255,
		112,0,112,0,6,106,11,40,69,41,108,105,109,105,
		110,97,114,0,106,2,69,0,100,100,92,16,100,9,
		112,11,73,36,70,2,48,165,0,48,157,0,95,1,
		112,0,95,1,112,1,73,36,72,2,48,166,0,95,
		1,112,0,100,69,28,25,36,73,2,48,167,0,48,
		157,0,95,1,112,0,48,166,0,95,1,112,0,112,
		1,73,36,76,2,48,50,0,48,157,0,95,1,112,
		0,100,100,100,100,100,100,100,100,100,100,100,100,100,
		100,100,100,89,17,0,0,0,1,0,1,0,48,168,
		0,95,255,112,0,6,112,17,73,25,33,36,80,2,
		176,47,0,106,21,65,99,99,101,115,111,32,110,111,
		32,112,101,114,109,105,116,105,100,111,46,0,20,1,
		36,84,2,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,171,0,2,0,116,171,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

