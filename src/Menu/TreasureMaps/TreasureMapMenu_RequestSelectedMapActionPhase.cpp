#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x02165B4C; symbol: func_ov004_02165b4c; size: 0x14.
extern "C" int TreasureMapMenu_RequestSelectedMapActionPhase(void *self) { Menu_QueueScriptEntry(self, 0x68); return 0; }
