#include <globaldefs.h>
ARM
extern "C" void GameState_ReadLinkedRecordValueByMode(int mode, int index, void *first, void *second);
// Original: arm9/ov000 @ 0x02181F30; symbol: func_ov000_02181f30; size: 0x1C.
extern "C" void Combat_ReadSecondaryLinkedSelectedValueAtSlotOne(void *unused, int first, void *second) {
    GameState_ReadLinkedRecordValueByMode(2, 1, (void *)first, second);
}
