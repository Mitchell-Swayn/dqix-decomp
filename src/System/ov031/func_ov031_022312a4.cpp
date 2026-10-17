#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int);
extern "C" int func_ov031_02231120(void);
extern "C" void SetPendingByteIfInvalid(int);
// Original: arm9/ov031 @ 0x022312A4; symbol: func_ov031_022312a4; size: 0x38.
extern "C" void func_ov031_022312a4(void) {
    if (AreInputMaskBitsHeld(2)) {
        SetPendingByteIfInvalid(0);
        return;
    }
    if (func_ov031_02231120()) SetPendingByteIfInvalid(0);
}
