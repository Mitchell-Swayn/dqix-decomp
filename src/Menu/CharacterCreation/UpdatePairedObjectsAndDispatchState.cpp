struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#pragma always_inline on
struct GameState { char prefix[0x7f71]; unsigned char cycle; };
struct TransitionResource { char unknown[0x568]; short id; };
struct TransitionState { char unknown0[0x7fc]; void* target; char unknown1[0x588]; TransitionResource* resource; char unknown2[0x10]; unsigned flags; };
struct OverlayState {};
typedef void (OverlayState::*StateUpdate)();
struct DispatchTable { StateUpdate entries[13]; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();unsigned _ZNK9GameState12GetTickCountEv(GameState*);
void Camera_UpdateManualInputAndTargetFollowing(void*);
WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
bool TextCanvas_IsReady(int);
typedef unsigned int undefined4;
ARM void Grid_SetLastTouchIndex(int,undefined4);
int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);
void _ZN8Object3D14AdvanceEffectsEv(void*);void CharacterPreview_ConsumeLoadedModelsAndAnimations(void*);
void Input_UpdateObjectYawFromButtonsAndTarget(unsigned char*,unsigned);
void CharacterCreation_SwapReadyAppearancePreview(char*);void CharacterCreation_QueueChangedAppearancePreview(TransitionState*);
void QueueStateBackgroundResourceLoad(unsigned char*);
// Original data: arm9/ov009 @ 0x218ab9c; symbol: data_ov009_0218ab9c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 3456180200000000d063180200000000dc65180200000000c468180200000000d869180200000000f066180200000000ec6a180200000000006c180200000000 ...; full span in module reference.
// Observed span: 104 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
extern DispatchTable UpdatePairedObjectsAndDispatchState_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern StateUpdate ShopUpdateInterface_UnknownRoleInitializedBytes;
}
// Original: arm9/ov009 @ 0x02184A18; symbol: func_ov009_02184a18; size: 0x1A4.
// Advances paired objects and records, then dispatches the signed state through a member-function table.
extern "C" bool UpdatePairedObjectsAndDispatchState(unsigned char* p) {
 unsigned ticks=_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv());
 if(!ticks)ticks=1;
 if(*(signed char*)(p+0xc58))Camera_UpdateManualInputAndTargetFollowing(p+0x924);
 if(*(signed char*)(p+0xc58)==9 && p[0xc59]==2) {
  unsigned record=(unsigned)Window_GetSelectedTextCanvas((WindowCanvasOwner*)((char*)p+0x2b4));
  if(record && TextCanvas_IsReady(record) && !(*(unsigned char*)(record+0xc5)&2)) Grid_SetLastTouchIndex((int)(p+0x2b8),-1);
 }
 Window_UpdateCanvasesAndSelection(p+0x1f8,ticks);
 p[0xd85]=Window_UpdateCanvasesAndSelection(p+0x2b4,ticks);
 if(*(unsigned*)(p+0xd9c)&0x200) {
  _ZN8Object3D14AdvanceEffectsEv(p+0x878);_ZN8Object3D14AdvanceEffectsEv(p+0xcd8);
 }
 if(*(void**)(p+0x7f8))CharacterPreview_ConsumeLoadedModelsAndAnimations(*(void**)(p+0x7f8));
 if(*(void**)(p+0x7fc))CharacterPreview_ConsumeLoadedModelsAndAnimations(*(void**)(p+0x7fc));
 Input_UpdateObjectYawFromButtonsAndTarget(p,ticks);
 CharacterCreation_SwapReadyAppearancePreview((char*)p);
 CharacterCreation_QueueChangedAppearancePreview((TransitionState*)p);
 DispatchTable table=UpdatePairedObjectsAndDispatchState_UnknownRoleProcedureReferenceRecords;
 table.entries[12]=ShopUpdateInterface_UnknownRoleInitializedBytes;
 int state=*(signed char*)(p+0xc58);
 if(!table.entries[state])return false;
 (((OverlayState*)p)->*table.entries[state])();
 QueueStateBackgroundResourceLoad(p);
 return *(signed char*)(p+0xc58)==12;
}
