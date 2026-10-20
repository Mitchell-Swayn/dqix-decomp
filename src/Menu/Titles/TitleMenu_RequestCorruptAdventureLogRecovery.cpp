#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *self, unsigned value);
// Original: arm9/ov004 @ 0x0216DCF0; symbol: func_ov004_0216dcf0; size: 0x14.
extern "C" unsigned TitleMenu_RequestCorruptAdventureLogRecovery(void *self) {
    Menu_QueueScriptEntry(self, 0x190);
    return 0;
}
