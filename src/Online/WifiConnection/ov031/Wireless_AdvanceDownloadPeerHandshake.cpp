#include <globaldefs.h>
ARM
extern "C" char* Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223B228; symbol: Wireless_AdvanceDownloadPeerHandshake; size: 0xE4.
// Scans active slots; slot one advances a phase counter every second tick or starts the phase on tag0xBD.
extern "C" void Wireless_AdvanceDownloadPeerHandshake() {
 int slot=0;do {
  char* self=Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
  if(*(void**)(self+0x208+slot*4)) {
   char* records=self+0x100;
   int offset=slot*0x44;
   if(slot==1) {
    if(*(unsigned char*)(self+0xa93)==1) {
     if(*(unsigned short*)(records+offset)!=0x10)return;
     ++*(unsigned*)(self+0xa94);
     if(!(*(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa94)&1)) {
      ++*(unsigned short*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x200);
      if(*(unsigned short*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x200)>=0x24)*(unsigned short*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x200)=0;
     }
    } else {
     *(unsigned short*)(self+0x202)=0xbc;
     if(*(unsigned short*)(records+offset)==0xbd) {
      Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa93]=1;
      *(unsigned short*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x200)=0;
      *(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa94)=0;
     }
    }
   }
  }
  ++slot;
 }while(slot<16);
}
