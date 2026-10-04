/* Assemble channel-8 power requests in sixteen slots, then dispatch the command. */
#pragma dont_inline on
#include "PowerState.h"
extern int ARM7_SendIpcCommand(int,int,int);
extern int ARM7_EnqueueSpiTask(int,unsigned int,unsigned short,...);
extern void ARM7_SendPowerReply(unsigned int,unsigned int,int);
void ARM7_PowerIpcReceive(unsigned int message)
{
 int i;
 unsigned short command,first;
 if(message&0x02000000) {
  i=0;
  do {ARM7_PowerRequest.slots[i]=0;i++;} while(i<16);
 }
 ARM7_PowerRequest.slots[(message&0x000f0000)>>16]=message;
 if(message&0x01000000) {
  first=ARM7_PowerState.request.slots[0];
  command=(first&0xff00)>>8;
  switch(command) {
  case 0x60:
   while(ARM7_SendIpcCommand(8,0x0300e000,0)<0) {}
   break;
  case 0x62:
   if(!ARM7_EnqueueSpiTask(3,command,2,first&0xff,ARM7_PowerState.request.slots[1]))
    ARM7_SendPowerReply(command,0xffff,1);
   break;
  case 0x61:
   if(!ARM7_EnqueueSpiTask(3,command,2,first&0xff,ARM7_PowerState.request.slots[1]))
    ARM7_SendPowerReply(command,0xffff,1);
   break;
  default:ARM7_SendPowerReply(command,1,0);break;
  }
 }
}
