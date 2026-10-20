#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21142e0; symbol: data_021142e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);extern "C" unsigned char* WMiCheckIdle_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D46FC; symbol: func_020d46fc; size: 0x30.
extern "C" unsigned int WirelessCommand_ReadSharedWord14CLowHalfwordAtomically() { int state=_Z20DisableIRQInterruptsv();unsigned char* p=WMiCheckIdle_UnknownRoleZeroInitializedStorage[1];unsigned int value=p ? *(unsigned int*)(p+0x14c) : 0;_Z20SetIRQInterruptStatei(state);return (unsigned short)value; }
