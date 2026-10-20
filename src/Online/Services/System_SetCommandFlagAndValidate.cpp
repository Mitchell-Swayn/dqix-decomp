#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5d8; symbol: data_ov031_0224e5d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage;
extern "C" int WM_EndScan(void *);
// Original: arm9/ov031 @ 0x02216178; symbol: func_ov031_02216178; size: 0x38.
extern "C" int System_SetCommandFlagAndValidate(void *param) {
    if (param == 0) return -1;
    *(int *)((unsigned char *)UtilCopyReadyContextRecords_UnknownRoleZeroInitializedStorage + 0x1A90) = 2;
    int result = WM_EndScan(param);
    if (result == 2) result = 0;
    return result;
}
