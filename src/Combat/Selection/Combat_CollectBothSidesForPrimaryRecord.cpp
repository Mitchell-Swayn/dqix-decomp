#include <globaldefs.h>
ARM
struct CombatSelectionContext;struct CombatSelectionAction;
extern "C" {
void* Combat_GetCommandActorSnapshot(void*,int);
int Combat_CollectEligiblePartyIds(void*,short*,int,int);
int Combat_CollectPresentEnemyIndices(void*,short*,int,int);
}
// Original: arm9/ov000 @ 0x02181ABC; symbol: Combat_CollectBothSidesForPrimaryRecord; size: 0x90.
extern "C" int Combat_CollectBothSidesForPrimaryRecord(CombatSelectionContext* context,CombatSelectionAction* action,int* output){
if(!Combat_GetCommandActorSnapshot(action,0))return 0;
short ids[16];int count=0;
count+=Combat_CollectEligiblePartyIds(context,ids,16,count);
count+=Combat_CollectPresentEnemyIndices(context,ids+count,16-count,0);
for(int i=0;i<count;++i)output[i]=ids[i];
return count;
}
