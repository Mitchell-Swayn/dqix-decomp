#include <globaldefs.h>
ARM
extern "C" void Overlay_UpdatePendingByteFromInputMasks(void);
extern "C" void func_ov031_02228768(void);
extern "C" void System_TransitionSharedByte22State(void);
// Original: arm9/ov031 @ 0x0222871C; symbol: func_ov031_0222871c; size: 0x14.
extern "C" void Overlay_UpdatePendingInputState(void) {
    Overlay_UpdatePendingByteFromInputMasks();
    func_ov031_02228768();
    System_TransitionSharedByte22State();
}
