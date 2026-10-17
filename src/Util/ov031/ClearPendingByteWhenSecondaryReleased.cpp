#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void SetPendingByteIfInvalid(signed char value);
extern "C" int System_IsFlag15At027FFFA8Set(void);
// Original: arm9/ov031 @ 0x0222AC20; symbol: func_ov031_0222ac20; size: 0x38.
extern "C" void ClearPendingByteWhenSecondaryReleased(void) {
    if (AreInputMaskBitsHeld(2)) {
        SetPendingByteIfInvalid(0);
        return;
    }
    if (System_IsFlag15At027FFFA8Set()) SetPendingByteIfInvalid(0);
}
