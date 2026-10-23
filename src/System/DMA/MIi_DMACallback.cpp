#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/DMA.h>
ARM
// NitroSDK mi_dma_gxcommand.c: full 32-byte transfer state.
// Current project DMA API stores DMACompletionCallback(int) and integer userdata.
// Pinned SDK uses void* userdata; this callback ignores its own input argument.
// Keep the accepted project callback and userdata types consistent end to end.
struct GeometryDmaCallbackState {
 volatile unsigned int busy;
 int channel;
 unsigned int source;
 unsigned int length;
 DMACompletionCallback callback;
 int userdata;
 unsigned int savedGeometryControl;
 InterruptHandlerProc savedHandler;
};
extern "C" GeometryDmaCallbackState MIiDMACallback_UnknownRoleZeroInitializedStorage;
#pragma always_inline on
static inline void SetFifoCondition(unsigned cond) {
 volatile unsigned* gxstat=(volatile unsigned*)0x04000600;
 *gxstat=(cond<<30)|(*gxstat&~0xc0000000U);
}
static inline void CallCallback(DMACompletionCallback callback,int arg) {if(callback)callback(arg);}
// Original: arm9/main @ 0x020CA24C; symbol: func_020ca24c; size: 0x60.
extern "C" void MIi_DMACallback(int) {
 DisableSpecificInterrupts(0x200000);
 SetFifoCondition(MIiDMACallback_UnknownRoleZeroInitializedStorage.savedGeometryControl);
 SetInterruptHandler(0x200000,MIiDMACallback_UnknownRoleZeroInitializedStorage.savedHandler);
 MIiDMACallback_UnknownRoleZeroInitializedStorage.busy=0;
 CallCallback(MIiDMACallback_UnknownRoleZeroInitializedStorage.callback,MIiDMACallback_UnknownRoleZeroInitializedStorage.userdata);
}
