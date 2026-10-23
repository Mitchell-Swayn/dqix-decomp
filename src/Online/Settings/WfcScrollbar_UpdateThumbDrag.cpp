#include <globaldefs.h>
ARM

extern "C" void ApplyContextValueAndStoreByte1A(unsigned);
extern "C" int WfcUtility_StopSequenceImmediately(...);
extern "C" int System_IsActiveInputPointWithinRectangle(...);
extern "C" int WfcScrollbar_UpdateDragResponseParameters(...);
extern "C" void ApplyContextValueAndStoreByte1A(unsigned);
extern "C" int WfcUtility_StopSequenceImmediately(...);
extern "C" int System_IsActiveInputPointWithinRectangle(...);
extern "C" int Input_CopyCurrentOrPreviousTouchPoint(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov031 @ 0x22491f4; symbol: data_ov031_022491f4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 55361e00.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcScrollbarGetPartBounds_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x22493b8; symbol: data_ov031_022493b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000001c000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2290cf4; symbol: data_ov031_02290cf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x022353B8; symbol: ClampInputPointToContextRangeAndUpdateState.
extern "C" void WfcScrollbar_UpdateThumbDrag(void){
if(System_IsActiveInputPointWithinRectangle(WfcScrollbarUpdateThumbDrag_UnknownRoleInitializedBytes)!=0){unsigned short point[2];Input_CopyCurrentOrPreviousTouchPoint(point);char* context=P(WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage,0);if(point[0]>=(int)H(context,16)-30){int selected=B(context,24)+((int)point[1]-H(context,22));if(selected<0)selected=0;else{int limit=B(context,25)-B(WfcScrollbarGetPartBounds_UnknownRoleInitializedBytes,B(context,27));if(selected>=limit)selected=limit;}WfcScrollbar_UpdateDragResponseParameters(selected);ApplyContextValueAndStoreByte1A(selected);B(P(WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage,0),29)=2;return;}}WfcUtility_StopSequenceImmediately();B(P(WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage,0),28)=0;B(P(WfcScrollbarDestroy_UnknownRoleZeroInitializedStorage,0),29)=3;
}
