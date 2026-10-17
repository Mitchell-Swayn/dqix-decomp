#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void SetPendingByteIfInvalid(signed char value);
extern "C" int ReadHighBitOfHalfwordAt027FFFA8(void);
// Original: arm9/ov031 @ 0x02231D90; symbol: func_ov031_02231d90; size: 0x38.
extern "C" void ClearPendingByteWhenConditionFalse(void) {
    if (AreInputMaskBitsHeld(2)) {
        SetPendingByteIfInvalid(0);
        return;
    }
    if (ReadHighBitOfHalfwordAt027FFFA8()) SetPendingByteIfInvalid(0);
}
