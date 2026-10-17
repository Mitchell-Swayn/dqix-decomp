#include <globaldefs.h>
ARM

extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void System_InitializeActionWhenBothContextsClear(void);

// Original: arm9/ov031 @ 0x02230FB4; symbol: func_ov031_02230fb4; size: 0x54.
extern "C" void System_ConfigureDisplayPlanesMask14(void) {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x14, 8);
    EnableDisplayControlPlaneBits(1, 1);
    EnableDisplayControlPlaneBits(0, 0x14);
    SetMainLoopCallback(System_InitializeActionWhenBothContextsClear);
}
