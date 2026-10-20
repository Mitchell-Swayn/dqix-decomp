#include <globaldefs.h>
ARM
extern "C" void Menu_CancelCharacterPreviewLoads(void*);
extern "C" void _ZN8Object3D10InitializeEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
// Original: arm9/ov023 @ 0x021E4F18; symbol: Unclassified_InitializeTenEmbeddedObjectsAndReleaseAllocators; size: 0x4C.
// Runs setup, initializes ten embedded Object3D values at 0xAC-byte strides while destroying their allocator slots, then destroys the final allocator at +0x780.
extern "C" void CharacterPreview_ResetModelsAndReleaseAllocators(unsigned char* self) {
    Menu_CancelCharacterPreviewLoads(self);
    for (int i = 0; i < 10; ++i) {
        _ZN8Object3D10InitializeEv(self + i * 0xac);
        _ZN13SafeAllocator7DestroyEv(self + 0x6b8 + i * 0x14);
    }
    _ZN13SafeAllocator7DestroyEv(self + 0x780);
}
