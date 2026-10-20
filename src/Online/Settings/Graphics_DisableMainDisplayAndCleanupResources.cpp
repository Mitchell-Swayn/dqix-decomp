#include <globaldefs.h>
ARM
extern "C" void Graphics_SaveDisplayModeAndClearDisplayModeBits();
extern "C" unsigned WfcUtility_SendPowerManagementOperationEighteenOne();
extern "C" int IPC_SendNormalizedBooleanModeCommand(int);
extern "C" void TouchInput_WaitForIPCOperationFourAndFreeSharedAllocation();
extern "C" void System_DisableGlobalInterruptsAndInstallInterruptOneHandler();
extern "C" void WfcUtility_DestroySoundContextAndUpdateTask();
extern "C" void WfcUtility_DestroySpriteGroupPools();
extern "C" void WfcUtility_DestroyOamServices();
extern "C" void WfcUtility_DestroyTextCanvasServices();
extern "C" void FreeGlobalSharedAllocationAndClearFlag();
extern "C" void WfcUtility_UnmountUtilityArchive();
extern "C" void WfcUtility_DestroyTaskQueues();
extern "C" void Memory_RemoveGlobalHPXEAllocator();
extern "C" void Graphics_RestoreVramMappingsAndClearOffsets();
// Original: arm9/ov031 @ 0x02227468; symbol: Graphics_DisableMainDisplayAndCleanupResources; size: 0x58.
// Saves display mode, clears the main display-control bit at 0x04001000, sends IPC mode 1, then runs ordered display, touch, and shared-resource cleanup.
extern "C" void Graphics_DisableMainDisplayAndCleanupResources(void) {
    Graphics_SaveDisplayModeAndClearDisplayModeBits();
    *(unsigned *)0x04001000 &= ~0x10000u;
    WfcUtility_SendPowerManagementOperationEighteenOne();
    IPC_SendNormalizedBooleanModeCommand(1);
    TouchInput_WaitForIPCOperationFourAndFreeSharedAllocation();
    System_DisableGlobalInterruptsAndInstallInterruptOneHandler();
    WfcUtility_DestroySoundContextAndUpdateTask();
    WfcUtility_DestroySpriteGroupPools();
    WfcUtility_DestroyOamServices();
    WfcUtility_DestroyTextCanvasServices();
    FreeGlobalSharedAllocationAndClearFlag();
    WfcUtility_UnmountUtilityArchive();
    WfcUtility_DestroyTaskQueues();
    Memory_RemoveGlobalHPXEAllocator();
    Graphics_RestoreVramMappingsAndClearOffsets();
}
