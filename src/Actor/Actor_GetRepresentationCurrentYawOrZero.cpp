#include <globaldefs.h>
struct Vec{int x,y,z;};struct Obj{char pad[0x50];Vec position;};struct Owner{char pad[0x14];void* first;Obj* second;Obj* third;};extern "C" int ActorSprite_GetFacingAngle(void*);
// Original: arm9/main @ 0x02040A20; symbol: func_02040a20; size: 0x70.
extern "C" ARM int Actor_GetRepresentationCurrentYawOrZero(Owner* p){if(p->first)return ActorSprite_GetFacingAngle(p->first);if(p->second){Vec v=p->second->position;return v.y;}if(p->third){Vec v=p->third->position;return v.y;}return 0;}
