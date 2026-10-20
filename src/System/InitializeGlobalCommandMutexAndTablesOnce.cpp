#include <globaldefs.h>
ARM
#include <System/Mutex.h>
// Original data: arm9/main @ 0x2112750; symbol: data_02112750.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2112754; symbol: data_02112754.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern int InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage_Variant3;extern Mutex ObjectInvokeLockMutex_UnknownRoleZeroInitializedStorage;void SoundCommand_InitializePoolAndSharedStatus();void SoundCommand_ClearCompletionCallbacks();
// Original: arm9/main @ 0x020D21C0; symbol: func_020d21c0; size: 0x38.
void InitializeGlobalCommandMutexAndTablesOnce(){if(InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage_Variant3)return;InitializeGlobalProcessorContextOnce_UnknownRoleZeroInitializedStorage_Variant3=1;ZeroInitializeMutex(&ObjectInvokeLockMutex_UnknownRoleZeroInitializedStorage);SoundCommand_InitializePoolAndSharedStatus();SoundCommand_ClearCompletionCallbacks();}}
