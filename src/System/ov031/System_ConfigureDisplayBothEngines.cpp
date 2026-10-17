#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void System_InstallContextCallbackWhenIdleThird();
// Original: arm9/ov031 @ 0x0222BA8C; symbol: func_ov031_0222ba8c; size: 0x54.
extern "C" void System_ConfigureDisplayBothEngines(void) {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x1d, 8);
    EnableDisplayControlPlaneBits(1, 1);
    EnableDisplayControlPlaneBits(0, 0x1d);
    SetMainLoopCallback(System_InstallContextCallbackWhenIdleThird);
}
