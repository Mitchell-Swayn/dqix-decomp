#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    extern unsigned char data_02114e20[];
    void Memory_FreeThroughAllocatorUnion(void *,void *);
// Original: arm9/main @ 0x020998AC; symbol: func_020998ac; size: 0x18.
    void AllocatorUnion_FreeStoredPointer(void **p){
        Memory_FreeThroughAllocatorUnion(data_02114e20,*p);
    }
}
