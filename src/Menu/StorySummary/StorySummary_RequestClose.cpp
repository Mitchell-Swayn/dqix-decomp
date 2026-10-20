#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216ACD0; symbol: func_ov004_0216acd0; size: 0x18.
extern "C" int StorySummary_RequestClose(void *self) { Menu_QueueScriptEntry(self, 0x3e7); return 0; }
