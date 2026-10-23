#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
struct Definition {unsigned unknown0;unsigned id:12,unknown4:20;char unknown8[0x18];unsigned unknown20:20,partyApplied:10,unknown23:2;unsigned monsterApplied:10,partyFallback:10,monsterFallback:10,unknown27:2;char unknown28[10];short category;};
struct ResultFlags {char prefix[0x1c];unsigned char low:7,enabled:1;};
struct CombatActionState {char prefix[0xc];ResultFlags* flags;unsigned char* combat;unsigned appliedCount;};
struct Flags;struct Record;struct Owner;
extern "C" {
void* GameState_GetIndexList(GameState*);
int PartyRoster_ContainsActiveObjectIndex(unsigned char*,unsigned);
void Combat_IncrementCappedEventCounter(unsigned char*,int);
unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
unsigned long long Combat_DispatchSecondaryEffectHandler(CombatActionState*,int,int,Definition*,unsigned char);
unsigned short Combat_SelectCategoryMessageCode(char*,int,int,int);
void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
void Combat_AppendResultMessage(void*,void*,unsigned short);
void Combat_PopulateResultWithCurrentHealthAndMagic(void*,Record*,Owner*,short,void*,void*,unsigned char);
}
// Original: arm9/ov024 @ 0x021DC0B8; symbol: Combat_ResolveDescriptorEffectsAndBuildCategoryResult; size: 0x1E8.
extern "C" void* Combat_ResolveDescriptorEffectsAndBuildCategoryResult(CombatActionState* self,int actor,int targetId,Definition* action,int unused4,int unused5,unsigned char enabled){
GameObject* target=GetCombatantByID((int)self->combat,targetId);if(!target)return 0;
unsigned long long outcome=0;unsigned short message=0;bool sourceEnabled=self->flags->enabled!=0;int applied=0;
if(enabled){outcome=Combat_DispatchSecondaryEffectHandler(self,actor,targetId,action,1);if(outcome!=0){message=Combat_SelectMessageForPartyOrMonster(targetId,action->partyApplied,action->monsterApplied);unsigned char* roster=(unsigned char*)GameState_GetIndexList(GameState::GetInstance());if(sourceEnabled&&PartyRoster_ContainsActiveObjectIndex(roster,actor)&&action->id==0xa9)Combat_IncrementCappedEventCounter(self->combat,5);++self->appliedCount;applied=1;}}
if(!applied){message=Combat_SelectCategoryMessageCode((char*)self,targetId,action->category,0);if(!message)message=Combat_SelectMessageForPartyOrMonster(targetId,action->partyFallback,action->monsterFallback);}
if(action->id==0x20f)message=0;void* result=Combat_ClearCurrentResultNodeSlot(self->combat);if(!result)return 0;
Combat_SuppressMessageForExceptionalOutcome(self,(Flags*)self->flags,&message);Combat_AppendResultMessage(self->combat,result,message);Combat_PopulateResultWithCurrentHealthAndMagic(self->combat,(Record*)result,(Owner*)target,0,(void*)(unsigned)outcome,(void*)(unsigned)(outcome>>32),self->flags->enabled!=0);return result;
}
