/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\Maquina.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( STARTTMAQUINA );
HB_FUNC( TMAQUINA );
HB_FUNC_EXTERN( CPATEMP );
HB_FUNC_EXTERN( OWND );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TMASDET );
HB_FUNC_STATIC( TMAQUINA_NEW );
HB_FUNC_STATIC( TMAQUINA_CREATEINIT );
HB_FUNC_STATIC( TMAQUINA_CREATE );
HB_FUNC_STATIC( TMAQUINA_OPENFILES );
HB_FUNC_STATIC( TMAQUINA_OPENSERVICE );
HB_FUNC_STATIC( TMAQUINA_CLOSEFILES );
HB_FUNC_STATIC( TMAQUINA_DEFINEFILES );
HB_FUNC_STATIC( TMAQUINA_RESOURCE );
HB_FUNC_STATIC( TMAQUINA_NTOTALVIRTUAL );
HB_FUNC_STATIC( TMAQUINA_CTOTALVIRTUAL );
HB_FUNC_STATIC( TMAQUINA_LTOTALVIRTUAL );
HB_FUNC_STATIC( TMAQUINA_NTOTALCOSTEDIA );
HB_FUNC_STATIC( TMAQUINA_CTOTALCOSTEDIA );
HB_FUNC_STATIC( TMAQUINA_LTOTALCOSTEDIA );
HB_FUNC_STATIC( TMAQUINA_NTOTALCOSTEHORA );
HB_FUNC_STATIC( TMAQUINA_CTOTALCOSTEHORA );
HB_FUNC_STATIC( TMAQUINA_LTOTALCOSTEHORA );
HB_FUNC_STATIC( TMAQUINA_LPRESAVE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( GETWNDFRAME );
HB_FUNC_EXTERN( NLEVELUSR );
HB_FUNC_EXTERN( NAND );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( TCOSMAQ );
HB_FUNC_EXTERN( TDETCOSTES );
HB_FUNC_EXTERN( TSECCION );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_EXTERN( APOLOBREAK );
HB_FUNC_EXTERN( DBFSERVER );
HB_FUNC_EXTERN( CDRIVER );
HB_FUNC_EXTERN( CPATDAT );
HB_FUNC_EXTERN( ERRORMESSAGE );
HB_FUNC_EXTERN( CDIVEMP );
HB_FUNC_EXTERN( NCHGDIV );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( LBLTITLE );
HB_FUNC_EXTERN( TBITMAP );
HB_FUNC_EXTERN( TGETHLP );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( NOTVALID );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( IXBROWSE );
HB_FUNC_EXTERN( RETFLD );
HB_FUNC_EXTERN( TRANSFORM );
HB_FUNC_EXTERN( ORETFLD );
HB_FUNC_EXTERN( MSGINFO );
HB_FUNC_EXTERN( CPORDIV );
HB_FUNC_EXTERN( NCNV2DIV );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_MAQUINA )
{ "STARTTMAQUINA", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( STARTTMAQUINA )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TMAQUINA", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA )}, NULL },
{ "CPATEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATEMP )}, NULL },
{ "OWND", {HB_FS_PUBLIC}, {HB_FUNCNAME( OWND )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TMASDET", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMASDET )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TMAQUINA_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_NEW )}, NULL },
{ "TMAQUINA_CREATEINIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_CREATEINIT )}, NULL },
{ "TMAQUINA_CREATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_CREATE )}, NULL },
{ "TMAQUINA_OPENFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_OPENFILES )}, NULL },
{ "TMAQUINA_OPENSERVICE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_OPENSERVICE )}, NULL },
{ "TMAQUINA_CLOSEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_CLOSEFILES )}, NULL },
{ "TMAQUINA_DEFINEFILES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_DEFINEFILES )}, NULL },
{ "TMAQUINA_RESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_RESOURCE )}, NULL },
{ "TMAQUINA_NTOTALVIRTUAL", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_NTOTALVIRTUAL )}, NULL },
{ "TMAQUINA_CTOTALVIRTUAL", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_CTOTALVIRTUAL )}, NULL },
{ "TMAQUINA_LTOTALVIRTUAL", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_LTOTALVIRTUAL )}, NULL },
{ "TMAQUINA_NTOTALCOSTEDIA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_NTOTALCOSTEDIA )}, NULL },
{ "TMAQUINA_CTOTALCOSTEDIA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_CTOTALCOSTEDIA )}, NULL },
{ "TMAQUINA_LTOTALCOSTEDIA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_LTOTALCOSTEDIA )}, NULL },
{ "TMAQUINA_NTOTALCOSTEHORA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_NTOTALCOSTEHORA )}, NULL },
{ "TMAQUINA_CTOTALCOSTEHORA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_CTOTALCOSTEHORA )}, NULL },
{ "TMAQUINA_LTOTALCOSTEHORA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_LTOTALCOSTEHORA )}, NULL },
{ "TMAQUINA_LPRESAVE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TMAQUINA_LPRESAVE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETWNDFRAME", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETWNDFRAME )}, NULL },
{ "NLEVEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NLEVEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEVELUSR", {HB_FS_PUBLIC}, {HB_FUNCNAME( NLEVELUSR )}, NULL },
{ "NAND", {HB_FS_PUBLIC}, {HB_FUNCNAME( NAND )}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "_CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OWNDPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BFIRSTKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODMAQ", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OCOSTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOSMAQ", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCOSMAQ )}, NULL },
{ "_ODETCOSTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDETCOSTES", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDETCOSTES )}, NULL },
{ "ADDDETAIL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODETCOSTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OSECCION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TSECCION", {HB_FS_PUBLIC}, {HB_FUNCNAME( TSECCION )}, NULL },
{ "_ODBF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "APOLOBREAK", {HB_FS_PUBLIC}, {HB_FUNCNAME( APOLOBREAK )}, NULL },
{ "DEFINEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODBFDIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NEWOPEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBFSERVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBFSERVER )}, NULL },
{ "CDRIVER", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDRIVER )}, NULL },
{ "CPATDAT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPATDAT )}, NULL },
{ "ADDBAG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFDIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AUTOINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPENFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCOSTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSECCION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPENDETAILS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ERRORMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORMESSAGE )}, NULL },
{ "CLOSEFILES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "USED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CLOSEDETAILS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPATH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTOTALCOSTEDIA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTOTALCOSTEHORA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDINDEX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODDIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDIVEMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CDIVEMP )}, NULL },
{ "_NVDVDIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCHGDIV", {HB_FS_PUBLIC}, {HB_FUNCNAME( NCHGDIV )}, NULL },
{ "LLOADDIVISA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODDIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "LBLTITLE", {HB_FS_PUBLIC}, {HB_FUNCNAME( LBLTITLE )}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBITMAP )}, NULL },
{ "TGETHLP", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGETHLP )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "_CCODMAQ", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NOTVALID", {HB_FS_PUBLIC}, {HB_FUNCNAME( NOTVALID )}, NULL },
{ "CALIAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDESMAQ", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CDESMAQ", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHORDIA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHORDIA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BCHANGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LTOTALVIRTUAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODSEC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CCODSEC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BHELP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BUSCAR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BVALID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EXISTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OHELPTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "APPEND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EDIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ZOOM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "IXBROWSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( IXBROWSE )}, NULL },
{ "_BCLRSEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BCLRSELFOCUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ODBFVIR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NMARQUEESTYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BLDBLCLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATEFROMRESOURCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDCOL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BSTRDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODCOS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RETFLD", {HB_FS_PUBLIC}, {HB_FUNCNAME( RETFLD )}, NULL },
{ "TRANSFORM", {HB_FS_PUBLIC}, {HB_FUNCNAME( TRANSFORM )}, NULL },
{ "ORETFLD", {HB_FS_PUBLIC}, {HB_FUNCNAME( ORETFLD )}, NULL },
{ "CPORDIV", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NDATASTRALIGN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHEADSTRALIGN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NPCTCOS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTOTALLINEA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OGETTOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NGETTOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NGETTOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OGETHOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NGETHOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NGETHOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
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
{ "GETSTATUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOTALLINEA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETSTATUS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOTALVIRTUAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OGETTOT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OGETHOR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOTALCOSTEDIA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPORDIV", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPORDIV )}, NULL },
{ "NCNV2DIV", {HB_FS_PUBLIC}, {HB_FUNCNAME( NCNV2DIV )}, NULL },
{ "SETTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOTALCOSTEHORA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SEEKINORD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_MAQUINA, ".\\.\\Prg\\Maquina.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_MAQUINA
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_MAQUINA )
   #include "hbiniseg.h"
#endif

HB_FUNC( STARTTMAQUINA )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,10,0,48,1,0,176,2,0,12,0,
		176,3,0,12,0,176,4,0,12,0,106,6,48,52,
		48,48,54,0,112,3,80,1,36,12,0,176,5,0,
		95,1,12,1,31,13,36,13,0,48,6,0,95,1,
		112,0,73,36,16,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( TMAQUINA )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,170,0,36,20,0,103,2,0,100,8,
		29,111,4,176,7,0,104,2,0,12,1,29,100,4,
		166,38,4,0,122,80,1,48,1,0,176,8,0,12,
		0,106,9,84,77,97,113,117,105,110,97,0,108,9,
		4,1,0,108,2,112,3,80,2,36,22,0,48,10,
		0,95,2,100,106,23,103,99,95,105,110,100,117,115,
		116,114,105,97,108,95,114,111,98,111,116,95,49,54,
		0,95,1,121,72,121,72,121,72,106,5,99,77,114,
		117,0,4,1,0,9,112,5,73,36,23,0,48,10,
		0,95,2,100,97,250,161,52,0,95,1,121,72,121,
		72,121,72,106,8,99,66,105,116,109,97,112,0,4,
		1,0,9,112,5,73,36,25,0,48,10,0,95,2,
		100,100,95,1,121,72,121,72,121,72,106,9,111,77,
		97,113,117,105,110,97,0,4,1,0,9,112,5,73,
		36,27,0,48,10,0,95,2,100,100,95,1,121,72,
		121,72,121,72,106,8,111,67,111,115,116,101,115,0,
		4,1,0,9,112,5,73,36,28,0,48,10,0,95,
		2,100,100,95,1,121,72,121,72,121,72,106,11,111,
		68,101,116,67,111,115,116,101,115,0,4,1,0,9,
		112,5,73,36,29,0,48,10,0,95,2,100,100,95,
		1,121,72,121,72,121,72,106,9,111,83,101,99,99,
		105,111,110,0,4,1,0,9,112,5,73,36,31,0,
		48,10,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,8,111,71,101,116,84,111,116,0,4,1,0,
		9,112,5,73,36,32,0,48,10,0,95,2,100,121,
		95,1,121,72,121,72,121,72,106,8,110,71,101,116,
		84,111,116,0,4,1,0,9,112,5,73,36,33,0,
		48,10,0,95,2,100,100,95,1,121,72,121,72,121,
		72,106,8,111,71,101,116,72,111,114,0,4,1,0,
		9,112,5,73,36,34,0,48,10,0,95,2,100,121,
		95,1,121,72,121,72,121,72,106,8,110,71,101,116,
		72,111,114,0,4,1,0,9,112,5,73,36,36,0,
		48,11,0,95,2,106,4,78,101,119,0,108,12,95,
		1,121,72,121,72,121,72,112,3,73,36,37,0,48,
		11,0,95,2,106,11,67,114,101,97,116,101,73,110,
		105,116,0,108,13,95,1,121,72,121,72,121,72,112,
		3,73,36,38,0,48,11,0,95,2,106,7,67,114,
		101,97,116,101,0,108,14,95,1,121,72,121,72,121,
		72,112,3,73,36,40,0,48,11,0,95,2,106,10,
		79,112,101,110,70,105,108,101,115,0,108,15,95,1,
		121,72,121,72,121,72,112,3,73,36,41,0,48,11,
		0,95,2,106,12,79,112,101,110,83,101,114,118,105,
		99,101,0,108,16,95,1,121,72,121,72,121,72,112,
		3,73,36,43,0,48,11,0,95,2,106,11,67,108,
		111,115,101,70,105,108,101,115,0,108,17,95,1,121,
		72,121,72,121,72,112,3,73,36,45,0,48,11,0,
		95,2,106,12,68,101,102,105,110,101,70,105,108,101,
		115,0,108,18,95,1,121,72,121,72,121,72,112,3,
		73,36,47,0,48,11,0,95,2,106,9,82,101,115,
		111,117,114,99,101,0,108,19,95,1,121,72,121,72,
		121,72,112,3,73,36,49,0,48,11,0,95,2,106,
		14,110,84,111,116,97,108,86,105,114,116,117,97,108,
		0,108,20,95,1,121,72,121,72,121,72,112,3,73,
		36,50,0,48,11,0,95,2,106,14,99,84,111,116,
		97,108,86,105,114,116,117,97,108,0,108,21,95,1,
		121,72,121,72,121,72,112,3,73,36,51,0,48,11,
		0,95,2,106,14,108,84,111,116,97,108,86,105,114,
		116,117,97,108,0,108,22,95,1,121,72,121,72,121,
		72,112,3,73,36,53,0,48,11,0,95,2,106,15,
		110,84,111,116,97,108,67,111,115,116,101,68,105,97,
		0,108,23,95,1,121,72,121,72,121,72,112,3,73,
		36,54,0,48,11,0,95,2,106,15,99,84,111,116,
		97,108,67,111,115,116,101,68,105,97,0,108,24,95,
		1,121,72,121,72,121,72,112,3,73,36,55,0,48,
		11,0,95,2,106,15,108,84,111,116,97,108,67,111,
		115,116,101,68,105,97,0,108,25,95,1,121,72,121,
		72,121,72,112,3,73,36,57,0,48,11,0,95,2,
		106,16,110,84,111,116,97,108,67,111,115,116,101,72,
		111,114,97,0,108,26,95,1,121,72,121,72,121,72,
		112,3,73,36,58,0,48,11,0,95,2,106,16,99,
		84,111,116,97,108,67,111,115,116,101,72,111,114,97,
		0,108,27,95,1,121,72,121,72,121,72,112,3,73,
		36,59,0,48,11,0,95,2,106,16,108,84,111,116,
		97,108,67,111,115,116,101,72,111,114,97,0,108,28,
		95,1,121,72,121,72,121,72,112,3,73,36,61,0,
		48,11,0,95,2,106,9,108,80,114,101,83,97,118,
		101,0,108,29,95,1,121,72,121,72,121,72,112,3,
		73,36,63,0,48,30,0,95,2,112,0,73,167,14,
		0,0,176,31,0,104,2,0,95,2,20,2,168,48,
		32,0,95,2,112,0,80,3,176,33,0,95,3,106,
		10,73,110,105,116,67,108,97,115,115,0,12,2,28,
		12,48,34,0,95,3,164,146,1,0,73,95,3,110,
		7,48,32,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,1,3,36,67,0,102,80,4,36,69,0,95,1,
		100,8,28,9,176,3,0,12,0,80,1,36,70,0,
		95,2,100,8,28,9,176,35,0,12,0,80,2,36,
		72,0,95,3,100,69,28,33,48,36,0,95,4,112,
		0,100,8,28,22,36,73,0,48,37,0,95,4,176,
		38,0,95,3,12,1,112,1,73,25,14,36,75,0,
		48,37,0,95,4,122,112,1,73,36,78,0,176,39,
		0,48,36,0,95,4,112,0,122,12,2,121,69,28,
		39,36,79,0,176,40,0,106,21,65,99,99,101,115,
		111,32,110,111,32,112,101,114,109,105,116,105,100,111,
		46,0,20,1,36,80,0,100,110,7,36,83,0,48,
		41,0,95,4,95,1,112,1,73,36,84,0,48,42,
		0,95,4,95,2,112,1,73,36,86,0,48,43,0,
		95,4,89,22,0,0,0,1,0,4,0,48,44,0,
		48,45,0,95,255,112,0,112,0,6,112,1,73,36,
		88,0,48,46,0,95,4,48,30,0,176,47,0,12,
		0,112,0,112,1,73,36,90,0,48,48,0,95,4,
		48,1,0,176,49,0,12,0,95,1,95,4,112,2,
		112,1,73,36,91,0,48,50,0,95,4,48,51,0,
		95,4,112,0,112,1,73,36,93,0,48,52,0,95,
		4,48,30,0,176,53,0,12,0,112,0,112,1,73,
		36,95,0,95,4,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_CREATEINIT )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,99,0,102,80,2,36,101,0,95,1,
		100,8,28,9,176,3,0,12,0,80,1,36,103,0,
		48,41,0,95,2,95,1,112,1,73,36,105,0,48,
		43,0,95,2,89,22,0,0,0,1,0,2,0,48,
		44,0,48,45,0,95,255,112,0,112,0,6,112,1,
		73,36,107,0,48,46,0,95,2,48,30,0,176,47,
		0,12,0,95,1,112,1,112,1,73,36,109,0,48,
		48,0,95,2,48,1,0,176,49,0,12,0,95,1,
		95,2,112,2,112,1,73,36,110,0,48,50,0,95,
		2,48,51,0,95,2,112,0,112,1,73,36,112,0,
		48,52,0,95,2,48,30,0,176,53,0,12,0,95,
		1,112,1,112,1,73,36,114,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_CREATE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,120,0,95,1,100,8,28,9,176,3,
		0,12,0,80,1,36,122,0,48,41,0,102,95,1,
		112,1,73,36,123,0,48,54,0,102,100,112,1,73,
		36,125,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_OPENFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,3,1,36,131,0,120,80,2,36,135,0,95,1,
		100,8,28,5,9,80,1,36,137,0,176,55,0,89,
		15,0,1,0,0,0,176,56,0,95,1,12,1,6,
		12,1,80,4,36,138,0,113,214,0,0,36,140,0,
		176,5,0,48,45,0,102,112,0,12,1,28,18,36,
		141,0,48,54,0,102,48,57,0,102,112,0,112,1,
		73,36,144,0,48,6,0,48,45,0,102,112,0,9,
		95,1,68,112,2,73,36,146,0,48,58,0,102,48,
		59,0,176,60,0,106,12,68,73,86,73,83,65,83,
		46,68,66,70,0,100,12,2,106,12,68,73,86,73,
		83,65,83,46,68,66,70,0,100,176,61,0,12,0,
		100,176,62,0,12,0,9,120,9,9,112,9,112,1,
		73,48,63,0,48,64,0,102,112,0,106,12,68,73,
		86,73,83,65,83,46,67,68,88,0,112,1,73,48,
		63,0,48,64,0,102,112,0,112,0,73,48,65,0,
		48,64,0,102,112,0,112,0,73,36,148,0,48,66,
		0,48,67,0,102,112,0,112,0,73,36,150,0,48,
		66,0,48,68,0,102,112,0,112,0,73,36,152,0,
		48,69,0,102,112,0,73,114,84,0,0,36,154,0,
		115,80,3,36,156,0,176,40,0,176,70,0,95,3,
		12,1,106,41,73,109,112,111,115,105,98,108,101,32,
		97,98,114,105,114,32,116,111,100,97,115,32,108,97,
		115,32,98,97,115,101,115,32,100,101,32,100,97,116,
		111,115,0,20,2,36,158,0,48,71,0,102,112,0,
		73,36,160,0,9,80,2,36,164,0,176,55,0,95,
		4,20,1,36,166,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_OPENSERVICE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,2,36,172,0,120,80,3,36,174,0,176,55,
		0,89,15,0,1,0,0,0,176,56,0,95,1,12,
		1,6,12,1,80,5,36,176,0,95,1,100,8,28,
		5,9,80,1,36,178,0,113,61,0,0,36,180,0,
		176,5,0,48,45,0,102,112,0,12,1,28,20,36,
		181,0,48,54,0,102,48,57,0,102,95,2,112,1,
		112,1,73,36,184,0,48,6,0,48,45,0,102,112,
		0,9,95,1,68,112,2,73,114,87,0,0,36,186,
		0,115,80,4,36,188,0,9,80,3,36,190,0,48,
		71,0,102,112,0,73,36,192,0,176,40,0,106,43,
		73,109,112,111,115,105,98,108,101,32,97,98,114,105,
		114,32,116,111,100,97,115,32,108,97,115,32,98,97,
		115,101,115,32,100,101,32,100,97,116,111,115,13,10,
		0,176,70,0,95,4,12,1,72,20,1,36,196,0,
		176,55,0,95,5,20,1,36,198,0,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_CLOSEFILES )
{
	static const HB_BYTE pcode[] =
	{
		36,204,0,48,45,0,102,112,0,100,69,28,41,48,
		72,0,48,45,0,102,112,0,112,0,28,28,36,205,
		0,48,73,0,48,45,0,102,112,0,112,0,73,36,
		206,0,48,54,0,102,100,112,1,73,36,209,0,48,
		67,0,102,112,0,100,69,28,17,36,210,0,48,73,
		0,48,67,0,102,112,0,112,0,73,36,213,0,48,
		68,0,102,112,0,100,69,28,17,36,214,0,48,73,
		0,48,68,0,102,112,0,112,0,73,36,217,0,48,
		46,0,102,100,112,1,73,36,218,0,48,52,0,102,
		100,112,1,73,36,220,0,48,74,0,102,112,0,73,
		36,222,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_DEFINEFILES )
{
	static const HB_BYTE pcode[] =
	{
		13,2,2,36,226,0,102,80,3,36,230,0,95,1,
		100,8,28,11,48,75,0,95,3,112,0,80,1,36,
		231,0,95,2,100,8,28,9,176,61,0,12,0,80,
		2,36,233,0,48,1,0,176,60,0,106,12,77,97,
		113,67,111,115,84,46,68,98,102,0,106,8,77,97,
		113,67,111,115,84,0,12,2,106,12,77,97,113,67,
		111,115,84,46,68,98,102,0,106,8,77,97,113,67,
		111,115,84,0,95,2,106,11,77,97,113,117,105,110,
		97,114,105,97,0,95,1,112,5,80,4,36,235,0,
		48,76,0,95,4,106,8,99,67,111,100,77,97,113,
		0,106,2,67,0,92,3,121,100,100,100,100,106,7,
		67,243,100,105,103,111,0,9,92,100,9,4,0,0,
		112,13,73,36,236,0,48,76,0,95,4,106,8,99,
		68,101,115,77,97,113,0,106,2,67,0,92,35,121,
		100,100,100,100,106,7,78,111,109,98,114,101,0,9,
		93,144,1,9,4,0,0,112,13,73,36,237,0,48,
		76,0,95,4,106,8,99,67,111,100,83,101,99,0,
		106,2,67,0,92,3,121,100,100,100,100,106,8,83,
		101,99,99,105,243,110,0,9,92,100,9,4,0,0,
		112,13,73,36,238,0,48,76,0,95,4,106,8,99,
		67,111,100,68,105,118,0,106,2,67,0,92,3,121,
		100,100,100,100,106,7,68,105,118,105,115,97,0,9,
		100,120,4,0,0,112,13,73,36,239,0,48,76,0,
		95,4,106,8,110,86,100,118,68,105,118,0,106,2,
		78,0,92,16,92,6,100,100,100,100,106,13,86,97,
		108,111,114,32,100,105,118,105,115,97,0,9,100,120,
		4,0,0,112,13,73,36,240,0,48,76,0,95,4,
		106,8,110,72,111,114,68,105,97,0,106,2,78,0,
		92,16,92,6,100,100,100,100,106,10,72,111,114,97,
		115,32,100,105,97,0,9,100,120,4,0,0,112,13,
		73,36,241,0,48,76,0,95,4,106,8,110,84,111,
		116,67,111,115,0,106,2,66,0,92,16,92,6,100,
		100,100,89,17,0,0,0,1,0,3,0,48,77,0,
		95,255,112,0,6,106,10,67,111,115,116,101,32,100,
		105,97,0,120,92,100,9,4,0,0,112,13,73,36,
		242,0,48,76,0,95,4,106,8,110,72,111,114,67,
		111,115,0,106,2,66,0,92,16,92,6,100,100,100,
		89,17,0,0,0,1,0,3,0,48,78,0,95,255,
		112,0,6,106,11,67,111,115,116,101,32,104,111,114,
		97,0,120,92,100,9,4,0,0,112,13,73,36,244,
		0,48,79,0,95,4,106,8,99,67,111,100,77,97,
		113,0,106,12,77,97,113,67,111,115,84,46,67,100,
		120,0,106,8,99,67,111,100,77,97,113,0,100,100,
		9,9,106,7,67,243,100,105,103,111,0,100,100,120,
		9,112,12,73,36,245,0,48,79,0,95,4,106,8,
		99,68,101,115,77,97,113,0,106,12,77,97,113,67,
		111,115,84,46,67,100,120,0,106,8,99,68,101,115,
		77,97,113,0,100,100,9,9,106,7,78,111,109,98,
		114,101,0,100,100,120,9,112,12,73,36,246,0,48,
		79,0,95,4,106,8,99,67,111,100,83,101,99,0,
		106,12,77,97,113,67,111,115,84,46,67,100,120,0,
		106,8,99,67,111,100,83,101,99,0,100,100,9,9,
		106,8,83,101,99,99,105,243,110,0,100,100,120,9,
		112,12,73,36,250,0,95,4,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_RESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,7,1,36,254,0,102,80,2,36,7,1,95,1,
		122,8,28,49,36,8,1,48,80,0,48,45,0,95,
		2,112,0,176,81,0,12,0,112,1,73,36,9,1,
		48,82,0,48,45,0,95,2,112,0,176,83,0,176,
		81,0,12,0,12,1,112,1,73,36,12,1,48,84,
		0,95,2,48,85,0,48,45,0,95,2,112,0,112,
		0,112,1,73,36,14,1,48,1,0,176,86,0,12,
		0,100,100,100,100,176,87,0,95,1,12,1,106,11,
		109,97,113,117,105,110,97,114,105,97,0,72,106,8,
		77,97,113,117,105,110,97,0,100,9,100,100,100,100,
		100,9,100,100,100,100,100,9,100,106,5,111,68,108,
		103,0,100,100,112,24,80,3,36,20,1,48,88,0,
		176,89,0,12,0,93,222,3,106,23,103,99,95,105,
		110,100,117,115,116,114,105,97,108,95,114,111,98,111,
		116,95,52,56,0,100,95,3,100,100,9,9,100,100,
		9,100,100,120,112,14,80,8,36,27,1,48,88,0,
		176,90,0,12,0,92,110,89,47,0,1,0,1,0,
		2,0,176,91,0,12,0,121,8,28,16,48,44,0,
		48,45,0,95,255,112,0,112,0,25,16,48,92,0,
		48,45,0,95,255,112,0,95,1,112,1,6,95,3,
		100,106,3,64,33,0,89,36,0,0,0,2,0,4,
		0,2,0,176,93,0,95,255,48,94,0,48,45,0,
		95,254,112,0,112,0,120,106,2,48,0,12,4,6,
		100,100,100,100,100,9,89,14,0,0,0,1,0,1,
		0,95,255,122,8,6,100,9,9,100,100,100,100,100,
		100,100,100,100,112,25,80,4,36,32,1,48,88,0,
		176,90,0,12,0,92,120,89,47,0,1,0,1,0,
		2,0,176,91,0,12,0,121,8,28,16,48,95,0,
		48,45,0,95,255,112,0,112,0,25,16,48,96,0,
		48,45,0,95,255,112,0,95,1,112,1,6,95,3,
		100,100,100,100,100,100,100,100,9,89,15,0,0,0,
		1,0,1,0,95,255,92,3,69,6,100,9,9,100,
		100,100,100,100,100,100,100,100,112,25,73,36,41,1,
		48,88,0,176,90,0,12,0,93,130,0,89,47,0,
		1,0,1,0,2,0,176,91,0,12,0,121,8,28,
		16,48,97,0,48,45,0,95,255,112,0,112,0,25,
		16,48,98,0,48,45,0,95,255,112,0,95,1,112,
		1,6,95,3,100,106,9,64,69,32,57,57,46,57,
		57,0,89,43,0,0,0,1,0,2,0,48,97,0,
		48,45,0,95,255,112,0,112,0,121,16,21,28,18,
		73,48,97,0,48,45,0,95,255,112,0,112,0,92,
		24,34,6,100,100,100,100,100,9,89,15,0,0,0,
		1,0,1,0,95,255,92,3,69,6,100,9,120,100,
		100,90,4,121,6,90,5,92,24,6,100,100,100,100,
		100,112,25,80,7,36,43,1,48,99,0,95,7,89,
		17,0,0,0,1,0,2,0,48,100,0,95,255,112,
		0,6,112,1,73,36,50,1,48,88,0,176,90,0,
		12,0,93,140,0,89,47,0,1,0,1,0,2,0,
		176,91,0,12,0,121,8,28,16,48,101,0,48,45,
		0,95,255,112,0,112,0,25,16,48,102,0,48,45,
		0,95,255,112,0,95,1,112,1,6,95,3,100,100,
		100,100,100,100,100,100,9,89,15,0,0,0,1,0,
		1,0,95,255,92,3,69,6,100,9,9,100,100,100,
		100,100,100,106,5,76,85,80,65,0,100,93,141,0,
		112,25,80,6,36,52,1,48,103,0,95,6,89,26,
		0,0,0,2,0,2,0,6,0,48,104,0,48,68,
		0,95,255,112,0,95,254,112,1,6,112,1,73,36,
		53,1,48,105,0,95,6,89,49,0,0,0,2,0,
		2,0,6,0,48,106,0,48,68,0,95,255,112,0,
		95,254,48,107,0,95,254,112,0,106,8,99,68,101,
		115,83,101,99,0,120,120,106,2,48,0,112,6,6,
		112,1,73,36,63,1,48,88,0,176,108,0,12,0,
		93,244,1,89,34,0,0,0,2,0,2,0,5,0,
		48,109,0,48,51,0,95,255,112,0,95,254,112,1,
		73,48,100,0,95,255,112,0,6,95,3,100,100,9,
		89,15,0,0,0,1,0,1,0,95,255,92,3,69,
		6,100,100,9,112,10,73,36,69,1,48,88,0,176,
		108,0,12,0,93,245,1,89,34,0,0,0,2,0,
		2,0,5,0,48,110,0,48,51,0,95,255,112,0,
		95,254,112,1,73,48,100,0,95,255,112,0,6,95,
		3,100,100,9,89,15,0,0,0,1,0,1,0,95,
		255,92,3,69,6,100,100,9,112,10,73,36,74,1,
		48,88,0,176,108,0,12,0,93,246,1,89,22,0,
		0,0,1,0,2,0,48,111,0,48,51,0,95,255,
		112,0,112,0,6,95,3,100,100,9,100,100,100,9,
		112,10,73,36,80,1,48,88,0,176,108,0,12,0,
		93,247,1,89,34,0,0,0,2,0,2,0,5,0,
		48,112,0,48,51,0,95,255,112,0,95,254,112,1,
		73,48,100,0,95,255,112,0,6,95,3,100,100,9,
		89,15,0,0,0,1,0,1,0,95,255,92,3,69,
		6,100,100,9,112,10,73,36,82,1,48,1,0,176,
		113,0,12,0,95,3,112,1,80,5,36,84,1,48,
		114,0,95,5,90,12,121,97,229,229,229,0,4,2,
		0,6,112,1,73,36,85,1,48,115,0,95,5,90,
		12,121,97,167,205,240,0,4,2,0,6,112,1,73,
		36,87,1,48,116,0,48,117,0,48,51,0,95,2,
		112,0,112,0,95,5,112,1,73,36,89,1,48,118,
		0,95,5,92,5,112,1,73,36,91,1,48,119,0,
		95,5,89,34,0,0,0,2,0,2,0,5,0,48,
		110,0,48,51,0,95,255,112,0,95,254,112,1,73,
		48,100,0,95,255,112,0,6,112,1,73,36,93,1,
		48,120,0,95,5,93,200,0,112,1,73,36,95,1,
		48,121,0,95,5,112,0,143,36,96,1,144,122,0,
		106,7,67,243,100,105,103,111,0,112,1,73,36,97,
		1,144,123,0,89,27,0,0,0,1,0,2,0,48,
		124,0,48,117,0,48,51,0,95,255,112,0,112,0,
		112,0,6,112,1,73,36,98,1,144,125,0,92,70,
		112,1,73,145,36,101,1,48,121,0,95,5,112,0,
		143,36,102,1,144,122,0,106,12,68,101,115,99,114,
		105,112,99,105,243,110,0,112,1,73,36,103,1,144,
		123,0,89,59,0,0,0,1,0,2,0,176,126,0,
		48,124,0,48,117,0,48,51,0,95,255,112,0,112,
		0,112,0,48,94,0,48,45,0,48,67,0,95,255,
		112,0,112,0,112,0,106,8,99,68,101,115,67,111,
		115,0,12,3,6,112,1,73,36,104,1,144,125,0,
		93,144,1,112,1,73,145,36,107,1,48,121,0,95,
		5,112,0,143,36,108,1,144,122,0,106,8,73,109,
		112,111,114,116,101,0,112,1,73,36,109,1,144,123,
		0,89,66,0,0,0,1,0,2,0,176,127,0,176,
		128,0,48,124,0,48,117,0,48,51,0,95,255,112,
		0,112,0,112,0,48,45,0,48,67,0,95,255,112,
		0,112,0,106,8,110,73,109,112,67,111,115,0,12,
		3,48,129,0,95,255,112,0,12,2,6,112,1,73,
		36,110,1,144,125,0,92,100,112,1,73,36,111,1,
		144,130,0,122,112,1,73,36,112,1,144,131,0,122,
		112,1,73,145,36,115,1,48,121,0,95,5,112,0,
		143,36,116,1,144,122,0,106,6,37,80,99,116,46,
		0,112,1,73,36,117,1,144,123,0,89,44,0,0,
		0,1,0,2,0,176,127,0,48,132,0,48,117,0,
		48,51,0,95,255,112,0,112,0,112,0,106,10,64,
		69,32,57,57,57,46,57,57,0,12,2,6,112,1,
		73,36,118,1,144,125,0,92,90,112,1,73,36,119,
		1,144,130,0,122,112,1,73,36,120,1,144,131,0,
		122,112,1,73,145,36,123,1,48,121,0,95,5,112,
		0,143,36,124,1,144,122,0,106,6,84,111,116,97,
		108,0,112,1,73,36,125,1,144,123,0,89,34,0,
		0,0,1,0,2,0,48,133,0,48,51,0,95,255,
		112,0,48,117,0,48,51,0,95,255,112,0,112,0,
		112,1,6,112,1,73,36,126,1,144,125,0,92,100,
		112,1,73,36,127,1,144,130,0,122,112,1,73,36,
		128,1,144,131,0,122,112,1,73,145,36,136,1,48,
		134,0,95,2,48,88,0,176,90,0,12,0,93,44,
		1,89,37,0,1,0,1,0,2,0,176,91,0,12,
		0,121,8,28,11,48,135,0,95,255,112,0,25,11,
		48,136,0,95,255,95,1,112,1,6,95,3,100,48,
		129,0,95,2,112,0,100,106,5,78,47,87,42,0,
		100,100,100,100,9,90,4,9,6,100,9,9,100,100,
		100,100,100,100,100,100,100,112,25,112,1,73,36,143,
		1,48,137,0,95,2,48,88,0,176,90,0,12,0,
		93,54,1,89,37,0,1,0,1,0,2,0,176,91,
		0,12,0,121,8,28,11,48,138,0,95,255,112,0,
		25,11,48,139,0,95,255,95,1,112,1,6,95,3,
		100,48,129,0,95,2,112,0,100,106,5,78,47,87,
		42,0,100,100,100,100,9,90,4,9,6,100,9,9,
		100,100,100,100,100,100,100,100,100,112,25,112,1,73,
		36,149,1,48,88,0,176,108,0,12,0,122,89,40,
		0,0,0,4,0,2,0,4,0,1,0,3,0,48,
		140,0,95,255,95,254,95,253,112,2,28,12,48,73,
		0,95,252,122,112,1,25,3,100,6,95,3,100,100,
		9,89,15,0,0,0,1,0,1,0,95,255,92,3,
		69,6,100,100,9,112,10,73,36,155,1,48,88,0,
		176,108,0,12,0,92,2,89,17,0,0,0,1,0,
		3,0,48,73,0,95,255,112,0,6,95,3,100,100,
		9,100,100,100,120,112,10,73,36,161,1,48,88,0,
		176,108,0,12,0,93,47,2,90,28,176,141,0,106,
		18,65,121,117,100,97,32,110,111,32,100,101,102,105,
		110,105,100,97,0,12,1,6,95,3,100,100,9,100,
		100,100,120,112,10,73,36,163,1,95,1,92,3,69,
		29,197,0,36,164,1,48,142,0,95,3,92,113,89,
		34,0,0,0,2,0,2,0,5,0,48,109,0,48,
		51,0,95,255,112,0,95,254,112,1,73,48,100,0,
		95,255,112,0,6,112,2,73,36,165,1,48,142,0,
		95,3,92,114,89,34,0,0,0,2,0,2,0,5,
		0,48,110,0,48,51,0,95,255,112,0,95,254,112,
		1,73,48,100,0,95,255,112,0,6,112,2,73,36,
		166,1,48,142,0,95,3,92,115,89,34,0,0,0,
		2,0,2,0,5,0,48,112,0,48,51,0,95,255,
		112,0,95,254,112,1,73,48,100,0,95,255,112,0,
		6,112,2,73,36,167,1,48,142,0,95,3,92,116,
		89,40,0,0,0,4,0,2,0,4,0,1,0,3,
		0,48,140,0,95,255,95,254,95,253,112,2,28,12,
		48,73,0,95,252,122,112,1,25,3,100,6,112,2,
		73,36,170,1,48,143,0,95,3,89,37,0,0,0,
		3,0,4,0,6,0,2,0,48,144,0,95,255,112,
		0,73,48,145,0,95,254,112,0,73,48,100,0,95,
		253,112,0,6,112,1,73,36,172,1,48,6,0,95,
		3,48,146,0,95,3,112,0,48,147,0,95,3,112,
		0,48,148,0,95,3,112,0,120,100,100,100,48,149,
		0,95,3,112,0,100,100,100,112,11,73,36,174,1,
		48,73,0,95,8,112,0,73,36,176,1,48,150,0,
		95,3,112,0,122,8,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_NTOTALVIRTUAL )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,182,1,121,80,2,36,184,1,95,1,
		100,8,28,15,48,117,0,48,51,0,102,112,0,112,
		0,80,1,36,186,1,48,151,0,95,1,112,0,73,
		36,188,1,48,152,0,95,1,112,0,73,36,189,1,
		48,153,0,95,1,112,0,31,35,36,190,1,96,2,
		0,48,154,0,48,51,0,102,112,0,95,1,112,1,
		135,36,191,1,48,155,0,95,1,112,0,73,25,213,
		36,194,1,48,156,0,95,1,112,0,73,36,196,1,
		95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_CTOTALVIRTUAL )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,202,1,95,1,100,8,28,15,48,117,
		0,48,51,0,102,112,0,112,0,80,1,36,204,1,
		176,127,0,48,157,0,102,95,1,112,1,48,129,0,
		102,112,0,20,2,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_LTOTALVIRTUAL )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,210,1,48,157,0,102,48,117,0,48,
		51,0,102,112,0,112,0,112,1,80,1,36,212,1,
		48,158,0,48,159,0,102,112,0,95,1,112,1,73,
		36,213,1,48,158,0,48,160,0,102,112,0,95,1,
		48,97,0,48,45,0,102,112,0,112,0,18,112,1,
		73,36,215,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_NTOTALCOSTEDIA )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,221,1,121,80,3,36,223,1,176,5,
		0,48,51,0,102,112,0,12,1,28,9,36,224,1,
		95,3,110,7,36,227,1,95,1,100,8,28,15,48,
		44,0,48,45,0,102,112,0,112,0,80,1,36,228,
		1,95,2,100,8,28,15,48,45,0,48,51,0,102,
		112,0,112,0,80,2,36,230,1,48,151,0,95,2,
		112,0,73,36,232,1,48,161,0,95,2,95,1,112,
		1,28,59,36,233,1,48,44,0,95,2,112,0,95,
		1,8,28,44,48,153,0,95,2,112,0,31,35,36,
		234,1,96,3,0,48,154,0,48,51,0,102,112,0,
		95,2,112,1,135,36,235,1,48,155,0,95,2,112,
		0,73,25,201,36,239,1,48,156,0,95,2,112,0,
		73,36,241,1,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_CTOTALCOSTEDIA )
{
	static const HB_BYTE pcode[] =
	{
		13,2,3,36,248,1,106,2,48,0,80,5,36,250,
		1,176,5,0,48,51,0,102,112,0,12,1,28,9,
		36,251,1,95,5,110,7,36,254,1,95,1,100,8,
		28,15,48,44,0,48,45,0,102,112,0,112,0,80,
		1,36,255,1,95,2,100,8,28,15,48,85,0,48,
		45,0,102,112,0,112,0,80,2,36,0,2,95,3,
		100,8,28,15,48,45,0,48,51,0,102,112,0,112,
		0,80,3,36,2,2,48,162,0,102,95,1,95,3,
		112,2,80,5,36,4,2,176,163,0,95,2,48,64,
		0,102,112,0,12,2,80,4,36,6,2,95,2,48,
		85,0,48,45,0,102,112,0,112,0,69,28,28,36,
		7,2,176,164,0,95,5,48,85,0,48,45,0,102,
		112,0,112,0,95,2,100,12,4,80,5,36,10,2,
		176,127,0,95,5,95,4,20,2,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_LTOTALCOSTEDIA )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,16,2,95,1,100,8,28,15,48,44,
		0,48,45,0,102,112,0,112,0,80,1,36,17,2,
		95,2,100,8,28,15,48,45,0,48,51,0,102,112,
		0,112,0,80,2,36,18,2,95,3,100,8,28,10,
		48,159,0,102,112,0,80,3,36,20,2,48,165,0,
		95,3,48,162,0,102,95,1,95,2,112,2,112,1,
		73,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_NTOTALCOSTEHORA )
{
	static const HB_BYTE pcode[] =
	{
		13,1,3,36,26,2,121,80,4,36,28,2,95,1,
		100,8,28,15,48,44,0,48,45,0,102,112,0,112,
		0,80,1,36,29,2,95,2,100,8,28,10,48,45,
		0,102,112,0,80,2,36,30,2,95,3,100,8,28,
		15,48,45,0,48,51,0,102,112,0,112,0,80,3,
		36,32,2,48,162,0,102,95,1,95,3,112,2,48,
		97,0,95,2,112,0,18,80,4,36,34,2,95,4,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_CTOTALCOSTEHORA )
{
	static const HB_BYTE pcode[] =
	{
		13,2,4,36,41,2,106,2,48,0,80,6,36,43,
		2,176,5,0,48,51,0,102,112,0,12,1,28,9,
		36,44,2,95,6,110,7,36,47,2,95,1,100,8,
		28,15,48,44,0,48,45,0,102,112,0,112,0,80,
		1,36,48,2,95,2,100,8,28,15,48,85,0,48,
		45,0,102,112,0,112,0,80,2,36,49,2,95,3,
		100,8,28,10,48,45,0,102,112,0,80,3,36,50,
		2,95,4,100,8,28,15,48,45,0,48,51,0,102,
		112,0,112,0,80,4,36,52,2,48,166,0,102,95,
		1,95,3,95,4,112,3,80,6,36,54,2,176,163,
		0,95,2,48,64,0,102,112,0,12,2,80,5,36,
		56,2,95,2,48,85,0,48,45,0,102,112,0,112,
		0,69,28,27,36,57,2,176,164,0,95,6,48,85,
		0,48,45,0,102,112,0,112,0,95,2,12,3,80,
		6,36,60,2,176,127,0,95,6,95,5,20,2,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_LTOTALCOSTEHORA )
{
	static const HB_BYTE pcode[] =
	{
		13,0,4,36,66,2,95,1,100,8,28,15,48,44,
		0,48,45,0,102,112,0,112,0,80,1,36,67,2,
		95,2,100,8,28,10,48,45,0,102,112,0,80,2,
		36,68,2,95,3,100,8,28,15,48,45,0,48,51,
		0,102,112,0,112,0,80,3,36,69,2,95,4,100,
		8,28,10,48,159,0,102,112,0,80,4,36,71,2,
		48,165,0,95,4,48,166,0,102,95,1,95,2,95,
		3,112,3,112,1,73,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TMAQUINA_LPRESAVE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,77,2,95,2,122,8,31,10,95,2,
		92,4,8,29,174,0,36,79,2,176,5,0,48,44,
		0,48,45,0,102,112,0,112,0,12,1,28,71,36,
		80,2,176,40,0,106,42,67,243,100,105,103,111,32,
		100,101,32,108,97,32,109,225,113,117,105,110,97,32,
		110,111,32,112,117,101,100,101,32,101,115,116,97,114,
		32,118,97,99,237,111,0,20,1,36,81,2,48,144,
		0,95,1,112,0,73,36,82,2,9,110,7,36,85,
		2,48,167,0,48,45,0,102,112,0,48,44,0,48,
		45,0,102,112,0,112,0,106,8,67,67,79,68,77,
		65,81,0,112,2,28,46,36,86,2,176,40,0,106,
		17,67,243,100,105,103,111,32,101,120,105,115,116,101,
		110,116,101,0,20,1,36,87,2,48,144,0,95,1,
		112,0,73,36,88,2,9,110,7,36,93,2,176,5,
		0,48,95,0,48,45,0,102,112,0,112,0,12,1,
		28,69,36,94,2,176,40,0,106,51,76,97,32,100,
		101,115,99,114,105,112,99,105,243,110,32,100,101,32,
		108,97,32,109,225,113,117,105,110,97,32,110,111,32,
		112,117,101,100,101,32,101,115,116,97,114,32,118,97,
		99,237,97,46,0,20,1,36,95,2,9,110,7,36,
		98,2,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,170,0,2,0,116,170,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

