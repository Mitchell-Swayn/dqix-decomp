#include <globaldefs.h>
ARM
extern "C" void GameState_GetValidLinkedObjectIndex(int, int, int, int);
// Original: arm9/ov000 @ 0x02182034; symbol: func_ov000_02182034; size: 0x18.
extern "C" void Combat_GetValidLinkedObjectIndexAtSlotThreeKindZero(int, int second, int third) {
    GameState_GetValidLinkedObjectIndex(second, 3, third, 0);
}
