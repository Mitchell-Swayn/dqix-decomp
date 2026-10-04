/* Poll extended input through a periodic alarm and publish its packed bits
 * in shared memory. Initialization requires the timer and alarm list. */
#pragma dont_inline on
typedef unsigned long long Tick;
typedef void (*Callback)(void*);
typedef struct Alarm Alarm;
struct Alarm { Callback callback; void *argument; unsigned int unknown8; Tick time; Alarm *previous,*next; Tick interval,residue; };
typedef char AlarmSizeCheck[sizeof(Alarm) == 44 ? 1 : -1];
typedef struct { unsigned int initialized; Alarm alarm; } InputPollingState;
InputPollingState ARM7_InputPollingState;
extern int ARM7_Is64BitTimerInitialized(void);
extern int ARM7_IsAlarmListInitialized(void);
extern void ARM7_ZeroInitializeAlarm(Alarm*);
extern Tick ARM7_GetCurrentTimestamp(void);
extern void ARM7_SetInterval(Alarm*,Tick,Tick,Callback,void*);
extern void ARM7_SetGPIOControlMode(unsigned int);
void ARM7_PollSharedInput(void*);
int ARM7_InitializeInputPolling(void)
{
 Tick now;
 if(!ARM7_Is64BitTimerInitialized() || !ARM7_IsAlarmListInitialized())return 0;
 if(ARM7_InputPollingState.initialized)return 0;
 ARM7_ZeroInitializeAlarm(&ARM7_InputPollingState.alarm);
 now=ARM7_GetCurrentTimestamp();
 ARM7_SetInterval(&ARM7_InputPollingState.alarm,now+2094,2094,ARM7_PollSharedInput,0);
 ARM7_InputPollingState.initialized=1;
 return 1;
}
void ARM7_PollSharedInput(void *argument)
{
 unsigned int highFlag=0;
 unsigned short input;
 ARM7_SetGPIOControlMode(0x8000);
 input=*(volatile unsigned short*)0x04000136;
 if(input&0x80)highFlag=0x8000;
 *(volatile unsigned short*)0x027fffa8=((input&0xb)<<10)|highFlag;
}
