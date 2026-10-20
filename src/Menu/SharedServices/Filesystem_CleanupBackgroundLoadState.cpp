#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage[];
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" void* Quest_GetGlobalOrderState();
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void* memcpy(void*, const void*, unsigned int);
// Original: arm9/ov004 @ 0x02166AC4; symbol: func_ov004_02166ac4; size: 0x7C.
extern "C" int Filesystem_CleanupBackgroundLoadState(void) {
    char* state = *(char**)FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)(state + 0x44));
    *(int*)(state + 0x44) = -1;
    _ZN13SafeAllocator7DestroyEv(state + 0x30);
    _ZN13SafeAllocator7DestroyEv(state + 0x1c);
    char* sourceState = *(char**)FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
    memcpy((char*)GameState_GetSerializedProgressState() + 0x2cc, sourceState + 0x51, 0x66);
    void* queue = Quest_GetGlobalOrderState();
    char* queueState = *(char**)FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage;
    *(void**)((char*)queue + 0xa0) = *(void**)(queueState + 0xb8);
    char* field = (char*)TextContext_GetSharedInstance();
    int zero = 0;
    field += 0x1000;
    *(volatile unsigned char*)(field + 0x962) = zero;
    return zero;
}
