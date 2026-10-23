#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int screen);
// Original data: arm9/ov031 @ 0x2290c78; symbol: data_ov031_02290c78.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[];
extern "C" void* WfcUtility_ScheduleConnectionActivation(void);
extern "C" void WfcUtility_ContinueConnectionStateMachine(void);
extern "C" void System_TransitionPendingScreenByTwoSharedFlags(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x0222A964; symbol: func_ov031_0222a964; size: 0x5C.
extern "C" void System_SelectMainLoopFromContextState(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0)
        return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0)
        return;
    if (ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[0] == 0 && ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[1] == 1)
        WfcUtility_ContinueConnectionStateMachine();
    else
        WfcUtility_ScheduleConnectionActivation();
    WfcUtility_SetMainLoopCallback(System_TransitionPendingScreenByTwoSharedFlags);
}
