#include <globaldefs.h>
struct ViewState { char opaque0[0x1c]; unsigned char mode; char opaque1[3]; int* values; void* resource; unsigned word28; unsigned char dirty; char opaque2[0x3b - 0x2d]; unsigned char value3b,value3c,value3d,value3e,unused3f; short height,width; };
// Original: arm9/ov015 @ 0x0219005C; symbol: func_ov015_0219005c; size: 0x34.
extern "C" ARM void func_ov015_0219005c(ViewState* p,int width,int height){if(p->mode==0||p->mode==1){if(p->width!=width||p->height!=height){p->width=width;p->height=height;p->dirty=2;}}}
