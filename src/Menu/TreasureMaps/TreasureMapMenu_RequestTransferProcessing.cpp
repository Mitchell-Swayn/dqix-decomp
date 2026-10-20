#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216589C; symbol: func_ov004_0216589c; size: 0x14.
extern "C" int TreasureMapMenu_RequestTransferProcessing(void *self) { Menu_QueueScriptEntry(self, 0x64); return 0; }
