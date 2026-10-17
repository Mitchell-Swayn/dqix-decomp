#include <globaldefs.h>
ARM
// The receiver plus 0x4340 is read as a 32-bit word.
// Original: arm9/ov017 @ 0x021bdbe4; symbol: func_ov017_021bdbe4; size: 0xc.
extern "C" ARM unsigned int ReadWordAtOverlayOffset4340(void* self) { return *(unsigned int*)((unsigned char*)self + 0x4340); }
