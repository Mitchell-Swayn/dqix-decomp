#include <globaldefs.h>
ARM
extern "C" void WfcUtility_QueueChoiceFromConfirmAndCancel(void);
extern "C" void WfcUtility_RunEmptyChoiceUpdateHook(void);
extern "C" void DispatchModeFromSharedByteState(void);
// Original: arm9/ov031 @ 0x02229F98; symbol: func_ov031_02229f98; size: 0x14.
extern "C" void System_RunInputStateHelpers(void) {
    WfcUtility_QueueChoiceFromConfirmAndCancel();
    WfcUtility_RunEmptyChoiceUpdateHook();
    DispatchModeFromSharedByteState();
}
