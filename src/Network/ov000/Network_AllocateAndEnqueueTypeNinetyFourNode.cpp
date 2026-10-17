#include <globaldefs.h>
ARM
extern "C" char data_ov000_02184264[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216C28C; symbol: func_ov000_0216c28c; size: 0x38.
extern "C" int Network_AllocateAndEnqueueTypeNinetyFourNode(void) {
    char *node = _ZN13SafeAllocator8AllocateEj((unsigned)*(void **)(data_ov000_02184264 + 8), 0xc);
    *(unsigned *)node = 0;
    *(unsigned *)(node + 4) = 0;
    *(unsigned *)node = 0x5e;
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
