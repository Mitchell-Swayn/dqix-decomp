#include <globaldefs.h>
#include <System/Memory.h>
#include <System/ProcessorContext.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int System_DispatchPendingRequestByTypeAndFlags(unsigned*);
extern "C" void Memory_ProcessBufferedRequest(unsigned);
extern "C" void* Memory_PopBufferedRequest(void*);
extern "C" int Network_CopyAvailableSocketReceiveData(void*,void*,int,unsigned short*,unsigned*);
// Original: arm9/ov031 @ 0x02205D10; symbol: func_ov031_02205d10; size: 0x150.
// Waits for receive progress, copies a blocking command's output, and releases consumed storage.
extern "C" int Network_ExecuteBlockingSocketReceive(void* object)
{
 unsigned char* request=(unsigned char*)object;
 unsigned char* self=*(unsigned char**)(request+4);
 unsigned char* owner=*(unsigned char**)(self+0x64);
 unsigned baseline;
 unsigned count;
 void* destination=*(void**)(request+0x10);
 count=*(unsigned*)(request+0x14);
 unsigned short* port=*(unsigned short**)(request+0x18);
 unsigned* address=*(unsigned**)(request+0x1c);
 baseline=*(unsigned*)(owner+0xf8);
 unsigned available;
 int result=0;
 // Dispatcher owns an int return; preserve its bits as an ARM32 address word.
 unsigned data;
 for(;;){
  data=(unsigned)System_DispatchPendingRequestByTypeAndFlags(&available);
  if(!data||(int)(available-baseline)>0)break;
  int mode=*(signed char*)(self+0x73);
  int stream=1;if(mode!=0&&mode!=4)stream=0;
  if(stream&&self[8]!=4){data=0;break;}
  SleepCurrentContext(10);
 }
 if(*(short*)(self+0x70)&0x80)return -15;
 if(*(signed char*)(self+0x73)==4){
  if(!data)return 0;
  if(count>available)count=available;
  MI_CpuCopy8((void*)data,destination,count);
  Memory_ProcessBufferedRequest(count);
  return count;
 }
 if(data)result=Network_CopyAvailableSocketReceiveData(self,destination,count,port,address);
 else result=0;
 if(result<=0)return result;
 if(*(int*)(owner+0xf8)>=*(unsigned short*)(owner+0xfc))Memory_PopBufferedRequest(self);
 return result;
}
