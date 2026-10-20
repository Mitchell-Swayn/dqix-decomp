#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EAE0C; symbol: Grotto_SetNestedWordFromCopiedStateOffsetAC; size: 0x2C.
// Copies the 0xB0-byte GameState buffer and writes its word at offset 0xAC to the nested output word.
extern "C" int Script_ReadStatisticsWordAtAC(void *p) {
    unsigned char buffer[0xb0];
    GameState_CopyStatisticsRecord(buffer);
    int value = *(int *)(buffer + 0xac);
    Script_WriteIntegerReferenceOutput(p, value);
    return 1;
}
