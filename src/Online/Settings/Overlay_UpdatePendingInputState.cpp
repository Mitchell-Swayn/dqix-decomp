#include <globaldefs.h>
ARM
extern "C" void WfcUtility_ReadMultiScreenConfirmCancel(void);
extern "C" void WfcUtility_RunMultiScreenInputHook(void);
extern "C" void WfcUtility_DispatchMultiScreenChoice(void);
// Original: arm9/ov031 @ 0x0222871C; symbol: func_ov031_0222871c; size: 0x14.
extern "C" void Overlay_UpdatePendingInputState(void) {
    WfcUtility_ReadMultiScreenConfirmCancel();
    WfcUtility_RunMultiScreenInputHook();
    WfcUtility_DispatchMultiScreenChoice();
}
