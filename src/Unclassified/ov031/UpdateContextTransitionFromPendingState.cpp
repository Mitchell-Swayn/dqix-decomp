#include <globaldefs.h>
ARM
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned int);
extern "C" void func_ov031_0223a374(void);
extern "C" int System_ValidateGlobalSlotOrFallbackTransition(void);
extern "C" void SetStateWithTransitionCallbacks(int);
// Original: arm9/ov031 @ 0x02239AA4; symbol: func_ov031_02239aa4; size: 0x34.
extern "C" void UpdateContextTransitionFromPendingState(void *state) {
    unsigned short value = *(unsigned short *)((char *)state + 2);
    if (value != 0) {
        SetSharedObjectWord54UnlessStateNineOrTen(value);
        func_ov031_0223a374();
        return;
    }
    if (System_ValidateGlobalSlotOrFallbackTransition() == 0) SetStateWithTransitionCallbacks(9);
}
