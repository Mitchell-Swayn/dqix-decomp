#include <globaldefs.h>
ARM
extern "C" char data_ov000_02184264[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216C1EC; symbol: func_ov000_0216c1ec; size: 0x50.
extern "C" int Network_AllocateAndEnqueueTypeNinetyTwoNode(const void *parameter) {
    char *node = _ZN13SafeAllocator8AllocateEj((unsigned)*(void **)(data_ov000_02184264 + 8), 0xc);
    *(unsigned *)node = 0;
    *(unsigned *)(node + 4) = 0;
    *(unsigned *)node = 0x5c;
    node[8] = (unsigned char)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
