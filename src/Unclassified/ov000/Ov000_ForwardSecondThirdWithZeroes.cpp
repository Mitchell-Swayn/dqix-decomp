#include <globaldefs.h>
ARM
extern "C" void GameState_GetValidLinkedObjectIndex(void *object, int zero1, void *value, int zero2);
// Original: arm9/ov000 @ 0x02181FEC; symbol: func_ov000_02181fec; size: 0x18.
extern "C" void Ov000_ForwardSecondThirdWithZeroes(void *unused, void *object, void *value) {
    GameState_GetValidLinkedObjectIndex(object, 0, value, 0);
}
