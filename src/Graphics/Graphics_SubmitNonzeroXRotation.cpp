#include <globaldefs.h>
ARM
struct Matrix43 {int v[12];};extern "C" Matrix43 _Z15RotationMatrixXi(int);extern "C" void Graphics_SubmitGeometryCommand25(const Matrix43*);
// Original: arm9/main @ 0x020311F0; symbol: func_020311f0; size: 0x44.
extern "C" void Graphics_SubmitNonzeroXRotation(int angle){if(angle){Matrix43 temp=_Z15RotationMatrixXi(angle);Graphics_SubmitGeometryCommand25(&temp);}}
