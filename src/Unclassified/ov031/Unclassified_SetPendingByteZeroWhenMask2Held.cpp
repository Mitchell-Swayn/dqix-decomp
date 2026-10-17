#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void SetPendingByteIfInvalid(signed char value);

// Original: arm9/ov031 @ 0x02228F30; symbol: func_ov031_02228f30; size: 0x20.
extern "C" void Unclassified_SetPendingByteZeroWhenMask2Held(void) {
    if (AreInputMaskBitsHeld(2))
        SetPendingByteIfInvalid(0);
}
