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
extern "C" AllocatorUnion data_02114e20;
extern "C" void Memory_FreeThroughAllocatorUnion(AllocatorUnion *, void *);
// Original: arm9/ov021 @ 0x0218B5C4; symbol: func_ov021_0218b5c4; size: 0x38.
extern "C" void func_ov021_0218b5c4(Stage *self) {
    SignedAllocatorHeader *allocation = self->allocator.GetSignedAllocator();
    self->allocator.Destroy();
    Memory_FreeThroughAllocatorUnion(&data_02114e20, allocation);
    self->screen = 0;
}
