#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA2AC; symbol: GameState_SetTypeThreeSecondWordFromStateOffset80; size: 0x30.
// Copies the GameState buffer and uses bits 16 and above of word +0x80 to set the nested type-three second word.
extern "C" int Script_ReadCompactAlchemyCount(void *object) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(object, *(unsigned int *)(state + 0x80) >> 16);
    return 1;
}
