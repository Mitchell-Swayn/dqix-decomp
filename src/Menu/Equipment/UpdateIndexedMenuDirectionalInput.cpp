#include <globaldefs.h>
ARM
struct GameResources;struct GameState;struct Grid;
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);void Grid_ChangeDisplayModeAndTransitionFlags(unsigned char*,unsigned char);GameResources* GameResources_GetInstance();unsigned Field_GetSharedSubscreenInstance(void*);void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);void* _ZN9GameState11GetInstanceEv();unsigned _ZNK9GameState12GetTickCountEv(GameState*);int Grid_UpdateDirectionalSelection(Grid*,int);int Grid_ComputeSelectedLinearIndex(int*);void HandleHeaderCursorCancelAndSelection(unsigned char*);void EquipmentMenu_HandleEquippedItemInput(unsigned char*);void EquipmentMenu_HandleInventoryItemInput(unsigned char*);extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];extern char Main_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov005 @ 0x0215730C; symbol: func_ov005_0215730c; size: 0x120.
// Handles cancel/alternate menu input, updates directional grid selection and dispatches by display mode.
extern "C" void UpdateIndexedMenuDirectionalInput(unsigned char* p){
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)){
  Grid_ChangeDisplayModeAndTransitionFlags(p,1);char* res=(char*)GameResources_GetInstance();char* obj=(char*)Field_GetSharedSubscreenInstance(*(void**)(res+0x3708));*(unsigned short*)(obj+0x634)|=0x800;SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,27,0);return;
 }
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,4)){
  if(p[0x3db8]==2 || p[0x3db8]==3 || p[0x3db8]==4){Grid_ChangeDisplayModeAndTransitionFlags(p,7);*(unsigned*)(p+0x3dcc)|=0x80000;return;}
 }
 unsigned ticks=_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv());if(!ticks)ticks=1;
 Grid_UpdateDirectionalSelection((Grid*)(p+0x19f4),ticks);Grid_ComputeSelectedLinearIndex((int*)(p+0x19f4));
 switch(p[0x3db8]){case 2:HandleHeaderCursorCancelAndSelection(p);return;case 3:EquipmentMenu_HandleEquippedItemInput(p);return;case 4:EquipmentMenu_HandleInventoryItemInput(p);return;}
}
