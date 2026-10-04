/* Route encoded SPI replies by command group and retry negative IPC results. */
#pragma dont_inline on
extern int ARM7_SendIpcCommand(int,int,int);
void ARM7_SendSpiReply(int command,unsigned int value)
{
 int channel;
 unsigned int message;
 switch(command&0x70) {
 case 0:case 0x10:channel=6;break;
 case 0x40:case 0x50:channel=9;break;
 case 0x60:case 0x70:channel=8;break;
 case 0x20:case 0x30:channel=4;break;
 }
 message=0x03000000|(((command&0xff)|0x80)<<8)|(value&0xff);
 while(ARM7_SendIpcCommand(channel,message,0)<0) {}
}
