#include <globaldefs.h>
ARM
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
// Original: arm9/ov023 @ 0x021FBE4C; symbol: func_ov023_021fbe4c; size: 0x24.
extern "C" void DestroyNestedSafeAllocatorIfSignedAllocatorPresent(void *object) {
    void *allocator = (char *)object + 0x20;
    if (_ZNK13SafeAllocator18GetSignedAllocatorEv(allocator))
        _ZN13SafeAllocator7DestroyEv(allocator);
}
