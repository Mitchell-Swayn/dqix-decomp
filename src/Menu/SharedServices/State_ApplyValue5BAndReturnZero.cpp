#include <globaldefs.h>
ARM
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0216A5E8; symbol: func_ov004_0216a5e8; size: 0x14.
extern "C" int State_ApplyValue5BAndReturnZero(State *self) {
    Menu_QueueScriptEntry(self, 0x5b);
    return 0;
}
