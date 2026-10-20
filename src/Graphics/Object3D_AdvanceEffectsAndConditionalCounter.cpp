#include <globaldefs.h>
#include "World/Object3D.h"
struct Obj{char pad[0xac];unsigned short flags;char other[0x12];int value;char tail[0x10];unsigned char blocked:1;unsigned char rest:7;};extern "C" void Object3D_AdvancePositionTowardTargetAndFinish(Obj*),Object3D_AdvanceYawTowardTargetWithFixedStep(Obj*);
// Original: arm9/main @ 0x02041298; symbol: func_02041298; size: 0x5C.
extern "C" ARM void Object3D_AdvanceEffectsAndConditionalCounter(Obj* p,int amount){if(p->blocked)return;((Object3D*)p)->AdvanceEffects();if(p->flags&1)Object3D_AdvancePositionTowardTargetAndFinish(p);Object3D_AdvanceYawTowardTargetWithFixedStep(p);if(!(p->flags&1))p->value+=amount;else p->value=0;}
