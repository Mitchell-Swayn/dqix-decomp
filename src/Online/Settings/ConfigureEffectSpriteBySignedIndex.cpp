#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2248d02; symbol: data_ov031_02248d02.
// Keyboard cursor origin table, preserved as split symbols. ConfigureEffectSpriteBySignedIndex reads x from 0x2248d02 + key*4 and y from 0x2248d04 + key*4.
// Initial values: hex 5000.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248d04; symbol: data_ov031_02248d04.
// Keyboard cursor origin table, preserved as split symbols. ConfigureEffectSpriteBySignedIndex reads x from 0x2248d02 + key*4 and y from 0x2248d04 + key*4.
// Initial values: hex 4a0070004a0090004a0050006100700061009000610050007800700078009000780050008f0070008f0090008f000200a8008200a800.
// Observed span: 54 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;extern "C" unsigned short ConfigureEffectSpriteBySignedIndex_KeyboardCursorOriginTablePreservedAsSplitSymbols[],ConfigureEffectSpriteBySignedIndex_KeyboardCursorOriginTablePreservedAsSplitSymbols_Variant2[];
extern "C" void* WfcUtility_GetSpriteGroupEntry(void*,int);extern "C" void WfcUtility_ExpandSpriteCellTemplate(unsigned,unsigned,void*);extern "C" void WfcUtility_SetSpriteGroupPriority(void*,int,unsigned);extern "C" void WfcUtility_SetSpriteGroupPosition(void*,int,unsigned,unsigned);
// Original: arm9/ov031 @ 0x022269D8; symbol: ConfigureEffectSpriteBySignedIndex; size: 0x8C.
// Selects sprite entry44/45 based on signed index63 and applies table coordinates.
extern "C" void ConfigureEffectSpriteBySignedIndex(){unsigned entry=*(signed char*)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+0x63)<=11?0x44:0x45;void* output=WfcUtility_GetSpriteGroupEntry(*(void**)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+0x58),0);WfcUtility_ExpandSpriteCellTemplate(0,entry,output);WfcUtility_SetSpriteGroupPriority(*(void**)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+0x58),-1,2);int index=*(signed char*)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+0x63);WfcUtility_SetSpriteGroupPosition(*(void**)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+0x58),-1,ConfigureEffectSpriteBySignedIndex_KeyboardCursorOriginTablePreservedAsSplitSymbols[index*2],ConfigureEffectSpriteBySignedIndex_KeyboardCursorOriginTablePreservedAsSplitSymbols_Variant2[index*2]);}
