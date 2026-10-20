#include <globaldefs.h>
ARM
extern "C" void GameState_ReadLinkedRecordValueByMode(int, int, int, int);
// Original: arm9/ov000 @ 0x02181E88; symbol: func_ov000_02181e88; size: 0x1C.
extern "C" void Combat_ReadLinkedRecordModeZeroIndexThree(int a0, int a1, int a2) {
    GameState_ReadLinkedRecordValueByMode(0, 3, a1, a2);
}
