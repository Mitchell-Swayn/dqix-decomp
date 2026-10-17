#include <globaldefs.h>
ARM
extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*, void*);
extern "C" unsigned char data_02114e20[];
// Original: arm9/ov003 @ 0x0217E36C; symbol: func_ov003_0217e36c; size: 0x4C.
extern "C" void Overlay_DestroyObjectAndFree(void* object) {
    if (*(unsigned*)((char*)object + 0x20) != 0) {
        OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(1);
        *(unsigned*)((char*)object + 0x20) = 0;
    }
    void* allocatorObject = (char*)object + 0xc;
    void* allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocatorObject);
    _ZN13SafeAllocator7DestroyEv(allocatorObject);
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocation);
}
