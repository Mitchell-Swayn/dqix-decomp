#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned int EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x02162320; symbol: func_ov001_02162320; size: 0x18.
extern "C" void Protection_AddThreeToScriptCheckCounter(void) {
    EventGetObjectSession_UnknownRoleZeroInitializedStorage[10] += 3;
}
