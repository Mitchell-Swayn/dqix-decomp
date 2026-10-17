#include <globaldefs.h>
ARM
extern "C" int Object_TestElement5Mask10(unsigned int *);
extern "C" int TestDescriptorFlag20(void *);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
// Original: arm9/ov024 @ 0x021F6D2C; symbol: func_ov024_021f6d2c; size: 0x54.
extern "C" int func_ov024_021f6d2c(void *p) {
    void *descriptor = *(void **)((char *)p + 4);
    if (Object_TestElement5Mask10((unsigned int *)*((unsigned int **)((char *)descriptor + 0x138))) || TestDescriptorFlag20(descriptor)) {
        *(unsigned int *)((char *)p + 0x1c) = _fmul(0x40000000, *(unsigned int *)((char *)p + 0x14));
        *(unsigned int *)((char *)p + 0x20) = _fmul(0x40000000, *(unsigned int *)((char *)p + 0x18));
    }
    return 1;
}
