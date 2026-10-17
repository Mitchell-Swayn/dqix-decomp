#include <globaldefs.h>
ARM
extern "C" void func_ov031_0222b168(void);
extern "C" void func_ov031_0222b1a0(void);
extern "C" void func_ov031_0222b1a4(void);
extern "C" void DispatchGlobalPointerOffset94WithZero(void);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_0222b1f0(void);
struct SetupCounter { unsigned short reserved; unsigned short value; };
extern "C" volatile struct SetupCounter data_ov031_02290c80;
// Original: arm9/ov031 @ 0x0222B3D4; symbol: func_ov031_0222b3d4; size: 0x4C.
extern "C" void System_AdvanceSetupAndInstallCallback(void) {
    func_ov031_0222b168();
    func_ov031_0222b1a0();
    func_ov031_0222b1a4();
    data_ov031_02290c80.value = data_ov031_02290c80.value + 1;
    if (data_ov031_02290c80.value < 0x438) return;
    DispatchGlobalPointerOffset94WithZero();
    SetMainLoopCallback(func_ov031_0222b1f0);
}
