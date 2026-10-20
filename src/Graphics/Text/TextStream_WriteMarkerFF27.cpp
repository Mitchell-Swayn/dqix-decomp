#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x0206994C; symbol: func_0206994c; size: 0x28.
extern "C" unsigned TextStream_WriteMarkerFF27(void** p){void* dest=*p;unsigned short code=65319;memcpy(dest,&code,2);return 2;}
