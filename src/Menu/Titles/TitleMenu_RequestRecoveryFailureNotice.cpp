#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);

// Original: arm9/ov004 @ 0x0216DD60; symbol: func_ov004_0216dd60; size: 0x18.
extern "C" int TitleMenu_RequestRecoveryFailureNotice(void *self) {
    Menu_QueueScriptEntry(self, 0x195);
    return 0;
}
