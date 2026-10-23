#include <globaldefs.h>
#include <Resource/GameResources.h>
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" GameResources* GameResources_GetInstance();
extern "C" unsigned FieldBattle_GetCombatContext(void*);
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct BattleSlotContext { unsigned char unknown[0x8de0]; unsigned assignments[8]; unsigned char gap[0x18]; unsigned char* encounter; };
struct BattleSlotPayload { unsigned short encounter; unsigned char slots[8]; };
struct BattleSlotPacket { unsigned char type,padding[3]; BattleSlotPayload payload; unsigned char unused[6]; };
// Original: arm9/ov017 @ 0x021cbdcc; symbol: Combat_QueueEncounterBattleSlotAssignments; size: 0x84.
extern "C" ARM void Combat_QueueEncounterBattleSlotAssignments() {
Object* queue=(Object*)Network_GetCommandRecordPool();
BattleSlotContext* context=(BattleSlotContext*)FieldBattle_GetCombatContext(GameResources_GetInstance()->unknown_ptr_3718);
if(context) {
BattleSlotPacket packet;packet.type=0x7e;
BattleSlotPayload* payload=&packet.payload;
payload->encounter=*(unsigned short*)(context->encounter+8);
unsigned char* slots=payload->slots;
for(int i=0;i<8;++i) {*slots=context->assignments[i];++slots;}
Network_QueueOutgoingRecord(queue,&packet,0);
}
}
