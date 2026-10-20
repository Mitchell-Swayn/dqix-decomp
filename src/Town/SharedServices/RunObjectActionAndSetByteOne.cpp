#include <globaldefs.h>
ARM
extern "C" void System_ClearConditionalOverlayFieldAndDestroyAllocator(void *object);
// Original: arm9/ov003 @ 0x0217EF0C; symbol: func_ov003_0217ef0c; size: 0x18.
extern "C" void RunObjectActionAndSetByteOne(unsigned char *object) {
    System_ClearConditionalOverlayFieldAndDestroyAllocator(object);
    object[1] = 1;
}
