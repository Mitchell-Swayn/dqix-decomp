#include <globaldefs.h>
ARM
extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
extern "C" void MIi_CpuClear32(int,void*,unsigned);
extern "C" void MIi_CpuCopy32(const void*,void*,unsigned);
extern "C" void SetGlobalIndexedWordAtOffset18(int,unsigned);
extern "C" int CopyAndSendCachedPayloadToArm7CommandTen(const void*,unsigned);
extern "C" unsigned ReadGlobalOperationContextPointerAt4();
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(unsigned,...);
extern "C" unsigned ReadAlignedSharedBufferSizeWhenReady();
extern "C" int ComputeAlignedSharedPacketBufferSize();
struct Packet { unsigned short command,pad; unsigned buffer,size,arg,receiveSize; unsigned char zero[0x1c]; unsigned char data[0x10]; };
// Original: arm9/main @ 0x020D5684; symbol: func_020d5684; size: 0x170.
extern "C" int Network_SendAlignedBufferRequest(unsigned callback,unsigned buffer,int size,unsigned arg,unsigned short receiveSize,const void* data) {
 Packet packet;
 char* shared=*(char**)(ReadGlobalOperationContextPointerAt4()+4);
 int result=TestCurrentStatusAgainstVariadicAllowedValues(2,7,8);
 if(result) return result;
 _Z24InvalidateDataCacheRangePKvj(shared+0x188,2);
 _Z24InvalidateDataCacheRangePKvj(shared+0xc6,2);
 if(*(unsigned short*)(shared+0x188) && *(unsigned short*)(shared+0xc6)!=1) return 3;
 _Z24InvalidateDataCacheRangePKvj(shared+0xc,4);
 if(*(unsigned*)(shared+0xc)==1) return 3;
 if(size&0x3f) return 6;
 if(receiveSize&0x1f) return 6;
 _Z24InvalidateDataCacheRangePKvj(shared+0x9c,2);
 if(!*(unsigned short*)(shared+0x9c)) {
  if(size<ComputeAlignedSharedPacketBufferSize()) return 6;
  if((int)receiveSize<(int)ReadAlignedSharedBufferSizeWhenReady()) return 6;
 }
 SetGlobalIndexedWordAtOffset18(0xe,callback);
 MIi_CpuClear32(0,&packet,0x40);
 packet.command=0xe; packet.buffer=buffer; packet.size=(unsigned)size>>1; packet.arg=arg; packet.receiveSize=receiveSize;
 MIi_CpuClear32(0,packet.zero,0x1c);
 MIi_CpuCopy32(data,packet.data,0x10);
 result=CopyAndSendCachedPayloadToArm7CommandTen(&packet,0x40);
 if(!result) result=2;
 return result;
}
