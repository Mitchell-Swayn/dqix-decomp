#include <globaldefs.h>
ARM
struct SafeAllocator;
extern "C" void Memory_AllocateTenSizedBlocksAndFourExtraBuffers(unsigned char*, SafeAllocator*, int);
// Original: arm9/ov017 @ 0x021A1178; symbol: func_ov017_021a1178; size: 0x3C.
extern "C" void Memory_AllocateIndexedAllocatorBlocks(unsigned char* self, int index) {
    int next = index + 1;
    SafeAllocator* alloc = (SafeAllocator*)(self + 0x38 + next * 0x14);
    int value = (int)(self + 0x2cc + next * 0x70);
    unsigned char* block = self + 0x12c8 + index * 0x5ec;
    Memory_AllocateTenSizedBlocksAndFourExtraBuffers(block, alloc, value);
}
