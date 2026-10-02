/* Alarm notifications enqueue message 1 without blocking. Queue-full failure
 * dispatches through the observed diagnostic callback; its policy is external. */
#pragma dont_inline on
typedef unsigned long long Tick;
typedef struct ProcessorContext ProcessorContext;
typedef struct Alarm Alarm;
typedef struct MessageQueue MessageQueue;
extern MessageQueue ARM7_SoundWorkerQueue;
extern void (*ARM7_SoundQueueFailureHandler)(const char*);
extern const char ARM7_SoundQueueFailureMessage[];
extern int ARM7_SendMessage(MessageQueue*,void*,int);
void ARM7_SoundWorkerAlarmCallback(void*);
void ARM7_SoundWorkerAlarmCallback(void *argument)
{
 if(!ARM7_SendMessage(&ARM7_SoundWorkerQueue,(void*)1,0))ARM7_SoundQueueFailureHandler(ARM7_SoundQueueFailureMessage);
}
