#include <globaldefs.h>
// Original: arm9/ov017 @ 0x021B354C; symbol: func_ov017_021b354c; size: 0x14.
extern "C" ARM unsigned Field_ReadNestedStatusByte(void* object) { void* nested=*(void**)((unsigned char*)object+0x150); return nested ? *((unsigned char*)nested+0x56e) : 0; }
