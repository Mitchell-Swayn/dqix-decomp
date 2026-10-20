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
int EquipmentMenu_AdvanceInventoryPage(char*,int);
void EquipmentMenu_RefreshInventoryPage(unsigned char*);
}
#define H(o) (*(short*)(p+(o)))
#define B(o) (*(unsigned char*)(p+(o)))
#define S(o) (*(signed char*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
struct PageFlags { unsigned low:17; unsigned previous:1; unsigned next:1; unsigned high:13; };
// Original: arm9/ov005 @ 0x0215771C; symbol: func_ov005_0215771c; size: 0x210.
// Handles row-grid input, wrapping page edges and confirming populated rows.
extern "C" void EquipmentMenu_HandleInventoryItemInput(unsigned char* p){
 int index=S(0x3dbb)-8;
 if(index<4 && Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x40)){
  Grid_ChangeDisplayModeAndTransitionFlags(p,3);
  B(0x3dbb)=B(0x3dbc);
  int selected=Grid_ComputeSelectedLinearIndex((int*)(p+0x19f4));
  EquipmentMenu_SetCursorForDisplayMode((char*)p,B(0x3db8),(unsigned char)selected);
  return;
 }
 int column=index%4;
 int changed=0;
 if(column==0){
  if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x20)){
   changed=EquipmentMenu_AdvanceInventoryPage((char*)p,-1);
   W(0x3dcc)|=0x20000;
  }
 }else if(column==3){
  if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x10)){
   changed=EquipmentMenu_AdvanceInventoryPage((char*)p,1);
   W(0x3dcc)|=0x40000;
  }
 }
 if(changed)EquipmentMenu_RefreshInventoryPage(p);
 else {((PageFlags*)(p+0x3dcc))->previous=0;((PageFlags*)(p+0x3dcc))->next=0;}
 int selected=Grid_ComputeSelectedLinearIndex((int*)(p+0x19f4))+8;
 if(selected!=S(0x3dbb)){
  B(0x3dbb)=selected;
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,2,0);
  EquipmentMenu_SetCursorForDisplayMode((char*)p,B(0x3db8),B(0x3dbb));
 }else if(selected==S(0x3dbb)){
  _ZN9GameState11GetInstanceEv();
  char* resources=(char*)GameResources_GetInstance();
  char* object=(char*)Field_GetSharedSubscreenInstance(*(void**)(resources+0x3708));
  if(!GameState_IsObjectAssociatedWithProtagonistWhenConnected(p,*(int*)(object+0x4fc)))return;
  if(!EquipmentMenu_IsConfirmPressed(p))return;
  if(*(short*)(p+S(0x3dbb)*28+0x2d90)<0)return;
  Grid_ChangeDisplayModeAndTransitionFlags(p,5);
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  *(unsigned short*)(object+0x634)&=~1;
  *(unsigned short*)(object+0x634)&=~0x80;
 }
}
