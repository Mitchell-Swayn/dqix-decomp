#include <globaldefs.h>
ARM
extern "C" void _Z19SleepCurrentContextj(unsigned int);
extern "C" void DispatchOverlayStateTransition(void);
extern "C" void WfcUtility_RequestValidatedScreenCancelFromInput(void);
extern "C" void WfcUtility_ReturnFromValidatedScreenPollingHook(void);
extern "C" void System_EnterModeSevenAndInstallConditionalLayerCallback(void);
// Original: arm9/ov031 @ 0x0223169C; symbol: System_SleepTenAndRunStateHandlers; size: 0x20.
// Sleeps the current context for 10 units, then calls four state handlers in order.
extern "C" void System_SleepTenAndRunStateHandlers(void) {
    _Z19SleepCurrentContextj(0xa);
    DispatchOverlayStateTransition();
    WfcUtility_RequestValidatedScreenCancelFromInput();
    WfcUtility_ReturnFromValidatedScreenPollingHook();
    System_EnterModeSevenAndInstallConditionalLayerCallback();
}
