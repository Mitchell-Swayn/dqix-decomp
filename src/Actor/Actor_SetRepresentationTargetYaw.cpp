#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void ActorSprite_SetQuantizedTargetFacing(void*,unsigned);
struct Links { char pad[20];char* first;char* second;char* third; };
// Original: arm9/main @ 0x02040AF0; symbol: func_02040af0; size: 0x3C.
extern "C" void Actor_SetRepresentationTargetYaw(Links* p,unsigned value) {
    if(p->first){ActorSprite_SetQuantizedTargetFacing(p->first,value);return;}
    if(p->second){*(unsigned*)(p->second+0xb0)=value;return;}
    if(p->third)*(unsigned*)(p->third+0x2d4)=value;
}
