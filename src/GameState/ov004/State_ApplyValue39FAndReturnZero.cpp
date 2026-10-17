#include <globaldefs.h>
ARM
struct State;
extern "C" void func_ov011_021848a0(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0215C194; symbol: func_ov004_0215c194; size: 0x18.
extern "C" int State_ApplyValue39FAndReturnZero(State *self) {
    func_ov011_021848a0(self, 0x39f);
    return 0;
}
