#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" unsigned Network_SelectUnusedEphemeralPort();
extern "C" void Network_SendPendingSpansAndUnblockContexts(void*);
extern "C" char* Network_AllocateSocketCommand(void(*)(void*),void*,unsigned);
extern "C" int Network_SubmitSendCommand(void*,void*);
// Original: arm9/ov031 @ 0x02206410; symbol: func_ov031_02206410; size: 0x174.
extern "C" int Network_QueueRingBufferSend(char* self,char* source,int size,int offset,unsigned short port,unsigned address,unsigned flags) {
 char* state=*(char**)(self+0x68);
 char* request=Network_AllocateSocketCommand(Network_SendPendingSpansAndUnblockContexts,*(void**)(state+0x10c),flags);
 if(!request) return -33;
 if((flags&1) && *(signed char*)(self+0x73)!=1) request[0xd]=3; else request[0xd]=0;
 char* buffer=*(char**)(state+0xfc);
 int capacity=*(int*)(state+0xf8);
 if(offset+size<capacity) {
 *(char**)(request+0x10)=buffer+offset;
 *(int*)(request+0x14)=size;
 *(int*)(request+0x18)=0;
 offset+=size;
 *(int*)(request+0x1c)=0;
 } else {
 *(char**)(request+0x10)=buffer+offset;
 *(int*)(request+0x14)=capacity-offset;
 *(char**)(request+0x18)=buffer;
 offset=size-*(int*)(request+0x14);
 *(int*)(request+0x1c)=offset;
 MI_CpuCopy8(source+*(int*)(request+0x14),*(void**)(request+0x18),offset);
 }
 MI_CpuCopy8(source,*(void**)(request+0x10),*(unsigned*)(request+0x14));
 unsigned short old=*(unsigned short*)(state+0x100);
 *(unsigned short*)(request+0x20)=offset;
 *(unsigned short*)(state+0x100)=*(unsigned short*)(request+0x20);
 if(*(signed char*)(self+0x73)==1) {
 if(!*(unsigned short*)(self+0x74)) {
 *(unsigned short*)(self+0x74)=Network_SelectUnusedEphemeralPort();
 *(unsigned short*)(self+0xa)=*(unsigned short*)(self+0x74);
 }
 *(unsigned short*)(request+0x24)=*(unsigned short*)(self+0x74);
 if(!*(unsigned*)(self+0x78) || address) {
 *(unsigned*)(request+0x28)=address;
 *(unsigned short*)(request+0x26)=port;
 } else {
 *(unsigned*)(request+0x28)=*(unsigned*)(self+0x78);
 *(unsigned short*)(request+0x26)=*(unsigned short*)(self+0x76);
 }
 } else *(unsigned*)(request+0x28)=0;
 if(Network_SubmitSendCommand(*(void**)(state+0x10c),request)) {
 *(unsigned short*)(state+0x100)=old;
 size=0;
 }
 return size;
}
