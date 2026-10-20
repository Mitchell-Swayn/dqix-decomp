#include <globaldefs.h>
ARM
extern "C" void ActorPool_ResetSpriteResourceDirectory(void*);extern "C" void ActorPool_ClearDefinitionList(void*);extern "C" void ActorPool_ClearMotionList(void*);extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0203CFB4; symbol: func_0203cfb4; size: 0x40.
extern "C" void ActorPool_ResetLiveActorsAndResources(unsigned char* p){ActorPool_ResetSpriteResourceDirectory(p);ActorPool_ClearDefinitionList(p+144);ActorPool_ClearMotionList(p+148);memset(p+12,0,128);*(int*)(p+152)=0;*(int*)(p+140)=0;p[156]=0;}
