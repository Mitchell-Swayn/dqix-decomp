#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char StartMode6ContextCallback_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02230EF0; symbol: func_ov031_02230ef0; size: 0x10.
extern "C" void WfcSettingsList_SetEntryOriginMode(unsigned char value) {
    *((unsigned char *)&StartMode6ContextCallback_UnknownRoleZeroInitializedStorage + 1) = value;
}
