#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x02079F9C; symbol: func_02079f9c; size: 0x2C.
 extern "C" void ResourceIndex_ClearAlternateLookupTables(unsigned char* p) { memset(p+0xc,0,12);memset(p+0x24,0,12); }
