#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x02069D6C; symbol: func_02069d6c; size: 0x28.
extern "C" unsigned Text_WriteControlCodeFF11(void** p){void* dest=*p;unsigned short code=65297;memcpy(dest,&code,2);return 2;}
