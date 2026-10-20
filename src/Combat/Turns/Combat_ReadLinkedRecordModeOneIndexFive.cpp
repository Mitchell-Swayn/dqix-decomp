#include <globaldefs.h>
ARM
extern "C" void GameState_ReadLinkedRecordValueByMode(unsigned, unsigned, unsigned, unsigned);
// Original: arm9/ov000 @ 0x02181DDC; symbol: func_ov000_02181ddc; size: 0x1C.
extern "C" void Combat_ReadLinkedRecordModeOneIndexFive(void *unused, unsigned a, unsigned b) {
    GameState_ReadLinkedRecordValueByMode(1, 5, a, b);
}
