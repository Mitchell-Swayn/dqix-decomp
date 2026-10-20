#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2112780; symbol: data_02112780.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);extern "C" void* SNDPushCommand_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D28A8; symbol: func_020d28a8; size: 0x48.
extern "C" void* SoundCommand_TakeFreeCommand(){int state=_Z20DisableIRQInterruptsv();void* q=SNDPushCommand_UnknownRoleZeroInitializedStorage[0];if(!q){_Z20SetIRQInterruptStatei(state);return 0;}void* next=*(void**)q;SNDPushCommand_UnknownRoleZeroInitializedStorage[0]=next;if(!next)SNDPushCommand_UnknownRoleZeroInitializedStorage[4]=0;_Z20SetIRQInterruptStatei(state);return q;}
