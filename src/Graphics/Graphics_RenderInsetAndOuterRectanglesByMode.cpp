#include <globaldefs.h>

ARM
extern "C" {
extern unsigned int data_020ef74c[];
void Graphics_WritePackedPolygonAttributes(int,int,int,int,int,int);
void Graphics_SubmitFixedPointQuadRegisters(int,int,int,int,int);
// Original: arm9/main @ 0x02029384; symbol: func_02029384; size: 0xEC.
int Graphics_RenderInsetAndOuterRectanglesByMode(int x,int y,int width,int height) {
    if (data_020ef74c[3] == 2) return 0;
    if (data_020ef74c[3] == 4) return 0;
    volatile unsigned short *control = (volatile unsigned short *)0x04000060;
    *control = (*control & ~0x3000) | 4;
    *(volatile unsigned short *)0x04000340 = 0;
    *(volatile unsigned int *)0x040004a8 = 0x900000;
    Graphics_WritePackedPolygonAttributes(0,1,3,0x3b,0x12,0);
    Graphics_SubmitFixedPointQuadRegisters(x+2,y+2,width-4,height-4,0);
    Graphics_WritePackedPolygonAttributes(0,1,3,0,0,0);
    Graphics_SubmitFixedPointQuadRegisters(x,y,width,height,0x7fff);
    return 1;
}
}
