#include <globaldefs.h>
ARM
// The receiver plus 0x4328 is read as a 32-bit word.
// Original: arm9/ov017 @ 0x0218d268; symbol: func_ov017_0218d268; size: 0xc.
extern "C" ARM unsigned int GameResources_GetTouchMovementController(void* self) { return *(unsigned int*)((unsigned char*)self + 0x4328); }
