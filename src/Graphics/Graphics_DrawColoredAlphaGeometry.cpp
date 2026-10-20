#include <globaldefs.h>
struct VertexTable { int xyz[4][3]; };
// Original data: arm9/main @ 0x20e8804; symbol: data_020e8804.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00100000001000000000000000f0ffff001000000000000000f0ffff00f0ffff000000000010000000f0ffff00000000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const VertexTable GraphicsDrawColoredAlphaGeometry_UnknownRoleInitializedBytes;
extern "C" void AlphaGeometry_WritePolygonAttributes(int,int,int,int,int,int);
extern "C" void Graphics_WriteThreeVertexCoordinates(short,short,short);
#define REG(a) (*(volatile unsigned int*)(a))
// Original: arm9/main @ 0x0207051C; symbol: func_0207051c; size: 0x250.
extern "C" void Graphics_DrawColoredAlphaGeometry(int unused, unsigned int color, int alpha) {
    VertexTable vertices = GraphicsDrawColoredAlphaGeometry_UnknownRoleInitializedBytes;
    REG(0x040004a8) = 0x900000;
    AlphaGeometry_WritePolygonAttributes(0,0,3,0x3a,alpha,0x8000);
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
        AlphaGeometry_WritePolygonAttributes(0,0,3,0x3a,0,0x8000);
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
