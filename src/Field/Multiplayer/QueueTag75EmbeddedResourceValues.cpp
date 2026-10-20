#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
struct Object;
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" unsigned FieldBattle_GetCombatContext(void*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct Payload75{unsigned short half;unsigned char byte,pad;unsigned word;};
struct Packet75{unsigned char tag,pad[3];Payload75 payload;unsigned unused[2];};
// Original: arm9/ov017 @ 0x021C83A0; symbol: func_ov017_021c83a0; size: 0x6C.
// Queues tag75 with embedded halfword8, byte5 and secondary resource word8e20.
extern "C" void QueueTag75EmbeddedResourceValues(){
 void*resource=*(void**)((unsigned char*)GameResources_GetInstance()+0x3718);
 unsigned char*embedded=(unsigned char*)FieldBattle_GetEncounterRequest(resource);
 unsigned secondary=FieldBattle_GetCombatContext(resource);
 Object*queue=(Object*)Network_GetCommandRecordPool();
 Packet75 packet;
 packet.tag=0x75;
 Payload75*payload=&packet.payload;
 payload->half=*(unsigned short*)(embedded+8);
 payload->word=*(unsigned*)(secondary+0x8e20);
 payload->byte=embedded[5];
 Network_QueueOutgoingRecord(queue,&packet,0);
}
