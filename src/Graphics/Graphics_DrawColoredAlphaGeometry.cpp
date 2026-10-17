#include <globaldefs.h>
struct VertexTable { int xyz[4][3]; };
extern "C" const VertexTable data_020e8804;
extern "C" void Graphics_WritePackedPolygonAttributeFields_Main0207076C(int,int,int,int,int,int);
extern "C" void Graphics_WriteThreeVertexCoordinates(short,short,short);
#define REG(a) (*(volatile unsigned int*)(a))
// Original: arm9/main @ 0x0207051C; symbol: func_0207051c; size: 0x250.
extern "C" void Graphics_DrawColoredAlphaGeometry(int unused, unsigned int color, int alpha) {
    VertexTable vertices = data_020e8804;
    REG(0x040004a8) = 0x900000;
    Graphics_WritePackedPolygonAttributeFields_Main0207076C(0,0,3,0x3a,alpha,0x8000);
    REG(0x04000444) = 0;
    REG(0x0400046c) = 0x100000;
    REG(0x0400046c) = 0xc0000;
    REG(0x0400046c) = 0;
    REG(0x04000500) = 1;
    REG(0x04000480) = color;
    Graphics_WriteThreeVertexCoordinates((short)vertices.xyz[0][0],(short)vertices.xyz[0][1],(short)vertices.xyz[0][2]);
    Graphics_WriteThreeVertexCoordinates((short)vertices.xyz[1][0],(short)vertices.xyz[1][1],(short)vertices.xyz[1][2]);
    Graphics_WriteThreeVertexCoordinates((short)vertices.xyz[2][0],(short)vertices.xyz[2][1],(short)vertices.xyz[2][2]);
    Graphics_WriteThreeVertexCoordinates((short)vertices.xyz[3][0],(short)vertices.xyz[3][1],(short)vertices.xyz[3][2]);
    REG(0x04000504) = 0;
    REG(0x04000448) = 1;
    if (alpha == 31) {
        Graphics_WritePackedPolygonAttributeFields_Main0207076C(0,0,3,0x3a,0,0x8000);
        REG(0x04000444) = 0;
        REG(0x0400046c) = 0x100000;
        REG(0x0400046c) = 0xc0000;
        REG(0x0400046c) = 0;
        REG(0x04000500) = 1;
        REG(0x04000480) = color;
        Graphics_WriteThreeVertexCoordinates((short)vertices.xyz[0][0],(short)vertices.xyz[0][1],(short)vertices.xyz[0][2]);
        Graphics_WriteThreeVertexCoordinates((short)vertices.xyz[1][0],(short)vertices.xyz[1][1],(short)vertices.xyz[1][2]);
        Graphics_WriteThreeVertexCoordinates((short)vertices.xyz[2][0],(short)vertices.xyz[2][1],(short)vertices.xyz[2][2]);
        Graphics_WriteThreeVertexCoordinates((short)vertices.xyz[3][0],(short)vertices.xyz[3][1],(short)vertices.xyz[3][2]);
        REG(0x04000504) = 0;
        REG(0x04000448) = 1;
    }
}
