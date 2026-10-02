#pragma dont_inline on

/* Create a blocked thread, initialize its stack sentinels and register frame,
 * and clear its queue/mutex/callback state while IRQs are disabled. The two
 * trailing context words remain unknown and are not initialized here. */
#include "ThreadContext.h"
typedef struct { unsigned int unknown0[5],uniqueIDCounter; } ThreadGlobals;
typedef char ContextSizeCheck[sizeof(ProcessorContext) == 0xa4 ? 1 : -1];
extern ThreadGlobals ARM7_ThreadGlobals;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern ProcessorContext* ARM7_InsertThreadGlobal(ProcessorContext*);
extern void ARM7_InitializeThreadRegisters(ProcessorContext*,unsigned int,unsigned int);
extern void ARM7_ThreadReturn(void);
extern void ARM7_FillWords(unsigned int,void*,unsigned int);
void ARM7_CreateThread(ProcessorContext *thread,unsigned int entry,unsigned int userData,unsigned int stackHigh,unsigned int stackSize,unsigned int priority)
{
 int id;
 int state=ARM7_DisableIRQInterrupts();
 id=++ARM7_ThreadGlobals.uniqueIDCounter;
 thread->priority=priority;
 thread->uniqueID=id;
 thread->state=0;
 thread->unknown58=0;
 ARM7_InsertThreadGlobal(thread);
 thread->stackHigh=stackHigh;
 thread->stackLow=stackHigh-stackSize;
 thread->stackReserved=0;
 *(unsigned int*)(thread->stackHigh-4)=0xd73bfdf7;
 *(unsigned int*)thread->stackLow=0xfbdd37bb;
 thread->joinWaiters.first=thread->joinWaiters.last=0;
 ARM7_InitializeThreadRegisters(thread,entry,stackHigh-4);
 thread->registers[0]=userData;
 thread->registers[14]=(unsigned int)ARM7_ThreadReturn;
 ARM7_FillWords(0,(void*)(stackHigh-stackSize+4),stackSize-8);
 thread->blockingMutex=0;
 thread->ownedMutexes.first=0;
 thread->ownedMutexes.last=0;
 thread->exitCallback=0;
 thread->container=0;
 thread->nextBlocked=0;
 thread->previousBlocked=0;
 ARM7_FillWords(0,&thread->unknown88,12);
 thread->sleepAlarm=0;
 ARM7_SetIRQInterruptState(state);
}
