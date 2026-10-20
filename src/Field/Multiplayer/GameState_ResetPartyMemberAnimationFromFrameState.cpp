#include <globaldefs.h>
ARM
extern "C" void * _ZN9GameState21GetPartyMemberByIndexEi(void *, int);
extern "C" void GameObject_ResetLadderTraversalAndAnimation(unsigned char *);
// Original: arm9/ov017 @ 0x021D443C; symbol: func_ov017_021d443c; size: 0x30.
extern "C" void GameState_ResetPartyMemberAnimationFromFrameState(int fallbackIndex, signed char *frameState, void *gameState) {
    int index = fallbackIndex;
    if (frameState[4] != -1)
        index = frameState[4];
    void *member = _ZN9GameState21GetPartyMemberByIndexEi(gameState, index);
    if (member)
        GameObject_ResetLadderTraversalAndAnimation((unsigned char *)member);
}
