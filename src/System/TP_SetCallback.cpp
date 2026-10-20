#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _Z20DisableIRQInterruptsv(); extern "C" void _Z20SetIRQInterruptStatei(int); extern "C" unsigned int TPWaitBusy_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020CDAC4; symbol: func_020cdac4; size: 0x20.
 extern "C" void TP_SetCallback(unsigned int value) { int state=_Z20DisableIRQInterruptsv(); TPWaitBusy_UnknownRoleZeroInitializedStorage[1]=value; _Z20SetIRQInterruptStatei(state); }
