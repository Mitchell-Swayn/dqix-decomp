#include <globaldefs.h>
ARM
extern "C" void Graphics_SetMainDisplayModeAndSelection(unsigned short, unsigned, int);
// Original data: arm9/ov016 @ 0x219d0c0; symbol: data_ov016_0219d0c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" volatile unsigned char MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov016 @ 0x0218BE7C; symbol: func_ov016_0218be7c; size: 0x48.
extern "C" void Graphics_ToggleMainDisplayMode(void) {
    if (*(volatile unsigned*)(MemoryAllocateSafe_UnknownRoleZeroInitializedStorage + 0x18) == 0)
        Graphics_SetMainDisplayModeAndSelection(6, 0, 0);
    else
        Graphics_SetMainDisplayModeAndSelection(2, 0, 0);
    *(volatile unsigned*)(MemoryAllocateSafe_UnknownRoleZeroInitializedStorage + 0x18) = *(volatile unsigned*)(MemoryAllocateSafe_UnknownRoleZeroInitializedStorage + 0x18) ^ 1;
}
