#pragma dont_inline on
extern void ARM7_TerminationCleanup(void*);
extern void ARM7_ResetInterruptDispatch(void);
extern void ARM7_DisableWirelessPower(void);
extern void ARM7_Terminate(void);
extern const char ARM7_CartridgeSourceFile[],ARM7_CartridgeInvalidCommand[];
extern void ARM7_Panic(const char*,int,const char*,...);
/* Channel13 command2 tears down cartridge activity before system termination. */
// Original: arm7/wram @ 0x03807890; symbol: ARM7_CartridgeShutdownReceive.
void ARM7_CartridgeShutdownReceive(int channel,unsigned int message,int error)
{
 if((message&63)==2) {
  ARM7_TerminationCleanup(0);
  ARM7_ResetInterruptDispatch();
  ARM7_DisableWirelessPower();
  ARM7_Terminate();
 } else ARM7_Panic(ARM7_CartridgeSourceFile,0x129,ARM7_CartridgeInvalidCommand);
}
