#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" unsigned WirelessHost_GetConnectedPeerMask();
extern "C" unsigned WirelessHost_GetSystemState();
extern "C" void* System_ResolvePacketExchangeEntry(unsigned);
extern "C" int Network_ExchangeSharedWirelessPacketAndRecordStatus(void*);
// Original: arm9/ov031 @ 0x0223B0C0; symbol: func_ov031_0223b0c0; size: 0x168.
extern "C" void System_UpdateTwoSlotPacketExchange(unsigned short first,unsigned short second,const void* payload) {
 if(*(unsigned char*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa93)==1) {
  *(unsigned short*)*(char**)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xab0)=first;
  *(unsigned short*)(*(char**)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xab0)+2)=second;
  MI_CpuCopy8(payload,*(char**)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xab0)+4,64);
 }else {
  ++*(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x204);
  *(unsigned short*)*(char**)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xab0)=188;
  *(*(char**)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xab0)+4)=*(unsigned char*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa92);
 }
 if(WirelessHost_GetSystemState()!=5)return;
 if(!Network_ExchangeSharedWirelessPacketAndRecordStatus(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage)) {*(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x204)+=4;return;}
 if(*(unsigned char*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa93)==0)++*(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x204);
 else {
  *(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x204)=0;
  if(WirelessHost_GetConnectedPeerMask()!=3) {*(unsigned char*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa90)=27;return;}
 }
 unsigned short i=0;
 do {
  void* packet=System_ResolvePacketExchangeEntry(i);
  if(packet) {
   MI_CpuCopy8(packet,Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x100+i*0x44,0x44);
   *(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x208+i*4)=1;
  }else *(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x208+i*4)=0;
  i=(unsigned short)(i+1);
 }while(i<2);
}
