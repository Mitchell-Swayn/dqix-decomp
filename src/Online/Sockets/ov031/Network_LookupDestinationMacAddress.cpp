#include <globaldefs.h>
#include <System/Timing.h>
#include <System/Interrupts.h>
ARM
#pragma optimization_level 4
extern "C" int Network_IsAddressWithinConfiguredHostRange(unsigned);
extern "C" unsigned Network_IsMulticastAddress(unsigned);
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char NetworkLookupDestinationMacAddress_UnknownRoleInitializedBytes[];
struct AddressRecord { unsigned address; unsigned char payload[6]; unsigned short timestamp; };
extern "C" AddressRecord NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage[8];
extern "C" unsigned char NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x02200BFC; symbol: Network_LookupDestinationMacAddress; size: 0xD0.
// Returns a special payload for loopback/local or broadcast/multicast addresses,
// otherwise finds one of eight address records and refreshes its timestamp.
extern "C" void* Network_LookupDestinationMacAddress(unsigned address)
{
 unsigned i;
 int irq = DisableIRQInterrupts();
 void* result = 0;
 if (address == 0x7f000001 || address == *(unsigned*)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage + 0x50))
  result = NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage;
 else if (Network_IsAddressWithinConfiguredHostRange(address) || Network_IsMulticastAddress(address))
  result = NetworkLookupDestinationMacAddress_UnknownRoleInitializedBytes;
 else {
  AddressRecord* record = NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage;
  i = 0;
  do {
   if (address == record->address) {
    address = GetCurrentTimestamp() >> 16;
    *(unsigned short*)(NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage_Variant2 + i * 12) = address;
    result = NetworkUpdateAddressCache_UnknownRoleZeroInitializedStorage[i].payload;
    break;
   }
   i++;
   record++;
  } while (i < 8);
 }
 SetIRQInterruptState(irq);
 return result;
}
