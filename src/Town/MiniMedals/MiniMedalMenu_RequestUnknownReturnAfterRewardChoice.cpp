#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void*, unsigned int);
// Original: arm9/ov004 @ 0x0216827C; symbol: func_ov004_0216827c; size: 0x14.
extern "C" int MiniMedalMenu_RequestUnknownReturnAfterRewardChoice(void* self) { Menu_QueueScriptEntry(self, 0x15); return 0; }
