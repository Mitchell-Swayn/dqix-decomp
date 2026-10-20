#include <globaldefs.h>
ARM
extern "C" void Graphics_SetMainAndSubBackgroundPrioritiesThree(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void Graphics_InitializeMainDisplayAndCallback(void);
// Original: arm9/ov031 @ 0x022299EC; symbol: Graphics_SubmitConfiguredBuffer31AndRegisterDisplayCallback; size: 0x20.
// Runs the preceding setup, submits configured buffer index 0x1F, and installs the main-loop callback.
extern "C" void Graphics_SubmitConfiguredBuffer31AndRegisterDisplayCallback(void) {
    Graphics_SetMainAndSubBackgroundPrioritiesThree();
    Graphics_SubmitIndexedConfiguredBuffer(0x1f);
    WfcUtility_SetMainLoopCallback(Graphics_InitializeMainDisplayAndCallback);
}
