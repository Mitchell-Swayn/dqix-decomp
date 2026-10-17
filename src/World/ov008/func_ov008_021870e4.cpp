#include <World/Object3D.h>
extern "C" const char data_ov008_0218b495[];
// Original: arm9/ov008 @ 0x021870E4; symbol: func_ov008_021870e4; size: 0x48.
extern "C" void func_ov008_021870e4(unsigned char* object) {
    if(!(*(unsigned*)(object+0xb18)&0x4000)) return;
    if(!((Object3D*)(object+0x790))->HasAnimationReachedEnd()) return;
    ((Object3D*)(object+0x790))->MaybeSetRegularAnimation(data_ov008_0218b495,0);
    *(unsigned*)(object+0xb18)&=~0x4000;
}
