#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void* out);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov023 @ 0x021E9E98; symbol: func_ov023_021e9e98; size: 0x34.
extern "C" int Grotto_SetTypeThreeSecondWordFromStateWord40(void* output) {
    char buffer[0xB0];
    GameState_CopyStatisticsRecord(buffer);
    unsigned int value = (*(volatile unsigned int*)(buffer + 0x40) << 8) >> 8;
    Script_WriteIntegerReferenceOutput(output, value);
    return 1;
}
