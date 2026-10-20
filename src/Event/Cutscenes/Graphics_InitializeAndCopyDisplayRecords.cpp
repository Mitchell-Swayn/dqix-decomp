#include <globaldefs.h>
ARM

extern "C" void CutsceneCamera_InitializeCommandPool(void *, void *, unsigned);
extern "C" void InitializeSessionRecords(void *, void *, unsigned);
extern "C" void Event_ResetScriptResourceState(void);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov001 @ 0x0215A8DC; symbol: func_ov001_0215a8dc; size: 0x78.
extern "C" void Graphics_InitializeAndCopyDisplayRecords(void) {
    volatile unsigned short *display = (volatile unsigned short *)0x04000060;
    *display = (unsigned short)(*display & 0xCFFB);
    CutsceneCamera_InitializeCommandPool(*(void **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24), *(void **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 8), 8);
    for (int i = 0; i < 0x18; i++) {
        void *destination = (char *)*(void **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x1C) + i * 0x588;
        void *source = *(void **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x20);
        InitializeSessionRecords(destination, source, 0x1C);
    }
    Event_ResetScriptResourceState();
}
