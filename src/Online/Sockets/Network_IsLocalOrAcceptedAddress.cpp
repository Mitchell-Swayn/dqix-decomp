#include <globaldefs.h>
ARM
#pragma always_inline on
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern unsigned NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];unsigned Network_IsAddressWithinConfiguredHostRange(unsigned);unsigned Network_IsMulticastAddress(unsigned);}
inline int IsConfiguredOrUnset(unsigned address){return NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[20]==0 || address==NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[20];}
inline int IsLocal(unsigned address){return IsConfiguredOrUnset(address)||address==0x7f000001;}
inline int IsLocalOrFirst(unsigned address){return IsLocal(address)||Network_IsAddressWithinConfiguredHostRange(address);}
// Original: arm9/ov031 @ 0x022007A4; symbol: func_ov031_022007a4; size: 0x80.
extern "C" int Network_IsLocalOrAcceptedAddress(unsigned address){return IsLocalOrFirst(address)||Network_IsMulticastAddress(address);}
