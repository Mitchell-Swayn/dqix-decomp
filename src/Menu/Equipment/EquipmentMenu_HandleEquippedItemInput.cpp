#include <globaldefs.h>
ARM
struct GameResources; struct GridSelection; struct Object;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
GameResources* GameResources_GetInstance();
unsigned Field_GetSharedSubscreenInstance(void*);
int GameState_IsObjectAssociatedWithProtagonistWhenConnected(void*,int);
void Grid_ChangeDisplayModeAndTransitionFlags(unsigned char*,unsigned char);
void EquipmentMenu_SetCursorForDisplayMode(char*,unsigned,int);
void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
int Grid_ComputeSelectedLinearIndex(int*);
int EquipmentMenu_IsConfirmPressed(void*);
int SwitchIndexedStateAndSavePreviousPhase(Object*,int,int);
void EquipmentMenu_RefreshInventoryPage(unsigned char*);
}
#define H(o) (*(short*)(p+(o)))
#define B(o) (*(unsigned char*)(p+(o)))
#define S(o) (*(signed char*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x0215751C; symbol: func_ov005_0215751c; size: 0x200.
// Handles header-grid navigation, confirmation, cancellation and empty-cell fallback.
extern "C" void EquipmentMenu_HandleEquippedItemInput(unsigned char* p){
 bool back=false;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x40))back=true;
 if(back){
  Grid_ChangeDisplayModeAndTransitionFlags(p,2);
  int index=Grid_ComputeSelectedLinearIndex((int*)(p+0x19f4));
  EquipmentMenu_SetCursorForDisplayMode((char*)p,B(0x3db8),(unsigned char)index);
  return;
 }
 bool cancel=false;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x80))cancel=true;
 if(!back){
  _ZN9GameState11GetInstanceEv();
  char* resources=(char*)GameResources_GetInstance();
  char* object=(char*)Field_GetSharedSubscreenInstance(*(void**)(resources+0x3708));
  if(!GameState_IsObjectAssociatedWithProtagonistWhenConnected(p,*(int*)(object+0x4fc)))return;
  if(EquipmentMenu_IsConfirmPressed(p)){
   if(*(short*)(p+B(0x3dbc)*28+0x2d90)<0)cancel=true;
   else{
    Grid_ChangeDisplayModeAndTransitionFlags(p,5);
    SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
    *(unsigned short*)(object+0x634)&=~1;
    *(unsigned short*)(object+0x634)&=~0x80;
   }
  }
 }
 if(cancel){
  Grid_ChangeDisplayModeAndTransitionFlags(p,4);
  B(0x3dbb)=8;
  Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x19f4),S(0x3dbb)-8);
  if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x80))SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,2,0);
  else if(EquipmentMenu_IsConfirmPressed(p))SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  EquipmentMenu_SetCursorForDisplayMode((char*)p,B(0x3db8),B(0x3dbb));
 }else{
  int index=Grid_ComputeSelectedLinearIndex((int*)(p+0x19f4));
  if(SwitchIndexedStateAndSavePreviousPhase((Object*)p,(unsigned char)index,0)){
   B(0x3dbb)=B(0x3dbc);
   W(0x3dcc)|=0x100;
   EquipmentMenu_RefreshInventoryPage(p);
  }
 }
}
