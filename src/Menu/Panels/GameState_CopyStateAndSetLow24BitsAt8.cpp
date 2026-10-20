#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9DC8; symbol: GameState_CopyStateAndSetLow24BitsAt8; size: 0x34.
extern "C" int GameState_CopyStateAndSetLow24BitsAt8(void *object) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    unsigned value = *(unsigned *)(state + 0x8);
    unsigned shifted = value << 8;
    shifted >>= 8;
    Script_WriteIntegerReferenceOutput(object, shifted);
    return 1;
}
