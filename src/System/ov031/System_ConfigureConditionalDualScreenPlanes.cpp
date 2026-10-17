#include <globaldefs.h>
ARM

extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void Overlay_StartContextModeThree(void);
extern "C" unsigned char data_ov031_02290c74[];

// Original: arm9/ov031 @ 0x0222A418; symbol: func_ov031_0222a418; size: 0x68.
extern "C" void System_ConfigureConditionalDualScreenPlanes(void) {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    if (data_ov031_02290c74[0] != 0) {
        func_ov031_0223c078(2, 1, 1, 8);
        EnableDisplayControlPlaneBits(1, 1);
    }
    SetMainLoopCallback(Overlay_StartContextModeThree);
}
