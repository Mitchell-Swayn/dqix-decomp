#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FC1EC; symbol: Object_GetEmbeddedAddressAtOffset34; size: 0x8.
// Returns the address object+0x34; the embedded member type is unknown.
extern "C" void* MenuZone_GetZoneState(void* self) { return (unsigned char*)self + 0x34; }
