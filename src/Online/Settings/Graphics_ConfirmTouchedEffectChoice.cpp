#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c00; symbol: data_ov031_02250c00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage;
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
// Original data: arm9/ov031 @ 0x22493b8; symbol: data_ov031_022493b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000001c000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes[],WfcNumberPadLayoutRow_NumericKeyboardKeyOrigins[],WfcNumberPadCreate_UnknownRoleInitializedBytes_Variant3[],WfcNumberPadLayoutRow_UnknownRoleInitializedBytes[],GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant3[],WfcNumberPadLayoutRow_UnknownRoleInitializedBytes_Variant2[],GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant4[];
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
extern "C" void ConfigureEffectSpriteBySignedIndex();
extern "C" void WfcUtility_BuildRectangleFromOriginAndSize(unsigned short*,unsigned short*,unsigned short*);
extern "C" int System_IsTouchInsideRectangle(unsigned short*);
#define B(o) (*(unsigned char*)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+(o)))
#define ACTIVE (*(signed char*)(WfcNumberPadDestroy_UnknownRoleZeroInitializedStorage+0x61))
#define CHECK_GROUP(ORIGIN,SIZE,COUNT,BASE,TABLE) \
{unsigned short* size;unsigned short* origin=ORIGIN;size=SIZE;int i=0;do{WfcUtility_BuildRectangleFromOriginAndSize(origin,size,rect);if(System_IsTouchInsideRectangle(rect)){if(ACTIVE!=i+BASE)return;B(0x60)=TABLE[i];B(0x63)=i+BASE;ConfigureEffectSpriteBySignedIndex();return;}++i;origin+=2;}while(i<COUNT);}
// Original: arm9/ov031 @ 0x02226108; symbol: func_ov031_02226108; size: 0x1D0.
// Tests three effect-choice rectangle groups, confirming only the already-active choice.
extern "C" void Graphics_ConfirmTouchedEffectChoice(){
unsigned short rect[4];B(0x60)=0;
if(!System_IsTouchInsideRectangle(WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes))return;
CHECK_GROUP(WfcNumberPadLayoutRow_NumericKeyboardKeyOrigins,WfcNumberPadCreate_UnknownRoleInitializedBytes_Variant3,10,0,Graphics_ConfirmTouchedEffectChoice_Text7894561230)
CHECK_GROUP(WfcNumberPadLayoutRow_UnknownRoleInitializedBytes,GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant3,2,10,GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant2)
CHECK_GROUP(WfcNumberPadLayoutRow_UnknownRoleInitializedBytes_Variant2,GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes_Variant4,2,12,GraphicsConfirmTouchedEffectChoice_UnknownRoleInitializedBytes)
}
