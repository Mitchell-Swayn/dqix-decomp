#include <globaldefs.h>
ARM
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0215C194; symbol: func_ov004_0215c194; size: 0x18.
extern "C" int State_ApplyValue39FAndReturnZero(State *self) {
    Menu_QueueScriptEntry(self, 0x39f);
    return 0;
}
