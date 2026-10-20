#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x021680B8; symbol: func_ov004_021680b8; size: 0x14.
extern "C" int MiniMedalMenu_RequestUnknownRewardListPhase(void *self) { Menu_QueueScriptEntry(self, 0x66); return 0; }
