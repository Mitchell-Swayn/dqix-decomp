#include <globaldefs.h>
ARM
extern "C" char data_02153680[];extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);extern "C" void _ZN13SafeAllocator5ResetEv(void*);
// Original: arm9/main @ 0x020E50EC; symbol: func_020e50ec; size: 0x28.
extern "C" void Allocator_CreateAndResetGlobalTypeAHeap(void* p,unsigned size){_ZN13SafeAllocator11CreateTypeAEPvj(data_02153680,p,size);_ZN13SafeAllocator5ResetEv(data_02153680);}
