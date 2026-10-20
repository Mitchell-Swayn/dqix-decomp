#include <globaldefs.h>
ARM
struct Queue {void* first;void* last;int count;};
struct Object {unsigned char pad[0x1500];Queue queues[3];};
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct MessagePayload80 {unsigned char identifier;unsigned char unknown;unsigned short value;unsigned tail[3];};
struct Message80 {unsigned char code;unsigned char unknown[3];MessagePayload80 payload;};
// Original: arm9/ov017 @ 0x021CBF18; symbol: func_ov017_021cbf18; size: 0x3C.
// Queues code0x80 with a byte identifier and halfword value; unused bytes remain unspecified as observed.
extern "C" void Field_QueueEncounterControlHandshake(int identifier,unsigned short value) {
 Object* queue=(Object*)Network_GetCommandRecordPool();
 unsigned char message[20];
 message[0]=0x80;
 MessagePayload80* payload=(MessagePayload80*)(message+4);
 payload->identifier=identifier;payload->value=value;
 Network_QueueOutgoingRecord(queue,message,0);
}
