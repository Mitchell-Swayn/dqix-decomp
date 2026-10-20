#include <globaldefs.h>
ARM
extern "C" {
void* Combat_GetCommandActorSnapshot(void* object,int index);
void* Combat_GetIndexedActionTarget(void* object,int index);
int Combat_CollectEligiblePartyIds(void* context,short* output,int limit,int flags);
int Combat_CollectPresentEnemyIndices(void*,short* output,int capacity,int flags);
}
inline int IsPartyIndex(int id) {return id>=0 && id<=3;}
inline int IsEnemyIndex(int id) {return id>=0xc0 && id<=0xc7;}
// Original: arm9/ov000 @ 0x0218177C; symbol: Combat_CollectLinkedRecordSideCombatants; size: 0x164.
// Reads the side of the first command actor or action target (party 0..3, enemy 0xc0..0xc7)
// and collects same-side or opposing combatant IDs, widening them to words.
extern "C" int Combat_CollectLinkedRecordSideCombatants(void* context,void* owner,int useCommandActor,int sameSide,int* output) {
 int id;
 if(useCommandActor) {char* record=(char*)Combat_GetCommandActorSnapshot(owner,0);if(!record)return 0;id=*(short*)(record+0x20);}
 else {char* record=(char*)Combat_GetIndexedActionTarget(owner,0);if(!record)return 0;id=*(short*)(record+0xe);}
 short ids[12];int count=0;
 if(sameSide) {
 if(IsPartyIndex(id))count=Combat_CollectEligiblePartyIds(context,ids,12,0);
 else if(IsEnemyIndex(id))count=Combat_CollectPresentEnemyIndices(context,ids,12,0);
 }else {
 if(IsPartyIndex(id))count=Combat_CollectPresentEnemyIndices(context,ids,12,0);
 else if(IsEnemyIndex(id))count=Combat_CollectEligiblePartyIds(context,ids,12,0);
 }
 for(int i=0;i<count;i++)output[i]=ids[i];
 return count;
}
