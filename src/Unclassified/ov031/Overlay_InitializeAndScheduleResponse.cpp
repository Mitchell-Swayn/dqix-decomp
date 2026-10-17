#include <globaldefs.h>
ARM
extern "C" void Graphics_LoadBG2AndSetFiveBackgroundPriorities_Ov0310222A398(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned);
extern "C" unsigned func_ov031_0222336c(unsigned, int, unsigned);
extern "C" unsigned char data_ov031_02290c74;
extern "C" void SetMainLoopCallback(void*);
extern "C" void System_ConfigureConditionalDualScreenPlanes(void);
// Original: arm9/ov031 @ 0x0222A35C; symbol: func_ov031_0222a35c; size: 0x3C.
extern "C" void Overlay_InitializeAndScheduleResponse(void) {
    Graphics_LoadBG2AndSetFiveBackgroundPriorities_Ov0310222A398();
    Graphics_SubmitIndexedConfiguredBuffer(0x20);
    data_ov031_02290c74 = (unsigned char)func_ov031_0222336c(0x3c, -1, 0);
    SetMainLoopCallback((void*)System_ConfigureConditionalDualScreenPlanes);
}
