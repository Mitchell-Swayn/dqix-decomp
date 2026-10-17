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
extern Vector3fix data_020e73c0;
extern short data_020e9450[];
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
        self->nearPlane, self->farPlane, 0x1000, &data_0210a010.projectionMatrix);
    data_0210a010.flags &= ~0x50;
    if (!self->roll) {
        self->up.x = 0; self->up.y = 0x1000; self->up.z = 0;
    } else {
        Vector3fix up = data_020e73c0;
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
        const Matrix4x3* view = &data_0210a010.viewMatrix;
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
        self->bobOffset = data_020e9450[2*(self->bobPhase >> 4)+1] >> 3;
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
    data_0210a010.eyeVector = eye;
    data_0210a010.upVector = self->up;
    data_0210a010.targetVector = target;
    Mat4x3_WriteViewMatrix(&eye,&self->up,&target,&data_0210a010.viewMatrix);
    data_0210a010.flags &= ~0xe8;
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
