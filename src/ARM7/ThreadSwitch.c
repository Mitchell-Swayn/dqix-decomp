#pragma dont_inline on

/* High-level scheduler decisions and callbacks. Actual register save/restore
 * remains in separately addressed original context routines. No assembly or
 * matching-only code is introduced here. The scheduler header and two context
 * blocks have source-defined storage; unidentified words remain explicit. */
typedef struct ProcessorContext ProcessorContext;
typedef struct Mutex Mutex;
typedef struct Alarm Alarm;
typedef struct { ProcessorContext *first,*last; } BlockedContextList;
typedef struct { Mutex *pFirst,*pLast; } MutexList;
struct ProcessorContext {
 unsigned int status,registers[15],resumeAddress,supervisorStack;
 int state;
 ProcessorContext *pNext;
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
struct Mutex { BlockedContextList waiters; ProcessorContext *owner; int count; Mutex *pNext_,*pPrev_; };
typedef void (*SwitchCallback)(ProcessorContext*,ProcessorContext*);
typedef struct { unsigned short pending,irqDepth; ProcessorContext *active,*first; SwitchCallback callback; } ThreadSystem;
typedef struct { unsigned int unknown0[2]; unsigned int switchLock; unsigned int unknownC[2],uniqueIDCounter; SwitchCallback callback; ProcessorContext **active; unsigned int initialized; ThreadSystem system; ProcessorContext idle,primary; } ThreadGlobals;
typedef char ContextSizeCheck[sizeof(ProcessorContext) == 0xa4 ? 1 : -1];
typedef char SchedulerSizeCheck[sizeof(ThreadGlobals) == 0x17c ? 1 : -1];
typedef char IdleOffsetCheck[(unsigned int)&((ThreadGlobals*)0)->idle == 0x34 ? 1 : -1];
typedef char PrimaryOffsetCheck[(unsigned int)&((ThreadGlobals*)0)->primary == 0xd8 ? 1 : -1];
ThreadGlobals ARM7_ThreadGlobals;
extern ThreadSystem ARM7_ThreadSystem;
extern int ARM7_GetProcessorMode(void);
extern ProcessorContext *ARM7_GetFirstReadyThread(void);
extern int ARM7_SaveThreadContext(ProcessorContext*);
extern void ARM7_RestoreThreadContext(ProcessorContext*);
void ARM7_SwitchThread(void)
{
 ThreadSystem *system;
 ProcessorContext *outgoing,*incoming;
 if(ARM7_ThreadGlobals.switchLock)return;
 system=&ARM7_ThreadSystem;
 if(ARM7_ThreadGlobals.system.irqDepth!=0 || ARM7_GetProcessorMode()==0x12){system->pending=1;return;}
 outgoing=*ARM7_ThreadGlobals.active;
 incoming=ARM7_GetFirstReadyThread();
 if(outgoing==incoming || !incoming)return;
 if(outgoing->state!=2){if(ARM7_SaveThreadContext(outgoing))return;}
 if(ARM7_ThreadGlobals.callback)ARM7_ThreadGlobals.callback(outgoing,incoming);
 if(system->callback)system->callback(outgoing,incoming);
 ARM7_ThreadGlobals.system.active=incoming;
 ARM7_RestoreThreadContext(incoming);
}
