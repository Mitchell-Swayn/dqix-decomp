#include <globaldefs.h>
extern "C" unsigned char data_ov031_02290c58[];
extern "C" void Graphics_LoadBG2AndSetFiveBackgroundPriorities();
extern "C" void System_CreateCopyAndFinalizeResource(int);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void func_ov031_02228664();
// Original: arm9/ov031 @ 0x0222859C; symbol: func_ov031_0222859c; size: 0x48.
extern "C" void OV031_InitializeFinalCallback(void) {
    *data_ov031_02290c58 = 0;
    Graphics_LoadBG2AndSetFiveBackgroundPriorities();
    System_CreateCopyAndFinalizeResource(0x12);
    func_ov031_0222336c(0x3b, -1, 0);
    Graphics_SubmitIndexedConfiguredBuffer(0x17);
    SetMainLoopCallback(func_ov031_02228664);
}
