#include <globaldefs.h>
ARM

extern "C" void *FindTreeNodeForwarder(void *tree, unsigned id);
extern "C" char *_ZN13SafeAllocator8AllocateEj(void *allocator, unsigned size);
extern "C" void ClearTwoBytesAndWord4(unsigned char *p);
extern "C" unsigned char data_ov004_02171034[];

// Original: arm9/ov004 @ 0x0216E210; symbol: func_ov004_0216e210; size: 0x48.
extern "C" int InitializeGlobalTreeEntry(void *tree) {
    void *node = FindTreeNodeForwarder(tree, 6);
    if (node != 0) {
        char *allocation = _ZN13SafeAllocator8AllocateEj((char *)node + 4, 8);
        *(char **)(data_ov004_02171034 + 0x10) = allocation;
    }
    ClearTwoBytesAndWord4(*(unsigned char **)(data_ov004_02171034 + 0x10));
    data_ov004_02171034[5] = 0;
    return 0;
}
