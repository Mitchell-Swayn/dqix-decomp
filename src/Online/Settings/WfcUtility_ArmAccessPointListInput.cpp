#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcScrollbar_EnableTouchInput(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void UpdateOverlaySelectionState(void);
// Original: arm9/ov031 @ 0x0222CBB8; symbol: Unclassified_ClearControlAndStartSelectionStateWhenObjectAbsent; size: 0x28.
// When no shared object pointer exists, clears control byte 0x18, clears byte +0x1E of the object referenced by the global pair, then installs the callback that updates selection state.
extern "C" void WfcUtility_ArmAccessPointListInput(void) {
    if (!WfcUtility_IsDialogActive()) {
        WfcUtility_EnableBottomButtonTouch();
        WfcScrollbar_EnableTouchInput();
        WfcUtility_SetMainLoopCallback(UpdateOverlaySelectionState);
    }
}
