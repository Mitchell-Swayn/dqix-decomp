#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct Point { int x; float y; };
// Original: arm9/main @ 0x020578E8; symbol: func_020578e8; size: 0x3C.
extern "C" float Point_ComputeFloatingPointSlope(Point** a,Point** b) {
    Point* first=*a;
    Point* second=*b;
    float delta=second->y-first->y;
    return delta/(float)(second->x-first->x);
}
