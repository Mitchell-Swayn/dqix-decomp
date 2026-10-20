#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x02165B38; symbol: func_ov004_02165b38; size: 0x14.
extern "C" int TreasureMapMenu_RequestUnknownMapDecisionPhase(void *self) {
    Menu_QueueScriptEntry(self, 0x67);
    return 0;
}
