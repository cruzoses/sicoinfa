/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\Prg\tablet\view\documentos\ventas\InvoiceDocumentSalesViewEdit.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( INVOICEDOCUMENTSALESVIEWEDIT );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( DOCUMENTSALESVIEWEDIT );
HB_FUNC_STATIC( INVOICEDOCUMENTSALESVIEWEDIT_DEFINEACEPTARCANCELAR );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( TGRIDIMAGE );
HB_FUNC_EXTERN( GRIDWIDTH );
HB_FUNC_EXTERN( RECEIPTINVOICECUSTOMER );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_INVOICEDOCUMENTSALESVIEWEDIT )
{ "INVOICEDOCUMENTSALESVIEWEDIT", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( INVOICEDOCUMENTSALESVIEWEDIT )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "DOCUMENTSALESVIEWEDIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( DOCUMENTSALESVIEWEDIT )}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INVOICEDOCUMENTSALESVIEWEDIT_DEFINEACEPTARCANCELAR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( INVOICEDOCUMENTSALESVIEWEDIT_DEFINEACEPTARCANCELAR )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETMODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "BUILD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TGRIDIMAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( TGRIDIMAGE )}, NULL },
{ "GRIDWIDTH", {HB_FS_PUBLIC}, {HB_FUNCNAME( GRIDWIDTH )}, NULL },
{ "ODLG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PLAY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RECEIPTINVOICECUSTOMER", {HB_FS_PUBLIC}, {HB_FUNCNAME( RECEIPTINVOICECUSTOMER )}, NULL },
{ "OSENDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BUTTONCANCEL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CANCELVIEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_BUTTONOK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ONVIEWSAVE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_INVOICEDOCUMENTSALESVIEWEDIT, ".\\Prg\\tablet\\view\\documentos\\ventas\\InvoiceDocumentSalesViewEdit.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_INVOICEDOCUMENTSALESVIEWEDIT
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_INVOICEDOCUMENTSALESVIEWEDIT )
   #include "hbiniseg.h"
#endif

HB_FUNC( INVOICEDOCUMENTSALESVIEWEDIT )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,26,0,36,5,0,103,2,0,100,8,
		29,186,0,176,1,0,104,2,0,12,1,29,175,0,
		166,113,0,0,122,80,1,48,2,0,176,3,0,12,
		0,106,29,73,110,118,111,105,99,101,68,111,99,117,
		109,101,110,116,83,97,108,101,115,86,105,101,119,69,
		100,105,116,0,108,4,4,1,0,108,0,112,3,80,
		2,36,7,0,48,5,0,95,2,106,22,100,101,102,
		105,110,101,65,99,101,112,116,97,114,67,97,110,99,
		101,108,97,114,0,108,6,95,1,121,72,121,72,121,
		72,112,3,73,36,9,0,48,7,0,95,2,112,0,
		73,167,14,0,0,176,8,0,104,2,0,95,2,20,
		2,168,48,9,0,95,2,112,0,80,3,176,10,0,
		95,3,106,10,73,110,105,116,67,108,97,115,115,0,
		12,2,28,12,48,11,0,95,3,164,146,1,0,73,
		95,3,110,7,48,9,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( INVOICEDOCUMENTSALESVIEWEDIT_DEFINEACEPTARCANCELAR )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,13,0,102,80,1,36,15,0,48,12,
		0,95,1,112,0,92,2,8,29,186,0,36,23,0,
		48,13,0,176,14,0,12,0,106,5,110,84,111,112,
		0,92,5,106,6,110,76,101,102,116,0,89,33,0,
		0,0,1,0,1,0,176,15,0,101,0,0,0,0,
		0,0,30,64,10,1,48,16,0,95,255,112,0,12,
		2,6,106,7,110,87,105,100,116,104,0,92,64,106,
		8,110,72,101,105,103,104,116,0,92,64,106,9,99,
		82,101,115,78,97,109,101,0,106,22,103,99,95,98,
		114,105,101,102,99,97,115,101,50,95,117,115,101,114,
		95,54,52,0,106,10,98,76,67,108,105,99,107,101,
		100,0,89,32,0,0,0,1,0,1,0,48,17,0,
		48,2,0,176,18,0,12,0,48,19,0,95,255,112,
		0,112,1,112,0,6,106,5,111,87,110,100,0,48,
		16,0,95,1,112,0,177,7,0,112,1,73,36,33,
		0,48,20,0,95,1,48,13,0,176,14,0,12,0,
		106,5,110,84,111,112,0,92,5,106,6,110,76,101,
		102,116,0,89,33,0,0,0,1,0,1,0,176,15,
		0,101,0,0,0,0,0,0,34,64,10,1,48,16,
		0,95,255,112,0,12,2,6,106,7,110,87,105,100,
		116,104,0,92,64,106,8,110,72,101,105,103,104,116,
		0,92,64,106,9,99,82,101,115,78,97,109,101,0,
		106,12,103,99,95,101,114,114,111,114,95,54,52,0,
		106,10,98,76,67,108,105,99,107,101,100,0,89,17,
		0,0,0,1,0,1,0,48,21,0,95,255,112,0,
		6,106,5,111,87,110,100,0,48,16,0,95,1,112,
		0,177,7,0,112,1,112,1,73,36,41,0,48,22,
		0,95,1,48,13,0,176,14,0,12,0,106,5,110,
		84,111,112,0,92,5,106,6,110,76,101,102,116,0,
		89,33,0,0,0,1,0,1,0,176,15,0,101,0,
		0,0,0,0,0,37,64,10,1,48,16,0,95,255,
		112,0,12,2,6,106,7,110,87,105,100,116,104,0,
		92,64,106,8,110,72,101,105,103,104,116,0,92,64,
		106,9,99,82,101,115,78,97,109,101,0,106,9,103,
		99,95,111,107,95,54,52,0,106,10,98,76,67,108,
		105,99,107,101,100,0,89,22,0,0,0,1,0,1,
		0,48,23,0,48,19,0,95,255,112,0,112,0,6,
		106,5,111,87,110,100,0,48,16,0,95,1,112,0,
		177,7,0,112,1,112,1,73,36,43,0,95,1,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,26,0,2,0,116,26,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}
