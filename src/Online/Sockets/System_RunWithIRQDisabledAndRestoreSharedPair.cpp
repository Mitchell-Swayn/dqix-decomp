#include <globaldefs.h>
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int Network_ResolveIpv4Host(void*);
// Original data: arm9/ov031 @ 0x224c9e0; symbol: data_ov031_0224c9e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02206EBC; symbol: func_ov031_02206ebc; size: 0x4C.
extern "C" int System_RunWithIRQDisabledAndRestoreSharedPair(void* object) {
    int irq = _Z20DisableIRQInterruptsv();
    unsigned first = NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[0];
    unsigned second = NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[1];
    NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[0] = 0;
    NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[1] = 0;
    int result = Network_ResolveIpv4Host(object);
    NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[0] = first;
    NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[1] = second;
    _Z20SetIRQInterruptStatei(irq);
    return result;
}
