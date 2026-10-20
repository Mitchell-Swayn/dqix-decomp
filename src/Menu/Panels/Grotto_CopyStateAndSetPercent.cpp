#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" unsigned int GameStats_GetCompletionPercentOf448(unsigned int*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov023 @ 0x021E99DC; symbol: func_ov023_021e99dc; size: 0x34.
extern "C" bool Grotto_CopyStateAndSetPercent(void* p) {
    unsigned char out[0xb0];
    GameState_CopyStatisticsRecord(out);
    Script_WriteIntegerReferenceOutput(p, (int)GameStats_GetCompletionPercentOf448((unsigned int*)out));
    return true;
}
