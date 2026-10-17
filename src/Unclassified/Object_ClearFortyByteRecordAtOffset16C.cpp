#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* Object_Clear40Bytes(void*);
// Original: arm9/main @ 0x0202EE84; symbol: func_0202ee84; size: 0x10.
extern "C" void* Object_ClearFortyByteRecordAtOffset16C(unsigned char* p){return Object_Clear40Bytes(p+364);}
