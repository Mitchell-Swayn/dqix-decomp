/* Execute queued power requests while owning the shared SPI service. */
#pragma dont_inline on
#include "SpiService.h"
#include "PowerState.h"
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern int ARM7_IsSpiServiceAvailable(int);
extern void ARM7_AcquireSpiService(int);
extern void ARM7_ReleaseSpiService(int);
extern void ARM7_SendPowerReply(unsigned int,unsigned int,int);
extern int ARM7_SendIpcCommand(int,int,int);
extern void ARM7_EnterPowerSleep(unsigned int,unsigned int,unsigned int);
extern unsigned int ARM7_ExecutePowerCommand(int,int);
extern void ARM7_SetPowerLedMode(int);
void ARM7_ExecutePowerTask(SpiTask *task)
{
 int state=ARM7_DisableIRQInterrupts();
 if(!ARM7_IsSpiServiceAvailable(3)) {
  ARM7_SetIRQInterruptState(state);
  ARM7_SendPowerReply((unsigned short)task->command,0xffff,1);
  return;
 }
 ARM7_AcquireSpiService(3);
 ARM7_SetIRQInterruptState(state);
 switch(task->command) {
 case 0x62:
  while(ARM7_SendIpcCommand(8,0x0300e200,0)<0) {}
  ARM7_PowerState.operation=1;
  ARM7_EnterPowerSleep(task->arguments[0]&0x1f,task->arguments[1],task->arguments[0]&0xc0);
  break;
 case 0x61:
  {
   unsigned int command,value;
   ARM7_PowerState.operation=2;
   command=task->arguments[0];value=task->arguments[1];
   if(command==14)while(ARM7_SendIpcCommand(8,0x0300e100,0)<0) {}
   value=ARM7_ExecutePowerCommand(command,(unsigned short)value);
   ARM7_SendPowerReply(0x61,value,0);
  }
  break;
 case 0x64:ARM7_SetPowerLedMode(task->arguments[0]);break;
 default:ARM7_SendPowerReply((unsigned short)task->command,1,0);break;
 }
 ARM7_ReleaseSpiService(3);
}
