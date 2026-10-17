#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void InitializeOverlaySelectionState(void);
extern "C" void SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x022334E8; symbol: func_ov031_022334e8; size: 0x28.
extern "C" void ClearControlAndRegisterCallback33510UnlessValueMinusTwo(void) {
    if (ReadSharedSignedByteAtOffset22() != -2) {
        ClearGlobalControlByte18();
        SetMainLoopCallback(InitializeOverlaySelectionState);
    }
}
