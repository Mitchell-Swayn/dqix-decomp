#include <globaldefs.h>
ARM

extern "C" void func_ov017_021b6790(void *);
extern "C" void AppendLinkedNodeAndMarkActive(unsigned int *, unsigned int);

// Original: arm9/ov017 @ 0x021B66F0; symbol: func_ov017_021b66f0; size: 0x38.
extern "C" void Resource_ActivateLinkedEntry(void *object) {
    func_ov017_021b6790(*(void **)((char *)object + 0x3B00));
    AppendLinkedNodeAndMarkActive(*(unsigned int **)((char *)object + 0x36FC), *(unsigned int *)((char *)object + 0x3B00));
    *((unsigned char *)(*(unsigned int **)((char *)object + 0x3B00)) + 0x1F) = 2;
}
