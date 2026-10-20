#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021CDB00; symbol: func_ov017_021cdb00; size: 0x4C.
// Queues message 0x91 containing two bytes, a halfword key and a word value.
extern "C" void Field_QueueIndexedProgressBoolean(int index,unsigned short key,unsigned value,int member) {
 void* queue=Network_GetCommandRecordPool();
 unsigned char message[20];
 struct Payload { unsigned char member,index; unsigned short key; unsigned value; };
 message[0]=0x91;
 Payload* payload=(Payload*)(message+4);
 payload->member=member;payload->index=index;
 payload->key=key;
 payload->value=value;
 Network_QueueOutgoingRecord(queue,message,0);
}
