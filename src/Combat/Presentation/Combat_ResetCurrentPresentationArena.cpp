#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator5ResetEv(void *);
extern "C" void TextureVRAM_SnapshotAllocationBounds(char *);
extern "C" void Combat_ProcessDeferredPresentationCleanup(void *, unsigned int);
// Original: arm9/ov025 @ 0x021E8B6C; symbol: func_ov025_021e8b6c; size: 0x38.
extern "C" void Combat_ResetCurrentPresentationArena(void *state) {
    volatile unsigned char *bytes = (volatile unsigned char *)state;
    _ZN13SafeAllocator5ResetEv(*(void **)((char *)state + bytes[0x30] * 4 + 0x10));
    TextureVRAM_SnapshotAllocationBounds((char *)*(void **)((char *)state + bytes[0x30] * 4 + 0x20));
    Combat_ProcessDeferredPresentationCleanup(state, bytes[0x30]);
}
