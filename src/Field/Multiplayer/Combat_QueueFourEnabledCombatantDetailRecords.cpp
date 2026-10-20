#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned GameResources_GetInstance(...);
extern "C" unsigned Network_QueueOutgoingRecord(...);
extern "C" unsigned FieldBattle_GetEncounterRequest(...);
extern "C" unsigned Network_GetCommandRecordPool(...);
extern "C" unsigned PartySelection_GetMemberMask(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState19GetCombatantByIndexEi(...);
// Original: arm9/ov017 @ 0x021c6bc8; symbol: Combat_QueueFourEnabledCombatantDetailRecords; size: 0xd8.
extern "C" void Combat_QueueFourEnabledCombatantDetailRecords(){
unsigned game=_ZN9GameState11GetInstanceEv();unsigned owner=FieldBattle_GetEncounterRequest(U32(GameResources_GetInstance()+0x3718));unsigned queue=Network_GetCommandRecordPool();struct Payload {unsigned short owner,index,a,b;unsigned flags,value;};struct Packet {unsigned char type,pad[3];Payload data;};Packet packet;packet.type=110;Payload* payload=&packet.data;
for(int i=0;i<4;++i){if(PartySelection_GetMemberMask(owner,(unsigned char)i)){unsigned combatant=_ZN9GameState19GetCombatantByIndexEi(game,i);if(U8(U32(combatant+0x138)+0x26)){payload->owner=U16(owner+8);payload->index=i;payload->a=U16(U32(combatant+0x138));payload->b=U16(U32(combatant+0x138)+2);payload->flags=U32(U32(combatant+0x138)+0x14);payload->value=U32(U32(combatant+0x138)+0x18);Network_QueueOutgoingRecord(queue,D(&packet),0);}}}
}