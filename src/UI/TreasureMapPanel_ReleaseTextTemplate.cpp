#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator4FreeEPv(void*,void*);
// Original: arm9/main @ 0x020263E4; symbol: func_020263e4; size: 0x34.
extern "C" void TreasureMapPanel_ReleaseTextTemplate(unsigned char* p){void* allocator=*(void**)(p+0x76c);if(allocator){void* block=*(void**)(p+0x770);if(block)_ZN13SafeAllocator4FreeEPv(allocator,block);}*(int*)(p+0x76c)=0;*(int*)(p+0x770)=0;*(int*)(p+0x774)=0;}
