#include <globaldefs.h>
ARM
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_BuildRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
extern "C" int WfcUtility_IsTouchPressInsideRectangle(unsigned short*);
// Original data: arm9/ov031 @ 0x22493b8; symbol: data_ov031_022493b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000001c000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2250bfc; symbol: data_ov031_02250bfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x22489c8; symbol: data_ov031_022489c8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1100120000000000020c0c0c0b00010101010000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248a0c; symbol: data_ov031_02248a0c.
// Full keyboard key origins; 47 keys, four-byte stride. Input_UpdateSelectionFromRectangleGroups passes entries to hitbox construction. Negative navigation values are special fallback destinations handled by the consumer.
// Initial values: hex 0400510016005100280051003a0051004c0051005e005100700051008200510094005100a6005100b8005100ca00510020006700320067004400670056006700 ...; full span in module reference.
// Observed span: 188 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcKeyboardLayoutRow_FullKeyboardKeyOrigins[][2],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/ov031 @ 0x22489e4; symbol: data_ov031_022489e4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 04006700.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22489f4; symbol: data_ov031_022489f4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1b001200.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcKeyboardLayoutRow_UnknownRoleInitializedBytes_Variant3[][2],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant6[][2];
// Original data: arm9/ov031 @ 0x224b43c; symbol: data_ov031_0224b43c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000000000000002000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int InputUpdateSelectionFromRectangleGroups_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x22489c4; symbol: data_ov031_022489c4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 78001200.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22489dc; symbol: data_ov031_022489dc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0400aa008400aa00.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcKeyboardLayoutRow_UnknownRoleInitializedBytes_Variant2[][2],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov031 @ 0x022242EC; symbol: func_ov031_022242ec; size: 0x1E8.
extern "C" void Input_UpdateSelectionFromRectangleGroups() {
 unsigned short rect[4];
 if(!WfcUtility_IsTouchPressInsideRectangle(WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes)) return;
 *(signed char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x11e)=-1;
 int i=0;
 do {
 WfcUtility_BuildRectangleFromOriginAndSize(WfcKeyboardLayoutRow_FullKeyboardKeyOrigins[i],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant3,rect);
 if(WfcUtility_IsTouchPressInsideRectangle(rect)) {
 if(!WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage[0x124]) {WfcUtility_PlaySequenceArchiveEntry(9);return;}
 WfcUtility_PlaySequenceArchiveEntry(0);WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage[0x11e]=i;return;
 }
 ++i;
 }while(i<47);
 i=0;
 do {
 WfcUtility_BuildRectangleFromOriginAndSize(WfcKeyboardLayoutRow_UnknownRoleInitializedBytes_Variant3[i],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant6[i],rect);
 if(WfcUtility_IsTouchPressInsideRectangle(rect)) {
 if((i==3 && !WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage[0x123]) || (i==2 && !WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage[0x124])) {WfcUtility_PlaySequenceArchiveEntry(9);return;}
 WfcUtility_PlaySequenceArchiveEntry(InputUpdateSelectionFromRectangleGroups_UnknownRoleInitializedBytes[i]);WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage[0x11e]=i+47;return;
 }
 ++i;
 }while(i<4);
 i=0;
 do {
 WfcUtility_BuildRectangleFromOriginAndSize(WfcKeyboardLayoutRow_UnknownRoleInitializedBytes_Variant2[i],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant2,rect);
 if(WfcUtility_IsTouchPressInsideRectangle(rect)) {
 WfcUtility_PlaySequenceArchiveEntry(0);WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage[0x11e]=i+51;return;
 }
 ++i;
 }while(i<2);
}
