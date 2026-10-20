#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void*, unsigned int);
// Original: arm9/ov004 @ 0x0216DCC8; symbol: func_ov004_0216dcc8; size: 0x14.
extern "C" int TitleMenu_RequestQuestCodeScreen(void* self) { Menu_QueueScriptEntry(self, 0x12c); return 0; }
