#include <globaldefs.h>
ARM
extern "C" void *SelectNonzeroByteEntry(void *object, int selector);
extern "C" void func_ov024_021fdf04(void *object, int mode);
// Original: arm9/ov024 @ 0x021FBED4; symbol: func_ov024_021fbed4; size: 0x28.
extern "C" void Ov024_ProcessObjectWhenEntryOneSelected(void *object) {
    if (SelectNonzeroByteEntry(object, 1) != 0)
        func_ov024_021fdf04(object, 4);
}
