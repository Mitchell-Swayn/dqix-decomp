#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e60c; symbol: data_ov031_0224e60c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02219220; symbol: func_ov031_02219220; size: 0x18.
extern "C" unsigned int WfcNetCheck_GetResultCode(void) {
    return *(unsigned int *)((char *)WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage + 0x1004);
}
