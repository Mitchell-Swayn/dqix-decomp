#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EAC08; symbol: func_ov023_021eac08; size: 0x34.
extern "C" bool Grotto_SetNestedWordFromPackedByteState(void *param) {
    unsigned char output[0xB0];
    GameState_CopyStatisticsRecord(output);
    Script_WriteIntegerReferenceOutput(param, (*(unsigned int *)(output + 0x98) << 1) >> 25);
    return true;
}
