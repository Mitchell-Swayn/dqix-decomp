#include <globaldefs.h>
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *, int);
extern "C" void *GameResources_GetInstance();
extern "C" void Field_MarkCombatantStatusAppearanceDirty(void *, int);
// Original: arm9/ov017 @ 0x021C1264; symbol: func_ov017_021c1264; size: 0x4C.
extern "C" void GameState_RefreshPresentPartyCombatantFlags(void) {
    void *game = _ZN9GameState11GetInstanceEv();
    void *resources = GameResources_GetInstance();
    for (int i = 0; i < 4; ++i)
        if (_ZN9GameState21GetPartyMemberByIndexEi(game, i)) Field_MarkCombatantStatusAppearanceDirty(resources, i);
}
