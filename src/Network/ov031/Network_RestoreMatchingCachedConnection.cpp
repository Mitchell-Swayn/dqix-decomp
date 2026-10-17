#include <globaldefs.h>
#include <System/Memory.h>
ARM
struct Cache {char first[0x20];char second[0x30];unsigned timestamp,address;unsigned short port;unsigned char valid,pad;};
extern "C" {extern Cache data_ov031_0224e3b8[4];unsigned long long _Z19GetCurrentTimestampv();int _Z20DisableIRQInterruptsv();int _Z20SetIRQInterruptStatei(int);}
// Original: arm9/ov031 @ 0x02207AA4; symbol: func_ov031_02207aa4; size: 0xA0.
extern "C" void Network_RestoreMatchingCachedConnection(unsigned char* p,unsigned address,unsigned short port){
int irq=_Z20DisableIRQInterruptsv();p[0x30]=0;
Cache* entry=data_ov031_0224e3b8;int i=0;
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
