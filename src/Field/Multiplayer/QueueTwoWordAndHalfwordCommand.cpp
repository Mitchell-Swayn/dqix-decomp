#include <globaldefs.h>
ARM
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
// Queue copies a 16-byte payload following its four-byte scalar header.
struct CommandPayload { unsigned first,second; unsigned short identifier; unsigned char unknown[6]; };
struct Command { unsigned char opcode,unknown1; unsigned short unknown2; CommandPayload payload; };
// Original: arm9/ov017 @ 0x021CF650; symbol: func_ov017_021cf650; size: 0x44.
// Queues opcode 0x6D with two words and a halfword; remaining command bytes are uninitialized originally.
extern "C" void QueueTwoWordAndHalfwordCommand(unsigned short identifier,unsigned first,unsigned second) {
 Object* queue=(Object*)Network_GetCommandRecordPool();
 Command command;
 command.opcode=0x6d;
 CommandPayload* payload=&command.payload;
 payload->first=first;payload->second=second;payload->identifier=identifier;
 Network_QueueOutgoingRecord(queue,&command,0);
}
