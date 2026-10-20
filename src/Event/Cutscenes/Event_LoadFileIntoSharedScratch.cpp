#include <globaldefs.h>
ARM
extern "C" {
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
    void _ZN16BackgroundLoader13AddLockGlobalEv();
    void _ZN16BackgroundLoader16RemoveLockGlobalEv();
    void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
}
// Original: arm9/ov001 @ 0x0215A750; symbol: func_ov001_0215a750; size: 0x4C.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" unsigned Event_LoadFileIntoSharedScratch(const char* path,void** out) {
    unsigned size;
    _ZN16BackgroundLoader13AddLockGlobalEv();
    size=0;
    if(!_Z18LoadFileIntoMemoryPKcPvPj(path,Main_UnknownRoleZeroInitializedStorage_Variant6,&size))return 0;
    _ZN16BackgroundLoader16RemoveLockGlobalEv();
    *out=Main_UnknownRoleZeroInitializedStorage_Variant6;
    return size;
}
