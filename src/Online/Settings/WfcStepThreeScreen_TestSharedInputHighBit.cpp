#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02231B90; symbol: func_ov031_02231b90; size: 0x20.
extern "C" bool WfcStepThreeScreen_TestSharedInputHighBit(void) {
    int value = *(volatile unsigned short *)0x027fffa8;
    value &= 0x8000;
    return value >> 15;
}
