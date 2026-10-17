#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290d3c[];
extern "C" void _ZN13HPXEAllocator14RemoveFromTreeEv(void *);
// Original: arm9/ov031 @ 0x0223CEDC; symbol: func_ov031_0223cedc; size: 0x24.
extern "C" void Memory_RemoveGlobalHPXEAllocator(void) {
    _ZN13HPXEAllocator14RemoveFromTreeEv(*(void **)data_ov031_02290d3c);
    *(void **)data_ov031_02290d3c = 0;
}
