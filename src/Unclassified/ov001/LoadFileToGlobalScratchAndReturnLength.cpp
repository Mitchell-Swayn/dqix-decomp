#include <globaldefs.h>
ARM
extern "C" {
    extern unsigned char data_0211e33c[];
    void _ZN16BackgroundLoader13AddLockGlobalEv();
    void _ZN16BackgroundLoader16RemoveLockGlobalEv();
    void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
}
// Original: arm9/ov001 @ 0x0215A750; symbol: func_ov001_0215a750; size: 0x4C.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" unsigned LoadFileToGlobalScratchAndReturnLength(const char* path,void** out) {
    unsigned size;
    _ZN16BackgroundLoader13AddLockGlobalEv();
    size=0;
    if(!_Z18LoadFileIntoMemoryPKcPvPj(path,data_0211e33c,&size))return 0;
    _ZN16BackgroundLoader16RemoveLockGlobalEv();
    *out=data_0211e33c;
    return size;
}
