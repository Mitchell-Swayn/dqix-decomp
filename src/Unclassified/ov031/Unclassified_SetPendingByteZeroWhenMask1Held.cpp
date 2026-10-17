#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void SetPendingByteIfInvalid(signed char value);

// Original: arm9/ov031 @ 0x0222E8A4; symbol: func_ov031_0222e8a4; size: 0x20.
extern "C" void Unclassified_SetPendingByteZeroWhenMask1Held(void) {
    if (AreInputMaskBitsHeld(1))
        SetPendingByteIfInvalid(0);
}
