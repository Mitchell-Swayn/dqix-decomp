#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void Object_SetHalfword1B2WhenMemberListedOrForced(void*, short, int);
// Original: arm9/ov017 @ 0x02192594; symbol: func_ov017_02192594; size: 0x4C.
extern "C" void GameState_ResetPartyMemberHalfwords(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    for (int i = 0; i < 4; ++i) {
        void* member = _ZN9GameState21GetPartyMemberByIndexEi(state, i);
        if (member != 0) Object_SetHalfword1B2WhenMemberListedOrForced(member, 0, 1);
    }
}
