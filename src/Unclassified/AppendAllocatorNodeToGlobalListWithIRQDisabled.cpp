#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" void _ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(void*,void*);extern "C" unsigned char data_021103bc[];
// Original: arm9/main @ 0x020BF458; symbol: func_020bf458; size: 0x2C.
extern "C" void AppendAllocatorNodeToGlobalListWithIRQDisabled(void* p){int irq=_Z20DisableIRQInterruptsv();_ZN19SignedAllocatorList11InsertAtEndEP21SignedAllocatorHeader(data_021103bc,p);_Z20SetIRQInterruptStatei(irq);}
