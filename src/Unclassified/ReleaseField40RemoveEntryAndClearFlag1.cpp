#include <globaldefs.h>
ARM
extern "C" unsigned char data_0210fca8[];extern "C" void ClearGlobal0210F3C0SlotBit(void*);extern "C" void _ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(void*,void*);
// Original: arm9/main @ 0x020BCCF0; symbol: func_020bccf0; size: 0x30.
extern "C" void ReleaseField40RemoveEntryAndClearFlag1(unsigned char* p){ClearGlobal0210F3C0SlotBit(*(void**)(p+64));_ZN19SignedAllocatorList6RemoveEP21SignedAllocatorHeader(data_0210fca8,p);*(unsigned*)(p+36)&=~1U;}
