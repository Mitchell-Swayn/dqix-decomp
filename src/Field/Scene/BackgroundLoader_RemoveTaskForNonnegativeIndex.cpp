#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void *, int);
// Original: arm9/ov017 @ 0x021C235C; symbol: BackgroundLoader_RemoveTaskForNonnegativeIndex; size: 0x24.
// Removes the background task named by signed halfword +8 only when that index is nonnegative.
extern "C" void BackgroundLoader_RemoveTaskForNonnegativeIndex(void *p) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    int task = *(signed short *)((unsigned char *)p + 8);
    if (task > -1) _ZN16BackgroundLoader10RemoveTaskEi(loader, task);
}
