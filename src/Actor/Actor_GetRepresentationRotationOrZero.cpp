#include <globaldefs.h>
#pragma always_inline on
struct Vec {int words[3];};
extern "C" {void __clear(void*,unsigned);int ActorSprite_GetFacingAngle(void*);}
struct PositionObject{char pad[0x50];Vec position;};struct Owner{char pad[0x14];void*first;PositionObject*second,*third;};
// Original: arm9/main @ 0x020407C4; symbol: func_020407c4; size: 0x98.
extern "C" ARM void Actor_GetRepresentationRotationOrZero(Vec*out,Owner*p){if(p->first){Vec v;__clear(&v,12);v.words[1]=ActorSprite_GetFacingAngle(p->first);*out=v;}else if(p->second)*out=p->second->position;else if(p->third)*out=p->third->position;else{Vec v;v.words[0]=0;v.words[1]=0;v.words[2]=0;*out=v;}}
