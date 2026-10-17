#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290c6c[];
extern "C" void Graphics_InitializeBG2ScreenLoaderAndPriorities(void);
extern "C" void System_CreateCopyAndFinalizeResource(int);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void System_ConfigureDualDisplayPlanes(void);
// Original: arm9/ov031 @ 0x02229E28; symbol: func_ov031_02229e28; size: 0x48.
extern "C" void Overlay_InitializeStartupSceneAndRegisterCallback(void) {
    data_ov031_02290c6c[0] = 0;
    Graphics_InitializeBG2ScreenLoaderAndPriorities();
    System_CreateCopyAndFinalizeResource(0x13);
    int mode = 0x3c;
    int offset = mode - 0x3d;
    func_ov031_0222336c(mode, offset, 0);
    Graphics_SubmitIndexedConfiguredBuffer(0x1b);
    SetMainLoopCallback(System_ConfigureDualDisplayPlanes);
}
