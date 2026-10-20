#include <globaldefs.h>
ARM
#pragma optimization_level 4

extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);

struct StateWord { unsigned int value : 24; };

// Original: arm9/ov023 @ 0x021EA378; symbol: func_ov023_021ea378; size: 0x34.
extern "C" int Script_ReadCompactExperienceEarned(void *arg) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(arg, ((StateWord *)(state + 0x8c))->value);
    return 1;
}
