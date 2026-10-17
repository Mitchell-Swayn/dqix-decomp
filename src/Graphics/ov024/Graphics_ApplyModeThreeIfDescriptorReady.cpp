#include <globaldefs.h>
ARM

struct LinkedDescriptorView;
extern "C" int TestLinkedDescriptorFlag8(LinkedDescriptorView *);
extern "C" void func_ov024_021fd160(void *, int);

// Original: arm9/ov024 @ 0x021FD428; symbol: func_ov024_021fd428; size: 0x34.
extern "C" void Graphics_ApplyModeThreeIfDescriptorReady(void *object) {
    if (!TestLinkedDescriptorFlag8((LinkedDescriptorView *)(*(unsigned int *)((char *)object + 0x668)))) {
        return;
    }
    if (*((unsigned char *)object + 0x661) != 0) {
        return;
    }
    func_ov024_021fd160(object, 3);
}
