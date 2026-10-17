#include <globaldefs.h>
ARM
extern "C" int SelectNonzeroByteEntry(void *object, int index);
extern "C" int func_ov024_021fdf04(void *object, int index);
// Original: arm9/ov024 @ 0x021FC018; symbol: func_ov024_021fc018; size: 0x28.
extern "C" int ProcessObjectAtIndex6WhenEntryFlagPresent(void *object) {
    if (SelectNonzeroByteEntry(object, 1))
        return func_ov024_021fdf04(object, 6);
}
