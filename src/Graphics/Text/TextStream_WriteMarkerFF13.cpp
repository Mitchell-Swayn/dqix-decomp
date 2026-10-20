#include <globaldefs.h>
extern "C" void* memcpy(void*, const void*, unsigned);
// Original: arm9/main @ 0x02069D94; symbol: func_02069d94; size: 0x28.
extern "C" int TextStream_WriteMarkerFF13(void** stream) { void* dest=*stream; unsigned short marker=0xff13; memcpy(dest,&marker,2); return 2; }
