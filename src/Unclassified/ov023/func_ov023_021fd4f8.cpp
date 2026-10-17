#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FD4F8; symbol: func_ov023_021fd4f8; size: 0x14.
extern "C" void func_ov023_021fd4f8(void *object) {
    void **vtable = *(void ***)object;
    ((void (*)(void *))vtable[0xb8 / 4])(object);
}
