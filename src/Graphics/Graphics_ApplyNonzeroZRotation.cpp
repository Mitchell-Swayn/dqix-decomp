#include <globaldefs.h>
#include <Graphics/Vector.h>
extern "C" void Graphics_SubmitGeometryCommand25(const Matrix4x3*);
// Original: arm9/main @ 0x02031278; symbol: func_02031278; size: 0x44.
extern "C" void Graphics_ApplyNonzeroZRotation(int angle) { if(angle) { Matrix4x3 copied=RotationMatrixZ(angle); Graphics_SubmitGeometryCommand25(&copied); } }
