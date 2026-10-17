#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned char data_02114e20[];extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
// Original: arm9/main @ 0x0209CCEC; symbol: func_0209ccec; size: 0x38.
extern "C" void AllocatePositiveWordArrayAndStoreByteCount(unsigned* p,int n){if(n<=0)return;p[0]=(unsigned)AllocatorUnion_AllocateFourByteAligned(data_02114e20,(unsigned)n<<2);((unsigned char*)p)[5]=n;((unsigned char*)p)[4]=0;}
