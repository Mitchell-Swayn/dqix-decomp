#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
// Original: arm9/main @ 0x0209CCEC; symbol: func_0209ccec; size: 0x38.
extern "C" void AllocatePositiveWordArrayAndStoreByteCount(unsigned* p,int n){if(n<=0)return;p[0]=(unsigned)AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,(unsigned)n<<2);((unsigned char*)p)[5]=n;((unsigned char*)p)[4]=0;}
