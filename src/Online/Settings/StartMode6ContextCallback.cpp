#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void CreateSharedDisplayResource();
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char StartMode6ContextCallback_UnknownRoleZeroInitializedStorage;
extern "C" void System_StoreValueAndScheduleTimedCallback(void*);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_SetMainLoopCallbackWhenNoSharedObject();
// Original: arm9/ov031 @ 0x02230E90; symbol: StartMode6ContextCallback; size: 0x40.
// When the shared signed byte is clear, selects mode 6, updates the overlay object from shared context, and installs the next callback.
extern "C" void StartMode6ContextCallback() {
    if (WfcUtility_GetDialogSelectionResult()) return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    CreateSharedDisplayResource();
    void* object = *(void**)((char*)&StartMode6ContextCallback_UnknownRoleZeroInitializedStorage + 8);
    System_StoreValueAndScheduleTimedCallback(*(void**)((char*)object + 0xc));
    WfcUtility_SetMainLoopCallback(System_SetMainLoopCallbackWhenNoSharedObject);
}
