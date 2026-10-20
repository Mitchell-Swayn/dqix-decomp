#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ce4; symbol: data_ov031_02290ce4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_LoadUsbAccessPointSetupBackground();
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_ConfigureSecondaryControlsForDisplayMode(unsigned);
extern "C" void OS_GetOwnerInfo(void*);
extern "C" void MIi_CpuClear16(int,void*,unsigned);
extern "C" void MIi_CpuCopy16(const void*,void*,unsigned);
extern "C" void WfcUtility_DrawPrimaryMessageAndValue(void*,unsigned);
extern "C" void WfcUtility_CreateAnimatedStatusSprite(unsigned);
extern "C" void Wireless_InitializeUsbAccessPointScan(void(*)());
extern "C" void WfcUtility_BeginScreenExitForMode();
extern "C" void System_CreateCopyAndFinalizeResource(unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void System_ConfigureDisplayPlaneAndCallbackTwo();
// Original: arm9/ov031 @ 0x022348CC; symbol: System_CopyHardwareConfigurationAndInstallMenuCallbacks; size: 0x94.
// Copies hardware configuration halfwords into cleared buffer, loads resource 11 and installs callbacks.
extern "C" void System_CopyHardwareConfigurationAndInstallMenuCallbacks() {
 WfcUtilityBeginScreenExitForMode_UnknownRoleZeroInitializedStorage=0;WfcUtility_LoadUsbAccessPointSetupBackground();System_CreateCopyAndFinalizeResource(8);WfcUtility_ConfigureSecondaryControlsForDisplayMode(2);
 unsigned short config[42],copy[11];OS_GetOwnerInfo(config);MIi_CpuClear16(0,copy,22);MIi_CpuCopy16(config+2,copy,config[13]*2);WfcUtility_DrawPrimaryMessageAndValue(copy,40);
 WfcUtility_CreateAnimatedStatusSprite(0);Wireless_InitializeUsbAccessPointScan(WfcUtility_BeginScreenExitForMode);WfcUtility_PlaySequenceArchiveEntry(11);WfcUtility_SetMainLoopCallback(System_ConfigureDisplayPlaneAndCallbackTwo);
}
