#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9BB0; symbol: func_ov023_021e9bb0; size: 0x34.
extern "C" int Grotto_SetNestedTypeThreeFieldFromGameState(void *p) {
    unsigned char output[0xB0];
    GameState_CopyStatisticsRecord(output);
    unsigned value = (*(unsigned int *)(output + 0x18) << 0xC) >> 0x1C;
    Script_WriteIntegerReferenceOutput(p, value);
    return 1;
}
