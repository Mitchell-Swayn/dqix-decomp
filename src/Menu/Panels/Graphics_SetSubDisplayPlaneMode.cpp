#include <globaldefs.h>
ARM
struct Owner {char pad[0x1d72];unsigned short flags;};
struct DisplayControl {unsigned low:8,planes:5,high:19;};
// Original: arm9/ov023 @ 0x021F1818; symbol: func_ov023_021f1818; size: 0x50.
// Toggles owner flag 0x80 and selects sub-display plane mask 2 or 23.
extern "C" void Graphics_SetSubDisplayPlaneMode(Owner* self,int enabled){
 if(enabled){self->flags|=0x80;((volatile DisplayControl*)0x04001000)->planes=2;}
 else {self->flags&=~0x80;((volatile DisplayControl*)0x04001000)->planes=23;}
}
