#pragma dont_inline on

/* Expire timer-1 alarms, invoke callbacks, and requeue periodic alarms.
 * The interrupt-entry wrapper remains original binary fallback. */
typedef unsigned long long uint64_t;
typedef void (*Callback)(void*);
typedef struct Alarm Alarm;
struct Alarm { Callback completionProc; void* ppContext; unsigned int unknown_8; uint64_t alarmTime; Alarm *pPrev,*pNext; uint64_t alarmIntervalLength,alarmIntervalResidue; };
typedef struct { unsigned short isInitialized; Alarm *pFirstAlarm,*pLastAlarm; } AlarmList;
extern AlarmList ARM7_ActiveAlarmList;
extern uint64_t ARM7_GetCurrentTimestamp(void);
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
#define TIMER_N_CONTROL(n) (*(volatile unsigned short*)(0x04000102+4*(n)))
#define IRQ_MASK_TIMER_1_OVERFLOW 0x10
extern void ARM7_MarkNextAlarmToSound(Alarm*);
extern void ARM7_RegisterAlarm(Alarm*,uint64_t);
void ARM7_HandleTimer1Overflow()
{
    uint64_t now;
    Alarm* firstAlarm;
    TIMER_N_CONTROL(1) = 0;
    ARM7_DisableSpecificInterrupts(IRQ_MASK_TIMER_1_OVERFLOW);
    (*(volatile unsigned int*)0x0380fff8) |= IRQ_MASK_TIMER_1_OVERFLOW;
    now = ARM7_GetCurrentTimestamp();

    firstAlarm = ARM7_ActiveAlarmList.pFirstAlarm;
    if (firstAlarm == 0)
        return;

    if (now < firstAlarm->alarmTime)
    {
        ARM7_MarkNextAlarmToSound(firstAlarm);
    }
    else
    {
        Callback callback;
        Alarm* next = firstAlarm->pNext;
        ARM7_ActiveAlarmList.pFirstAlarm = next;
        if (next == 0)
            ARM7_ActiveAlarmList.pLastAlarm = 0;
        else
            next->pPrev = 0;

        callback = firstAlarm->completionProc;
        if (firstAlarm->alarmIntervalLength == 0)
            firstAlarm->completionProc = 0;
        if (callback != 0)
            callback(firstAlarm->ppContext);
        
        if (firstAlarm->alarmIntervalLength != 0)
        {
            firstAlarm->completionProc = callback;
            ARM7_RegisterAlarm(firstAlarm, 0);
        }

        if (ARM7_ActiveAlarmList.pFirstAlarm != 0)
            ARM7_MarkNextAlarmToSound(ARM7_ActiveAlarmList.pFirstAlarm);
    }
}
