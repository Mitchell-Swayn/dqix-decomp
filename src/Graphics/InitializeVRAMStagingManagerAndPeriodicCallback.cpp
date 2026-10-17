#include <globaldefs.h>
#include <Graphics/itcm/VRAMStaging.h>
extern VRAMStagingManager g_stagingManagerInstance;
extern "C" void func_020c89c4(void);
extern "C" void OS_EnableDTCM(void);
extern "C" void Object_ClearElement0AndClearElement2AndClearElement8(void*);
extern "C" void ConfigurePeriodicScanlineAlarmUnderIRQProtection(void*, int, int, void*, void*);
extern "C" char data_0214e5bc[];
// Original: arm9/main @ 0x020DC034; symbol: func_020dc034; size: 0x48.
extern "C" void InitializeVRAMStagingManagerAndPeriodicCallback(void) {
    func_020c89c4();
    OS_EnableDTCM();
    g_stagingManagerInstance.ZeroInitialize();
    Object_ClearElement0AndClearElement2AndClearElement8(data_0214e5bc);
    ConfigurePeriodicScanlineAlarmUnderIRQProtection(data_0214e5bc,0xc0,0xf,(void*)SendStagedVRAMDataToVRAM,&g_stagingManagerInstance);
}
