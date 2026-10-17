#include <globaldefs.h>
struct Anim{char pad[0x9a0];int mode;char pad2[0x100a];signed char frame;bool phase;char pad3[0x1a];unsigned char active;};
#pragma optimization_level 3
// Original: arm9/main @ 0x020456D0; symbol: func_020456d0; size: 0x70.
extern "C" ARM void Object_AdvanceThirtyTwoFrameBlinkPhase(Anim* p){if(p->mode==1||p->mode==3||p->mode==2){if(!p->active)return;++p->frame;p->frame&=31;p->phase=p->frame>15;}else{p->frame=0;p->phase=0;}}
