#include <globaldefs.h>
ARM
#pragma force_active on
// Original data: arm9/ov031 @ 0x02248e2c; symbol: data_ov031_02248e2c.
// Initial value: 0x02 (palette bank).
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x02290c8c; symbol: data_ov031_02290c8c.
// Initial value: zero-filled at load; runtime pointer or shared state storage.
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityRestoreAccessPointListPalette_UnknownRoleInitializedBytes;
extern "C" unsigned char TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_QueueBackgroundPaletteBankCopy(unsigned, unsigned, unsigned);
// Original: arm9/ov031 @ 0x0222CB5C; symbol: func_ov031_0222cb5c; size: 0x30.
// Restores the list background palette using the saved palette-bank index.
extern "C" void WfcUtility_RestoreAccessPointListPalette(void)
{
    unsigned palette = WfcUtilityRestoreAccessPointListPalette_UnknownRoleInitializedBytes;
    // Preserve the original byte-local save while passing its widened value.
    volatile unsigned char savedPalette = palette;
    unsigned char *context = *(unsigned char **)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4);
    WfcUtility_QueueBackgroundPaletteBankCopy(*(unsigned *)(context + 8), palette, palette);
}
#pragma force_active reset
