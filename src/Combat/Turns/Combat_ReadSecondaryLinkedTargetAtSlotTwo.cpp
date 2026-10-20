#include <globaldefs.h>
ARM
extern "C" void GameState_ReadLinkedRecordValueByMode(int mode, int index, void *first, void *second);
// Original: arm9/ov000 @ 0x02181E6C; symbol: func_ov000_02181e6c; size: 0x1C.
extern "C" void Combat_ReadSecondaryLinkedTargetAtSlotTwo(void *unused, int first, void *second) {
    GameState_ReadLinkedRecordValueByMode(0, 2, (void *)first, second);
}
