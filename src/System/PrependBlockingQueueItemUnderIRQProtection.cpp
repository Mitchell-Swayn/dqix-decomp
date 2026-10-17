#include <globaldefs.h>
#include <System/Interrupts.h>
#include <System/ProcessorContext.h>
struct Queue {BlockedContextList blocked,wake;unsigned* slots;int capacity,index,count;};
// Original: arm9/main @ 0x020C7F44; symbol: func_020c7f44; size: 0x9C.
extern "C" int PrependBlockingQueueItemUnderIRQProtection(Queue* self,unsigned value,unsigned flags) {int irq=DisableIRQInterrupts();int capacity=self->capacity;if(capacity<=self->count){do {if(!(flags&1)){SetIRQInterruptState(irq);return 0;}BlockCurrentContext(&self->blocked);capacity=self->capacity;}while(capacity<=self->count);}self->index=(self->index+capacity-1)%capacity;self->slots[self->index]=value;++self->count;UnblockContexts(&self->wake);SetIRQInterruptState(irq);return 1;}
