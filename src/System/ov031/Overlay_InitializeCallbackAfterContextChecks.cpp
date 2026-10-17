#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void func_ov031_0223c7c4(int value);
extern "C" void Overlay_ProcessPendingFlag(void);
extern "C" void ClearDisplayPlaneMask(unsigned int engine, unsigned int mask);
extern "C" void SetSharedWords10And14(unsigned int a, unsigned int b);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0222905c(void);
// Original: arm9/ov031 @ 0x0222A2C4; symbol: func_ov031_0222a2c4; size: 0x64.
extern "C" void Overlay_InitializeCallbackAfterContextChecks(void) {
    if (ReadSelectedContextByte9(1) != 0 || ReadSelectedContextByte9(0) != 0) {
        return;
    }
    func_ov031_0223c7c4(0);
    Overlay_ProcessPendingFlag();
    ClearDisplayPlaneMask(1, 1);
    ClearDisplayPlaneMask(0, 0x15);
    SetSharedWords10And14(0, 1);
    SetMainLoopCallback(func_ov031_0222905c);
}
