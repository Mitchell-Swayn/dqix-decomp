#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB878; symbol: func_ov023_021fb878; size: 0x14.
extern "C" void MenuSprite_SetDrawPosition(void* dst, unsigned int* src) { *(unsigned int*)((char*)dst + 0xa8) = src[0]; *(unsigned int*)((char*)dst + 0xac) = src[1]; }
