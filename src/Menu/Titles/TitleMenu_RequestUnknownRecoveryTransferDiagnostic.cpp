#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *self, unsigned value);
// Original: arm9/ov004 @ 0x0216DD34; symbol: func_ov004_0216dd34; size: 0x18.
extern "C" unsigned TitleMenu_RequestUnknownRecoveryTransferDiagnostic(void *self) {
    Menu_QueueScriptEntry(self, 0x193);
    return 0;
}
