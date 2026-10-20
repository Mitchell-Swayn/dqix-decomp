#include <globaldefs.h>
ARM
extern "C" void* Network_GetCommandRecordPool(void);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CC2F0; symbol: func_ov017_021cc2f0; size: 0x30.
extern "C" void System_MoveQueuedRecordWithTypeSixDescriptor(unsigned char value) { unsigned char descriptor[0x14]; void* object = Network_GetCommandRecordPool(); descriptor[0] = 6; descriptor[4] = value; Network_QueueOutgoingRecord(object, descriptor, 0); }
