#include <globaldefs.h>
ARM

extern "C" void *_ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void *, int);

// Original: arm9/ov017 @ 0x021B33D8; symbol: func_ov017_021b33d8; size: 0x6C.
extern "C" void BackgroundLoader_ClearStateAndRemoveTasks(int *state) {
    void *loader = _ZN16BackgroundLoader11GetInstanceEv();
    for (int i = 0; i < 14; i++) {
        int task = *(int *)((char *)state + i * 4 + 0x10);
        if (task >= 0) {
            _ZN16BackgroundLoader10RemoveTaskEi(loader, task);
        }
    }
    *(short *)((char *)state + 8) = -1;
    *((char *)state + 0xA) = 0;
    *((char *)state + 0xB) = 0;
    for (int i = 0; i < 14; i++) {
        *(int *)((char *)state + i * 4 + 0x10) = -1;
    }
}
