#include <globaldefs.h>
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*, void*, int);
struct MessagePayload1B { unsigned char opcode; unsigned char pad[3]; };
// Original: arm9/ov017 @ 0x021D2400; symbol: func_ov017_021d2400; size: 0x28.
extern "C" ARM void Network_QueuePartyRecoveryRequest() { void* context=Network_GetCommandRecordPool(); unsigned char payload[20]; payload[0]=0x1b; Network_QueueOutgoingRecord(context, payload, 0); }
