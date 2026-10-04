/* Reset command handshake, status and quiescing before boot handoff. */
#pragma dont_inline on
typedef struct { unsigned short initialized,requested; } ResetState;
ResetState ARM7_ResetState;
extern const char ARM7_ResetSourceFile[],ARM7_ResetUnknownCommand[];
extern void ARM7_SetIpcHandler(int,void(*)(int,unsigned int,int));
extern void ARM7_Panic(const char*,int,const char*,...);
extern unsigned int ARM7_SetSpecificInterruptsEnabled(unsigned int);
extern unsigned int ARM7_AcknowledgeSpecificInterrupts(unsigned int);
extern void ARM7_ResetDmaChannel(int);
extern void ARM7_ResetSoundChannels(void);
extern int ARM7_SendIpcCommand(int,unsigned int,int);
extern void ARM7_ResetBootHandoff(void);
void ARM7_ResetIpcCallback(int,unsigned int,int);
void ARM7_InitializeReset(void)
{
 if(!ARM7_ResetState.initialized){
  ARM7_ResetState.initialized=1;
  ARM7_SetIpcHandler(12,ARM7_ResetIpcCallback);
 }
}
int ARM7_IsResetRequested(void)
{
 return ARM7_ResetState.requested;
}
void ARM7_ResetIpcCallback(int channel,unsigned int message,int error)
{
 unsigned short command=(message&0x7f00)>>8;
 if(command==16)ARM7_ResetState.requested=1;
 else ARM7_Panic(ARM7_ResetSourceFile,0xe7,ARM7_ResetUnknownCommand);
}
void ARM7_SoftReset(void)
{
 ARM7_SetSpecificInterruptsEnabled(0x40000);
 ARM7_AcknowledgeSpecificInterrupts(~0);
 ARM7_ResetDmaChannel(0);ARM7_ResetDmaChannel(1);ARM7_ResetDmaChannel(2);ARM7_ResetDmaChannel(3);
 ARM7_ResetSoundChannels();
 while(ARM7_SendIpcCommand(12,0x1000,0)!=0){}
 *(volatile unsigned short*)0x04000208=0;
 ARM7_ResetBootHandoff();
}
