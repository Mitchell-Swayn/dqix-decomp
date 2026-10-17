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
extern "C" State data_02111684;
// Original: arm9/main @ 0x020CA2AC; symbol: func_020ca2ac; size: 0xB8.
extern "C" ARM void DMA_StartTransferOrInvokeCallbackForZeroSize(int channel,unsigned source,unsigned size,DMACompletionCallback callback,int data)
{
    if(!size)
    {
        if(callback)callback(data);
        return;
    }while(data_02111684.busy)
    {
    }data_02111684.busy=1;
    data_02111684.channel=channel;
    data_02111684.callback=callback;
    data_02111684.userdata=data;
    VerifyDMATimingChangePermitted_020c9fd0(channel,0x38000000);
    VerifyDMASource(channel,source,size,0);
    AwaitDMACompletion(channel);
    SetDMACompletionCallback(channel,Geometry_CompleteDMATransferCallback,0);
    ConfigureDMATransferAtomic(channel,source,0x04000400,(size>>2)|0xfc400000);
}
