#include <globaldefs.h>
ARM
extern "C" void *Memory_AllocateZeroedBlock(unsigned int, int);
// Original data: arm9/ov031 @ 0x2290c48; symbol: data_ov031_02290c48.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void * volatile WfcUtilityCopyNetworkTaskResult_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_FreeNetworkTaskBuffer(void);
extern "C" void WfcUtility_CopyNetworkTaskResult(void);
extern "C" void WfcUtility_AllocateNetworkTaskBuffer(void);
extern "C" int WirelessSetup_StartConfigurationWorker(unsigned int, unsigned int, void (*)(void), void (*)(void), void (*)(void), unsigned int);
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void _Z19SleepCurrentContextj(unsigned int);
// Original: arm9/ov031 @ 0x02227B38; symbol: func_ov031_02227b38; size: 0x6C.
extern "C" void WfcUtility_InitializeNetworkTaskContext(void) {
    WfcUtilityCopyNetworkTaskResult_UnknownRoleZeroInitializedStorage = Memory_AllocateZeroedBlock(0xc, -4);
    int result = WirelessSetup_StartConfigurationWorker(0xf, 0x40, WfcUtility_CopyNetworkTaskResult, WfcUtility_AllocateNetworkTaskBuffer, WfcUtility_FreeNetworkTaskBuffer, 0x800);
    if (result != 1) DisableInterruptsAndHaltForever();
    _Z19SleepCurrentContextj(10);
}
