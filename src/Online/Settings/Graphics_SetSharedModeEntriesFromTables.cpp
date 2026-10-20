#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250ba8; symbol: data_ov031_02250ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2248940; symbol: data_ov031_02248940.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 02010102010102000d003c00e6005e000d002800e6007000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov031 @ 0x2248932; symbol: data_ov031_02248932.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0001000000000001010001000001.
// Observed span: 14 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char GraphicsSetSharedModeEntriesFromTables_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov031 @ 0x224891c; symbol: data_ov031_0224891c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0800.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short GraphicsSetSharedModeEntriesFromTables_UnknownRoleInitializedBytes[];
extern "C" void WfcUtility_SetSpriteGroupPosition(void*,int,unsigned,void*);
// Original: arm9/ov031 @ 0x02222EB0; symbol: Graphics_SetSharedModeEntriesFromTables; size: 0x94.
// Sets base shared entry and mode-counted entries from byte/halfword lookup tables.
extern "C" void Graphics_SetSharedModeEntriesFromTables(char* value) {
 int count=WfcUtilityCreateBottomButtonBar_UnknownRoleInitializedBytes_Variant2[WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[0x17]];
 WfcUtility_SetSpriteGroupPosition(*(void**)(WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage+8),-1,0,value);
 int i=0;if(count>0)do {WfcUtility_SetSpriteGroupPosition(((void**)WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage)[i],-1,GraphicsSetSharedModeEntriesFromTables_UnknownRoleInitializedBytes[*(GraphicsSetSharedModeEntriesFromTables_UnknownRoleInitializedBytes_Variant2+2*WfcUtilityDestroyBottomButtonBar_UnknownRoleZeroInitializedStorage[0x17]+i)*2],value+4);++i;}while(i<count);
}
