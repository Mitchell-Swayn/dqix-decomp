#include <globaldefs.h>
ARM
struct Object;struct GameResources;
extern "C" void* memset(void*,int,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* Network_GetCommandRecordPool();
extern "C" void* FieldBattle_GetCombatContext(void*);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" unsigned int GameObject_GetBattleGridIndexOrInvalid(unsigned char*);
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
struct Record {unsigned char type;unsigned char pad[3];unsigned char party[4];unsigned char group[8];unsigned short value;unsigned short tail;};
// Original: arm9/ov017 @ 0x021C894C; symbol: func_ov017_021c894c; size: 0x164.
// Queues type 0x79 with party/group nested bytes, defaulting absent entries to 0xff.
extern "C" void QueueCombatantNestedByteLists(unsigned short value){
 void *game=_ZN9GameState11GetInstanceEv();unsigned char *resources=(unsigned char*)GameResources_GetInstance();
 Object *queue=(Object*)Network_GetCommandRecordPool();char *context=(char*)FieldBattle_GetCombatContext(*(void**)(resources+0x3718));
 if(!context)return;
 Record r;short ids[8];memset(&r,0,0x14);unsigned char *fields=r.party;r.type=0x79;*(unsigned short*)(fields+12)=value;
 for(int i=0;i<4;i++)fields[i]=0xff;
 for(int i=0;i<8;i++)(fields+i)[4]=0xff;
 int count=Combat_CollectEligiblePartyIds(context,ids,8,0x10);
 for(int i=0;i<count;i++){unsigned char *o=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(game,ids[i]);if(o)fields[ids[i]]=GameObject_GetBattleGridIndexOrInvalid(o);}
 count=Combat_CollectGroupIndicesByDescriptorFlags(context,ids,8,0x10);
 for(int i=0;i<count;i++){unsigned char *o=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(game,ids[i]);if(o){int index=ids[i]-0xc0;(fields+index)[4]=GameObject_GetBattleGridIndexOrInvalid(o);}}
 Network_QueueOutgoingRecord(queue,&r,0);
}
