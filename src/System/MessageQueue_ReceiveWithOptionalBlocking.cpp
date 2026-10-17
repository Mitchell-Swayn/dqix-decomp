#pragma optimize_for_size off
#include <globaldefs.h>
ARM
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"
struct Queue { BlockedContextList readers,writers; unsigned* data; int capacity,index,count; };
// Original: arm9/main @ 0x020C7EA0; symbol: func_020c7ea0; size: 0xA4.
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(Queue* queue,unsigned* output,unsigned flags) { int irq=DisableIRQInterrupts(); if(queue->count==0) { do { if(!(flags&1)) { SetIRQInterruptState(irq); return 0; } BlockCurrentContext(&queue->writers); } while(queue->count==0); } if(output) *output=queue->data[queue->index]; queue->index=(queue->index+1)%queue->capacity; --queue->count; UnblockContexts(&queue->readers); SetIRQInterruptState(irq); return 1; }
