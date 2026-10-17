#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" void _Z19BlockCurrentContextP18BlockedContextList(void*);
struct Ring {unsigned char pad[0x28];unsigned write;int pad2;unsigned read;unsigned char pad3[0x20];void* blocked;unsigned char* buffer;unsigned capacity;};
extern "C" Ring data_ov031_0224c980;
extern "C" void* data_02111304[];
// Original: arm9/ov031 @ 0x02200AF8; symbol: func_ov031_02200af8; size: 0xC0.
extern "C" unsigned char* Network_WaitForRingRecordAndReturnPayload(unsigned* size){
 int irq=_Z20DisableIRQInterruptsv();
 while(data_ov031_0224c980.read==data_ov031_0224c980.write){
 data_ov031_0224c980.blocked=data_02111304[1];
 _Z19BlockCurrentContextP18BlockedContextList(0);
 data_ov031_0224c980.blocked=0;
 }
 _Z20SetIRQInterruptStatei(irq);
 unsigned char* buffer=data_ov031_0224c980.buffer;
 unsigned length;
 do{
 if(data_ov031_0224c980.capacity-data_ov031_0224c980.read<2)data_ov031_0224c980.read=0;
 length=*(unsigned short*)(buffer+data_ov031_0224c980.read);
 if(!length)data_ov031_0224c980.read=0;
 }while(!length);
 *size=length-2;
 return data_ov031_0224c980.buffer+data_ov031_0224c980.read+2;
}
