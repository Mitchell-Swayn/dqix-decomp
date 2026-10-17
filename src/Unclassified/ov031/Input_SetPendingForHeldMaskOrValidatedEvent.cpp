#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int);
extern "C" void SetPendingByteIfInvalid(unsigned int);
extern "C" int System_ReadHardwareStatusBit15Flag(void);
// Original: arm9/ov031 @ 0x02234AA4; symbol: func_ov031_02234aa4; size: 0x38.
extern "C" void Input_SetPendingForHeldMaskOrValidatedEvent(void) {
    if (AreInputMaskBitsHeld(2)) {
        SetPendingByteIfInvalid(0);
        return;
    }
    if (System_ReadHardwareStatusBit15Flag()) SetPendingByteIfInvalid(0);
}
