#include <globaldefs.h>
#include <System/Matrix.h>
#include <Graphics/NSBXX/RenderConfig.h>
ARM
// Original: arm9/ov017 @ 0x02196048; symbol: func_ov017_02196048; size: 0x70.
// Stores the eye/up/target vectors, writes the render view matrix and clears the original view-state flag mask.
extern "C" void Graphics_WriteViewMatrixAndClearStateFlags(const Vector3fix* eye,const Vector3fix* up,const Vector3fix* target)
{
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.eyeVector=*eye;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.upVector=*up;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.targetVector=*target;
    Mat4x3_WriteViewMatrix(eye,up,target,&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewMatrix);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags &= ~0xe8;
}
