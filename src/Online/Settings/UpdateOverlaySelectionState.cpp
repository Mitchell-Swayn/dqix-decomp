#include <globaldefs.h>
ARM
extern "C" void WfcUtility_HandleAccessPointListInput(void);
extern "C" void WfcUtility_HandleAccessPointListScrollActions(void);
extern "C" void WfcUtility_DispatchAccessPointSelection(void);
// Original: arm9/ov031 @ 0x0222BB44; symbol: func_ov031_0222bb44; size: 0x14.
extern "C" void UpdateOverlaySelectionState(void) {
    WfcUtility_HandleAccessPointListInput();
    WfcUtility_HandleAccessPointListScrollActions();
    WfcUtility_DispatchAccessPointSelection();
}
