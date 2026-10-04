/* Create the sound worker once, control its recurring alarm, and post a
 * nonblocking notification. Externals name field views into the owned state
 * aggregate; the linker records their observed addresses explicitly. */
#pragma dont_inline on
typedef unsigned long long Tick;
typedef struct MessageQueue MessageQueue;
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
struct Alarm { void (*callback)(void*); void *argument; unsigned int unknown8; Tick time; Alarm *previous,*next; Tick interval,residue; };
struct MessageQueue { BlockedContextList sendWaiters,receiveWaiters; void **messages; int capacity,head,count; };
typedef struct { unsigned int initialized; void *messages[8]; MessageQueue queue; Alarm alarm; ProcessorContext thread; unsigned char stack[0x400]; } SoundWorkerState;
typedef char SoundWorkerSizeCheck[sizeof(SoundWorkerState) == 0x514 ? 1 : -1];
typedef char SoundWorkerThreadOffsetCheck[(unsigned int)&((SoundWorkerState*)0)->thread == 0x70 ? 1 : -1];
SoundWorkerState ARM7_SoundWorkerState;

extern unsigned int ARM7_SoundWorkerInitialized;
extern ProcessorContext ARM7_SoundWorkerThread;
extern char ARM7_SoundWorkerStackTop[];
extern Alarm ARM7_SoundWorkerAlarm;
extern MessageQueue ARM7_SoundWorkerQueue;
extern void ARM7_InitializeSoundWorkerPlatform(void);
extern void ARM7_CreateThread(ProcessorContext*,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
extern void ARM7_MarkThreadReady(ProcessorContext*);
extern Tick ARM7_GetCurrentTimestamp(void);
extern void ARM7_SetInterval(Alarm*,Tick,Tick,void(*)(void*),void*);
extern void ARM7_CancelAlarm(Alarm*);
extern int ARM7_SendMessage(MessageQueue*,void*,int);
extern void ARM7_SoundWorkerMain(void*);
void ARM7_SoundWorkerAlarmCallback(void*);
void ARM7_InitializeSoundWorker(unsigned int priority)
{
 if(ARM7_SoundWorkerInitialized)return;
 ARM7_SoundWorkerInitialized=1;
 ARM7_InitializeSoundWorkerPlatform();
 ARM7_CreateThread(&ARM7_SoundWorkerThread,(unsigned int)ARM7_SoundWorkerMain,0,(unsigned int)ARM7_SoundWorkerStackTop,0x400,priority);
 ARM7_MarkThreadReady(&ARM7_SoundWorkerThread);
}
void ARM7_StartSoundWorkerAlarm(void)
{
 Tick now=ARM7_GetCurrentTimestamp();
 ARM7_SetInterval(&ARM7_SoundWorkerAlarm,now+0x10000,0xaa8,ARM7_SoundWorkerAlarmCallback,0);
}
void ARM7_StopSoundWorkerAlarm(void)
{
 ARM7_CancelAlarm(&ARM7_SoundWorkerAlarm);
}
void ARM7_NotifySoundWorker(void)
{
 ARM7_SendMessage(&ARM7_SoundWorkerQueue,(void*)2,0);
}
