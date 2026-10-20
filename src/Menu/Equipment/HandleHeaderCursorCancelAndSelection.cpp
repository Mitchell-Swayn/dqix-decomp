#include <globaldefs.h>
ARM
struct Object;
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
extern "C" {int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);int Grid_ComputeSelectedLinearIndex(int*);void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);void EquipmentMenu_RefreshInventoryPage(unsigned char*);int EquipmentMenu_IsConfirmPressed(void*);void Grid_ChangeDisplayModeAndTransitionFlags(unsigned char*,unsigned char);void EquipmentMenu_SetCursorForDisplayMode(char*,unsigned,int);int SwitchIndexedStateAndSavePreviousPhase(Object*,int,int);extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];extern char Main_UnknownRoleZeroInitializedStorage[];}
#define B(o) (*(unsigned char*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x0215742C; symbol: func_ov005_0215742c; size: 0xF0.
// Handles header cursor cancellation and updates selected header index with row refresh.
extern "C" void HandleHeaderCursorCancelAndSelection(unsigned char* p){
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,128)){
  Grid_ChangeDisplayModeAndTransitionFlags(p,3);B(0x3dbb)=B(0x3dbc);
  if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,128))SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,2,0);
  else if(EquipmentMenu_IsConfirmPressed(p))SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  EquipmentMenu_SetCursorForDisplayMode((char*)p,B(0x3db8),B(0x3dbb));return;
 }
 int index=Grid_ComputeSelectedLinearIndex((int*)(p+0x19f4));
 if(SwitchIndexedStateAndSavePreviousPhase((Object*)p,(unsigned char)index,0)){
  W(0x3dcc)|=0x100;EquipmentMenu_SetCursorForDisplayMode((char*)p,B(0x3db8),B(0x3dbc));EquipmentMenu_RefreshInventoryPage(p);
 }
}
