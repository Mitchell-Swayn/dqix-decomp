#include <globaldefs.h>
extern "C" {
void ResourceHandle_StartOrDeferSequenceArchiveEntry(void *, int, int, int);
// Original: arm9/main @ 0x0205EB24; symbol: func_0205eb24; size: 0x24.
ARM void SoundSfx_StartSecondarySequenceArchiveEntry(void *param_1, int param_2, int param_3, int param_4) {
    short index = *(short *)((char *)param_1 + 0xbc);
    if (index < 0) return;
    ResourceHandle_StartOrDeferSequenceArchiveEntry(param_1, index, param_2, param_3);
}
}
