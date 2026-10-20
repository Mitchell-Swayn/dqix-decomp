#include <globaldefs.h>
ARM
extern "C" void *GameResources_GetInstance();
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" void GameResources_ClearSecondaryFlags(int, unsigned int);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];

// Original: arm9/ov017 @ 0x021BEF84; symbol: func_ov017_021bef84; size: 0x48.
extern "C" void Resource_DestroyObjectAllocatorAndClearFlags(void *object) {
    void *resources = GameResources_GetInstance();
    void *allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((unsigned char *)object + 0x44);
    if (allocator != 0) {
        _ZN13SafeAllocator7DestroyEv((unsigned char *)object + 0x44);
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocator);
    }
    GameResources_ClearSecondaryFlags((int)resources, 0xc0);
}
