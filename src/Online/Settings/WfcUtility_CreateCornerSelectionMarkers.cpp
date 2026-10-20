#include <globaldefs.h>
ARM
extern "C" void Overlay_ClearFourSharedObjects();
extern "C" void *WfcUtility_CreateSpriteGroupFromCellTemplate(int,int,int);
extern "C" void WfcUtility_SetSpriteGroupPriority(void*,int,unsigned);
extern "C" void WfcUtility_SetSpriteGroupPosition(void*,int,int,int);
// Original data: arm9/ov031 @ 0x2250bf0; symbol: data_ov031_02250bf0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void **OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022237DC; symbol: Graphics_CreateFourObjectsAtRectangle; size: 0xf0.
// Creates resources six through nine and places them at the four supplied coordinate combinations.
extern "C" void WfcUtility_CreateCornerSelectionMarkers(int x1,int x2,int y1,int y2){
int resource=6;Overlay_ClearFourSharedObjects();
 for(int i=0;i<4;++i,++resource){OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[i]=WfcUtility_CreateSpriteGroupFromCellTemplate(0,resource,1);WfcUtility_SetSpriteGroupPriority(OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[i],-1,1);}
 WfcUtility_SetSpriteGroupPosition(OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[0],-1,x1,y1);
 WfcUtility_SetSpriteGroupPosition(OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[1],-1,x2,y1);
 WfcUtility_SetSpriteGroupPosition(OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[2],-1,x1,y2);
 WfcUtility_SetSpriteGroupPosition(OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[3],-1,x2,y2);
}
