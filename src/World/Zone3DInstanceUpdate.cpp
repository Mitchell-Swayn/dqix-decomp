#include "World/Zone3D.h"
#include "World/Zone3DPaths.h"
#include "GameState/GameState.h"

extern char data_02108760[];
extern char data_02109bf4[];
extern "C" void func_0205eaa0(void*, int, int);
extern "C" int func_0209ca2c(void*);

void Zone3D::UpdateBMDJInstance(Zone3D_BMDJStruct::InstanceEntry* instance)
{
    GameState* game = GameState::GetInstance();
    Zone3D_BMDJStruct::ObjectEntry* resource = instance->resource;
    if (!resource || !resource->unknown_4) return;
    fix32_t dt = game->GetAnimationDeltaTime();
    if (resource->kind == 0)
    {
        if (resource->patternAnimation) resource->patternAnimation->AdvanceTimer(dt);
        if (resource->textureAnimation) resource->textureAnimation->AdvanceTimer(dt);
        if (resource->materialAnimation) resource->materialAnimation->AdvanceTimer(dt);
        if (resource->skeletalAnimation) resource->skeletalAnimation->AdvanceTimer(dt);
        int current = instance->currentAngle;
        if (current != fix32ReduceAngle0To2Pi(instance->targetAngle))
        {
            int distance = fix32SignedAngleDistance(current, instance->targetAngle);
            int step = (int)(((long long)instance->rotationSpeed * dt + 0x800) >> 12);
            if (distance > 0)
            {
                if (distance < step) instance->currentAngle = instance->targetAngle;
                else instance->currentAngle += step;
            }
            else if (distance < 0)
            {
                if (-distance < step) instance->currentAngle = instance->targetAngle;
                else instance->currentAngle -= step;
            }
            instance->currentAngle = fix32ReduceAngle0To2Pi(instance->currentAngle);
        }
        else if (instance->rotationSpeed)
        {
            if (instance->flags & 0x10)
                instance->rotationSpeed = 0;
            else if (instance->flags & 0x80)
            {
                instance->flags &= ~0x80;
                instance->rotationSpeed = 0;
            }
            else if (instance->countdown > 0)
            {
                int count = instance->countdown - 3;
                if (count < 0)
                {
                    count = 0;
                    instance->rotationSpeed = 0;
                }
                instance->countdown = count;
                if (!instance->countdown) instance->flags |= 4;
            }
        }
        if (instance->movementStep)
        {
            if (Vector3fix_Distance(&instance->position, &instance->targetPosition) < instance->movementStep)
            {
                instance->position = instance->targetPosition;
                instance->movementStep = 0;
            }
            else
            {
                Vector3i movement = instance->movementDirection;
                Vector3fixMultiplyScalar(&movement, instance->movementStep, &movement);
                Vector3fix_Add(&instance->position, &movement, &instance->position);
            }
        }
    }
    if ((instance->flags & 0x100) && instance->object)
    {
        if (instance->doorState == 0)
        {
            instance->object->SetAnimationPlaybackSpeed(0x1800, 0);
            if (instance->object->MaybeSetRegularAnimation(gZone3DPaths.openAnimation, 1))
                func_0205eaa0(data_02108760, 0x12, 0);
            else if (instance->object->MaybeSetRegularAnimation(gZone3DPaths.openAnimation2, 1))
                func_0205eaa0(data_02108760, 0x62, 0);
            instance->doorState = 1;
        }
        else if (instance->doorState == 1)
        {
            if (instance->object->HasAnimationStopped())
            {
                instance->doorTimer = 500;
                instance->doorState = 2;
            }
        }
        else if (instance->doorState == 2)
        {
            unsigned int elapsed = game->GetEffectiveDeltaTime();
            if (elapsed < instance->doorTimer)
                instance->doorTimer -= elapsed;
            else if (!func_0209ca2c(data_02109bf4))
            {
                if (instance->object->MaybeSetRegularAnimation(gZone3DPaths.closeAnimation, 5))
                    func_0205eaa0(data_02108760, 0x13, 0);
                else if (instance->object->MaybeSetRegularAnimation(gZone3DPaths.closeAnimation2, 5))
                    func_0205eaa0(data_02108760, 0x62, 0);
                instance->flags &= ~0x100;
            }
        }
    }
}
