#include <globaldefs.h>
extern "C" void Network_StartSharedPairCallbacksOrSetFailureState(void*, unsigned, unsigned, unsigned);
extern "C" int WirelessConnection_PollStatus();
extern "C" int Network_SetWirelessProfileAndAuxiliaryBytes(void*, unsigned, unsigned, unsigned, unsigned);
// Original data: arm9/ov031 @ 0x224e5b4; symbol: data_ov031_0224e5b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02211D54; symbol: func_ov031_02211d54; size: 0x5C.
extern "C" int WirelessConnection_StartProfileAfterFallback(void* a, unsigned b, unsigned c, unsigned d, unsigned e) {
    Network_StartSharedPairCallbacksOrSetFailureState(a, b, c, d);
    unsigned char* entry = *(unsigned char**)(WirelessConnectionPollStatus_UnknownRoleZeroInitializedStorage + 4);
    if (entry) entry[0xc] = 1;
    int result = WirelessConnection_PollStatus();
    if (result != 2) return result;
    return Network_SetWirelessProfileAndAuxiliaryBytes(a, b, c, d, e);
}
