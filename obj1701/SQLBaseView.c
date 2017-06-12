/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\SQLBaseView.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( SQLBASEVIEW );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_STATIC( SQLBASEVIEW_NEW );
HB_FUNC_STATIC( SQLBASEVIEW_BUILDSQLSHELL );
HB_FUNC_STATIC( SQLBASEVIEW_BUILDSQLBROWSE );
HB_FUNC_STATIC( SQLBASEVIEW_BUILDSQLNUCLEARBROWSE );
HB_FUNC_EXTERN( HHASKEY );
HB_FUNC_EXTERN( HGET );
HB_FUNC_STATIC( SQLBASEVIEW_GENERALBUTTONS );
HB_FUNC_STATIC( SQLBASEVIEW_ENDBUTTON );
HB_FUNC_STATIC( SQLBASEVIEW_CHANGEFIND );
HB_FUNC_STATIC( SQLBASEVIEW_CHANGECOMBO );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( DISABLEACCESO );
HB_FUNC_EXTERN( SQLTSHELL );
HB_FUNC_EXTERN( OWND );
HB_FUNC_EXTERN( ENABLEACCESO );
HB_FUNC_EXTERN( SPACE );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( LOWER );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( TCOMBOBOX );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( SQLXBROWSE );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_SQLBASEVIEW )
{ "SQLBASEVIEW", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( SQLBASEVIEW )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLBASEVIEW_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLBASEVIEW_NEW )}, NULL },
{ "SQLBASEVIEW_BUILDSQLSHELL", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLBASEVIEW_BUILDSQLSHELL )}, NULL },
{ "SQLBASEVIEW_BUILDSQLBROWSE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLBASEVIEW_BUILDSQLBROWSE )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLBASEVIEW_BUILDSQLNUCLEARBROWSE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLBASEVIEW_BUILDSQLNUCLEARBROWSE )}, NULL },
{ "HHASKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HHASKEY )}, NULL },
{ "HTEXTMODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETMODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCONTROLLER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGET )}, NULL },
{ "GENERALBUTTONS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENDBUTTON", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLBASEVIEW_GENERALBUTTONS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLBASEVIEW_GENERALBUTTONS )}, NULL },
{ "ADDVIRTUAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLBASEVIEW_ENDBUTTON", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLBASEVIEW_ENDBUTTON )}, NULL },
{ "_CBROWSESTATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CBROWSESTATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLBASEVIEW_CHANGEFIND", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLBASEVIEW_CHANGEFIND )}, NULL },
{ "SQLBASEVIEW_CHANGECOMBO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SQLBASEVIEW_CHANGECOMBO )}, NULL },
{ "SAVEHISTORY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OMODEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWAT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSHELL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEARCHSETFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDSEABAR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "APPEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INSERTAFTERAPPENDBUTTON", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DUPLICATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EDIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ZOOM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DELETE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FINDGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETCOLOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REFRESHCURRENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "GETCOLUMNHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VARGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLICKONHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DISABLEACCESO", {HB_FS_PUBLIC}, {HB_FUNCNAME( DISABLEACCESO )}, NULL },
{ "_OSHELL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLTSHELL", {HB_FS_PUBLIC}, {HB_FUNCNAME( SQLTSHELL )}, NULL },
{ "CTITLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OWND", {HB_FS_PUBLIC}, {HB_FUNCNAME( OWND )}, NULL },
{ "GETMODEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEVEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CIMAGENAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETOBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GENERATECOLUMNSFORBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETCOMBOBOX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATEXFROMCODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETDCLICKDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOBUTTONS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRESIZED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BKEYDOWN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLBUTTONUP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SAVEHISTORYOFSHELL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DESTROYSQLMODEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETCOMBOBOXCHANGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHANGECOMBO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENABLEACCESO", {HB_FS_PUBLIC}, {HB_FUNCNAME( ENABLEACCESO )}, NULL },
{ "SPACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SPACE )}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "LOWER", {HB_FS_PUBLIC}, {HB_FUNCNAME( LOWER )}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "_BCHANGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CHANGEFIND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMBOBOX", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCOMBOBOX )}, NULL },
{ "BUILDSQLNUCLEARBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BLDBLCLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "ADDFASTKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SAVEHISTORYOFBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NRESULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SQLXBROWSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SQLXBROWSE )}, NULL },
{ "_BCLRSEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BCLRSELFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LHSCROLL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NMARQUEESTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETMODEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDCOLUMNSFORBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BRCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RBUTTONDOWN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATEFROMRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STARTBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_SQLBASEVIEW, ".\\.\\Prg\\SQLBaseView.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_SQLBASEVIEW
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_SQLBASEVIEW )
   #include "hbiniseg.h"
#endif

HB_FUNC( SQLBASEVIEW )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,112,0,36,7,0,103,2,0,100,8,
		29,11,5,176,1,0,104,2,0,12,1,29,0,5,
		166,194,4,0,122,80,1,48,2,0,176,3,0,12,
		0,106,12,83,81,76,66,97,115,101,86,105,101,119,
		0,108,4,4,1,0,108,0,112,3,80,2,36,9,
		0,48,5,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,7,111,83,104,101,108,108,0,4,1,0,
		9,112,5,73,36,11,0,48,5,0,95,2,100,100,
		95,1,121,72,121,72,121,72,106,12,111,67,111,110,
		116,114,111,108,108,101,114,0,4,1,0,9,112,5,
		73,36,13,0,48,5,0,95,2,100,100,95,1,121,
		72,121,72,121,72,106,8,111,66,114,111,119,115,101,
		0,4,1,0,9,112,5,73,36,18,0,48,5,0,
		95,2,100,122,106,11,65,241,97,100,105,101,110,100,
		111,32,0,92,2,106,13,77,111,100,105,102,105,99,
		97,110,100,111,32,0,92,3,106,14,86,105,115,117,
		97,108,105,122,97,110,100,111,32,0,92,4,106,12,
		68,117,112,108,105,99,97,110,100,111,32,0,177,4,
		0,95,1,121,72,121,72,121,72,106,10,104,84,101,
		120,116,77,111,100,101,0,4,1,0,9,112,5,73,
		36,20,0,48,5,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,13,99,66,114,111,119,115,101,83,
		116,97,116,101,0,4,1,0,9,112,5,73,36,22,
		0,48,5,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,11,99,73,109,97,103,101,78,97,109,101,
		0,4,1,0,9,112,5,73,36,24,0,48,6,0,
		95,2,106,4,78,101,119,0,108,7,95,1,121,72,
		121,72,121,72,112,3,73,36,26,0,48,6,0,95,
		2,106,14,98,117,105,108,100,83,81,76,83,104,101,
		108,108,0,108,8,95,1,121,72,121,72,121,72,112,
		3,73,36,28,0,48,6,0,95,2,106,15,98,117,
		105,108,100,83,81,76,66,114,111,119,115,101,0,108,
		9,95,1,121,72,121,72,121,72,112,3,73,36,30,
		0,48,10,0,95,2,106,11,115,101,116,111,66,114,
		111,119,115,101,0,89,17,0,2,0,0,0,48,11,
		0,95,1,95,2,112,1,6,95,1,121,72,121,72,
		121,72,112,3,73,36,31,0,48,10,0,95,2,106,
		11,103,101,116,111,66,114,111,119,115,101,0,89,15,
		0,1,0,0,0,48,12,0,95,1,112,0,6,95,
		1,121,72,121,72,121,72,112,3,73,36,33,0,48,
		6,0,95,2,106,22,98,117,105,108,100,83,81,76,
		78,117,99,108,101,97,114,66,114,111,119,115,101,0,
		108,13,95,1,121,72,121,72,121,72,112,3,73,36,
		35,0,48,10,0,95,2,106,9,108,98,108,84,105,
		116,108,101,0,89,63,0,1,0,0,0,176,14,0,
		48,15,0,95,1,112,0,48,16,0,48,17,0,95,
		1,112,0,112,0,12,2,28,28,176,18,0,48,15,
		0,95,1,112,0,48,16,0,48,17,0,95,1,112,
		0,112,0,12,2,25,5,106,1,0,6,95,1,121,
		72,121,72,121,72,112,3,73,36,37,0,48,10,0,
		95,2,106,12,65,117,116,111,66,117,116,116,111,110,
		115,0,89,23,0,1,0,0,0,48,19,0,95,1,
		112,0,73,48,20,0,95,1,112,0,6,95,1,121,
		72,121,72,121,72,112,3,73,36,38,0,48,6,0,
		95,2,106,15,71,101,110,101,114,97,108,66,117,116,
		116,111,110,115,0,108,21,95,1,121,72,121,72,121,
		72,112,3,73,36,39,0,48,22,0,95,2,106,24,
		105,110,115,101,114,116,65,102,116,101,114,65,112,112,
		101,110,100,66,117,116,116,111,110,0,112,1,73,36,
		40,0,48,6,0,95,2,106,10,69,110,100,66,117,
		116,116,111,110,0,108,23,95,1,121,72,121,72,121,
		72,112,3,73,36,42,0,48,10,0,95,2,106,15,
		115,101,116,66,114,111,119,115,101,83,116,97,116,101,
		0,89,17,0,2,0,0,0,48,24,0,95,1,95,
		2,112,1,6,95,1,121,72,121,72,121,72,112,3,
		73,36,43,0,48,10,0,95,2,106,15,103,101,116,
		66,114,111,119,115,101,83,116,97,116,101,0,89,15,
		0,1,0,0,0,48,25,0,95,1,112,0,6,95,
		1,121,72,121,72,121,72,112,3,73,36,45,0,48,
		6,0,95,2,106,11,99,104,97,110,103,101,70,105,
		110,100,0,108,26,95,1,121,72,121,72,121,72,112,
		3,73,36,46,0,48,6,0,95,2,106,12,99,104,
		97,110,103,101,67,111,109,98,111,0,108,27,95,1,
		121,72,121,72,121,72,112,3,73,36,48,0,48,10,
		0,95,2,106,19,115,97,118,101,72,105,115,116,111,
		114,121,79,102,83,104,101,108,108,0,89,36,0,1,
		0,0,0,48,28,0,48,17,0,95,1,112,0,106,
		7,95,115,104,101,108,108,0,48,12,0,95,1,112,
		0,112,2,6,95,1,121,72,121,72,121,72,112,3,
		73,36,50,0,48,10,0,95,2,106,20,115,97,118,
		101,72,105,115,116,111,114,121,79,102,66,114,111,119,
		115,101,0,89,37,0,1,0,0,0,48,28,0,48,
		17,0,95,1,112,0,106,8,95,98,114,111,119,115,
		101,0,48,12,0,95,1,112,0,112,2,6,95,1,
		121,72,121,72,121,72,112,3,73,36,52,0,48,10,
		0,95,2,106,9,103,101,116,77,111,100,101,108,0,
		89,20,0,1,0,0,0,48,29,0,48,17,0,95,
		1,112,0,112,0,6,95,1,121,72,121,72,121,72,
		112,3,73,36,54,0,48,30,0,95,2,112,0,73,
		167,14,0,0,176,31,0,104,2,0,95,2,20,2,
		168,48,32,0,95,2,112,0,80,3,176,33,0,95,
		3,106,10,73,110,105,116,67,108,97,115,115,0,12,
		2,28,12,48,34,0,95,3,164,146,1,0,73,95,
		3,110,7,48,32,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLBASEVIEW_NEW )
{
	static const HB_BYTE pcode[] =
	{
		36,60,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLBASEVIEW_GENERALBUTTONS )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,64,0,102,80,1,36,70,0,48,35,
		0,48,36,0,95,1,112,0,106,4,66,85,83,0,
		100,100,89,22,0,0,0,1,0,1,0,48,37,0,
		48,36,0,95,255,112,0,112,0,6,106,9,40,66,
		41,117,115,99,97,114,0,106,2,66,0,100,100,100,
		100,9,112,11,73,36,72,0,48,38,0,48,36,0,
		95,1,112,0,112,0,73,36,80,0,48,35,0,48,
		36,0,95,1,112,0,106,4,78,69,87,0,100,100,
		89,22,0,0,0,1,0,1,0,48,39,0,48,17,
		0,95,255,112,0,112,0,6,106,9,40,65,41,241,
		97,100,105,114,0,106,2,65,0,100,100,92,2,100,
		9,112,11,73,36,82,0,48,40,0,95,1,112,0,
		73,36,90,0,48,35,0,48,36,0,95,1,112,0,
		106,4,68,85,80,0,100,100,89,22,0,0,0,1,
		0,1,0,48,41,0,48,17,0,95,255,112,0,112,
		0,6,106,11,40,68,41,117,112,108,105,99,97,114,
		0,106,2,68,0,100,100,92,2,100,9,112,11,73,
		36,97,0,48,35,0,48,36,0,95,1,112,0,106,
		5,69,68,73,84,0,100,100,89,22,0,0,0,1,
		0,1,0,48,42,0,48,17,0,95,255,112,0,112,
		0,6,106,12,40,77,41,111,100,105,102,105,99,97,
		114,0,106,2,77,0,100,100,92,4,100,9,112,11,
		73,36,105,0,48,35,0,48,36,0,95,1,112,0,
		106,5,90,79,79,77,0,100,100,89,22,0,0,0,
		1,0,1,0,48,43,0,48,17,0,95,255,112,0,
		112,0,6,106,7,40,90,41,111,111,109,0,106,2,
		90,0,100,100,92,8,100,9,112,11,73,36,113,0,
		48,35,0,48,36,0,95,1,112,0,106,4,68,69,
		76,0,100,100,89,22,0,0,0,1,0,1,0,48,
		44,0,48,17,0,95,255,112,0,112,0,6,106,11,
		40,69,41,108,105,109,105,110,97,114,0,106,2,69,
		0,100,100,92,16,100,9,112,11,73,36,115,0,95,
		1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLBASEVIEW_ENDBUTTON )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,119,0,102,80,1,36,125,0,48,35,
		0,48,36,0,95,1,112,0,106,4,69,78,68,0,
		100,100,89,22,0,0,0,1,0,1,0,48,45,0,
		48,36,0,95,255,112,0,112,0,6,106,8,40,83,
		41,97,108,105,114,0,106,2,83,0,100,100,100,100,
		9,112,11,73,36,127,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLBASEVIEW_CHANGEFIND )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,133,0,48,46,0,48,17,0,102,112,
		0,95,1,112,1,80,2,36,135,0,95,2,28,21,
		36,136,0,48,47,0,95,1,121,97,255,255,255,0,
		112,2,73,25,23,36,138,0,48,47,0,95,1,97,
		255,255,255,0,97,255,102,102,0,112,2,73,36,141,
		0,48,48,0,48,12,0,102,112,0,112,0,73,36,
		143,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLBASEVIEW_CHANGECOMBO )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,151,0,176,49,0,48,12,0,102,112,
		0,12,1,28,8,36,152,0,102,110,7,36,155,0,
		176,49,0,95,1,12,1,28,8,36,156,0,102,110,
		7,36,159,0,48,50,0,48,12,0,102,112,0,48,
		51,0,95,1,112,0,112,1,80,2,36,161,0,176,
		49,0,95,2,12,1,31,21,36,162,0,48,52,0,
		48,17,0,102,112,0,95,2,95,1,112,2,73,36,
		165,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLBASEVIEW_BUILDSQLSHELL )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,169,0,102,80,1,36,171,0,176,53,
		0,20,0,36,173,0,48,54,0,95,1,48,2,0,
		176,55,0,12,0,92,2,92,10,92,18,92,70,48,
		56,0,48,17,0,95,1,112,0,112,0,100,176,57,
		0,12,0,100,100,9,100,100,48,58,0,95,1,112,
		0,100,100,100,100,4,0,0,89,22,0,0,0,1,
		0,1,0,48,42,0,48,17,0,95,255,112,0,112,
		0,6,100,89,22,0,0,0,1,0,1,0,48,44,
		0,48,17,0,95,255,112,0,112,0,6,100,100,48,
		59,0,48,17,0,95,1,112,0,112,0,48,60,0,
		95,1,112,0,97,104,0,63,0,100,100,120,112,29,
		112,1,73,36,175,0,48,61,0,95,1,48,62,0,
		48,36,0,95,1,112,0,112,0,112,1,73,36,177,
		0,48,63,0,48,17,0,95,1,112,0,48,64,0,
		48,36,0,95,1,112,0,112,0,112,1,73,36,179,
		0,48,65,0,48,36,0,95,1,112,0,112,0,73,
		36,181,0,48,66,0,48,36,0,95,1,112,0,89,
		22,0,0,0,1,0,1,0,48,42,0,48,17,0,
		95,255,112,0,112,0,6,112,1,73,36,183,0,48,
		67,0,95,1,112,0,73,36,185,0,48,68,0,48,
		36,0,95,1,112,0,100,48,69,0,48,36,0,95,
		1,112,0,112,0,48,70,0,48,36,0,95,1,112,
		0,112,0,48,71,0,48,36,0,95,1,112,0,112,
		0,48,72,0,48,36,0,95,1,112,0,112,0,48,
		73,0,48,36,0,95,1,112,0,112,0,48,74,0,
		48,36,0,95,1,112,0,112,0,48,75,0,48,36,
		0,95,1,112,0,112,0,100,100,100,100,100,100,100,
		100,100,100,48,76,0,48,36,0,95,1,112,0,112,
		0,9,112,20,73,36,187,0,48,77,0,48,36,0,
		95,1,112,0,89,19,0,0,0,1,0,1,0,48,
		78,0,95,255,112,0,73,120,6,112,1,73,36,188,
		0,48,79,0,48,36,0,95,1,112,0,89,22,0,
		0,0,1,0,1,0,48,80,0,48,17,0,95,255,
		112,0,112,0,6,112,1,73,36,190,0,48,81,0,
		48,36,0,95,1,112,0,89,29,0,0,0,1,0,
		1,0,48,82,0,95,255,48,64,0,48,36,0,95,
		255,112,0,112,0,112,1,6,112,1,73,36,192,0,
		176,83,0,20,0,36,194,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLBASEVIEW_BUILDSQLBROWSE )
{
	static const HB_BYTE pcode[] =
	{
		13,7,1,36,198,0,102,80,2,36,202,0,176,84,
		0,93,200,0,12,1,80,5,36,205,0,95,1,4,
		1,0,80,8,36,207,0,48,2,0,176,85,0,12,
		0,100,100,100,100,106,13,83,101,108,101,99,99,105,
		111,110,97,114,32,0,176,86,0,95,1,12,1,72,
		106,16,72,69,76,80,95,66,82,79,87,83,69,95,
		83,81,76,0,100,9,100,100,100,100,100,9,100,100,
		100,100,100,9,100,106,5,111,68,108,103,0,100,100,
		112,24,80,3,36,213,0,48,87,0,176,88,0,12,
		0,92,104,89,28,0,1,0,1,0,5,0,176,89,
		0,12,0,121,8,28,6,95,255,25,7,95,1,165,
		80,255,6,95,3,100,100,100,100,100,100,100,100,9,
		100,100,9,9,100,100,100,100,100,100,106,5,70,73,
		78,68,0,100,100,112,25,80,4,36,215,0,48,90,
		0,95,4,89,21,0,0,0,2,0,2,0,4,0,
		48,91,0,95,255,95,254,112,1,6,112,1,73,36,
		221,0,48,87,0,176,92,0,12,0,92,102,89,28,
		0,1,0,1,0,7,0,176,89,0,12,0,121,8,
		28,6,95,255,25,7,95,1,165,80,255,6,95,8,
		95,3,100,100,100,100,100,100,9,100,100,100,100,100,
		100,112,17,80,6,36,223,0,48,90,0,95,6,89,
		21,0,0,0,2,0,2,0,6,0,48,82,0,95,
		255,95,254,112,1,6,112,1,73,36,225,0,48,93,
		0,95,2,92,105,95,3,95,6,112,3,73,36,227,
		0,48,94,0,48,12,0,95,2,112,0,89,18,0,
		0,0,1,0,3,0,48,45,0,95,255,122,112,1,
		6,112,1,73,36,232,0,48,87,0,176,95,0,12,
		0,122,89,18,0,0,0,1,0,3,0,48,45,0,
		95,255,122,112,1,6,95,3,100,100,9,100,100,100,
		9,112,10,73,36,238,0,48,87,0,176,95,0,12,
		0,92,2,89,17,0,0,0,1,0,3,0,48,45,
		0,95,255,112,0,6,95,3,100,100,9,100,100,100,
		120,112,10,73,36,243,0,48,87,0,176,95,0,12,
		0,93,244,1,89,22,0,0,0,1,0,2,0,48,
		39,0,48,17,0,95,255,112,0,112,0,6,95,3,
		100,100,9,100,100,100,9,112,10,73,36,248,0,48,
		87,0,176,95,0,12,0,93,245,1,89,22,0,0,
		0,1,0,2,0,48,42,0,48,17,0,95,255,112,
		0,112,0,6,95,3,100,100,9,100,100,100,9,112,
		10,73,36,250,0,48,96,0,95,3,92,13,89,18,
		0,0,0,1,0,3,0,48,45,0,95,255,122,112,
		1,6,112,2,73,36,251,0,48,96,0,95,3,92,
		116,89,18,0,0,0,1,0,3,0,48,45,0,95,
		255,122,112,1,6,112,2,73,36,252,0,48,96,0,
		95,3,92,113,89,22,0,0,0,1,0,2,0,48,
		39,0,48,17,0,95,255,112,0,112,0,6,112,2,
		73,36,253,0,48,96,0,95,3,92,114,89,22,0,
		0,0,1,0,2,0,48,42,0,48,17,0,95,255,
		112,0,112,0,6,112,2,73,36,255,0,48,68,0,
		95,3,100,100,100,120,89,17,0,0,0,1,0,2,
		0,48,97,0,95,255,112,0,6,112,5,73,36,1,
		1,48,98,0,95,3,112,0,122,8,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SQLBASEVIEW_BUILDSQLNUCLEARBROWSE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,3,36,5,1,102,80,4,36,7,1,48,61,
		0,95,4,48,2,0,176,99,0,12,0,95,2,112,
		1,112,1,73,36,9,1,48,100,0,48,12,0,95,
		4,112,0,90,12,121,97,229,229,229,0,4,2,0,
		6,112,1,73,36,10,1,48,101,0,48,12,0,95,
		4,112,0,90,12,121,97,167,205,240,0,4,2,0,
		6,112,1,73,36,12,1,48,102,0,48,12,0,95,
		4,112,0,9,112,1,73,36,13,1,48,103,0,48,
		12,0,95,4,112,0,92,6,112,1,73,36,15,1,
		48,104,0,48,12,0,95,4,112,0,48,58,0,95,
		4,112,0,112,1,73,36,17,1,48,63,0,48,17,
		0,95,4,112,0,95,3,112,1,73,36,19,1,48,
		105,0,48,17,0,95,4,112,0,95,3,112,1,73,
		36,21,1,48,94,0,48,12,0,95,4,112,0,89,
		22,0,0,0,1,0,4,0,48,42,0,48,17,0,
		95,255,112,0,112,0,6,112,1,73,36,22,1,48,
		106,0,48,12,0,95,4,112,0,89,28,0,3,0,
		1,0,4,0,48,107,0,48,12,0,95,255,112,0,
		95,1,95,2,95,3,112,3,6,112,1,73,36,24,
		1,48,108,0,48,12,0,95,4,112,0,95,1,112,
		1,73,36,26,1,48,109,0,48,17,0,95,4,112,
		0,95,3,112,1,73,36,28,1,95,4,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,112,0,2,0,116,112,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

