#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02210EF8; symbol: GlobalState_IsCurrentObjectFieldSeven; size: 0x2C.
// Returns true when the pointer stored in the global is nonnull and its first word equals 7.
extern "C" int GlobalState_IsCurrentObjectFieldSeven(void) {
    if (YssdClientRunWorker_UnknownRoleZeroInitializedStorage == 0)
        return 0;
    return *(int *)YssdClientRunWorker_UnknownRoleZeroInitializedStorage == 7;
}
