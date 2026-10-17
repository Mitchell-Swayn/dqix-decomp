#include <globaldefs.h>
ARM
extern "C" void ClearPendingByteWhenSecondaryReleased(void);
extern "C" void func_ov031_0222ac58(void);
extern "C" void System_StartSequenceWhenSharedByteZero(void);
// Original: arm9/ov031 @ 0x0222AC0C; symbol: func_ov031_0222ac0c; size: 0x14.
extern "C" void System_RunThreeInitializationHelpers(void) {
    ClearPendingByteWhenSecondaryReleased();
    func_ov031_0222ac58();
    System_StartSequenceWhenSharedByteZero();
}
