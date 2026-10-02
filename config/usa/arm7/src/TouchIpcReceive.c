/* Assemble channel-6 touch requests and validate state before queuing work. */
#pragma dont_inline on
#include "TouchState.h"
extern int ARM7_EnqueueSpiTask(int,unsigned int,unsigned short,...);
extern void ARM7_SendSpiReply(int,unsigned int);
void ARM7_TouchIpcReceive(unsigned int message)
{
 int i;
 unsigned short command,first;
 if(message&0x02000000) {
  i=0;
  do {ARM7_TouchRequest.slots[i]=0;i++;} while(i<16);
 }
 ARM7_TouchRequest.slots[(message&0x000f0000)>>16]=message;
 if(message&0x01000000) {
  first=ARM7_TouchState.request.slots[0];
  command=(first&0xff00)>>8;
  switch(command) {
  case 3:
   {
    unsigned short threshold=first&0xff;
    if(!threshold)ARM7_SendSpiReply(3,2);
    else {
     ARM7_TouchState.request.filterThreshold=threshold;
     ARM7_TouchState.request.retryThreshold=threshold;
     ARM7_SendSpiReply(3,0);
    }
   }
   break;
  case 0:
   if(!ARM7_EnqueueSpiTask(0,command,0))ARM7_SendSpiReply(command,4);
   break;
  case 1:
   if(ARM7_TouchState.request.operation)ARM7_SendSpiReply(command,3);
   else {
    unsigned short count=first&0xff;
    if(count==0 || count>4)ARM7_SendSpiReply(command,2);
    else {
     unsigned short scanline=ARM7_TouchState.request.slots[1];
     if(scanline>=0x107)ARM7_SendSpiReply(command,2);
     else if(ARM7_EnqueueSpiTask(0,command,2,count,scanline))ARM7_TouchState.request.operation=1;
     else ARM7_SendSpiReply(command,4);
    }
   }
   break;
  case 2:
   if(ARM7_TouchState.request.operation!=2)ARM7_SendSpiReply(command,3);
   else if(ARM7_EnqueueSpiTask(0,command,0))ARM7_TouchState.request.operation=3;
   else ARM7_SendSpiReply(command,4);
   break;
  default:ARM7_SendSpiReply(command,1);break;
  }
 }
}
