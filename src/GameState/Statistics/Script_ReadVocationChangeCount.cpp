#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *out);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9F00; symbol: GameState_SetTypeThreeSecondWordFromStateOffset28; size: 0x30.
// Copies the GameState buffer and uses bits 22 and above of word +0x28 to set the nested type-three second word.
extern "C" int Script_ReadVocationChangeCount(void *object) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    Script_WriteIntegerReferenceOutput(object, *(unsigned int *)(state + 0x28) >> 22);
    return 1;
}
