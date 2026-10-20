#include <globaldefs.h>
ARM
struct Record;
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" unsigned GameStats_GetCompletionPercentOf232(Record* p);
extern "C" void Script_WriteIntegerReferenceOutput(void *,int);
// Original: arm9/ov023 @ 0x021E9A10; symbol: func_ov023_021e9a10; size: 0x34.
extern "C" int GameState_SetNestedTypeThreePercentage(void* object) {
    unsigned char buffer[0xb0];
    GameState_CopyStatisticsRecord(buffer);
    unsigned value = GameStats_GetCompletionPercentOf232((Record*)buffer);
    Script_WriteIntegerReferenceOutput(object, (int)value);
    return 1;
}
