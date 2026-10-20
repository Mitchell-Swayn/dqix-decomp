#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E8A64; symbol: func_ov025_021e8a64; size: 0x10.
extern "C" unsigned int Combat_GetCurrentPresentationTextureState(void* p) { unsigned int i = *((unsigned char*)p + 0x30); return *(unsigned int*)((char*)p + 0x20 + i * 4); }
