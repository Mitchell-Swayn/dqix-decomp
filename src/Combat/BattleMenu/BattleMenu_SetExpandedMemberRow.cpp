#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02174A38; symbol: func_ov000_02174a38; size: 0x18.
extern "C" void BattleMenu_SetExpandedMemberRow(void *p, int enabled) {
    unsigned char *field = (unsigned char *)p + 0x24;
    if (enabled) *field |= 4;
    else *field &= ~4;
}
