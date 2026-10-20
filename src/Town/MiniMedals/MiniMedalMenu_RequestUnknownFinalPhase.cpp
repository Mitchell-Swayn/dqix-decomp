#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x02168670; symbol: func_ov004_02168670; size: 0x14.
extern "C" int MiniMedalMenu_RequestUnknownFinalPhase(void *self) { Menu_QueueScriptEntry(self, 0x69); return 0; }
