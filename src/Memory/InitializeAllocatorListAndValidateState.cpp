#include <Memory/SignedAllocator.h>
extern "C" int AllocateTwentyByteNodeAndAppendToAllocatorList(void *);

// Original: arm9/main @ 0x020BDBF0; symbol: func_020bdbf0; size: 0x34.
extern "C" int InitializeAllocatorListAndValidateState(unsigned int *object, unsigned int value) {
    ((SignedAllocatorList *)(object + 1))->Initialize(0xc);
    *object = value;
    return AllocateTwentyByteNodeAndAppendToAllocatorList(object) != 0;
}
