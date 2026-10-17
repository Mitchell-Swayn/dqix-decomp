#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/main @ 0x02069E84; symbol: func_02069e84; size: 0x28.
extern "C" int TextStream_WriteMarkerFF2E(void** p){void* out=*p;unsigned short marker=0xff2e;memcpy(out,&marker,2);return 2;}
