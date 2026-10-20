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
extern "C" int UpdatePairedObjectsAndDispatchState(void *);
struct Transition { int active; unsigned char unknown[0xa8]; short first, second; };
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Transition Main_UnknownRoleZeroInitializedStorage;
extern "C" void ResourceHandle_PlayDeferredSequenceArchiveEntry(Transition *);
extern "C" void Sound_UpdatePlaybackAndFlushCommands();
// Original: arm9/ov021 @ 0x0218BAF8; symbol: func_ov021_0218baf8; size: 0x38.
extern "C" void CharacterCreation_UpdateStandaloneScene(Stage *self) {
    BackgroundLoader::GetInstance()->RemoveAllLocks();
    if (UpdatePairedObjectsAndDispatchState(self->screen)) self->exitRequested = 1;
    ResourceHandle_PlayDeferredSequenceArchiveEntry(&Main_UnknownRoleZeroInitializedStorage);
    Sound_UpdatePlaybackAndFlushCommands();
}
