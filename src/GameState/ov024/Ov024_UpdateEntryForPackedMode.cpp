#include <globaldefs.h>
extern "C" void* SelectNonzeroByteEntry(void*, unsigned);
extern "C" void func_ov024_021fdf04(void*, unsigned);
extern "C" void func_ov024_021fd954(void*, unsigned);
// Original: arm9/ov024 @ 0x021FC2B4; symbol: func_ov024_021fc2b4; size: 0x6C.
extern "C" ARM void Ov024_UpdateEntryForPackedMode(void* object) {
    unsigned mode = (*(unsigned*)((char*)*(void**)((char*)object + 0x64c) + 8) << 22) >> 30;
    if (mode == 1) {
        if (SelectNonzeroByteEntry(object, 0x10))
            func_ov024_021fdf04(object, 0x16);
        return;
    }
    if (!*((unsigned char*)object + 0x6b)) return;
    if (SelectNonzeroByteEntry(object, 0xa))
        func_ov024_021fd954(object, 0x16);
}
