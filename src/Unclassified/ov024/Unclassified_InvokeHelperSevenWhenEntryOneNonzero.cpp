#include <globaldefs.h>
ARM
extern "C" int SelectNonzeroByteEntry(void *object, int index);
extern "C" void func_ov024_021fdf04(void *object, int value);
// Original: arm9/ov024 @ 0x021FC28C; symbol: func_ov024_021fc28c; size: 0x28.
extern "C" void Unclassified_InvokeHelperSevenWhenEntryOneNonzero(void *object) {
    if (SelectNonzeroByteEntry(object, 1) != 0)
        func_ov024_021fdf04(object, 7);
}
