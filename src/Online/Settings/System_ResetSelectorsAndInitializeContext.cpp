#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_SetCallbackQueueEnabled(int,int);
extern "C" void Memory_FreeIndexedGlobalPointerAndClear(int);
extern "C" void WfcUtility_FreeBackgroundHighlightBuffer(void);
extern "C" void DestroySharedObjectSlotsAndFreeAllocation(void);
extern "C" void System_UpdateObjectAndGlobalContext(void*);
extern "C" void WfcUtility_FreeMessageTablePool(void);
extern "C" void Memory_FreeSharedAllocationAndClearFlag(void);
extern "C" void WfcUtility_RequestModalExit(void);
// Original data: arm9/ov031 @ 0x2290c4c; symbol: data_ov031_02290c4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02227D20; symbol: System_ResetSelectorsAndInitializeContext; size: 0x74.
// When context byte 9 is clear for both screens, resets selectors and runs the initialization and cleanup helper sequence.
extern "C" void System_ResetSelectorsAndInitializeContext(void) {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (WfcUtility_IsScreenTransitionBusy(0)) return;
    WfcUtility_SetCallbackQueueEnabled(0,0); WfcUtility_SetCallbackQueueEnabled(1,0);
    Memory_FreeIndexedGlobalPointerAndClear(1); Memory_FreeIndexedGlobalPointerAndClear(0);
    WfcUtility_FreeBackgroundHighlightBuffer(); DestroySharedObjectSlotsAndFreeAllocation();
    System_UpdateObjectAndGlobalContext((void*)WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage); WfcUtility_FreeMessageTablePool();
    Memory_FreeSharedAllocationAndClearFlag(); WfcUtility_RequestModalExit();
}
