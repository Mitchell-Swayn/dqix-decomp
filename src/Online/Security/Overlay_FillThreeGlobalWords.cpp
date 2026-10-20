#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224b114; symbol: data_ov031_0224b114.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex acfb24020100000000080000ffffffff40000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned char Ov031UpdateModeFromStatus_UnknownRoleDataReferences[];
extern "C" int Time_GetScaledCurrentTimestamp(int);
// Original: arm9/ov031 @ 0x02222AA4; symbol: func_ov031_02222aa4; size: 0x38.
extern "C" int Overlay_FillThreeGlobalWords(void* out) {
    *(unsigned*)out = *(unsigned*)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage + 0x38);
    int value = *(volatile int*)(Ov031UpdateModeFromStatus_UnknownRoleDataReferences + 0xc);
    if (value == -1) {
        *(int*)((char*)out + 4) = -1;
    } else {
        value = *(volatile int*)(Ov031UpdateModeFromStatus_UnknownRoleDataReferences + 0xc) - Time_GetScaledCurrentTimestamp(-1);
        *(int*)((char*)out + 4) = value;
    }
    *(unsigned*)((char*)out + 8) = *(unsigned*)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage + 0x78);
    return 1;
}
