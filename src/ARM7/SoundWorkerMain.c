/* Initialize sound services and consume blocking worker notifications forever.
 * Message 1 requests a timed update; message 2 leaves the tick flag clear.
 * Opaque subsystem routines retain call-site names until independently recovered. */
#pragma dont_inline on
typedef unsigned long long Tick;
typedef struct MessageQueue MessageQueue;
typedef struct Alarm Alarm;
extern MessageQueue ARM7_SoundWorkerQueue;
extern void *ARM7_SoundWorkerMessages[8];
extern Alarm ARM7_SoundWorkerAlarm;
extern void ARM7_InitializeMessageQueue(MessageQueue*,void**,int);
extern void ARM7_ZeroInitializeAlarm(Alarm*);
extern void ARM7_InitializeSoundChannels(void);
extern void ARM7_SoundWorkerInitializeA(void);
extern void ARM7_SoundWorkerInitializeB(void);
extern void ARM7_EnableSoundMaster(void);
extern void ARM7_SetSoundOutputRouting(unsigned int,unsigned int,unsigned int,unsigned int);
extern void ARM7_SetSoundMasterVolume(unsigned int);
extern Tick ARM7_GetCurrentTimestamp(void);
extern void ARM7_SetInterval(Alarm*,Tick,Tick,void(*)(void*),void*);
extern void ARM7_SoundWorkerAlarmCallback(void*);
extern int ARM7_ReceiveMessage(MessageQueue*,void**,int);
extern void ARM7_ApplySoundChannelUpdates(void);
extern void ARM7_SoundWorkerUpdateA(void);
extern void ARM7_SoundWorkerUpdateB(int);
extern void ARM7_SoundWorkerUpdateChannels(int);
extern void ARM7_SoundWorkerUpdateC(void);
extern unsigned short ARM7_NextSoundRandom(void);
void ARM7_SoundWorkerMain(void *argument)
{
 void *message;
 Tick now;
 ARM7_InitializeMessageQueue(&ARM7_SoundWorkerQueue,ARM7_SoundWorkerMessages,8);
 ARM7_ZeroInitializeAlarm(&ARM7_SoundWorkerAlarm);
 ARM7_InitializeSoundChannels();
 ARM7_SoundWorkerInitializeA();
 ARM7_SoundWorkerInitializeB();
 ARM7_EnableSoundMaster();
 ARM7_SetSoundOutputRouting(0,0,0,0);
 ARM7_SetSoundMasterVolume(127);
 now=ARM7_GetCurrentTimestamp();
 ARM7_SetInterval(&ARM7_SoundWorkerAlarm,now+0x10000,0xaa8,ARM7_SoundWorkerAlarmCallback,0);
 for(;;){
  int tick=0;
  ARM7_ReceiveMessage(&ARM7_SoundWorkerQueue,&message,1);
  switch((unsigned int)message){case 1:tick=1;break;case 2:break;}
  ARM7_ApplySoundChannelUpdates();
  ARM7_SoundWorkerUpdateA();
  ARM7_SoundWorkerUpdateB(tick);
  ARM7_SoundWorkerUpdateChannels(tick);
  ARM7_SoundWorkerUpdateC();
  ARM7_NextSoundRandom();
 }
}
