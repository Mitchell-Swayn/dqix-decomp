#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage;
extern "C" void DisableInterruptsAndHaltForever();
extern "C" void WirelessHost_SetSystemState(int);
extern "C" unsigned short Network_SelectSetMaskPosition(unsigned short);
extern "C" unsigned char Network_ComputeAndPublishSharedValue_FormatDecidedChannelD;
typedef void (*Callback)(void*, const void*, unsigned short);
// Original: arm9/ov031 @ 0x02239E68; symbol: Network_ComputeAndPublishSharedValue; size: 0x78.
// Requires shared object state 7, computes and stores its halfword at +0x5c, then invokes the registered callback when present.
extern "C" unsigned short Network_ComputeAndPublishSharedValue() {
    if (*((unsigned int*)*(unsigned char**)((char*)&WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4) + 0x10) != 7) DisableInterruptsAndHaltForever();
    WirelessHost_SetSystemState(1);
    unsigned short result = Network_SelectSetMaskPosition(*(unsigned short*)(*(unsigned char**)((char*)&WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4) + 0x60));
    *(unsigned short*)(*(unsigned char**)((char*)&WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4) + 0x5c) = result;
    Callback callback = *(Callback*)&WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage;
    if (callback) callback((void*)0x08000000, &Network_ComputeAndPublishSharedValue_FormatDecidedChannelD, *(unsigned short*)(*(unsigned char**)((char*)&WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4) + 0x5c));
    return *(unsigned short*)(*(unsigned char**)((char*)&WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4) + 0x5c);
}
