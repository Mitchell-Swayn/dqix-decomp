#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA310; symbol: func_ov023_021ea310; size: 0x34.
extern "C" bool Grotto_SetNestedSecondWordFromByteState(void *param) {
    unsigned char output[0xB0];
    GameState_CopyStatisticsRecord(output);
    Script_WriteIntegerReferenceOutput(param, (*(unsigned int *)(output + 0x84) << 6) >> 16);
    return true;
}
