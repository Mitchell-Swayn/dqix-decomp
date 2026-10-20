#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" int StoreReadySharedValue(int);
extern "C" void YssdCommand_ClearReplyHandler(void);
// Original: arm9/ov031 @ 0x0220F728; symbol: func_ov031_0220f728; size: 0x48.
extern "C" void Network_ResolveYssdRequestHandle(void) {
    if (StoreReadySharedValue(0)) {
        void* state = *(void**)&StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
        char* object = *(char**)((char*)state + 0x24);
        *(void**)(object + 0x24) = **(void***)((char*)object + 0xc);
        state = *(void**)&StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
        object = *(char**)((char*)state + 0x24);
        *(unsigned*)(object + 0x20) = 1;
    }
    YssdCommand_ClearReplyHandler();
}
