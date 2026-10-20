#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021CBEB0; symbol: func_ov017_021cbeb0; size: 0x3C.
// Queues message 0x7f with a member byte and halfword token, paired with Field_ApplyMemberPresenceToken.
extern "C" void Field_QueueMemberPresenceToken(int member,unsigned short token) {
 void* queue=Network_GetCommandRecordPool();
 unsigned char message[20];
 struct Payload { unsigned char member,pad; unsigned short token; };
 message[0]=0x7f;
 Payload* payload=(Payload*)(message+4);
 payload->member=member;
 payload->token=token;
 Network_QueueOutgoingRecord(queue,message,0);
}
