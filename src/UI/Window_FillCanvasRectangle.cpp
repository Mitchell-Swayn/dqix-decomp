#include <globaldefs.h>
extern "C" void TextCanvas_FillRegionRectangle4Bpp(void*,int,int,int,int,int);struct Owner{int unused;void** object;};
// Original: arm9/main @ 0x020E23C0; symbol: func_020e23c0; size: 0x34.
extern "C" ARM void Window_FillCanvasRectangle(Owner* p,int b,int c,int d,short x,short y){TextCanvas_FillRegionRectangle4Bpp(p->object[1],c,d,x,y,b);}
