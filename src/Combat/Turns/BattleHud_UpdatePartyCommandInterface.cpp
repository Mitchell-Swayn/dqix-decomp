#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct State {unsigned char pad[28];unsigned char first:4;unsigned char second:4;};
struct SessionFlags {unsigned reserved:1;signed suppressPalette:1;unsigned rest:30;};
struct Entry {char pad[0x4c];unsigned key;char tail[0x3f8];};
extern "C" {
int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
void* Network_GetConnectionManager();bool Network_IsSessionActive(int*);
int GameState_ReadProtagonistObjectIndex(void*);
void Graphics_LoadPartyPalettePreset(int,int);
int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);
Entry* BattleMenu_GetSelectedPartyCommandRecord(char*);
void GameState_InvalidateRecordWordForEligibleLastEntry(unsigned char*);
void GameState_UpdateFourRecordsFromObjects(void*);
void BattleMenu_ProcessPendingCommandMenuRefresh(char*);
void BattleMenu_AdjustPartyPanelForCommandTransition(char*);
void BattleMenu_AdvancePartyPanelFlashAnimations(unsigned char*,int);
void BattleMenu_AdvancePartyPalettePulses(unsigned char*,int);
char* BattleMenu_FindPartyCommandRecord(char*,int);
void BattleMenu_SynchronizeEnemyGroupAndMemberSelection(char*,int,int,char*);
void BattleMenu_UpdateGlobalCommandMenu(char*,int,int);
void BattleMenu_AdvanceHeaderSlideAnimation(void*);
void BattleMenu_RefreshExistingPanel(char*,char*,unsigned,int,int,unsigned char);
int BattleMenu_IsPartyCommandInputPending(char*,int);
void GameState_ResetFlaggedEntriesOutsideSelectedOwner(unsigned char*);
void BattleMenu_UpdateSelectedPartyCommandWindows(char*,int,int);
void BattleMenu_RefreshSelectedPartyPanelExpansion(unsigned char*);
void BattleMenu_UpdateTransitionForSelectedPartyCommand(char*,void*);
void BattleMenu_StartTransitionWhenAllPartyCommandsAreReady(unsigned char*);
void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
// Original data: arm9/ov000 @ 0x02183FF0 and 0x02184288; command-menu shared state.
extern unsigned BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[];
extern unsigned BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
}
#define W(p,o) (*(int*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define S(p,o) (*(signed char*)((p)+(o)))
// Original: arm9/ov000 @ 0x021735D0; symbol: func_ov000_021735d0; size: 0x384.
// Advances party command canvases, selection, network transitions and selected command panels.
extern "C" void BattleHud_UpdatePartyCommandInterface(char* self,int step){
 W(self,0x94c)=step;
 Graphics_InvokeTwoIndexTransferCallback((State*)(self+0x8a4),(void*)(0u-(unsigned)W(self,0x940)),(void*)(0u-(unsigned)W(self,0x944)));
 Graphics_InvokeTwoIndexTransferCallback((State*)(self+0x8c4),0,0);
 Graphics_InvokeTwoIndexTransferCallback((State*)(self+0x8e4),0,0);
 GameState* game=GameState::GetInstance();Network_GetConnectionManager();
 if(((SessionFlags*)((char*)game+0x5ccc))->suppressPalette)Graphics_LoadPartyPalettePreset(0,-1);
 if(!step)step=1;
 int update=1;char* selected=(char*)BattleMenu_GetSelectedPartyCommandRecord(self);
 if(selected&&S(selected+S(selected,0x18),0x10)==100)update=0;
 if(update){
  GameState_InvalidateRecordWordForEligibleLastEntry((unsigned char*)self);
  selected=(char*)BattleMenu_GetSelectedPartyCommandRecord(self);
  int clear=0;
  unsigned char first=B(self,0x21c),second=B(self,0x21d);
  if(selected&&!(H(self,0x1d72)&0x200)&&((signed char*)(self+0x1d60))[S(self,0x1d68)]!=6&&((signed char*)(self+0x1d60))[S(self,0x1d68)]!=7&&!(B(selected,0x24)&1))clear=1;
  if(clear){B(self,0x21c)=0;B(self,0x21d)=0;}
  W(self,0x118)=Window_UpdateCanvasesAndSelection((unsigned char*)self+0x188,step);
  if(clear){if(first)B(self,0x21c)=1;if(second)B(self,0x21d)=1;}
 }
 GameState_UpdateFourRecordsFromObjects(self);BattleMenu_ProcessPendingCommandMenuRefresh(self);
 BattleMenu_AdjustPartyPanelForCommandTransition(self);
 BattleMenu_AdvancePartyPanelFlashAnimations((unsigned char*)self,step);BattleMenu_AdvancePartyPalettePulses((unsigned char*)self,step);
 if(H(self,0x1d72)&0x200){
  char* actor=BattleMenu_FindPartyCommandRecord(self,(signed char)GameState_ReadProtagonistObjectIndex(GameState::GetInstance()));
  BattleMenu_SynchronizeEnemyGroupAndMemberSelection(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[0],BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1],actor);
  BattleMenu_UpdateGlobalCommandMenu(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[0],BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
  BattleMenu_AdvanceHeaderSlideAnimation(self);
  int complete=S(self+S(self,0x1d68),0x1d60)==100;
  if(complete&Network_IsSessionActive((int*)Network_GetConnectionManager())){
   if(B(self,0x1d81)==1){
    for(int i=0;i<2;++i)BattleMenu_RefreshExistingPanel(self,actor,23,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[0],BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1],0);
    B(self,0x1d81)=2;
   }else if(B(self,0x1d81)==0)B(self,0x1d81)=1;
  }
 }
 if(H(self,0x1d72)&0x400)BattleMenu_AdvanceHeaderSlideAnimation(self);
 if(!BattleMenu_IsPartyCommandInputPending(self,-1)){
  if(B(self,0x1d70)&&W(self,0x90c)>=0){void* loader=_ZN16BackgroundLoader11GetInstanceEv();_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0x90c));W(self,0x90c)=-1;}
 }else{
  GameState_ResetFlaggedEntriesOutsideSelectedOwner((unsigned char*)self);
  if(!(H(self,0x1d72)&0x200)){
   if(S(self+S(self,0x1d68),0x1d60)==13){
    if(!(H(self,0x1d72)&4))BattleMenu_UpdateSelectedPartyCommandWindows(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[0],BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
   }else BattleMenu_UpdateGlobalCommandMenu(self,BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[0],BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
   BattleMenu_RefreshSelectedPartyPanelExpansion((unsigned char*)self);
   BattleMenu_UpdateTransitionForSelectedPartyCommand(self,(void*)step);
   BattleMenu_StartTransitionWhenAllPartyCommandsAreReady((unsigned char*)self);
  }
 }
}
