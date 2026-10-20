#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*, int, void**, unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void* memcpy(void*, const void*, unsigned);
// Original: arm9/ov012 @ 0x02185EA8; symbol: func_ov012_02185ea8; size: 0x5C.
extern "C" void Filesystem_ConsumeLoadedFileTask(unsigned char* object) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    void* data;
    _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, *(unsigned*)(object + 0x1384), &data, (unsigned*)(object + 0x13b8));
    memcpy(*(void**)(object + 0x13b4), data, *(unsigned*)(object + 0x13b8));
    _ZN16BackgroundLoader10RemoveTaskEi(loader, *(unsigned*)(object + 0x1384));
    *(unsigned*)(object + 0x1384) = 0xffffffff;
}
