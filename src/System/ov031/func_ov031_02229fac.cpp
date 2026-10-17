#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void SetPendingByteIfInvalid(unsigned int value);
// Original: arm9/ov031 @ 0x02229FAC; symbol: func_ov031_02229fac; size: 0x38.
extern "C" void func_ov031_02229fac(void) {
    if (AreInputMaskBitsHeld(1)) SetPendingByteIfInvalid(1);
    if (AreInputMaskBitsHeld(2)) SetPendingByteIfInvalid(0);
}
