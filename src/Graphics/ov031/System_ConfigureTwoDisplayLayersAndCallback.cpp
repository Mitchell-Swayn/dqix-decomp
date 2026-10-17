#include <globaldefs.h>
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void System_InstallContextCallbackWhenIdleFourth();
// Original: arm9/ov031 @ 0x02233458; symbol: func_ov031_02233458; size: 0x54.
extern "C" void System_ConfigureTwoDisplayLayersAndCallback() {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x14, 8);
    EnableDisplayControlPlaneBits(1, 1);
    EnableDisplayControlPlaneBits(0, 0x14);
    SetMainLoopCallback(System_InstallContextCallbackWhenIdleFourth);
}
