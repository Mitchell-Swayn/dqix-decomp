#include <globaldefs.h>
ARM
struct State { char pad[64]; int value; };
struct Globals { void (*callback)(int,const char*,int); State* state; };
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Globals WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224c318; symbol: data_ov031_0224c318.
// Wireless host system state names indexed by state enum.
// Initial values: hex dcc12402f8c124024cc2240214c224026cc22402acc224028cc22402f4c22402d0c2240230c22402.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int WirelessHostSetSystemState_WirelessHostSystemStateNamesIndexedByStateEnum[];
extern "C" char WirelessHost_SetSystemState_FormatS[];
extern "C" char WirelessHost_SetSystemState_FormatS_Copy2[];
// Original: arm9/ov031 @ 0x02239368; symbol: func_ov031_02239368; size: 0x7C.
extern "C" void WirelessHost_SetSystemState(int value) {
 if (WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.callback) WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.callback(0x8000000,WirelessHost_SetSystemState_FormatS,WirelessHostSetSystemState_WirelessHostSystemStateNamesIndexedByStateEnum[WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.state->value]);
 WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.state->value=value;
 if (WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.callback) WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.callback(0x8000000,WirelessHost_SetSystemState_FormatS_Copy2,WirelessHostSetSystemState_WirelessHostSystemStateNamesIndexedByStateEnum[WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage.state->value]);
}
