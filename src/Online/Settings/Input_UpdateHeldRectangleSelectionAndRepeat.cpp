#include <globaldefs.h>
ARM
extern "C" void WfcNumberPad_SetHighlightedKey(int);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_BuildRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
extern "C" int System_IsActiveInputPointWithinRectangle(const void*);
// Original data: arm9/ov031 @ 0x22493b8; symbol: data_ov031_022493b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000001c000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2248c88; symbol: data_ov031_02248c88.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1c0014000c000400.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248cda; symbol: data_ov031_02248cda.
// Numeric keyboard key origins; 10 keys, four-byte stride. Graphics_UpdateTouchSelectionFromThreeButtonGroups iterates 10 entries. Negative navigation values are special fallback destinations handled by the consumer.
// Initial values: hex 52004c0072004c0092004c0052006300720063009200630052007a0072007a0092007a0052009100.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcNumberPadLayoutRow_NumericKeyboardKeyOrigins[][2],WfcNumberPadCreate_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/ov031 @ 0x2248c90; symbol: data_ov031_02248c90.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1c001400.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248cb0; symbol: data_ov031_02248cb0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 7200910092009100.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcNumberPadLayoutRow_UnknownRoleInitializedBytes[][2],GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/ov031 @ 0x2248c94; symbol: data_ov031_02248c94.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 78001200000000000203030301000000000200000000010000000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248cb8; symbol: data_ov031_02248cb8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0400aa008400aa00.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcNumberPadLayoutRow_UnknownRoleInitializedBytes_Variant2[][2],GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant4[];
struct State { unsigned char pad[0x60]; unsigned char state; signed char selected; unsigned char pad2[3]; unsigned char hold,enabled; };
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" State* WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022262D8; symbol: func_ov031_022262d8; size: 0x1F0.
extern "C" void Input_UpdateHeldRectangleSelectionAndRepeat() {
 unsigned short rect[4];
 if(!System_IsActiveInputPointWithinRectangle(WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes)) goto reset;
 {
 int i=0;
 do {
 WfcUtility_BuildRectangleFromOriginAndSize(WfcNumberPadLayoutRow_NumericKeyboardKeyOrigins[i],WfcNumberPadCreate_UnknownRoleInitializedBytes_Variant3,rect);
 if(System_IsActiveInputPointWithinRectangle(rect)) {
 if(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->selected!=i) goto reset;
 WfcNumberPad_SetHighlightedKey(i);goto done;
 }
 ++i;
 }while(i<10);
 }
 {
 unsigned short* origin=WfcNumberPadLayoutRow_UnknownRoleInitializedBytes[0];
 int i=0;
 do {
 WfcUtility_BuildRectangleFromOriginAndSize(origin,GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant3,rect);
 if(System_IsActiveInputPointWithinRectangle(rect)) {
 int code=i+10;
 if(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->selected!=code) goto reset;
 WfcNumberPad_SetHighlightedKey(code);
 if(i!=0) goto done;
 WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->hold++;
 if(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->hold<40) return;
 if(!WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->enabled) {
 WfcUtility_PlaySequenceArchiveEntry(9);
 WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->selected=-1;return;
 }
 WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->state=16;
 WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->hold-=7;return;
 }
 ++i;origin+=2;
 }while(i<2);
 }
 {
 unsigned short* origin=WfcNumberPadLayoutRow_UnknownRoleInitializedBytes_Variant2[0];
 int i=0;
 do {
 WfcUtility_BuildRectangleFromOriginAndSize(origin,GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant4,rect);
 if(System_IsActiveInputPointWithinRectangle(rect)) {
 int code=i+12;
 if(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->selected!=code) goto reset;
 WfcNumberPad_SetHighlightedKey(code);goto done;
 }
 ++i;origin+=2;
 }while(i<2);
 }
 reset:WfcNumberPad_SetHighlightedKey(-1);
 done:WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage->hold=0;
}
