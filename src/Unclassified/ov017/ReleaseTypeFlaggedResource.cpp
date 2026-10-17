#include <globaldefs.h>

extern "C" void Memory_FreeThroughAllocatorUnion(void *, void *); extern "C" unsigned int data_02114e20;
ARM
// Original: arm9/ov017 @ 0x021C2710; symbol: func_ov017_021c2710; size: 0x34.
extern "C" void ReleaseTypeFlaggedResource(void *record) { void **resource=(void **)((unsigned char *)record+8); if(*resource) { Memory_FreeThroughAllocatorUnion(&data_02114e20,*resource); *resource=0; } *((unsigned char *)record+1)=1; }
