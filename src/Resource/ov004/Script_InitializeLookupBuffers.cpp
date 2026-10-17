#include <globaldefs.h>
ARM
extern "C" void* FindTreeNodeForwarder(void*, unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void func_ov004_02167b78(void*, int);
extern "C" unsigned data_ov004_02171024[];
// Original: arm9/ov004 @ 0x02167D04; symbol: func_ov004_02167d04; size: 0x6C.
extern "C" int Script_InitializeLookupBuffers(void* owner) {
    void* allocator = FindTreeNodeForwarder(owner, 0);
    if (allocator) {
        data_ov004_02171024[1] = (unsigned)_ZN13SafeAllocator8AllocateEj((unsigned)allocator + 4, 0xc);
        data_ov004_02171024[0] = (unsigned)_ZN13SafeAllocator8AllocateEj((unsigned)allocator + 4, 0x80);
        data_ov004_02171024[2] = (unsigned)_ZN13SafeAllocator8AllocateEj((unsigned)allocator + 4, 0x80);
        func_ov004_02167b78(owner, 0);
    }
    return 0;
}
