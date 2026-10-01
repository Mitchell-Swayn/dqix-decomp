#pragma dont_inline on

/* High-level scheduler decisions and callbacks. Actual register save/restore
 * remains in separately addressed original context routines. No assembly or
 * ownership of opaque scheduler storage is introduced here. */
typedef struct ProcessorContext ProcessorContext;
typedef struct Mutex Mutex;
typedef struct { ProcessorContext *first,*last; } BlockedContextList;
typedef struct { Mutex *pFirst,*pLast; } MutexList;
struct ProcessorContext { char registers[0x48]; int state; ProcessorContext *pNext; unsigned int uniqueID,priority,unknown58; BlockedContextList *container; ProcessorContext *pPrevBlocked,*pNextBlocked; };
struct Mutex { BlockedContextList waiters; ProcessorContext *owner; int count; Mutex *pNext_,*pPrev_; };
typedef void (*SwitchCallback)(ProcessorContext*,ProcessorContext*);
typedef struct { unsigned short pending,irqDepth; ProcessorContext *active,*first; SwitchCallback callback; } ThreadSystem;
typedef struct { char unknown[8]; unsigned int switchLock; char unknownC[12]; SwitchCallback callback; ProcessorContext **active; unsigned int unknown20; ThreadSystem system; } ThreadGlobals;
extern ThreadGlobals ARM7_ThreadGlobals;
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
