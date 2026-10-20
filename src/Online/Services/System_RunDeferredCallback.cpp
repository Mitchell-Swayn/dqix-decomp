#include <globaldefs.h>
ARM
extern "C" void System_ActivatePendingGlobalRequestAndDrainQueues(void*);
extern "C" void System_RunCallbackAndAwaitContextCompletion(void);
extern "C" void Http_FinalizeWorkerSynchronization(void);
// Original data: arm9/ov031 @ 0x2290fbc; symbol: data_ov031_02290fbc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char HttpStartRequestWorker_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0223FDE4; symbol: func_ov031_0223fde4; size: 0x3C.
extern "C" void System_RunDeferredCallback(void (*callback)(void)) {
    System_ActivatePendingGlobalRequestAndDrainQueues((void*)callback);
    System_RunCallbackAndAwaitContextCompletion();
    unsigned char* state = HttpStartRequestWorker_UnknownRoleZeroInitializedStorage;
    ((void (*)(unsigned))*(void**)(state + 0x0c))(*(unsigned*)(state + 0x18));
    Http_FinalizeWorkerSynchronization();
    *(unsigned*)HttpStartRequestWorker_UnknownRoleZeroInitializedStorage = 0;
    callback();
}
