#include <globaldefs.h>
#include <System/ProcessorContext.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" {
 void Network_BroadcastArpRequest(unsigned);
 void* Network_LookupDestinationMacAddress(unsigned);
 extern unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
}
// Pinned NitroWiFi CPS network.c: arprequest; CPSMyIp is global+0x50.
// Original: arm9/ov031 @ 0x02200DC8; symbol: func_ov031_02200dc8; size: 0x70.
extern "C" void* Network_ResolveMacAddressWithArpRetries(unsigned ip) {
 for(unsigned long retry1=0;retry1<8;++retry1) {
  Network_BroadcastArpRequest(ip);
  for(unsigned long retry2=0;retry2<20;++retry2) {
   if(*(unsigned*)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage+0x50)==0)return 0;
   SleepCurrentContext(100);
   void* mac=Network_LookupDestinationMacAddress(ip);
   if(mac)return mac;
  }
 }
 return 0;
}
