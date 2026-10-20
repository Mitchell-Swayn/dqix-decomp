#include <globaldefs.h>
ARM
#pragma force_active on
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void* System_WaitForOrRegisterSharedContext(void);
// Original data: arm9/ov031 @ 0x0224C9E0; symbol: data_ov031_0224c9e0.
// Two mutable DNS server words, also written by CopyNetworkConfigurationToStateGlobals.
extern "C" unsigned NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[2];
// Original: arm9/ov031 @ 0x02206F08; symbol: func_ov031_02206f08; size: 0x34.
// Stores the DNS server address pair once the shared socket context is available.
extern "C" int Network_SetDnsServers(unsigned primary, unsigned secondary)
{
    if (!System_WaitForOrRegisterSharedContext()) return -39;
    NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[0] = primary;
    NetworkSetDnsServers_UnknownRoleZeroInitializedStorage[1] = secondary;
    return 0;
}
