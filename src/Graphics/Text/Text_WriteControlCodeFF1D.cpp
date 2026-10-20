#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x02069884; symbol: func_02069884; size: 0x28.
extern "C" unsigned Text_WriteControlCodeFF1D(void** p){void* dest=*p;unsigned short code=65309;memcpy(dest,&code,2);return 2;}
