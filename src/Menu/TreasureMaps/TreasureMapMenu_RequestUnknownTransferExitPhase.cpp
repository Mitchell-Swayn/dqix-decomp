#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void*, unsigned int);
// Original: arm9/ov004 @ 0x02165A08; symbol: func_ov004_02165a08; size: 0x14.
extern "C" int TreasureMapMenu_RequestUnknownTransferExitPhase(void* self) { Menu_QueueScriptEntry(self, 0x70); return 0; }
