#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void DispatchGlobalPointerOffset94WithZero(void);
extern "C" void SetPendingByteIfInvalid(int value);
// Original: arm9/ov031 @ 0x0223232C; symbol: func_ov031_0223232c; size: 0x24.
extern "C" void System_HandleHeldInputMaskBit2(void) {
    if (AreInputMaskBitsHeld(2)) {
        DispatchGlobalPointerOffset94WithZero();
        SetPendingByteIfInvalid(0);
    }
}
