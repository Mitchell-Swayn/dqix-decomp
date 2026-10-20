#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *self, unsigned value);
// Original: arm9/ov004 @ 0x02165888; symbol: func_ov004_02165888; size: 0x14.
extern "C" unsigned TreasureMapMenu_RequestUnknownTransferResolution(void *self) {
    Menu_QueueScriptEntry(self, 0x6d);
    return 0;
}
