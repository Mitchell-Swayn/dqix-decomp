#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224c9d0; symbol: data_ov031_0224c9d0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e1c4; symbol: data_ov031_0224e1c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e1d0; symbol: data_ov031_0224e1d0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern unsigned NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant2;extern unsigned NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage;extern char* NetworkCleanupSocketStack_UnknownRoleInitializedBytes;extern unsigned NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant3[];int Overlay_InvokeCallbackWhenProgressComplete();void _Z19SleepCurrentContextj(unsigned);int System_PollSharedSequenceAndDrainQueue();void Network_StopWorkersAndResetStack();void Network_SetMaintenanceCallback(unsigned);}
// Original: arm9/ov031 @ 0x02206C44; symbol: DrainSharedSequenceAndReleaseContext; size: 0xa4.
// Waits while progress returns-26 then drains sequence and releases inactive context.
extern "C" int Network_CleanupSocketStack(){if(!NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant2)NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant2=NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage;int poll=System_PollSharedSequenceAndDrainQueue();if(poll==-26){do{_Z19SleepCurrentContextj(100);poll=System_PollSharedSequenceAndDrainQueue();}while(poll==-26);}int result=Overlay_InvokeCallbackWhenProgressComplete();if(result>=0){Network_StopWorkersAndResetStack();Network_SetMaintenanceCallback(0);if(!*(int*)(NetworkCleanupSocketStack_UnknownRoleInitializedBytes+0x28))((void(*)(unsigned))*(unsigned*)(NetworkCleanupSocketStack_UnknownRoleInitializedBytes+0x1c))(NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage_Variant3[7]);NetworkCleanupSocketStack_UnknownRoleInitializedBytes=0;}return result;}
