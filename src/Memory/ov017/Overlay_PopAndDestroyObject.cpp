#include <globaldefs.h>
ARM
extern "C" void PopGlobalStackAndOptionallyNotify(int);
extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" unsigned char data_02114e20[];
extern "C" void* volatile data_ov017_021d840c;
// Original: arm9/ov017 @ 0x021B2C88; symbol: func_ov017_021b2c88; size: 0x60.
extern "C" void Overlay_PopAndDestroyObject(void* object) {
    if (data_ov017_021d840c != 0) {
        PopGlobalStackAndOptionallyNotify(1);
        OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(1);
        data_ov017_021d840c = 0;
    }
    void* allocatorObject = (char*)object + 0xc;
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocatorObject);
    _ZN13SafeAllocator7DestroyEv(allocatorObject);
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocation);
}
