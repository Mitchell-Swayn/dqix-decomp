// Original: arm9/main @ 0x0208A370; symbol: BattleAI_SelectActionByWeightProfile; size: 0x13C.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Util/Random.h>
ARM
extern "C" {
GameObject* GameState_FindIndexedObjectWithFlag400(GameState*,int);
int BattleAI_TryActionSlotAndBuildTargets(void*,unsigned char,int,void*,int);
int Combat_SelectAutomaticActionTargets(void*,int,unsigned short,short*);
extern const unsigned char BattleAISelectActionByWeightProfile_UnknownRoleInitializedBytes[];
}
extern "C" unsigned short BattleAI_SelectActionByWeightProfile(void* context,int profile,int member,void* output,int targetAddress){
unsigned char* self=(unsigned char*)context;int* count=(int*)output;const unsigned char* weights;int selected;unsigned char* actions;unsigned char* object=(unsigned char*)GameState_FindIndexedObjectWithFlag400(GameState::GetInstance(),member);actions=*(unsigned char**)(object+0x148);weights=BattleAISelectActionByWeightProfile_UnknownRoleInitializedBytes+profile*6;
int ticket=NextRandomMax(*(Random**)self,256)+1;selected=0;for(;selected<6;++selected){int weight=weights[selected];if(weight>=ticket)break;ticket-=weight;}if(selected>=6)selected=5;
if(BattleAI_TryActionSlotAndBuildTargets(self,(unsigned char)selected,member,count,targetAddress))return *(unsigned short*)(actions+0x18+selected*2);
int slot=selected;while(--slot>=0){if(BattleAI_TryActionSlotAndBuildTargets(self,(unsigned char)slot,member,count,targetAddress))return *(unsigned short*)(actions+0x18+slot*2);}
while(++selected<6){if(BattleAI_TryActionSlotAndBuildTargets(self,(unsigned char)selected,member,count,targetAddress))return *(unsigned short*)(actions+0x18+selected*2);}
*count=0;*count=Combat_SelectAutomaticActionTargets(*(void**)self,member,2,(short*)targetAddress);return 2;
}
