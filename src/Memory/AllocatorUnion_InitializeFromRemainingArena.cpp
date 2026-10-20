#include <globaldefs.h>
ARM
unsigned GetArenaLow(int); unsigned GetArenaHigh(int); void *AllocateArenaLow(int,unsigned,unsigned);
struct HPXEAllocator { static HPXEAllocator *CreateAtLocation(void *,unsigned,unsigned short); };
struct AllocatorUnion { void InitializeTypeB(HPXEAllocator *,int); };
extern "C" void DisableInterruptsAndHaltForever();
// Original: arm9/main @ 0x02012D18; symbol: func_02012d18; size: 0x70.
extern "C" void AllocatorUnion_InitializeFromRemainingArena(AllocatorUnion *self) { unsigned low=GetArenaLow(0); unsigned high=GetArenaHigh(0); unsigned length=(high&~15U)-((low+15)&~15U); void *memory=AllocateArenaLow(0,length,16); HPXEAllocator *allocator=HPXEAllocator::CreateAtLocation(memory,length,0); self->InitializeTypeB(allocator,4); if(length<0x12d0f4) DisableInterruptsAndHaltForever(); }
