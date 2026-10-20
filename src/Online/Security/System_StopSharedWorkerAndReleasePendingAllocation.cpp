#include <globaldefs.h>
THUMB
struct SharedWorker { char a[12];void (*freeAllocation)(void*);int stop;char b[28];void* allocation;char c[4];int state;char d[40];int active;char e[12];int result;};
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" SharedWorker WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x224f71c; symbol: data_ov031_0224f71c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupStartConfigurationWorker_UnknownRoleZeroInitializedStorage[];
extern "C" void ARM _Z19SleepCurrentContextj(unsigned);
extern "C" int ARM _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void ARM _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
extern "C" void ARM _Z22AwaitContextCompletionP16ProcessorContext(void*);
extern "C" void WirelessSetup_NotifyProgress();
extern "C" int WirelessSetup_ShutdownWirelessAndFreeWorkspace();
THUMB
// Original: arm9/ov031 @ 0x02222A10; symbol: System_StopSharedWorkerAndReleasePendingAllocation; size: 0x94.
// Stops active worker context, waits for completion, releases pending allocation and consumes positive result.
extern "C" int System_StopSharedWorkerAndReleasePendingAllocation() {
 if(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.active){int oldState=WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.state;WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.stop=1;
 while(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.state>=1&&WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.state<=5)_Z19SleepCurrentContextj(100);
 _Z19SleepCurrentContextj(500);
 if(!_Z17IsContextInactiveP16ProcessorContext(WirelessSetupStartConfigurationWorker_UnknownRoleZeroInitializedStorage))do{_Z25MarkContextReadyAndSwitchP16ProcessorContext(WirelessSetupStartConfigurationWorker_UnknownRoleZeroInitializedStorage);_Z22AwaitContextCompletionP16ProcessorContext(WirelessSetupStartConfigurationWorker_UnknownRoleZeroInitializedStorage);}while(!_Z17IsContextInactiveP16ProcessorContext(WirelessSetupStartConfigurationWorker_UnknownRoleZeroInitializedStorage));
 if(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.allocation){WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.freeAllocation(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.allocation);WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.allocation=0;}
 WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.active=0;if(oldState!=WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.state)WirelessSetup_NotifyProgress();}
 if(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.result>0){int result=WirelessSetup_ShutdownWirelessAndFreeWorkspace();WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage.result=0;return result;}return -10;
}
