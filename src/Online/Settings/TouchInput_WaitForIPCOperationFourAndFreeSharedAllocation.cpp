#include <globaldefs.h>
ARM
extern "C" void TouchInput_RequestIPCOperationFour();
extern "C" void TP_WaitBusy(unsigned);
extern "C" unsigned TP_CheckError(unsigned);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void**);
// Original data: arm9/ov031 @ 0x2290d44; symbol: data_ov031_02290d44.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char TouchInputWaitForIPCOperationFourAndFreeSharedAllocation_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0223D06C; symbol: func_ov031_0223d06c; size: 0x38.
extern "C" void TouchInput_WaitForIPCOperationFourAndFreeSharedAllocation(void) {
    do {
        TouchInput_RequestIPCOperationFour();
        TP_WaitBusy(4);
    } while (TP_CheckError(4) != 0);
    WfcUtility_FreeAllocationAndClearPointer((void**)TouchInputWaitForIPCOperationFourAndFreeSharedAllocation_UnknownRoleZeroInitializedStorage);
}
