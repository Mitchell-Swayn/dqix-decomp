#pragma dont_inline on

/* Timer-1 alarm queue. The compiler links the unsigned 64-bit division helper
 * from the preserved runtime. Diagnostic strings also remain binary-owned. */
typedef unsigned long long uint64_t;
typedef long long int64_t;
typedef void (*Callback)(void*);
typedef struct Alarm Alarm;
struct Alarm { Callback completionProc; void* ppContext; unsigned int unknown_8; uint64_t alarmTime; Alarm *pPrev,*pNext; uint64_t alarmIntervalLength,alarmIntervalResidue; };
typedef struct { unsigned short isInitialized; Alarm *pFirstAlarm,*pLastAlarm; } AlarmList;
AlarmList ARM7_ActiveAlarmList;
extern uint64_t ARM7_GetCurrentTimestamp(void);
extern void ARM7_SetTimerOverflowCallback(int,void(*)(int),int);
extern void ARM7_Timer1OverflowInterruptRoutine(int);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern void ARM7_MarkAlarmInitializationFlagBit(int);
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_Panic(const char*,int,const char*,...);
extern const char ARM7_AlarmSourceFile[],ARM7_AlarmAllocationError[];
#define TIMER_N_COUNTER(n) (*(volatile unsigned short*)(0x04000100+4*(n)))
#define TIMER_N_CONTROL(n) (*(volatile unsigned short*)(0x04000102+4*(n)))
#define TIMER_CONTROL_FLAGS_START 0x80
#define TIMER_CONTROL_FLAGS_ENABLE_IRQ_ON_OVERFLOW 0x40
#define TIMER_CONTROL_FLAGS_PRESCALE_64X 1
#define IRQ_MASK_TIMER_1_OVERFLOW 0x10
void ARM7_MarkNextAlarmToSound(Alarm *timing)
{
    int64_t timeRemaining;
    unsigned short counterValue;
    uint64_t now = ARM7_GetCurrentTimestamp();
    TIMER_N_CONTROL(1) = 0;
    timeRemaining = timing->alarmTime - now;
    ARM7_SetTimerOverflowCallback(1, &ARM7_Timer1OverflowInterruptRoutine, 0);
    counterValue = 0;
    if (timeRemaining < 0)
    {
        counterValue = 0xfffe;
    }
    else if (timeRemaining < 0x10000)
    {
        
        counterValue = ~timeRemaining;
    }
    TIMER_N_COUNTER(1) = counterValue;
    TIMER_N_CONTROL(1) = TIMER_CONTROL_FLAGS_START | TIMER_CONTROL_FLAGS_ENABLE_IRQ_ON_OVERFLOW | TIMER_CONTROL_FLAGS_PRESCALE_64X;
    ARM7_EnableSpecificInterrupts(IRQ_MASK_TIMER_1_OVERFLOW);
}

void ARM7_InitializeActiveAlarmList()
{
    if (ARM7_ActiveAlarmList.isInitialized)
        return;

    ARM7_ActiveAlarmList.isInitialized = 1;
    ARM7_MarkAlarmInitializationFlagBit(1);
    ARM7_ActiveAlarmList.pFirstAlarm = 0;
    ARM7_ActiveAlarmList.pLastAlarm = 0;
    ARM7_DisableSpecificInterrupts(IRQ_MASK_TIMER_1_OVERFLOW);
}

int ARM7_IsAlarmListInitialized()
{
    return ARM7_ActiveAlarmList.isInitialized;
}

void ARM7_ZeroInitializeAlarm(Alarm* alarm)
{
    alarm->completionProc = 0;
    alarm->unknown_8 = 0;
}

void ARM7_RegisterAlarm(Alarm* alarm, uint64_t ringTime)
{
    Alarm *loopAlarm, *prevAlarm;
    if (alarm->alarmIntervalLength != 0)
    {
        uint64_t now = ARM7_GetCurrentTimestamp();
        ringTime = alarm->alarmIntervalResidue;
        if (alarm->alarmIntervalResidue < now)
        {
            uint64_t blockCount = (now - alarm->alarmIntervalResidue) / alarm->alarmIntervalLength;
            ringTime = alarm->alarmIntervalResidue + alarm->alarmIntervalLength * (blockCount + 1);
        }
    }
    alarm->alarmTime = ringTime;

    loopAlarm = ARM7_ActiveAlarmList.pFirstAlarm;
    while (loopAlarm != 0)
    {
        if ((int64_t)(ringTime - loopAlarm->alarmTime) < 0)
        {
            alarm->pPrev = loopAlarm->pPrev;
            loopAlarm->pPrev = alarm;
            alarm->pNext = loopAlarm;

            if (alarm->pPrev != 0)
            {
                alarm->pPrev->pNext = alarm;
            }
            else
            {
                ARM7_ActiveAlarmList.pFirstAlarm = alarm;
                ARM7_MarkNextAlarmToSound(alarm);
            }
            return;
        }
        loopAlarm = loopAlarm->pNext;
    }


    // If we get here, this alarm is to go at the end of the list
    alarm->pNext = 0;
    prevAlarm = ARM7_ActiveAlarmList.pLastAlarm;
    ARM7_ActiveAlarmList.pLastAlarm = alarm;
    alarm->pPrev = prevAlarm;
    if (prevAlarm != 0)
    {
        prevAlarm->pNext = alarm;
    }
    else
    {
        ARM7_ActiveAlarmList.pLastAlarm = alarm;
        ARM7_ActiveAlarmList.pFirstAlarm = alarm;
        ARM7_MarkNextAlarmToSound(alarm);
    }
}

void ARM7_SetTimeout(Alarm* alarm, uint64_t numTicks,
    Callback callback, void* ppContext)
{
    int priorState;
    uint64_t now;
    if (alarm == 0 || alarm->completionProc != 0)
        ARM7_Panic(ARM7_AlarmSourceFile, 0x174, ARM7_AlarmAllocationError);

    priorState = ARM7_DisableIRQInterrupts();
    alarm->alarmIntervalLength = 0;
    alarm->completionProc = callback;
    alarm->ppContext = ppContext;

    now = ARM7_GetCurrentTimestamp();
    ARM7_RegisterAlarm(alarm, numTicks + now);
    ARM7_SetIRQInterruptState(priorState);
}

void ARM7_SetInterval(Alarm *alarm, uint64_t residue, uint64_t interval,
    Callback callback, void*ppContext)
{
    int priorState;
    if (alarm == 0 || alarm->completionProc != 0)
        ARM7_Panic(ARM7_AlarmSourceFile, 0x1a2, ARM7_AlarmAllocationError);

    priorState = ARM7_DisableIRQInterrupts();
    alarm->alarmIntervalLength = interval;
    alarm->alarmIntervalResidue = residue;
    alarm->completionProc = callback;
    alarm->ppContext = ppContext;

    ARM7_RegisterAlarm(alarm, 0);
    ARM7_SetIRQInterruptState(priorState);
}

void ARM7_CancelAlarm(Alarm *alarm)
{
    int priorState;
    Alarm *nextAlarm;
    priorState = ARM7_DisableIRQInterrupts();

    if (alarm->completionProc == 0)
    {
        ARM7_SetIRQInterruptState(priorState);
        return;
    }

    nextAlarm = alarm->pNext;
    if (alarm->pNext == 0)
        ARM7_ActiveAlarmList.pLastAlarm = alarm->pPrev;
    else
        alarm->pNext->pPrev = alarm->pPrev;

    if (alarm->pPrev != 0)
        alarm->pPrev->pNext = nextAlarm;
    else // this is the first alarm
    {
        ARM7_ActiveAlarmList.pFirstAlarm = nextAlarm;
        if (nextAlarm != 0)
            ARM7_MarkNextAlarmToSound(nextAlarm);
    }

    alarm->completionProc = 0;
    alarm->alarmIntervalLength = 0;
    ARM7_SetIRQInterruptState(priorState);
}

