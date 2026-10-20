#include <globaldefs.h>
ARM
extern "C" void WfcConnectionMethod_ProcessChooserInput(void);
extern "C" void WfcConnectionMethod_ReturnFromInputFollowupHook(void);
extern "C" void WfcConnectionMethod_DispatchChooserResult(void);
// Original: arm9/ov031 @ 0x02233510; symbol: func_ov031_02233510; size: 0x14.
extern "C" void InitializeOverlaySelectionState(void) {
    WfcConnectionMethod_ProcessChooserInput();
    WfcConnectionMethod_ReturnFromInputFollowupHook();
    WfcConnectionMethod_DispatchChooserResult();
}
