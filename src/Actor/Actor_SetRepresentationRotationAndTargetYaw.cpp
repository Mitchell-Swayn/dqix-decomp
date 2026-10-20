#include <globaldefs.h>
ARM
struct State{int pad[5];unsigned char* a;unsigned char* b;unsigned char* c;};extern "C" {void ActorSprite_SetQuantizedFacingAndTarget(void*,int,int,int);void Object3D_SetRotationComponents(void*);
// Original: arm9/main @ 0x0204085C; symbol: func_0204085c; size: 0x6C.
void Actor_SetRepresentationRotationAndTargetYaw(State* p,int x,int y,int z){unsigned char* a=p->a;if(a){*(int*)(a+16)=x;*(int*)(a+20)=y;*(int*)(a+24)=z;ActorSprite_SetQuantizedFacingAndTarget(p->a,y,y,z);return;}if(p->b){Object3D_SetRotationComponents(p->b);*(int*)(p->b+0xb0)=y;return;}if(p->c){Object3D_SetRotationComponents(p->c);*(int*)(p->c+0x2d4)=y;}}}
