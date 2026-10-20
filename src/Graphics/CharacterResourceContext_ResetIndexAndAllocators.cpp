#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original: arm9/main @ 0x02054280; symbol: func_02054280; size: 0x34.
extern "C" void CharacterResourceContext_ResetIndexAndAllocators(unsigned char* p){*(short*)p=-1;for(int i=0;i<10;i++)_ZN13SafeAllocator21ResetAllocatorPointerEv(p+4+i*20);}
