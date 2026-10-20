#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_ReadPResources(void*);
extern "C" char* GameState_GetFieldOrbitCamera(void*);
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" void UpdateEmbeddedDisplayContextWhenEnabled(unsigned char*,int);
extern "C" int Selection_ReadEnabledIndexFromEmbeddedControl(unsigned char*);
extern "C" void TextLayout_ShowPanelImmediately(unsigned char*);
extern "C" bool TextLayout_IsPanelVisible(unsigned char*);
extern "C" int Object_ReadSelectionResultWhenGridReady(unsigned char*);
extern "C" int Camera_IsOrbitInputEnabled(void*);
extern "C" int FieldInput_IsPostCommandCooldownExpired(void*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
class Screen {};
typedef void (Screen::*Handler)(int);
// Original data: arm9/main @ 0x20f08b8; symbol: data_020f08b8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex bc78060200000000d479060200000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Handler GraphicsUpdateReadySelectionAndDispatch_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020676E0; symbol: func_020676e0; size: 0x1DC.
extern "C" void Graphics_UpdateReadySelectionAndDispatch(char* self,int elapsed) {
 if(*(int*)(self+0x9a0)!=6) return;
 if(!*(unsigned char*)(self+0x19ba)) return;
 UpdateEmbeddedDisplayContextWhenEnabled((unsigned char*)self+0x90,elapsed);
 if(!TextLayout_IsPanelVisible((unsigned char*)self+0x90)) {
 TextLayout_ShowPanelImmediately((unsigned char*)self+0x90);
 return;
 }
 int ready=1;
 int confirm=Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x401)!=0;
 int cancel=Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)!=0;
 char* game;
 char* resources;
 int mode=*(int*)(self+0x98c);
 game=_ZN9GameState11GetInstanceEv();
 char* object=GameState_GetFieldOrbitCamera(game);
 resources=GameState_ReadPResources(game);
 if(mode!=1 && *(unsigned char*)(self+0x19d2)) {
 if(object) {
 if((*(unsigned char*)(object+0x244)&2) || !Camera_IsOrbitInputEnabled(object)) confirm=(confirm | Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200))!=0;
 } else confirm=(confirm | Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200))!=0;
 }
 int special=0;
 if(*(unsigned char*)(game+0x5cc8)==2) special=1;
 if(!special && resources) {
 if(!FieldInput_IsPostCommandCooldownExpired(resources)) ready=cancel=confirm=0;
 }
 if(!special && *(char**)(self+0x8c)) {
 if(*(unsigned short*)(*(char**)(self+0x8c)+0xda)&0x20) ready=cancel=confirm=0;
 }
 int result=-1;
 if(ready) result=Object_ReadSelectionResultWhenGridReady((unsigned char*)self+0x90);
 if(confirm) result=Selection_ReadEnabledIndexFromEmbeddedControl((unsigned char*)self+0x90);
 else if(cancel) result=-2;
 *(int*)(self+0x954)=result;
 (((Screen*)self)->*GraphicsUpdateReadySelectionAndDispatch_UnknownRoleProcedureReferenceRecords[mode])(result);
}
