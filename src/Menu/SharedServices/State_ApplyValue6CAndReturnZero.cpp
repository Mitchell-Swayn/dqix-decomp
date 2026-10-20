#include <globaldefs.h>
ARM
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x02167678; symbol: func_ov004_02167678; size: 0x14.
extern "C" int State_ApplyValue6CAndReturnZero(State *self) {
    Menu_QueueScriptEntry(self, 0x6c);
    return 0;
}
