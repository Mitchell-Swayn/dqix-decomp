#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0217F464; symbol: func_ov000_0217f464; size: 0x1C.
extern "C" int BattleMenu_HasUnfinishedPartyCommand(void *p) {
    signed char index = *(signed char *)((char *)p + 0x18);
    signed char value = *(signed char *)((char *)p + index + 0x10);
    return value < 100;
}
