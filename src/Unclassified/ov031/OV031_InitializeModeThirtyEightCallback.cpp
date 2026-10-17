#include <globaldefs.h>
extern "C" void Graphics_LoadMainBG2AndSetBackgroundPriorities();
extern "C" void System_CreateCopyAndFinalizeResource(int);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_02228c60();
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void func_ov031_02228e64();
// Original: arm9/ov031 @ 0x02228BAC; symbol: func_ov031_02228bac; size: 0x34.
extern "C" void OV031_InitializeModeThirtyEightCallback(void) {
    Graphics_LoadMainBG2AndSetBackgroundPriorities();
    System_CreateCopyAndFinalizeResource(0x11);
    func_ov031_0222336c(0x3a, -1, 0);
    func_ov031_02228c60();
    SetMainLoopCallback(func_ov031_02228e64);
}
