#include <globaldefs.h>
ARM
extern "C" void func_ov003_02160134(void *resource);
// Original: arm9/ov017 @ 0x021B6B5C; symbol: func_ov017_021b6b5c; size: 0x18.
extern "C" void Graphics_ResetNestedResourceAtOffset24(void *object) {
    void *resource = *(void **)((unsigned char *)object + 0x24);
    if (resource) func_ov003_02160134(resource);
}
