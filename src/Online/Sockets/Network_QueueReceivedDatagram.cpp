#include <globaldefs.h>
ARM
extern "C" int MI_CpuCopy8(...);
extern "C" int _Z15UnblockContextsP18BlockedContextList(...);
extern "C" int _Z20DisableIRQInterruptsv(...);
extern "C" int _Z20SetIRQInterruptStatei(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkCleanupSocketStack_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x224e224; symbol: data_ov031_0224e224.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
struct Counters{int allocation,capacity;};extern "C" Counters NetworkQueueReceivedDatagram_UnknownRoleZeroInitializedStorage;

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0220603C; symbol: EnqueueReceivedDatagramAndWakeBlockedContexts.
extern "C" int Network_QueueReceivedDatagram(char*data,unsigned size,char*context){
char*owner=P(context,100);char*packet;int irq=_Z20DisableIRQInterruptsv();if(H(owner+256,10)>=H(owner+256,8)+size){typedef char*(*Allocator)(unsigned);packet=((Allocator)P(P(NetworkCleanupSocketStack_UnknownRoleInitializedBytes,0),24))(size+12);if(packet){struct Buffer{char pad[8];unsigned short used,capacity;inline unsigned short Read(){return used;}inline void Write(unsigned short value){used=value;}};unsigned used=((Buffer*)(owner+256))->Read();((Buffer*)(owner+256))->Write(used+size);W(packet,0)=0;H(packet,4)=size;H(packet,6)=H(context,24);W(packet,8)=W(context,28);MI_CpuCopy8(data,packet+12,size);if(P(owner,256))P(*(char* volatile*)(owner+256),0)=packet;P(owner,256)=packet;if(!P(owner,260))P(owner,260)=packet;}else NetworkQueueReceivedDatagram_UnknownRoleZeroInitializedStorage.allocation++;}else NetworkQueueReceivedDatagram_UnknownRoleZeroInitializedStorage.capacity++;if(!H(context,116))H(context,116)=H(context,10);H(context,24)=H(context,26);W(context,28)=W(context,32);_Z15UnblockContextsP18BlockedContextList(owner+268);_Z20SetIRQInterruptStatei(irq);return 1;
}
