#include <globaldefs.h>
// Original data: arm9/main @ 0x21142e8; symbol: data_021142e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char WMiSendCommand_UnknownRoleZeroInitializedStorage[];extern "C" int MessageQueue_ReceiveWithOptionalBlocking(void*,unsigned short**,int);extern "C" void PrependBlockingQueueItemUnderIRQProtection(void*,unsigned short*,int);extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
#pragma optimization_level 4
// Original: arm9/main @ 0x020D4064; symbol: func_020d4064; size: 0x58.
extern "C" ARM unsigned short* WirelessCommand_TryReceiveHighBitMarkedPacket(){unsigned short* p;if(!MessageQueue_ReceiveWithOptionalBlocking(WMiSendCommand_UnknownRoleZeroInitializedStorage,&p,0))return 0;_Z24InvalidateDataCacheRangePKvj(p,2);if(*p&0x8000)return p;PrependBlockingQueueItemUnderIRQProtection(WMiSendCommand_UnknownRoleZeroInitializedStorage,p,1);return 0;}
