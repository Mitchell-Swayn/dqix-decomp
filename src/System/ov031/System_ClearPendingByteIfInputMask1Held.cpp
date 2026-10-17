#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void SetPendingByteIfInvalid(signed char value);
// Original: arm9/ov031 @ 0x02228AC0; symbol: func_ov031_02228ac0; size: 0x20.
extern "C" void System_ClearPendingByteIfInputMask1Held(void) {
    if (AreInputMaskBitsHeld(1))
        SetPendingByteIfInvalid(0);
}
