#include <globaldefs.h>
ARM
extern "C" void ActorPool_ResetSpriteResourceDirectory(void*);extern "C" void ActorPool_Initialize(void*);
// Original: arm9/main @ 0x0203EF60; symbol: func_0203ef60; size: 0x1C.
extern "C" void* ActorPool_Construct(void* p){ActorPool_ResetSpriteResourceDirectory(p);ActorPool_Initialize(p);return p;}
