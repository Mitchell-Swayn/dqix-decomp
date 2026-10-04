/* Validate the removal command and quiesce hardware before termination. */
#pragma dont_inline on
extern void ARM7_ResetDmaChannel(int);
extern void ARM7_TerminationCleanup(void*);
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_PowerOffSound(void);
extern void ARM7_DisableWirelessPower(void);
extern void ARM7_Terminate(void);
extern void ARM7_Panic(const char*,int,const char*,...);
extern const char ARM7_CardRemovalFile[],ARM7_CardRemovalCommandError[];
void ARM7_CardRemovalCallback(int channel,unsigned int message,int flag)
{
 if((message&0x3f)==1) {
  int state;
  ARM7_ResetDmaChannel(0);
  ARM7_ResetDmaChannel(1);
  ARM7_ResetDmaChannel(2);
  ARM7_ResetDmaChannel(3);
  ARM7_TerminationCleanup(0);
  state=ARM7_DisableIRQInterrupts();
  ARM7_PowerOffSound();
  ARM7_DisableWirelessPower();
  ARM7_SetIRQInterruptState(state);
  ARM7_Terminate();
 }else ARM7_Panic(ARM7_CardRemovalFile,0x85,ARM7_CardRemovalCommandError);
}
