#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x02069E5C; symbol: func_02069e5c; size: 0x28.
extern "C" unsigned Text_WriteControlCodeFF2D(void** p){void* dest=*p;unsigned short code=65325;memcpy(dest,&code,2);return 2;}
