#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" {
// Original data: arm9/ov031 @ 0x22493b8; symbol: data_ov031_022493b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000001c000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned short WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char* WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2248c88; symbol: data_ov031_02248c88.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1c0014000c000400.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248c90; symbol: data_ov031_02248c90.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1c001400.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248c94; symbol: data_ov031_02248c94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 78001200000000000203030301000000000200000000010000000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248cb0; symbol: data_ov031_02248cb0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 7200910092009100.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248cb8; symbol: data_ov031_02248cb8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0400aa008400aa00.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248cda; symbol: data_ov031_02248cda.
// Numeric keyboard key origins; 10 keys, four-byte stride. Graphics_UpdateTouchSelectionFromThreeButtonGroups iterates 10 entries. Negative navigation values are special fallback destinations handled by the consumer.
// Initial values: hex 52004c0072004c0092004c0052006300720063009200630052007a0072007a0092007a0052009100.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned short WfcNumberPadLayoutRow_NumericKeyboardKeyOrigins[],WfcNumberPadCreate_UnknownRoleInitializedBytes_Variant3[],WfcNumberPadLayoutRow_UnknownRoleInitializedBytes[],GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant3[],WfcNumberPadLayoutRow_UnknownRoleInitializedBytes_Variant2[],GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant4[];
void WfcUtility_BuildRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
int WfcUtility_IsTouchPressInsideRectangle(unsigned short*);
void WfcUtility_PlaySequenceArchiveEntry(int);
}
// Original: arm9/ov031 @ 0x02225F2C; symbol: func_ov031_02225f2c; size: 0x1DC.
extern "C" void Graphics_UpdateTouchSelectionFromThreeButtonGroups() {
 if(!WfcUtility_IsTouchPressInsideRectangle(WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes))return;
 *(signed char*)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+0x61)=-1;
 unsigned short rect[4];
 {
 unsigned short* origin=WfcNumberPadLayoutRow_NumericKeyboardKeyOrigins;
 for(int i=0;i<10;i++,origin+=2) {
  WfcUtility_BuildRectangleFromOriginAndSize(origin,WfcNumberPadCreate_UnknownRoleInitializedBytes_Variant3,rect);
  if(WfcUtility_IsTouchPressInsideRectangle(rect)) {
   if(!WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x67]) {WfcUtility_PlaySequenceArchiveEntry(9);return;}
   WfcUtility_PlaySequenceArchiveEntry(0);
   WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x61]=i;
   return;
  }
 }
 }
 {
 unsigned short* origin=WfcNumberPadLayoutRow_UnknownRoleInitializedBytes;
 for(int i=0;i<2;i++,origin+=2) {
  WfcUtility_BuildRectangleFromOriginAndSize(origin,GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant3,rect);
  if(WfcUtility_IsTouchPressInsideRectangle(rect)) {
   if((i==0 && !WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x66]) || (i==1 && !WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x68])) {WfcUtility_PlaySequenceArchiveEntry(9);return;}
   WfcUtility_PlaySequenceArchiveEntry(0);
   WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x61]=i+10;
   return;
  }
 }
 }
 {
 unsigned short* origin=WfcNumberPadLayoutRow_UnknownRoleInitializedBytes_Variant2;
 for(int i=0;i<2;i++,origin+=2) {
  WfcUtility_BuildRectangleFromOriginAndSize(origin,GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant4,rect);
  if(WfcUtility_IsTouchPressInsideRectangle(rect)) {
   WfcUtility_PlaySequenceArchiveEntry(0);
   WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage[0x61]=i+12;
   return;
  }
 }
 }
}
