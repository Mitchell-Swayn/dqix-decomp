#include <globaldefs.h>
ARM
extern "C" void WfcUtility_UpdateButtonInput(void);
extern "C" void TouchInput_UpdateHeldPressedReleasedAndRepeat(void);
// Original: arm9/ov031 @ 0x0223D0A4; symbol: func_ov031_0223d0a4; size: 0x10.
extern "C" void Math_InitializeDivisionAndInverseSupport(void) {
    WfcUtility_UpdateButtonInput();
    TouchInput_UpdateHeldPressedReleasedAndRepeat();
}
