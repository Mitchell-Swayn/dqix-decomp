#include <globaldefs.h>
ARM
extern "C" void func_ov024_021fd954(void *object, int index);
// Original: arm9/ov024 @ 0x021FBEFC; symbol: func_ov024_021fbefc; size: 0x1C.
extern "C" void InvokeObjectProcessorIndex4WhenCountAtLeast3(void *object) {
    if (*(int *)((unsigned char *)object + 0xc) >= 3)
        func_ov024_021fd954(object, 4);
}
