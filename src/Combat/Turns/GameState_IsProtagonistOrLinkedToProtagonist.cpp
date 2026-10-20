#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadProtagonistObjectIndex(void *);
extern "C" void *GameState_FindIndexedObjectWithFlag1000(void *, int);
extern "C" int GameObject_GetAssociatedPartyMemberIndex(void *);
// Original: arm9/ov000 @ 0x0215FD24; symbol: func_ov000_0215fd24; size: 0x58.
// Tests the requested index against the protagonist index, then checks the matching flagged object field 0x2D0 against that index.
extern "C" int GameState_IsProtagonistOrLinkedToProtagonist(void *unused, int index) {
    void *state = _ZN9GameState11GetInstanceEv();
    int protagonist = GameState_ReadProtagonistObjectIndex(state);
    if (index == protagonist) return 1;
    void *object = GameState_FindIndexedObjectWithFlag1000(state, index);
    return object != 0 && GameObject_GetAssociatedPartyMemberIndex(object) == GameState_ReadProtagonistObjectIndex(state);
}
