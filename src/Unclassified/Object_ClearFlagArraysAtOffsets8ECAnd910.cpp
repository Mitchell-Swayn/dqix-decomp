#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x02083C18; symbol: func_02083c18; size: 0x30.
extern "C" void Object_ClearFlagArraysAtOffsets8ECAnd910(unsigned char* p) { memset(p+0x8ec,0,0x24);memset(p+0x910,0,9); }
