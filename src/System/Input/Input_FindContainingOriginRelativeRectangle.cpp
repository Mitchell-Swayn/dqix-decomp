#include <globaldefs.h>
struct CoordinateHitRectangle { short left, top, right, bottom; };
struct CoordinateHitSet {
    unsigned int field0;
    unsigned char* origin;
    signed char count;
    unsigned char padding;
    CoordinateHitRectangle rectangles[1];
};
// Original: arm9/main @ 0x020E1EB0; symbol: func_020e1eb0; size: 0x6C.
// Finds the first inclusive rectangle containing a coordinate after origin offsets.
extern "C" int Input_FindContainingOriginRelativeRectangle(CoordinateHitSet* hits, int x, int y)
{
    for (int index = 0; index < hits->count; ++index) {
        int left = hits->origin[0x38] + hits->rectangles[index].left;
        int top = hits->origin[0x39] + hits->rectangles[index].top;
        int right = hits->origin[0x38] + hits->rectangles[index].right;
        int bottom = hits->origin[0x39] + hits->rectangles[index].bottom;
        if (left <= x && x <= right && top <= y && y <= bottom)
            return index;
    }
    return -1;
}
