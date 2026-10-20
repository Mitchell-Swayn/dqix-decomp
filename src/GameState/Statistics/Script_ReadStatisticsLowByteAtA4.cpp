#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EAD0C; symbol: GameState_CopyStateAndSetLowByteAtA4; size: 0x34.
extern "C" int Script_ReadStatisticsLowByteAtA4(void *object) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    unsigned value = *(unsigned *)(state + 0xa4);
    unsigned shifted = value << 24;
    shifted >>= 24;
    Script_WriteIntegerReferenceOutput(object, shifted);
    return 1;
}
