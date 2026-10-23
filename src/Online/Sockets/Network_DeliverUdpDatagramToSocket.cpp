#include <globaldefs.h>
#include <System/ProcessorContext.h>
#include <System/Interrupts.h>
#include <System/Memory.h>
ARM
#pragma always_inline on
#pragma optimization_level 3
#pragma optimize_for_size off
#define F(T,p,o) (*(T*)((unsigned char*)(p)+(o)))
extern "C" int System_CheckCombinedFieldValue(void*,unsigned,void*,unsigned);
inline int SwapHalf(int value) { return (value >> 8) | (value << 8); }
inline unsigned ReadAddress(void* p,int offset) {
 int low=F(unsigned short,p,offset+2),high=F(unsigned short,p,offset);
 return ((unsigned)(unsigned short)SwapHalf(high)<<16)|(unsigned short)SwapHalf(low);
}
// Original: arm9/ov031 @ 0x0220296C; symbol: func_ov031_0220296c; size: 0x20C.
// Validates a UDP checksum, selects the matching thread socket, copies the payload,
// and wakes its waiter or invokes its receive callback while IRQs are disabled.
extern "C" void Network_DeliverUdpDatagramToSocket(void* ip,void* udp,unsigned length)
{
 if(F(unsigned short,udp,6) && System_CheckCombinedFieldValue(udp,length,ip,17))return;
 char* socket;
 int irq=DisableIRQInterrupts();
 char* thread=F(char*,&OSInitThread_UnknownRoleZeroInitializedStorage_Variant2,8);
 if(thread)do {
  socket=F(char*,thread,0xa4);
  if(socket && F(ProcessorContext*,socket,0) && F(unsigned char,socket,8)==10
    && F(unsigned short,socket,10)==(unsigned short)SwapHalf(F(unsigned short,udp,2))
    && (!F(unsigned short,socket,0x18) || F(unsigned short,socket,0x18)==(unsigned short)SwapHalf(F(unsigned short,udp,0)))
    && (!F(unsigned,socket,0x1c) || F(unsigned,socket,0x1c)==0xffffffffU || F(unsigned,socket,0x1c)==ReadAddress(ip,12))) {
   F(unsigned,socket,0x14)=ReadAddress(ip,16);
   if(!F(unsigned,socket,0x1c)){
    F(unsigned,socket,0x1c)=ReadAddress(ip,12);
    F(unsigned short,socket,0x18)=SwapHalf(F(unsigned short,udp,0));
   }
   if(F(unsigned,socket,0x44))break;
   if(length-8>F(unsigned,socket,0x3c))F(unsigned,socket,0x44)=F(unsigned,socket,0x3c);
   else F(unsigned,socket,0x44)=length-8;
   MI_CpuCopy8((unsigned char*)udp+8,F(void*,socket,0x40),F(unsigned,socket,0x44));
   if(F(int,socket,4)==3){F(int,socket,4)=0;MarkContextReadyAndSwitch(F(ProcessorContext*,socket,0));}
   else {
    typedef int (*ReceiveCallback)(char*,unsigned,char*);
    ReceiveCallback callback=F(ReceiveCallback,socket,0x38);
    if(callback && callback(F(char*,socket,0x40),F(unsigned,socket,0x44),socket))F(unsigned,socket,0x44)=0;
   }
   break;
  }
  thread=F(char*,thread,0x68);
 }while(thread);
 SetIRQInterruptState(irq);
}
