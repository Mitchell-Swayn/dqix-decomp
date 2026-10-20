#include <globaldefs.h>

extern "C" void Bgm_StopPlaybackAndResetController(void*);
extern "C" void ResourceHandle_ReleaseArchiveAndResetState(void*);

// Original: arm9/main @ 0x0209C278; symbol: func_0209c278; size: 0x18.
extern "C" ARM void Bgm_ReleaseArchiveController(void* object) {
    Bgm_StopPlaybackAndResetController(object);
    ResourceHandle_ReleaseArchiveAndResetState(object);
}
