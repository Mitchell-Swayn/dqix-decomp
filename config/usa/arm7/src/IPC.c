#pragma dont_inline on

/* ARM7 FIFO command setup and sending. The 32 handlers and init flag are
 * source-owned BSS; the cross-CPU registration masks are shared system RAM. */
typedef void (*IPCHandler)(int,unsigned int,int);
typedef union { unsigned int word; struct { unsigned int channel:5,flag:1,argument:26; } parts; } IPCCommand;
typedef struct { unsigned short initialized,padding; IPCHandler handlers[32]; } IPCState;
IPCState ARM7_IPCState;
typedef struct { char unknown[0x388]; unsigned int masks[2]; } IPCShared;
extern IPCShared ARM7_SharedSystem;
#define IPC_SHARED (&ARM7_SharedSystem)
#define IPC_SYNC (*(volatile unsigned short*)0x04000180)
#define IPC_CONTROL (*(volatile unsigned short*)0x04000184)
#define IPC_SEND (*(volatile unsigned int*)0x04000188)
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern unsigned int ARM7_AcknowledgeSpecificInterrupts(unsigned int);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
extern void ARM7_SetInterruptHandler(unsigned int,void(*)(int));
extern void ARM7_HandleIPCReceive(int);
extern int ARM7_GetIpcBootMode(void);
extern void ARM7_WaitCycles(int);
int ARM7_SendIpcWord(unsigned int);
void ARM7_InitializeIPC(void)
{
 int state=ARM7_DisableIRQInterrupts();
 if(!ARM7_IPCState.initialized){
  int channel;
  ARM7_IPCState.initialized=1;
  IPC_SHARED->masks[1]=0;
  channel=0;
  do {ARM7_IPCState.handlers[channel]=0;channel++;}while(channel<32);
  IPC_CONTROL=0xc408;
  ARM7_AcknowledgeSpecificInterrupts(0x40000);
  ARM7_SetInterruptHandler(0x40000,ARM7_HandleIPCReceive);
  ARM7_EnableSpecificInterrupts(0x40000);
  if(ARM7_GetIpcBootMode())IPC_SYNC=0x100;
  else {
   int count=8;
   while(count>=0){
    IPC_SYNC=count<<8;
    ARM7_WaitCycles(1000);
    if((IPC_SYNC&15)!=count)count=8;
    count--;
   }
  }
 }
 ARM7_SetIRQInterruptState(state);
}
void ARM7_SetIpcHandler(int channel,IPCHandler handler)
{
 int state=ARM7_DisableIRQInterrupts();
 IPCShared *data=(IPCShared*)0x027ffc00;
 ARM7_IPCState.handlers[channel]=handler;
 if(handler)data->masks[1]|=1<<channel;
 else data->masks[1]&=~(1<<channel);
 ARM7_SetIRQInterruptState(state);
}
int ARM7_IsIpcHandlerRegistered(int channel,int side)
{
 IPCShared *data=(IPCShared*)0x027ffc00;
 return !!(data->masks[side]&(1<<channel));
}
int ARM7_SendIpcCommand(int channel,int argument,int flag)
{
 IPCCommand command;
 command.parts.channel=channel;
 command.parts.flag=flag;
 command.parts.argument=argument;
 return ARM7_SendIpcWord(command.word);
}
int ARM7_SendIpcWord(unsigned int word)
{
 int state;
 if(IPC_CONTROL&0x4000){IPC_CONTROL|=0xc000;return -1;}
 state=ARM7_DisableIRQInterrupts();
 if(IPC_CONTROL&2){ARM7_SetIRQInterruptState(state);return -2;}
 IPC_SEND=word;
 ARM7_SetIRQInterruptState(state);
 return 0;
}
