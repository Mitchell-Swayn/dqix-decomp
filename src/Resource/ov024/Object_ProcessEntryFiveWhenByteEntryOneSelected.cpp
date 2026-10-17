#include <globaldefs.h>
ARM
extern "C" int SelectNonzeroByteEntry(void *, int);
extern "C" void func_ov024_021fdf04(void *, int);
// Original: arm9/ov024 @ 0x021FC254; symbol: func_ov024_021fc254; size: 0x28.
extern "C" void Object_ProcessEntryFiveWhenByteEntryOneSelected(void *object) {
    if (SelectNonzeroByteEntry(object, 1))
        func_ov024_021fdf04(object, 5);
}
