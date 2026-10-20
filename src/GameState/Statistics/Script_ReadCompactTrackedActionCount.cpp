#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA248; symbol: func_ov023_021ea248; size: 0x30.
extern "C" unsigned int Script_ReadCompactTrackedActionCount(void *object) {
    unsigned char state[0xB0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(object, *(unsigned int *)(state + 0x7C) >> 20);
    return 1;
}
