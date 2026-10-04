/* Sound IPC transport initialization and interrupt-protected command receipt. */
#pragma dont_inline on
typedef struct SoundMessageQueue SoundMessageQueue;
extern SoundMessageQueue ARM7_SoundCommandQueue;
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern int ARM7_SendMessage(SoundMessageQueue*,void*,int);
extern void ARM7_NotifySoundWorker(void);
void ARM7_SoundCommandIpcCallback(int,unsigned int,int);
void ARM7_SoundCommandIpcCallback(int channel,unsigned int message,int error)
{
 int state=ARM7_DisableIRQInterrupts();
 if(message>=0x02000000)ARM7_SendMessage(&ARM7_SoundCommandQueue,(void*)message,0);
 else if(message==0)ARM7_NotifySoundWorker();
 ARM7_SetIRQInterruptState(state);
}
