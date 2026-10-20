#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
// Original: arm9/ov017 @ 0x021CD6D8; symbol: func_ov017_021cd6d8; size: 0x70.
// Packs selected paired-state fields into message 0x8e without initializing unspecified record bytes.
extern "C" void Field_QueuePairedStateRequest(char* state) {
 void* queue=Network_GetCommandRecordPool();
 unsigned char message[20];
 unsigned char* payload=message+4;
 message[0]=0x8e;
 *(unsigned short*)payload=*(unsigned short*)state;
 *(unsigned short*)(payload+2)=*(unsigned short*)(state+2);
 *(unsigned short*)(payload+4)=*(unsigned short*)(state+4);
 payload[10]=*(unsigned char*)(state+8);
 *(unsigned short*)(payload+6)=*(unsigned short*)(state+10);
 *(short*)(payload+8)=*(short*)(state+6);
 *(unsigned*)(payload+12)=*(unsigned*)(state+16);
 payload[11]=*(signed char*)(state+12);
 Network_QueueOutgoingRecord(queue,message,0);
}
