#include <globaldefs.h>
ARM

extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void System_InstallCallbackWhenSelectedContextByte9Zero(void);

// Original: arm9/ov031 @ 0x02229EF0; symbol: func_ov031_02229ef0; size: 0x54.
extern "C" void System_ConfigureDualDisplayPlanes(void) {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(1, 1);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(System_InstallCallbackWhenSelectedContextByte9Zero);
}
