#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <Graphics/Vector.h>

// Original data: arm9/main @ 0x02107874, 0x021078AC, 0x021078E4: the matrix members of the eye, target and
// attachment TrackedBoneMatrix entries registered by BoneTrackingCamera_RefreshTrackedBones.
extern Matrix4x3 BoneTrackingCameraUpdateEndpointsAndAttachment_UnknownRoleZeroInitializedStorage;
extern Matrix4x3 BoneTrackingCameraUpdateEndpointsAndAttachment_UnknownRoleZeroInitializedStorage_Variant2;
extern Matrix4x3 BoneTrackingCameraUpdateEndpointsAndAttachment_UnknownRoleZeroInitializedStorage_Variant3;

struct ManualCamera;
typedef unsigned int undefined4;
extern "C" {
void Camera_ApplyManualInput(ManualCamera* self);
undefined4 Camera_GetManualControlMode(int param_1);
void BoneTrackingCamera_RefreshTrackedBones(unsigned char* object);
void Camera_RecalculateOrbitAndEye(void* object);
void Object3D_SetNormalizedAngleAndUpdatePosition(char* object, int value);
}

// Original: arm9/main @ 0x0204A170; symbol: func_0204a170; size: 0x280.
// Copies the source object's transform onto the tracked model, places the camera eye and target at the
// scaled tracked eye/target bone positions, and moves the attached object to the third bone, turning it
// towards the bone (immediately, or halfway every third frame).
extern "C" void BoneTrackingCamera_UpdateEndpointsAndAttachment(unsigned char* object)
{
    Matrix4x3 eyeMatrix;
    Matrix4x3 targetMatrix;
    Matrix4x3 attachmentMatrix;
    if (*(Object3D**)(object + 0x21c) == 0)
        return;
    if (*(int*)(object + 0x260) >= 0) {
        GameState* state = GameState::GetInstance();
        GameObject* source = state->GetGameObjectByIndex(*(int*)(object + 0x260));
        if (source) {
            (*(Object3D**)(object + 0x21c))->position_ = source->obj3D_.position_;
            (*(Object3D**)(object + 0x21c))->rotation_ = source->obj3D_.rotation_;
            (*(Object3D**)(object + 0x21c))->SetScale(&source->obj3D_.GetScale());
        }
    }
    Camera_ApplyManualInput((ManualCamera*)object);
    if (Camera_GetManualControlMode((int)object) != 0)
        return;
    BoneTrackingCamera_RefreshTrackedBones(object);
    const Vector3fix& scale = (*(Object3D**)(object + 0x21c))->GetScale();
    Vector3fix eye;
    Vector3fix target;
    Vector3fix attachment;
    (*(Object3D**)(object + 0x21c))->UpdateTrackedBoneMatrices();
    eyeMatrix = BoneTrackingCameraUpdateEndpointsAndAttachment_UnknownRoleZeroInitializedStorage;
    targetMatrix = BoneTrackingCameraUpdateEndpointsAndAttachment_UnknownRoleZeroInitializedStorage_Variant2;
    attachmentMatrix = BoneTrackingCameraUpdateEndpointsAndAttachment_UnknownRoleZeroInitializedStorage_Variant3;
    eye.x = eyeMatrix.translation.x;
    eye.y = eyeMatrix.translation.y;
    eye.z = eyeMatrix.translation.z;
    target.x = targetMatrix.translation.x;
    target.y = targetMatrix.translation.y;
    target.z = targetMatrix.translation.z;
    attachment.x = attachmentMatrix.translation.x;
    attachment.y = attachmentMatrix.translation.y;
    attachment.z = attachmentMatrix.translation.z;
    Vector3fixMultiply(&eye, &scale, &eye);
    Vector3fixMultiply(&target, &scale, &target);
    Vector3fixMultiply(&attachment, &scale, &attachment);
    Object3D* model = *(Object3D**)(object + 0x21c);
    Vector3fix_Add(&eye, &model->position_, &eye);
    Vector3fix_Add(&target, &model->position_, &target);
    Vector3fix_Add(&attachment, &model->position_, &attachment);
    *(Vector3fix*)(object + 0x10) = target;
    *(Vector3fix*)(object + 0x4) = eye;
    Camera_RecalculateOrbitAndEye(object);
    Object3D* attached = *(Object3D**)(object + 0x220);
    if (attached == 0)
        return;
    int heading = fix32ReduceAngle0To2Pi(fix32_Atan2(attachment.x - attached->position_.x, attachment.z - attached->position_.z));
    Object3D* moved = *(Object3D**)(object + 0x220);
    moved->position_ = attachment;
    if (object[0x265] != 0)
        return;
    if (++object[0x264] >= 3) {
        Object3D_SetNormalizedAngleAndUpdatePosition((char*)moved, FIX32_MULTIPLY(attached->rotation_.y + heading, 0x800));
        object[0x264] = 0;
    } else {
        Object3D_SetNormalizedAngleAndUpdatePosition((char*)moved, attached->rotation_.y);
    }
}
