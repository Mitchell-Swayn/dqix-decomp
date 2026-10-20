#include <globaldefs.h>
ARM
extern "C" int System_StopSharedWorkerAndReleasePendingAllocation(void);
extern "C" void DisableInterruptsAndHaltForever(void);
// Original data: arm9/ov031 @ 0x2290c48; symbol: data_ov031_02290c48.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityCopyNetworkTaskResult_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original: arm9/ov031 @ 0x02227BA4; symbol: func_ov031_02227ba4; size: 0x24.
extern "C" void System_ValidateThenFreeSharedGlobalAllocation(void) {
    if (System_StopSharedWorkerAndReleasePendingAllocation() != 1)
        DisableInterruptsAndHaltForever();
    WfcUtility_FreeAllocationAndClearPointer((void **)WfcUtilityCopyNetworkTaskResult_UnknownRoleZeroInitializedStorage);
}
