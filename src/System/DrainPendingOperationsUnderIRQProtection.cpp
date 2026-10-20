#include <globaldefs.h>
#include <System/Interrupts.h>
struct Job {char pad[0x24];unsigned flags;char pad28[0x10];unsigned pending;unsigned unused;unsigned channel;void* event;};
extern "C" void SoundStream_DispatchNextBufferSlice(Job*,unsigned);
extern "C" void SoundCommand_SubmitOpcodeTwelve(void*,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020BCE2C; symbol: func_020bce2c; size: 0x70.
extern "C" void DrainPendingOperationsUnderIRQProtection(Job* p) {if(!((int)(p->flags<<30)>>31))return;if(p->pending)do{int state=DisableIRQInterrupts();SoundStream_DispatchNextBufferSlice(p,1);SetIRQInterruptState(state);}while(p->pending);SoundCommand_SubmitOpcodeTwelve(p->event,0,1u<<p->channel,0);}
