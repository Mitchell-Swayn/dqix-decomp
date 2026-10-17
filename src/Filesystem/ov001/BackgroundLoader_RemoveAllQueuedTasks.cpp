#include <globaldefs.h>
ARM
extern "C" void *_ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void *, int);
extern "C" int data_ov001_021658e0[];
extern "C" unsigned char data_ov001_021658b8[];

// Original: arm9/ov001 @ 0x0215AAC8; symbol: func_ov001_0215aac8; size: 0x58.
extern "C" void BackgroundLoader_RemoveAllQueuedTasks(void) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    for (int i = 0; i < *(int *)(data_ov001_021658b8 + 0x88); ++i) {
        int task = data_ov001_021658e0[i];
        _ZN16BackgroundLoader10RemoveTaskEi(loader, task);
        data_ov001_021658e0[i] = -1;
    }
    *(int *)(data_ov001_021658b8 + 0x88) = 0;
}
