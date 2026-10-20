#include <globaldefs.h>
ARM
extern "C" void UpdatePendingByteFromInput(void);
extern "C" void WfcUtility_RunEmptyResponsePromptUpdateHook(void);
extern "C" void SetFlagAndDispatchModeFromSharedByte(void);
// Original: arm9/ov031 @ 0x0222A4F0; symbol: Overlay_UpdatePendingInputAndSelectMainLoopCallback; size: 0x14.
// Updates the pending input byte, then selects the main-loop callback from the shared byte.
extern "C" void WfcUtility_UpdateResponsePromptInput(void) {
    UpdatePendingByteFromInput();
    WfcUtility_RunEmptyResponsePromptUpdateHook();
    SetFlagAndDispatchModeFromSharedByte();
}
