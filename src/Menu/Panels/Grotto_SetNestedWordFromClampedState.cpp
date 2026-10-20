#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9F9C; symbol: func_ov023_021e9f9c; size: 0x38.
extern "C" int Grotto_SetNestedWordFromClampedState(void *arg) {
    unsigned char state[0xB0];
    GameState_CopyStatisticsRecord(state);
    unsigned int value = *(unsigned int *)(state + 0x48);
    if (value > 0x7FFFFFFF) value = 0x7FFFFFFF;
    Script_WriteIntegerReferenceOutput(arg, (int)value);
    return 1;
}
