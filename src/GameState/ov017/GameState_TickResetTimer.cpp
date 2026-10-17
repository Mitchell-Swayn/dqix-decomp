#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void *);
extern "C" void GameState_ResetUnknownObjectAndResourceFlag(void);
// Original: arm9/ov017 @ 0x021BFEE8; symbol: func_ov017_021bfee8; size: 0x3C.
extern "C" int GameState_TickResetTimer(void *self) {
    void *state = _ZN9GameState11GetInstanceEv();
    unsigned delta = _ZNK9GameState21GetEffectiveDeltaTimeEv(state);
    unsigned short timer = *(unsigned short *)((char *)self + 8);
    if (delta < timer) {
        *(unsigned short *)((char *)self + 8) = (unsigned short)(timer - delta);
        return 6;
    }
    *(unsigned short *)((char *)self + 8) = 0;
    GameState_ResetUnknownObjectAndResourceFlag();
    return 8;
}
