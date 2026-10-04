/* Dispatch power-register, sound and LED commands with original query defaults. */
#pragma dont_inline on
extern void ARM7_SetPowerLedPattern(int);
extern void ARM7_SetPowerLedMode(int);
extern int ARM7_GetPowerLedPattern(void);
extern void ARM7_SetPowerControlBits(unsigned int);
extern void ARM7_ClearPowerControlBits(unsigned int);
extern void ARM7_PowerOffSound(void);
extern unsigned int ARM7_ReadPowerRegister(unsigned int);
extern void ARM7_WritePowerRegister(unsigned int,unsigned int);
unsigned int ARM7_ExecutePowerCommand(int command,int value)
{
 switch(command) {
 case 1:ARM7_SetPowerLedPattern(1);ARM7_SetPowerLedMode(1);break;
 case 2:ARM7_SetPowerLedPattern(3);ARM7_SetPowerLedMode(3);break;
 case 3:ARM7_SetPowerLedPattern(2);ARM7_SetPowerLedMode(2);break;
 case 4:ARM7_SetPowerControlBits(4);break;
 case 5:ARM7_ClearPowerControlBits(4);break;
 case 6:ARM7_SetPowerControlBits(8);break;
 case 7:ARM7_ClearPowerControlBits(8);break;
 case 8:ARM7_SetPowerControlBits(12);break;
 case 9:ARM7_ClearPowerControlBits(12);break;
 case 10:ARM7_SetPowerControlBits(1);break;
 case 11:ARM7_ClearPowerControlBits(1);break;
 case 12:ARM7_ClearPowerControlBits(2);break;
 case 13:ARM7_SetPowerControlBits(2);break;
 case 14:ARM7_PowerOffSound();ARM7_SetPowerControlBits(0x40);break;
 case 15:
  switch(value) {
  case 0:return ARM7_ReadPowerRegister(1)&1;
  case 1:return ARM7_ReadPowerRegister(0)&12;
  case 2:return ARM7_ReadPowerRegister(0)&1;
  case 3:return 0;
  case 4:return ARM7_ReadPowerRegister(2)&1;
  case 5:return ARM7_ReadPowerRegister(3)&3;
  case 6:return (unsigned short)ARM7_GetPowerLedPattern();
  default:return 2;
  }
 case 16:ARM7_WritePowerRegister(2,value&1);break;
 case 17:ARM7_WritePowerRegister(3,value&3);break;
 case 18:ARM7_SetPowerLedPattern(value);break;
 case 19:return ARM7_ReadPowerRegister(value);
 case 20:ARM7_WritePowerRegister((value>>8)&0xff,value&0xff);break;
 }
 return 0;
}
