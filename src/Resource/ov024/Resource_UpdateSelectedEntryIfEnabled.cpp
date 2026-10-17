#include <globaldefs.h>
ARM
extern "C" void* SelectNonzeroByteEntry(void*, int);
extern "C" void func_ov024_021fd954(void*, int);
// Original: arm9/ov024 @ 0x021FCAF0; symbol: func_ov024_021fcaf0; size: 0x34.
extern "C" void Resource_UpdateSelectedEntryIfEnabled(void* object) {
    if (*(unsigned char*)((char*)object + 0x6f) == 0) return;
    if (SelectNonzeroByteEntry(object, 0xb) == 0) return;
    func_ov024_021fd954(object, 0xe);
}
