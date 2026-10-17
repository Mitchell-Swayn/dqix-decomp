#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x02069B5C; symbol: func_02069b5c; size: 0x28.
extern "C" unsigned Text_WriteControlCodeFF07(void** p){void* dest=*p;unsigned short code=65287;memcpy(dest,&code,2);return 2;}
