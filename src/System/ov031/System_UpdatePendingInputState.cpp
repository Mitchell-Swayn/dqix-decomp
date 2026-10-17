#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void SetPendingByteIfInvalid(signed char value);
// Original: arm9/ov031 @ 0x022346E4; symbol: func_ov031_022346e4; size: 0x38.
extern "C" void System_UpdatePendingInputState(void) {
    if (AreInputMaskBitsHeld(1))
        SetPendingByteIfInvalid(1);
    if (AreInputMaskBitsHeld(2))
        SetPendingByteIfInvalid(0);
}
