#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int);
extern "C" int System_IsHardwareStatusBit15Set(void);
extern "C" void SetPendingByteIfInvalid(int);
// Original: arm9/ov031 @ 0x0222B168; symbol: func_ov031_0222b168; size: 0x38.
extern "C" void func_ov031_0222b168(void) {
    if (AreInputMaskBitsHeld(2) != 0) {
        SetPendingByteIfInvalid(0);
        return;
    }
    if (System_IsHardwareStatusBit15Set() != 0) SetPendingByteIfInvalid(0);
}
