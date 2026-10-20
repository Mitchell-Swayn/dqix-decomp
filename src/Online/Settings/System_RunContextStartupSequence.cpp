#include <globaldefs.h>
ARM
extern "C" void Math_InitializeDivisionAndInverseSupport(void);
extern "C" void WfcUtility_RunTaskQueue(int value);
extern "C" void WfcUtility_QueueSetupCancelFromButtonOrSystemGate(void);
extern "C" void WfcUtility_CancelSetupTaskAndBeginExit(void);
// Original: arm9/ov031 @ 0x0222B36C; symbol: func_ov031_0222b36c; size: 0x1C.
extern "C" void System_RunContextStartupSequence(void) {
    Math_InitializeDivisionAndInverseSupport();
    WfcUtility_RunTaskQueue(0);
    WfcUtility_QueueSetupCancelFromButtonOrSystemGate();
    WfcUtility_CancelSetupTaskAndBeginExit();
}
