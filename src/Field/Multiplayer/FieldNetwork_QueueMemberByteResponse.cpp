#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021D0860; symbol: func_ov017_021d0860; size: 0x6C.
// Queues message 0x9a with target and local member identifiers; response byte is written for kinds zero and one.
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_GetLocalMemberId(void*);
extern "C" void FieldNetwork_QueueMemberByteResponse(int target,int kind,int value) {
 void* queue=Network_GetCommandRecordPool();
 void* game=Network_GetConnectionManager();
 unsigned char message[20];
 unsigned char* payload=message+4;
 message[0]=0x9a;payload[0]=target;payload[2]=kind;
 payload[1]=Network_GetLocalMemberId(game);
 if(payload[2]==0) payload[3]=value;
 else if(payload[2]==1) payload[3]=value;
 Network_QueueOutgoingRecord(queue,message,0);
}
