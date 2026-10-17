#include <globaldefs.h>
extern "C" void SetStateWithTransitionCallbacks(int);
extern "C" int ValidateSlotAgainstSharedMaskAndSubmit(int, unsigned);
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned);
extern "C" void func_ov031_0223a358();
extern "C" unsigned char System_SetStateFromHalfword2[];
// Original: arm9/ov031 @ 0x02239AD8; symbol: func_ov031_02239ad8; size: 0x38.
extern "C" int System_ValidateGlobalSlotOrFallbackTransition() {
    SetStateWithTransitionCallbacks(3);
    int result = ValidateSlotAgainstSharedMaskAndSubmit((int)System_SetStateFromHalfword2, 0);
    if (result == 2) return 1;
    SetSharedObjectWord54UnlessStateNineOrTen((unsigned)result);
    func_ov031_0223a358();
    return 0;
}
