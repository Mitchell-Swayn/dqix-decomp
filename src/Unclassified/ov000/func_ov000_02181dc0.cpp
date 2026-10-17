#include <globaldefs.h>
ARM
extern "C" void GameState_ReadLinkedRecordValueByMode(int, int, int, int);
// Original: arm9/ov000 @ 0x02181DC0; symbol: func_ov000_02181dc0; size: 0x1C.
extern "C" void func_ov000_02181dc0(int, int second, int third) {
    GameState_ReadLinkedRecordValueByMode(1, 4, second, third);
}
