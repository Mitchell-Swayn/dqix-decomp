#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void System_InstallAlternateCallbackWhenSelectedContextByte9Zero();
// Original: arm9/ov031 @ 0x02234A08; symbol: func_ov031_02234a08; size: 0x34.
extern "C" void System_ConfigureDisplayPlaneAndCallbackTwo(void) {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(System_InstallAlternateCallbackWhenSelectedContextByte9Zero);
}
