#pragma dont_inline on

/* Release one scheduler lock level, returning the old count or zero.
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
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
unsigned int ARM7_UnlockThreadSwitch(void)
{
 int state=ARM7_DisableIRQInterrupts();
 unsigned int previous=0;
 if(ARM7_ThreadGlobals.switchLock){previous=ARM7_ThreadGlobals.switchLock;ARM7_ThreadGlobals.switchLock=previous-1;}
 ARM7_SetIRQInterruptState(state);
 return previous;
}
