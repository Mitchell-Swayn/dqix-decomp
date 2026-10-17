#include <globaldefs.h>
ARM
extern "C" void func_ov003_0215ca1c(void *object);
// Original: arm9/ov017 @ 0x021BAE80; symbol: func_ov017_021bae80; size: 0x18.
extern "C" void Ov017_ProcessPointerAtField20(unsigned char *self) {
    void *object = *(void **)(self + 0x20);
    if (object != 0) func_ov003_0215ca1c(object);
}
