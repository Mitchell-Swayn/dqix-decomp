#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Text_CopyBoundedNullTerminatedString(const char*,char*,unsigned);
// Original: arm9/main @ 0x0204653C; symbol: func_0204653c; size: 0x1C.
extern "C" void CopyBoundedTextIntoFieldAtOffset42C(unsigned char* p,const char* text){Text_CopyBoundedNullTerminatedString(text,(char*)p+0x42c,64);}
