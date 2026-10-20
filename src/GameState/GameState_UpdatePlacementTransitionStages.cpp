#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* TextContext_GetSharedInstance();
char* GameResources_GetInstance();
char* GameState_GetIndexList(void*);
unsigned char* NavigationMessage_GetGlobalInstance();
unsigned GameState_CountMatchingFourPlacementBytes(int,unsigned);
void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
int LinkedList_ContainsTag(void*,int);
void* FieldBattle_GetEncounterRequest(void*);
int PartySelection_CountEnabledMembers(void*);
unsigned TextWindow_GetChoiceResult(void*);
void GameState_EmitObjectPositionAndZoneRequest(char*,unsigned);
unsigned _ZNK9GameState12GetTickCountEv(void*);
int NavigationMessage_EnqueueWithFormattedMemberName(unsigned char*,short,int,signed char);
signed char GameState_FindByteKeyInFourSlots(void*,int);
}
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define SB(p,o) (*(signed char*)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define W(p,o) (*(unsigned*)((p)+(o)))
// Original: arm9/main @ 0x020930D0; symbol: func_020930d0; size: 0x358.
extern "C" void GameState_UpdatePlacementTransitionStages(char* p){
char* state=(char*)_ZN9GameState11GetInstanceEv();char* owner=(char*)TextContext_GetSharedInstance();char* resources=GameResources_GetInstance();unsigned display;unsigned char count,total;int i;char* indices;void* list=(void*)W(resources,0x36fc);indices=GameState_GetIndexList(state);display=(unsigned)NavigationMessage_GetGlobalInstance();
if(B(p,0x35)==0){H(p,0x30)=0;B(p,0x35)++;return;}
else if(B(p,0x35)==1){
 display=GameState_CountMatchingFourPlacementBytes((int)p,1);count=0;
 for(i=0;i<4;i++)if(_ZN9GameState21GetPartyMemberByIndexEi(state,i))count++;
 count-=B(indices,0xf7c);total=B(indices,0xf7c)+count;
 int ready=0;if(count==0)ready=1;
 else if(display==0){unsigned char enabled=0;for(int i=0;i<4;i++)if(B(state,0x7f7a)&(1<<i))enabled++;if(enabled>=count)ready=1;}
 if(ready){if(H(p,0x32)!=0)return;TextWindow_ResetGlyphBuffersAndFrameContexts(owner);short next;int zero=GameState_CountMatchingFourPlacementBytes((int)p,0);int five=GameState_CountMatchingFourPlacementBytes((int)p,5);
 if(zero==4&&count==0)next=8;
 else{next=6;if(LinkedList_ContainsTag(list,10)){if(total==PartySelection_CountEnabledMembers(FieldBattle_GetEncounterRequest((void*)W(resources,0x3718)))&&zero+five==4)B(p,0x3b)=1;}}
 H(p,0x30)=next;B(p,0x35)=3;return;
 }else{if(W(owner,0x998))return;H(p,0x30)=5;B(p,0x35)++;return;}
}
else if(B(p,0x35)==2){if(W(owner,0x9a0))return;unsigned result=TextWindow_GetChoiceResult(owner);if(result==0){B(p,0x35)=3;GameState_EmitObjectPositionAndZoneRequest(p,0);return;}else if(result==1){B(p,0x35)=1;H(p,0x32)=0;}return;}
else if(B(p,0x35)==3){
 if(SB(p,0x39)<10){SB(p,0x39)+=_ZNK9GameState12GetTickCountEv(state);return;}
 if(B(p,0x3b)){B(p,0x3b)=0;NavigationMessage_EnqueueWithFormattedMemberName((unsigned char*)display,0x4e24,-1,0);}
 if(GameState_CountMatchingFourPlacementBytes((int)p,2)>1)NavigationMessage_EnqueueWithFormattedMemberName((unsigned char*)display,0x4e22,-1,GameState_FindByteKeyInFourSlots(p,2));
 else if(GameState_CountMatchingFourPlacementBytes((int)p,2)==1)NavigationMessage_EnqueueWithFormattedMemberName((unsigned char*)display,0x4e21,-1,GameState_FindByteKeyInFourSlots(p,2));
 for(unsigned char i=0;i<4;i++){if(B(state+i,0x7f76)==4)NavigationMessage_EnqueueWithFormattedMemberName((unsigned char*)display,0x2711,-1,(signed char)i);}
 B(p,0x35)++;return;
}
else if(B(p,0x35)==4){if(!W(owner,0x998)){B(p,0x34)=4;B(p,0x35)=0;}}
}
