#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void *, int);
// Original: arm9/ov023 @ 0x021F5410; symbol: func_ov023_021f5410; size: 0x38.
extern "C" bool BackgroundLoader_RemoveTaskAndResetLoadState(void *state) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    int task = *(int *)((unsigned char *)state + 0x10);
    if (task >= 0) {
        _ZN16BackgroundLoader10RemoveTaskEi(loader, task);
        *(int *)((unsigned char *)state + 0x10) = -1;
    }
    *(unsigned short *)((unsigned char *)state + 0x0C) = 0;
    *(int *)((unsigned char *)state + 0x14) = 0;
    return true;
}
