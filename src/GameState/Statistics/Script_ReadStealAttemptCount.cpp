#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9CC4; symbol: GameState_CopyStateAndSetLow24BitsAt2C; size: 0x34.
extern "C" int Script_ReadStealAttemptCount(void *object) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    unsigned value = *(unsigned *)(state + 0x2c);
    unsigned shifted = value << 8;
    shifted >>= 8;
    Script_WriteIntegerReferenceOutput(object, shifted);
    return 1;
}
