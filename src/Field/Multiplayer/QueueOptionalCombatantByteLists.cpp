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
struct Flags {unsigned char kind:4;unsigned char enabled:1;unsigned char rest:3;};
struct Record {unsigned char type;unsigned char pad[3];Flags flags;unsigned char bytes[15];};
// Original: arm9/ov017 @ 0x021C812C; symbol: func_ov017_021c812c; size: 0x190.
// Queues type 0x74, bitfield mode, and optional party/group nested-byte values.
extern "C" void QueueOptionalCombatantByteLists(int kind,int enabled){
 void *game=_ZN9GameState11GetInstanceEv();unsigned char *resources=(unsigned char*)GameResources_GetInstance();Object *queue=(Object*)Network_GetCommandRecordPool();
 Record r;short ids[8];memset(&r,0,0x14);r.type=0x74;*(unsigned char*)&r.flags=(*(unsigned char*)&r.flags&~0xf)|(kind&0xf);r.flags.enabled=(unsigned char)enabled;
 unsigned char *fields=(unsigned char*)&r.flags;
 if(!enabled){
 for(int i=0;i<4;i++)(fields+i)[1]=0xff;
 for(int i=0;i<8;i++)(fields+i)[5]=0xff;
 char *context=(char*)FieldBattle_GetCombatContext(*(void**)(resources+0x3718));if(context){
 int count=Combat_CollectEligiblePartyIds(context,ids,8,0x10);
 for(int i=0;i<count;i++){unsigned char *o=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(game,ids[i]);if(o){int index=*(short*)(o+4);(fields+index)[1]=GameObject_GetBattleGridIndexOrInvalid(o);}}
 count=Combat_CollectGroupIndicesByDescriptorFlags(context,ids,8,0x10);
 for(int i=0;i<count;i++){unsigned char *o=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(game,ids[i]);if(o){int index=*(short*)(o+4)-0xc0;(fields+index)[5]=GameObject_GetBattleGridIndexOrInvalid(o);}}
 }}
 Network_QueueOutgoingRecord(queue,&r,0);
}
