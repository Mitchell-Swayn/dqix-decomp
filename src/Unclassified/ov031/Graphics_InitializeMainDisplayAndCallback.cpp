#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_02229aa8(void);
// Original: arm9/ov031 @ 0x02229A74; symbol: func_ov031_02229a74; size: 0x34.
extern "C" void Graphics_InitializeMainDisplayAndCallback(void) {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(func_ov031_02229aa8);
}
