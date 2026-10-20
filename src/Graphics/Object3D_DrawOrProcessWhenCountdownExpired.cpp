#include <globaldefs.h>
#pragma bool on
#include "World/Object3D.h"
extern "C" void Object3D_DrawEffectHandle(Object3D*);struct State{unsigned char pad[0xac];int mode;short countdown;unsigned char rest[0x1a];unsigned char a:2;bool flag:1;};
// Original: arm9/main @ 0x0205A148; symbol: func_0205a148; size: 0x38.
extern "C" ARM void Object3D_DrawOrProcessWhenCountdownExpired(Object3D* p){State* s=(State*)p;if(s->countdown>0)return;if(s->mode==0){p->Draw(s->flag);return;}Object3D_DrawEffectHandle(p);}
