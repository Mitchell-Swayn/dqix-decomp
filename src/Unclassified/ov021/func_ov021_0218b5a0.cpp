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
#include <Resource/Brightness.h>
// Original: arm9/ov021 @ 0x0218B5A0; symbol: func_ov021_0218b5a0; size: 0x24.
extern "C" void func_ov021_0218b5a0(Stage *self) {
    InitializeBrightnessState((GameResources *)self);
    self->allocator.ResetAllocatorPointer();
    self->screen = 0;
    self->exitRequested = 0;
}
