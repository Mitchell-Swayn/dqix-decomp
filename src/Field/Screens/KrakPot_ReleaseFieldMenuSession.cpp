#include <globaldefs.h>
extern "C" void VRAMBankConfig_Reset(void *);
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *);
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameState_GetFieldOrbitCamera(void *);
extern "C" void Camera_EnableOrbitInput(void *);
// Original data: arm9/ov017 @ 0x21d83ec; symbol: data_ov017_021d83ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov017 @ 0x021B14EC; symbol: func_ov017_021b14ec; size: 0x78.
extern "C" void KrakPot_ReleaseFieldMenuSession(void *self) {
    void *resource = *(void **)((char *)self + 0x1c);
    if (resource) VRAMBankConfig_Reset(resource);
    KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage = 0;
    void *allocator = (char *)self + 8;
    void *signedAllocator = _ZNK13SafeAllocator18GetSignedAllocatorEv(allocator);
    if (signedAllocator) {
        _ZN13SafeAllocator7DestroyEv(allocator);
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, signedAllocator);
    }
    OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);
    OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
    void *game = _ZN9GameState11GetInstanceEv();
    void *object = GameState_GetFieldOrbitCamera(game);
    if (object) Camera_EnableOrbitInput(object);
}
