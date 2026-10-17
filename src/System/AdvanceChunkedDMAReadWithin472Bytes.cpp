#include <globaldefs.h>
#include <System/DMA.h>
#include <System/Interrupts.h>
struct State{unsigned unknown;int channel;unsigned source,remaining;};extern "C" State data_02111684;extern "C" void func_020ca24c(int);
// Original: arm9/main @ 0x020CA1A0; symbol: func_020ca1a0; size: 0xAC.
extern "C" ARM void AdvanceChunkedDMAReadWithin472Bytes(){unsigned source;unsigned count=data_02111684.remaining;if(!count)return;if(count>=472)count=472;source=data_02111684.source;data_02111684.remaining-=count;data_02111684.source=source+count;if(!data_02111684.remaining){SetDMACompletionCallback(data_02111684.channel,func_020ca24c,0);ConfigureDMATransferAtomic(data_02111684.channel,source,0x04000400,0xc4400000|(count>>2));AcknowledgeSpecificInterrupts(0x200000);}else{ConfigureDMATransferAtomic(data_02111684.channel,source,0x04000400,0x84400000|(count>>2));AcknowledgeSpecificInterrupts(0x200000);}}
