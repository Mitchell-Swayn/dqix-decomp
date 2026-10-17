#include <globaldefs.h>

union Pair { struct { int x,y; }; long long packed; };
#pragma force_active on
// Original: arm9/ov000 @ 0x0216F74C; symbol: func_ov000_0216f74c; size: 0xE0.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" void ComputeGridIndexCoordinatePair(Pair* out, int* index)
{
    int q=*index/9; int r=*index%9; volatile Pair values; values.x=(int)(-42566.87890625f + (float)r * 10641.7197265625f + (float)(q%2) * 5320.85986328125f); int y=(int)(-36864.0f + (float)q * 3072.0f * 3.0f); values.y=y; out->x=values.x; out->y=y;
}
