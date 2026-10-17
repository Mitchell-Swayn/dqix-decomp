#include <globaldefs.h>
ARM
struct State;
extern "C" void GameState_AppendValueAndSetNodeFlags(void *object, int first, int second);
extern "C" void func_ov011_021848a0(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0215CBEC; symbol: func_ov004_0215cbec; size: 0x28.
extern "C" int GameState_ApplyModes2And8ThenValue68(State *self) {
    GameState_AppendValueAndSetNodeFlags(self, 2, 8);
    func_ov011_021848a0(self, 0x68);
    return 0;
}
