#pragma dont_inline on

/* IRQ-protected blocking, wakeups and readiness selection. Thread and
 * scheduler structures remain partial views with no new storage ownership. */
typedef struct ProcessorContext ProcessorContext;
typedef struct Mutex Mutex;
typedef struct { ProcessorContext *first,*last; } BlockedContextList;
typedef struct { Mutex *pFirst,*pLast; } MutexList;
struct ProcessorContext { char registers[0x48]; int state; ProcessorContext *pNext; unsigned int uniqueID,priority,unknown58; BlockedContextList *container; ProcessorContext *pPrevBlocked,*pNextBlocked; };
struct Mutex { BlockedContextList waiters; ProcessorContext *owner; int count; Mutex *pNext_,*pPrev_; };
typedef struct { char prefix[0x1c]; ProcessorContext **active; char unknown20[12]; ProcessorContext *firstContext; } ThreadGlobals;
extern ThreadGlobals ARM7_ThreadGlobals;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_InsertBlockedThread(BlockedContextList*,ProcessorContext*);
extern void ARM7_SwitchThread(void);
void ARM7_BlockCurrentThread(BlockedContextList *queue)
{
 int state=ARM7_DisableIRQInterrupts();
 ProcessorContext *current=*ARM7_ThreadGlobals.active;
 if(queue){current->container=queue;ARM7_InsertBlockedThread(queue,current);}
 current->state=0;
 ARM7_SwitchThread();
 ARM7_SetIRQInterruptState(state);
}
void ARM7_UnblockThreads(BlockedContextList *queue)
{
 int state=ARM7_DisableIRQInterrupts();
 if(queue->first){
  ProcessorContext *context;
  while(queue->first){
   ProcessorContext *front=queue->first;
   if(front){
    ProcessorContext *next=front->pNextBlocked;
    queue->first=next;
    if(next)next->pPrevBlocked=0;
    else{queue->last=0;front->container=0;}
   }
   context=front;
   context->state=1;
   context->container=0;
   context->pNextBlocked=0;
   context->pPrevBlocked=0;
  }
  queue->last=0;
  queue->first=0;
  ARM7_SwitchThread();
 }
 ARM7_SetIRQInterruptState(state);
}
void ARM7_MarkThreadReady(ProcessorContext *thread)
{
 int state=ARM7_DisableIRQInterrupts();
 thread->state=1;
 ARM7_SwitchThread();
 ARM7_SetIRQInterruptState(state);
}
ProcessorContext *ARM7_GetFirstReadyThread(void)
{
 ProcessorContext *thread=ARM7_ThreadGlobals.firstContext;
 while(thread && thread->state!=1)thread=thread->pNext;
 return thread;
}
