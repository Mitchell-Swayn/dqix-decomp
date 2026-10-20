#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" ARM unsigned GameStats_GetCompletionPercentOf307(void *p);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E99A8; symbol: func_ov023_021e99a8; size: 0x34.
extern "C" int Grotto_SetNestedTypeThreePercentFromGameState(void *p) {
    unsigned char output[0xB0];
    GameState_CopyStatisticsRecord(output);
    unsigned value = GameStats_GetCompletionPercentOf307(output);
    Script_WriteIntegerReferenceOutput(p, value);
    return 1;
}
