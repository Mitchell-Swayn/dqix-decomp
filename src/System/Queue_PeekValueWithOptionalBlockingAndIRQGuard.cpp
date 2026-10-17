#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <System/Interrupts.h>
#include <System/ProcessorContext.h>
struct Queue{char pad[8];BlockedContextList waiting;unsigned* values;int capacity;int index;int count;};
// Original: arm9/main @ 0x020C7FE0; symbol: func_020c7fe0; size: 0x7C.
extern "C" int Queue_PeekValueWithOptionalBlockingAndIRQGuard(Queue* q,unsigned* out,unsigned flags){int irq=DisableIRQInterrupts();if(!q->count){do{if(!(flags&1)){SetIRQInterruptState(irq);return 0;}BlockCurrentContext(&q->waiting);}while(!q->count);}if(out)*out=q->values[q->index];SetIRQInterruptState(irq);return 1;}
