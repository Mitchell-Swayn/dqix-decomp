#include <globaldefs.h>
ARM
extern "C" {
void Network_UpdateGlobalFlagsAtomically(void*);
int Util_FindNextEnabledBitModuloThirteen(int);
unsigned short ComputeHardwareAddressChecksumModuloTen();
void MI_CpuCopy8(const void*,void*,unsigned);
extern char* data_ov031_0224e53c;
extern unsigned char data_ov031_02245fb0[],data_ov031_02245fb8[];
}
// Original: arm9/ov031 @ 0x0220D73C; symbol: func_ov031_0220d73c; size: 0x198.
extern "C" void Network_ConfigureExtendedScanParameters(const void* address,const unsigned char* name,void* config){
Network_UpdateGlobalFlagsAtomically(config);
*(char**)(data_ov031_0224e53c+0x2288)=data_ov031_0224e53c+0x1500;
*(unsigned short*)(data_ov031_0224e53c+0x228c)=0x400;
*(unsigned short*)(data_ov031_0224e53c+0x228e)=(1<<Util_FindNextEnabledBitModuloThirteen(0))>>1;
unsigned short checksum=*(unsigned short*)(data_ov031_0224e53c+0x2268);
if(!checksum)checksum=ComputeHardwareAddressChecksumModuloTen();
*(unsigned short*)(data_ov031_0224e53c+0x2290)=checksum;
*(unsigned short*)(data_ov031_0224e53c+0x2298)=(*(unsigned*)(data_ov031_0224e53c+0x2264)&0x300000)!=0x300000;
if(!address)MI_CpuCopy8(data_ov031_02245fb0,data_ov031_0224e53c+0x2292,6);
else MI_CpuCopy8(address,data_ov031_0224e53c+0x2292,6);
if(!name || name==data_ov031_02245fb8){
MI_CpuCopy8(data_ov031_02245fb8,data_ov031_0224e53c+0x229c,32);
*(unsigned short*)(data_ov031_0224e53c+0x229a)=0;
}else{
MI_CpuCopy8(name,data_ov031_0224e53c+0x229c,32);
int len=0;
do{if(!*name)break;len++;name++;}while(len<32);
*(unsigned short*)(data_ov031_0224e53c+0x229a)=len;
}
*(unsigned*)(data_ov031_0224e53c+0x2284)=0;
}
