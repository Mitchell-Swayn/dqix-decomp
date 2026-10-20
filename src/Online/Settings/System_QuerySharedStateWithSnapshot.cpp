#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c48; symbol: data_ov031_02290c48.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned* WfcUtilityCopyNetworkTaskResult_UnknownRoleZeroInitializedStorage;
extern "C" int WirelessSetup_CopyReceivedConfiguration(void*);
extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/ov031 @ 0x02227BC8; symbol: func_ov031_02227bc8; size: 0xBC.
extern "C" int System_QuerySharedStateWithSnapshot(int fallback) {
 switch(WfcUtilityCopyNetworkTaskResult_UnknownRoleZeroInitializedStorage[0]) {
 case 0: case 1: case 3: case 5: return 0;
 case 2: return 1;
 case 4: return 2;
 case 6: {
  int snapshot[58];
  if(WirelessSetup_CopyReceivedConfiguration(snapshot)!=1) DisableInterruptsAndHaltForever();
  if(snapshot[8]>=0 && snapshot[8]<=3 && snapshot[9]==1) return 3;
  return 5;
 }
 case 7: return 4;
 }
 return fallback;
}
