#include <globaldefs.h>
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void *memcpy(void *, const void *, unsigned);
extern "C" void func_ov011_02184a24(void *, unsigned, unsigned);
struct Block { unsigned w[19]; };
extern "C" Block data_ov004_0216ffac;
// Original: arm9/ov004 @ 0x021677B4; symbol: func_ov004_021677b4; size: 0x6C.
extern "C" void OV004_AllocateCopyAndDispatch(void *allocator, void *state) {
    Block local = data_ov004_0216ffac;
    char *copy = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0x4c);
    memcpy(copy, &local, 0x4c);
    func_ov011_02184a24(state, (unsigned)copy, 0x13);
}
