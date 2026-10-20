#include <globaldefs.h>
ARM
extern "C" int GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9944; symbol: func_ov023_021e9944; size: 0x30.
extern "C" int SetObjectNestedWordFromCopiedStateTopByte(void *object) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    unsigned int word = *(unsigned int *)(state + 8);
    Script_WriteIntegerReferenceOutput(object, (int)(word >> 24));
    return 1;
}
