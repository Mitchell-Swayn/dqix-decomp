/* Write the two command words in wire byte order after ROMCTRL is idle. */
#pragma dont_inline on
#define ROMCTRL (*(volatile unsigned int*)0x040001a4)
#define AUXSPI_HIGH (*(volatile unsigned char*)0x040001a1)
#define COMMAND ((volatile unsigned char*)0x040001a8)
void ARM7_SetCardCommand(unsigned int first,unsigned int second)
{
 while(ROMCTRL&0x80000000) {}
 AUXSPI_HIGH=0xc0;
 COMMAND[0]=first>>24;
 COMMAND[1]=first>>16;
 COMMAND[2]=first>>8;
 COMMAND[3]=first;
 COMMAND[4]=second>>24;
 COMMAND[5]=second>>16;
 COMMAND[6]=second>>8;
 COMMAND[7]=second;
}
