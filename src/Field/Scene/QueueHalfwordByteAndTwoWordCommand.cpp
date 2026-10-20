#include <globaldefs.h>
ARM
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
struct CommandPayload { unsigned short identifier;unsigned char selector,unknown3;unsigned first,second;unsigned char unknown[4]; };
struct Command { unsigned char opcode,unknown1;unsigned short unknown2;CommandPayload payload; };
// Original: arm9/ov017 @ 0x021D09CC; symbol: func_ov017_021d09cc; size: 0x4C.
// Queues opcode 0x8B with a halfword, byte and two words; untouched bytes remain uninitialized as originally.
extern "C" void QueueHalfwordByteAndTwoWordCommand(unsigned short identifier,unsigned char selector,unsigned first,unsigned second) {
 Object* queue=(Object*)Network_GetCommandRecordPool();
 Command command;
 unsigned char opcode=0x8b;
 CommandPayload* payload=&command.payload;
 command.opcode=opcode;
 payload->identifier=identifier;payload->selector=selector;payload->first=first;payload->second=second;
 Network_QueueOutgoingRecord(queue,&command,0);
}
