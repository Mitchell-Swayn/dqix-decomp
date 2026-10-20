#include <globaldefs.h>
ARM
#pragma opt_common_subs off
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2248c80; symbol: data_ov031_02248c80.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 12130000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248c84; symbol: data_ov031_02248c84.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 10110000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Graphics_ConfirmTouchedEffectChoice_Text7894561230[],GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant2[],GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes[];
extern "C" void WfcNumberPad_MoveSelection(int);
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" int WfcUtility_AreButtonsPressed(unsigned);
extern "C" bool WfcUtility_AreButtonsPressedOrRepeating(unsigned);
extern "C" int WfcUtility_AreButtonsReleased(unsigned);
#define B(o) (*(unsigned char*)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+(o)))
#define SELECTED (*(signed char*)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+0x63))
// Original: arm9/ov031 @ 0x02226514; symbol: func_ov031_02226514; size: 0x19C.
// Moves effect selection, maps enabled choices into pending codes and handles cancel edge state.
extern "C" void Graphics_HandleEffectSelectionAndCancelInput(){
if(WfcUtility_AreButtonsPressedOrRepeating(32))WfcNumberPad_MoveSelection(0);
if(WfcUtility_AreButtonsPressedOrRepeating(64))WfcNumberPad_MoveSelection(1);
if(WfcUtility_AreButtonsPressedOrRepeating(16))WfcNumberPad_MoveSelection(2);
if(WfcUtility_AreButtonsPressedOrRepeating(128))WfcNumberPad_MoveSelection(3);
if(WfcUtility_AreButtonsPressed(1)){
char* state=WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;int selected=*(signed char*)(state+0x63);
if(selected<10){if((*(unsigned char*)(state+0x67))){(*(unsigned char*)(state+0x60))=Graphics_ConfirmTouchedEffectChoice_Text7894561230[selected];return;}else {WfcUtility_PlaySequenceArchiveEntry(9);return;}}
else if(selected-10<2){
if((selected-10==0 && (*(unsigned char*)(state+0x66))==0) || (selected-10==1 && (*(unsigned char*)(state+0x68))==0)){WfcUtility_PlaySequenceArchiveEntry(9);return;}
(*(unsigned char*)(state+0x60))=GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant2[selected-10];return;
}else (*(unsigned char*)(state+0x60))=GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes[selected-12];
}
if(WfcUtility_AreButtonsPressedOrRepeating(2)){
if(B(0x66)==0){if(B(0x69))return;WfcUtility_PlaySequenceArchiveEntry(9);B(0x69)=1;return;}
B(0x60)=16;return;
}
if(WfcUtility_AreButtonsReleased(2))B(0x69)=0;
}
