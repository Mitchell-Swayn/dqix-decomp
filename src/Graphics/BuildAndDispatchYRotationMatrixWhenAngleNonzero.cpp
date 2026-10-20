#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
extern "C" void Graphics_SubmitGeometryCommand25(const Matrix4x3*);
// Original: arm9/main @ 0x02031234; symbol: func_02031234; size: 0x44.
extern "C" void BuildAndDispatchYRotationMatrixWhenAngleNonzero(int angle){if(angle){Matrix4x3 original=RotationMatrixY(angle);Graphics_SubmitGeometryCommand25(&original);}}
