#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5d8; symbol: data_ov031_0224e5d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage;
extern "C" int WM_End(unsigned int value);
// Original: arm9/ov031 @ 0x02216070; symbol: func_ov031_02216070; size: 0x40.
extern "C" int System_SubmitOperationWithStateCleanup(unsigned int value) {
    if (value == 0)
        return -1;
    *(unsigned int*)((char*)UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage + 0x1a90) = 3;
    UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage = 0;
    int result = WM_End(value);
    if (result == 2)
        result = 0;
    return result;
}
