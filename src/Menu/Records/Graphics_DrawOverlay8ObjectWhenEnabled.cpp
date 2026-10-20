#include <World/Object3D.h>
// Original: arm9/ov008 @ 0x02184918; symbol: func_ov008_02184918; size: 0x50.
extern "C" void Graphics_DrawOverlay8ObjectWhenEnabled(signed char* object) {
    int state=object[0xb10];
    if(state==0 || state==14 || (*(unsigned*)(object+0xb18)&0x80)) return;
    *(volatile unsigned*)0x04000444=0;
    ((Object3D*)(object+0x790))->Draw(false);
    *(volatile unsigned*)0x04000448=1;
}
