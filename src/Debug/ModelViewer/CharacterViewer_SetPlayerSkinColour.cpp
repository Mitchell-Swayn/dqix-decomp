#include <globaldefs.h>
struct ViewState { char opaque0[0x1c]; unsigned char mode; char opaque1[3]; int* values; void* resource; unsigned word28; unsigned char dirty; char opaque2[0x3b - 0x2d]; unsigned char value3b,value3c,value3d,value3e,unused3f; short height,width; };
// Original: arm9/ov015 @ 0x0218FFD0; symbol: func_ov015_0218ffd0; size: 0x28.
extern "C" ARM void CharacterViewer_SetPlayerSkinColour(ViewState* p,int value){if(p->mode==0||p->mode==1){if(p->value3d!=value){p->value3d=value;p->dirty=1;}}}
