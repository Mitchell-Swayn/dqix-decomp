// Original data: arm9/main @ 0x21117ec; symbol: data_021117ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2111808; symbol: data_02111808.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int PMGoSleepMode_UnknownRoleZeroInitializedStorage[]; extern "C" volatile int IPCWaitForPendingCommandCompletion_UnknownRoleZeroInitializedStorage; unsigned int GetIRQInterruptState(); void HandleCommandReceivedFromArm7();
// Original: arm9/main @ 0x020CE188; symbol: func_020ce188; size: 0x50.
 extern "C" void IPC_PollPendingReplyWhenInterruptsUnavailable() { volatile int *pending=&IPCWaitForPendingCommandCompletion_UnknownRoleZeroInitializedStorage; if(!PMGoSleepMode_UnknownRoleZeroInitializedStorage[7])return; volatile unsigned short *enabled=(volatile unsigned short *)0x04000208; do { if(GetIRQInterruptState()==128 || !*enabled)HandleCommandReceivedFromArm7(); }while(*pending); }
