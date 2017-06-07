/*
 * Harbour 3.2.0dev (r1307082134)
 * Borland C++ 5.8.2 (32-bit)
 * Generated C source from ".\Prg\Comercio\TComercioStock.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( TCOMERCIOSTOCK );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( TCOMERCIOCONECTOR );
HB_FUNC_STATIC( TCOMERCIOSTOCK_BUILDLISTPRODUCTTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_CALCULATESTOCKSPRODUCTSTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_CALCULATESTOCKSPRODUCTTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_ADDSTOCKPRODUCTTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTSTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTSTOCKTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_CREATECOMMANDPRODUCTSTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_CREATECOMMANDPRODUCTTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_GETCOMMANDPRODUCTTOUPDATE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_INSERTPRODUCTSTOUPADATESTOCKS );
HB_FUNC_STATIC( TCOMERCIOSTOCK_APPENDPRODUCTSTOUPADATESTOCKS );
HB_FUNC_STATIC( TCOMERCIOSTOCK_UPDATEWEBPRODUCTSTOCKS );
HB_FUNC_STATIC( TCOMERCIOSTOCK_GETIDATTRIBUTEPRODUCTSTOCK );
HB_FUNC_STATIC( TCOMERCIOSTOCK_UPDATEPRODUCTSTOCKS );
HB_FUNC_STATIC( TCOMERCIOSTOCK_IDPRODUCTATTRIBUTE );
HB_FUNC_STATIC( TCOMERCIOSTOCK_EVALPRODUCTSTOSTOCK );
HB_FUNC_STATIC( TCOMERCIOSTOCK_GETIDPRODUCTPRESTASHOP );
HB_FUNC_STATIC( TCOMERCIOSTOCK_EXECUTEMULTICOMMAND );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( D );
HB_FUNC_EXTERN( ORDSETFOCUS );
HB_FUNC_EXTERN( DBSEEK );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( EOF );
HB_FUNC_EXTERN( SPACE );
HB_FUNC_EXTERN( DBSKIP );
HB_FUNC_EXTERN( MSGSTOP );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( HSCAN );
HB_FUNC_EXTERN( HSET );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC_EXTERN( HGET );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( TWAITMETER );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( AEVAL );
HB_FUNC_EXTERN( HEVAL );
HB_FUNC_EXTERN( HHASKEY );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( TCOMERCIOCONFIG );
HB_FUNC_EXTERN( TMSQUERY );
HB_FUNC_EXTERN( HB_ATOKENS );
HB_FUNC_EXTERN( FW_GT );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_TCOMERCIOSTOCK )
{ "TCOMERCIOSTOCK", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "TCOMERCIOCONECTOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCOMERCIOCONECTOR )}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDINLINE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HPRODUCTSTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HPRODUCTSTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOSTOCK_BUILDLISTPRODUCTTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_BUILDLISTPRODUCTTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_CALCULATESTOCKSPRODUCTSTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_CALCULATESTOCKSPRODUCTSTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_CALCULATESTOCKSPRODUCTTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_CALCULATESTOCKSPRODUCTTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_ADDSTOCKPRODUCTTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_ADDSTOCKPRODUCTTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTSTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTSTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTSTOCKTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTSTOCKTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_CREATECOMMANDPRODUCTSTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_CREATECOMMANDPRODUCTSTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_CREATECOMMANDPRODUCTTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_CREATECOMMANDPRODUCTTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_GETCOMMANDPRODUCTTOUPDATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_GETCOMMANDPRODUCTTOUPDATE )}, NULL },
{ "TCOMERCIOSTOCK_INSERTPRODUCTSTOUPADATESTOCKS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_INSERTPRODUCTSTOUPADATESTOCKS )}, NULL },
{ "TCOMERCIOSTOCK_APPENDPRODUCTSTOUPADATESTOCKS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_APPENDPRODUCTSTOUPADATESTOCKS )}, NULL },
{ "TCOMERCIOSTOCK_UPDATEWEBPRODUCTSTOCKS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_UPDATEWEBPRODUCTSTOCKS )}, NULL },
{ "TCOMERCIOSTOCK_GETIDATTRIBUTEPRODUCTSTOCK", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_GETIDATTRIBUTEPRODUCTSTOCK )}, NULL },
{ "TCOMERCIOSTOCK_UPDATEPRODUCTSTOCKS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_UPDATEPRODUCTSTOCKS )}, NULL },
{ "TCOMERCIOSTOCK_IDPRODUCTATTRIBUTE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_IDPRODUCTATTRIBUTE )}, NULL },
{ "TCOMERCIOSTOCK_EVALPRODUCTSTOSTOCK", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_EVALPRODUCTSTOSTOCK )}, NULL },
{ "TCOMERCIOSTOCK_GETIDPRODUCTPRESTASHOP", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_GETIDPRODUCTPRESTASHOP )}, NULL },
{ "TCOMERCIOSTOCK_EXECUTEMULTICOMMAND", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TCOMERCIOSTOCK_EXECUTEMULTICOMMAND )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RESETPRODUCTSTOUPDATESTOCKS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ARTICULOS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "D", {HB_FS_PUBLIC}, {HB_FUNCNAME( D )}, NULL },
{ "GETVIEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ORDSETFOCUS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ORDSETFOCUS )}, NULL },
{ "DBSEEK", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBSEEK )}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "CWEBSHOP", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "GETCURRENTWEBNAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC}, {HB_FUNCNAME( EOF )}, NULL },
{ "WRITETEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CODIGO", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "SPACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SPACE )}, NULL },
{ "NOMBRE", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "GETIDPRODUCTPRESTASHOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INSERTPRODUCTSTOUPADATESTOCKS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DBSKIP", {HB_FS_PUBLIC}, {HB_FUNCNAME( DBSKIP )}, NULL },
{ "MSGSTOP", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGSTOP )}, NULL },
{ "GOTOARTICULOS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "HSCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( HSCAN )}, NULL },
{ "HSET", {HB_FS_PUBLIC}, {HB_FUNCNAME( HSET )}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "HGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( HGET )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "ISREALTIMECONEXION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOCONFIG", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_OWAITMETER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RUN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TWAITMETER", {HB_FS_PUBLIC}, {HB_FUNCNAME( TWAITMETER )}, NULL },
{ "CALCULATESTOCKSPRODUCTSTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CREATECOMMANDPRODUCTSTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OWAITMETER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETCURRENTWEBNAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CALCULATESTOCKSPRODUCTTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETIDATTRIBUTEPRODUCTSTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SETMESSAGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ASTOCKARTICULO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSTOCK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETSTORE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODIGO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODIGOPROPIEDAD1", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CVALORPROPIEDAD1", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CCODIGOPROPIEDAD2", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CVALORPROPIEDAD2", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NUNIDADES", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "METERPROCESOSETTOTAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "SETIDATTRIBUTEPRODUCTTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "METERPROCESOTEXT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "AEVAL", {HB_FS_PUBLIC}, {HB_FUNCNAME( AEVAL )}, NULL },
{ "SETIDATTRIBUTEPRODUCTSTOCKTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETVALUEATTRIBUTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TPRESTASHOPID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "IDPRODUCTATTRIBUTE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HEVAL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HEVAL )}, NULL },
{ "CREATECOMMANDPRODUCTTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PRESTASHOPCONNECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETCOMMANDPRODUCTTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EXECUTEMULTICOMMAND", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SAVELASTINSERTSTOCK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIO", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "PRESTASHOPDISCONNECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HHASKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HHASKEY )}, NULL },
{ "CPREFIXTABLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "GETVALUEPRODUCTATTRIBUTECOMBINATION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ISDELETEWITHOUTSTOCK", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "TCOMERCIOCONFIG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TCOMERCIOCONFIG )}, NULL },
{ "TMSQUERY", {HB_FS_PUBLIC}, {HB_FUNCNAME( TMSQUERY )}, NULL },
{ "OCONEXIONMYSQLDATABASE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPEN", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RECCOUNT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GOTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FIELDGET", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "SKIP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDSTOCKPRODUCTTOUPDATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "UPDATEPRODUCTSTOCKS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "GETVALUEPRODUCT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HB_ATOKENS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ATOKENS )}, NULL },
{ "COMMANDEXECDIRECT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FW_GT", {HB_FS_PUBLIC}, {HB_FUNCNAME( FW_GT )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_TCOMERCIOSTOCK, ".\\Prg\\Comercio\\TComercioStock.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_TCOMERCIOSTOCK
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_TCOMERCIOSTOCK )
   #include "hbiniseg.h"
#endif

HB_FUNC( TCOMERCIOSTOCK )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,119,0,36,9,0,103,2,0,100,8,
		29,96,5,176,1,0,104,2,0,12,1,29,85,5,
		166,23,5,0,122,80,1,48,2,0,176,3,0,12,
		0,106,15,84,67,111,109,101,114,99,105,111,83,116,
		111,99,107,0,108,4,4,1,0,108,0,112,3,80,
		2,36,11,0,48,5,0,95,2,100,100,95,1,121,
		72,121,72,121,72,106,10,84,67,111,109,101,114,99,
		105,111,0,4,1,0,9,112,5,73,36,13,0,48,
		5,0,95,2,100,100,95,1,121,72,121,72,121,72,
		106,11,111,87,97,105,116,77,101,116,101,114,0,4,
		1,0,9,112,5,73,36,15,0,48,5,0,95,2,
		100,4,0,0,95,1,121,72,121,72,121,72,106,26,
		101,120,116,101,114,110,97,108,115,80,114,111,100,117,
		99,116,115,84,111,85,112,100,97,116,101,0,4,1,
		0,9,112,5,73,36,16,0,48,5,0,95,2,100,
		177,0,0,95,1,121,72,121,72,121,72,106,18,104,
		80,114,111,100,117,99,116,115,84,111,85,112,100,97,
		116,101,0,4,1,0,9,112,5,73,36,18,0,48,
		6,0,95,2,106,28,114,101,115,101,116,80,114,111,
		100,117,99,116,115,84,111,85,112,100,97,116,101,83,
		116,111,99,107,115,0,89,18,0,1,0,0,0,48,
		7,0,95,1,177,0,0,112,1,6,95,1,121,72,
		121,72,121,72,112,3,73,36,19,0,48,6,0,95,
		2,106,27,103,101,116,80,114,111,100,117,99,116,115,
		84,111,85,112,97,100,97,116,101,83,116,111,99,107,
		115,0,89,15,0,1,0,0,0,48,8,0,95,1,
		112,0,6,95,1,121,72,121,72,121,72,112,3,73,
		36,23,0,48,9,0,95,2,106,25,98,117,105,108,
		100,76,105,115,116,80,114,111,100,117,99,116,84,111,
		85,112,100,97,116,101,0,108,10,95,1,121,72,121,
		72,121,72,112,3,73,36,25,0,48,9,0,95,2,
		106,32,99,97,108,99,117,108,97,116,101,83,116,111,
		99,107,115,80,114,111,100,117,99,116,115,84,111,85,
		112,100,97,116,101,0,108,11,95,1,121,72,121,72,
		121,72,112,3,73,36,26,0,48,9,0,95,2,106,
		31,99,97,108,99,117,108,97,116,101,83,116,111,99,
		107,115,80,114,111,100,117,99,116,84,111,85,112,100,
		97,116,101,0,108,12,95,1,121,72,121,72,121,72,
		112,3,73,36,27,0,48,9,0,95,2,106,24,97,
		100,100,83,116,111,99,107,80,114,111,100,117,99,116,
		84,111,85,112,100,97,116,101,0,108,13,95,1,121,
		72,121,72,121,72,112,3,73,36,29,0,48,9,0,
		95,2,106,31,115,101,116,73,100,65,116,116,114,105,
		98,117,116,101,80,114,111,100,117,99,116,115,84,111,
		85,112,100,97,116,101,0,108,14,95,1,121,72,121,
		72,121,72,112,3,73,36,30,0,48,9,0,95,2,
		106,30,115,101,116,73,100,65,116,116,114,105,98,117,
		116,101,80,114,111,100,117,99,116,84,111,85,112,100,
		97,116,101,0,108,15,95,1,121,72,121,72,121,72,
		112,3,73,36,31,0,48,9,0,95,2,106,35,115,
		101,116,73,100,65,116,116,114,105,98,117,116,101,80,
		114,111,100,117,99,116,83,116,111,99,107,84,111,85,
		112,100,97,116,101,0,108,16,95,1,121,72,121,72,
		121,72,112,3,73,36,33,0,48,9,0,95,2,106,
		30,99,114,101,97,116,101,67,111,109,109,97,110,100,
		80,114,111,100,117,99,116,115,84,111,85,112,100,97,
		116,101,0,108,17,95,1,121,72,121,72,121,72,112,
		3,73,36,34,0,48,9,0,95,2,106,29,99,114,
		101,97,116,101,67,111,109,109,97,110,100,80,114,111,
		100,117,99,116,84,111,85,112,100,97,116,101,0,108,
		18,95,1,121,72,121,72,121,72,112,3,73,36,35,
		0,48,9,0,95,2,106,26,103,101,116,67,111,109,
		109,97,110,100,80,114,111,100,117,99,116,84,111,85,
		112,100,97,116,101,0,108,19,95,1,121,72,121,72,
		121,72,112,3,73,36,37,0,48,9,0,95,2,106,
		30,105,110,115,101,114,116,80,114,111,100,117,99,116,
		115,84,111,85,112,97,100,97,116,101,83,116,111,99,
		107,115,0,108,20,95,1,121,72,121,72,121,72,112,
		3,73,36,41,0,48,9,0,95,2,106,30,97,112,
		112,101,110,100,80,114,111,100,117,99,116,115,84,111,
		85,112,97,100,97,116,101,83,116,111,99,107,115,0,
		108,21,95,1,121,72,121,72,121,72,112,3,73,36,
		43,0,48,9,0,95,2,106,23,117,112,100,97,116,
		101,87,101,98,80,114,111,100,117,99,116,83,116,111,
		99,107,115,0,108,22,95,1,121,72,121,72,121,72,
		112,3,73,36,47,0,48,9,0,95,2,106,27,103,
		101,116,73,100,65,116,116,114,105,98,117,116,101,80,
		114,111,100,117,99,116,83,116,111,99,107,0,108,23,
		95,1,121,72,121,72,121,72,112,3,73,36,49,0,
		48,9,0,95,2,106,20,117,112,100,97,116,101,80,
		114,111,100,117,99,116,83,116,111,99,107,115,0,108,
		24,95,1,121,72,121,72,121,72,112,3,73,36,51,
		0,48,9,0,95,2,106,19,105,100,80,114,111,100,
		117,99,116,65,116,116,114,105,98,117,116,101,0,108,
		25,95,1,121,72,121,72,121,72,112,3,73,36,53,
		0,48,9,0,95,2,106,20,101,118,97,108,80,114,
		111,100,117,99,116,115,84,111,83,116,111,99,107,0,
		108,26,95,1,121,72,121,72,121,72,112,3,73,36,
		55,0,48,9,0,95,2,106,23,103,101,116,73,100,
		80,114,111,100,117,99,116,80,114,101,115,116,97,115,
		104,111,112,0,108,27,95,1,121,72,121,72,121,72,
		112,3,73,36,57,0,48,9,0,95,2,106,20,101,
		120,101,99,117,116,101,77,117,108,116,105,67,111,109,
		109,97,110,100,0,108,28,95,1,121,72,121,72,121,
		72,112,3,73,36,59,0,48,29,0,95,2,112,0,
		73,167,14,0,0,176,30,0,104,2,0,95,2,20,
		2,168,48,31,0,95,2,112,0,80,3,176,32,0,
		95,3,106,10,73,110,105,116,67,108,97,115,115,0,
		12,2,28,12,48,33,0,95,3,164,146,1,0,73,
		95,3,110,7,48,31,0,103,2,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_BUILDLISTPRODUCTTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,68,0,48,34,0,102,112,0,73,36,
		70,0,85,48,35,0,176,36,0,12,0,48,37,0,
		102,112,0,112,1,74,176,38,0,106,9,108,87,101,
		98,83,104,111,112,0,20,1,74,36,72,0,85,48,
		35,0,176,36,0,12,0,48,37,0,102,112,0,112,
		1,74,176,39,0,95,1,12,1,119,29,245,0,36,
		74,0,176,40,0,48,35,0,176,36,0,12,0,48,
		37,0,102,112,0,112,1,88,41,0,12,1,48,42,
		0,102,112,0,8,29,238,0,85,48,35,0,176,36,
		0,12,0,48,37,0,102,112,0,112,1,74,176,43,
		0,12,0,119,32,211,0,36,76,0,48,44,0,102,
		176,40,0,48,35,0,176,36,0,12,0,48,37,0,
		102,112,0,112,1,88,45,0,12,1,176,46,0,122,
		12,1,72,176,40,0,48,35,0,176,36,0,12,0,
		48,37,0,102,112,0,112,1,88,47,0,12,1,72,
		112,1,73,36,78,0,48,48,0,102,48,35,0,176,
		36,0,12,0,48,37,0,102,112,0,112,1,88,45,
		0,48,42,0,102,112,0,112,2,80,2,36,80,0,
		95,2,121,69,28,39,36,81,0,48,49,0,102,48,
		35,0,176,36,0,12,0,48,37,0,102,112,0,112,
		1,88,45,0,95,2,48,42,0,102,112,0,112,3,
		73,36,84,0,85,48,35,0,176,36,0,12,0,48,
		37,0,102,112,0,112,1,74,176,50,0,20,0,74,
		26,17,255,36,90,0,176,51,0,48,42,0,102,112,
		0,106,14,110,111,32,101,110,99,111,110,116,114,97,
		100,111,0,20,2,36,94,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_APPENDPRODUCTSTOUPADATESTOCKS )
{
	static const HB_BYTE pcode[] =
	{
		13,2,2,36,104,0,48,52,0,176,36,0,12,0,
		95,1,95,2,112,2,28,22,36,105,0,48,35,0,
		176,36,0,12,0,95,2,112,1,88,41,0,80,3,
		36,108,0,176,53,0,95,3,12,1,28,8,36,109,
		0,102,110,7,36,112,0,48,48,0,102,95,1,95,
		3,112,2,80,4,36,114,0,176,53,0,95,4,12,
		1,28,8,36,115,0,102,110,7,36,118,0,48,49,
		0,102,95,1,95,4,95,3,112,3,73,36,120,0,
		102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_INSERTPRODUCTSTOUPADATESTOCKS )
{
	static const HB_BYTE pcode[] =
	{
		13,2,7,36,135,0,106,3,105,100,0,95,1,106,
		20,105,100,80,114,111,100,117,99,116,80,114,101,115,
		116,97,115,104,111,112,0,95,2,106,16,105,100,70,
		105,114,115,116,80,114,111,112,101,114,116,121,0,95,
		4,106,19,118,97,108,117,101,70,105,114,115,116,80,
		114,111,112,101,114,116,121,0,95,5,106,17,105,100,
		83,101,99,111,110,100,80,114,111,112,101,114,116,121,
		0,95,6,106,20,118,97,108,117,101,83,101,99,111,
		110,100,80,114,111,112,101,114,116,121,0,95,7,106,
		11,99,111,109,109,97,110,100,83,81,76,0,106,1,
		0,177,7,0,80,9,36,137,0,176,54,0,48,8,
		0,102,112,0,89,15,0,2,0,1,0,3,0,95,
		1,95,255,8,6,12,2,80,8,36,138,0,95,8,
		121,8,28,26,36,139,0,176,55,0,48,8,0,102,
		112,0,95,3,95,9,4,1,0,20,3,26,213,0,
		36,141,0,176,56,0,48,8,0,102,112,0,95,3,
		1,89,170,0,1,0,5,0,1,0,4,0,5,0,
		6,0,7,0,176,57,0,95,1,106,3,105,100,0,
		12,2,95,255,8,21,29,136,0,73,176,57,0,95,
		1,106,16,105,100,70,105,114,115,116,80,114,111,112,
		101,114,116,121,0,12,2,95,254,8,21,28,103,73,
		176,57,0,95,1,106,19,118,97,108,117,101,70,105,
		114,115,116,80,114,111,112,101,114,116,121,0,12,2,
		95,253,8,21,28,68,73,176,57,0,95,1,106,17,
		105,100,83,101,99,111,110,100,80,114,111,112,101,114,
		116,121,0,12,2,95,252,8,21,28,35,73,176,57,
		0,95,1,106,20,118,97,108,117,101,83,101,99,111,
		110,100,80,114,111,112,101,114,116,121,0,12,2,95,
		251,8,6,12,2,121,8,28,21,36,142,0,176,58,
		0,48,8,0,102,112,0,95,3,1,95,9,20,2,
		36,146,0,48,8,0,102,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_UPDATEWEBPRODUCTSTOCKS )
{
	static const HB_BYTE pcode[] =
	{
		36,152,0,48,59,0,48,60,0,102,112,0,112,0,
		31,8,36,153,0,9,110,7,36,156,0,176,53,0,
		48,8,0,102,112,0,12,1,28,8,36,157,0,9,
		110,7,36,160,0,48,61,0,102,48,62,0,48,2,
		0,176,63,0,12,0,106,20,65,99,116,117,97,108,
		105,122,97,110,100,111,32,115,116,111,99,107,115,0,
		106,20,69,115,112,101,114,101,32,112,111,114,32,102,
		97,118,111,114,46,46,46,0,112,2,112,0,112,1,
		73,36,162,0,48,64,0,102,112,0,73,36,164,0,
		48,65,0,102,112,0,73,36,166,0,48,66,0,48,
		67,0,102,112,0,112,0,73,36,168,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_UPDATEPRODUCTSTOCKS )
{
	static const HB_BYTE pcode[] =
	{
		13,0,2,36,174,0,48,68,0,48,60,0,102,112,
		0,95,1,112,1,73,36,176,0,48,69,0,102,95,
		2,112,1,73,36,178,0,48,70,0,102,112,0,73,
		36,180,0,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_ADDSTOCKPRODUCTTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,11,1,36,187,0,121,80,3,36,189,0,121,80,
		5,36,190,0,4,0,0,80,6,36,191,0,176,57,
		0,95,1,106,3,105,100,0,12,2,80,7,36,192,
		0,176,57,0,95,1,106,20,105,100,80,114,111,100,
		117,99,116,80,114,101,115,116,97,115,104,111,112,0,
		12,2,80,8,36,193,0,176,57,0,95,1,106,16,
		105,100,70,105,114,115,116,80,114,111,112,101,114,116,
		121,0,12,2,80,9,36,194,0,176,57,0,95,1,
		106,19,118,97,108,117,101,70,105,114,115,116,80,114,
		111,112,101,114,116,121,0,12,2,80,10,36,195,0,
		176,57,0,95,1,106,17,105,100,83,101,99,111,110,
		100,80,114,111,112,101,114,116,121,0,12,2,80,11,
		36,196,0,176,57,0,95,1,106,20,118,97,108,117,
		101,83,101,99,111,110,100,80,114,111,112,101,114,116,
		121,0,12,2,80,12,36,198,0,176,53,0,48,67,
		0,102,112,0,12,1,31,46,36,199,0,48,71,0,
		48,67,0,102,112,0,106,19,67,97,108,99,117,108,
		97,110,100,111,32,115,116,111,99,107,115,32,0,176,
		40,0,95,7,12,1,72,112,1,73,36,202,0,48,
		44,0,102,106,19,67,97,108,99,117,108,97,110,100,
		111,32,115,116,111,99,107,115,32,0,176,40,0,95,
		7,12,1,72,112,1,73,36,206,0,48,72,0,48,
		73,0,102,112,0,95,7,48,74,0,48,60,0,102,
		112,0,112,0,112,2,80,4,36,210,0,95,4,96,
		2,0,129,1,1,29,81,1,36,216,0,48,75,0,
		95,2,112,0,95,7,8,29,58,1,176,53,0,95,
		9,12,1,31,15,48,76,0,95,2,112,0,95,9,
		8,29,36,1,176,53,0,95,10,12,1,31,15,48,
		77,0,95,2,112,0,95,10,8,29,14,1,176,53,
		0,95,11,12,1,31,15,48,78,0,95,2,112,0,
		95,11,8,29,248,0,176,53,0,95,12,12,1,31,
		15,48,79,0,95,2,112,0,95,12,8,29,226,0,
		36,220,0,96,3,0,48,80,0,95,2,112,0,135,
		36,222,0,176,53,0,48,77,0,95,2,112,0,12,
		1,28,17,176,53,0,48,79,0,95,2,112,0,12,
		1,32,180,0,36,230,0,176,58,0,95,6,106,10,
		105,100,80,114,111,100,117,99,116,0,95,7,106,19,
		105,100,80,114,111,100,117,99,116,65,116,116,114,105,
		98,117,116,101,0,95,5,106,16,105,100,70,105,114,
		115,116,80,114,111,112,101,114,116,121,0,48,76,0,
		95,2,112,0,106,17,105,100,83,101,99,111,110,100,
		80,114,111,112,101,114,116,121,0,48,78,0,95,2,
		112,0,106,19,118,97,108,117,101,70,105,114,115,116,
		80,114,111,112,101,114,116,121,0,48,77,0,95,2,
		112,0,106,20,118,97,108,117,101,83,101,99,111,110,
		100,80,114,111,112,101,114,116,121,0,48,79,0,95,
		2,112,0,106,10,117,110,105,116,83,116,111,99,107,
		0,48,80,0,95,2,112,0,177,7,0,20,2,36,
		238,0,130,32,181,254,132,36,242,0,121,80,5,36,
		250,0,176,58,0,95,6,106,10,105,100,80,114,111,
		100,117,99,116,0,95,7,106,19,105,100,80,114,111,
		100,117,99,116,65,116,116,114,105,98,117,116,101,0,
		95,5,106,16,105,100,70,105,114,115,116,80,114,111,
		112,101,114,116,121,0,176,46,0,92,20,12,1,106,
		17,105,100,83,101,99,111,110,100,80,114,111,112,101,
		114,116,121,0,176,46,0,92,20,12,1,106,19,118,
		97,108,117,101,70,105,114,115,116,80,114,111,112,101,
		114,116,121,0,176,46,0,92,20,12,1,106,20,118,
		97,108,117,101,83,101,99,111,110,100,80,114,111,112,
		101,114,116,121,0,176,46,0,92,20,12,1,106,10,
		117,110,105,116,83,116,111,99,107,0,95,3,177,7,
		0,20,2,36,252,0,176,55,0,95,1,106,7,115,
		116,111,99,107,115,0,95,6,20,3,36,254,0,120,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTSTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,6,1,48,81,0,102,176,82,0,48,
		8,0,102,112,0,12,1,112,1,73,36,8,1,48,
		8,0,102,112,0,96,1,0,129,1,1,28,30,36,
		10,1,48,83,0,102,95,1,112,1,73,36,12,1,
		48,84,0,102,112,0,73,36,14,1,130,31,230,132,
		36,16,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,20,1,102,80,2,36,22,1,176,85,
		0,176,57,0,95,1,106,7,115,116,111,99,107,115,
		0,12,2,89,24,0,1,0,2,0,2,0,1,0,
		48,86,0,95,255,95,254,96,1,0,112,2,6,20,
		2,36,24,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_SETIDATTRIBUTEPRODUCTSTOCKTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,3,2,36,30,1,121,80,3,36,31,1,121,80,
		4,36,32,1,121,80,5,36,34,1,176,53,0,176,
		57,0,95,2,106,19,118,97,108,117,101,70,105,114,
		115,116,80,114,111,112,101,114,116,121,0,12,2,12,
		1,31,78,36,35,1,48,87,0,48,88,0,102,112,
		0,176,57,0,95,2,106,16,105,100,70,105,114,115,
		116,80,114,111,112,101,114,116,121,0,12,2,176,57,
		0,95,2,106,19,118,97,108,117,101,70,105,114,115,
		116,80,114,111,112,101,114,116,121,0,12,2,72,48,
		42,0,102,112,0,112,2,80,4,36,38,1,176,53,
		0,176,57,0,95,2,106,20,118,97,108,117,101,83,
		101,99,111,110,100,80,114,111,112,101,114,116,121,0,
		12,2,12,1,31,80,36,39,1,48,87,0,48,88,
		0,102,112,0,176,57,0,95,2,106,17,105,100,83,
		101,99,111,110,100,80,114,111,112,101,114,116,121,0,
		12,2,176,57,0,95,2,106,20,118,97,108,117,101,
		83,101,99,111,110,100,80,114,111,112,101,114,116,121,
		0,12,2,72,48,42,0,102,112,0,112,2,80,5,
		36,42,1,95,4,121,69,28,52,95,5,121,69,28,
		46,36,43,1,48,89,0,102,176,57,0,95,1,106,
		20,105,100,80,114,111,100,117,99,116,80,114,101,115,
		116,97,115,104,111,112,0,12,2,95,4,95,5,112,
		3,80,3,36,46,1,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_GETIDATTRIBUTEPRODUCTSTOCK )
{
	static const HB_BYTE pcode[] =
	{
		13,3,5,36,52,1,121,80,6,36,53,1,121,80,
		7,36,54,1,121,80,8,36,56,1,95,2,100,8,
		28,11,176,46,0,92,20,12,1,80,2,36,57,1,
		95,3,100,8,28,11,176,46,0,92,20,12,1,80,
		3,36,58,1,95,4,100,8,28,11,176,46,0,92,
		20,12,1,80,4,36,59,1,95,5,100,8,28,11,
		176,46,0,92,20,12,1,80,5,36,61,1,176,53,
		0,95,3,12,1,31,29,36,62,1,48,87,0,48,
		88,0,102,112,0,95,2,95,3,72,48,42,0,102,
		112,0,112,2,80,7,36,65,1,176,53,0,95,5,
		12,1,31,29,36,66,1,48,87,0,48,88,0,102,
		112,0,95,4,95,5,72,48,42,0,102,112,0,112,
		2,80,8,36,69,1,95,7,121,69,31,8,95,8,
		121,69,28,19,36,70,1,48,89,0,102,95,1,95,
		7,95,8,112,3,80,6,36,73,1,95,6,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_CREATECOMMANDPRODUCTSTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,77,1,102,80,1,36,79,1,176,90,
		0,48,8,0,95,1,112,0,89,21,0,2,0,1,
		0,1,0,48,91,0,95,255,95,1,95,2,112,2,
		6,20,2,36,81,1,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_CREATECOMMANDPRODUCTTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,2,2,36,90,1,48,68,0,48,60,0,102,112,
		0,95,1,112,1,73,36,92,1,48,81,0,102,176,
		82,0,48,8,0,102,112,0,12,1,112,1,73,36,
		94,1,48,92,0,102,112,0,28,114,36,96,1,95,
		2,96,4,0,129,1,1,28,84,36,98,1,176,53,
		0,95,4,12,1,31,66,36,100,1,48,93,0,102,
		95,4,112,1,80,3,36,102,1,176,53,0,95,3,
		12,1,31,14,36,103,1,48,94,0,102,95,3,112,
		1,73,36,106,1,48,95,0,48,96,0,102,112,0,
		176,57,0,95,4,106,3,105,100,0,12,2,112,1,
		73,36,110,1,130,31,176,132,36,112,1,48,97,0,
		102,112,0,73,36,114,1,120,110,7,36,118,1,120,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_GETCOMMANDPRODUCTTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,6,1,36,127,1,106,1,0,80,5,36,128,1,
		121,80,6,36,129,1,121,80,7,36,131,1,176,98,
		0,95,1,106,7,115,116,111,99,107,115,0,12,2,
		31,9,36,132,1,95,5,110,7,36,135,1,176,57,
		0,95,1,106,7,115,116,111,99,107,115,0,12,2,
		80,3,36,138,1,96,5,0,106,13,68,69,76,69,
		84,69,32,70,82,79,77,32,0,48,99,0,102,106,
		16,115,116,111,99,107,95,97,118,97,105,108,97,98,
		108,101,0,112,1,72,106,21,32,87,72,69,82,69,
		32,105,100,95,112,114,111,100,117,99,116,32,61,32,
		0,72,176,40,0,176,100,0,176,57,0,95,1,106,
		20,105,100,80,114,111,100,117,99,116,80,114,101,115,
		116,97,115,104,111,112,0,12,2,12,1,12,1,72,
		106,2,59,0,72,135,36,140,1,95,3,96,4,0,
		129,1,1,29,36,3,36,142,1,48,101,0,48,88,
		0,102,112,0,176,57,0,95,1,106,3,105,100,0,
		12,2,176,57,0,95,4,106,16,105,100,70,105,114,
		115,116,80,114,111,112,101,114,116,121,0,12,2,72,
		176,57,0,95,4,106,19,118,97,108,117,101,70,105,
		114,115,116,80,114,111,112,101,114,116,121,0,12,2,
		72,176,57,0,95,4,106,17,105,100,83,101,99,111,
		110,100,80,114,111,112,101,114,116,121,0,12,2,72,
		176,57,0,95,4,106,20,118,97,108,117,101,83,101,
		99,111,110,100,80,114,111,112,101,114,116,121,0,12,
		2,72,48,42,0,102,112,0,112,2,80,7,36,161,
		1,96,5,0,106,13,73,78,83,69,82,84,32,73,
		78,84,79,32,0,48,99,0,102,106,16,115,116,111,
		99,107,95,97,118,97,105,108,97,98,108,101,0,112,
		1,72,106,4,32,40,32,0,72,106,13,105,100,95,
		112,114,111,100,117,99,116,44,32,0,72,106,23,105,
		100,95,112,114,111,100,117,99,116,95,97,116,116,114,
		105,98,117,116,101,44,32,0,72,106,10,105,100,95,
		115,104,111,112,44,32,0,72,106,16,105,100,95,115,
		104,111,112,95,103,114,111,117,112,44,32,0,72,106,
		11,113,117,97,110,116,105,116,121,44,32,0,72,106,
		19,100,101,112,101,110,100,115,95,111,110,95,115,116,
		111,99,107,44,32,0,72,106,16,111,117,116,95,111,
		102,95,115,116,111,99,107,32,41,32,0,72,106,10,
		86,65,76,85,69,83,32,40,32,0,72,106,2,39,
		0,72,176,40,0,176,100,0,176,57,0,95,1,106,
		20,105,100,80,114,111,100,117,99,116,80,114,101,115,
		116,97,115,104,111,112,0,12,2,12,1,12,1,72,
		106,4,39,44,32,0,72,106,2,39,0,72,176,40,
		0,176,100,0,95,7,12,1,12,1,72,106,4,39,
		44,32,0,72,106,6,39,49,39,44,32,0,72,106,
		6,39,48,39,44,32,0,72,106,2,39,0,72,176,
		40,0,176,100,0,176,57,0,95,4,106,10,117,110,
		105,116,83,116,111,99,107,0,12,2,12,1,12,1,
		72,106,4,39,44,32,0,72,106,6,39,48,39,44,
		32,0,72,106,6,39,50,39,32,41,0,72,106,2,
		59,0,72,135,36,163,1,96,6,0,176,57,0,95,
		4,106,10,117,110,105,116,83,116,111,99,107,0,12,
		2,135,36,167,1,106,33,65,99,116,117,97,108,105,
		122,97,110,100,111,32,115,116,111,99,107,44,32,112,
		114,111,112,105,101,100,97,100,101,115,32,0,80,2,
		36,168,1,96,2,0,176,40,0,176,57,0,95,1,
		106,3,105,100,0,12,2,12,1,106,3,44,32,0,
		72,135,36,169,1,96,2,0,176,40,0,176,100,0,
		176,57,0,95,1,106,20,105,100,80,114,111,100,117,
		99,116,80,114,101,115,116,97,115,104,111,112,0,12,
		2,12,1,12,1,106,3,44,32,0,72,135,36,170,
		1,96,2,0,176,40,0,176,57,0,95,4,106,19,
		118,97,108,117,101,70,105,114,115,116,80,114,111,112,
		101,114,116,121,0,12,2,12,1,106,3,44,32,0,
		72,135,36,171,1,96,2,0,176,40,0,176,57,0,
		95,4,106,20,118,97,108,117,101,83,101,99,111,110,
		100,80,114,111,112,101,114,116,121,0,12,2,12,1,
		106,3,44,32,0,72,135,36,172,1,96,2,0,106,
		12,99,97,110,116,105,100,97,100,32,58,32,0,176,
		40,0,176,100,0,176,57,0,95,4,106,10,117,110,
		105,116,83,116,111,99,107,0,12,2,12,1,12,1,
		72,135,36,175,1,130,32,226,252,132,36,177,1,95,
		6,121,34,29,8,1,48,102,0,176,103,0,12,0,
		112,0,29,251,0,36,181,1,106,9,85,80,68,65,
		84,69,32,32,0,48,99,0,102,106,8,112,114,111,
		100,117,99,116,0,112,1,72,106,29,32,83,69,84,
		32,97,99,116,105,118,101,32,61,32,48,44,32,105,
		110,100,101,120,101,100,32,61,32,48,0,72,106,22,
		32,87,72,69,82,69,32,105,100,95,112,114,111,100,
		117,99,116,32,61,32,39,0,72,176,40,0,176,100,
		0,176,57,0,95,1,106,20,105,100,80,114,111,100,
		117,99,116,80,114,101,115,116,97,115,104,111,112,0,
		12,2,12,1,12,1,72,106,3,39,59,0,72,80,
		5,36,183,1,106,23,68,101,115,97,99,116,105,118,
		97,110,100,111,32,97,114,116,237,99,117,108,111,32,
		0,80,2,36,184,1,96,2,0,176,40,0,176,57,
		0,95,1,106,3,105,100,0,12,2,12,1,106,3,
		44,32,0,72,135,36,185,1,96,2,0,176,40,0,
		176,100,0,176,57,0,95,1,106,20,105,100,80,114,
		111,100,117,99,116,80,114,101,115,116,97,115,104,111,
		112,0,12,2,12,1,12,1,106,3,44,32,0,72,
		135,36,189,1,176,53,0,48,67,0,102,112,0,12,
		1,31,19,36,190,1,48,71,0,48,67,0,102,112,
		0,95,2,112,1,73,36,193,1,48,44,0,102,95,
		2,112,1,73,36,195,1,95,5,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_IDPRODUCTATTRIBUTE )
{
	static const HB_BYTE pcode[] =
	{
		13,6,3,36,203,1,9,80,6,36,204,1,9,80,
		7,36,205,1,106,1,0,80,8,36,206,1,121,80,
		9,36,209,1,176,53,0,95,2,12,1,32,142,1,
		176,53,0,95,3,12,1,29,132,1,36,211,1,106,
		15,83,69,76,69,67,84,32,42,32,70,82,79,77,
		32,0,48,99,0,102,106,18,112,114,111,100,117,99,
		116,95,97,116,116,114,105,98,117,116,101,0,112,1,
		72,106,21,32,87,72,69,82,69,32,105,100,95,112,
		114,111,100,117,99,116,32,61,32,0,72,176,40,0,
		176,100,0,95,1,12,1,12,1,72,80,8,36,213,
		1,48,44,0,102,95,8,112,1,73,36,215,1,48,
		2,0,176,104,0,12,0,48,105,0,102,112,0,95,
		8,112,2,80,4,36,217,1,48,106,0,95,4,112,
		0,29,14,3,48,107,0,95,4,112,0,121,15,29,
		2,3,36,219,1,48,108,0,95,4,112,0,73,36,
		220,1,48,109,0,95,4,112,0,32,234,2,36,222,
		1,106,15,83,69,76,69,67,84,32,42,32,70,82,
		79,77,32,0,48,99,0,102,106,30,112,114,111,100,
		117,99,116,95,97,116,116,114,105,98,117,116,101,95,
		99,111,109,98,105,110,97,116,105,111,110,0,112,1,
		72,106,31,32,87,72,69,82,69,32,105,100,95,112,
		114,111,100,117,99,116,95,97,116,116,114,105,98,117,
		116,101,32,61,32,0,72,176,40,0,176,100,0,48,
		110,0,95,4,122,112,1,12,1,12,1,72,80,8,
		36,224,1,48,44,0,102,95,8,112,1,73,36,226,
		1,48,2,0,176,104,0,12,0,48,105,0,102,112,
		0,95,8,112,2,80,5,36,228,1,48,106,0,95,
		5,112,0,28,42,48,107,0,95,5,112,0,122,8,
		28,31,48,110,0,95,5,122,112,1,95,2,8,28,
		18,36,229,1,48,110,0,95,4,122,112,1,80,9,
		26,33,2,36,233,1,48,111,0,95,4,112,0,73,
		26,31,255,36,239,1,176,53,0,95,2,12,1,32,
		6,2,176,53,0,95,3,12,1,32,252,1,36,241,
		1,106,15,83,69,76,69,67,84,32,42,32,70,82,
		79,77,32,0,48,99,0,102,106,18,112,114,111,100,
		117,99,116,95,97,116,116,114,105,98,117,116,101,0,
		112,1,72,106,21,32,87,72,69,82,69,32,105,100,
		95,112,114,111,100,117,99,116,32,61,32,0,72,176,
		40,0,176,100,0,95,1,12,1,12,1,72,80,8,
		36,243,1,48,44,0,102,95,8,112,1,73,36,245,
		1,48,2,0,176,104,0,12,0,48,105,0,102,112,
		0,95,8,112,2,80,4,36,247,1,48,106,0,95,
		4,112,0,29,118,1,36,249,1,48,108,0,95,4,
		112,0,73,36,250,1,48,109,0,95,4,112,0,32,
		94,1,36,252,1,106,15,83,69,76,69,67,84,32,
		42,32,70,82,79,77,32,0,48,99,0,102,106,30,
		112,114,111,100,117,99,116,95,97,116,116,114,105,98,
		117,116,101,95,99,111,109,98,105,110,97,116,105,111,
		110,0,112,1,72,106,29,32,87,72,69,82,69,32,
		105,100,95,112,114,111,100,117,99,116,95,97,116,116,
		114,105,98,117,116,101,61,0,72,176,40,0,176,100,
		0,48,110,0,95,4,122,112,1,12,1,12,1,72,
		80,8,36,254,1,48,44,0,102,95,8,112,1,73,
		36,0,2,48,2,0,176,104,0,12,0,48,105,0,
		102,112,0,95,8,112,2,80,5,36,2,2,48,106,
		0,95,5,112,0,29,164,0,48,107,0,95,5,112,
		0,92,2,8,29,151,0,36,4,2,48,108,0,95,
		5,112,0,73,36,5,2,48,109,0,95,5,112,0,
		31,40,36,7,2,95,6,31,20,36,8,2,48,110,
		0,95,5,122,112,1,95,2,8,80,6,25,15,36,
		12,2,48,111,0,95,5,112,0,73,25,208,36,16,
		2,48,108,0,95,5,112,0,73,36,17,2,48,109,
		0,95,5,112,0,31,40,36,19,2,95,7,31,20,
		36,20,2,48,110,0,95,5,122,112,1,95,3,8,
		80,7,25,15,36,24,2,48,111,0,95,5,112,0,
		73,25,208,36,28,2,95,6,28,21,95,7,28,17,
		36,29,2,48,110,0,95,4,122,112,1,80,9,25,
		28,36,35,2,48,111,0,95,4,112,0,73,36,37,
		2,9,80,6,36,38,2,9,80,7,26,155,254,36,
		46,2,95,9,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_CALCULATESTOCKSPRODUCTSTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,50,2,102,80,1,36,52,2,176,90,
		0,48,8,0,95,1,112,0,89,21,0,2,0,1,
		0,1,0,48,69,0,95,255,95,1,95,2,112,2,
		6,20,2,36,54,2,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_CALCULATESTOCKSPRODUCTTOUPDATE )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,62,2,48,81,0,102,176,82,0,95,
		2,12,1,112,1,73,36,64,2,95,2,96,3,0,
		129,1,1,28,30,36,66,2,48,112,0,102,95,3,
		112,1,73,36,68,2,48,84,0,102,112,0,73,36,
		70,2,130,31,230,132,36,72,2,9,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_EVALPRODUCTSTOSTOCK )
{
	static const HB_BYTE pcode[] =
	{
		13,1,0,36,76,2,102,80,1,36,78,2,48,92,
		0,95,1,112,0,28,49,36,80,2,176,90,0,48,
		8,0,95,1,112,0,89,21,0,2,0,1,0,1,
		0,48,113,0,95,255,95,1,95,2,112,2,6,20,
		2,36,82,2,48,97,0,95,1,112,0,73,36,86,
		2,95,1,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_GETIDPRODUCTPRESTASHOP )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,36,92,2,48,114,0,48,88,0,102,112,
		0,95,1,95,2,112,2,80,3,36,94,2,95,3,
		121,8,28,69,36,95,2,48,44,0,102,106,10,80,
		114,111,100,117,99,116,111,32,0,176,40,0,95,1,
		12,1,72,106,26,32,110,111,32,101,110,99,111,110,
		116,114,97,100,111,32,101,110,32,108,97,32,119,101,
		98,32,0,72,176,40,0,95,2,12,1,72,112,1,
		73,36,98,2,95,3,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TCOMERCIOSTOCK_EXECUTEMULTICOMMAND )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,36,105,2,176,115,0,95,1,106,2,59,
		0,12,2,80,3,36,107,2,95,3,96,2,0,129,
		1,1,28,32,36,109,2,176,53,0,95,2,12,1,
		31,14,36,110,2,48,116,0,102,95,2,112,1,73,
		36,113,2,130,31,228,132,36,115,2,102,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,119,0,2,0,116,119,0,4,0,0,82,1,0,
		7
	};

	hb_vmExecute( pcode, symbols );
}

