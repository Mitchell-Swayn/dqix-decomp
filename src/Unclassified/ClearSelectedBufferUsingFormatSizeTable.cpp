#include <globaldefs.h>
ARM
extern "C" unsigned int data_020e7b98[][4];extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x0204B010; symbol: func_0204b010; size: 0x3C.
extern "C" void ClearSelectedBufferUsingFormatSizeTable(unsigned char* p,void* buffer) { if(!buffer)buffer=*(void**)(p+0x14);if(!buffer)return;memset(buffer,0,data_020e7b98[p[0x1f]][*(unsigned int*)(p+0x18)]); }
