#include <globaldefs.h>
ARM
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x02165BD0; symbol: func_ov004_02165bd0; size: 0x14.
extern "C" int GrottoMenu_RequestUnknownTerminalPhase(State *self) {
    Menu_QueueScriptEntry(self, 0x75);
    return 0;
}
