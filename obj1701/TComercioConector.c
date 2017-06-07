/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\Prg\Comercio\TComercioConector.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TCOMERCIOCONECTOR );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HBOBJECT );
HB_FUNC_STATIC( TCOMERCIOCONECTOR_NEW );
HB_FUNC_STATIC( TCOMERCIOCONECTOR_COMMANDEXECDIRECT );
HB_FUNC_EXTERN( TMSQUERY );
HB_FUNC_STATIC( TCOMERCIOCONECTOR_TRUNCATETABLE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( TMSCOMMAND );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TCOMERCIOCONECTOR )
{ "TCOMERCIOCONECTOR", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOCONECTOR )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HBOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBOBJECT )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOCONECTOR_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOCONECTOR_NEW )}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NVIEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TPRESTASHOPID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOCONFIG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LSYNCALL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLANGUAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOCUSTOMER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOBUDGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOORDER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOPRODUCT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOCATEGORY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETCURRENTWEBNAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "WRITETEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "WRITETEXTOK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "WRITETEXTERROR", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSTOCK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCON", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CPREFIXTABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "METERTOTALTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "METERTOTALSETTOTAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "METERPROCESOTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "METERPROCESOSETTOTAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LPRODUCTIDCOLUMNIMAGESHOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LPRODUCTIDCOLUMNPRODUCTATTRIBUTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LPRODUCTIDCOLUMNPRODUCTATTRIBUTESHOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LSPECIFICPRICEIDCOLUMNREDUCTIONTAX", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ATYPEIMAGESPRESTASHOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OFTP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDIRECTORYPRODUCT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDIRECTORYCATEGORIES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CDIRECTORYMANUFACTURE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETRECURSIVEFOLDERPRESTASHOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOCONECTOR_COMMANDEXECDIRECT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOCONECTOR_COMMANDEXECDIRECT )}, NULL },
{ "TMSQUERY", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMSQUERY )}, NULL },
{ "OCONEXIONMYSQLDATABASE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOCONECTOR_TRUNCATETABLE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOCONECTOR_TRUNCATETABLE )}, NULL },
{ "PRESTASHOPCONNECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PRESTASHOPDISCONNECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FILESOPEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FILESCLOSE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SAVELASTINSERTSTOCK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETLASTINSERTSTOCK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETTIME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_TCOMERCIO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "COMMANDEXECDIRECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ISDEBUGMODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMEGACOMMAND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EXECDIRECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TMSCOMMAND", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMSCOMMAND )}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TCOMERCIOCONECTOR, ".\\Prg\\Comercio\\TComercioConector.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TCOMERCIOCONECTOR
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TCOMERCIOCONECTOR )
   #include "hbiniseg.h"
#endif

HB_FUNC( TCOMERCIOCONECTOR )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,66,0,36,12,0,103,2,0,100,8,
		29,87,10,176,1,0,104,2,0,12,1,29,76,10,
		166,14,10,0,122,80,1,48,2,0,176,3,0,12,
		0,106,18,84,67,111,109,101,114,99,105,111,67,111,
		110,101,99,116,111,114,0,108,4,4,1,0,108,0,
		112,3,80,2,36,14,0,48,5,0,95,2,100,100,
		95,1,121,72,121,72,121,72,106,10,84,67,111,109,
		101,114,99,105,111,0,4,1,0,9,112,5,73,36,
		16,0,48,6,0,95,2,106,4,78,101,119,0,108,
		7,95,1,92,8,72,121,72,121,72,112,3,73,36,
		20,0,48,8,0,95,2,106,8,103,101,116,86,105,
		101,119,0,89,20,0,1,0,0,0,48,9,0,48,
		10,0,95,1,112,0,112,0,6,95,1,121,72,121,
		72,121,72,112,3,73,36,22,0,48,8,0,95,2,
		106,14,84,80,114,101,115,116,97,115,104,111,112,73,
		100,0,89,20,0,1,0,0,0,48,11,0,48,10,
		0,95,1,112,0,112,0,6,95,1,121,72,121,72,
		121,72,112,3,73,36,23,0,48,8,0,95,2,106,
		16,84,67,111,109,101,114,99,105,111,67,111,110,102,
		105,103,0,89,20,0,1,0,0,0,48,12,0,48,
		10,0,95,1,112,0,112,0,6,95,1,121,72,121,
		72,121,72,112,3,73,36,25,0,48,8,0,95,2,
		106,16,105,115,83,121,110,99,114,111,110,105,122,101,
		65,108,108,0,89,20,0,1,0,0,0,48,13,0,
		48,10,0,95,1,112,0,112,0,6,95,1,121,72,
		121,72,121,72,112,3,73,36,26,0,48,8,0,95,
		2,106,12,103,101,116,76,97,110,103,117,97,103,101,
		0,89,20,0,1,0,0,0,48,14,0,48,10,0,
		95,1,112,0,112,0,6,95,1,121,72,121,72,121,
		72,112,3,73,36,28,0,48,8,0,95,2,106,18,
		84,67,111,109,101,114,99,105,111,67,117,115,116,111,
		109,101,114,0,89,20,0,1,0,0,0,48,15,0,
		48,10,0,95,1,112,0,112,0,6,95,1,121,72,
		121,72,121,72,112,3,73,36,29,0,48,8,0,95,
		2,106,16,84,67,111,109,101,114,99,105,111,66,117,
		100,103,101,116,0,89,20,0,1,0,0,0,48,16,
		0,48,10,0,95,1,112,0,112,0,6,95,1,121,
		72,121,72,121,72,112,3,73,36,30,0,48,8,0,
		95,2,106,15,84,67,111,109,101,114,99,105,111,79,
		114,100,101,114,0,89,20,0,1,0,0,0,48,17,
		0,48,10,0,95,1,112,0,112,0,6,95,1,121,
		72,121,72,121,72,112,3,73,36,31,0,48,8,0,
		95,2,106,17,84,67,111,109,101,114,99,105,111,80,
		114,111,100,117,99,116,0,89,20,0,1,0,0,0,
		48,18,0,48,10,0,95,1,112,0,112,0,6,95,
		1,121,72,121,72,121,72,112,3,73,36,32,0,48,
		8,0,95,2,106,18,84,67,111,109,101,114,99,105,
		111,67,97,116,101,103,111,114,121,0,89,20,0,1,
		0,0,0,48,19,0,48,10,0,95,1,112,0,112,
		0,6,95,1,121,72,121,72,121,72,112,3,73,36,
		34,0,48,8,0,95,2,106,18,103,101,116,67,117,
		114,114,101,110,116,87,101,98,78,97,109,101,0,89,
		20,0,1,0,0,0,48,20,0,48,10,0,95,1,
		112,0,112,0,6,95,1,121,72,121,72,121,72,112,
		3,73,36,36,0,48,8,0,95,2,106,10,119,114,
		105,116,101,84,101,120,116,0,89,22,0,2,0,0,
		0,48,21,0,48,10,0,95,1,112,0,95,2,112,
		1,6,95,1,121,72,121,72,121,72,112,3,73,36,
		37,0,48,8,0,95,2,106,12,119,114,105,116,101,
		84,101,120,116,79,107,0,89,24,0,3,0,0,0,
		48,22,0,48,10,0,95,1,112,0,95,2,95,3,
		112,2,6,95,1,121,72,121,72,121,72,112,3,73,
		36,38,0,48,8,0,95,2,106,15,119,114,105,116,
		101,84,101,120,116,69,114,114,111,114,0,89,24,0,
		3,0,0,0,48,23,0,48,10,0,95,1,112,0,
		95,2,95,3,112,2,6,95,1,121,72,121,72,121,
		72,112,3,73,36,40,0,48,8,0,95,2,106,7,
		111,83,116,111,99,107,0,89,20,0,1,0,0,0,
		48,24,0,48,10,0,95,1,112,0,112,0,6,95,
		1,121,72,121,72,121,72,112,3,73,36,42,0,48,
		8,0,95,2,106,23,111,67,111,110,101,120,105,111,
		110,77,121,83,81,76,68,97,116,97,98,97,115,101,
		0,89,20,0,1,0,0,0,48,25,0,48,10,0,
		95,1,112,0,112,0,6,95,1,121,72,121,72,121,
		72,112,3,73,36,44,0,48,8,0,95,2,106,13,
		99,80,114,101,102,105,120,116,97,98,108,101,0,89,
		22,0,2,0,0,0,48,26,0,48,10,0,95,1,
		112,0,95,2,112,1,6,95,1,121,72,121,72,121,
		72,112,3,73,36,46,0,48,8,0,95,2,106,15,
		109,101,116,101,114,84,111,116,97,108,84,101,120,116,
		0,89,22,0,2,0,0,0,48,27,0,48,10,0,
		95,1,112,0,95,2,112,1,6,95,1,121,72,121,
		72,121,72,112,3,73,36,47,0,48,8,0,95,2,
		106,19,109,101,116,101,114,84,111,116,97,108,83,101,
		116,84,111,116,97,108,0,89,22,0,2,0,0,0,
		48,28,0,48,10,0,95,1,112,0,95,2,112,1,
		6,95,1,121,72,121,72,121,72,112,3,73,36,48,
		0,48,8,0,95,2,106,17,109,101,116,101,114,80,
		114,111,99,101,115,111,84,101,120,116,0,89,22,0,
		2,0,0,0,48,29,0,48,10,0,95,1,112,0,
		95,2,112,1,6,95,1,121,72,121,72,121,72,112,
		3,73,36,49,0,48,8,0,95,2,106,21,109,101,
		116,101,114,80,114,111,99,101,115,111,83,101,116,84,
		111,116,97,108,0,89,22,0,2,0,0,0,48,30,
		0,48,10,0,95,1,112,0,95,2,112,1,6,95,
		1,121,72,121,72,121,72,112,3,73,36,51,0,48,
		8,0,95,2,106,26,108,80,114,111,100,117,99,116,
		73,100,67,111,108,117,109,110,73,109,97,103,101,83,
		104,111,112,0,89,20,0,1,0,0,0,48,31,0,
		48,10,0,95,1,112,0,112,0,6,95,1,121,72,
		121,72,121,72,112,3,73,36,52,0,48,8,0,95,
		2,106,33,108,80,114,111,100,117,99,116,73,100,67,
		111,108,117,109,110,80,114,111,100,117,99,116,65,116,
		116,114,105,98,117,116,101,0,89,20,0,1,0,0,
		0,48,32,0,48,10,0,95,1,112,0,112,0,6,
		95,1,121,72,121,72,121,72,112,3,73,36,53,0,
		48,8,0,95,2,106,37,108,80,114,111,100,117,99,
		116,73,100,67,111,108,117,109,110,80,114,111,100,117,
		99,116,65,116,116,114,105,98,117,116,101,83,104,111,
		112,0,89,20,0,1,0,0,0,48,33,0,48,10,
		0,95,1,112,0,112,0,6,95,1,121,72,121,72,
		121,72,112,3,73,36,54,0,48,8,0,95,2,106,
		35,108,83,112,101,99,105,102,105,99,80,114,105,99,
		101,73,100,67,111,108,117,109,110,82,101,100,117,99,
		116,105,111,110,84,97,120,0,89,20,0,1,0,0,
		0,48,34,0,48,10,0,95,1,112,0,112,0,6,
		95,1,121,72,121,72,121,72,112,3,73,36,55,0,
		48,8,0,95,2,106,22,97,84,121,112,101,73,109,
		97,103,101,115,80,114,101,115,116,97,115,104,111,112,
		0,89,20,0,1,0,0,0,48,35,0,48,10,0,
		95,1,112,0,112,0,6,95,1,121,72,121,72,121,
		72,112,3,73,36,57,0,48,8,0,95,2,106,5,
		111,70,116,112,0,89,20,0,1,0,0,0,48,36,
		0,48,10,0,95,1,112,0,112,0,6,95,1,121,
		72,121,72,121,72,112,3,73,36,58,0,48,8,0,
		95,2,106,18,99,68,105,114,101,99,116,111,114,121,
		80,114,111,100,117,99,116,0,89,20,0,1,0,0,
		0,48,37,0,48,10,0,95,1,112,0,112,0,6,
		95,1,121,72,121,72,121,72,112,3,73,36,59,0,
		48,8,0,95,2,106,21,99,68,105,114,101,99,116,
		111,114,121,67,97,116,101,103,111,114,105,101,115,0,
		89,20,0,1,0,0,0,48,38,0,48,10,0,95,
		1,112,0,112,0,6,95,1,121,72,121,72,121,72,
		112,3,73,36,60,0,48,8,0,95,2,106,22,99,
		68,105,114,101,99,116,111,114,121,77,97,110,117,102,
		97,99,116,117,114,101,0,89,20,0,1,0,0,0,
		48,39,0,48,10,0,95,1,112,0,112,0,6,95,
		1,121,72,121,72,121,72,112,3,73,36,62,0,48,
		8,0,95,2,106,29,103,101,116,82,101,99,117,114,
		115,105,118,101,70,111,108,100,101,114,80,114,101,115,
		116,97,115,104,111,112,0,89,22,0,2,0,0,0,
		48,40,0,48,10,0,95,1,112,0,95,2,112,1,
		6,95,1,121,72,121,72,121,72,112,3,73,36,64,
		0,48,6,0,95,2,106,18,99,111,109,109,97,110,
		100,69,120,101,99,68,105,114,101,99,116,0,108,41,
		95,1,121,72,121,72,121,72,112,3,73,36,65,0,
		48,8,0,95,2,106,16,113,117,101,114,121,69,120,
		101,99,68,105,114,101,99,116,0,89,27,0,2,0,
		0,0,48,2,0,176,42,0,12,0,48,43,0,95,
		1,112,0,95,2,112,2,6,95,1,121,72,121,72,
		121,72,112,3,73,36,67,0,48,6,0,95,2,106,
		14,116,114,117,110,99,97,116,101,84,97,98,108,101,
		0,108,44,95,1,121,72,121,72,121,72,112,3,73,
		36,69,0,48,8,0,95,2,106,18,112,114,101,115,
		116,97,83,104,111,112,67,111,110,110,101,99,116,0,
		89,20,0,1,0,0,0,48,45,0,48,10,0,95,
		1,112,0,112,0,6,95,1,121,72,121,72,121,72,
		112,3,73,36,70,0,48,8,0,95,2,106,21,112,
		114,101,115,116,97,83,104,111,112,68,105,115,67,111,
		110,110,101,99,116,0,89,20,0,1,0,0,0,48,
		46,0,48,10,0,95,1,112,0,112,0,6,95,1,
		121,72,121,72,121,72,112,3,73,36,72,0,48,8,
		0,95,2,106,10,102,105,108,101,115,79,112,101,110,
		0,89,20,0,1,0,0,0,48,47,0,48,10,0,
		95,1,112,0,112,0,6,95,1,121,72,121,72,121,
		72,112,3,73,36,73,0,48,8,0,95,2,106,11,
		102,105,108,101,115,67,108,111,115,101,0,89,20,0,
		1,0,0,0,48,48,0,48,10,0,95,1,112,0,
		112,0,6,95,1,121,72,121,72,121,72,112,3,73,
		36,75,0,48,8,0,95,2,106,20,115,97,118,101,
		76,97,115,116,73,110,115,101,114,116,83,116,111,99,
		107,0,89,22,0,2,0,0,0,48,49,0,48,10,
		0,95,1,112,0,95,2,112,1,6,95,1,121,72,
		121,72,121,72,112,3,73,36,76,0,48,8,0,95,
		2,106,19,103,101,116,76,97,115,116,73,110,115,101,
		114,116,115,116,111,99,107,0,89,20,0,1,0,0,
		0,48,50,0,48,10,0,95,1,112,0,112,0,6,
		95,1,121,72,121,72,121,72,112,3,73,36,80,0,
		48,8,0,95,2,106,8,103,101,116,68,97,116,101,
		0,89,22,0,2,0,0,0,48,51,0,48,10,0,
		95,1,112,0,95,2,112,1,6,95,1,121,72,121,
		72,121,72,112,3,73,36,81,0,48,8,0,95,2,
		106,8,103,101,116,84,105,109,101,0,89,22,0,2,
		0,0,0,48,52,0,48,10,0,95,1,112,0,95,
		2,112,1,6,95,1,121,72,121,72,121,72,112,3,
		73,36,83,0,48,53,0,95,2,112,0,73,167,14,
		0,0,176,54,0,104,2,0,95,2,20,2,168,48,
		55,0,95,2,112,0,80,3,176,56,0,95,3,106,
		10,73,110,105,116,67,108,97,115,115,0,12,2,28,
		12,48,57,0,95,3,164,146,1,0,73,95,3,110,
		7,48,55,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOCONECTOR_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,89,0,48,58,0,102,95,1,112,1,
		73,36,91,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOCONECTOR_TRUNCATETABLE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,97,0,48,59,0,102,106,16,84,82,
		85,78,67,65,84,69,32,84,65,66,76,69,32,0,
		48,26,0,102,95,1,112,1,72,112,1,28,58,36,
		98,0,48,21,0,102,106,7,84,97,98,108,97,32,
		0,48,26,0,102,95,1,112,1,72,106,23,32,98,
		111,114,114,97,100,97,32,99,111,114,114,101,99,116,
		97,109,101,110,116,101,0,72,112,1,73,25,49,36,
		100,0,48,21,0,102,106,26,69,114,114,111,114,32,
		97,108,32,98,111,114,114,97,114,32,108,97,32,116,
		97,98,108,97,32,0,48,26,0,102,95,1,112,1,
		72,112,1,73,36,103,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOCONECTOR_COMMANDEXECDIRECT )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,109,0,48,21,0,102,95,1,112,1,
		73,36,111,0,48,60,0,48,10,0,102,112,0,112,
		0,28,25,36,112,0,48,61,0,48,10,0,102,112,
		0,95,1,112,1,73,36,113,0,120,110,7,36,116,
		0,48,62,0,48,2,0,176,63,0,12,0,48,43,
		0,102,112,0,112,1,95,1,112,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,66,0,2,0,116,66,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

