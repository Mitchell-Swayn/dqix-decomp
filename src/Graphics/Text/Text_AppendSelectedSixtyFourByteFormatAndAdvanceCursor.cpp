#include <globaldefs.h>
extern "C" int Text_ParseIntegerFromFirstDecimalDigit(void*);extern "C" int sprintf(char*,const char*,...);
#pragma optimization_level 4
// Original: arm9/main @ 0x020691F8; symbol: func_020691f8; size: 0x3C.
extern "C" ARM void Text_AppendSelectedSixtyFourByteFormatAndAdvanceCursor(void* a,char** out,char* base){int n=Text_ParseIntegerFromFirstDecimalDigit(a)-1;char* fmt=base+0x4ac+n*64;if(!fmt)return;*out+=sprintf(*out,fmt);}
