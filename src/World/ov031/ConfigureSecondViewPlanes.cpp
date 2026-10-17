#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void System_InstallContextCallbackWhenIdleAlternate();
// Original: arm9/ov031 @ 0x022292C0; symbol: func_ov031_022292c0; size: 0x54.
extern "C" void ConfigureSecondViewPlanes() {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x14, 8);
    EnableDisplayControlPlaneBits(1, 1);
    EnableDisplayControlPlaneBits(0, 0x14);
    SetMainLoopCallback((void*)System_InstallContextCallbackWhenIdleAlternate);
}
