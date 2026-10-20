#include <globaldefs.h>
ARM
#pragma optimization_level 4

extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);

struct StateWord { unsigned int : 24; unsigned int value : 7; };

// Original: arm9/ov023 @ 0x021EACA4; symbol: func_ov023_021eaca4; size: 0x34.
extern "C" int CopyTypeThreeSecondWordFromGameStateBits24(void *arg) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(arg, ((StateWord *)(state + 0x9c))->value);
    return 1;
}
