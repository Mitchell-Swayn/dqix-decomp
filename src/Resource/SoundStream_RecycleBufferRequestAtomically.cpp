#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21103bc; symbol: data_021103bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" void _ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(void*,void*);extern "C" unsigned char NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/main @ 0x020BF458; symbol: func_020bf458; size: 0x2C.
extern "C" void SoundStream_RecycleBufferRequestAtomically(void* p){int irq=_Z20DisableIRQInterruptsv();_ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant2,p);_Z20SetIRQInterruptStatei(irq);}
