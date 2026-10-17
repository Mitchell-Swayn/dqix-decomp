#include <globaldefs.h>
ARM
struct State;
extern "C" void func_ov011_021848a0(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0216DD4C; symbol: func_ov004_0216dd4c; size: 0x14.
extern "C" int State_ApplyValue194AndReturnZero(State *self) {
    func_ov011_021848a0(self, 0x194);
    return 0;
}
