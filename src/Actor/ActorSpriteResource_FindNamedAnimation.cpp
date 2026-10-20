#include <globaldefs.h>
ARM
extern "C" int strcmp(const char*,const char*);
// Original: arm9/main @ 0x02040184; symbol: func_02040184; size: 0x60.
extern "C" unsigned ActorSpriteResource_FindNamedAnimation(unsigned* p,const char* text){if(!p[0])return ~0U;for(unsigned i=0;i<p[6];++i){if(strcmp(text,*(const char**)(p[7]+i*20))==0)return i;}return ~0U;}
