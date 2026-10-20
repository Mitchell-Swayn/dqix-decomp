#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021F1440; symbol: func_ov024_021f1440; size: 0x1C.
extern "C" int Combatant_TestTargetCapabilityBit2(void *p) {
    unsigned char *q = *(unsigned char **)((char *)p + 0x138);
    return (((unsigned int)q[0x3c] << 29) >> 31) != 0;
}
