#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
extern "C" bool BackgroundLoader_RemoveTaskAndResetLoadState(void *state);
// Original: arm9/ov023 @ 0x021F52A0; symbol: func_ov023_021f52a0; size: 0x28.
extern "C" bool Filesystem_ResetBackgroundLoaderState(void *state) {
    memset(state, 0, 0xc);
    *(int *)((char *)state + 0x10) = -1;
    return BackgroundLoader_RemoveTaskAndResetLoadState(state);
}
