#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/ov031 @ 0x02290CA0; symbol: data_ov031_02290ca0.
// Shared list state; zero-initialized storage.
extern "C" unsigned char StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x02248F78; symbol: data_ov031_02248f78.
// Read-only action-to-marker mapping.
extern "C" unsigned char WfcSettingsListUpdateSelectionHighlight_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x02249002; symbol: data_ov031_02249002.
// Read-only packed marker rectangle fields.
extern "C" unsigned short WfcSettingsListUpdateSelectionHighlight_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov031 @ 0x02249004; symbol: data_ov031_02249004.
// Read-only rectangle field alias at two-byte offset.
extern "C" unsigned short WfcSettingsListUpdateSelectionHighlight_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/ov031 @ 0x02249006; symbol: data_ov031_02249006.
// Read-only rectangle field alias at four-byte offset.
extern "C" unsigned short WfcSettingsListUpdateSelectionHighlight_UnknownRoleInitializedBytes_Variant4[];
extern "C" void WfcUtility_CreatePairedSelectionMarkers(unsigned, unsigned, unsigned, unsigned);
#pragma force_active on
// Original: arm9/ov031 @ 0x022307FC; symbol: func_ov031_022307fc; size: 0xD8.
// Maps the selected action to its marker rectangle and offsets list-row highlights by their visible row.
extern "C" void WfcSettingsList_UpdateSelectionHighlight()
{
    struct Mapping { unsigned char values[14]; };
    struct Rectangle { unsigned short x, y, width, height; };
    Mapping mapping = *(Mapping*)WfcSettingsListUpdateSelectionHighlight_UnknownRoleInitializedBytes;
    int entry = mapping.values[StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[0]];
    if (entry >= 3)
    {
        WfcUtility_CreatePairedSelectionMarkers(3,
            WfcSettingsListUpdateSelectionHighlight_UnknownRoleInitializedBytes_Variant2[entry * 4],
            WfcSettingsListUpdateSelectionHighlight_UnknownRoleInitializedBytes_Variant4[entry * 4],
            WfcSettingsListUpdateSelectionHighlight_UnknownRoleInitializedBytes_Variant3[entry * 4]);
        return;
    }
    Rectangle rectangle = ((Rectangle*)WfcSettingsListUpdateSelectionHighlight_UnknownRoleInitializedBytes_Variant2)[entry];
    rectangle.y += StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[2] * 29;
    WfcUtility_CreatePairedSelectionMarkers(1, rectangle.x, rectangle.width, rectangle.y);
}
