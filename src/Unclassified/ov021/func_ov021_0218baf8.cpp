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
#include <Filesystem/BackgroundLoader.h>
extern "C" int func_ov009_02184a18(void *);
struct Transition { int active; unsigned char unknown[0xa8]; short first, second; };
extern "C" Transition data_02108760;
extern "C" void ConsumeActivePairAndInvalidateIndices(Transition *);
extern "C" void Object_Invokewhile();
// Original: arm9/ov021 @ 0x0218BAF8; symbol: func_ov021_0218baf8; size: 0x38.
extern "C" void func_ov021_0218baf8(Stage *self) {
    BackgroundLoader::GetInstance()->RemoveAllLocks();
    if (func_ov009_02184a18(self->screen)) self->exitRequested = 1;
    ConsumeActivePairAndInvalidateIndices(&data_02108760);
    Object_Invokewhile();
}
