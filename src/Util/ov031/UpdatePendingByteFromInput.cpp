#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void SetPendingByteIfInvalid(signed char value);
// Original: arm9/ov031 @ 0x0222A504; symbol: func_ov031_0222a504; size: 0x38.
extern "C" void UpdatePendingByteFromInput(void) {
    if (AreInputMaskBitsHeld(1)) {
        SetPendingByteIfInvalid(1);
    }
    if (AreInputMaskBitsHeld(2)) {
        SetPendingByteIfInvalid(0);
    }
}
