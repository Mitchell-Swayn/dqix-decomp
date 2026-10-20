#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(int *, unsigned int);
// Original: arm9/ov004 @ 0x021650E4; symbol: func_ov004_021650e4; size: 0x14.
extern "C" int TreasureMapMenu_RequestUnknownTransferPollPhase(int *state) {
    Menu_QueueScriptEntry(state, 0x6a);
    return 0;
}
