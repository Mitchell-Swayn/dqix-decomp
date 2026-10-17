#include <globaldefs.h>
ARM
extern "C" void Graphics_StopIndexedObjectAnimation(void*, void*);
extern "C" void* data_ov001_02165884;
// Original: arm9/ov001 @ 0x02159B34; symbol: func_ov001_02159b34; size: 0x20.
extern "C" int func_ov001_02159b34(void* unused, void* p) { Graphics_StopIndexedObjectAnimation(data_ov001_02165884, *(void**)((char*)p + 0x70)); return 0; }
