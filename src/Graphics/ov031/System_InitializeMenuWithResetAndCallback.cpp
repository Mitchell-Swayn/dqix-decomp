#include <globaldefs.h>
extern "C" void func_ov031_022276f8(void (*)());
extern "C" void System_InitializeModeCallbacks();
extern "C" unsigned char data_ov031_02290c7c;
extern "C" void Graphics_LoadMainBG2ScreenAndSetPriorities();
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void func_ov031_02222b0c(int);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void InitializeOverlayDisplay();
// Original: arm9/ov031 @ 0x0222AABC; symbol: func_ov031_0222aabc; size: 0x4C.
extern "C" void System_InitializeMenuWithResetAndCallback() {
    func_ov031_022276f8(System_InitializeModeCallbacks);
    data_ov031_02290c7c = 0;
    Graphics_LoadMainBG2ScreenAndSetPriorities();
    Graphics_SubmitIndexedConfiguredBuffer(0x1c);
    func_ov031_02222b0c(0);
    System_ResolveGlobalGroupEntry(0xb);
    SetMainLoopCallback(InitializeOverlayDisplay);
}
