#include <globaldefs.h>
ARM
extern "C" void _ZN7Model3D5ClearEv(void*);
extern "C" void _ZN8Object3D10InitializeEv(void*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void TextureVRAM_SnapshotAllocationBounds(char*);
// Original: arm9/ov017 @ 0x0219BC50; symbol: func_ov017_0219bc50; size: 0x38.
extern "C" void Model3D_ResetAttachedObjectsAndAllocator(char* p) {
    _ZN7Model3D5ClearEv(*(void**)(p + 0x36c8));
    _ZN8Object3D10InitializeEv(*(void**)(p + 0x36cc));
    _ZN13SafeAllocator5ResetEv(p + 0xb0);
    TextureVRAM_SnapshotAllocationBounds(p + 0x56c);
}
