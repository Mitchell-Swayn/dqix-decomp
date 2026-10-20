#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *, int);
// Original: arm9/ov003 @ 0x02155FC0; symbol: func_ov003_02155fc0; size: 0x3C.
extern "C" int Alltrades_IsMemberDead(void *unused, int index) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *member = _ZN9GameState21GetPartyMemberByIndexEi(state, index);
    if (member != 0) {
        unsigned int value = **(unsigned int **)((char *)member + 0x130);
        return (value & 1) != 0;
    }
    return 0;
}
