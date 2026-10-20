#pragma dont_inline on

/* Bounded circular message queue with independent send/receive wait lists.
 * Flag bit zero selects blocking behavior. All mutations occur under IRQ
 * protection; blocked callers are resumed by the opposite operation. */
#include "MessageQueue.h"
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_BlockCurrentThread(ThreadQueue*);
extern void ARM7_UnblockThreads(ThreadQueue*);
// Original: arm7/wram @ 0x037FCADC; symbol: ARM7_InitializeMessageQueue.
void ARM7_InitializeMessageQueue(MessageQueue *queue,void **messages,int capacity)
{
 queue->sendWaiters.first=queue->sendWaiters.last=0;
 queue->receiveWaiters.first=queue->receiveWaiters.last=0;
 queue->messages=messages;
 queue->capacity=capacity;
 queue->head=0;
 queue->count=0;
}
// Original: arm7/wram @ 0x037FCB04; symbol: ARM7_SendMessage.
int ARM7_SendMessage(MessageQueue *queue,void *message,int flags)
{
 int state=ARM7_DisableIRQInterrupts();
 while(queue->capacity<=queue->count){
  if(!(flags&1)){ARM7_SetIRQInterruptState(state);return 0;}
  ARM7_BlockCurrentThread(&queue->sendWaiters);
 }
 queue->messages[(queue->head+queue->count)%queue->capacity]=message;
 queue->count++;
 ARM7_UnblockThreads(&queue->receiveWaiters);
 ARM7_SetIRQInterruptState(state);
 return 1;
}
// Original: arm7/wram @ 0x037FCB90; symbol: ARM7_ReceiveMessage.
int ARM7_ReceiveMessage(MessageQueue *queue,void **message,int flags)
{
 int state=ARM7_DisableIRQInterrupts();
 while(queue->count==0){
  if(!(flags&1)){ARM7_SetIRQInterruptState(state);return 0;}
  ARM7_BlockCurrentThread(&queue->receiveWaiters);
 }
 if(message)*message=queue->messages[queue->head];
 queue->head=(queue->head+1)%queue->capacity;
 queue->count--;
 ARM7_UnblockThreads(&queue->sendWaiters);
 ARM7_SetIRQInterruptState(state);
 return 1;
}
// Original: arm7/wram @ 0x037FCC2C; symbol: ARM7_PeekMessage.
int ARM7_PeekMessage(MessageQueue *queue,void **message,int flags)
{
 int state;
 int blocking;
 state=ARM7_DisableIRQInterrupts();
 blocking=flags&1;
 while(queue->count==0){
  if(!blocking){ARM7_SetIRQInterruptState(state);return 0;}
  ARM7_BlockCurrentThread(&queue->receiveWaiters);
 }
 if(message)*message=queue->messages[queue->head];
 ARM7_SetIRQInterruptState(state);
 return 1;
}
