#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2249054; symbol: data_ov031_02249054.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000102020304050606070800.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcSettingsListActivateAction_UnknownRoleInitializedBytes[];
extern "C" int WfcSettingsList_FindVisibleRowSlot(int value);
extern "C" void WfcSettingsList_UpdateSelectionHighlight(void);
// Original: arm9/ov031 @ 0x02230984; symbol: func_ov031_02230984; size: 0x30.
extern "C" void WfcSettingsList_SelectActionAndHighlight(unsigned char index) {
    StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[0] = index;
    StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[2] = (unsigned char)WfcSettingsList_FindVisibleRowSlot(WfcSettingsListActivateAction_UnknownRoleInitializedBytes[index]);
    WfcSettingsList_UpdateSelectionHighlight();
}
