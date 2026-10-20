#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216F620; symbol: func_ov004_0216f620; size: 0x14.
extern "C" int OnlineTransferMenu_RequestClose(void *self) { Menu_QueueScriptEntry(self, 1); return 0; }
