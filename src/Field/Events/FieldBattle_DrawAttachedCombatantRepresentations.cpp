#include <globaldefs.h>
ARM
extern "C" void GameState_RefreshAttachedIndexedObjectState(void *);
// Original: arm9/ov017 @ 0x021B8420; symbol: func_ov017_021b8420; size: 0x18.
extern "C" void FieldBattle_DrawAttachedCombatantRepresentations(void *p) {
    void *state = *(void **)((unsigned char *)p + 0x6ac);
    if (state) GameState_RefreshAttachedIndexedObjectState(state);
}
