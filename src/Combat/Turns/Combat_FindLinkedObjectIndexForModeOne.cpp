#include <globaldefs.h>
ARM
extern "C" void GameState_GetValidLinkedObjectIndex(int, int, int, int);

// Original: arm9/ov000 @ 0x02182004; symbol: func_ov000_02182004; size: 0x18.
extern "C" void Combat_FindLinkedObjectIndexForModeOne(int unused, int value, int third) {
    GameState_GetValidLinkedObjectIndex(value, 1, third, 0);
}
