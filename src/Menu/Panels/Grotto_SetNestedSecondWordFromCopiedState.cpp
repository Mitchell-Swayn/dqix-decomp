#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA118; symbol: func_ov023_021ea118; size: 0x34.
extern "C" int Grotto_SetNestedSecondWordFromCopiedState(void *object) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    unsigned short value = (unsigned short)*(unsigned int *)(state + 0x74);
    Script_WriteIntegerReferenceOutput(object, value);
    return 1;
}
