#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d10; symbol: data_ov031_02290d10.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned* WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_RequestTaskRemoval(unsigned,void*);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
extern "C" void IncrementGlobalCounterAndNotifyAtEight(void*,void*);
// Original: arm9/ov031 @ 0x02237E58; symbol: func_ov031_02237e58; size: 0x44.
extern "C" void CreateSharedDisplayResource() {
    WfcUtility_RequestTaskRemoval(0, ((void**)WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage)[5]);
    ((void**)WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage)[5] = WfcUtility_CreateTaskWithBorrowedContext(1, IncrementGlobalCounterAndNotifyAtEight, 0, 0x78);
}
