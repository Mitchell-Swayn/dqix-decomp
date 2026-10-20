#include <globaldefs.h>
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
extern "C" void Network_QueueExplicitPartyMemberState(int, int, int, int, int, int, int, int, int);
// Original: arm9/ov000 @ 0x0217616C; symbol: func_ov000_0217616c; size: 0x5C.
extern "C" void BattleMenu_BroadcastPartyDisplayStats(void *record) {
    void *game = _ZN9GameState11GetInstanceEv();
    if (!GameState_GetObjectWithFlag100(game, *(int *)((char *)record + 0x4c))) return;
    Network_QueueExplicitPartyMemberState(*(int *)((char *)record + 0x4c),
        *(short *)((char *)record + 0x0c), *(short *)((char *)record + 8), *(short *)((char *)record + 0x0e),
        *(short *)((char *)record + 0x0a), *(int *)((char *)record + 0x28), 0, 0, 0);
}
