#include <globaldefs.h>
ARM
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0216DCB4; symbol: func_ov004_0216dcb4; size: 0x14.
extern "C" int State_ApplyValueC9AndReturnZero(State *self) {
    Menu_QueueScriptEntry(self, 0xc9);
    return 0;
}
