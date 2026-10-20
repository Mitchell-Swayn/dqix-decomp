#include <globaldefs.h>
#include <System/Matrix.h>
#include <Graphics/NSBXX/RenderConfig.h>
#include <Graphics/NSBXX/GeometryFifo.h>
ARM

typedef unsigned int uint;
extern "C" {
void* __clear(void* destination, unsigned int count);
uint GameResources_GetMaskedSecondaryFlags(int param_1, uint param_2);
void* Object_GetGlobalSixteenEntryDisplayState();
void ObjectPool_DrawMarkedDisplayEntries(unsigned char* owner);
void MIi_CpuCopyFast(const void*, void*, unsigned);
void Graphics_WriteViewMatrixAndClearStateFlags(const Vector3fix* eye, const Vector3fix* up, const Vector3fix* target);
void FieldCommandQueue_DrawFrontCommandModel(void* p);
}
extern Vector3fix FieldDrawMarkedObjectsAndSceneCommands_UnknownRoleInitializedBytes;
extern Vector3fix FieldDrawMarkedObjectsAndSceneCommands_UnknownRoleInitializedBytes_Variant2;

// Original: arm9/ov017 @ 0x02195ECC; symbol: func_ov017_02195ecc; size: 0x17c.
// Saves the active projection and view, applies a temporary overlay camera, draws
// marked display entries and the front field command model, then restores state.
extern "C" void Field_DrawMarkedObjectsAndSceneCommands(int owner, unsigned mode)
{
    if (mode == 0)
        return;

    Vector3fix savedEye = RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.eyeVector;
    Vector3fix savedUp = RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.upVector;
    Vector3fix savedTarget = RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.targetVector;
    Matrix4x4 savedProjection = RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.projectionMatrix;

    Vector3fix eye = FieldDrawMarkedObjectsAndSceneCommands_UnknownRoleInitializedBytes;
    Vector3fix target;
    __clear(&target, 0xc);
    Vector3fix up = FieldDrawMarkedObjectsAndSceneCommands_UnknownRoleInitializedBytes_Variant2;

    Mat4x4_WriteProjectionUnknown(0xe000, 0xe000 - 0x30000, 0xe000 - 0x2e000,
                                  0x20000, 0x1000, 0x190000, 0x1000,
                                  &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.projectionMatrix);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags &= ~0x50u;
    Graphics_WriteViewMatrixAndClearStateFlags(&eye, &up, &target);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();

    if (mode & 1) {
        unsigned char* displayState = (unsigned char*)Object_GetGlobalSixteenEntryDisplayState();
        if (GameResources_GetMaskedSecondaryFlags(owner, 0x20) == 0)
            ObjectPool_DrawMarkedDisplayEntries(displayState);
    }
    if (mode & 2)
        FieldCommandQueue_DrawFrontCommandModel(*(void**)(owner + 0x36fc));

    Graphics_WriteViewMatrixAndClearStateFlags(&savedEye, &savedUp, &savedTarget);
    MIi_CpuCopyFast(&savedProjection, &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.projectionMatrix, 0x40);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags &= ~0x50u;
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
}
