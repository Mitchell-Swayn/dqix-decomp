#include <globaldefs.h>
ARM
extern "C" ARM int AreInputMaskBitsHeld(unsigned int);
extern "C" void SetPendingByteIfInvalid(unsigned int);
// Original: arm9/ov031 @ 0x02229B10; symbol: func_ov031_02229b10; size: 0x20.
extern "C" void func_ov031_02229b10(void) {
    if (AreInputMaskBitsHeld(1)) SetPendingByteIfInvalid(0);
}
