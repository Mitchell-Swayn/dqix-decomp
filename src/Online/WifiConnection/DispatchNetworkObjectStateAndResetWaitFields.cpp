#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WirelessHost_GetSystemState();extern "C" void WirelessHost_BeginChannelOccupancySurvey();extern "C" unsigned Network_ComputeAndPublishSharedValue();extern "C" void Network_SetStateTenWhenSubmitResultIsZero();extern "C" void DisableInterruptsAndHaltForever();extern "C" char* Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223AB6C; symbol: DispatchNetworkObjectStateAndResetWaitFields; size: 0xA8.
// Dispatches network state0/1/3/7/9 and resets the wait word/state for states0 and7.
extern "C" void DispatchNetworkObjectStateAndResetWaitFields(){switch(WirelessHost_GetSystemState()){case 1:WirelessHost_BeginChannelOccupancySurvey();break;case 3:break;case 7:*(unsigned short*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x64a)=Network_ComputeAndPublishSharedValue();*(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa98)=0;Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa90]=3;break;case 0:*(unsigned*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa98)=0;Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa90]=3;break;case 9:Network_SetStateTenWhenSubmitResultIsZero();break;default:DisableInterruptsAndHaltForever();break;}}
