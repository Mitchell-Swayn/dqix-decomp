#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" unsigned char* _ZN19SignedAllocatorList12ElementAfterEP21SignedAllocatorHeader(void*,void*);extern "C" void _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(void*,void*);
// Original: arm9/main @ 0x020BF3C8; symbol: func_020bf3c8; size: 0x50.
extern "C" void* ResourceQueue_PopFirstAndDecrementOwnerCountAtomically(void* list){int irq=_Z20DisableIRQInterruptsv();unsigned char* item=_ZN19SignedAllocatorList12ElementAfterEP21SignedAllocatorHeader(list,0);if(item){_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(list,item);--(*(unsigned**)(item+8))[71];}_Z20SetIRQInterruptStatei(irq);return item;}
