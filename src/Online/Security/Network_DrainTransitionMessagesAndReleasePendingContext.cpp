#pragma thumb off
#include "System/ProcessorContext.h"
extern "C" void System_DrainSharedSequenceAndReleaseContext();
#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" int TryTransitionSharedState7To4();
extern "C" unsigned WirelessSetup_PopEvent();
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221FCB4; symbol: func_ov031_0221fcb4; size: 0x64.
extern "C" void Network_DrainTransitionMessagesAndReleasePendingContext() {
 bool pending=true;
 if(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[8]) {
  if(TryTransitionSharedState7To4()) {
   do {
    SleepCurrentContext(10);
    unsigned message=WirelessSetup_PopEvent();
    while(message) {
     switch(message) {case 4:case 5:break;case 14:pending=false;break;default:pending=false;break;}
     message=WirelessSetup_PopEvent();
    }
   }while(pending);
  }
  WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[8]=0;
 }
 if(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[9]) {
  WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[9]=0;
  System_DrainSharedSequenceAndReleaseContext();
 }
}
