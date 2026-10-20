#include <globaldefs.h>
ARM
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0216DC78; symbol: func_ov004_0216dc78; size: 0x14.
extern "C" int TitleMenu_RequestAdventureLogDeletionPrompt(State *self) {
    Menu_QueueScriptEntry(self, 0x96);
    return 0;
}
