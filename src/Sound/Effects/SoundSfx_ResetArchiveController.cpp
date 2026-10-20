#include <globaldefs.h>

extern "C" void ResourceHandle_ReleaseArchiveAndResetState(void*);
extern "C" void ResourceHandle_InitializeThreeValueIndexSlots(void*);

// Original: arm9/main @ 0x0205E8D4; symbol: func_0205e8d4; size: 0x18.
extern "C" ARM void SoundSfx_ResetArchiveController(void* object) {
    ResourceHandle_ReleaseArchiveAndResetState(object);
    ResourceHandle_InitializeThreeValueIndexSlots(object);
}
