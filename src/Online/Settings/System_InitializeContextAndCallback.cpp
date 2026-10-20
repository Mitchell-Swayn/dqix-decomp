#include <globaldefs.h>
ARM
extern "C" void Graphics_LoadMultiBackgroundScreenAndSetPriorities(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int value);
extern "C" void WfcUtility_InitializeConnectionProfilesAndHeaders(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void System_ConfigureDisplayAndInstallScreenZeroContextCallback(void);
// Original: arm9/ov031 @ 0x02228980; symbol: func_ov031_02228980; size: 0x24.
extern "C" void System_InitializeContextAndCallback(void) {
    Graphics_LoadMultiBackgroundScreenAndSetPriorities();
    Graphics_SubmitIndexedConfiguredBuffer(0x19);
    WfcUtility_InitializeConnectionProfilesAndHeaders();
    WfcUtility_SetMainLoopCallback(System_ConfigureDisplayAndInstallScreenZeroContextCallback);
}
