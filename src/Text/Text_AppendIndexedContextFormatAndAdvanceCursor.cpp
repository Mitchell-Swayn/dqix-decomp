#include <globaldefs.h>
extern "C" int Text_ParseIntegerFromFirstDecimalDigit(const signed char*); extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x020691C0; symbol: func_020691c0; size: 0x38.
extern "C" ARM void Text_AppendIndexedContextFormatAndAdvanceCursor(const signed char* input,char** out,char* base){int n=Text_ParseIntegerFromFirstDecimalDigit(input)-1; char* format=base+0x2ec+n*64; if(!format)return; *out+=sprintf(*out,format);}
