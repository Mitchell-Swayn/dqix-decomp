#include <globaldefs.h>
ARM
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" void *GameResources_GetInstance();
extern "C" void GameResources_ClearSecondaryFlags(int, unsigned int);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021A9714; symbol: func_ov017_021a9714; size: 0x54.
extern "C" void Resource_ReleaseAllocatorAndResetState(void *p) {
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv((char *)p + 0xc);
    if (allocation != 0) {
        _ZN13SafeAllocator7DestroyEv((char *)p + 0xc);
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    }
    _ZN13SafeAllocator21ResetAllocatorPointerEv((char *)p + 0xc);
    *((unsigned char *)p + 8) = 0;
    *(unsigned int *)((char *)p + 0x20) = 0;
    GameResources_ClearSecondaryFlags((int)GameResources_GetInstance(), 0xc0);
}
