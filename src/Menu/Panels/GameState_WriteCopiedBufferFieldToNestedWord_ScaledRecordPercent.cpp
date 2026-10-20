#include <globaldefs.h>
ARM
struct Record { char pad[20]; unsigned a:9; unsigned b:9; unsigned c:11; unsigned rest:3; };
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" unsigned GameStats_GetCompletionPercentOf944(Record *p);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9A44; symbol: func_ov023_021e9a44; size: 0x34.
extern "C" int GameState_WriteCopiedBufferFieldToNestedWord_ScaledRecordPercent(void *out) {
    unsigned char state[0xB0];
    GameState_CopyStatisticsRecord(state);
    unsigned percent = GameStats_GetCompletionPercentOf944((Record *)state);
    Script_WriteIntegerReferenceOutput(out, percent);
    return 1;
}
