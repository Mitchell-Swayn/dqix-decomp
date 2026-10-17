#include <globaldefs.h>
ARM

extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void **p);
extern "C" unsigned char data_ov031_02290d24[];
extern "C" void func_ov031_0223bf48(void *, void *);

// Original: arm9/ov031 @ 0x0223B710; symbol: func_ov031_0223b710; size: 0x34.
extern "C" void Unclassified_FreeArgumentAndUpdateGlobalOwner(void *allocation, void *unused1, void *unused2, void *unused3) {
    FreeSharedAllocationAndClearFlagWithInterruptMask(&allocation);
    void *owner = *(void **)data_ov031_02290d24;
    func_ov031_0223bf48(*(void **)((char *)owner + 0x84), allocation);
}
