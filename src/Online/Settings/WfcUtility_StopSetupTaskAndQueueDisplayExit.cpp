#include <globaldefs.h>
ARM
#pragma force_active on
// Original data: arm9/ov031 @ 0x02290c80; symbol: data_ov031_02290c80.
// Initial value: zero-filled at load; runtime pointer or shared state storage.
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
extern "C" void WfcUtility_DisableBottomButtonTouch(void);
extern "C" void WfcUtility_RemoveTaskImmediately(unsigned, void *);
extern "C" int System_QueueTimedCallbackForSharedRecord(unsigned short);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_BeginSetupPromptFadeOut(void);
extern "C" unsigned char WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222B1F0; symbol: func_ov031_0222b1f0; size: 0x3C.
// Stops the setup task and schedules the prompt fade-out callback.
extern "C" void WfcUtility_StopSetupTaskAndQueueDisplayExit(void)
{
    WfcUtility_DisableBottomButtonTouch();
    void *task = *(void **)(WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage + 4);
    if (task != 0) WfcUtility_RemoveTaskImmediately(1, task);
    System_QueueTimedCallbackForSharedRecord(8);
    WfcUtility_SetMainLoopCallback(WfcUtility_BeginSetupPromptFadeOut);
}
#pragma force_active reset
