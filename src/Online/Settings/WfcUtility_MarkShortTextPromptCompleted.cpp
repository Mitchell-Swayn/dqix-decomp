#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c78; symbol: data_ov031_02290c78.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222AA88; symbol: func_ov031_0222aa88; size: 0x14.
extern "C" void WfcUtility_MarkShortTextPromptCompleted(void) {
    ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[0] = 1;
}
