#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" char* data_ov031_02290d20;
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" unsigned func_ov031_02239bd4();
extern "C" unsigned Ov031_GetGlobalObjectField40();
extern "C" void* func_ov031_0223a288(unsigned);
extern "C" int Network_ExchangeSharedWirelessPacketAndRecordStatus(void*);
// Original: arm9/ov031 @ 0x0223B0C0; symbol: func_ov031_0223b0c0; size: 0x168.
extern "C" void System_UpdateTwoSlotPacketExchange(unsigned short first,unsigned short second,const void* payload) {
 if(*(unsigned char*)(data_ov031_02290d20+0xa93)==1) {
  *(unsigned short*)*(char**)(data_ov031_02290d20+0xab0)=first;
  *(unsigned short*)(*(char**)(data_ov031_02290d20+0xab0)+2)=second;
  MI_CpuCopy8(payload,*(char**)(data_ov031_02290d20+0xab0)+4,64);
 }else {
  ++*(unsigned*)(data_ov031_02290d20+0x204);
  *(unsigned short*)*(char**)(data_ov031_02290d20+0xab0)=188;
  *(*(char**)(data_ov031_02290d20+0xab0)+4)=*(unsigned char*)(data_ov031_02290d20+0xa92);
 }
 if(Ov031_GetGlobalObjectField40()!=5)return;
 if(!Network_ExchangeSharedWirelessPacketAndRecordStatus(data_ov031_02290d20)) {*(unsigned*)(data_ov031_02290d20+0x204)+=4;return;}
 if(*(unsigned char*)(data_ov031_02290d20+0xa93)==0)++*(unsigned*)(data_ov031_02290d20+0x204);
 else {
  *(unsigned*)(data_ov031_02290d20+0x204)=0;
  if(func_ov031_02239bd4()!=3) {*(unsigned char*)(data_ov031_02290d20+0xa90)=27;return;}
 }
 unsigned short i=0;
 do {
  void* packet=func_ov031_0223a288(i);
  if(packet) {
   MI_CpuCopy8(packet,data_ov031_02290d20+0x100+i*0x44,0x44);
   *(unsigned*)(data_ov031_02290d20+0x208+i*4)=1;
  }else *(unsigned*)(data_ov031_02290d20+0x208+i*4)=0;
  i=(unsigned short)(i+1);
 }while(i<2);
}
