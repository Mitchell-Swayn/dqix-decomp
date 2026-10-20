#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216DCDC; symbol: func_ov004_0216dcdc; size: 0x14.
extern "C" int TitleMenu_RequestUnknownQuickSaveCompletionDiagnostic(void *self) {
    Menu_QueueScriptEntry(self, 0xca);
    return 0;
}
