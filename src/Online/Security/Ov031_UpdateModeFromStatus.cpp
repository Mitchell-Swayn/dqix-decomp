#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224b114; symbol: data_ov031_0224b114.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex acfb24020100000000080000ffffffff40000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned Ov031UpdateModeFromStatus_UnknownRoleDataReferences[];
extern "C" unsigned WirelessSetup_RunConfigurationExchange();
extern "C" void Network_DrainTransitionMessagesAndReleasePendingContext();
extern "C" void WirelessSetup_NotifyProgress();
// Original: arm9/ov031 @ 0x02220ED4; symbol: func_ov031_02220ed4; size: 0x38.
extern "C" THUMB void Ov031_UpdateModeFromStatus() {
    unsigned status = WirelessSetup_RunConfigurationExchange();
    WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[0x78 / 4] = status;
    Network_DrainTransitionMessagesAndReleasePendingContext();
    if (status == 1) WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[0x38 / 4] = 6;
    else WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[0x38 / 4] = 7;
    Ov031UpdateModeFromStatus_UnknownRoleDataReferences[0xc / 4] = 0xffffffff;
    WirelessSetup_NotifyProgress();
}
