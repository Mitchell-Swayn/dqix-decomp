#include <globaldefs.h>

extern "C" void SoundStream_StopPlayerWithFade(void*, int);
// Preserve the original two independent reads of the shared handle.

// Original: arm9/main @ 0x020BEC58; symbol: func_020bec58; size: 0x1C.
extern "C" ARM void ResourceHandle_SetOptionalEnabledState(void* volatile* owner, int enabled) {
    if (*owner) SoundStream_StopPlayerWithFade(*owner, enabled);
}
