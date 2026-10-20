#include <globaldefs.h>

extern "C" void SoundSfx_RestoreSecondaryHeapStateAndVolume(void*);
extern "C" void ResourceHandle_ReleaseArchiveAndResetState(void*);

// Original: arm9/main @ 0x0205E92C; symbol: func_0205e92c; size: 0x18.
extern "C" ARM void ResourceHandle_ResetSlotsAndReleaseState(void* object) {
    SoundSfx_RestoreSecondaryHeapStateAndVolume(object);
    ResourceHandle_ReleaseArchiveAndResetState(object);
}
