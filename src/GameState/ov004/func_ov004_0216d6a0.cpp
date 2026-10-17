#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void GameState_SetUnk4Element0(void *, unsigned char);
extern "C" void GameState_WriteUnknownF70(void *, unsigned char);
struct State;
extern "C" void func_ov011_021848a0(State *self, unsigned int value);
// Original: arm9/ov004 @ 0x0216D6A0; symbol: func_ov004_0216d6a0; size: 0x3C.
extern "C" int func_ov004_0216d6a0(State *self) {
    void *state = _ZN9GameState11GetInstanceEv();
    GameState_SetUnk4Element0(state, 8);
    GameState_WriteUnknownF70(state, 0);
    func_ov011_021848a0(self, 999);
    return 0;
}
