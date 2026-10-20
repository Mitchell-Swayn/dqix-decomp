#include <globaldefs.h>
// Original: arm9/ov017 @ 0x021B2BF4; symbol: func_ov017_021b2bf4; size: 0x18.
extern "C" ARM void Field_SetOverlayLoadSkipFadeOut(void* object, unsigned int value) { unsigned int flags = *(unsigned int*)((char*)object + 0x38); unsigned int bit = (value << 31) >> 27; flags = (flags & ~0x10u) | bit; *(unsigned int*)((char*)object + 0x38) = flags; }
