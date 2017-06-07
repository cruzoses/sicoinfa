/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\.\Prg\C5Lib.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( AC5BOX );
HB_FUNC_EXTERN( MOVETO );
HB_FUNC_EXTERN( LINETO );
HB_FUNC( C5BOX );
HB_FUNC( FONTUNDER );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( CREATEFONTUNDERLINE );
HB_FUNC_EXTERN( CREATEFONT );
HB_FUNC( COLORES );
HB_FUNC_EXTERN( CREATEDC );
HB_FUNC_EXTERN( GETDEVICECAPS );
HB_FUNC_EXTERN( DELETEDC );
HB_FUNC_EXTERN( INT );
HB_FUNC( GETORIGINALORDEN );
HB_FUNC( LOADACCESOS );
HB_FUNC( GETBITMAPSIZE );
HB_FUNC( GETBITMAP16 );
HB_FUNC_EXTERN( CREATECOMPATIBLEDC );
HB_FUNC_EXTERN( BMPWIDTH );
HB_FUNC_EXTERN( BMPHEIGHT );
HB_FUNC_EXTERN( SELECTOBJECT );
HB_FUNC_EXTERN( C5_EXTFLOODFILL );
HB_FUNC_EXTERN( CREATECOMPATIBLEBITMAP );
HB_FUNC_EXTERN( FILLSOLIDRECT );
HB_FUNC_EXTERN( SETSTRETCHBLTMODE );
HB_FUNC_EXTERN( STRETCHBLT );
HB_FUNC_EXTERN( DESTROYICON );
HB_FUNC_EXTERN( DELETEOBJECT );
HB_FUNC( __MIRROW );
HB_FUNC_EXTERN( VGRADIENTFILL );
HB_FUNC_EXTERN( HGRADIENTFILL );
HB_FUNC( XADRIVES );
HB_FUNC_EXTERN( ISDISKETTE );
HB_FUNC_EXTERN( CHR );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( ISCDROM );
HB_FUNC_EXTERN( FILE );
HB_FUNC( SAVESCREENASBMP );
HB_FUNC_EXTERN( BITBLT );
HB_FUNC( RESTORESCREENFROMBMP );
HB_FUNC_EXTERN( DRAWBITMAP );
HB_FUNC( GENIMAGELIST );
HB_FUNC_EXTERN( CGETFILEEX );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_STATIC( ADDIMAGES );
HB_FUNC_EXTERN( MSGYESNO );
HB_FUNC_EXTERN( CGETFILE );
HB_FUNC_STATIC( SAVEIMAGENAS );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( GETDC );
HB_FUNC( LFN2SFNEX );
HB_FUNC_EXTERN( READBITMAP );
HB_FUNC_EXTERN( NBMPWIDTH );
HB_FUNC_EXTERN( NBMPHEIGHT );
HB_FUNC_EXTERN( MAX );
HB_FUNC_EXTERN( DRAWMASKED );
HB_FUNC_EXTERN( RELEASEDC );
HB_FUNC_EXTERN( DIBWRITE );
HB_FUNC_EXTERN( DIBFROMBITMAP );
HB_FUNC_EXTERN( STRTRAN );
HB_FUNC( FINDCHAR );
HB_FUNC_EXTERN( LEFT );
HB_FUNC_EXTERN( LFN2SFN );
HB_FUNC_EXTERN( SUBSTR );
HB_FUNC( DLGCHANGESIZE );
HB_FUNC_EXTERN( GETCURSORPOS );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( TGET );
HB_FUNC_EXTERN( PCOUNT );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC( STRCOUNT );
HB_FUNC( ASPLIT );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( STRTOKEN );
HB_FUNC( LOADICONEX );
HB_FUNC_EXTERN( LOADICON );
HB_FUNC_EXTERN( GETRESOURCES );
HB_FUNC_EXTERN( EXTRACTICON );
HB_FUNC( LOADIMAGEEX );
HB_FUNC_EXTERN( LOADBITMAP );
HB_FUNC( LOADIMAGEEX2 );
HB_FUNC( GETDEFFONT );
HB_FUNC_EXTERN( GETSTOCKOBJECT );
HB_FUNC( LTHEMES );
HB_FUNC_EXTERN( C5_ISAPPTHEMED );
HB_FUNC_EXTERN( C5_ISTHEMEACTIVE );
HB_FUNC( CREAVGRIP );
HB_FUNC( CREAAROWRIGHT );
HB_FUNC_EXTERN( POLYPOLYGON );
HB_FUNC( CREABITMAPEX );
HB_FUNC_EXTERN( VERTICALGRADIENT );
HB_FUNC( CREABITMAPEX2 );
HB_FUNC( MEMOWRITEX );
HB_FUNC_EXTERN( FCREATE );
HB_FUNC_EXTERN( FWRITE );
HB_FUNC_EXTERN( FCLOSE );
HB_FUNC( DRAWMTEXT );
HB_FUNC_EXTERN( AT );
HB_FUNC_EXTERN( GETSIZETEXT );
HB_FUNC_EXTERN( RTRIM );
HB_FUNC_EXTERN( EXTTEXTOUT );
HB_FUNC( ICON2BMP );
HB_FUNC_EXTERN( DRAWICON );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_C5LIB )
{ "AC5BOX", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( AC5BOX )}, NULL },
{ "MOVETO", {HB_FS_PUBLIC}, {HB_FUNCNAME( MOVETO )}, NULL },
{ "LINETO", {HB_FS_PUBLIC}, {HB_FUNCNAME( LINETO )}, NULL },
{ "C5BOX", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( C5BOX )}, NULL },
{ "FONTUNDER", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( FONTUNDER )}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "CREATEFONTUNDERLINE", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEFONTUNDERLINE )}, NULL },
{ "CREATEFONT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEFONT )}, NULL },
{ "NINPHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NINPWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NESCAPEMENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NORIENTATION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LBOLD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LITALIC", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LSTRIKEOUT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCHARSET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NOUTPRECISION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NCLIPPRECISION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NQUALITY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NPITCHFAMILY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CFACENAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "COLORES", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( COLORES )}, NULL },
{ "CREATEDC", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEDC )}, NULL },
{ "GETDEVICECAPS", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETDEVICECAPS )}, NULL },
{ "DELETEDC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DELETEDC )}, NULL },
{ "INT", {HB_FS_PUBLIC}, {HB_FUNCNAME( INT )}, NULL },
{ "GETORIGINALORDEN", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETORIGINALORDEN )}, NULL },
{ "LOADACCESOS", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LOADACCESOS )}, NULL },
{ "GETBITMAPSIZE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETBITMAPSIZE )}, NULL },
{ "GETBITMAP16", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETBITMAP16 )}, NULL },
{ "CREATECOMPATIBLEDC", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATECOMPATIBLEDC )}, NULL },
{ "BMPWIDTH", {HB_FS_PUBLIC}, {HB_FUNCNAME( BMPWIDTH )}, NULL },
{ "BMPHEIGHT", {HB_FS_PUBLIC}, {HB_FUNCNAME( BMPHEIGHT )}, NULL },
{ "SELECTOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( SELECTOBJECT )}, NULL },
{ "C5_EXTFLOODFILL", {HB_FS_PUBLIC}, {HB_FUNCNAME( C5_EXTFLOODFILL )}, NULL },
{ "CREATECOMPATIBLEBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATECOMPATIBLEBITMAP )}, NULL },
{ "FILLSOLIDRECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FILLSOLIDRECT )}, NULL },
{ "SETSTRETCHBLTMODE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETSTRETCHBLTMODE )}, NULL },
{ "STRETCHBLT", {HB_FS_PUBLIC}, {HB_FUNCNAME( STRETCHBLT )}, NULL },
{ "DESTROYICON", {HB_FS_PUBLIC}, {HB_FUNCNAME( DESTROYICON )}, NULL },
{ "DELETEOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( DELETEOBJECT )}, NULL },
{ "__MIRROW", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( __MIRROW )}, NULL },
{ "VGRADIENTFILL", {HB_FS_PUBLIC}, {HB_FUNCNAME( VGRADIENTFILL )}, NULL },
{ "HGRADIENTFILL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGRADIENTFILL )}, NULL },
{ "XADRIVES", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( XADRIVES )}, NULL },
{ "ISDISKETTE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ISDISKETTE )}, NULL },
{ "CHR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CHR )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ISCDROM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ISCDROM )}, NULL },
{ "FILE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FILE )}, NULL },
{ "SAVESCREENASBMP", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SAVESCREENASBMP )}, NULL },
{ "BITBLT", {HB_FS_PUBLIC}, {HB_FUNCNAME( BITBLT )}, NULL },
{ "RESTORESCREENFROMBMP", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( RESTORESCREENFROMBMP )}, NULL },
{ "DRAWBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( DRAWBITMAP )}, NULL },
{ "GENIMAGELIST", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GENIMAGELIST )}, NULL },
{ "CGETFILEEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( CGETFILEEX )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "ADDIMAGES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( ADDIMAGES )}, NULL },
{ "MSGYESNO", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGYESNO )}, NULL },
{ "CGETFILE", {HB_FS_PUBLIC}, {HB_FUNCNAME( CGETFILE )}, NULL },
{ "SAVEIMAGENAS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SAVEIMAGENAS )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "GETDC", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETDC )}, NULL },
{ "LFN2SFNEX", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LFN2SFNEX )}, NULL },
{ "READBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( READBITMAP )}, NULL },
{ "NBMPWIDTH", {HB_FS_PUBLIC}, {HB_FUNCNAME( NBMPWIDTH )}, NULL },
{ "NBMPHEIGHT", {HB_FS_PUBLIC}, {HB_FUNCNAME( NBMPHEIGHT )}, NULL },
{ "MAX", {HB_FS_PUBLIC}, {HB_FUNCNAME( MAX )}, NULL },
{ "DRAWMASKED", {HB_FS_PUBLIC}, {HB_FUNCNAME( DRAWMASKED )}, NULL },
{ "RELEASEDC", {HB_FS_PUBLIC}, {HB_FUNCNAME( RELEASEDC )}, NULL },
{ "DIBWRITE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DIBWRITE )}, NULL },
{ "DIBFROMBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( DIBFROMBITMAP )}, NULL },
{ "STRTRAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( STRTRAN )}, NULL },
{ "FINDCHAR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( FINDCHAR )}, NULL },
{ "LEFT", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEFT )}, NULL },
{ "LFN2SFN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LFN2SFN )}, NULL },
{ "SUBSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SUBSTR )}, NULL },
{ "DLGCHANGESIZE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( DLGCHANGESIZE )}, NULL },
{ "GETCURSORPOS", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETCURSORPOS )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "TGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGET )}, NULL },
{ "PCOUNT", {HB_FS_PUBLIC}, {HB_FUNCNAME( PCOUNT )}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BLCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BMOVED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BPAINTED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "MOVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TOOLWINDOW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BRCLICKED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STRCOUNT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( STRCOUNT )}, NULL },
{ "ASPLIT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ASPLIT )}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "STRTOKEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( STRTOKEN )}, NULL },
{ "LOADICONEX", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LOADICONEX )}, NULL },
{ "LOADICON", {HB_FS_PUBLIC}, {HB_FUNCNAME( LOADICON )}, NULL },
{ "GETRESOURCES", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETRESOURCES )}, NULL },
{ "EXTRACTICON", {HB_FS_PUBLIC}, {HB_FUNCNAME( EXTRACTICON )}, NULL },
{ "LOADIMAGEEX", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LOADIMAGEEX )}, NULL },
{ "LOADBITMAP", {HB_FS_PUBLIC}, {HB_FUNCNAME( LOADBITMAP )}, NULL },
{ "LOADIMAGEEX2", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LOADIMAGEEX2 )}, NULL },
{ "GETDEFFONT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETDEFFONT )}, NULL },
{ "GETSTOCKOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETSTOCKOBJECT )}, NULL },
{ "LTHEMES", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( LTHEMES )}, NULL },
{ "C5_ISAPPTHEMED", {HB_FS_PUBLIC}, {HB_FUNCNAME( C5_ISAPPTHEMED )}, NULL },
{ "C5_ISTHEMEACTIVE", {HB_FS_PUBLIC}, {HB_FUNCNAME( C5_ISTHEMEACTIVE )}, NULL },
{ "CREAVGRIP", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( CREAVGRIP )}, NULL },
{ "CREAAROWRIGHT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( CREAAROWRIGHT )}, NULL },
{ "POLYPOLYGON", {HB_FS_PUBLIC}, {HB_FUNCNAME( POLYPOLYGON )}, NULL },
{ "CREABITMAPEX", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( CREABITMAPEX )}, NULL },
{ "VERTICALGRADIENT", {HB_FS_PUBLIC}, {HB_FUNCNAME( VERTICALGRADIENT )}, NULL },
{ "CREABITMAPEX2", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( CREABITMAPEX2 )}, NULL },
{ "MEMOWRITEX", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( MEMOWRITEX )}, NULL },
{ "FCREATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FCREATE )}, NULL },
{ "FWRITE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FWRITE )}, NULL },
{ "FCLOSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FCLOSE )}, NULL },
{ "DRAWMTEXT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( DRAWMTEXT )}, NULL },
{ "AT", {HB_FS_PUBLIC}, {HB_FUNCNAME( AT )}, NULL },
{ "GETSIZETEXT", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETSIZETEXT )}, NULL },
{ "RTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( RTRIM )}, NULL },
{ "EXTTEXTOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( EXTTEXTOUT )}, NULL },
{ "ICON2BMP", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ICON2BMP )}, NULL },
{ "DRAWICON", {HB_FS_PUBLIC}, {HB_FUNCNAME( DRAWICON )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00004)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_C5LIB, ".\\.\\Prg\\C5Lib.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_C5LIB
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_C5LIB )
   #include "hbiniseg.h"
#endif

HB_FUNC( AC5BOX )
{
	static const HB_BYTE pcode[] =
	{
		13,4,2,36,39,0,95,2,122,1,80,3,36,40,
		0,95,2,92,2,1,80,4,36,41,0,95,2,92,
		3,1,80,5,36,42,0,95,2,92,4,1,80,6,
		36,45,0,176,1,0,95,1,95,4,95,3,20,3,
		36,46,0,176,2,0,95,1,95,6,95,3,20,3,
		36,47,0,176,2,0,95,1,95,6,95,5,20,3,
		36,48,0,176,2,0,95,1,95,4,95,5,20,3,
		36,49,0,176,2,0,95,1,95,4,95,3,20,3,
		36,51,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( C5BOX )
{
	static const HB_BYTE pcode[] =
	{
		13,0,5,36,57,0,176,0,0,95,1,95,2,95,
		3,95,4,95,5,4,4,0,20,2,36,59,0,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( FONTUNDER )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,68,0,176,5,0,95,1,12,1,106,
		2,78,0,8,28,13,36,70,0,176,6,0,95,1,
		20,1,7,36,81,0,176,7,0,48,8,0,95,1,
		112,0,48,9,0,95,1,112,0,48,10,0,95,1,
		112,0,48,11,0,95,1,112,0,48,12,0,95,1,
		112,0,28,7,93,188,2,25,5,93,144,1,48,13,
		0,95,1,112,0,120,48,14,0,95,1,112,0,48,
		15,0,95,1,112,0,48,16,0,95,1,112,0,48,
		17,0,95,1,112,0,48,18,0,95,1,112,0,48,
		19,0,95,1,112,0,48,20,0,95,1,112,0,4,
		14,0,20,1,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( COLORES )
{
	static const HB_BYTE pcode[] =
	{
		13,3,0,36,86,0,176,22,0,106,8,68,73,83,
		80,76,65,89,0,106,1,0,106,1,0,12,3,80,
		1,36,87,0,176,23,0,95,1,92,14,12,2,80,
		2,36,88,0,176,23,0,95,1,92,12,12,2,80,
		3,36,89,0,176,24,0,95,1,20,1,36,91,0,
		176,25,0,92,2,95,2,95,3,65,84,20,1,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( GETORIGINALORDEN )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,101,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LOADACCESOS )
{
	static const HB_BYTE pcode[] =
	{
		13,0,3,36,107,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( GETBITMAPSIZE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,4,36,116,0,95,4,100,8,28,5,9,80,
		4,36,118,0,176,29,0,95,1,95,2,95,3,95,
		4,20,4,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( GETBITMAP16 )
{
	static const HB_BYTE pcode[] =
	{
		13,8,5,36,127,0,95,2,100,8,28,6,92,16,
		80,2,36,128,0,95,3,100,8,28,6,95,2,80,
		3,36,129,0,95,4,100,8,28,5,9,80,4,36,
		130,0,95,5,100,8,28,5,9,80,5,36,132,0,
		176,22,0,106,8,68,73,83,80,76,65,89,0,121,
		121,121,12,4,80,9,36,133,0,176,30,0,95,9,
		12,1,80,10,36,134,0,176,30,0,95,9,12,1,
		80,11,36,137,0,95,5,28,18,36,138,0,92,32,
		80,12,36,139,0,92,32,80,13,25,26,36,141,0,
		176,31,0,95,1,12,1,80,12,36,142,0,176,32,
		0,95,1,12,1,80,13,36,145,0,176,33,0,95,
		11,95,1,12,2,80,8,36,146,0,176,34,0,95,
		11,122,122,97,255,255,255,0,20,4,36,148,0,176,
		35,0,95,9,95,2,95,3,12,3,80,6,36,149,
		0,176,33,0,95,10,95,6,12,2,80,7,36,150,
		0,176,36,0,95,10,121,121,95,3,95,2,4,4,
		0,97,255,0,255,0,20,3,36,151,0,176,37,0,
		95,10,92,3,20,2,36,152,0,176,38,0,95,10,
		121,121,95,2,95,3,95,11,121,121,95,12,95,13,
		97,32,0,204,0,20,11,36,153,0,176,33,0,95,
		10,95,7,20,2,36,154,0,176,33,0,95,11,95,
		8,20,2,36,155,0,176,24,0,95,10,20,1,36,
		156,0,176,24,0,95,11,20,1,36,157,0,176,24,
		0,95,9,20,1,36,159,0,95,4,28,31,36,160,
		0,95,5,28,14,36,161,0,176,39,0,95,1,20,
		1,25,12,36,163,0,176,40,0,95,1,20,1,36,
		167,0,95,6,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( __MIRROW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,5,36,175,0,95,5,28,103,36,176,0,176,
		42,0,95,1,95,2,122,1,95,2,92,2,1,95,
		2,122,1,95,2,92,3,1,95,2,122,1,49,92,
		2,18,72,95,2,92,4,1,4,4,0,95,3,95,
		4,20,4,36,177,0,176,42,0,95,1,95,2,122,
		1,95,2,92,3,1,95,2,122,1,49,92,2,18,
		72,95,2,92,2,1,95,2,92,3,1,95,2,92,
		4,1,4,4,0,95,4,95,3,20,4,25,104,36,
		179,0,176,43,0,95,1,95,2,122,1,95,2,92,
		2,1,95,2,92,3,1,95,2,92,2,1,95,2,
		92,4,1,95,2,92,2,1,49,92,2,18,72,4,
		4,0,95,3,95,4,20,4,36,180,0,176,43,0,
		95,1,95,2,122,1,95,2,92,2,1,95,2,92,
		4,1,95,2,92,2,1,49,92,2,18,72,95,2,
		92,3,1,95,2,92,4,1,4,4,0,95,3,95,
		4,20,4,36,183,0,121,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( XADRIVES )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,36,188,0,4,0,0,80,2,36,191,0,
		95,1,100,8,28,5,121,80,1,36,193,0,95,1,
		121,5,31,8,95,1,122,5,28,67,36,194,0,92,
		65,165,80,3,25,52,36,195,0,176,45,0,176,46,
		0,95,3,12,1,106,2,58,0,72,12,1,28,24,
		36,196,0,176,47,0,95,2,176,46,0,95,3,12,
		1,106,2,58,0,72,20,2,36,194,0,175,3,0,
		92,66,15,28,203,36,201,0,95,1,121,5,31,9,
		95,1,92,2,5,28,90,36,202,0,92,67,165,80,
		3,25,75,36,203,0,176,48,0,176,46,0,95,3,
		12,1,106,2,58,0,72,12,1,31,25,176,49,0,
		176,46,0,95,3,12,1,106,6,58,92,78,85,76,
		0,72,12,1,28,24,36,204,0,176,47,0,95,2,
		176,46,0,95,3,12,1,106,2,58,0,72,20,2,
		36,202,0,175,3,0,92,90,15,28,180,36,209,0,
		95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( SAVESCREENASBMP )
{
	static const HB_BYTE pcode[] =
	{
		13,5,5,36,217,0,176,30,0,95,1,12,1,80,
		8,36,219,0,95,5,95,3,49,80,9,36,220,0,
		95,4,95,2,49,80,10,36,222,0,176,35,0,95,
		1,95,9,95,10,12,3,80,6,36,223,0,176,33,
		0,95,8,95,6,12,2,80,7,36,224,0,176,51,
		0,95,8,121,121,95,9,95,10,95,1,95,3,95,
		2,97,32,0,204,0,20,9,36,225,0,176,33,0,
		95,8,95,7,20,2,36,226,0,176,24,0,95,8,
		20,1,36,228,0,95,6,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( RESTORESCREENFROMBMP )
{
	static const HB_BYTE pcode[] =
	{
		13,0,4,36,232,0,176,53,0,95,1,95,2,95,
		3,95,4,20,4,36,234,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( GENIMAGELIST )
{
	static const HB_BYTE pcode[] =
	{
		13,3,0,116,127,0,36,241,0,4,0,0,80,1,
		36,242,0,106,28,73,109,195,161,103,101,110,101,115,
		32,40,42,46,98,109,112,41,32,124,32,42,46,98,
		109,112,32,124,0,80,2,36,244,0,4,0,0,82,
		4,0,36,249,0,176,55,0,106,6,42,46,98,109,
		112,0,106,21,83,101,108,101,99,99,105,111,110,101,
		32,105,109,195,161,103,101,110,101,115,0,12,2,80,
		1,36,251,0,176,56,0,95,1,12,1,31,112,36,
		253,0,176,57,0,95,1,20,1,36,255,0,176,58,
		0,106,26,68,101,115,101,97,32,116,101,114,109,105,
		110,97,114,32,101,108,32,112,114,111,99,101,115,111,
		0,12,1,28,157,36,0,1,176,59,0,106,6,42,
		46,98,109,112,0,106,23,71,117,97,114,100,97,114,
		32,105,109,97,103,101,110,32,99,111,109,111,46,46,
		46,0,122,100,120,12,5,80,3,36,1,1,176,60,
		0,95,3,20,1,36,2,1,100,110,7,36,6,1,
		176,58,0,106,26,68,101,115,101,97,32,116,101,114,
		109,105,110,97,114,32,101,108,32,112,114,111,99,101,
		115,111,0,12,1,31,5,26,55,255,36,13,1,100,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( ADDIMAGES )
{
	static const HB_BYTE pcode[] =
	{
		13,3,1,116,127,0,36,20,1,9,80,4,36,22,
		1,122,165,80,2,25,88,36,23,1,9,80,4,36,
		24,1,122,165,80,3,25,33,36,25,1,95,1,95,
		2,1,103,4,0,95,3,1,8,28,10,36,26,1,
		120,80,4,25,19,36,24,1,175,3,0,176,61,0,
		103,4,0,12,1,15,28,216,36,30,1,95,4,31,
		18,36,31,1,176,47,0,103,4,0,95,1,95,2,
		1,20,2,36,22,1,175,2,0,176,61,0,95,1,
		12,1,15,28,162,36,35,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( SAVEIMAGENAS )
{
	static const HB_BYTE pcode[] =
	{
		13,12,1,116,127,0,36,42,1,4,0,0,80,4,
		36,43,1,121,80,5,36,44,1,121,80,6,36,47,
		1,176,62,0,121,12,1,80,12,36,50,1,122,165,
		80,2,25,108,36,52,1,176,63,0,103,4,0,95,
		2,1,12,1,80,13,36,53,1,176,64,0,121,95,
		13,12,2,80,3,36,54,1,176,65,0,95,3,12,
		1,80,7,36,55,1,176,66,0,95,3,12,1,80,
		8,36,56,1,176,47,0,95,4,95,3,95,7,95,
		8,4,3,0,20,2,36,57,1,176,67,0,95,7,
		95,5,12,2,80,5,36,58,1,176,67,0,95,8,
		95,6,12,2,80,6,36,50,1,175,2,0,176,61,
		0,103,4,0,12,1,15,28,141,36,62,1,176,30,
		0,95,12,12,1,80,9,36,63,1,176,35,0,95,
		12,95,5,176,61,0,103,4,0,12,1,65,95,6,
		12,3,80,10,36,64,1,176,33,0,95,9,95,10,
		12,2,80,11,36,66,1,176,36,0,95,9,121,121,
		95,6,95,5,176,61,0,103,4,0,12,1,65,4,
		4,0,97,255,0,255,0,20,3,36,68,1,122,165,
		80,2,25,43,36,69,1,176,68,0,95,9,95,4,
		95,2,1,122,1,95,6,95,4,95,2,1,92,3,
		1,49,95,2,122,49,95,5,65,20,4,36,68,1,
		175,2,0,176,61,0,103,4,0,12,1,15,28,206,
		36,72,1,176,33,0,95,9,95,11,20,2,36,74,
		1,176,24,0,95,9,20,1,36,75,1,176,69,0,
		121,95,12,20,2,36,77,1,176,70,0,95,1,176,
		71,0,95,10,12,1,20,2,36,79,1,176,40,0,
		95,10,20,1,36,81,1,122,165,80,2,25,24,36,
		82,1,176,40,0,103,4,0,95,2,1,122,1,20,
		1,36,81,1,175,2,0,176,61,0,103,4,0,12,
		1,15,28,225,36,85,1,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LFN2SFNEX )
{
	static const HB_BYTE pcode[] =
	{
		13,5,1,36,89,1,106,1,0,80,2,36,90,1,
		176,61,0,95,1,12,1,176,61,0,176,72,0,95,
		1,106,2,92,0,106,1,0,12,3,12,1,49,80,
		3,36,94,1,122,165,80,5,25,52,36,95,1,176,
		73,0,95,1,106,2,92,0,95,5,12,3,80,4,
		36,96,1,176,74,0,95,1,95,4,12,2,80,6,
		36,97,1,176,75,0,95,6,12,1,80,2,36,94,
		1,175,5,0,95,3,15,28,203,36,101,1,95,2,
		176,76,0,95,1,95,4,122,72,12,2,72,80,6,
		36,102,1,95,6,80,2,36,104,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( FINDCHAR )
{
	static const HB_BYTE pcode[] =
	{
		13,3,3,36,107,1,121,80,4,36,108,1,176,61,
		0,95,1,12,1,80,5,36,111,1,122,165,80,6,
		25,52,36,112,1,176,76,0,95,1,95,6,176,61,
		0,95,2,12,1,12,3,95,2,8,28,22,36,113,
		1,95,3,175,4,0,8,28,11,36,114,1,95,6,
		80,4,25,13,36,111,1,175,6,0,95,5,15,28,
		203,36,120,1,95,4,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( DLGCHANGESIZE )
{
	static const HB_BYTE pcode[] =
	{
		13,7,2,36,131,1,95,1,80,7,36,132,1,176,
		78,0,12,0,80,8,36,133,1,95,8,122,1,95,
		8,92,2,1,4,2,0,80,9,36,136,1,95,2,
		100,8,28,5,9,80,2,36,144,1,48,79,0,176,
		80,0,12,0,93,153,1,93,32,2,93,249,1,93,
		197,2,106,8,84,97,109,97,195,177,111,0,100,100,
		9,100,100,100,100,100,120,100,100,100,100,100,9,100,
		106,5,111,68,108,103,0,100,100,112,24,80,3,36,
		148,1,48,79,0,176,81,0,12,0,92,10,92,25,
		89,28,0,1,0,1,0,1,0,176,82,0,12,0,
		121,8,28,6,95,255,25,7,95,1,165,80,255,6,
		95,3,92,15,92,8,100,100,100,100,100,9,100,120,
		100,9,100,9,9,100,9,9,9,100,120,100,100,90,
		5,92,30,6,90,6,93,88,2,6,100,100,106,6,
		111,71,101,116,49,0,100,112,33,80,4,36,151,1,
		48,79,0,176,83,0,12,0,92,34,92,43,106,8,
		65,99,101,112,116,97,114,0,95,3,89,17,0,0,
		0,1,0,3,0,48,84,0,95,255,112,0,6,92,
		29,92,10,100,100,120,120,9,100,9,100,100,9,106,
		6,111,66,116,110,49,0,9,112,19,80,5,36,154,
		1,48,79,0,176,83,0,12,0,92,34,92,9,106,
		9,67,97,110,99,101,108,97,114,0,95,3,89,25,
		0,0,0,3,0,7,0,1,0,3,0,95,255,80,
		254,48,84,0,95,253,112,0,6,92,28,92,10,100,
		100,9,120,9,100,9,100,100,9,106,6,111,66,116,
		110,50,0,9,112,19,80,6,36,158,1,48,85,0,
		95,3,48,86,0,95,3,112,0,48,87,0,95,3,
		112,0,48,88,0,95,3,112,0,120,100,100,89,42,
		0,1,0,3,0,8,0,2,0,3,0,95,254,28,
		19,48,89,0,95,253,95,255,122,1,95,255,92,2,
		1,112,2,73,48,90,0,95,253,112,0,6,48,91,
		0,95,3,112,0,100,100,100,112,11,73,36,161,1,
		121,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( STRCOUNT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,167,1,176,61,0,95,1,12,1,176,
		61,0,176,72,0,95,1,95,2,106,1,0,12,3,
		12,1,176,61,0,95,2,12,1,18,49,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( ASPLIT )
{
	static const HB_BYTE pcode[] =
	{
		13,3,2,36,173,1,176,92,0,95,1,95,2,12,
		2,80,3,36,174,1,4,0,0,80,4,36,178,1,
		95,3,121,8,28,9,36,179,1,95,4,110,7,36,
		182,1,122,165,80,5,25,34,36,183,1,176,47,0,
		95,4,176,94,0,176,95,0,95,1,95,5,95,2,
		12,3,12,1,20,2,36,182,1,175,5,0,95,3,
		122,72,15,28,219,36,186,1,95,4,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LOADICONEX )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,192,1,121,80,2,36,194,1,176,97,
		0,176,98,0,12,0,95,1,12,2,80,2,36,195,
		1,95,2,121,8,28,14,36,196,1,176,99,0,95,
		1,12,1,80,2,36,199,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LOADIMAGEEX )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,206,1,121,80,2,36,208,1,176,101,
		0,176,98,0,12,0,95,1,12,2,80,2,36,209,
		1,95,2,121,8,28,15,36,210,1,176,64,0,121,
		95,1,12,2,80,2,36,213,1,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LOADIMAGEEX2 )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,218,1,9,80,3,36,220,1,176,100,
		0,95,1,12,1,80,2,36,221,1,95,2,121,8,
		28,57,36,222,1,176,97,0,176,98,0,12,0,95,
		1,12,2,80,2,36,223,1,95,2,121,8,28,25,
		36,224,1,176,99,0,95,1,12,1,80,2,36,225,
		1,95,2,121,69,80,3,25,8,36,227,1,120,80,
		3,36,231,1,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( GETDEFFONT )
{
	static const HB_BYTE pcode[] =
	{
		36,234,1,176,104,0,92,17,20,1,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( LTHEMES )
{
	static const HB_BYTE pcode[] =
	{
		36,241,1,176,106,0,12,0,21,28,8,73,176,107,
		0,12,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( CREAVGRIP )
{
	static const HB_BYTE pcode[] =
	{
		13,7,2,36,247,1,176,22,0,106,8,68,73,83,
		80,76,65,89,0,121,121,121,12,4,80,3,36,248,
		1,176,30,0,95,3,12,1,80,4,36,249,1,176,
		35,0,95,3,92,5,95,2,12,3,80,5,36,250,
		1,176,33,0,95,4,95,5,12,2,80,6,36,251,
		1,121,121,95,2,92,5,4,4,0,80,7,36,253,
		1,176,25,0,95,2,92,4,18,12,1,80,9,36,
		255,1,176,36,0,95,4,95,7,97,255,0,255,0,
		20,3,36,1,2,92,2,92,2,92,4,92,4,4,
		4,0,80,7,36,3,2,122,165,80,8,25,46,36,
		4,2,176,36,0,95,4,95,7,97,255,255,255,0,
		20,3,36,5,2,95,7,122,148,92,4,135,36,6,
		2,95,7,92,3,148,92,4,135,36,3,2,175,8,
		0,95,9,15,28,209,36,9,2,122,122,92,3,92,
		3,4,4,0,80,7,36,11,2,122,165,80,8,25,
		43,36,12,2,176,36,0,95,4,95,7,95,1,20,
		3,36,13,2,95,7,122,148,92,4,135,36,14,2,
		95,7,92,3,148,92,4,135,36,11,2,175,8,0,
		95,9,15,28,212,36,17,2,176,33,0,95,4,95,
		6,20,2,36,18,2,176,24,0,95,4,20,1,36,
		19,2,176,24,0,95,3,20,1,36,21,2,95,5,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( CREAAROWRIGHT )
{
	static const HB_BYTE pcode[] =
	{
		13,7,0,36,26,2,176,22,0,106,8,68,73,83,
		80,76,65,89,0,121,121,121,12,4,80,1,36,27,
		2,176,30,0,95,1,12,1,80,2,36,28,2,176,
		35,0,95,1,92,8,92,11,12,3,80,3,36,29,
		2,176,33,0,95,2,95,3,12,2,80,4,36,30,
		2,121,121,92,11,92,8,4,4,0,80,5,36,31,
		2,176,104,0,92,4,12,1,80,6,36,32,2,176,
		33,0,95,2,95,6,12,2,80,7,36,34,2,176,
		36,0,95,2,95,5,97,255,0,255,0,20,3,36,
		36,2,176,110,0,95,2,92,2,121,4,2,0,92,
		7,92,5,4,2,0,92,2,92,10,4,2,0,92,
		2,121,4,2,0,4,4,0,20,2,36,39,2,176,
		33,0,95,2,95,7,20,2,36,40,2,176,33,0,
		95,2,95,4,20,2,36,41,2,176,24,0,95,2,
		20,1,36,42,2,176,24,0,95,1,20,1,36,44,
		2,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( CREABITMAPEX )
{
	static const HB_BYTE pcode[] =
	{
		13,5,5,36,51,2,176,22,0,106,8,68,73,83,
		80,76,65,89,0,121,121,121,12,4,80,6,36,52,
		2,176,30,0,95,6,12,1,80,7,36,53,2,176,
		35,0,95,6,95,1,95,2,12,3,80,8,36,54,
		2,176,33,0,95,7,95,8,12,2,80,9,36,55,
		2,121,121,95,2,95,1,4,4,0,80,10,36,57,
		2,95,5,100,8,28,5,120,80,5,36,58,2,95,
		4,100,8,28,6,95,3,80,4,36,60,2,95,5,
		28,20,36,61,2,176,112,0,95,7,95,10,95,3,
		95,4,20,4,25,43,36,63,2,176,43,0,95,7,
		95,10,122,1,95,10,92,2,1,95,10,92,3,1,
		92,2,72,95,10,92,4,1,4,4,0,95,3,95,
		4,92,60,20,5,36,66,2,176,33,0,95,7,95,
		9,20,2,36,67,2,176,24,0,95,7,20,1,36,
		68,2,176,24,0,95,6,20,1,36,70,2,95,8,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( CREABITMAPEX2 )
{
	static const HB_BYTE pcode[] =
	{
		13,5,7,36,75,2,176,22,0,106,8,68,73,83,
		80,76,65,89,0,121,121,121,12,4,80,8,36,76,
		2,176,30,0,95,8,12,1,80,9,36,77,2,176,
		35,0,95,8,95,1,95,2,12,3,80,10,36,78,
		2,176,33,0,95,9,95,10,12,2,80,11,36,79,
		2,121,121,95,2,95,1,4,4,0,80,12,36,81,
		2,95,7,100,8,28,5,120,80,7,36,82,2,95,
		4,100,8,28,6,95,3,80,4,36,84,2,95,7,
		28,108,36,85,2,176,112,0,95,9,95,12,122,1,
		95,12,92,2,1,95,12,122,1,95,12,92,3,1,
		95,12,122,1,49,92,2,18,72,95,12,92,4,1,
		4,4,0,95,3,95,4,20,4,36,86,2,176,112,
		0,95,9,95,12,122,1,95,12,92,3,1,95,12,
		122,1,49,92,2,18,72,122,49,95,12,92,2,1,
		95,12,92,3,1,92,2,72,95,12,92,4,1,4,
		4,0,95,5,95,6,20,4,25,84,36,88,2,176,
		43,0,95,9,95,12,122,1,95,12,92,2,1,95,
		12,92,3,1,92,2,72,95,12,92,4,1,4,4,
		0,95,3,95,4,92,60,20,5,36,89,2,176,43,
		0,95,9,95,12,122,1,95,12,92,2,1,95,12,
		92,3,1,92,2,72,95,12,92,4,1,4,4,0,
		95,3,95,4,92,60,20,5,36,92,2,176,33,0,
		95,9,95,11,20,2,36,93,2,176,24,0,95,9,
		20,1,36,94,2,176,24,0,95,8,20,1,36,96,
		2,95,10,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( MEMOWRITEX )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,103,2,176,115,0,95,1,121,12,2,
		80,3,36,104,2,176,116,0,95,3,95,2,20,2,
		36,105,2,176,117,0,95,3,20,1,36,107,2,121,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( DRAWMTEXT )
{
	static const HB_BYTE pcode[] =
	{
		13,8,4,36,112,2,95,3,92,4,1,95,3,92,
		2,1,49,80,5,36,115,2,95,3,92,2,1,80,
		8,36,116,2,95,3,122,1,80,9,36,117,2,106,
		1,0,80,10,36,119,2,121,80,12,36,121,2,95,
		4,100,8,28,5,120,80,4,36,123,2,96,2,0,
		106,2,32,0,135,36,124,2,176,119,0,106,2,32,
		0,95,2,12,2,165,80,6,121,69,29,184,0,36,
		126,2,176,76,0,95,2,175,6,0,122,12,3,106,
		2,32,0,8,31,237,36,128,2,176,74,0,95,2,
		95,6,122,49,12,2,80,7,36,130,2,174,12,0,
		36,132,2,176,120,0,95,1,95,10,176,121,0,95,
		7,12,1,72,12,2,80,11,36,134,2,95,11,122,
		1,95,5,35,28,13,36,136,2,96,10,0,95,7,
		135,25,78,36,140,2,95,4,28,43,36,141,2,176,
		122,0,95,1,95,9,95,8,95,9,95,3,92,2,
		1,95,9,95,11,92,2,1,72,95,3,92,4,1,
		4,4,0,95,10,92,4,20,6,36,144,2,95,7,
		80,10,36,146,2,95,12,122,15,28,14,36,147,2,
		96,9,0,95,11,92,2,1,135,36,152,2,176,76,
		0,95,2,95,6,12,2,80,2,26,56,255,36,155,
		2,95,4,28,40,176,122,0,95,1,95,9,95,8,
		95,9,95,3,92,2,1,95,9,95,11,92,2,1,
		72,95,3,92,4,1,4,4,0,95,10,92,4,20,
		6,36,157,2,95,9,95,11,92,2,1,72,95,3,
		122,1,49,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( ICON2BMP )
{
	static const HB_BYTE pcode[] =
	{
		13,7,1,36,231,2,176,96,0,95,1,12,1,80,
		8,36,233,2,176,22,0,106,8,68,73,83,80,76,
		65,89,0,121,121,121,12,4,80,4,36,234,2,176,
		30,0,95,4,12,1,80,5,36,236,2,92,32,80,
		6,36,237,2,92,32,80,7,36,239,2,176,35,0,
		95,4,95,6,95,7,12,3,80,2,36,240,2,176,
		33,0,95,5,95,2,12,2,80,3,36,241,2,176,
		36,0,95,5,121,121,95,7,95,6,4,4,0,97,
		255,0,255,0,20,3,36,242,2,176,124,0,95,5,
		121,121,95,8,20,4,36,243,2,176,33,0,95,5,
		95,3,20,2,36,244,2,176,24,0,95,5,20,1,
		36,245,2,176,24,0,95,4,20,1,36,246,2,176,
		39,0,95,8,20,1,36,248,2,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,127,0,4,0,116,127,0,4,0,0,82,1,0,
		4,0,0,82,4,0,7
	};

	hb_vmExecute( pcode, symbols );
}

#line 765 ".\\.\\Prg\\C5Lib.prg"
#include "windows.h"
#include "hbapi.h"

#ifdef __XHARBOUR__
   #define hb_parvc        hb_parc
   #define hb_parvni       hb_parni
   #define hb_storvc       hb_storc
   #define hb_storvni      hb_storni 
#endif

void DrawGradientFill( HDC hDC, RECT rct, COLORREF crStart, COLORREF crEnd, int nSegments, int bVertical )
{
        // Get the starting RGB values and calculate the incremental
        // changes to be applied.

        COLORREF cr;
        int nR = GetRValue(crStart);
        int nG = GetGValue(crStart);
        int nB = GetBValue(crStart);

        int neB = GetBValue(crEnd);
        int neG = GetGValue(crEnd);
        int neR = GetRValue(crEnd);

        int nDiffR = (neR - nR);
        int nDiffG = (neG - nG);
        int nDiffB = (neB - nB);

        int ndR = 256 * (nDiffR) / (max(nSegments,1));
        int ndG = 256 * (nDiffG) / (max(nSegments,1));
        int ndB = 256 * (nDiffB) / (max(nSegments,1));

        int nCX = (rct.right-rct.left) / max(nSegments,1);
        int nCY = (rct.bottom-rct.top) / max(nSegments,1);
        int nTop = rct.top;
        int nBottom = rct.bottom;
        int nLeft = rct.left;
        int nRight = rct.right;

        HPEN hPen;
        HPEN hOldPen;
        HBRUSH hBrush;
        HBRUSH pbrOld;

        int i;

        if(nSegments > ( rct.right - rct.left ) )
                nSegments = ( rct.right - rct.left );


        nR *= 256;
        nG *= 256;
        nB *= 256;

        hPen    = CreatePen( PS_NULL, 1, 0 );
        hOldPen = (HPEN) SelectObject( hDC, hPen );

        for (i = 0; i < nSegments; i++, nR += ndR, nG += ndG, nB += ndB)
        {
                // Use special code for the last segment to avoid any problems
                // with integer division.

                if (i == (nSegments - 1))
                {
                        nRight  = rct.right;
                        nBottom = rct.bottom;
                }
                else
                {
                        nBottom = nTop + nCY;
                        nRight = nLeft + nCX;
                }

                cr = RGB(nR / 256, nG / 256, nB / 256);

                {

                        hBrush = CreateSolidBrush( cr );
                        pbrOld = (HBRUSH) SelectObject( hDC, hBrush );

                        if( bVertical )
                           Rectangle(hDC, rct.left, nTop, rct.right, nBottom + 1 );
                        else
                           Rectangle(hDC, nLeft, rct.top, nRight + 1, rct.bottom);

                        (HBRUSH) SelectObject( hDC, pbrOld );
                        DeleteObject( hBrush );
                }

                // Reset the left side of the drawing rectangle.

                nLeft = nRight;
                nTop = nBottom;
        }

        (HPEN) SelectObject( hDC, hOldPen );
        DeleteObject( hPen );
}


HB_FUNC( DRAWGRADIENTFILL )
{
        RECT rct;

        rct.top    = hb_parvni( 2, 1 );
        rct.left   = hb_parvni( 2, 2 );
        rct.bottom = hb_parvni( 2, 3 );
        rct.right  = hb_parvni( 2, 4 );

        DrawGradientFill( ( HDC ) hb_parnl( 1 ) , rct, hb_parnl( 3 ), hb_parnl( 4 ), hb_parni(5), hb_parl( 6 ) );
}
