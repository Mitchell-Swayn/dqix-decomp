/* Configure/start/stop tagged sound alarms and deliver their IPC notifications. */
#pragma dont_inline on
typedef unsigned long long Tick;
typedef struct Alarm Alarm;
struct Alarm { void (*callback)(void*); void *argument; unsigned int unknown8; Tick time; Alarm *previous,*next; Tick interval,residue; };
typedef struct { unsigned char active,tag; unsigned short unknown2; Tick delay,interval; Alarm alarm; } SoundAlarmSlot;
typedef char SoundAlarmSlotSizeCheck[sizeof(SoundAlarmSlot)==64?1:-1];
extern SoundAlarmSlot ARM7_SoundAlarmSlots[8];
extern void ARM7_CancelAlarm(Alarm*);
extern void ARM7_ZeroInitializeAlarm(Alarm*);
extern void ARM7_SetTimeout(Alarm*,Tick,void(*)(void*),void*);
extern void ARM7_SetInterval(Alarm*,Tick,Tick,void(*)(void*),void*);
extern Tick ARM7_GetCurrentTimestamp(void);
extern int ARM7_SendIpcCommand(int,unsigned int,int);
void ARM7_SoundAlarmCallback(void*);
void ARM7_ConfigureSoundAlarm(int index,Tick delay,Tick interval,unsigned int tag)
{
 SoundAlarmSlot *slot=&ARM7_SoundAlarmSlots[index];
 if(slot->active){ARM7_CancelAlarm(&slot->alarm);slot->active=0;}
 slot->delay=delay;slot->interval=interval;slot->tag=tag;
}
void ARM7_StartSoundAlarm(int index)
{
 Tick delay,interval; SoundAlarmSlot *slot=&ARM7_SoundAlarmSlots[index];
 unsigned int argument;
 if(slot->active){ARM7_CancelAlarm(&slot->alarm);slot->active=0;}
 argument=index|(slot->tag<<8);delay=slot->delay;interval=slot->interval;
 ARM7_ZeroInitializeAlarm(&slot->alarm);
 if(!interval)ARM7_SetTimeout(&slot->alarm,delay,ARM7_SoundAlarmCallback,(void*)argument);
 else ARM7_SetInterval(&slot->alarm,ARM7_GetCurrentTimestamp()+delay,interval,ARM7_SoundAlarmCallback,(void*)argument);
 slot->active=1;
}
void ARM7_StopSoundAlarm(int index)
{
 SoundAlarmSlot *slot=&ARM7_SoundAlarmSlots[index];
 if(slot->active){ARM7_CancelAlarm(&slot->alarm);slot->tag++;slot->active=0;}
}
void ARM7_SoundAlarmCallback(void *argument)
{
 while(ARM7_SendIpcCommand(7,(unsigned int)argument,0)<0){}
}
