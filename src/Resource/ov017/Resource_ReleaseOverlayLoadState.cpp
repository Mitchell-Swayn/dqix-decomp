#include <globaldefs.h>
ARM
extern "C" void Memory_FreeThroughAllocatorUnion(void* allocator,void* allocation);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int enabled);
extern "C" void PopGlobalStackAndOptionallyNotify(int enabled);
extern "C" void Graphics_ResetOverlayBackgroundState(char* p);
extern "C" char *data_ov017_021d83f0[];
extern "C" char data_02114e20[];
// Original: arm9/ov017 @ 0x021B2200; symbol: func_ov017_021b2200; size: 0x8C.
extern "C" void Resource_ReleaseOverlayLoadState(char *self) {
    if (*(int*)(self + 12) > -1) {
        void *loader = _ZN16BackgroundLoader11GetInstanceEv();
        _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)(self + 12));
        *(int*)(self + 12) = -1;
    }
    if (data_ov017_021d83f0[1]) {
        Graphics_ResetOverlayBackgroundState(data_ov017_021d83f0[1]);
        data_ov017_021d83f0[1] = 0;
        PopGlobalStackAndOptionallyNotify(1);
        OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(1);
    }
    void *allocation = _ZNK13SafeAllocator18GetSignedAllocatorEv(self + 16);
    if (allocation) {
        _ZN13SafeAllocator7DestroyEv(self + 16);
        Memory_FreeThroughAllocatorUnion(data_02114e20, allocation);
    }
}
