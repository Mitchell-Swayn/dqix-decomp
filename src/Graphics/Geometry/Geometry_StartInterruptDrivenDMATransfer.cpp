#include <globaldefs.h>
#include <System/DMA.h>
#include <System/Interrupts.h>

struct GeometryDmaCallbackState
{
    volatile unsigned int busy;
    int channel;
    unsigned int source;
    unsigned int length;
    DMACompletionCallback callback;
    int userdata;
    unsigned int savedGeometryControl;
    InterruptHandlerProc savedHandler;
};

extern "C" GeometryDmaCallbackState data_02111684;
extern "C" void AdvanceChunkedDMAReadWithin472Bytes();

// Original: arm9/main @ 0x020CA0A8; symbol: func_020ca0a8; size: 0xF8.
extern "C" void Geometry_StartInterruptDrivenDMATransfer(int channel, const void* source, unsigned int length,
                               DMACompletionCallback callback, int userdata)
{
    if (length == 0)
    {
        if (callback != 0)
            callback(userdata);
        return;
    }

    do
    {
    } while (data_02111684.busy != 0);

    volatile unsigned int* geometryStatus = (volatile unsigned int*)0x04000600;
    while (((*geometryStatus & 0x07000000) >> 24 & 2) == 0)
    {
    }

    data_02111684.busy = 1;
    data_02111684.channel = channel;
    data_02111684.source = (unsigned int)source;
    data_02111684.length = length;
    data_02111684.callback = callback;
    data_02111684.userdata = userdata;

    VerifyDMASource(channel, (unsigned int)source, length, 0);
    AwaitDMACompletion(channel);

    int priorState = DisableIRQInterrupts();
    data_02111684.savedGeometryControl = (*geometryStatus & 0xc0000000) >> 30;
    data_02111684.savedHandler = GetInterruptHandler(0x00200000);
    *geometryStatus = (*geometryStatus & 0x3fffffff) | 0x40000000;
    SetInterruptHandler(0x00200000, (const void*)AdvanceChunkedDMAReadWithin472Bytes);
    EnableSpecificInterrupts(0x00200000);
    AdvanceChunkedDMAReadWithin472Bytes();
    SetIRQInterruptState(priorState);
}
