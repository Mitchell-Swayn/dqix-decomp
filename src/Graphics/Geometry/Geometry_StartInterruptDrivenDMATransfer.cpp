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

// Original data: arm9/main @ 0x2111684; symbol: data_02111684.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" GeometryDmaCallbackState MIiDMACallback_UnknownRoleZeroInitializedStorage;
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
    } while (MIiDMACallback_UnknownRoleZeroInitializedStorage.busy != 0);

    volatile unsigned int* geometryStatus = (volatile unsigned int*)0x04000600;
    while (((*geometryStatus & 0x07000000) >> 24 & 2) == 0)
    {
    }

    MIiDMACallback_UnknownRoleZeroInitializedStorage.busy = 1;
    MIiDMACallback_UnknownRoleZeroInitializedStorage.channel = channel;
    MIiDMACallback_UnknownRoleZeroInitializedStorage.source = (unsigned int)source;
    MIiDMACallback_UnknownRoleZeroInitializedStorage.length = length;
    MIiDMACallback_UnknownRoleZeroInitializedStorage.callback = callback;
    MIiDMACallback_UnknownRoleZeroInitializedStorage.userdata = userdata;

    VerifyDMASource(channel, (unsigned int)source, length, 0);
    AwaitDMACompletion(channel);

    int priorState = DisableIRQInterrupts();
    MIiDMACallback_UnknownRoleZeroInitializedStorage.savedGeometryControl = (*geometryStatus & 0xc0000000) >> 30;
    MIiDMACallback_UnknownRoleZeroInitializedStorage.savedHandler = GetInterruptHandler(0x00200000);
    *geometryStatus = (*geometryStatus & 0x3fffffff) | 0x40000000;
    SetInterruptHandler(0x00200000, (const void*)AdvanceChunkedDMAReadWithin472Bytes);
    EnableSpecificInterrupts(0x00200000);
    AdvanceChunkedDMAReadWithin472Bytes();
    SetIRQInterruptState(priorState);
}
