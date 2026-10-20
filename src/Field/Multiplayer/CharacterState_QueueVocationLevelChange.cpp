#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021CE614; symbol: func_ov017_021ce614; size: 0x44.
// Queues three bytes in message 0xb0; remaining payload bytes are unspecified in the original.
extern "C" void CharacterState_QueueVocationLevelChange(int member,int vocation,int level) {
 void* queue=Network_GetCommandRecordPool();
 unsigned char message[20];
 struct Payload { unsigned char member,vocation,level; };
 message[0]=0xb0;
 Payload* payload=(Payload*)(message+4);
 payload->member=member;payload->vocation=vocation;payload->level=level;
 Network_QueueOutgoingRecord(queue,message,0);
}
