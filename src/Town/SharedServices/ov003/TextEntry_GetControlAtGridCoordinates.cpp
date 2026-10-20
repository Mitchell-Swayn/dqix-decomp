#include <globaldefs.h>
ARM
struct HalfwordGrid { unsigned char unknown; signed char width,height; unsigned char padding; short* values; };
// Original: arm9/ov003 @ 0x0215E9A4; symbol: TextEntry_GetControlAtGridCoordinates; size: 0x48.
// Returns a signed halfword from the row-major grid, or -1 for an out-of-range coordinate.
extern "C" int TextEntry_GetControlAtGridCoordinates(const HalfwordGrid* grid,int x,int y) {
    if (x>=0 && x<grid->width && y>=0 && y<grid->height) {
        short* row=grid->values+grid->width*y;
        return row[x];
    }
    return -1;
}
