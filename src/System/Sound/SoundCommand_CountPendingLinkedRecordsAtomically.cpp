#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2112780; symbol: data_02112780.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _Z20DisableIRQInterruptsv();extern "C" void _Z20SetIRQInterruptStatei(int);extern "C" void* SNDPushCommand_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020D2768; symbol: func_020d2768; size: 0x3C.
extern "C" unsigned SoundCommand_CountPendingLinkedRecordsAtomically(){int state=_Z20DisableIRQInterruptsv();unsigned count=0;void* node=SNDPushCommand_UnknownRoleZeroInitializedStorage;if(node){do{node=*(void**)node;++count;}while(node);}_Z20SetIRQInterruptStatei(state);return count;}
