#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "GameState/GameState.h"
#pragma thumb off

struct Camera {
    unsigned objectHeader;
    Vector3fix eye, target, up; // +004,+010,+01c
    unsigned char reserved028[0x34];
    fix32_t projectionSine, projectionCosine, aspect, nearPlane, farPlane; // +05c
    unsigned char reserved070[0x0c];
    short roll;
    unsigned char reserved07E[0x72];
    Matrix4x3 transform; // +0f0
    Vector3fix worldEye, worldTarget, direction; // +120,+12c,+138
    Matrix3x3 inverseViewRotation; // +144
    unsigned flags; // +168
    unsigned char tracks[0x78];
    int shakeAmplitude; // +1e4
    unsigned shakeTime;
    unsigned char reserved1EC[0x0c];
    unsigned char bobEnabled;
    unsigned char reserved1F9;
    unsigned short bobPhase;
    fix32_t bobOffset;
    float bobSpeed;
    fix32_t bobAmplitude, minimumEyeHeight;
    unsigned char minimumHeightEnabled;
    unsigned char reserved20D[5];
    short yaw;
};
extern "C" {
void MotionOwner_AdvanceThreeTracksPositionAndAngle(Camera*);
void Graphics_AdvanceTimedAngleTransition(Camera*);
// Original data: arm9/main @ 0x20e73c0; symbol: data_020e73c0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000010000000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Vector3fix CameraUpdateRenderView_UnknownRoleInitializedBytes;
// Original data: arm9/main @ 0x20e9450; symbol: data_020e9450.
// Interleaved signed Q12 sine/cosine lookup table used by Fix32Sin and Fix32Cos. Source definition preserves the complete fixed-point table.
// Initial values: hex 00000010060000100d00001013000010190000101f000010260000102c00001032000010390000103f0000104500ff0f4b00ff0f5200ff0f5800ff0f5e00ff0f ...; full span in module reference.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern short Math_SinCosQ12Table[];
}
// Rotate the eye-to-target displacement, keeping the eye fixed.
static inline void ApplyCameraYaw(Vector3fix* eye, Vector3fix* target, short yaw)
{
    Vector3fix direction;
    Vector3fix_Subtract(target, eye, &direction);
    Matrix4x3 rotation = RotationMatrixY(yaw);
    Mat4x3_ApplyToVector(&direction, &rotation, &direction);
    Vector3fix_Add(eye, &direction, target);
}
// Original: arm9/main @ 0x0202E0A4; symbol: func_0202e0a4; size: 0x51C.
// Update the animated camera, apply shake/bob/roll, and publish its render view.
extern "C" void Camera_UpdateRenderView(Camera* self)
{
    MotionOwner_AdvanceThreeTracksPositionAndAngle(self);
    Graphics_AdvanceTimedAngleTransition(self);
    self->worldEye = self->eye;
    self->worldTarget = self->target;
    if (self->flags & 1) {
        Mat4x3_ApplyToVector(&self->worldEye, &self->transform, &self->worldEye);
        Mat4x3_ApplyToVector(&self->worldTarget, &self->transform, &self->worldTarget);
    }
    Mat4x4_MaybeWriteFrustum(self->projectionSine, self->projectionCosine, self->aspect,
        self->nearPlane, self->farPlane, 0x1000, &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.projectionMatrix);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags &= ~0x50;
    if (!self->roll) {
        self->up.x = 0; self->up.y = 0x1000; self->up.z = 0;
    } else {
        Vector3fix up = CameraUpdateRenderView_UnknownRoleInitializedBytes;
        Matrix4x3 rotation = RotationMatrixZ(self->roll);
        Mat4x3_ApplyToVector(&up, &rotation, &up);
        Vector3fix direction;
        Vector3fix_Subtract(&self->worldTarget, &self->worldEye, &direction);
        direction.y = 0;
        Vector3fix_Normalize(&direction, &direction);
        rotation = RotationMatrixY(fix32ReduceAngle0To2Pi(fix32_Atan2(direction.x,direction.z)));
        Mat4x3_ApplyToVector(&up, &rotation, &self->up);
    }
    Vector3fix eye = self->worldEye;
    Vector3fix target = self->worldTarget;
    if (self->shakeTime && !(self->flags & 4)) {
        if (self->shakeTime <= 33) {
            self->shakeTime = 0; self->shakeAmplitude = 0;
        } else {
            self->shakeTime -= 33;
            int amplitude = self->shakeAmplitude;
            self->shakeAmplitude = amplitude - amplitude * 33 / self->shakeTime;
        }
    }
    if (self->shakeAmplitude > 0) {
        const Matrix4x3* view = &RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewMatrix;
        Vector3fix horizontal = {view->entries[0],view->entries[1],view->entries[2]};
        Vector3fix vertical = {view->entries[3],view->entries[4],view->entries[5]};
        switch (rand() % 4) {
        case 0:
            Vector3fixMultiplyScalar(&horizontal,self->shakeAmplitude,&horizontal);
            Vector3fixMultiplyScalar(&vertical,self->shakeAmplitude,&vertical);
            break;
        case 1:
            Vector3fixMultiplyScalar(&horizontal,-self->shakeAmplitude,&horizontal);
            Vector3fixMultiplyScalar(&vertical,self->shakeAmplitude,&vertical);
            break;
        case 2:
            Vector3fixMultiplyScalar(&horizontal,self->shakeAmplitude,&horizontal);
            Vector3fixMultiplyScalar(&vertical,-self->shakeAmplitude,&vertical);
            break;
        case 3:
            Vector3fixMultiplyScalar(&horizontal,-self->shakeAmplitude,&horizontal);
            Vector3fixMultiplyScalar(&vertical,-self->shakeAmplitude,&vertical);
            break;
        }
        Vector3fix_Add(&eye,&horizontal,&eye);
        Vector3fix_Add(&eye,&vertical,&eye);
        Vector3fix_Add(&target,&horizontal,&target);
        Vector3fix_Add(&target,&vertical,&target);
    }
    if (self->bobEnabled) {
        self->bobPhase += (int)(self->bobSpeed * (float)(GameState::GetInstance()->GetTickCount() * 182));
        self->bobOffset = Math_SinCosQ12Table[2*(self->bobPhase >> 4)+1] >> 3;
        self->bobOffset = FIX32_MULTIPLY(self->bobOffset,self->bobAmplitude);
        eye.y += self->bobOffset;
        target.y += self->bobOffset;
    }
    if (self->minimumHeightEnabled && eye.y < self->minimumEyeHeight)
        eye.y = self->minimumEyeHeight;
    short yaw = self->yaw;
    if (yaw) {
        ApplyCameraYaw(&eye,&target,yaw);
    }
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.eyeVector = eye;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.upVector = self->up;
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.targetVector = target;
    Mat4x3_WriteViewMatrix(&eye,&self->up,&target,&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.viewMatrix);
    RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage.flags &= ~0xe8;
    Vector3fix_Subtract(&self->worldTarget,&self->worldEye,&self->direction);
    Vector3fix_Normalize(&self->direction,&self->direction);
    const Matrix4x3* inverse = RenderConfig::GetInverseViewMatrix();
    self->inverseViewRotation.entries[0] = inverse->entries[0];
    self->inverseViewRotation.entries[1] = inverse->entries[1];
    self->inverseViewRotation.entries[2] = inverse->entries[2];
    self->inverseViewRotation.entries[3] = inverse->entries[3];
    self->inverseViewRotation.entries[4] = inverse->entries[4];
    self->inverseViewRotation.entries[5] = inverse->entries[5];
    self->inverseViewRotation.entries[6] = inverse->entries[6];
    self->inverseViewRotation.entries[7] = inverse->entries[7];
    self->inverseViewRotation.entries[8] = inverse->entries[8];
}
