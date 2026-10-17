#include <globaldefs.h>
ARM
extern "C" void GameState_GetValidLinkedObjectIndex(void *object, int mode, void *value, int flag);
// Original: arm9/ov000 @ 0x02182094; symbol: func_ov000_02182094; size: 0x18.
extern "C" void Ov000_ForwardSecondThirdWithMode3Flag1(void *unused, void *object, void *value) {
    GameState_GetValidLinkedObjectIndex(object, 3, value, 1);
}
