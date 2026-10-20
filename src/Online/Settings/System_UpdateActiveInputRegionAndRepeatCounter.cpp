#include <globaldefs.h>
ARM
struct Rect { unsigned short v[4]; };
// Original data: arm9/ov031 @ 0x22493b8; symbol: data_ov031_022493b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000001c000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Rect WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x22489c4; symbol: data_ov031_022489c4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 78001200.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22489c8; symbol: data_ov031_022489c8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1100120000000000020c0c0c0b00010101010000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22489dc; symbol: data_ov031_022489dc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0400aa008400aa00.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22489ec; symbol: data_ov031_022489ec.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 04009300dc005100.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22489fc; symbol: data_ov031_022489fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2800120020001200.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2248a0c; symbol: data_ov031_02248a0c.
// Full keyboard key origins; 47 keys, four-byte stride. Input_UpdateSelectionFromRectangleGroups passes entries to hitbox construction. Negative navigation values are special fallback destinations handled by the consumer.
// Initial values: hex 0400510016005100280051003a0051004c0051005e005100700051008200510094005100a6005100b8005100ca00510020006700320067004400670056006700 ...; full span in module reference.
// Observed span: 188 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcKeyboardLayoutRow_FullKeyboardKeyOrigins[][2],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant3[2],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant8[][2],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant5[][2],WfcKeyboardLayoutRow_UnknownRoleInitializedBytes_Variant2[][2],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant2[2];
// Original data: arm9/ov031 @ 0x2250bfc; symbol: data_ov031_02250bfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage;
extern "C" void System_SetActiveInputRegion(int);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_BuildRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
extern "C" int System_IsActiveInputPointWithinRectangle(const Rect*);
// Original: arm9/ov031 @ 0x0222481C; symbol: func_ov031_0222481c; size: 0x204.
extern "C" void System_UpdateActiveInputRegionAndRepeatCounter() {
 Rect rect;
 if(System_IsActiveInputPointWithinRectangle(&WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes)) {
  for(int i=0;i<47;i++) {
   WfcUtility_BuildRectangleFromOriginAndSize(WfcKeyboardLayoutRow_FullKeyboardKeyOrigins[i],WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant3,rect.v);
   if(System_IsActiveInputPointWithinRectangle(&rect)) {
    if(*(signed char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x11e)!=i) goto fail;
    System_SetActiveInputRegion(i);goto done;
   }
  }
  unsigned short* size=WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant8[0];
  unsigned short* origin=WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant5[0];
  for(int i=2;i<4;i++,size+=2,origin+=2) {
   WfcUtility_BuildRectangleFromOriginAndSize(origin,size,rect.v);
   if(System_IsActiveInputPointWithinRectangle(&rect)) {
    if(*(signed char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x11e)!=i+47) goto fail;
    System_SetActiveInputRegion(i+47);
    if(i!=3)return;
    ++*(unsigned char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x122);
    if(*(unsigned char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x122)<40)return;
    if(!*(unsigned char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x123)) {
     WfcUtility_PlaySequenceArchiveEntry(9);
     *(signed char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x11e)=-1;
     return;
    } else {
     *(unsigned char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x11c)=0x80;
     *(unsigned char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x122)-=7;
     return;
    }
   }
  }
  unsigned short* lastOrigin=WfcKeyboardLayoutRow_UnknownRoleInitializedBytes_Variant2[0];
  for(int i=0;i<2;i++,lastOrigin+=2) {
   WfcUtility_BuildRectangleFromOriginAndSize(lastOrigin,WfcKeyboardConfirmTouchInput_UnknownRoleInitializedBytes_Variant2,rect.v);
   if(System_IsActiveInputPointWithinRectangle(&rect)) {
    if(*(signed char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x11e)!=i+51) goto fail;
    System_SetActiveInputRegion(i+51);goto done;
   }
  }
 }
 fail: System_SetActiveInputRegion(-1);
 done: *(unsigned char*)(WfcKeyboardDestroy_UnknownRoleZeroInitializedStorage+0x122)=0;
}
