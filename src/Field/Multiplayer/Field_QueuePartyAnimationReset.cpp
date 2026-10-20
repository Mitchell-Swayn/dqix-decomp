#include <globaldefs.h>
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, void*, int);
struct MessagePayload3C { unsigned char opcode; unsigned char pad[3]; unsigned char value; };
// Original: arm9/ov017 @ 0x021D440C; symbol: func_ov017_021d440c; size: 0x30.
extern "C" ARM void Field_QueuePartyAnimationReset(int value) { void* context=Network_GetCommandRecordPool(); unsigned char payload[20]; payload[0]=0x3c; payload[4]=(unsigned char)value; Network_QueueOutgoingRecord(context, payload, 0); }
