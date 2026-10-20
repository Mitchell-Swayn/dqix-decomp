#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216DCA0; symbol: func_ov004_0216dca0; size: 0x14.
extern "C" int TitleMenu_RequestUnknownQuickSaveEntryDiagnostic(void *self) { Menu_QueueScriptEntry(self, 0xc8); return 0; }
