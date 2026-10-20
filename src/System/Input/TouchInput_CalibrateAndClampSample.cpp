#include <globaldefs.h>

ARM
#pragma optimize_for_size off
extern "C" {
struct Input { unsigned short x,y; unsigned short touching,other; };
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char TPWaitBusy_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x21117cc; symbol: data_021117cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern int TouchInputCalibrateAndClampSample_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020CDFD8; symbol: func_020cdfd8; size: 0x124.
void TouchInput_CalibrateAndClampSample(Input *out, const Input *in) {
    if (*(unsigned short *)(TPWaitBusy_UnknownRoleZeroInitializedStorage+0x34)==0) { unsigned short x=((const volatile Input *)in)->x,y=((const volatile Input *)in)->y;out->x=x;out->y=y;unsigned short touching=((const volatile Input *)in)->touching,other=((const volatile Input *)in)->other;out->touching=touching;out->other=other; return; }
    int *calibration = TouchInputCalibrateAndClampSample_UnknownRoleZeroInitializedStorage;
    out->touching=in->touching; out->other=in->other;
    if(!in->touching){out->x=0;out->y=0;return;}
    out->x=((((long long)((int)in->x*4))-calibration[0])*calibration[2])>>22;
    if ((short)out->x<0) out->x=0; else if((short)out->x>255) out->x=255;
    out->y=((((long long)((int)in->y*4))-calibration[3])*calibration[5])>>22;
    if ((short)out->y<0) out->y=0; else if((short)out->y>191) out->y=191;

}
}
