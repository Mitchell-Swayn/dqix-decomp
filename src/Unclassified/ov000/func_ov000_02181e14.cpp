#include <globaldefs.h>
ARM
extern "C" void GameState_ReadLinkedRecordValueByMode(int, int, int, int);

// Original: arm9/ov000 @ 0x02181E14; symbol: func_ov000_02181e14; size: 0x1C.
extern "C" void func_ov000_02181e14(int unused, int first, int second) {
    GameState_ReadLinkedRecordValueByMode(1, 7, first, second);
}
