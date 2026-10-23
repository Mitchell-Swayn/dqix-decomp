#include <globaldefs.h>
#include <Graphics/Vector.h>
ARM
#pragma opt_propagation off // Preserve the separate rounded-square stages.
extern "C" bool Bounds3D_ContainsPoint(int*, int*);

// Original: arm9/main @ 0x020321E0; symbol: func_020321e0; size: 0xE0.
// Applies inverse yaw about the center before testing the original axis-aligned bounds.
extern "C" int Bounds3D_ContainsPointWithInverseYaw(const Vector3fix* point,
    const Vector3fix* bounds, int yaw, const Vector3fix* center, int radiusSquared)
{
    Vector3fix transformed = *point;
    if (yaw) {
        Vector3fix delta;
        Vector3fix_Subtract(point, center, &delta);
        int zz = FIX32_MULTIPLY(delta.z, delta.z);
        int xx = FIX32_MULTIPLY(delta.x, delta.x);
        if (radiusSquared < xx + zz) return 0;
        Matrix4x3 rotation = RotationMatrixY(fix32ReduceAngle0To2Pi(-yaw));
        Mat4x3_ApplyToVector(&delta, &rotation, &delta);
        Vector3fix_Add(&delta, center, &transformed);
    }
    return Bounds3D_ContainsPoint((int*)&transformed, (int*)bounds);
}
