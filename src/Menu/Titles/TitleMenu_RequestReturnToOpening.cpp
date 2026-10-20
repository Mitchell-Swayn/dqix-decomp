#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void GameState_SetUnk4Element0(void *, int);
extern "C" void GameState_SetUnknown7f6c(void *, int);
struct State;
extern "C" void Menu_QueueScriptEntry(State *, unsigned);
// Original: arm9/ov004 @ 0x0216DC24; symbol: func_ov004_0216dc24; size: 0x3C.
extern "C" int TitleMenu_RequestReturnToOpening(State *self) {
    void *state = _ZN9GameState11GetInstanceEv();
    GameState_SetUnk4Element0(state, 6);
    GameState_SetUnknown7f6c(state, 2);
    Menu_QueueScriptEntry(self, 999);
    return 0;
}
