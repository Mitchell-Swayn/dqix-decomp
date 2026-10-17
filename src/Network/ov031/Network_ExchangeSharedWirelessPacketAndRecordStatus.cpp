#include <globaldefs.h>
ARM
struct Global { void (*log)(unsigned,const char*); unsigned char* object; };
extern "C" Global data_ov031_02290d18;
extern "C" char data_ov031_0224c498[];
extern "C" char data_ov031_0224c4c8[];
extern "C" int Network_ExchangeQueuedWirelessPacket(unsigned char*,void*,void*);
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned);
// Original: arm9/ov031 @ 0x0223A2B0; symbol: func_ov031_0223a2b0; size: 0xA8.
extern "C" int Network_ExchangeSharedWirelessPacketAndRecordStatus(void* send) {
 unsigned char* self=data_ov031_02290d18.object;
 int result=Network_ExchangeQueuedWirelessPacket(self+0x13e0,send,self+0x1c00);
 if(result==7) {
  if(data_ov031_02290d18.log) data_ov031_02290d18.log(0x8000000,data_ov031_0224c498);
  return 0;
 }
 if(result==5) {
  if(data_ov031_02290d18.log) data_ov031_02290d18.log(0x8000000,data_ov031_0224c4c8);
  SetSharedObjectWord54UnlessStateNineOrTen(result);
  return 0;
 }
 if(!result) return 1;
 SetSharedObjectWord54UnlessStateNineOrTen(result);
 return 0;
}
