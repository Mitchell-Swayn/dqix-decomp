#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x02168024; symbol: func_ov004_02168024; size: 0x14.
extern "C" int MiniMedalMenu_RequestUnknownPrimaryReturn(void *self) { Menu_QueueScriptEntry(self, 0x15); return 0; }
