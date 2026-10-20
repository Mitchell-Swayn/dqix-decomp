#include <globaldefs.h>
struct XYZ { int x,y,z; }; struct Matrix { int values[12]; };
extern "C" { void Vector3fix_Subtract(const XYZ*,const XYZ*,XYZ*); void Vector3fix_Add(const XYZ*,const XYZ*,XYZ*); void _Z15RotationMatrixYi(Matrix*,int); void Mat4x3_ApplyToVector(const XYZ*,const Matrix*,XYZ*); void _ZN8Vector3iaSERKS_(void*,const XYZ*); void Camera_RecalculateOrbitAndEye(void*); }
// Original: arm9/main @ 0x0202E894; symbol: func_0202e894; size: 0xA4.
extern "C" ARM void Camera_RotateTargetAroundEye(char* object,int angle) { XYZ origin=*(XYZ*)(object+4); XYZ end=*(XYZ*)(object+16); Matrix rotation; Matrix copy; XYZ delta; Vector3fix_Subtract(&end,&origin,&delta); _Z15RotationMatrixYi(&rotation,angle); copy=rotation; Mat4x3_ApplyToVector(&delta,&copy,&delta); Vector3fix_Add(&origin,&delta,&end); _ZN8Vector3iaSERKS_(object+16,&end); Camera_RecalculateOrbitAndEye(object); }
