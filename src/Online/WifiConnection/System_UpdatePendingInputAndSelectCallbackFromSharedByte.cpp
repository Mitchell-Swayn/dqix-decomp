#include <globaldefs.h>
ARM
extern "C" void System_UpdatePendingInputState(void);
extern "C" void WfcUtility_RunEmptySelectionInputHook(void);
extern "C" void Overlay_SelectCallbackFromSharedByte(void);
// Original: arm9/ov031 @ 0x022346D0; symbol: System_UpdatePendingInputAndSelectCallbackFromSharedByte; size: 0x14.
// Updates pending input state and selects the callback using the shared byte.
extern "C" void System_UpdatePendingInputAndSelectCallbackFromSharedByte(void) {
    System_UpdatePendingInputState();
    WfcUtility_RunEmptySelectionInputHook();
    Overlay_SelectCallbackFromSharedByte();
}
