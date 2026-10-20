#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x02069F4C; symbol: func_02069f4c; size: 0x28.
extern "C" unsigned Text_WriteControlCodeFF17(void** p){void* dest=*p;unsigned short code=65303;memcpy(dest,&code,2);return 2;}
