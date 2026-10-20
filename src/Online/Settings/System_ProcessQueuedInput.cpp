#include <globaldefs.h>
ARM
extern "C" void WfcUtility_HandleWirelessTextEditorInput(void);
extern "C" void WfcUtility_RunEmptyWirelessTextEditorUpdateHook(void);
// Original: arm9/ov031 @ 0x0222CEC0; symbol: System_ProcessQueuedInput; size: 0x10.
// Runs the queued-input dispatcher and its following empty routine.
extern "C" void System_ProcessQueuedInput(void) {
    WfcUtility_HandleWirelessTextEditorInput();
    WfcUtility_RunEmptyWirelessTextEditorUpdateHook();
}
