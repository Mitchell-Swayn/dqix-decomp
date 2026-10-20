#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void ResourceHandle_RestoreArchiveHeapState(void *,void *);
// Original: arm9/main @ 0x0205EBEC; symbol: func_0205ebec; size: 0x10.
    void SoundSfx_RestoreHeapAfterGroupPlayback(unsigned char *p){
        ResourceHandle_RestoreArchiveHeapState(p,*(void **)(p+192));
    }
}
