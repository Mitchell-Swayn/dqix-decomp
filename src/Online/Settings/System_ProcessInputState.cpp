#include <globaldefs.h>
ARM
extern "C" void WfcUtility_HandleIpv4EditorInput(void);
extern "C" void WfcUtility_RunEmptyIpv4EditorUpdateHook(void);
// Original: arm9/ov031 @ 0x0222DA50; symbol: System_ProcessInputState; size: 0x10.
// Processes the current input state and then calls the adjacent empty routine.
extern "C" void System_ProcessInputState(void) {
    WfcUtility_HandleIpv4EditorInput();
    WfcUtility_RunEmptyIpv4EditorUpdateHook();
}
