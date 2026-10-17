#include "System/Matrix.h"
// Fixed-point segment/triangle intersection, with barycentric output weights.
// Original: arm9/main @ 0x02031B84; symbol: func_02031b84; size: 0x19C.
extern "C" int Geometry_IntersectSegmentWithFrontFacingTriangle(const Vector3fix* start, const Vector3fix* end, const Vector3fix* a,
    const Vector3fix* b, const Vector3fix* c, int unused, int* weightA, int* weightB, int* weightC, int* distance)
{
    struct Temporaries { Vector3fix cross, offset, normal, direction, edgeC, edgeB; } temp;
    Vector3fix_Subtract(b, a, &temp.edgeB);
    Vector3fix_Subtract(c, a, &temp.edgeC);
    Vector3fix_Subtract(start, end, &temp.direction);
    Vector3fix_CrossProduct(&temp.edgeB, &temp.edgeC, &temp.normal);
    int denominator = Vector3fix_InnerProduct(&temp.direction, &temp.normal);
    if (denominator <= 0) return 0;
    Vector3fix_Subtract(start, a, &temp.offset);
    *distance = Vector3fix_InnerProduct(&temp.offset, &temp.normal);
    if (*distance < 0) return 0;
    if (*distance > denominator) return 0;
    Vector3fix_CrossProduct(&temp.direction, &temp.offset, &temp.cross);
    *weightB = Vector3fix_InnerProduct(&temp.edgeC, &temp.cross);
    if (*weightB < 0 || *weightB > denominator) return -1;
    *weightC = -Vector3fix_InnerProduct(&temp.edgeB, &temp.cross);
    if (*weightC < 0 || *weightB + *weightC > denominator) return -1;
    int reciprocal = fix32_Divide(0x1000, denominator);
    *distance = (int)(((long long)*distance * reciprocal + 0x800) >> 12);
    *weightB = (int)(((long long)*weightB * reciprocal + 0x800) >> 12);
    *weightC = (int)(((long long)*weightC * reciprocal + 0x800) >> 12);
    *weightA = (0x1000 - *weightB) - *weightC;
    return 1;
}
