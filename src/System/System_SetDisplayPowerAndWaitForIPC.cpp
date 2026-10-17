#include <globaldefs.h>
ARM
extern "C" void OS_SpinWait(unsigned);
extern "C" void System_WaitForInterruptOneAfterShortDelay();
extern "C" unsigned MapModeToCommandSelectorOrInvalidFFFF(int,unsigned,unsigned);
extern "C" int IPC_RunSynchronousCommandAndReturnReply(int);
extern "C" unsigned IPC_SendCommandSixteenWhenReady(unsigned);
extern "C" unsigned data_021117ec[];
// Original: arm9/main @ 0x020CEBA8; symbol: func_020ceba8; size: 0x218.
extern "C" int System_SetDisplayPowerAndWaitForIPC(int power,int command,int force,int synchronous) {
 switch(power) {
 case 1:
  if(!force) {
   if(*(volatile unsigned*)0x027ffc3c-data_021117ec[1]<=7) return 0;
  }
  if(command) {
   if(synchronous) {
    while(IPC_RunSynchronousCommandAndReturnReply(command)) OS_SpinWait(0xa3a47);
   } else {
    while(MapModeToCommandSelectorOrInvalidFFFF(command,0,0)) OS_SpinWait(0xa3a47);
   }
  }
  *(volatile unsigned short*)0x04000304|=1;
  while(IPC_SendCommandSixteenWhenReady(data_021117ec[4])) OS_SpinWait(0xa3a47);
  break;
 case 0:
  while(IPC_SendCommandSixteenWhenReady(0)) OS_SpinWait(0xa3a47);
  if(*(volatile unsigned*)0x027ffc3c-data_021117ec[2]<=2) {
   System_WaitForInterruptOneAfterShortDelay();
   System_WaitForInterruptOneAfterShortDelay();
  }
  *(volatile unsigned short*)0x04000304&=~1;
  data_021117ec[1]=*(volatile unsigned*)0x027ffc3c;
  if(command) {
   if(synchronous) {
    while(IPC_RunSynchronousCommandAndReturnReply(command)) OS_SpinWait(0xa3a47);
   } else {
    while(MapModeToCommandSelectorOrInvalidFFFF(command,0,0)) OS_SpinWait(0xa3a47);
   }
  }
  break;
 }
 return 1;
}
