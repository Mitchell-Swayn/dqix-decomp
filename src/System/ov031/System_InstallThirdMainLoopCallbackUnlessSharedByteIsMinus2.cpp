#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void UpdateOverlaySelectionState(void);
extern "C" void SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x0222BB1C; symbol: func_ov031_0222bb1c; size: 0x28.
extern "C" void System_InstallThirdMainLoopCallbackUnlessSharedByteIsMinus2(void) {
    if (ReadSharedSignedByteAtOffset22() != -2) {
        ClearGlobalControlByte18();
        SetMainLoopCallback((void *)UpdateOverlaySelectionState);
    }
}
