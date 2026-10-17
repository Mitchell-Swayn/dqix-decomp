#include <globaldefs.h>
ARM
extern "C" void GameState_GetValidLinkedObjectIndex(void *object, int mode, void *value, int flag);
// Original: arm9/ov000 @ 0x0218207C; symbol: func_ov000_0218207c; size: 0x18.
extern "C" void Ov000_ForwardSecondThirdWithMode2Flag1(void *unused, void *object, void *value) {
    GameState_GetValidLinkedObjectIndex(object, 2, value, 1);
}
