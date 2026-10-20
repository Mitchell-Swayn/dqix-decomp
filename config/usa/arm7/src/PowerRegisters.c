/* Power-management SPI register transactions and control-bit updates. */
#pragma dont_inline on
#define CONTROL (*(volatile unsigned short*)0x040001c0)
#define DATA (*(volatile unsigned short*)0x040001c2)
void ARM7_WritePowerSpiByte(unsigned int);
// Original: arm7/wram @ 0x03805E2C; symbol: ARM7_WritePowerRegister.
void ARM7_WritePowerRegister(unsigned int reg,unsigned int value)
{
 while(CONTROL&0x80) {}
 CONTROL=0x8202;
 CONTROL=0x8802;
 ARM7_WritePowerSpiByte(reg&0xff);
 CONTROL=0x8002;
 DATA=value&0xff;
}
// Original: arm7/wram @ 0x03805E84; symbol: ARM7_WritePowerSpiByte.
void ARM7_WritePowerSpiByte(unsigned int value)
{
 DATA=value&0xff;
 while(CONTROL&0x80) {}
}
// Original: arm7/wram @ 0x03805EA8; symbol: ARM7_ReadPowerRegister.
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
// Original: arm7/wram @ 0x03805F1C; symbol: ARM7_SetPowerControlBits.
void ARM7_SetPowerControlBits(unsigned int mask)
{
 unsigned int value=ARM7_ReadPowerRegister(0);
 ARM7_WritePowerRegister(0,value|mask);
}
// Original: arm7/wram @ 0x03805F40; symbol: ARM7_ClearPowerControlBits.
void ARM7_ClearPowerControlBits(unsigned int mask)
{
 unsigned int value=ARM7_ReadPowerRegister(0);
 ARM7_WritePowerRegister(0,(value&~mask)&0xff);
}
