#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned mask);
extern "C" void SetPendingByteIfInvalid(signed char value);
extern "C" int System_ReadHardwareStatusRegisterBit15(void);
// Original: arm9/ov031 @ 0x022316BC; symbol: func_ov031_022316bc; size: 0x38.
extern "C" void System_UpdatePendingStateForMaskTwo(void) {
    if (AreInputMaskBitsHeld(2)) {
        SetPendingByteIfInvalid(0);
        return;
    }
    if (!System_ReadHardwareStatusRegisterBit15()) return;
    SetPendingByteIfInvalid(0);
}
