#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Util/Random.h>
#include <std_library_functions.h>
ARM
struct Definition {unsigned prefix[2];unsigned unknown8:8,side:2,rest8:22;unsigned unknownc[2];unsigned unknown14:28,mode:4;unsigned unknown18:5,kind:7,rest18:20;unsigned unknown1c:14,repeat:5,rest1c:13;};
struct Choices{short ids[8];};
struct Object;struct RetargetFlags {unsigned first:1,second:1,rest:30;};
extern "C" {
void* ActionData_GetGlobalTables();
void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
bool Combat_HasPartyOnlyRetargetingStatus(Object*);
int Combat_SelectPartyOnlyTargetsByActionType(void*,int,int,short*);
int GameObject_GetCombatTrackingRecord(int);
int CharacterState_GetLearnedSkillMask(unsigned char*,int);
void Combat_ReplaceDisabledMonsterTargetFromGroup(void*,int,int*);
void Util_ReplaceInactiveIndexWithRandomActiveRecord(char*,int*);
void GameState_UpdateSelectionIfEligible(void*,unsigned,int*);
int Combat_CollectMonsterTargetsInGroup(unsigned char*,short*,int,int,int);
int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
int Combat_CollectEligiblePartyIds(void*,short*,int,int);
int Util_GetRandomizedTableByte(Random*,int);
extern const short Combat_ResolvePartyCommandTargets_CombatantSelectionInitialIds[8];
}
// Original: arm9/ov000 @ 0x021540FC; symbol: Combat_ResolvePartyCommandTargets; size: 0x2F8.
extern "C" int Combat_ResolvePartyCommandTargets(void* context,int actor,int actionId,short* output){
unsigned char* self=(unsigned char*)context;GameState* game=GameState::GetInstance();Definition* action=(Definition*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(),(short)actionId);if(!action)return 0;GameObject* object=GameState_GetObjectWithFlag100(game,actor);if(!object)return 0;if(Combat_HasPartyOnlyRetargetingStatus((Object*)object))return Combat_SelectPartyOnlyTargetsByActionType(self,actor,actionId,output);
unsigned char* tracking=(unsigned char*)GameObject_GetCombatTrackingRecord((int)object);if(!tracking)return 0;int count;unsigned side=action->side;unsigned mode=action->mode;count=0;
if(mode==6)mode=CharacterState_GetLearnedSkillMask(*(unsigned char**)((char*)object+0x150),0xe6)?3:2;
if(mode==5){unsigned address=*(unsigned*)((char*)object+0x150)+0x2f4;if(!address)return 0;RetargetFlags* flags=(RetargetFlags*)address;if(flags->second)mode=3;else if(flags->first)mode=4;else mode=2;}
if(mode==1){output[count++]=actor;}else if(side==1){if(mode==2){int target=tracking[2];Combat_ReplaceDisabledMonsterTargetFromGroup(self,tracking[3],&target);output[count++]=target;}else if(mode==4){int group=tracking[3];Util_ReplaceInactiveIndexWithRandomActiveRecord((char*)self,&group);count=Combat_CollectMonsterTargetsInGroup(self,output,8,group,1);}else if(mode==3)count=Combat_CollectGroupIndicesByDescriptorFlags((char*)self,output,8,1);
}else if(side==2){if(mode==2||mode-7<=1){int target=tracking[2];if(action->kind!=0x12)GameState_UpdateSelectionIfEligible(self,actor,&target);output[count++]=target;}else if(mode-3<=1){if(action->kind!=0x21)count=Combat_CollectEligiblePartyIds(self,output,8,1);else count=Combat_CollectEligiblePartyIds(self,output,8,0);}}
Choices choices=*(const Choices*)Combat_ResolvePartyCommandTargets_CombatantSelectionInitialIds;short* sampled=choices.ids;short* sampledBuffer=sampled;int repeats=Util_GetRandomizedTableByte((Random*)self,(signed char)action->repeat);if(repeats>0){for(int i=0;i<repeats;++i)sampledBuffer[i]=output[NextRandomMax((Random*)self,count)];memset(output,0,count*2);memcpy(output,choices.ids,repeats*2);count=repeats;}return count;
}
