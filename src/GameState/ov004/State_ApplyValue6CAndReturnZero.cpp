#include <globaldefs.h>
ARM
struct State;
extern "C" void func_ov011_021848a0(State *self, unsigned value);
// Original: arm9/ov004 @ 0x02167678; symbol: func_ov004_02167678; size: 0x14.
extern "C" int State_ApplyValue6CAndReturnZero(State *self) {
    func_ov011_021848a0(self, 0x6c);
    return 0;
}
