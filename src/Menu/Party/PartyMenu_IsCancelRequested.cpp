#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short *, unsigned int);
extern "C" int Window_ClassifyTouchAgainstSelectedCanvas(void *);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov002 @ 0x02161B48; symbol: Object_TestOwnerStateAndSecondaryCondition; size: 0x50.
extern "C" int PartyMenu_IsCancelRequested(void *object, int enabled) {
    if (Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 2)) return 1;
    if (enabled && Window_ClassifyTouchAgainstSelectedCanvas((char *)object + 0xec8) == 2) return 1;
    return 0;
}
