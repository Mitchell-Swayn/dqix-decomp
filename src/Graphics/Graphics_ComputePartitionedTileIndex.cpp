#include <globaldefs.h>
#pragma optimize_for_size off
// Original data: arm9/main @ 0x20e91e0; symbol: data_020e91e0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000010002000200000101010201020100020102020203020002010202030303.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char GraphicsComputePartitionedTileIndex_UnknownRoleInitializedBytes[4][4][2];
// The pinned CodeWarrior compiler has no CLZ intrinsic. The original uses CLZ
// for floor-log2; only the two CLZ hardware primitives remain in assembly.
// Original: arm9/main @ 0x020B10B4; symbol: func_020b10b4; size: 0xF8.
// Computes a tile index in an alignment-partitioned rectangle.
extern "C" ARM unsigned Graphics_ComputePartitionedTileIndex(unsigned x, unsigned y, int width, int height, int initialWidthShift, int initialHeightShift)
{
    unsigned mask;
    unsigned offset;
    int heightShift;
    int widthShift;
    widthShift=initialWidthShift;
    heightShift=initialHeightShift;
    offset=0;
        for (;;) {
        mask=~0u;
        unsigned alignedWidth;
        unsigned alignedHeight;
        alignedWidth=width & (mask<<widthShift);
        alignedHeight=height & (mask<<heightShift);
        if (alignedHeight<=y) {
            offset+=width*alignedHeight;
            if (alignedWidth<=x) {
                height-=alignedHeight;
                offset+=alignedWidth*height;
                x-=alignedWidth;
                y-=alignedHeight;
                width-=alignedWidth;
            } else {
                width=alignedWidth;
                y-=alignedHeight;
                height-=alignedHeight;
            }
        } else {
            unsigned heightMask=~(mask<<heightShift);
            if (alignedWidth<=x) {
                offset+=alignedWidth*alignedHeight;
                height=alignedHeight;
                x-=alignedWidth;
                width-=alignedWidth;
            } else {
                unsigned row=y & (mask<<heightShift);
                offset+=alignedWidth*row;
                unsigned column=x & (mask<<widthShift);
                unsigned widthMask=~(mask<<widthShift);
                offset+=(column<<heightShift);
                offset+=((y&heightMask)<<widthShift);
                offset+=(x&widthMask);
                return offset;
            }
        }
        if(width>=8) heightShift=3;
        else {heightShift=width; asm {clz heightShift,heightShift} heightShift=31-heightShift;}
        if(height>=8) widthShift=3;
        else {widthShift=height; asm {clz widthShift,widthShift} widthShift=31-widthShift;}
        unsigned char* shifts=GraphicsComputePartitionedTileIndex_UnknownRoleInitializedBytes[widthShift][heightShift];
        widthShift=shifts[0];
        heightShift=shifts[1];
        // Preserve the original stores to the incoming shift argument slots.
        *(volatile int*)&initialWidthShift=widthShift;
        *(volatile int*)&initialHeightShift=heightShift;
    }
}
