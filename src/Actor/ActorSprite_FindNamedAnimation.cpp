#include <globaldefs.h>
ARM
extern "C" unsigned char* Resource_GetActiveGraphicCacheEntry(void*,int);extern "C" int ActorSpriteResource_FindNamedAnimation(void*,const char*);
// Original: arm9/main @ 0x0203F0FC; symbol: func_0203f0fc; size: 0x3C.
extern "C" int ActorSprite_FindNamedAnimation(unsigned char* p,const char* name){int index=*(short*)(p+40);if(index<0)return -1;unsigned char* entry=Resource_GetActiveGraphicCacheEntry(*(void**)p,index);if(!entry)return -1;return ActorSpriteResource_FindNamedAnimation(entry+16,name);}
