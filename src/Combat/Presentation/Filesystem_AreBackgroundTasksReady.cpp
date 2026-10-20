#include <globaldefs.h>
ARM

extern "C" void *_ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void *loader, unsigned id);

// Original: arm9/ov025 @ 0x021EB0F4; symbol: func_ov025_021eb0f4; size: 0x54.
extern "C" int Filesystem_AreBackgroundTasksReady(unsigned char *state) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    unsigned short *task = (unsigned short *)(state + 0x584);
    int i = 0;
    while (i < state[0x582]) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, *task) == 0) return 0;
        task++;
        i++;
    }
    return 1;
}
