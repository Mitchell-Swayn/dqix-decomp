#include <globaldefs.h>
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void System_InstallCallback0223442CIfScreenContextClear();
// Original: arm9/ov031 @ 0x022343D4; symbol: func_ov031_022343d4; size: 0x34.
extern "C" void System_ConfigureDisplayAndRegisterMainLoopB() {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(System_InstallCallback0223442CIfScreenContextClear);
}
