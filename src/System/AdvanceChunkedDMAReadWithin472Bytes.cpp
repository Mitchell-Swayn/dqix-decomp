#include <globaldefs.h>
#include <System/DMA.h>
#include <System/Interrupts.h>
// Original data: arm9/main @ 0x2111684; symbol: data_02111684.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{unsigned unknown;int channel;unsigned source,remaining;};extern "C" State MIiDMACallback_UnknownRoleZeroInitializedStorage;extern "C" void MIi_DMACallback(int);
// Original: arm9/main @ 0x020CA1A0; symbol: func_020ca1a0; size: 0xAC.
extern "C" ARM void AdvanceChunkedDMAReadWithin472Bytes(){unsigned source;unsigned count=MIiDMACallback_UnknownRoleZeroInitializedStorage.remaining;if(!count)return;if(count>=472)count=472;source=MIiDMACallback_UnknownRoleZeroInitializedStorage.source;MIiDMACallback_UnknownRoleZeroInitializedStorage.remaining-=count;MIiDMACallback_UnknownRoleZeroInitializedStorage.source=source+count;if(!MIiDMACallback_UnknownRoleZeroInitializedStorage.remaining){SetDMACompletionCallback(MIiDMACallback_UnknownRoleZeroInitializedStorage.channel,MIi_DMACallback,0);ConfigureDMATransferAtomic(MIiDMACallback_UnknownRoleZeroInitializedStorage.channel,source,0x04000400,0xc4400000|(count>>2));AcknowledgeSpecificInterrupts(0x200000);}else{ConfigureDMATransferAtomic(MIiDMACallback_UnknownRoleZeroInitializedStorage.channel,source,0x04000400,0x84400000|(count>>2));AcknowledgeSpecificInterrupts(0x200000);}}
