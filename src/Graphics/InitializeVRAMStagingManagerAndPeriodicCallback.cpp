#include <globaldefs.h>
#include <Graphics/itcm/VRAMStaging.h>
extern VRAMStagingManager g_stagingManagerInstance;
extern "C" void OS_EnableITCM(void);
extern "C" void OS_EnableDTCM(void);
extern "C" void OS_CreateVAlarm(void*);
extern "C" void ConfigurePeriodicScanlineAlarmUnderIRQProtection(void*, int, int, void*, void*);
// Original data: arm9/main @ 0x214e5bc; symbol: data_0214e5bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char InitializeVRAMStagingManagerAndPeriodicCallback_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020DC034; symbol: func_020dc034; size: 0x48.
extern "C" void InitializeVRAMStagingManagerAndPeriodicCallback(void) {
    OS_EnableITCM();
    OS_EnableDTCM();
    g_stagingManagerInstance.ZeroInitialize();
    OS_CreateVAlarm(InitializeVRAMStagingManagerAndPeriodicCallback_UnknownRoleZeroInitializedStorage);
    ConfigurePeriodicScanlineAlarmUnderIRQProtection(InitializeVRAMStagingManagerAndPeriodicCallback_UnknownRoleZeroInitializedStorage,0xc0,0xf,(void*)SendStagedVRAMDataToVRAM,&g_stagingManagerInstance);
}
