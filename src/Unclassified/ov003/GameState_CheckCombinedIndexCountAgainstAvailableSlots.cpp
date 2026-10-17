#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned char *GameState_GetIndexList(void *state);
extern "C" void func_ov003_02160c58(int unused, short *total, short *remaining);
// Original: arm9/ov003 @ 0x021614E8; symbol: func_ov003_021614e8; size: 0x5C.
extern "C" int GameState_CheckCombinedIndexCountAgainstAvailableSlots(int value) {
    unsigned char *indices = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    short combined = (short)(indices[0xf7c] + indices[0x2c8c]);
    short bound = (short)(combined - 1);
    short result[2];
    func_ov003_02160c58(value, &result[1], &result[0]);
    return result[1] <= bound;
}
