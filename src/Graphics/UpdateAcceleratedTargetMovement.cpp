// Original: arm9/main @ 0x020A0E4C; symbol: func_020a0e4c; size: 0x1e8.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
struct AcceleratedTargetMovement {
    int active;
    Vector3fix position, target;
    int speed, maximumSpeed, acceleration;
};
// ARM9 main, original func_020a0e4c at 0x020a0e4c.
// Proposed semantic name: UpdateAcceleratedTargetMovement.
extern "C" ARM void UpdateAcceleratedTargetMovement(AcceleratedTargetMovement *state)
{
    float deltaSeconds = (float)GameState::GetInstance()->GetEffectiveDeltaTime() / 1000.0f;
    int accelerationStep = (int)((float)state->acceleration * deltaSeconds);
    int speedStep = (int)((float)state->speed * deltaSeconds);
    Vector3fix direction;
    Vector3fix_Subtract(&state->target, &state->position, &direction);
    Vector3fix_Normalize(&direction, &direction);
    int distance = Vector3fix_Distance(&state->target, &state->position);
    float scaledSpeed = (float)speedStep / 4096.0f;
    float speedSquared = scaledSpeed * scaledSpeed;
    float scaledAcceleration = (float)accelerationStep / 4096.0f;
    float stoppingDistance = speedSquared / (2.0f * scaledAcceleration);
    if (distance < accelerationStep) {
        state->position = state->target;
        state->active = 0;
    } else if ((int)(4096.0f * stoppingDistance) < distance + 409) {
        int step = speedStep + accelerationStep;
        state->speed = (int)((float)step / deltaSeconds);
        if (state->maximumSpeed < state->speed) {
            state->speed = state->maximumSpeed;
            step = (int)((float)state->speed * deltaSeconds);
        }
        Vector3fix displacement;
        Vector3fixMultiplyScalar(&direction, step, &displacement);
        Vector3fix_Add(&state->position, &displacement, &state->position);
    } else {
        int step = speedStep - accelerationStep;
        if (step > distance / 2) step = distance / 2;
        state->speed = (int)((float)step / deltaSeconds);
        if (step < accelerationStep) {
            state->position = state->target;
            state->active = 0;
        } else {
            Vector3fix displacement;
            Vector3fixMultiplyScalar(&direction, step, &displacement);
            Vector3fix_Add(&state->position, &displacement, &state->position);
        }
    }
}
