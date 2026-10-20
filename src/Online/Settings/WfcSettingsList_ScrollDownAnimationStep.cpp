#include <globaldefs.h>
ARM
struct State{int a;unsigned short index;short pad;char* child;};
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" State StartMode6ContextCallback_UnknownRoleZeroInitializedStorage;
extern "C" void WfcScrollbar_DisableTouchInput(void*);
extern "C" void Overlay_ClearFourSharedObjects();
extern "C" int FastIntModulus(int,int);
extern "C" void WfcSettingsList_PositionVisibleRowSprites();
extern "C" void WfcSettingsList_RedrawVisibleRows();
extern "C" void WfcScrollbar_SetThumbOffset(int);
extern "C" void WfcScrollbar_EnableTouchInput();
extern "C" void WfcSettingsList_ResolveSelectedRowAction();
extern "C" void WfcUtility_RequestTaskRemoval(int,void*);
// Original: arm9/ov031 @ 0x022306D4; symbol: AdvanceSelectionBySixAndUpdateScaledPosition; size: 0xa4.
extern "C" void WfcSettingsList_ScrollDownAnimationStep(void* self) {
 WfcScrollbar_DisableTouchInput(self);Overlay_ClearFourSharedObjects();StartMode6ContextCallback_UnknownRoleZeroInitializedStorage.index+=6;int remainder=FastIntModulus(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage.index,29);if(remainder>=6){WfcSettingsList_PositionVisibleRowSprites();return;}
 StartMode6ContextCallback_UnknownRoleZeroInitializedStorage.index-=remainder;WfcSettingsList_RedrawVisibleRows();WfcScrollbar_SetThumbOffset((StartMode6ContextCallback_UnknownRoleZeroInitializedStorage.index*55)/145);WfcScrollbar_EnableTouchInput();WfcSettingsList_ResolveSelectedRowAction();*(int*)(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage.child+56)=0;WfcUtility_RequestTaskRemoval(0,self);
}
