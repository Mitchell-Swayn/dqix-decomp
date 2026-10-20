#include <Memory/SafeAllocator.h>
// Brightness state occupies the shared first 0x2c bytes; the following
// fields are proved by the five ov021 entry points and their main callees.
struct Stage {
    unsigned char brightness[0x2c];
    SafeAllocator allocator;
    void *screen;
    unsigned char renderer[0x70];
    void *resource;
    int exitRequested;
};

#pragma force_active on
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" void Memory_FreeThroughAllocatorUnion(AllocatorUnion *, void *);
// Original: arm9/ov021 @ 0x0218B5C4; symbol: func_ov021_0218b5c4; size: 0x38.
extern "C" void CharacterCreation_ReleaseStandaloneScene(Stage *self) {
    SignedAllocatorHeader *allocation = self->allocator.GetSignedAllocator();
    self->allocator.Destroy();
    Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    self->screen = 0;
}
