#include <globaldefs.h>
ARM
#pragma optimization_level 4

extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);

struct StateWord { unsigned int value : 17; };

// Original: arm9/ov023 @ 0x021EABA0; symbol: func_ov023_021eaba0; size: 0x34.
extern "C" int Script_ReadStatisticsLow17BitValueAt98(void *arg) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(arg, ((StateWord *)(state + 0x98))->value);
    return 1;
}
