#include <globaldefs.h>
ARM
extern "C" void Graphics_LoadMainBG2DataAndSetBackgroundPriorities(void);
extern "C" void func_ov031_0222e484(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0222e7f8(void);
// Original: arm9/ov031 @ 0x0222E3E8; symbol: func_ov031_0222e3e8; size: 0x1C.
extern "C" void System_InitializeAndInstallMainLoopCallback(void) {
    Graphics_LoadMainBG2DataAndSetBackgroundPriorities();
    func_ov031_0222e484();
    SetMainLoopCallback(func_ov031_0222e7f8);
}
