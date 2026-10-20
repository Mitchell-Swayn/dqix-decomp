#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
extern "C" void CutsceneCamera_InitializeCommandPool(void*, void*, unsigned);
// Original: arm9/ov001 @ 0x0215A954; symbol: func_ov001_0215a954; size: 0x60.
extern "C" void Graphics_ResetWindowConfiguration(void) {
    volatile unsigned short* display = (volatile unsigned short*)0x04000060;
    unsigned short control = *display;
    *display = (control & ~0x3000) | 4;
    *(volatile unsigned short*)0x04000340 = 0;
    CutsceneCamera_InitializeCommandPool(*(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24), *(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 8), 8);
    *(unsigned*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0xEC) = 0;
    if (*(unsigned*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0xE4) != 0)
        *(unsigned*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage + 0xE4) = 0;
}
