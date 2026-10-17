#include <Memory/SafeAllocator.h>
struct Item{char unknown[0xd4];int tail;};struct Object{Item items[12];int count;short a,b;SafeAllocator allocator;unsigned char flags[4];float scalarA,scalarB;};extern "C" void Object_ClearD4ByteDisplayEntryAndSetDefaults(void*);
// Original: arm9/main @ 0x020D6D18; symbol: func_020d6d18; size: 0x78.
extern "C" void InitializeTwelveEntriesAndAllocatorState(Object *self){for(int i=0;i<12;i++){Object_ClearD4ByteDisplayEntryAndSetDefaults(self->items+i);self->items[i].tail=0;}self->allocator.ResetAllocatorPointer();self->count=0;self->a=0;self->b=0;self->flags[0]=0;self->flags[1]=0;self->scalarA=1.0f;self->scalarB=-0.2f;}
