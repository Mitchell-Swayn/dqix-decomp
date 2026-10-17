#include <globaldefs.h>
extern "C" unsigned data_ov000_02184220[];
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*, unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
// Original: arm9/ov000 @ 0x02160E94; symbol: func_ov000_02160e94; size: 0x64.
extern "C" void Filesystem_RemoveFailedTaskAndResetLoadState(unsigned char* self) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    if ((int)_ZN16BackgroundLoader13GetTaskStatusEi(loader, *(short*)(self + 0x7730)) >= 0) return;
    _ZN16BackgroundLoader10RemoveTaskEi(loader, *(short*)(self + 0x7730));
    *(short*)(self + 0x7730) = -1;
    *(unsigned*)(self + 0xea8) = 8;
    *(unsigned*)(self + 0xeac) = 0;
    data_ov000_02184220[0] = 1;
}
