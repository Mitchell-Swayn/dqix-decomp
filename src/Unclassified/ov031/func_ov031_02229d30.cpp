#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned mask);
extern "C" void SetPendingByteIfInvalid(signed char value);
// Original: arm9/ov031 @ 0x02229D30; symbol: func_ov031_02229d30; size: 0x20.
extern "C" void func_ov031_02229d30(void) {
    if (AreInputMaskBitsHeld(1))
        SetPendingByteIfInvalid(0);
}
