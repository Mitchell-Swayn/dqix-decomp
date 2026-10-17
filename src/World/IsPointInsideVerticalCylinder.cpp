#include <globaldefs.h>
#pragma always_inline on
struct FixedPointPosition { int x, y, z; };
struct FixedPointCylinder { int x, bottomY, z, radius, height; };
static inline int SquareQ12(int value) { return (int)(((long long)value * value + 0x800) >> 12); }
// Original: arm9/main @ 0x02032148; symbol: func_02032148; size: 0x98.
// Tests inclusive cylinder height and radius, rounding each Q12 squared distance before summing.
extern "C" ARM bool IsPointInsideVerticalCylinder(const FixedPointPosition* point, const FixedPointCylinder* cylinder)
{
    if (cylinder->bottomY > point->y) return false;
    if (cylinder->bottomY + cylinder->height < point->y) return false;
    int dx = point->x - cylinder->x;
    int dz = point->z - cylinder->z;
    int dzSquared = SquareQ12(dz);
    int dxSquared = SquareQ12(dx);
    int radiusSquared = SquareQ12(cylinder->radius);
    return radiusSquared >= dxSquared + dzSquared;
}
