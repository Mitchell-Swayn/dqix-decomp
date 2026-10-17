#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void System_InstallContextCallbackWhenIdle(void);
// Original: arm9/ov031 @ 0x0222818C; symbol: func_ov031_0222818c; size: 0x54.
extern "C" void Overlay_SetDisplayPlanesAndContinue(void) {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x14, 8);
    EnableDisplayControlPlaneBits(1, 1);
    EnableDisplayControlPlaneBits(0, 0x14);
    SetMainLoopCallback((void*)System_InstallContextCallbackWhenIdle);
}
