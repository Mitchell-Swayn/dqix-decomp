#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);

// Original: arm9/ov004 @ 0x021683EC; symbol: func_ov004_021683ec; size: 0x14.
extern "C" int MiniMedalMenu_RequestUnknownPostPreviewPhase(void *self) {
    Menu_QueueScriptEntry(self, 0x83);
    return 0;
}
