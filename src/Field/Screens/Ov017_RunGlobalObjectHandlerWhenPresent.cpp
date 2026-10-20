#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83ec; symbol: data_ov017_021d83ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage[];
extern "C" void RenderSelectionScreenAndResetTransfers(void);
// Original: arm9/ov017 @ 0x021B1D04; symbol: func_ov017_021b1d04; size: 0x20.
extern "C" void Ov017_RunGlobalObjectHandlerWhenPresent(void) {
    if (*(void **)KrakPotDrawFieldMenuSession_UnknownRoleZeroInitializedStorage != 0) RenderSelectionScreenAndResetTransfers();
}
