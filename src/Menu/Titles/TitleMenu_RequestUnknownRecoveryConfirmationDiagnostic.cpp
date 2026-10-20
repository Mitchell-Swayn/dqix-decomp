#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216DD1C; symbol: func_ov004_0216dd1c; size: 0x18.
extern "C" int TitleMenu_RequestUnknownRecoveryConfirmationDiagnostic(void *self) { Menu_QueueScriptEntry(self, 0x192); return 0; }
