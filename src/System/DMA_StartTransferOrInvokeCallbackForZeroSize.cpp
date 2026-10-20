#include <globaldefs.h>
#include "System/DMA.h"
extern void SetDMACompletionCallback(int,DMACompletionCallback,int);
extern "C" void Geometry_CompleteDMATransferCallback(int);
struct State
{
    volatile int busy;
    int channel;
    unsigned pad[2];
    DMACompletionCallback callback;
    int userdata;
};
// Original data: arm9/main @ 0x2111684; symbol: data_02111684.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State MIiDMACallback_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020CA2AC; symbol: func_020ca2ac; size: 0xB8.
extern "C" ARM void DMA_StartTransferOrInvokeCallbackForZeroSize(int channel,unsigned source,unsigned size,DMACompletionCallback callback,int data)
{
    if(!size)
    {
        if(callback)callback(data);
        return;
    }while(MIiDMACallback_UnknownRoleZeroInitializedStorage.busy)
    {
    }MIiDMACallback_UnknownRoleZeroInitializedStorage.busy=1;
    MIiDMACallback_UnknownRoleZeroInitializedStorage.channel=channel;
    MIiDMACallback_UnknownRoleZeroInitializedStorage.callback=callback;
    MIiDMACallback_UnknownRoleZeroInitializedStorage.userdata=data;
    VerifyOtherDMATimingCompatibility(channel,0x38000000);
    VerifyDMASource(channel,source,size,0);
    AwaitDMACompletion(channel);
    SetDMACompletionCallback(channel,Geometry_CompleteDMATransferCallback,0);
    ConfigureDMATransferAtomic(channel,source,0x04000400,(size>>2)|0xfc400000);
}
