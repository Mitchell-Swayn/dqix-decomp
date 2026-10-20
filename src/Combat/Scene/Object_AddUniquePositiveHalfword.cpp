#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0216FDF8; symbol: func_ov000_0216fdf8; size: 0x50.
extern "C" void Object_AddUniquePositiveHalfword(void* object, int value) {
    int i;
    int count = *(int*)((char*)object + 0x84);
    if (count > 0x3f) return;
    if (value <= 0) return;
    i = 0;
    for (; i < count; ++i) {
        if (*(short*)((char*)object + 4 + i * 2) == value) return;
    }
    *(unsigned short*)((char*)object + 4 + count * 2) = (unsigned short)value;
    *(int*)((char*)object + 0x84) = *(volatile int*)((char*)object + 0x84) + 1;
}
