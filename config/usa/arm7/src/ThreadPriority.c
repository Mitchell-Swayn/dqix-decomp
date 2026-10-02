#pragma dont_inline on

/* Priority changes preserve global-list order and exclude the idle thread.
 * The external scheduler and context views own no additional storage. */
typedef struct ProcessorContext ProcessorContext;
typedef struct Mutex Mutex;
typedef struct Alarm Alarm;
typedef struct { ProcessorContext *first,*last; } BlockedContextList;
typedef struct { Mutex *first,*last; } MutexList;
struct ProcessorContext {
 unsigned int status,registers[15],resumeAddress,supervisorStack;
 int state;
 ProcessorContext *next;
 unsigned int uniqueID,priority,unknown58;
 BlockedContextList *container;
 ProcessorContext *previousBlocked,*nextBlocked;
 Mutex *blockingMutex;
 MutexList ownedMutexes;
 unsigned int stackLow,stackHigh,stackReserved;
 BlockedContextList joinWaiters;
 unsigned int unknown88[3];
 Alarm *sleepAlarm;
 void (*exitCallback)(int);
 unsigned int unknown9c[2];
};
typedef void (*SwitchCallback)(ProcessorContext*,ProcessorContext*);
typedef struct { unsigned int unknown0[2],switchLock,unknownC[4]; ProcessorContext **active; unsigned int initialized; unsigned short pending,irqDepth; ProcessorContext *current,*first; SwitchCallback callback; } ThreadGlobals;
typedef char ContextSizeCheck[sizeof(ProcessorContext) == 0xa4 ? 1 : -1];
extern ThreadGlobals ARM7_ThreadGlobals;
extern ProcessorContext ARM7_IdleThread;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern ProcessorContext *ARM7_InsertThreadGlobal(ProcessorContext*);
extern void ARM7_SwitchThread(void);
int ARM7_SetThreadPriority(ProcessorContext *thread,unsigned int priority)
{
 ProcessorContext *current=ARM7_ThreadGlobals.first;
 ProcessorContext *previous=0;
 int state=ARM7_DisableIRQInterrupts();
 while(current && current!=thread){previous=current;current=current->next;}
 if(!current || current==&ARM7_IdleThread){ARM7_SetIRQInterruptState(state);return 0;}
 if(current->priority!=priority){
  if(!previous)ARM7_ThreadGlobals.first=thread->next;
  else previous->next=thread->next;
  thread->priority=priority;
  ARM7_InsertThreadGlobal(thread);
  ARM7_SwitchThread();
 }
 ARM7_SetIRQInterruptState(state);
 return 1;
}
