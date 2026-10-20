#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x224e590; symbol: data_ov031_0224e590.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage[];
extern "C" int Network_TryStopSharedContext();
extern "C" int YssdClient_TryStopWorker();
extern "C" int YssdSession_GetWorkspaceSize();
extern "C" void OnlineMemory_FreeTagged(unsigned, void *, unsigned);
// Original: arm9/ov031 @ 0x0221126C; symbol: func_ov031_0221126c; size: 0x78.
extern "C" int YssdSession_TryDestroy(void) {
    int ok = 1;
    void *request = *(void **)YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
    if (!request) return ok;
    *(unsigned *)request = 3;
    if (Network_TryStopSharedContext() == 0) ok = 0;
    if (YssdClient_TryStopWorker() == 0) ok = 0;
    if (ok) {
        unsigned length = YssdSession_GetWorkspaceSize();
        OnlineMemory_FreeTagged(0x53574300, *(void **)YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage, length);
        *(void **)YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage = 0;
    }
    return ok;
}
