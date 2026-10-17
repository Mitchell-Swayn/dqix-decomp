#include <globaldefs.h>
ARM
extern "C" void *Object_GetGlobalSixteenEntryDisplayState(void);
extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int *, int);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" unsigned int data_02114e20;
extern "C" void func_020a0c0c(void);
// Original: arm9/ov017 @ 0x021AC2A8; symbol: func_ov017_021ac2a8; size: 0x44.
extern "C" void Resource_RemoveDisplayStateAndFreeBuffers(void *owner) {
    RemoveMatchingNodeAndResetMatchingObjectSlots((int *)Object_GetGlobalSixteenEntryDisplayState(), 5);
    void *allocator = (char *)owner + 0x10;
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    if (allocation != 0) {
        _ZN13SafeAllocator7DestroyEv(allocator);
        Memory_FreeThroughAllocatorUnion(&data_02114e20, allocation);
    }
    func_020a0c0c();
}
