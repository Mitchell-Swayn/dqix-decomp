#ifndef ARM7_THREAD_CONTEXT_H
#define ARM7_THREAD_CONTEXT_H
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
typedef char ProcessorContextSizeCheck[sizeof(ProcessorContext)==0xa4?1:-1];
#endif
