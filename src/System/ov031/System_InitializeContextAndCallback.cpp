#include <globaldefs.h>
ARM
extern "C" void Graphics_LoadMultiBackgroundScreenAndSetPriorities(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int value);
extern "C" void func_ov031_022364c0(void);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void func_ov031_02228a24(void);
// Original: arm9/ov031 @ 0x02228980; symbol: func_ov031_02228980; size: 0x24.
extern "C" void System_InitializeContextAndCallback(void) {
    Graphics_LoadMultiBackgroundScreenAndSetPriorities();
    Graphics_SubmitIndexedConfiguredBuffer(0x19);
    func_ov031_022364c0();
    SetMainLoopCallback(func_ov031_02228a24);
}
