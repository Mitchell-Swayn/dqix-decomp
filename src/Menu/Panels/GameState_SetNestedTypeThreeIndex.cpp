#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *,int);
// Original: arm9/ov023 @ 0x021E9B7C; symbol: func_ov023_021e9b7c; size: 0x34.
extern "C" int GameState_SetNestedTypeThreeIndex(void* object) {
    unsigned char buffer[0xb0];
    GameState_CopyStatisticsRecord(buffer);
    unsigned int field = *(unsigned int*)(buffer + 0x18);
    Script_WriteIntegerReferenceOutput(object, (int)((field << 16) >> 25));
    return 1;
}
