#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void System_RunContextStartupSequence(void*,void*);
extern "C" void WfcUtility_UpdateSetupTaskStatus(void);
// Original data: arm9/ov031 @ 0x2290c80; symbol: data_ov031_02290c80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222B04C; symbol: Unclassified_RegisterTimedCallbackWhenSharedByteValid; size: 0x48.
// Unless the shared signed byte is -2, registers a mode-1 callback with timeout 0x78, stores its handle in data_ov031_02290c80[1], and sets the main-loop callback.
extern "C" void WfcUtility_ScheduleSetupPollingTask(void) {
    if (WfcUtility_GetBottomButtonSelection() == -2) return;
    void* handle = WfcUtility_CreateTaskWithBorrowedContext(1, System_RunContextStartupSequence, 0, 0x78);
    WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[1] = (unsigned int)handle;
    WfcUtility_SetMainLoopCallback((void*)WfcUtility_UpdateSetupTaskStatus);
}
