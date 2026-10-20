#include <globaldefs.h>
ARM
extern "C" void OS_SpinWait(unsigned);
extern "C" void System_WaitForInterruptOneAfterShortDelay();
extern "C" unsigned PowerManagement_SendMappedModeCommand(int,unsigned,unsigned);
extern "C" int IPC_RunSynchronousCommandAndReturnReply(int);
extern "C" unsigned IPC_SendCommandSixteenWhenReady(unsigned);
// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned PMGoSleepMode_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020CEBA8; symbol: func_020ceba8; size: 0x218.
extern "C" int System_SetDisplayPowerAndWaitForIPC(int power,int command,int force,int synchronous) {
 switch(power) {
 case 1:
  if(!force) {
   if(*(volatile unsigned*)0x027ffc3c-PMGoSleepMode_UnknownRoleZeroInitializedStorage[1]<=7) return 0;
  }
  if(command) {
   if(synchronous) {
    while(IPC_RunSynchronousCommandAndReturnReply(command)) OS_SpinWait(0xa3a47);
   } else {
    while(PowerManagement_SendMappedModeCommand(command,0,0)) OS_SpinWait(0xa3a47);
   }
  }
  *(volatile unsigned short*)0x04000304|=1;
  while(IPC_SendCommandSixteenWhenReady(PMGoSleepMode_UnknownRoleZeroInitializedStorage[4])) OS_SpinWait(0xa3a47);
  break;
 case 0:
  while(IPC_SendCommandSixteenWhenReady(0)) OS_SpinWait(0xa3a47);
  if(*(volatile unsigned*)0x027ffc3c-PMGoSleepMode_UnknownRoleZeroInitializedStorage[2]<=2) {
   System_WaitForInterruptOneAfterShortDelay();
   System_WaitForInterruptOneAfterShortDelay();
  }
  *(volatile unsigned short*)0x04000304&=~1;
  PMGoSleepMode_UnknownRoleZeroInitializedStorage[1]=*(volatile unsigned*)0x027ffc3c;
  if(command) {
   if(synchronous) {
    while(IPC_RunSynchronousCommandAndReturnReply(command)) OS_SpinWait(0xa3a47);
   } else {
    while(PowerManagement_SendMappedModeCommand(command,0,0)) OS_SpinWait(0xa3a47);
   }
  }
  break;
 }
 return 1;
}
