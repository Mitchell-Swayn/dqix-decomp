#include <globaldefs.h>
ARM

struct GameState;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(GameState *, int);
extern "C" unsigned ReadNestedFieldAtOffset150And150And950And16C(void *);

// Original: arm9/ov003 @ 0x02155FFC; symbol: func_ov003_02155ffc; size: 0x38.
extern "C" int GameState_PartyMemberFieldDiffersFrom99(void *unused, int index) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *member = _ZN9GameState21GetPartyMemberByIndexEi((GameState *)state, index);
    int result = 0;
    if (member != 0) {
        result = ReadNestedFieldAtOffset150And150And950And16C(member) != 0x63;
    }
    return result;
}
