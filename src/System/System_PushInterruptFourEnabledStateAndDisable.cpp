// Reviewed original instruction stream; opaque fields require later semantic naming.
// Original data: arm9/main @ 0x214e4a0; symbol: data_0214e4a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[];unsigned int DisableSpecificInterrupts(unsigned int);
// Original: arm9/main @ 0x020D8654; symbol: func_020d8654; size: 0x40.
extern "C" void System_PushInterruptFourEnabledStateAndDisable(){GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[1]<<=1;unsigned int old=DisableSpecificInterrupts(4);unsigned int flag=(old&4)!=0;GraphicsGetSwapPhase_UnknownRoleZeroInitializedStorage[1]|=flag;}
