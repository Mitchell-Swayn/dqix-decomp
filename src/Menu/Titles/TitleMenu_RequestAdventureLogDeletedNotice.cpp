#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *self, unsigned value);
// Original: arm9/ov004 @ 0x0216DC8C; symbol: func_ov004_0216dc8c; size: 0x14.
extern "C" unsigned TitleMenu_RequestAdventureLogDeletedNotice(void *self) {
    Menu_QueueScriptEntry(self, 0x97);
    return 0;
}
