#include <globaldefs.h>
ARM
extern "C" void func_ov003_02168324(void *);
extern "C" void Overlay_DestroyObjectAndFree(void *);
// Original: arm9/ov003 @ 0x0217E5B0; symbol: func_ov003_0217e5b0; size: 0x2C.
extern "C" void Overlay_DestroyOptionalField20AndMark(void *object) {
    if (*(void **)((unsigned char *)object + 0x20) != 0)
        func_ov003_02168324(*(void **)((unsigned char *)object + 0x20));
    Overlay_DestroyObjectAndFree(object);
    ((unsigned char *)object)[1] = 1;
}
