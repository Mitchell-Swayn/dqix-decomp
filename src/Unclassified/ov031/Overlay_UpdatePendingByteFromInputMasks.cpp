#include <globaldefs.h>
ARM
extern "C" int AreInputMaskBitsHeld(unsigned int mask);
extern "C" void SetPendingByteIfInvalid(signed char value);
// Original: arm9/ov031 @ 0x02228730; symbol: func_ov031_02228730; size: 0x38.
extern "C" void Overlay_UpdatePendingByteFromInputMasks(void) {
    if (AreInputMaskBitsHeld(1)) SetPendingByteIfInvalid(1);
    if (AreInputMaskBitsHeld(2)) SetPendingByteIfInvalid(0);
}
