#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Util/Random.h>
ARM
struct Choices{short ids[8];};
extern "C" {
void* ActionData_GetGlobalTables();
void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern const short Combat_SelectPartyOnlyTargetsByActionType_CombatantSelectionInitialIds[8];
}
// Original: arm9/ov000 @ 0x02153F98; symbol: Combat_SelectPartyOnlyTargetsByActionType; size: 0x130.
extern "C" int Combat_SelectPartyOnlyTargetsByActionType(void* context,int actor,int actionId,short* output){
GameState* game=GameState::GetInstance();char* definition=(char*)ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(),(short)actionId);if(!definition)return 0;
if(!GameState_GetObjectWithFlag100(game,actor))return 0;
unsigned mode=*(unsigned*)(definition+0x14)>>28;int count=Combat_CollectEligiblePartyIds(context,output,8,1);
if(mode==2){output[0]=output[NextRandomMax((Random*)context,count)];count=1;
}else if(mode==8){Choices choices=*(const Choices*)Combat_SelectPartyOnlyTargetsByActionType_CombatantSelectionInitialIds;short* selected=choices.ids;short kept=0;
for(int i=0;i<count;++i){short id=output[i];if(actor!=id)selected[kept++]=id;}
output[0]=selected[NextRandomMax((Random*)context,kept)];count=1;
}else{output[0]=actor;count=1;}
return count;
}
