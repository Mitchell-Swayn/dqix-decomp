#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int screen);
extern "C" int IsGlobalControlAbsentOrByte19Clear(void);
extern "C" void func_ov031_0223c7c4(int screen);
extern "C" void ClearDisplayPlaneMask(unsigned engine, unsigned mask);
extern "C" void SetSharedWords10And14(unsigned a, unsigned b);
extern "C" void System_InitializeMenuWithResetAndCallback(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02229DD8; symbol: func_ov031_02229dd8; size: 0x50.
extern "C" void System_InstallCallbackWhenContextReady(void) {
    if (ReadSelectedContextByte9(0) != 0)
        return;
    if (!IsGlobalControlAbsentOrByte19Clear())
        return;
    func_ov031_0223c7c4(0);
    ClearDisplayPlaneMask(0, 0x15);
    SetSharedWords10And14(0, 1);
    SetMainLoopCallback(System_InitializeMenuWithResetAndCallback);
}
