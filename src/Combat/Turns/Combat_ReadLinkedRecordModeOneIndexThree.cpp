#include <globaldefs.h>
ARM
extern "C" void GameState_ReadLinkedRecordValueByMode(int, int, int, int);
// Original: arm9/ov000 @ 0x02181DA4; symbol: func_ov000_02181da4; size: 0x1C.
extern "C" void Combat_ReadLinkedRecordModeOneIndexThree(int a0, int a1, int a2) {
    GameState_ReadLinkedRecordValueByMode(1, 3, a1, a2);
}
