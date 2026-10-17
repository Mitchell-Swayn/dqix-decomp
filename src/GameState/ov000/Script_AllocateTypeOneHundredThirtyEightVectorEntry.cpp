#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void __clear(void*, unsigned);
extern "C" void _ZN6Script9Parameter9ToVec3fixEP8Vector3i(const void*, void*);
extern "C" void _ZN8Vector3iaSERKS_(void*, const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216D038; symbol: func_ov000_0216d038; size: 0x70.
extern "C" int Script_AllocateTypeOneHundredThirtyEightVectorEntry(const void* parameter) {
    char* entry = _ZN13SafeAllocator8AllocateEj((unsigned)*(void**)(data_ov000_02184264 + 8), 0x14);
    *(unsigned*)entry = 0;
    *(unsigned*)(entry + 4) = 0;
    *(unsigned*)entry = 0x8A;
    int vector[3];
    __clear(vector, 0xC);
    _ZN6Script9Parameter9ToVec3fixEP8Vector3i(parameter, vector);
    _ZN8Vector3iaSERKS_(entry + 8, vector);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
