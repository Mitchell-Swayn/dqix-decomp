#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x02169BB4; symbol: func_ov000_02169bb4; size: 0x3C.
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void* owner) {
    char* node = _ZN13SafeAllocator8AllocateEj(*(unsigned*)(data_ov000_02184264 + 8), 8);
    if (!node) return;
    *(unsigned*)node = 0;
    *(unsigned*)(node + 4) = 0;
    *(void**)node = owner;
    Overlay_EnqueueLinkedNode(node);
}
