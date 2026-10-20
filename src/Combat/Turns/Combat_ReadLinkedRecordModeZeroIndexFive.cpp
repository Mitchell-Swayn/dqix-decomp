#include <globaldefs.h>
ARM
extern "C" void GameState_ReadLinkedRecordValueByMode(int, int, int, int);
// Original: arm9/ov000 @ 0x02181EC0; symbol: func_ov000_02181ec0; size: 0x1C.
extern "C" void Combat_ReadLinkedRecordModeZeroIndexFive(int, int second, int third) {
    GameState_ReadLinkedRecordValueByMode(0, 5, second, third);
}
