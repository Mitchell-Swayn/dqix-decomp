#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x02069ED4; symbol: func_02069ed4; size: 0x28.
extern "C" unsigned Text_WriteControlCodeFF14(void** p){void* dest=*p;unsigned short code=65300;memcpy(dest,&code,2);return 2;}
