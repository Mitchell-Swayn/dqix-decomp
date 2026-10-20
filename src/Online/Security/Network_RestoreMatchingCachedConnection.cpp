#include <globaldefs.h>
#include <System/Memory.h>
ARM
struct Cache {char first[0x20];char second[0x30];unsigned timestamp,address;unsigned short port;unsigned char valid,pad;};
// Original data: arm9/ov031 @ 0x224e3b8; symbol: data_ov031_0224e3b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 368 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern Cache MemoryZeroBlock170_UnknownRoleZeroInitializedStorage[4];unsigned long long _Z19GetCurrentTimestampv();int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);}
// Original: arm9/ov031 @ 0x02207AA4; symbol: func_ov031_02207aa4; size: 0xA0.
extern "C" void Network_RestoreMatchingCachedConnection(unsigned char* p,unsigned address,unsigned short port){
int irq=_Z20DisableIRQInterruptsv();p[0x30]=0;
Cache* entry=MemoryZeroBlock170_UnknownRoleZeroInitializedStorage;int i=0;
do{
if(entry->valid && entry->address==address && entry->port==port){
MI_CpuCopy8(entry,p+0x74,0x20);MI_CpuCopy8(entry->second,p,0x30);
entry->timestamp=_Z19GetCurrentTimestampv()>>16;
p[0x30]=1;break;
}
i++;entry++;
}while(i<4);
_Z20SetIRQInterruptStatei(irq);
}
