#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2291e04; symbol: data_ov031_02291e04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02243418; symbol: func_ov031_02243418; size: 0x14.
extern "C" void OnlineTransfer_MarkSaveSubmissionComplete(void) {
    ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[12] = 1;
}
