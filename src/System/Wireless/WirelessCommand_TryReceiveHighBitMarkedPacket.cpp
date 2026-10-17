#include <globaldefs.h>
extern "C" char data_021142e8[];extern "C" int MessageQueue_ReceiveWithOptionalBlocking(void*,unsigned short**,int);extern "C" void PrependBlockingQueueItemUnderIRQProtection(void*,unsigned short*,int);extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
#pragma optimization_level 4
// Original: arm9/main @ 0x020D4064; symbol: func_020d4064; size: 0x58.
extern "C" ARM unsigned short* WirelessCommand_TryReceiveHighBitMarkedPacket(){unsigned short* p;if(!MessageQueue_ReceiveWithOptionalBlocking(data_021142e8,&p,0))return 0;_Z24InvalidateDataCacheRangePKvj(p,2);if(*p&0x8000)return p;PrependBlockingQueueItemUnderIRQProtection(data_021142e8,p,1);return 0;}
