#include <globaldefs.h>
ARM
class Object;
extern "C" void Field_ResetLeaderTransitionStatusAndRefreshParty(void);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState20GetUnknownGameObjectEv(void *);
extern "C" void GameObject_DisableMovementInput(Object *, int);
// Original: arm9/ov001 @ 0x021609A0; symbol: GameState_ResetCurrentObjectStateAndAnimation; size: 0x20.
// Runs the setup helper, then clears the current object's state fields and resets its animation.
extern "C" int GameState_ResetCurrentObjectStateAndAnimation(void) {
    Field_ResetLeaderTransitionStatusAndRefreshParty();
    void *state = _ZN9GameState11GetInstanceEv();
    GameObject_DisableMovementInput((Object *)_ZN9GameState20GetUnknownGameObjectEv(state), 1);
    return 1;
}
