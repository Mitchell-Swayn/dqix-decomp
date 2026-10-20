#include <globaldefs.h>
ARM
struct Object;struct GameResources;
extern "C" void* memset(void*,int,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* Network_GetCommandRecordPool();
extern "C" void* FieldBattle_GetCombatContext(void*);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
struct Record {unsigned char type;int position[3];short index;unsigned short value;};
// Original: arm9/ov017 @ 0x021C8758; symbol: func_ov017_021c8758; size: 0x174.
// Queues type 0x78 position records for collected party and group combatants.
extern "C" void QueueCollectedCombatantPositions(unsigned short value){
 void *game=_ZN9GameState11GetInstanceEv();unsigned char *resources=(unsigned char*)GameResources_GetInstance();
 Object *queue=(Object*)Network_GetCommandRecordPool();char *context=(char*)FieldBattle_GetCombatContext(*(void**)(resources+0x3718));
 if(!context)return;
 short ids[8];int count=Combat_CollectEligiblePartyIds(context,ids,8,0x10);
 for(int i=0;i<count;i++){
 unsigned char *o=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(game,ids[i]);
 if(o){unsigned char *nested=*(unsigned char**)(o+0x13c);if(nested){
 Record r;memset(&r,0,0x14);r.type=0x78;unsigned char *fields=(unsigned char*)r.position;*(unsigned short*)(fields+14)=value;*(short*)(fields+12)=ids[i];_ZN8Vector3iaSERKS_(fields,nested+0x10);
 Network_QueueOutgoingRecord(queue,&r,0);}}}
 count=Combat_CollectGroupIndicesByDescriptorFlags(context,ids,8,0x10);
 for(int i=0;i<count;i++){
 unsigned char *o=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(game,ids[i]);
 if(o){unsigned char *nested=*(unsigned char**)(o+0x13c);if(nested){
 Record r;memset(&r,0,0x14);r.type=0x78;unsigned char *fields=(unsigned char*)r.position;*(unsigned short*)(fields+14)=value;*(short*)(fields+12)=ids[i];_ZN8Vector3iaSERKS_(fields,nested+0x10);
 Network_QueueOutgoingRecord(queue,&r,0);}}}
}
