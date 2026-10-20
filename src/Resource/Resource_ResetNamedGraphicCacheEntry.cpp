#include <globaldefs.h>
ARM
extern "C" void ActorSpriteResource_Reset(void*);
// Original: arm9/main @ 0x02040258; symbol: func_02040258; size: 0x24.
extern "C" void Resource_ResetNamedGraphicCacheEntry(unsigned char* p){p[0]=0;ActorSpriteResource_Reset(p+16);*(int*)(p+56)=-1;}
