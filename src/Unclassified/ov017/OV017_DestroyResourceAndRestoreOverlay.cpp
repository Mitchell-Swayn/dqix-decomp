#include <globaldefs.h>
extern "C" void ResetResourceWithModeZero(void *);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" void OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(int);
extern "C" void PopGlobalStackAndOptionallyNotify(int);
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameState_GetField3B0ObjectWithFlag4(void *);
extern "C" void Object_SetWordAtOffset23CTo1(void *);
extern "C" unsigned data_ov017_021d83ec;
extern "C" unsigned char data_02114e20[];
// Original: arm9/ov017 @ 0x021B14EC; symbol: func_ov017_021b14ec; size: 0x78.
extern "C" void OV017_DestroyResourceAndRestoreOverlay(void *self) {
    void *resource = *(void **)((char *)self + 0x1c);
    if (resource) ResetResourceWithModeZero(resource);
    data_ov017_021d83ec = 0;
    void *allocator = (char *)self + 8;
    void *signedAllocator = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    if (signedAllocator) {
        _ZN13SafeAllocator7DestroyEv(allocator);
        Memory_FreeThroughAllocatorUnion(data_02114e20, signedAllocator);
    }
    OverlayLoader_PopSlotAndOptionallyRestorePriorOverlay(1);
    PopGlobalStackAndOptionallyNotify(1);
    void *game = _ZN9GameState11GetInstanceEv();
    void *object = GameState_GetField3B0ObjectWithFlag4(game);
    if (object) Object_SetWordAtOffset23CTo1(object);
}
