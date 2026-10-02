#pragma dont_inline on

/* Thread return, optional exit-stack handoff, callback dispatch and teardown.
 * Register initialization/restoration and scheduler locks remain binary-owned.
 * Context and scheduler types describe observed fields without owning storage. */
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
typedef struct { unsigned int unknown0,exitStack,switchLock,unknownC[3]; void *callback; ProcessorContext **active; unsigned int initialized; unsigned short pending,irqDepth; ProcessorContext *current,*first; } ThreadGlobals;
typedef char ContextSizeCheck[sizeof(ProcessorContext) == 0xa4 ? 1 : -1];
extern ThreadGlobals ARM7_ThreadGlobals;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_InitializeThreadRegisters(ProcessorContext*,unsigned int,unsigned int);
extern void ARM7_RestoreThreadContext(ProcessorContext*);
extern unsigned int ARM7_LockThreadSwitch(void);
extern unsigned int ARM7_UnlockThreadSwitch(void);
extern void ARM7_UnlockAllMutexesLockedByContext(ProcessorContext*);
extern ProcessorContext *ARM7_RemoveBlockedThread(BlockedContextList*,ProcessorContext*);
extern void ARM7_RemoveThreadGlobal(ProcessorContext*);
extern void ARM7_UnblockThreads(BlockedContextList*);
extern void ARM7_SwitchThread(void);
extern void ARM7_Terminate(void);
void ARM7_ExitThread(ProcessorContext*,int);
void ARM7_RunThreadExitCallback(int);
void ARM7_DestroyCurrentThread(void);
void ARM7_ThreadReturn(void)
{
 ARM7_DisableIRQInterrupts();
 ARM7_ExitThread(ARM7_ThreadGlobals.current,0);
}
void ARM7_ExitThread(ProcessorContext *thread,int argument)
{
 if(ARM7_ThreadGlobals.exitStack){
  ARM7_InitializeThreadRegisters(thread,(unsigned int)ARM7_RunThreadExitCallback,ARM7_ThreadGlobals.exitStack);
  thread->registers[0]=argument;
  thread->status|=0x80;
  thread->state=1;
  ARM7_RestoreThreadContext(thread);
 }else ARM7_RunThreadExitCallback(argument);
}
void ARM7_RunThreadExitCallback(int argument)
{
 ProcessorContext *thread=*ARM7_ThreadGlobals.active;
 if(thread->exitCallback){
  void (*callback)(int)=thread->exitCallback;
  thread->exitCallback=0;
  callback(argument);
  ARM7_DisableIRQInterrupts();
 }
 ARM7_DestroyCurrentThread();
}
void ARM7_DestroyCurrentThread(void)
{
 ProcessorContext *thread=*ARM7_ThreadGlobals.active;
 int state;
 ARM7_LockThreadSwitch();
 ARM7_UnlockAllMutexesLockedByContext(thread);
 if(thread->container) ARM7_RemoveBlockedThread(thread->container,thread);
 ARM7_RemoveThreadGlobal(thread);
 thread->state=2;
 ARM7_UnblockThreads(&thread->joinWaiters);
 ARM7_UnlockThreadSwitch();
 state=ARM7_DisableIRQInterrupts();
 ARM7_SwitchThread();
 ARM7_SetIRQInterruptState(state);
 ARM7_Terminate();
}
