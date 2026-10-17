#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
unsigned func_ov031_022006f0(unsigned);
unsigned func_ov031_02200790(unsigned);
unsigned long long _Z19GetCurrentTimestampv();
void MI_CpuCopy8(const void*,void*,unsigned);
extern unsigned char data_ov031_0224c980[];
struct Entry { unsigned address; unsigned char bytes[6]; unsigned short time; };
struct Timestamp { unsigned short value; char pad[10]; };
extern Entry data_ov031_0224ca00[];
extern Timestamp data_ov031_0224ca0a[];
}
// Original: arm9/ov031 @ 0x02200E38; symbol: func_ov031_02200e38; size: 0x13C.
extern "C" void Network_UpdateAddressCache(const void* bytes,unsigned address,int insert){
if(address==0x7f000001 || address==*(unsigned*)(data_ov031_0224c980+0x50))return;
if(!func_ov031_022006f0(address))return;
if(func_ov031_02200790(address))return;
unsigned short now=(unsigned short)(_Z19GetCurrentTimestampv()>>16);
unsigned i=0;
Entry* e=data_ov031_0224ca00;
do {
if(address==e->address){
data_ov031_0224ca0a[i].value=now;
MI_CpuCopy8(bytes,data_ov031_0224ca00[i].bytes,6);
return;
}
e++;i++;
}while(i<8);
if(!insert)return;
unsigned index;int oldest=0;index=oldest;
insert=oldest; Entry* second=data_ov031_0224ca00;
do {
if(!second->address){index=insert;break;}
unsigned age=now-second->time;
if(oldest<(short)age){index=insert;oldest=age&0xffff;}
second++;insert++;
}while((unsigned)insert<8);
data_ov031_0224ca00[index].address=address;
MI_CpuCopy8(bytes,data_ov031_0224ca00[index].bytes,6);
data_ov031_0224ca0a[index].value=now;
}
