// Original data alias: arm9/main @ 0x2111644; symbol: data_02111644.
// Upper 32 bits of OS_TimerOverflowCount, at OS_TimerState + 12. Initially zero; runtime contents are mutable.
// Initial values (hex for initialized storage): zero-filled at load; mutable at runtime.
#pragma once

#include "std_library_functions.h"
#include <globaldefs.h>

#if defined(jpn)
#define MarkAlarmInitializationFlagBit_UnknownRoleZeroInitializedStorage data_021112d4
#define OS_TimerState data_021112d8
#define OS_TimerOverflowCountHighWord data_021112e4
#define CancelAlarm_UnknownRoleZeroInitializedStorage data_021112e8
#endif

struct ProcessorContext;

// sizeof == 44 == 0x2C
struct Alarm
{
    // parameter might be a generic userdata pointer
    typedef void (*PFNCompletion)(ProcessorContext**);

    PFNCompletion completionProc;
    ProcessorContext** ppContext;
    unsigned int unknown_8;
    uint64_t alarmTime; // timestamp at which this alarm 'rings' i.e. the completion proc runs
    Alarm* pPrev;
    Alarm* pNext;
    uint64_t alarmIntervalLength;
    uint64_t alarmIntervalResidue; // if e.g. length = 5 and residue = 2, then the 
                                   // alarm sounds when global tick counter = 2, 7, 12, 17, ...
};

// Original data: arm9/main @ 0x2111634; symbol: data_02111634.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short MarkAlarmInitializationFlagBit_UnknownRoleZeroInitializedStorage;

struct Timer64Bit
{
    unsigned short isInitialized;
    int reloadTimerOnNextInterrupt;
    volatile uint64_t numTimerOverflows;
};

// Original data: arm9/main @ 0x2111638; symbol: data_02111638.
// Timer-0 overflow accounting and deferred counter reload state, represented by Timer64Bit. Initially zero; runtime fields are mutable.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Timer64Bit OS_TimerState;

struct ActiveAlarmList
{
    unsigned short isInitialized; 
    Alarm* pFirstAlarm;
    Alarm* pLastAlarm;
};

// Original data: arm9/main @ 0x2111648; symbol: data_02111648.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern ActiveAlarmList CancelAlarm_UnknownRoleZeroInitializedStorage;

#define TIMER_TICKS_PER_MILLISECOND 33514 // approximate, should be 33513.982

void MarkAlarmInitializationFlagBit(int);

void Initialize64BitTimer();
int Is64BitTimerInitialized();
void On16BitTimerOverflow(int);

uint64_t GetCurrentTimestamp();
unsigned short GetMain16BitTimerCounter();

void MarkNextAlarmToSound(Alarm* timing);

void InitializeActiveAlarmList();
int IsAlarmListInitialized();
void ZeroInitializeAlarm(Alarm* alarm);
// Registers for a single activation, so interval alarms will have to repeatedly
// call this (the interrupt handler sorts this out). ringTime is ignored for
// interval alarms.
void RegisterAlarm(Alarm* alarm, uint64_t ringTime);

void SetTimeout(Alarm* alarm, uint64_t delay, Alarm::PFNCompletion callback, ProcessorContext** ppContext);
void SetInterval(Alarm* alarm, uint64_t residue, uint64_t interval,
    Alarm::PFNCompletion callback, ProcessorContext** ppContext);
void CancelAlarm(Alarm* alarm);

void Timer1OverflowInterruptRoutine(int); // not sure if void() or void(int) or int(int)
void HandleTimer1Overflow();