#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x02069FC4; symbol: func_02069fc4; size: 0x28.
extern "C" unsigned Text_WriteControlCodeFF0E(void** p){void* dest=*p;unsigned short code=65294;memcpy(dest,&code,2);return 2;}
