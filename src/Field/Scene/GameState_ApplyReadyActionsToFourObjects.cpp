#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" int Field_MarkCombatantStatusAppearanceDirty(void*, int);
extern "C" void Graphics_StagePartyObjectTexturesAfterDisplayWait(void*, int);
// Original: arm9/ov017 @ 0x0218F79C; symbol: GameState_ApplyReadyActionsToFourObjects; size: 0x70.
// For each of four game-object indices, checks that the object exists and that the ov017 readiness helper returns nonzero, then dispatches the per-index action.
extern "C" void GameState_ApplyReadyActionsToFourObjects(void* self) {
    void* game = _ZN9GameState11GetInstanceEv();
    for (int i = 0; i < 4; ++i) {
        if (!_ZN9GameState20GetGameObjectByIndexEi(game, i)) continue;
        int eligible = Field_MarkCombatantStatusAppearanceDirty(self, i) ? 1 : 0;
        if (eligible != 0) Graphics_StagePartyObjectTexturesAfterDisplayWait(self, i);
    }
}
