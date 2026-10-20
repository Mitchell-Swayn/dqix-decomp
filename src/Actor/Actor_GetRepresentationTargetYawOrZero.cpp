#include <globaldefs.h>
ARM
extern "C" void* ActorSprite_GetTargetFacingAngle(void*);
// Original: arm9/main @ 0x020409E0; symbol: func_020409e0; size: 0x40.
extern "C" void* Actor_GetRepresentationTargetYawOrZero(unsigned char* p){void* a=*(void**)(p+20);if(a)return ActorSprite_GetTargetFacingAngle(a);unsigned char* b=*(unsigned char**)(p+24);if(b)return *(void**)(b+176);unsigned char* c=*(unsigned char**)(p+28);return c?*(void**)(c+724):0;}
