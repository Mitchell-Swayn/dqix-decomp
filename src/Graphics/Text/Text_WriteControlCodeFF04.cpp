#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x02069AE4; symbol: func_02069ae4; size: 0x28.
extern "C" unsigned Text_WriteControlCodeFF04(void** p){void* dest=*p;unsigned short code=65284;memcpy(dest,&code,2);return 2;}
