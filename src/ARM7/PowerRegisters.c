/* Power-management SPI register transactions and control-bit updates. */
#pragma dont_inline on
#define CONTROL (*(volatile unsigned short*)0x040001c0)
#define DATA (*(volatile unsigned short*)0x040001c2)
void ARM7_WritePowerSpiByte(unsigned int);
void ARM7_WritePowerRegister(unsigned int reg,unsigned int value)
{
 while(CONTROL&0x80) {}
 CONTROL=0x8202;
 CONTROL=0x8802;
 ARM7_WritePowerSpiByte(reg&0xff);
 CONTROL=0x8002;
 DATA=value&0xff;
}
void ARM7_WritePowerSpiByte(unsigned int value)
{
 DATA=value&0xff;
 while(CONTROL&0x80) {}
}
unsigned int ARM7_ReadPowerRegister(unsigned int reg)
{
 while(CONTROL&0x80) {}
 CONTROL=0x8202;
 CONTROL=0x8802;
 ARM7_WritePowerSpiByte((reg|0x80)&0xff);
 CONTROL=0x8002;
 DATA=0;
 while(CONTROL&0x80) {}
 return DATA&0xff;
}
void ARM7_SetPowerControlBits(unsigned int mask)
{
 unsigned int value=ARM7_ReadPowerRegister(0);
 ARM7_WritePowerRegister(0,value|mask);
}
void ARM7_ClearPowerControlBits(unsigned int mask)
{
 unsigned int value=ARM7_ReadPowerRegister(0);
 ARM7_WritePowerRegister(0,(value&~mask)&0xff);
}
