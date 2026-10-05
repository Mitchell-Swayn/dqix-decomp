/* Encode power replies/notifications and preserve their distinct IPC retry tests. */
#pragma dont_inline on
extern int ARM7_SendIpcCommand(int,int,int);
void ARM7_SendPowerReply(unsigned int command,unsigned int value,int flag)
{
 unsigned int message=0x03000000|(((command&0xff)|0x80)<<8)|(value&0xff);
 while(ARM7_SendIpcCommand(8,message,flag)<0) {}
}
void ARM7_SendPowerNotification(unsigned int command,unsigned int value)
{
 unsigned int message=((command<<8)&0x7f00)|(value&0xff);
 while(ARM7_SendIpcCommand(8,message,0)!=0) {}
}
