#include <globaldefs.h>
ARM
extern "C" void WfcUtility_RunEmptyMessageCompletionPreludeHook(void);
extern "C" void WfcUtility_RunEmptyMessageCompletionEpilogueHook(void);
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void System_ConfigureMode3AndPlaneMask0x14WhenNoSharedObject(void);
// Original: arm9/ov031 @ 0x02234260; symbol: func_ov031_02234260; size: 0x3C.
extern "C" void WfcUtility_CreateDisplayResourceAfterMessageCompletion(void) {
    WfcUtility_RunEmptyMessageCompletionPreludeHook();
    WfcUtility_RunEmptyMessageCompletionEpilogueHook();
    if (WfcUtility_GetDialogSelectionResult())
        return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    CreateSharedDisplayResource();
    WfcUtility_PlaySequenceArchiveEntry(6);
    WfcUtility_SetMainLoopCallback((void*)System_ConfigureMode3AndPlaneMask0x14WhenNoSharedObject);
}
