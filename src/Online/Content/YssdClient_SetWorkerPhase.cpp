#include <globaldefs.h>
extern "C" {
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern int* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
}
// Original: arm9/ov031 @ 0x022103DC; symbol: func_ov031_022103dc; size: 0x1C.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void YssdClient_SetWorkerPhase(int value)
{
    if(YssdClientRunWorker_UnknownRoleZeroInitializedStorage)
    {
        (void)*(volatile int*)YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
        *YssdClientRunWorker_UnknownRoleZeroInitializedStorage=value;
    }
}
