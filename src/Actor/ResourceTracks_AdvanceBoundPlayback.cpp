#include <globaldefs.h>

extern "C" void EffectEmitter_AdvanceTracksAndSpawnChildren(void*);
struct HandleOwner { char unknown[0x4]; void* handle; };

// Original: arm9/main @ 0x02055774; symbol: func_02055774; size: 0x18.
extern "C" ARM void ResourceTracks_AdvanceBoundPlayback(HandleOwner* owner) {
    if (owner->handle)
        EffectEmitter_AdvanceTracksAndSpawnChildren(owner->handle);
}
