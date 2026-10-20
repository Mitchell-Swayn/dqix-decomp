#include <globaldefs.h>
ARM
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct Payload {unsigned short identifier;char unknown;unsigned char low:4;signed char high:4;};
struct Message {unsigned char opcode,unknown;unsigned short padding;Payload payload;unsigned unusedPayload[3];};
// Original: arm9/ov017 @ 0x021C9544; symbol: Field_QueueMonsterHideRequest; size: 0x70.
// Enqueues opcode 0x86 with a halfword identifier and two packed nibbles.
// The third argument and remaining record bytes have no writes in the original.
extern "C" void Field_QueueMonsterHideRequest(unsigned identifier,unsigned low,unsigned unused,int high) {
 Object* object=(Object*)Network_GetCommandRecordPool();
 Message message;
 Payload* payload=&message.payload;
 message.opcode=0x86;
 payload->identifier=identifier;
 payload->low=(unsigned char)low;
 payload->high=(signed char)high;
 Network_QueueOutgoingRecord(object,&message,0);
}
