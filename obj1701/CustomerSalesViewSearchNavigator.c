/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\Prg\tablet\view\terceros\CustomerSalesViewSearchNavigator.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( CUSTOMERSALESVIEWSEARCHNAVIGATOR );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( DOCUMENTSALESVIEWSEARCHNAVIGATOR );
HB_FUNC_EXTERN( D );
HB_FUNC_STATIC( CUSTOMERSALESVIEWSEARCHNAVIGATOR_BOTONESACCIONES );
HB_FUNC_STATIC( CUSTOMERSALESVIEWSEARCHNAVIGATOR_CHANGEFILTER );
HB_FUNC_STATIC( CUSTOMERSALESVIEWSEARCHNAVIGATOR_RESOURCE );
HB_FUNC_STATIC( CUSTOMERSALESVIEWSEARCHNAVIGATOR_SETCOLUMNS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( TGRIDIMAGE );
HB_FUNC_EXTERN( GRIDWIDTH );
HB_FUNC_EXTERN( LIQUIDATERECEIPT );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( TGRIDSAY );
HB_FUNC_EXTERN( OGRIDFONT );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( CPORDIV );
HB_FUNC_EXTERN( CIMP );
HB_FUNC_EXTERN( TRANSFORM );
HB_FUNC_EXTERN( NTOTPDTFACCLI );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_CUSTOMERSALESVIEWSEARCHNAVIGATOR )
{ "CUSTOMERSALESVIEWSEARCHNAVIGATOR", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( CUSTOMERSALESVIEWSEARCHNAVIGATOR )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "DOCUMENTSALESVIEWSEARCHNAVIGATOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( DOCUMENTSALESVIEWSEARCHNAVIGATOR )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FACTURASCLIENTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "D", {HB_FS_PUBLIC}, {HB_FUNCNAME( D )}, NULL },
{ "GETVIEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CUSTOMERSALESVIEWSEARCHNAVIGATOR_BOTONESACCIONES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( CUSTOMERSALESVIEWSEARCHNAVIGATOR_BOTONESACCIONES )}, NULL },
{ "CUSTOMERSALESVIEWSEARCHNAVIGATOR_CHANGEFILTER", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( CUSTOMERSALESVIEWSEARCHNAVIGATOR_CHANGEFILTER )}, NULL },
{ "CUSTOMERSALESVIEWSEARCHNAVIGATOR_RESOURCE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( CUSTOMERSALESVIEWSEARCHNAVIGATOR_RESOURCE )}, NULL },
{ "CUSTOMERSALESVIEWSEARCHNAVIGATOR_SETCOLUMNS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( CUSTOMERSALESVIEWSEARCHNAVIGATOR_SETCOLUMNS )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BUILD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGRIDIMAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGRIDIMAGE )}, NULL },
{ "GRIDWIDTH", {HB_FS_PUBLIC}, {HB_FUNCNAME( GRIDWIDTH )}, NULL },
{ "ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PLAY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LIQUIDATERECEIPT", {HB_FS_PUBLIC}, {HB_FUNCNAME( LIQUIDATERECEIPT )}, NULL },
{ "NVIEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSENDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CIDCLIENTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REFRESHBROWSECUSTOMERSALES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCAPTION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSAYFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LIQINVOICE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETFIELD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "CHANGEFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OSAYFILTER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGRIDSAY", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGRIDSAY )}, NULL },
{ "OGRIDFONT", {HB_FS_PUBLIC}, {HB_FUNCNAME( OGRIDFONT )}, NULL },
{ "_BSTART", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VARPUT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "REFRESH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FILTERSALESCUSTOMERTABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFINETITULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LSELECTORMODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFINEACEPTARCANCELAR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFINESALIR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DEFINEBARRABUSQUEDA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BOTONESACCIONES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BOTONESMOVIMIENTOBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BROWSEGENERAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BLDBLCLICK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OBROWSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VISUALIZAFACTURA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BRESIZED", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RESIZEDIALOG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALIDDIALOG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INITDIALOG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ENDDIALOG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETBROWSECONFIGURATIONNAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDCOLUMN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CHEADER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BEDITVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "_NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_LHIDE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_CEDITPICTURE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPORDIV", {HB_FS_PUBLIC}, {HB_FUNCNAME( CPORDIV )}, NULL },
{ "_NDATASTRALIGN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_NHEADSTRALIGN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CIMP", {HB_FS_PUBLIC}, {HB_FUNCNAME( CIMP )}, NULL },
{ "TRANSFORM", {HB_FS_PUBLIC}, {HB_FUNCNAME( TRANSFORM )}, NULL },
{ "NTOTPDTFACCLI", {HB_FS_PUBLIC}, {HB_FUNCNAME( NTOTPDTFACCLI )}, NULL },
{ "FACTURASCLIENTESLINEAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TIPOSIVA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DIVISAS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FACTURASCLIENTESCOBROS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ANTICIPOSCLIENTES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_CUSTOMERSALESVIEWSEARCHNAVIGATOR, ".\\Prg\\tablet\\view\\terceros\\CustomerSalesViewSearchNavigator.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_CUSTOMERSALESVIEWSEARCHNAVIGATOR
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_CUSTOMERSALESVIEWSEARCHNAVIGATOR )
   #include "hbiniseg.h"
#endif

HB_FUNC( CUSTOMERSALESVIEWSEARCHNAVIGATOR )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,85,0,36,5,0,103,2,0,100,8,
		29,244,1,176,1,0,104,2,0,12,1,29,233,1,
		166,171,1,0,122,80,1,48,2,0,176,3,0,12,
		0,106,33,67,117,115,116,111,109,101,114,83,97,108,
		101,115,86,105,101,119,83,101,97,114,99,104,78,97,
		118,105,103,97,116,111,114,0,108,4,4,1,0,108,
		0,112,3,80,2,36,7,0,48,5,0,95,2,100,
		100,95,1,121,72,121,72,121,72,106,11,111,83,97,
		121,70,105,108,116,101,114,0,4,1,0,9,112,5,
		73,36,9,0,48,6,0,95,2,106,13,103,101,116,
		68,97,116,97,84,97,98,108,101,0,89,18,0,1,
		0,0,0,106,8,70,97,99,67,108,105,84,0,6,
		95,1,121,72,121,72,121,72,112,3,73,36,10,0,
		48,6,0,95,2,106,12,103,101,116,87,111,114,107,
		65,114,101,97,0,89,25,0,1,0,0,0,48,7,
		0,176,8,0,12,0,48,9,0,95,1,112,0,112,
		1,6,95,1,121,72,121,72,121,72,112,3,73,36,
		12,0,48,10,0,95,2,106,16,98,111,116,111,110,
		101,115,65,99,99,105,111,110,101,115,0,108,11,95,
		1,121,72,121,72,121,72,112,3,73,36,14,0,48,
		6,0,95,2,106,18,103,101,116,84,105,116,108,101,
		68,111,99,117,109,101,110,116,111,0,89,27,0,1,
		0,0,0,106,17,70,97,99,116,117,114,97,115,32,
		99,108,105,101,110,116,101,0,6,95,1,121,72,121,
		72,121,72,112,3,73,36,16,0,48,10,0,95,2,
		106,13,67,104,97,110,103,101,70,105,108,116,101,114,
		0,108,12,95,1,121,72,121,72,121,72,112,3,73,
		36,18,0,48,10,0,95,2,106,9,82,101,115,111,
		117,114,99,101,0,108,13,95,1,121,72,121,72,121,
		72,112,3,73,36,20,0,48,10,0,95,2,106,11,
		115,101,116,67,111,108,117,109,110,115,0,108,14,95,
		1,121,72,121,72,121,72,112,3,73,36,22,0,48,
		15,0,95,2,112,0,73,167,14,0,0,176,16,0,
		104,2,0,95,2,20,2,168,48,17,0,95,2,112,
		0,80,3,176,18,0,95,3,106,10,73,110,105,116,
		67,108,97,115,115,0,12,2,28,12,48,19,0,95,
		3,164,146,1,0,73,95,3,110,7,48,17,0,103,
		2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( CUSTOMERSALESVIEWSEARCHNAVIGATOR_BOTONESACCIONES )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,26,0,102,80,1,36,35,0,48,20,
		0,176,21,0,12,0,106,5,110,84,111,112,0,92,
		75,106,6,110,76,101,102,116,0,89,33,0,0,0,
		1,0,1,0,176,22,0,101,0,0,0,0,0,0,
		224,63,10,1,48,23,0,95,255,112,0,12,2,6,
		106,7,110,87,105,100,116,104,0,92,64,106,8,110,
		72,101,105,103,104,116,0,92,64,106,9,99,82,101,
		115,78,97,109,101,0,106,16,103,99,95,115,97,102,
		101,95,105,110,116,111,95,54,52,0,106,10,98,76,
		67,108,105,99,107,101,100,0,89,74,0,0,0,1,
		0,1,0,48,24,0,48,2,0,176,25,0,12,0,
		48,26,0,48,27,0,95,255,112,0,112,0,48,28,
		0,48,27,0,95,255,112,0,112,0,112,2,112,0,
		73,48,29,0,48,27,0,95,255,112,0,48,30,0,
		48,31,0,95,255,112,0,112,0,112,1,6,106,5,
		111,87,110,100,0,48,23,0,95,1,112,0,177,7,
		0,112,1,73,36,43,0,48,20,0,176,21,0,12,
		0,106,5,110,84,111,112,0,92,75,106,6,110,76,
		101,102,116,0,89,33,0,0,0,1,0,1,0,176,
		22,0,101,0,0,0,0,0,0,248,63,10,1,48,
		23,0,95,255,112,0,12,2,6,106,7,110,87,105,
		100,116,104,0,92,64,106,8,110,72,101,105,103,104,
		116,0,92,64,106,9,99,82,101,115,78,97,109,101,
		0,106,13,103,99,95,109,111,110,101,121,50,95,54,
		52,0,106,10,98,76,67,108,105,99,107,101,100,0,
		89,101,0,0,0,1,0,1,0,48,32,0,48,27,
		0,95,255,112,0,48,33,0,95,255,106,6,83,101,
		114,105,101,0,112,1,176,34,0,48,33,0,95,255,
		106,7,78,117,109,101,114,111,0,112,1,12,1,72,
		48,33,0,95,255,106,7,83,117,102,105,106,111,0,
		112,1,72,112,1,73,48,29,0,48,27,0,95,255,
		112,0,48,30,0,48,31,0,95,255,112,0,112,0,
		112,1,6,106,5,111,87,110,100,0,48,23,0,95,
		1,112,0,177,7,0,112,1,73,36,51,0,48,20,
		0,176,21,0,12,0,106,5,110,84,111,112,0,92,
		75,106,6,110,76,101,102,116,0,89,33,0,0,0,
		1,0,1,0,176,22,0,101,0,0,0,0,0,0,
		4,64,10,1,48,23,0,95,255,112,0,12,2,6,
		106,7,110,87,105,100,116,104,0,92,64,106,8,110,
		72,101,105,103,104,116,0,92,64,106,9,99,82,101,
		115,78,97,109,101,0,106,13,103,99,95,102,117,110,
		110,101,108,95,54,52,0,106,10,98,76,67,108,105,
		99,107,101,100,0,89,17,0,0,0,1,0,1,0,
		48,35,0,95,255,112,0,6,106,5,111,87,110,100,
		0,48,23,0,95,1,112,0,177,7,0,112,1,73,
		36,63,0,48,36,0,95,1,48,20,0,176,37,0,
		12,0,106,5,110,82,111,119,0,92,75,106,5,110,
		67,111,108,0,89,33,0,0,0,1,0,1,0,176,
		22,0,101,0,0,0,0,0,0,12,64,10,1,48,
		23,0,95,255,112,0,12,2,6,106,6,98,84,101,
		120,116,0,90,6,106,1,0,6,106,5,111,87,110,
		100,0,48,23,0,95,1,112,0,106,6,111,70,111,
		110,116,0,176,38,0,12,0,106,8,108,80,105,120,
		101,108,115,0,120,106,9,110,67,108,114,84,101,120,
		116,0,121,106,9,110,67,108,114,66,97,99,107,0,
		97,255,255,255,0,106,7,110,87,105,100,116,104,0,
		89,24,0,0,0,1,0,1,0,176,22,0,92,3,
		48,23,0,95,255,112,0,12,2,6,106,8,110,72,
		101,105,103,104,116,0,92,23,106,8,108,68,101,115,
		105,103,110,0,9,177,11,0,112,1,112,1,73,36,
		65,0,48,39,0,48,23,0,95,1,112,0,89,17,
		0,0,0,1,0,1,0,48,35,0,95,255,112,0,
		6,112,1,73,36,67,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( CUSTOMERSALESVIEWSEARCHNAVIGATOR_CHANGEFILTER )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,73,0,106,1,0,80,1,36,76,0,
		48,30,0,48,31,0,102,112,0,112,0,106,1,0,
		8,28,23,36,77,0,106,11,80,101,110,100,105,101,
		110,116,101,115,0,80,1,26,137,0,36,79,0,48,
		30,0,48,31,0,102,112,0,112,0,106,9,67,111,
		98,114,97,100,97,115,0,8,28,17,36,80,0,106,
		6,84,111,100,97,115,0,80,1,25,93,36,82,0,
		48,30,0,48,31,0,102,112,0,112,0,106,11,80,
		101,110,100,105,101,110,116,101,115,0,8,28,20,36,
		83,0,106,9,67,111,98,114,97,100,97,115,0,80,
		1,25,45,36,85,0,48,30,0,48,31,0,102,112,
		0,112,0,106,6,84,111,100,97,115,0,8,28,20,
		36,86,0,106,11,80,101,110,100,105,101,110,116,101,
		115,0,80,1,36,90,0,48,40,0,48,31,0,102,
		112,0,95,1,112,1,73,36,91,0,48,41,0,48,
		31,0,102,112,0,112,0,73,36,93,0,48,42,0,
		48,27,0,102,112,0,48,30,0,48,31,0,102,112,
		0,112,0,112,1,73,36,95,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( CUSTOMERSALESVIEWSEARCHNAVIGATOR_RESOURCE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,99,0,102,80,1,36,101,0,48,43,
		0,95,1,48,2,0,176,44,0,12,0,122,92,5,
		92,40,92,100,106,15,71,69,83,84,79,79,76,32,
		84,65,66,76,69,84,0,100,100,9,48,45,0,95,
		1,112,0,100,97,255,255,255,0,100,100,9,100,176,
		38,0,12,0,100,100,100,9,100,106,5,111,68,108,
		103,0,112,22,112,1,73,36,103,0,48,46,0,95,
		1,112,0,73,36,105,0,48,47,0,95,1,112,0,
		28,15,36,106,0,48,48,0,95,1,112,0,73,25,
		13,36,108,0,48,49,0,95,1,112,0,73,36,111,
		0,48,50,0,95,1,112,0,73,36,113,0,48,51,
		0,95,1,112,0,73,36,115,0,48,52,0,95,1,
		112,0,73,36,117,0,48,53,0,95,1,112,0,73,
		36,119,0,48,54,0,48,55,0,95,1,112,0,89,
		76,0,0,0,1,0,1,0,48,56,0,48,27,0,
		95,255,112,0,48,33,0,95,255,106,6,83,101,114,
		105,101,0,112,1,176,34,0,48,33,0,95,255,106,
		7,78,117,109,101,114,111,0,112,1,12,1,72,48,
		33,0,95,255,106,7,83,117,102,105,106,111,0,112,
		1,72,112,1,6,112,1,73,36,121,0,48,57,0,
		48,23,0,95,1,112,0,89,17,0,0,0,1,0,
		1,0,48,58,0,95,255,112,0,6,112,1,73,36,
		123,0,48,59,0,48,23,0,95,1,112,0,100,100,
		100,120,89,17,0,0,0,1,0,1,0,48,60,0,
		95,255,112,0,6,100,89,17,0,0,0,1,0,1,
		0,48,61,0,95,255,112,0,6,112,7,73,36,125,
		0,48,62,0,95,1,112,0,73,36,127,0,95,1,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( CUSTOMERSALESVIEWSEARCHNAVIGATOR_SETCOLUMNS )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,131,0,102,80,1,36,133,0,48,63,
		0,95,1,106,20,103,114,105,100,95,118,101,110,116,
		97,115,99,108,105,101,110,116,101,115,0,112,1,73,
		36,135,0,48,64,0,95,1,112,0,143,36,136,0,
		144,65,0,106,3,73,100,0,112,1,73,36,137,0,
		144,66,0,89,88,0,0,0,1,0,1,0,48,33,
		0,95,255,106,6,83,101,114,105,101,0,112,1,106,
		2,47,0,72,176,67,0,176,34,0,48,33,0,95,
		255,106,7,78,117,109,101,114,111,0,112,1,12,1,
		12,1,72,106,2,13,0,72,106,2,10,0,72,176,
		68,0,48,33,0,95,255,106,6,70,101,99,104,97,
		0,112,1,12,1,72,6,112,1,73,36,138,0,144,
		69,0,93,165,0,112,1,73,145,36,141,0,48,64,
		0,95,1,112,0,143,36,142,0,144,65,0,106,8,
		67,108,105,101,110,116,101,0,112,1,73,36,143,0,
		144,66,0,89,71,0,0,0,1,0,1,0,176,67,
		0,48,33,0,95,255,106,8,67,108,105,101,110,116,
		101,0,112,1,12,1,106,2,13,0,72,106,2,10,
		0,72,176,67,0,48,33,0,95,255,106,14,78,111,
		109,98,114,101,67,108,105,101,110,116,101,0,112,1,
		12,1,72,6,112,1,73,36,144,0,144,69,0,93,
		54,1,112,1,73,145,36,147,0,48,64,0,95,1,
		112,0,143,36,148,0,144,65,0,106,7,65,103,101,
		110,116,101,0,112,1,73,36,149,0,144,66,0,89,
		26,0,0,0,1,0,1,0,48,33,0,95,255,106,
		7,65,103,101,110,116,101,0,112,1,6,112,1,73,
		36,150,0,144,69,0,92,100,112,1,73,36,151,0,
		144,70,0,120,112,1,73,145,36,154,0,48,64,0,
		95,1,112,0,143,36,155,0,144,65,0,106,5,66,
		97,115,101,0,112,1,73,36,156,0,144,66,0,89,
		29,0,0,0,1,0,1,0,48,33,0,95,255,106,
		10,84,111,116,97,108,78,101,116,111,0,112,1,6,
		112,1,73,36,157,0,144,71,0,176,72,0,12,0,
		112,1,73,36,158,0,144,69,0,92,100,112,1,73,
		36,159,0,144,73,0,122,112,1,73,36,160,0,144,
		74,0,122,112,1,73,36,161,0,144,70,0,120,112,
		1,73,145,36,164,0,48,64,0,95,1,112,0,143,
		36,165,0,144,65,0,176,75,0,12,0,112,1,73,
		36,166,0,144,66,0,89,33,0,0,0,1,0,1,
		0,48,33,0,95,255,106,14,84,111,116,97,108,73,
		109,112,117,101,115,116,111,0,112,1,6,112,1,73,
		36,167,0,144,71,0,176,72,0,12,0,112,1,73,
		36,168,0,144,69,0,92,100,112,1,73,36,169,0,
		144,73,0,122,112,1,73,36,170,0,144,74,0,122,
		112,1,73,36,171,0,144,70,0,120,112,1,73,145,
		36,174,0,48,64,0,95,1,112,0,143,36,175,0,
		144,65,0,106,5,82,46,69,46,0,112,1,73,36,
		176,0,144,66,0,89,32,0,0,0,1,0,1,0,
		48,33,0,95,255,106,13,84,111,116,97,108,82,101,
		99,97,114,103,111,0,112,1,6,112,1,73,36,177,
		0,144,71,0,176,72,0,12,0,112,1,73,36,178,
		0,144,69,0,92,100,112,1,73,36,179,0,144,73,
		0,122,112,1,73,36,180,0,144,74,0,122,112,1,
		73,36,181,0,144,70,0,120,112,1,73,145,36,184,
		0,48,64,0,95,1,112,0,143,36,185,0,144,65,
		0,106,9,84,111,116,47,80,100,116,46,0,112,1,
		73,36,186,0,144,66,0,89,0,1,0,0,1,0,
		1,0,176,76,0,48,33,0,95,255,106,15,84,111,
		116,97,108,68,111,99,117,109,101,110,116,111,0,112,
		1,176,72,0,12,0,12,2,106,2,13,0,72,106,
		2,10,0,72,176,76,0,176,77,0,48,33,0,95,
		255,106,6,83,101,114,105,101,0,112,1,176,34,0,
		48,33,0,95,255,106,7,78,117,109,101,114,111,0,
		112,1,12,1,72,48,33,0,95,255,106,7,83,117,
		102,105,106,111,0,112,1,72,48,7,0,176,8,0,
		12,0,48,26,0,48,27,0,95,255,112,0,112,0,
		112,1,48,78,0,176,8,0,12,0,48,26,0,48,
		27,0,95,255,112,0,112,0,112,1,48,79,0,176,
		8,0,12,0,48,26,0,48,27,0,95,255,112,0,
		112,0,112,1,48,80,0,176,8,0,12,0,48,26,
		0,48,27,0,95,255,112,0,112,0,112,1,48,81,
		0,176,8,0,12,0,48,26,0,48,27,0,95,255,
		112,0,112,0,112,1,48,82,0,176,8,0,12,0,
		48,26,0,48,27,0,95,255,112,0,112,0,112,1,
		12,7,176,72,0,12,0,12,2,72,6,112,1,73,
		36,187,0,144,69,0,93,155,0,112,1,73,36,188,
		0,144,73,0,122,112,1,73,36,189,0,144,74,0,
		122,112,1,73,145,36,192,0,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,85,0,2,0,116,85,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

