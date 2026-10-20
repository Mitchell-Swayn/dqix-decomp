#include <globaldefs.h>
ARM
#pragma opt_propagation off
#define W(o) (*(int*)(self+(o)))
#define H(o) (*(short*)(self+(o)))
#define B(o) (*(unsigned char*)(self+(o)))
#define P(o) (*(char**)(self+(o)))
extern "C" char *TextContext_GetSharedInstance();
extern "C" char *_ZN9GameState11GetInstanceEv();
extern "C" char *GameState_GetObjectWithFlag100(void*,int);
extern "C" char *GameState_GetFieldOrbitCamera(void*);
extern "C" int Input_IsKeyMaskNewlyPressed(void*,unsigned);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void Grid_SelectIndexAndComputePageCoordinates(void*,int);
extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(void*,int);
extern "C" void Window_PopCanvasesAndResetSelection(void*,int);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(void*,unsigned,unsigned);
extern "C" void Window_SetCanvasDisplayAttribute(void*,int,int);
extern "C" void Window_SelectCanvasById(void*,unsigned);
extern "C" void Window_SetCanvasEnabled(void*,int,int);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,void*);
extern "C" int Camera_IsOrbitInputEnabled(void*);
extern "C" int ReadAvailableMemberValueRelativeToProtagonist(int,int,int,int);
extern "C" char *ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" char *Window_GetRenderState(void*);
extern "C" void Window_HideAndResetOptionSelection(void*);
extern "C" void Window_CreateOptionLayoutAndResetSelection(void*,int);
extern "C" int Window_GetCurrentOption(void*);
extern "C" int Window_GetConfirmedOptionForActiveInput(void*);
extern "C" int Input_TestPressedKeyBitOne(void*);
extern "C" void PartyMenu_PopPanelGroupAndRestoreSelection(void*);
extern "C" int PartyMenu_ApplySelectedItemCommandAndChooseMessage(void*);
extern "C" void PartyMenu_RebuildPanelTextById(void*,int,int);
extern "C" void PartyMenu_BuildActionConfirmationText(void*);
extern "C" void PartyMenu_ConfigureSelectionForCurrentScreen(void*);
extern "C" void PartyMenu_SetMultiplayerItemActionMessage(void*,int);
extern "C" void Field_QueueSessionTransitionTask(int,int,int);
extern "C" void Network_QueueFieldActionResponse(int,int,int,int);
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
extern "C" char Main_UnknownRoleZeroInitializedStorage[],KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov002 @ 0x216d3ac; symbol: data_ov002_0216d3ac.
// Menu condition flag; func_ov002_0215505c initializes and ProcessRecordActionConfirmation sets via byte access.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" unsigned char PartyMenuInitializeController_MenuConditionFlag;
// Original: arm9/ov002 @ 0x0216A300; symbol: ProcessRecordActionConfirmation; size: 0x9f0.
// Drives two-choice record actions, confirming, cancelling and restoring selection state.
extern "C" void PartyMenu_UpdateActionConfirmation(char *self){
 int index;char *owner=TextContext_GetSharedInstance(); owner[0x19ae]=0;
 if(W(0x1bc0)==0){
 W(0x247c)&=~4;
 Window_BindNextCanvasResourceByFormatAndLayer(self+0xec8,0,3);
 PartyMenu_ConfigureSelectionForCurrentScreen(self);PartyMenu_BuildActionConfirmationText(self);
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,5,0);
 Window_SetCanvasEnabled(self+0xec8,0,0x25);
 char *record=Window_GetRenderState(*(void**)(P(0)+16));
 if((unsigned)((unsigned char)record[0x3f]<<31)>>31)Window_CreateOptionLayoutAndResetSelection(P(4),*(int*)(record+0x30));else Window_CreateOptionLayoutAndResetSelection(P(4),-1);
 ++W(0x1bc0);return;
 }
 if(W(0x1bc0)!=1)return;
 Window_SetCanvasEnabled(self+0xec8,0,0x25);W(0x247c)|=4;
 H(0x1c12)=Selection_ReadEnabledIndexFromControl(self+0xec8);
 int special=0;char *member=GameState_GetFieldOrbitCamera(_ZN9GameState11GetInstanceEv());
 if(member&&(((unsigned char)member[0x244]&2)||Camera_IsOrbitInputEnabled(member)==0))special=Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200)!=0;
 H(0x1c12)=Window_GetConfirmedOptionForActiveInput(P(4));
 if(H(0x1c12)>=0||special){
 H(0x1c12)=Window_GetCurrentOption(P(4));Window_HideAndResetOptionSelection(P(4));
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);PartyMenuInitializeController_MenuConditionFlag=0;
 switch(H(0x1c12)){
 case 0:{
 W(0x247c)&=~4;B(0xf80)=W(0x1bb8);
 char *record=ZoneState2754_FindPrimaryRecordByKey(self+0x7ec,H(0x1c22));
 if(record&&*(short*)(record+24)==0x5612){
 PartyMenu_RebuildPanelTextById(self,(unsigned char)W(0x1bb8),1);Window_PopCanvasesAndResetSelection(self+0xec8,0);
 H(0x1c28)=0x7972;H(0x1c2a)=-1;W(0x1bb8)=0x26;W(0x1bbc)=0x2b;W(0x1bc0)=0;B(0x1c2e)=0;Field_QueueSessionTransitionTask(1,1,1);return;}
 if(B(0x1c30)){
 B(0x1c2e)=0;Window_PopCanvasesAndResetSelection(self+0xec8,0);
 switch(B(0x1c79)){case 0:{
 char *m=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),*(signed char*)(self+0x1c21));int available=1;
 if(m&&*(unsigned short*)(*(char**)(m+0x130)+4)==0)available=0;
 if(!ReadAvailableMemberValueRelativeToProtagonist(B(0x1c21),1,0,0))available=0;
 if(available){PartyMenu_SetMultiplayerItemActionMessage(self,1);Network_QueueFieldActionResponse(1,*(signed char*)(self+0x1c20),*(signed char*)(self+0x1c21),H(0x1c22));W(0x1c74)=30;return;}
 PartyMenu_SetMultiplayerItemActionMessage(self,6);return;
 }
 case 3:{PartyMenu_SetMultiplayerItemActionMessage(self,4);Network_QueueFieldActionResponse(2,*(signed char*)(self+0x1c20),*(signed char*)(self+0x1c21),H(0x1c22));}return;default:return;}
 }
 if(B(0x1c32)){B(0x1c32)=0;H(0x1c28)=0x2367;H(0x1c2a)=-1;W(0x1bb8)=0x26;W(0x1bbc)=5;W(0x1bc0)=0;B(0x1c2e)=1;return;}
 H(0x1c28)=PartyMenu_ApplySelectedItemCommandAndChooseMessage(self);H(0x1c2a)=-1;B(0x1c2e)=0;
 if(H(0x1c28)<0){PartyMenu_PopPanelGroupAndRestoreSelection(self);if(H(0x1c0a)>=0){PartyMenu_PopPanelGroupAndRestoreSelection(self);PartyMenu_PopPanelGroupAndRestoreSelection(self);PartyMenu_ConfigureSelectionForCurrentScreen(self);W(0x1bc0)=1;H(0x1c0a)=-1;}}
 else{Window_PopCanvasesAndResetSelection(self+0xec8,0);W(0x1bb8)=0x26;H(0x1c16)=0;H(0x1c18)=0;PartyMenu_ConfigureSelectionForCurrentScreen(self);W(0x1bc8)=1;W(0x1bc0)=0;}
 if(W(0x1bbc)==0x24){Window_SetCanvasDisplayAttribute(self+0xec8,0x15,1);W(0x1bb8)=0x24;W(0x1bc0)=1;}
 if(W(0x1bbc)==11){PartyMenu_RebuildPanelTextById(self,13,0);Window_SetCanvasDisplayAttribute(self+0xec8,11,1);Window_SetCanvasDisplayAttribute(self+0xec8,13,1);}return;
 }
 case 1:
 W(0x247c)&=~4;B(0x1c2e)=0;
 char *record=ZoneState2754_FindPrimaryRecordByKey(self+0x7ec,H(0x1c22));
 if(record&&*(short*)(record+24)==0x5612){
 PartyMenu_RebuildPanelTextById(self,(unsigned char)W(0x1bb8),1);Window_PopCanvasesAndResetSelection(self+0xec8,0);
 H(0x1c28)=0x797e;H(0x1c2a)=-1;W(0x1bb8)=0x26;W(0x1bbc)=5;W(0x1bc0)=0;B(0x1c2e)=0;return;}
 if(B(0x1c30)){
 PartyMenu_RebuildPanelTextById(self,(unsigned char)W(0x1bb8),1);Window_PopCanvasesAndResetSelection(self+0xec8,0);
 switch(B(0x1c79)){case 0:PartyMenu_SetMultiplayerItemActionMessage(self,4);return;case 3:PartyMenu_SetMultiplayerItemActionMessage(self,2);return;default:return;}
 }
 PartyMenu_PopPanelGroupAndRestoreSelection(self);TextWindow_ResetGlyphBuffersAndFrameContexts(owner);
 if(B(0x2521)){W(0x1bb8)=W(0x1bbc);Window_SelectCanvasById(self+0xec8,4);Window_SetCanvasDisplayAttribute(self+0xec8,4,0);PartyMenu_ConfigureSelectionForCurrentScreen(self);B(0x2521)=0;}
 else if((H(0x1bf0)>=0||H(0x1be8)>=0||H(0x1c0a)>=0)&&H(0x1c0a)!=0){char *control=self+0xec8;index=7;H(0x1c0a)=index;Grid_SelectIndexAndInvalidateTouchHistory(control+4,index);Grid_SelectIndexAndComputePageCoordinates(control+0x54,index);PartyMenu_RebuildPanelTextById(self,0x21,0);}
 if(W(0x1bbc)==11){W(0x1bb8)=11;PartyMenu_RebuildPanelTextById(self,11,0);Window_SelectCanvasById(self+0xec8,11);Window_SetCanvasDisplayAttribute(self+0xec8,11,0);Window_SetCanvasDisplayAttribute(self+0xec8,13,1);PartyMenu_ConfigureSelectionForCurrentScreen(self);}
return;default:return;}
 }else{
 if(!P(4)||!Input_TestPressedKeyBitOne(P(4)))goto input_unhandled;
 Window_HideAndResetOptionSelection(P(4));W(0x247c)&=~4;B(0x1c2e)=0;PartyMenuInitializeController_MenuConditionFlag=0;
 }
 char *record=ZoneState2754_FindPrimaryRecordByKey(self+0x7ec,H(0x1c22));
 if(record&&*(short*)(record+24)==0x5612){
 PartyMenu_RebuildPanelTextById(self,(unsigned char)W(0x1bb8),1);Window_PopCanvasesAndResetSelection(self+0xec8,0);
 H(0x1c28)=0x797e;H(0x1c2a)=-1;W(0x1bb8)=0x26;W(0x1bbc)=5;W(0x1bc0)=0;B(0x1c2e)=0;return;}
 if(B(0x1c30)){
 PartyMenu_RebuildPanelTextById(self,(unsigned char)W(0x1bb8),1);Window_PopCanvasesAndResetSelection(self+0xec8,0);
 switch(B(0x1c79)){case 0:PartyMenu_SetMultiplayerItemActionMessage(self,4);return;case 3:PartyMenu_SetMultiplayerItemActionMessage(self,2);return;default:return;}
 }
 PartyMenu_PopPanelGroupAndRestoreSelection(self);TextWindow_ResetGlyphBuffersAndFrameContexts(owner);
 if(B(0x2521)){W(0x1bb8)=W(0x1bbc);Window_SelectCanvasById(self+0xec8,4);Window_SetCanvasDisplayAttribute(self+0xec8,4,0);PartyMenu_ConfigureSelectionForCurrentScreen(self);B(0x2521)=0;}
 else if((H(0x1bf0)>=0||H(0x1be8)>=0||H(0x1c0a)>=0)&&H(0x1c0a)!=0){char *control=self+0xec8;index=7;H(0x1c0a)=index;Grid_SelectIndexAndInvalidateTouchHistory(control+4,index);Grid_SelectIndexAndComputePageCoordinates(control+0x54,index);PartyMenu_RebuildPanelTextById(self,0x21,0);}
 if(W(0x1bbc)==11){W(0x1bb8)=11;PartyMenu_RebuildPanelTextById(self,11,0);Window_SelectCanvasById(self+0xec8,11);Window_SetCanvasDisplayAttribute(self+0xec8,11,0);Window_SetCanvasDisplayAttribute(self+0xec8,13,1);PartyMenu_ConfigureSelectionForCurrentScreen(self);}
return;
input_unhandled:PartyMenuInitializeController_MenuConditionFlag=1;
}
