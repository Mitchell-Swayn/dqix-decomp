#include <globaldefs.h>
extern "C" void* SelectNonzeroByteEntry(void*, unsigned);
extern "C" void func_ov024_021fd954(void*, unsigned);
// Original: arm9/ov024 @ 0x021FC698; symbol: func_ov024_021fc698; size: 0x34.
extern "C" ARM void Ov024_UpdateSelectedEntry(void* object) {
    if (!*((unsigned char*)object + 0x71)) return;
    if (!SelectNonzeroByteEntry(object, 12)) return;
    func_ov024_021fd954(object, 11);
}
