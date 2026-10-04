/* Suspend power services until a selected hardware wake source resumes the CPU. */
#pragma dont_inline on
#include "PowerState.h"
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern unsigned int ARM7_DisableSpecificInterrupts(unsigned int);
extern unsigned int ARM7_EnableSpecificInterrupts(unsigned int);
extern unsigned int ARM7_SetSpecificInterruptsEnabled(unsigned int);
extern unsigned int ARM7_ReadPowerRegister(unsigned int);
extern void ARM7_WritePowerRegister(unsigned int,unsigned int);
extern void ARM7_SetPowerLedPattern(int);
extern void ARM7_SetPowerLedMode(int);
extern void ARM7_PowerOffSound(void);
extern void ARM7_PowerOnSound(void);
extern void ARM7_ClearPowerControlBits(unsigned int);
extern void ARM7_SetPowerControlBits(unsigned int);
extern unsigned int ARM7_ExecutePowerCommand(int,int);
extern void ARM7_UpdateGPIOControl(unsigned int,unsigned int);
extern void ARM7_SetGPIOControlMode(unsigned int);
extern void ARM7_SleepUntilInterrupt(void);
extern void ARM7_SendPowerNotification(unsigned int,unsigned int);
#define IME (*(volatile unsigned short*)0x04000208)
#define KEYCNT (*(volatile unsigned short*)0x04000132)
#define GPIOCONTROL (*(volatile unsigned short*)0x04000134)
void ARM7_EnterPowerSleep(unsigned int sources,unsigned int keys,unsigned int restore)
{
 int irq;
 unsigned int gpio;
 int restoreGPIO=0;
 unsigned int oldIME=IME;
 unsigned int enabled,control;
 IME=0;
 irq=ARM7_DisableIRQInterrupts();
 enabled=ARM7_DisableSpecificInterrupts(~0xfe000000);
 control=ARM7_ReadPowerRegister(0);
 ARM7_SetPowerLedPattern(2);
 ARM7_SetPowerLedMode(2);
 ARM7_SetPowerLedMode(2);
 ARM7_PowerOffSound();
 ARM7_ClearPowerControlBits(1);
 if(sources&1) {
  KEYCNT=keys|0x4000;
  ARM7_EnableSpecificInterrupts(0x1000);
 }
 if(sources&4)ARM7_EnableSpecificInterrupts(0x400000);
 if(sources&2) {
  gpio=GPIOCONTROL;
  restoreGPIO=1;
  ARM7_SetGPIOControlMode(0x8000);
  ARM7_UpdateGPIOControl(0x40,0);
  ARM7_UpdateGPIOControl(0x100,0x100);
  ARM7_EnableSpecificInterrupts(0x80);
 }
 if(sources&8)ARM7_EnableSpecificInterrupts(0x100000);
 if(sources&16)ARM7_EnableSpecificInterrupts(0x2000);
 ARM7_SetIRQInterruptState(irq);
 (void)IME;
 IME=1;
 ARM7_SleepUntilInterrupt();
 ARM7_WritePowerRegister(0,control);
 {
  int amp=(restore&0x40)?6:7;
  int speaker=(restore&0x80)?4:5;
  ARM7_ExecutePowerCommand(amp,0);
  ARM7_ExecutePowerCommand(speaker,0);
 }
 if(restoreGPIO)GPIOCONTROL=gpio;
 ARM7_SetPowerControlBits(1);
 ARM7_PowerOnSound();
 ARM7_PowerRequest.operation=0;
 ARM7_SendPowerNotification(0x63,0);
 ARM7_DisableIRQInterrupts();
 ARM7_SetSpecificInterruptsEnabled(enabled);
 ARM7_SetIRQInterruptState(irq);
 (void)IME;
 IME=oldIME;
}
