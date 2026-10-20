#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void*, unsigned int);
// Original: arm9/ov004 @ 0x0216E1CC; symbol: func_ov004_0216e1cc; size: 0x18.
extern "C" int TitleMenu_RequestQuickSaveCorruptionReturnNotice(void* self) { Menu_QueueScriptEntry(self, 0x259); return 0; }
