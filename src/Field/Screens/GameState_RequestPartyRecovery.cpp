#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void GameState_SetPartyRecoveryPending(int, unsigned char);
// Original: arm9/ov017 @ 0x021D2428; symbol: func_ov017_021d2428; size: 0x14.
extern "C" void GameState_RequestPartyRecovery(void) {
    GameState_SetPartyRecoveryPending((int)_ZN9GameState11GetInstanceEv(), 1);
}
