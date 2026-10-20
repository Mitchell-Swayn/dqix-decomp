#include <globaldefs.h>
ARM
extern "C" void Resource_AdvanceMemberTaskStateMachine(char*);
struct Owner {char pad[0x774];unsigned short flags;char gap[7];signed char state;};
// Original: arm9/ov023 @ 0x021DFAD8; symbol: func_ov023_021dfad8; size: 0x74.
// Advances member loading and toggles main display plane zero when state equals two.
extern "C" void Graphics_AdvanceTaskAndToggleMainPlaneZero(Owner* self){
 Resource_AdvanceMemberTaskStateMachine((char*)self);
 if(self->state!=2)return;
 volatile unsigned* display=(volatile unsigned*)0x04000000;
 if(self->flags&0x800){unsigned planes=(*display&0x1f00)>>8;*display=(*display&~0x1f00)|((planes|1)<<8);}
 else {unsigned planes=(*display&0x1f00)>>8;*display=(*display&~0x1f00)|((planes&~1)<<8);}
}
