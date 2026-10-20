#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcKeyboard_StartSlideOut(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_DispatchWirelessTextValidationResult(void);
// Original: arm9/ov031 @ 0x0222D0B0; symbol: System_InstallMode0x15CallbackWhenScreen1ContextByte9IsZero; size: 0x30.
// When screen 1 context byte 9 is zero, initializes global components, resolves entry 0x15, and registers the follow-up callback.
extern "C" void System_InstallMode0x15CallbackWhenScreen1ContextByte9IsZero(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    WfcKeyboard_StartSlideOut();
    WfcUtility_PlaySequenceArchiveEntry(0x15);
    WfcUtility_SetMainLoopCallback(WfcUtility_DispatchWirelessTextValidationResult);
}
