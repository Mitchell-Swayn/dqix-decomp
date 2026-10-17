#include <globaldefs.h>
ARM
extern "C" unsigned int GameState_GetValidLinkedObjectIndex(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov000 @ 0x0218201C; symbol: func_ov000_0218201c; size: 0x18.
extern "C" unsigned int func_ov000_0218201c(unsigned int unused, unsigned int first, unsigned int third) {
    return GameState_GetValidLinkedObjectIndex(first, 2, third, 0);
}
