#include "Graphics/Vector.h"

#if defined(jpn)
#define Math_SinCosQ12Table data_020e955c
#endif

// Original data: arm9/main @ 0x20e9450; symbol: data_020e9450.
// Interleaved signed Q12 sine/cosine lookup table used by Fix32Sin and Fix32Cos. Source definition preserves the complete fixed-point table.
// Initial values: hex 00000010060000100d00001013000010190000101f000010260000102c00001032000010390000103f0000104500ff0f4b00ff0f5200ff0f5800ff0f5e00ff0f ...; full span in module reference.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const fix16_t Math_SinCosQ12Table[4096 * 2];

// Original: arm9/main @ 0x02030C68; symbol: _Z8fix32sini; size: 0x34.
fix32_t fix32sin(fix32_t x)
{
    // The table stores 4096 sine/cosine phase pairs; the 12-bit index wraps
    // values outside of (0, 2pi).
    unsigned short normalizedAngle = (x << 16) / FIX_2PI;
    int tableIndex = normalizedAngle >> 4;

    return Math_SinCosQ12Table[tableIndex * 2];
}

// Original: arm9/main @ 0x02030C9C; symbol: _Z8fix32cosi; size: 0x3C.
fix32_t fix32cos(fix32_t x)
{
    // The table stores 4096 sine/cosine phase pairs; the 12-bit index wraps
    // values outside of (0, 2pi).
    unsigned short normalizedAngle = (x << 16) / FIX_2PI;
    int tableIndex = normalizedAngle >> 4;

    return Math_SinCosQ12Table[tableIndex * 2 + 1];
}

// Original: arm9/main @ 0x02030CD8; symbol: _Z24fix32SignedAngleDistanceii; size: 0x4C.
fix32_t fix32SignedAngleDistance(fix32_t a, fix32_t b)
{
    fix32_t ret = 0;
    if (a < b)
    {
        ret = b - a;
        if (ret > 0x3244)
            ret -= 0x6488;
    }
    else if (b < a)
    {
        ret = -(a - b);
        if (ret < -0x3244)
            ret += 0x6488;
    }
    return ret;
}

// Original: arm9/main @ 0x02030D24; symbol: _Z8fix32absi; size: 0xC.
fix32_t fix32abs(fix32_t x)
{
    if (x < 0)
        x = -x;
    return x;
}

// Original: arm9/main @ 0x02030D30; symbol: _Z15RotationMatrixXi; size: 0x54.
Matrix4x3 RotationMatrixX(fix32_t angle)
{
    fix32_t sine = fix32sin(angle);
    fix32_t cosine = fix32cos(angle);

    Matrix4x3 ret;
    MTX_RotX43_(&ret, sine, cosine);
    return ret;
}

// Original: arm9/main @ 0x02030D84; symbol: _Z15RotationMatrixYi; size: 0x54.
Matrix4x3 RotationMatrixY(fix32_t angle)
{
    fix32_t sine = fix32sin(angle);
    fix32_t cosine = fix32cos(angle);

    Matrix4x3 ret;
    MTX_RotY43_(&ret, sine, cosine);
    return ret;
}

// Original: arm9/main @ 0x02030DD8; symbol: _Z15RotationMatrixZi; size: 0x54.
Matrix4x3 RotationMatrixZ(fix32_t angle)
{
    fix32_t sine = fix32sin(angle);
    fix32_t cosine = fix32cos(angle);

    Matrix4x3 ret;
    MTX_RotZ43_(&ret, sine, cosine);
    return ret;
}

// Original: arm9/main @ 0x02030E2C; symbol: _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_; size: 0x5C.
void Vector3fixMultiplyScalar(const Vector3fix* in, fix32_t scalar, Vector3fix* out)
{
    out->x = FIX32_MULTIPLY(in->x, scalar);
    out->y = FIX32_MULTIPLY(in->y, scalar);
    out->z = FIX32_MULTIPLY(in->z, scalar);
}

// Original: arm9/main @ 0x02030E88; symbol: _Z18Vector3fixMultiplyPK8Vector3iS1_PS_; size: 0x68.
void Vector3fixMultiply(const Vector3fix* a, const Vector3fix* b, Vector3fix* out)
{
    out->x = FIX32_MULTIPLY(a->x, b->x);
    out->y = FIX32_MULTIPLY(a->y, b->y);
    out->z = FIX32_MULTIPLY(a->z, b->z);
}

// Original: arm9/main @ 0x02030EF0; symbol: _Z22Vector3fixDivideScalarPK8Vector3iiPS_; size: 0x40.
void Vector3fixDivideScalar(const Vector3fix* in, fix32_t scalar, Vector3fix* out)
{
    out->x = fix32_Divide(in->x, scalar);
    out->y = fix32_Divide(in->y, scalar);
    out->z = fix32_Divide(in->z, scalar);
}

// Original: arm9/main @ 0x02030F30; symbol: _Z22fix32ReduceAngle0To2Pii; size: 0x98.
fix32_t fix32ReduceAngle0To2Pi(fix32_t angle)
{
    if (angle < 0)
    {
        // bitwise AND gets floor of (-angle / 2pi)
        fix32_t periods = (fix32_Divide(-angle, FIX_2PI) + (1 << 12)) & ~0xfff;
        angle += FIX32_MULTIPLY(periods, FIX_2PI);
    }
    else if (angle > FIX_2PI)
    {
        fix32_t periods = fix32_Divide(angle, FIX_2PI) & ~0xfff;
        angle -= FIX32_MULTIPLY(periods, FIX_2PI);
    }

    return angle;
}

// Original: arm9/main @ 0x02030FC8; symbol: _Z16Vector3fix16CopyP8Vector3sPKS_; size: 0x1C.
void Vector3fix16Copy(Vector3fix16* dst, const Vector3fix16* src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

// Original: arm9/main @ 0x02030FE4; symbol: _Z25Vector3fixSquaredDistancePK8Vector3iS1_; size: 0x70.
fix32_t Vector3fixSquaredDistance(const Vector3fix* a, const Vector3fix* b)
{
    fix32_t dx = a->x - b->x;
    fix32_t dy = a->y - b->y;
    fix32_t dz = a->z - b->z;

    fix32_t zsq = FIX32_MULTIPLY(dz, dz);
    fix32_t ysq = FIX32_MULTIPLY(dy, dy);
    fix32_t xsq = FIX32_MULTIPLY(dx, dx);

    fix32_t sum = xsq + ysq; // ...
    return xsq + ysq + zsq;
}

// Original: arm9/main @ 0x02031054; symbol: _Z22Vector3fixAngleToPointPK8Vector3iS1_; size: 0x48.
fix32_t Vector3fixAngleToPoint(const Vector3fix* source, const Vector3fix* target)
{
    Vector3fix difference;
    Vector3fix_Subtract(target, source, &difference);
    difference.y = 0;
    // not sure why we need this. is it just numerical stability?
    Vector3fix_Normalize(&difference, &difference);
    fix32_t angle = fix32_Atan2(difference.x, difference.z);
    return fix32ReduceAngle0To2Pi(angle);
}
