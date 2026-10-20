#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022101AC; symbol: func_ov031_022101ac; size: 0x18.
extern "C" void YssdClient_SetSessionValueCallback(unsigned int value) {
    void *object = YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
    if (object)
        *(unsigned int *)((char *)object + 0x30) = value;
}
