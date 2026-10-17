#include <globaldefs.h>
ARM
extern "C" void func_ov017_021c12b0(int);
extern "C" void * volatile data_ov017_021d8478;
extern "C" void PopGlobalStackAndOptionallyNotify(int);
extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" unsigned int data_02114e20;
// Original: arm9/ov017 @ 0x021C1394; symbol: func_ov017_021c1394; size: 0x70.
extern "C" void Resource_CleanupOverlaySlotAndBuffer(void *state) {
    if (*((unsigned char *)state + 0x1e) != 0) func_ov017_021c12b0(0);
    if (data_ov017_021d8478 != 0) {
        data_ov017_021d8478 = 0;
        PopGlobalStackAndOptionallyNotify(1);
        OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(1);
    }
    void *allocator = (char *)state + 8;
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    _ZN13SafeAllocator7DestroyEv(allocator);
    Memory_FreeThroughAllocatorUnion(&data_02114e20, allocation);
}
