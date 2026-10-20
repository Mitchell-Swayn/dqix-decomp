#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x210fca8; symbol: data_0210fca8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char NNSSndStrmSetup_UnknownRoleZeroInitializedStorage[];extern "C" void Sound_ReleaseStreamAlarmSlot(void*);extern "C" void _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(void*,void*);
// Original: arm9/main @ 0x020BCCF0; symbol: func_020bccf0; size: 0x30.
extern "C" void SoundStream_ReleaseAlarmAndUnregister(unsigned char* p){Sound_ReleaseStreamAlarmSlot(*(void**)(p+64));_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(NNSSndStrmSetup_UnknownRoleZeroInitializedStorage,p);*(unsigned*)(p+36)&=~1U;}
