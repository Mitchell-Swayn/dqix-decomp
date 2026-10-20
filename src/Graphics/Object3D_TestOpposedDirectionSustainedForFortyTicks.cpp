#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include <globaldefs.h>

extern "C" {
int GameObject_HasWallContactGeometry(void*);
void* GameObject_GetWallContactGeometry(void*);
void* GameObject_GetWallContactDescriptor(void*);
void* ActorDescriptor_HasOpposedFacingTrigger(void*);
void* ActorDescriptor_GetOpposedFacingTriggerIdentifier(void*);
void* ActorDescriptor_GetOpposedFacingTriggerParameter(void*);
}

ARM
// Original: arm9/main @ 0x020A7D74; symbol: func_020a7d74; size: 0x144.
extern "C" int Object3D_TestOpposedDirectionSustainedForFortyTicks(void* object, void** outFirst, void** outSecond,
                              unsigned int unused)
{
    (void)unused;
    GameState* gameState = GameState::GetInstance();
    volatile int* elapsedField = (volatile int*)((char*)object + 0x138);
    Vector3fix facing;
    Vector3fix direction;
    int ready = 1;
    if (*(int*)((char*)object + 0x134) == 0)
        ready = 0;
    if (GameObject_HasWallContactGeometry(object) == 0)
        ready = 0;
    void* target = GameObject_GetWallContactDescriptor(object);
    if (target == 0)
        ready = 0;
    int result = (int)ActorDescriptor_HasOpposedFacingTrigger(target);
    if (result == 0)
        ready = 0;
    if (!ready) {
        result = 0;
        *elapsedField = result;
    } else {
        Vector3fix localAngles = *(Vector3fix*)((char*)object + 0x50);
        int angle = localAngles.y;
        fix32_t forwardZ = fix32cos(angle);
        facing.x = fix32sin(angle);
        facing.y = 0;
        facing.z = forwardZ;
        Vector3fix_Normalize(&facing, &facing);

        void* orientation = GameObject_GetWallContactGeometry(object);
        fix32_t directionZ = *(fix32_t*)((char*)orientation + 0x2c);
        fix32_t directionX = *(fix32_t*)((char*)orientation + 0x24);
        direction.x = directionX;
        direction.y = 0;
        direction.z = directionZ;
        Vector3fix_Normalize(&direction, &direction);
        int dot = Vector3fix_InnerProduct(&direction, &facing);
        if (dot < -0xc00)
            result = gameState->GetTickCount() + *(int*)((char*)object + 0x138);
        else
            result = 0;
        *elapsedField = result;
        if (*elapsedField < 0x28) {
            result = 0;
        } else {
            *outFirst = ActorDescriptor_GetOpposedFacingTriggerIdentifier(target);
            *outSecond = ActorDescriptor_GetOpposedFacingTriggerParameter(target);
            result = 1;
        }
    }
    return result;
}
