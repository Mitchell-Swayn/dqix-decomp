#include <globaldefs.h>
ARM
#pragma force_active on
// Original data: arm9/ov031 @ 0x02290c8c; symbol: data_ov031_02290c8c.
// Initial value: zero-filled at load; runtime pointer or shared state storage.
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x02248e84; symbol: data_ov031_02248e84.
// Initial value: 0x0004 (first halfword).
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x02248e86; symbol: data_ov031_02248e86.
// Initial value: 0x002e (first halfword).
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x02248e88; symbol: data_ov031_02248e88.
// Initial value: 0x00db (first halfword).
// Field offsets and indexed loads follow the original instructions.
// Full initial contents and references: docs/data-symbols/ov031.md.
extern "C" unsigned char TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned short WfcUtilityUpdateAccessPointSelectionHighlight_UnknownRoleInitializedBytes[];
extern "C" unsigned short WfcUtilityUpdateAccessPointSelectionHighlight_UnknownRoleInitializedBytes_Variant2[];
extern "C" unsigned short WfcUtilityUpdateAccessPointSelectionHighlight_UnknownRoleInitializedBytes_Variant3[];
extern "C" void WfcUtility_CreatePairedSelectionMarkers(unsigned, unsigned, unsigned, unsigned);
// Original: arm9/ov031 @ 0x0222C8CC; symbol: func_ov031_0222c8cc; size: 0x4C.
// Updates the paired selection markers from the selected access-point row.
extern "C" void WfcUtility_UpdateAccessPointSelectionHighlight(void)
{
    unsigned selected = TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[0];
    WfcUtility_CreatePairedSelectionMarkers(selected < 4 ? 2 : 3,
        WfcUtilityUpdateAccessPointSelectionHighlight_UnknownRoleInitializedBytes[selected * 4],
        WfcUtilityUpdateAccessPointSelectionHighlight_UnknownRoleInitializedBytes_Variant3[selected * 4],
        WfcUtilityUpdateAccessPointSelectionHighlight_UnknownRoleInitializedBytes_Variant2[selected * 4]);
}
#pragma force_active reset
