#include <globaldefs.h>
ARM
struct PackedModes { unsigned short a:2,b:4,c:3,d:3,reserved:4; };
struct CombatRecord { char pad[0x22]; PackedModes modes; unsigned char value; unsigned char pad25; unsigned char active; };
struct CombatExtra { char pad[0x30]; unsigned short a,b; };
struct QueuedCombatant { char pad[0x134]; CombatExtra* extra; CombatRecord* record; };
struct Payload { unsigned short id,index; PackedModes modes; unsigned char value; unsigned char gap; unsigned short a,b; unsigned pad; };
struct Packet { unsigned char type; unsigned char pad[3]; Payload payload; };
inline Payload* PacketPayload(Packet* p) { return &p->payload; }
extern "C" {
void* _ZN9GameState11GetInstanceEv();
QueuedCombatant* _ZN9GameState19GetCombatantByIndexEi(void*,int);
void* Network_GetCommandRecordPool();
void Network_QueueOutgoingRecord(void*,const void*,short);
unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);
unsigned char* GameResources_GetInstance();
unsigned char* FieldBattle_GetEncounterRequest(void*);
}
inline unsigned char Modea(CombatRecord* p) { return p->modes.a; }
inline unsigned char Modeb(CombatRecord* p) { return p->modes.b; }
inline unsigned char Modec(CombatRecord* p) { return p->modes.c; }
inline unsigned char Moded(CombatRecord* p) { return p->modes.d; }
// Original: arm9/ov017 @ 0x021C6D50; symbol: func_ov017_021c6d50; size: 0x16C.
extern "C" void GameState_QueueActiveCombatantRecords() {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char* group=FieldBattle_GetEncounterRequest(*(void**)(GameResources_GetInstance()+0x3718));
 void* queue=Network_GetCommandRecordPool();
 Packet packet;
 packet.type=0x6f;
 Payload* payload=PacketPayload(&packet);
 for(int i=0;i<4;i++) {
  if(PartySelection_GetMemberMask(group,(unsigned char)i)) {
   QueuedCombatant* p=_ZN9GameState19GetCombatantByIndexEi(state,i);
   if(p->record->active) {
    payload->id=*(unsigned short*)(group+8);
    payload->index=i;
    payload->modes.a=Modea(p->record);
    payload->modes.b=Modeb(p->record);
    payload->modes.c=Modec(p->record);
    payload->modes.d=Moded(p->record);
    payload->value=p->record->value;
    payload->a=p->extra->a;
    payload->b=p->extra->b;
    Network_QueueOutgoingRecord(queue,&packet,0);
   }
  }
 }
}
